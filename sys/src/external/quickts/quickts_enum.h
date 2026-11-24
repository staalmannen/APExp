/*
 * quickts: TypeScript enums.
 *
 * The second construct that emits code rather than erasing it, and the more
 * involved one. `enum E { A, B = 4, C }` becomes
 *
 *     let E = {};
 *     {                          // a block scope, so a later member can say
 *       const A = 0;             // `B = A << 1` -- tsc resolves that
 *       E["A"] = A; E[A] = "A";  // reference to `E.A`; a real lexical
 *       const B = 4;             // scope gets the same result for free
 *       E["B"] = B; E[B] = "B";
 *       const C = 5;
 *       E["C"] = C; E[C] = "C";
 *     }
 *
 * A member whose initialiser is a plain string literal gets no reverse
 * mapping, matching tsc.
 *
 * Included from quickts.h.
 */

static __exception int js_define_var(JSParseState *s, JSAtom name, int tok);

static __exception int ts_emit_string(JSParseState *s, const char *str, size_t len)
{
    JSValue v = JS_NewStringLen(s->ctx, str, len);
    int ret;

    if (JS_IsException(v))
        return -1;
    ret = emit_push_const(s, v, TRUE);
    JS_FreeValue(s->ctx, v);
    return ret;
}

static __exception int ts_emit_atom_string(JSParseState *s, JSAtom atom)
{
    JSValue v = JS_AtomToString(s->ctx, atom);
    int ret;

    if (JS_IsException(v))
        return -1;
    ret = emit_push_const(s, v, TRUE);
    JS_FreeValue(s->ctx, v);
    return ret;
}

static void ts_emit_get_var(JSParseState *s, JSAtom name)
{
    emit_op(s, OP_scope_get_var);
    emit_atom(s, name);
    emit_u16(s, s->cur_func->scope_level);
}

static void ts_emit_put_var_init(JSParseState *s, JSAtom name)
{
    emit_op(s, OP_scope_put_var_init);
    emit_atom(s, name);
    emit_u16(s, s->cur_func->scope_level);
}

/* Current token is TOK_ENUM; the caller has already eaten `const`. */
static __exception int ts_parse_enum(JSParseState *s, BOOL export_flag)
{
    JSContext *ctx = s->ctx;
    JSAtom enum_name = JS_ATOM_NULL, key = JS_ATOM_NULL, prev_key = JS_ATOM_NULL;
    BOOL have_counter = TRUE;   /* the next value is known at compile time */
    int32_t counter = 0;
    BOOL scope_pushed = FALSE;

    if (next_token(s))                          /* `enum` */
        return -1;
    if (!token_is_ident(s->token.val) || s->token.u.ident.is_reserved)
        return js_parse_error(s, "enum name expected");
    enum_name = JS_DupAtom(ctx, s->token.u.ident.atom);
    if (next_token(s))
        goto fail;
    if (js_parse_expect(s, '{'))
        goto fail;

    if (js_define_var(s, enum_name, TOK_LET) < 0)
        goto fail;
    if (export_flag &&
        !add_export_entry(s, s->cur_func->module, enum_name, enum_name,
                          JS_EXPORT_TYPE_LOCAL))
        goto fail;
    emit_op(s, OP_object);
    ts_emit_put_var_init(s, enum_name);

    if (push_scope(s) < 0)
        goto fail;
    scope_pushed = TRUE;

    while (s->token.val != '}') {
        JSAtom binding = JS_ATOM_NULL;  /* the `const A` name, if bindable */
        BOOL is_string_member = FALSE;

        if (s->token.val == TOK_STRING) {
            key = JS_ValueToAtom(ctx, s->token.u.str.str);
            if (key == JS_ATOM_NULL)
                goto fail;
        } else if (token_is_ident(s->token.val)) {
            key = JS_DupAtom(ctx, s->token.u.ident.atom);
            if (s->token.val == TOK_IDENT && !s->token.u.ident.is_reserved)
                binding = JS_DupAtom(ctx, key);
        } else {
            js_parse_error(s, "enum member name expected");
            goto fail;
        }
        if (next_token(s))
            goto fail_member;

        if (s->token.val == '=') {
            if (next_token(s))
                goto fail_member;
            /* `A = "x"` and nothing else: a string member, no reverse map. */
            if (s->token.val == TOK_STRING) {
                int after = peek_token(s, FALSE);
                is_string_member = (after == ',' || after == '}');
            }
            /* `A = 3` folds into the counter, so a bare `B` after it is 4. */
            if (s->token.val == TOK_NUMBER &&
                JS_VALUE_GET_TAG(s->token.u.num.val) == JS_TAG_INT) {
                int after = peek_token(s, FALSE);
                if (after == ',' || after == '}') {
                    counter = JS_VALUE_GET_INT(s->token.u.num.val);
                    have_counter = TRUE;
                    emit_op(s, OP_push_i32);
                    emit_u32(s, counter);
                    if (next_token(s))
                        goto fail_member;
                    goto have_value;
                }
            }
            have_counter = FALSE;
            if (js_parse_assign_expr(s))
                goto fail_member;
        } else if (have_counter) {
            emit_op(s, OP_push_i32);
            emit_u32(s, counter);
        } else if (prev_key != JS_ATOM_NULL) {
            /* the previous value was not a compile-time constant: read it
               back off the enum object, i.e. `E[prev] + 1` */
            ts_emit_get_var(s, enum_name);
            if (ts_emit_atom_string(s, prev_key))
                goto fail_member;
            emit_op(s, OP_get_array_el);
            emit_op(s, OP_push_i32);
            emit_u32(s, 1);
            emit_op(s, OP_add);
        } else {
            emit_op(s, OP_push_i32);
            emit_u32(s, 0);
        }
    have_value:
        /* stack: V */
        if (binding != JS_ATOM_NULL) {
            if (js_define_var(s, binding, TOK_CONST) < 0)
                goto fail_member;
            emit_op(s, OP_dup);
            ts_emit_put_var_init(s, binding);
        }
        if (is_string_member) {
            ts_emit_get_var(s, enum_name);      /* V E */
            emit_op(s, OP_swap);                /* E V */
            emit_op(s, OP_define_field);        /* E     (E[key] = V) */
            emit_atom(s, key);
            emit_op(s, OP_drop);
        } else {
            emit_op(s, OP_dup);                 /* V V */
            ts_emit_get_var(s, enum_name);      /* V V E */
            emit_op(s, OP_swap);                /* V E V */
            emit_op(s, OP_define_field);        /* V E   (E[key] = V) */
            emit_atom(s, key);
            emit_op(s, OP_swap);                /* E V */
            if (ts_emit_atom_string(s, key))    /* E V "key" */
                goto fail_member;
            emit_op(s, OP_put_array_el);        /*       (E[V] = "key") */
        }
        if (have_counter)
            counter++;
        JS_FreeAtom(ctx, binding);
        JS_FreeAtom(ctx, prev_key);
        prev_key = key;
        key = JS_ATOM_NULL;

        if (s->token.val != ',')
            break;
        if (next_token(s))
            goto fail;
        continue;

    fail_member:
        JS_FreeAtom(ctx, binding);
        goto fail;
    }

    if (js_parse_expect(s, '}'))
        goto fail;
    pop_scope(s);
    JS_FreeAtom(ctx, enum_name);
    JS_FreeAtom(ctx, prev_key);
    return 0;

 fail:
    if (scope_pushed)
        pop_scope(s);
    JS_FreeAtom(ctx, enum_name);
    JS_FreeAtom(ctx, key);
    JS_FreeAtom(ctx, prev_key);
    return -1;
}

/* `enum E {}` or `const enum E {}` as a statement. Returns 1 when consumed. */
static int ts_try_enum(JSParseState *s, BOOL export_flag)
{
    if (!s->ts)
        return 0;
    if (s->token.val == TOK_ENUM)
        return ts_parse_enum(s, export_flag) < 0 ? -1 : 1;
    if (s->token.val == TOK_CONST && ts_next_word_is(s, "enum")) {
        if (next_token(s))                      /* `const` */
            return -1;
        return ts_parse_enum(s, export_flag) < 0 ? -1 : 1;
    }
    return 0;
}
