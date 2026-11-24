/*
 * quickts - TypeScript and JSX inside the QuickJS parser.
 *
 * Included from quickjs.c after js_parse_seek_token() so it can use the
 * tokenizer, the position save/restore helpers and js_parse_error().
 *
 * This file is *erasure*: types are consumed as tokens and nothing is
 * emitted, so the bytecode is identical to what the same file with the types
 * stripped would produce. The two constructs that need real code generation
 * live next door: quickts_enum.h and quickts_jsx.h. (Constructor parameter
 * properties are the third, and are here because they hang off the parameter
 * list.)
 *
 * Deliberately not handled (see README.md, "What is not supported"):
 *   - method and function overload signatures
 *   - a namespace that declares values (rejected, not erased)
 *   - decorators (QuickJS has none)
 *   - the legacy `<T>value` assertion form
 */

#define TS_MAX_DEPTH 96

static int js_parse_skip_parens_token(JSParseState *s, int *pbits,
                                      BOOL no_line_terminator);

/* ---------------------------------------------------------------- helpers */

/* Several constructs are decided by trying a type parse and backing out:
   `f<T>(x)` versus `f < T > (x)`, `(a): T => b` versus `c ? (a) : b`. During
   those attempts a failure is an answer, not an error, so it must not build
   a JSError with a backtrace -- doing that turned every '<' comparison in a
   36 KB app into an exception object and cost 54% of the parse time. */
#define ts_error(s, msg) ((s)->ts_quiet ? -1 : js_parse_error(s, msg))

static int ts_expect(JSParseState *s, int tok)
{
    if (s->token.val != tok) {
        if (s->ts_quiet)
            return -1;
        return js_parse_expect(s, tok);
    }
    return next_token(s);
}

/* Drop whatever exception a speculative parse left behind. */
static void ts_clear_error(JSParseState *s)
{
    JS_FreeValue(s->ctx, JS_GetException(s->ctx));
}

/* TRUE if the current token is the unescaped identifier `kw`. Compares the
   source bytes rather than an atom so quickjs-atom.h stays untouched: adding
   atoms there shifts every TOK_* value and the bytecode atom table.
   s->buf_ptr sits exactly one past the end of the current token. */
static BOOL ts_is_word(JSParseState *s, const char *kw)
{
    size_t len = strlen(kw);

    if (s->token.val != TOK_IDENT || s->token.u.ident.has_escape)
        return FALSE;
    if ((size_t)(s->buf_ptr - s->token.ptr) != len)
        return FALSE;
    return memcmp(s->token.ptr, kw, len) == 0;
}

/* Cheap raw lookahead: is the token after the current one the word `kw`?
   Reads source bytes rather than lexing, because the enum hook fires on
   every `const` in the file and a get_pos/next_token/seek_token round trip
   there cost 9% of the parse time on a 36 KB app. */
static BOOL ts_next_word_is(JSParseState *s, const char *kw)
{
    const uint8_t *p = s->buf_ptr, *end = s->buf_end;
    size_t len = strlen(kw);
    int c;

    for (;;) {
        while (p < end && (*p == ' ' || *p == '\t' || *p == '\n' ||
                           *p == '\r' || *p == '\f' || *p == '\v'))
            p++;
        if (p + 1 < end && p[0] == '/' && p[1] == '/') {
            p += 2;
            while (p < end && *p != '\n')
                p++;
            continue;
        }
        if (p + 1 < end && p[0] == '/' && p[1] == '*') {
            p += 2;
            while (p + 1 < end && !(p[0] == '*' && p[1] == '/'))
                p++;
            p = (p + 1 < end) ? p + 2 : end;
            continue;
        }
        break;
    }
    if ((size_t)(end - p) < len || memcmp(p, kw, len) != 0)
        return FALSE;
    if ((size_t)(end - p) == len)
        return TRUE;
    c = p[len];
    return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
             (c >= '0' && c <= '9') || c == '_' || c == '$' || c >= 128);
}

/* TRUE if the current token's source starts with '>' (i.e. it is one of
   > >= >> >>= >>> >>>=). Inside a type these must be split. */
static BOOL ts_starts_with_gt(JSParseState *s)
{
    switch (s->token.val) {
    case '>':
    case TOK_GTE:
    case TOK_SAR:
    case TOK_SAR_ASSIGN:
    case TOK_SHR:
    case TOK_SHR_ASSIGN:
        return TRUE;
    }
    return FALSE;
}

/* Consume exactly one '>' out of a >/>=/>>/>>>/... token by re-lexing from
   one byte past the token start. */
static __exception int ts_next_gt(JSParseState *s)
{
    s->buf_ptr = s->token.ptr + 1;
    s->got_lf = FALSE;
    return next_token(s);
}

static __exception int ts_skip_type(JSParseState *s);

/* Skip a balanced ( ) / [ ] / { } / < > region, current token being the
   opener; leaves the token after the closer current. */
static __exception int ts_skip_bracketed(JSParseState *s)
{
    char stack[TS_MAX_DEPTH];
    int sp = 0;

    for (;;) {
        int t = s->token.val;

        if (t == TOK_EOF)
            return ts_error(s, "unexpected end of input in TypeScript type");

        if (t == '(' || t == '[' || t == '{' || t == '<') {
            if (sp >= TS_MAX_DEPTH)
                return ts_error(s, "TypeScript type nested too deeply");
            stack[sp++] = (char)t;
            if (next_token(s))
                return -1;
            continue;
        }
        if (t == TOK_TEMPLATE) {
            /* `a${ ... }b`: the '}' that closes the hole resumes the
               template, exactly as js_parse_skip_parens_token() does. */
            if (s->token.u.str.sep != '`') {
                if (sp >= TS_MAX_DEPTH)
                    return ts_error(s, "TypeScript type nested too deeply");
                stack[sp++] = '`';
                if (next_token(s))
                    return -1;
                continue;
            }
            /* the closing part of the template */
            if (next_token(s))
                return -1;
            if (sp == 0)
                return 0;
            continue;
        }
        if (t == ')' || t == ']' || t == '}') {
            char want = t == ')' ? '(' : t == ']' ? '[' : '{';
            if (sp > 0 && t == '}' && stack[sp - 1] == '`') {
                sp--;
                free_token(s, &s->token);
                s->got_lf = FALSE;
                if (js_parse_template_part(s, s->buf_ptr))
                    return -1;
                continue;
            }
            if (sp == 0 || stack[sp - 1] != want)
                return ts_error(s, "unbalanced TypeScript type");
            sp--;
            if (next_token(s))
                return -1;
            if (sp == 0)
                return 0;
            continue;
        }
        if (ts_starts_with_gt(s)) {
            if (sp > 0 && stack[sp - 1] == '<') {
                sp--;
                if (ts_next_gt(s))
                    return -1;
                if (sp == 0)
                    return 0;
                continue;
            }
            if (ts_next_gt(s))
                return -1;
            continue;
        }
        if (next_token(s))
            return -1;
    }
}

/* Current token is '('. TRUE when what follows looks unambiguously like a
   function type's parameter list rather than a parenthesised type. This is
   the rule that keeps `c ? (a) : (b) => d` a conditional expression and
   `(a): ((b) => c) => d` an arrow function -- same test TypeScript uses. */
static BOOL ts_paren_is_param_list(JSParseState *s)
{
    JSParsePos pos;
    BOOL ret = FALSE;
    int t;

    js_parse_get_pos(s, &pos);
    s->ts_quiet++;
    if (next_token(s))
        goto done;
    t = s->token.val;
    if (t == ')' || t == TOK_ELLIPSIS || t == '{' || t == '[') {
        ret = TRUE;
        goto done;
    }
    if (t == TOK_IDENT || t == TOK_THIS ||
        (t >= TOK_FIRST_KEYWORD && t <= TOK_LAST_KEYWORD)) {
        t = peek_token(s, FALSE);
        ret = (t == ':' || t == ',' || t == '?' || t == '=' || t == ')');
    }
 done:
    s->ts_quiet--;
    ts_clear_error(s);
    if (js_parse_seek_token(s, &pos))
        return FALSE;
    return ret;
}

/* One "unit" of a type: a primary plus its postfixes. `callable` records
   whether a trailing '=>' would make this a function type; only a parameter
   list, a type-parameter list or `new` can. */
static __exception int ts_skip_type_unit(JSParseState *s)
{
    BOOL callable = FALSE;

    /* prefix type operators */
    for (;;) {
        if (s->token.val == '|' || s->token.val == '&') {
            if (next_token(s))
                return -1;
            continue;
        }
        if (ts_is_word(s, "keyof") || ts_is_word(s, "readonly") ||
            ts_is_word(s, "infer") || ts_is_word(s, "unique") ||
            ts_is_word(s, "asserts") || ts_is_word(s, "abstract")) {
            if (next_token(s))
                return -1;
            continue;
        }
        break;
    }

    switch (s->token.val) {
    case '(':
        callable = ts_paren_is_param_list(s);
        if (ts_skip_bracketed(s))
            return -1;
        break;
    case '<':
        callable = TRUE;
        if (ts_skip_bracketed(s))
            return -1;
        break;
    case '[':
    case '{':
        if (ts_skip_bracketed(s))
            return -1;
        break;
    case TOK_NEW:
        callable = TRUE;
        if (next_token(s))
            return -1;
        if (s->token.val == '<' && ts_skip_bracketed(s))
            return -1;
        if (s->token.val != '(')
            return ts_error(s, "'(' expected in constructor type");
        if (ts_skip_bracketed(s))
            return -1;
        break;
    case TOK_TYPEOF:
    case TOK_IMPORT:
        /* `typeof x.y`, `import("m").T`, `typeof import("m").T` */
        if (next_token(s))
            return -1;
        if (s->token.val == TOK_IMPORT && next_token(s))
            return -1;
        if (s->token.val == '(' && ts_skip_bracketed(s))
            return -1;
        for (;;) {
            if (s->token.val != TOK_IDENT &&
                !(s->token.val >= TOK_FIRST_KEYWORD && s->token.val <= TOK_LAST_KEYWORD))
                break;
            if (next_token(s))
                return -1;
            if (s->token.val != '.')
                break;
            if (next_token(s))
                return -1;
        }
        break;
    case '-':
        if (next_token(s))
            return -1;
        if (s->token.val != TOK_NUMBER)
            return ts_error(s, "number expected in literal type");
        if (next_token(s))
            return -1;
        break;
    case TOK_TEMPLATE:
        if (s->token.u.str.sep != '`') {
            if (ts_skip_bracketed(s))   /* template literal type with holes */
                return -1;
        } else if (next_token(s)) {
            return -1;
        }
        break;
    case TOK_NUMBER:
    case TOK_STRING:
    case TOK_NULL:
    case TOK_TRUE:
    case TOK_FALSE:
    case TOK_VOID:
    case TOK_THIS:
    case TOK_CONST:   /* `x as const` */
    case TOK_IDENT:
        if (next_token(s))
            return -1;
        break;
    default:
        return ts_error(s, "TypeScript type expected");
    }

    /* postfixes: qualified names, type arguments, indexed access, arrays,
       and the '=>' of a function type. */
    for (;;) {
        if (s->token.val == '.') {
            if (next_token(s))
                return -1;
            if (s->token.val != TOK_IDENT &&
                !(s->token.val >= TOK_FIRST_KEYWORD && s->token.val <= TOK_LAST_KEYWORD))
                return ts_error(s, "identifier expected in qualified type name");
            if (next_token(s))
                return -1;
            continue;
        }
        if (s->token.val == '<') {
            /* type arguments: `Promise<void>` is not callable, so a '=>'
               after it belongs to the enclosing construct, not to a
               function type. */
            if (ts_skip_bracketed(s))
                return -1;
            continue;
        }
        if (s->token.val == '[' && !s->got_lf) {
            if (ts_skip_bracketed(s))
                return -1;
            continue;
        }
        if (s->token.val == '(' && callable) {
            if (ts_skip_bracketed(s))
                return -1;
            continue;
        }
        if (s->token.val == TOK_ARROW && callable) {
            if (next_token(s))
                return -1;
            return ts_skip_type(s);
        }
        break;
    }
    return 0;
}

/* A full type: unions, intersections, conditional types and `x is T`. */
static __exception int ts_skip_type(JSParseState *s)
{
    /* conditional and function types recurse; on a device whose render task
       has a few tens of KB of stack, a pathological type must fail cleanly
       rather than smash it. */
    if (js_check_stack_overflow(s->ctx->rt, 0)) {
        if (s->ts_quiet)
            return -1;
        (void)JS_ThrowStackOverflow(s->ctx);
        return -1;
    }
    if (ts_skip_type_unit(s))
        return -1;
    for (;;) {
        if (s->token.val == '|' || s->token.val == '&') {
            if (next_token(s))
                return -1;
            if (ts_skip_type_unit(s))
                return -1;
            continue;
        }
        if (ts_is_word(s, "is")) {          /* type predicate: `a is Foo` */
            if (next_token(s))
                return -1;
            if (ts_skip_type_unit(s))
                return -1;
            continue;
        }
        if (s->token.val == TOK_EXTENDS) {  /* conditional type / constraint */
            if (next_token(s))
                return -1;
            if (ts_skip_type(s))
                return -1;
            if (s->token.val != '?')
                break;
            if (next_token(s))
                return -1;
            if (ts_skip_type(s))
                return -1;
            if (ts_expect(s, ':'))
                return -1;
            if (ts_skip_type(s))
                return -1;
            continue;
        }
        break;
    }
    return 0;
}

/* ------------------------------------------------------------ entry points */

/* `: T` after a binding, a parameter or a parameter list. */
static __exception int ts_annotation(JSParseState *s)
{
    if (!s->ts || s->token.val != ':')
        return 0;
    if (next_token(s))
        return -1;
    return ts_skip_type(s);
}

/* `?` (optional) and `!` (definite assignment) markers before an annotation. */
static __exception int ts_opt_marker(JSParseState *s)
{
    if (!s->ts)
        return 0;
    if (s->token.val == '?' || s->token.val == '!') {
        if (next_token(s))
            return -1;
    }
    return 0;
}

/* Inside the `?` branch of a conditional, `(...) : T => body` is only an
   arrow function if the conditional's own ':' still follows the body:

       a ? (x): number => x : e     arrow in the true branch
       a ? (b) : c => d             conditional; `c => d` is the else branch

   tsc decides this by parsing the arrow and looking at the next token. This
   scans the body instead: a block is skipped whole, an expression is walked
   at bracket depth 0 (nested `?:` pairs counted) until a ':' (arrow) or a
   token that ends the expression (not an arrow). Current token is '=>'. */
static BOOL ts_arrow_body_then_colon(JSParseState *s)
{
    int depth_q = 0;

    if (next_token(s))
        return FALSE;
    if (s->token.val == '{')
        return ts_skip_bracketed(s) == 0 && s->token.val == ':';
    for (;;) {
        int t = s->token.val;
        if (t == '(' || t == '[' || t == '{' || t == TOK_TEMPLATE) {
            if (ts_skip_bracketed(s))
                return FALSE;
            continue;
        }
        if (t == '?') {
            depth_q++;
        } else if (t == ':') {
            if (depth_q == 0)
                return TRUE;
            depth_q--;
        } else if (t == ';' || t == ',' || t == ')' || t == ']' || t == '}' ||
                   t == TOK_EOF) {
            return FALSE;
        }
        if (next_token(s))
            return FALSE;
    }
}

/* Called from js_parse_skip_parens_token() when the token after a closing
   ')' / '}' / ']' is ':'. Parses the annotation and returns the token that
   follows it, so a return type does not hide the '=>' of an arrow function.
   The caller restores the parser position afterwards. */
static int ts_scan_past_annotation(JSParseState *s)
{
    int tok = ':';

    s->ts_quiet++;
    if (next_token(s) == 0 && ts_skip_type(s) == 0) {
        tok = s->token.val;
        if (tok == TOK_ARROW && s->ts_arrow_in_cond &&
            !ts_arrow_body_then_colon(s))
            tok = ':';
    }
    ts_clear_error(s);
    s->ts_quiet--;
    return tok;
}

/* `<T>(x: T) => x` at the head of an expression (the caller has already
   handled an `async` prefix). Returns 1 with the parser left on the '(' so
   the normal arrow path can take over. */
static int ts_try_generic_arrow(JSParseState *s)
{
    JSParsePos pos;

    if (!s->ts || s->token.val != '<')
        return 0;
    js_parse_get_pos(s, &pos);
    s->ts_quiet++;
    if (ts_skip_bracketed(s) == 0 && s->token.val == '(' &&
        js_parse_skip_parens_token(s, NULL, TRUE) == TOK_ARROW) {
        s->ts_quiet--;
        return 1;
    }
    s->ts_quiet--;
    ts_clear_error(s);
    if (js_parse_seek_token(s, &pos))
        return -1;
    return 0;
}

/* `import type ...` / `export type ...`: the whole statement is erased.
   Called with the token after `import` / `export` current. Returns 1 when a
   type-only clause was consumed. */
static int ts_try_type_only_clause(JSParseState *s)
{
    JSParsePos pos;
    int tok;

    if (!s->ts || !ts_is_word(s, "type"))
        return 0;
    js_parse_get_pos(s, &pos);
    if (next_token(s))
        return -1;
    /* `import type X`, `import type {`, `import type *`, `export type {` --
       but not `export type = ...` or `import type from './type'`, where
       `type` is the imported binding. */
    tok = s->token.val;
    if (tok == '{') {
        if (ts_skip_bracketed(s))
            return -1;
    } else if (tok == '*') {
        if (next_token(s))                      /* '*' */
            return -1;
        if (ts_is_word(s, "as")) {              /* `* as ns` */
            if (next_token(s) || next_token(s))
                return -1;
        }
    } else if (tok == TOK_IDENT && !ts_is_word(s, "from")) {
        if (next_token(s))                      /* the default binding */
            return -1;
        if (s->token.val == ',') {
            if (next_token(s))
                return -1;
            if (s->token.val == '{') {
                if (ts_skip_bracketed(s))
                    return -1;
            } else if (s->token.val == '*') {
                if (next_token(s) || next_token(s) || next_token(s))
                    return -1;
            }
        }
    } else {
        if (js_parse_seek_token(s, &pos))
            return -1;
        return 0;
    }
    /* `export type { A }` has no from-clause; stop at the end of the
       statement rather than running on into the next one. */
    if (ts_is_word(s, "from")) {
        if (next_token(s))
            return -1;
        if (s->token.val == TOK_STRING && next_token(s))
            return -1;
    }
    if (s->token.val == ';' && next_token(s))
        return -1;
    return 1;
}

/* An inline `type` specifier inside `import { ... }` / `export { ... }`:
   `import { type A, type B as C, D }`. Returns 1 when one was consumed,
   leaving the token on ',' or '}'.

   `type` on its own is an ordinary binding (`import { type }`), and so is
   `type as X`, which imports the name `type`. */
static int ts_try_type_specifier(JSParseState *s)
{
    JSParsePos pos;

    if (!s->ts || !ts_is_word(s, "type"))
        return 0;
    js_parse_get_pos(s, &pos);
    if (next_token(s))
        return -1;
    if (!(s->token.val == TOK_STRING ||
          (s->token.val == TOK_IDENT && !ts_is_word(s, "as")) ||
          (s->token.val >= TOK_FIRST_KEYWORD && s->token.val <= TOK_LAST_KEYWORD))) {
        if (js_parse_seek_token(s, &pos))
            return -1;
        return 0;
    }
    if (next_token(s))          /* the exported/imported name */
        return -1;
    if (ts_is_word(s, "as")) {
        if (next_token(s))
            return -1;
        if (next_token(s))      /* the local alias */
            return -1;
    }
    return 1;
}

/* `<T, U extends V>` after a function, class or method name. */
static __exception int ts_type_params(JSParseState *s)
{
    if (!s->ts || s->token.val != '<')
        return 0;
    return ts_skip_bracketed(s);
}

/* `implements A, B<C>` in a class heritage clause. */
static __exception int ts_implements_clause(JSParseState *s)
{
    if (!s->ts)
        return 0;
    if (s->token.val != TOK_IMPLEMENTS && !ts_is_word(s, "implements"))
        return 0;
    if (next_token(s))
        return -1;
    for (;;) {
        if (ts_skip_type(s))
            return -1;
        if (s->token.val != ',')
            break;
        if (next_token(s))
            return -1;
    }
    return 0;
}

/* `x as T` / `x satisfies T`, hooked into the relational precedence level. */
static BOOL ts_is_assertion_op(JSParseState *s)
{
    return s->ts && !s->got_lf &&
        (ts_is_word(s, "as") || ts_is_word(s, "satisfies"));
}

/* `f<T>(x)`: consume the type arguments only when what follows makes the
   '<' unambiguous -- a call, a tagged template, or (`new Map<string, number>`,
   `const g = f<string>`) a token that could not follow a comparison's right
   operand in valid JavaScript: `;` `,` `)` `]` `}` `.` `?.` or the end of
   input. Otherwise it is a '<' comparison. Returns 1 if consumed, 0 if not,
   -1 on error. */
static BOOL ts_ends_type_args(int tok)
{
    return tok == '(' || tok == TOK_TEMPLATE || tok == ';' || tok == ',' ||
        tok == ')' || tok == ']' || tok == '}' || tok == '.' ||
        tok == TOK_QUESTION_MARK_DOT || tok == TOK_EOF;
}

static int ts_try_call_type_args(JSParseState *s)
{
    JSParsePos pos;

    if (!s->ts || s->token.val != '<')
        return 0;
    js_parse_get_pos(s, &pos);
    s->ts_quiet++;
    if (ts_skip_bracketed(s) == 0 && ts_ends_type_args(s->token.val)) {
        s->ts_quiet--;
        return 1;
    }
    s->ts_quiet--;
    ts_clear_error(s);
    if (js_parse_seek_token(s, &pos))
        return -1;
    return 0;
}

/* A `namespace X { ... }` body. A namespace that declares only types erases
   cleanly; one that declares values needs an IIFE and a merged object, which
   quickts does not build. Refuse that loudly rather than silently dropping
   the values -- a wrong answer on a frame is worse than a failed deploy. */
static int ts_skip_namespace_body(JSParseState *s)
{
    int depth = 0;

    for (;;) {
        int t = s->token.val;

        if (t == TOK_EOF)
            return js_parse_error(s, "unterminated namespace");
        if (t == '{' || t == '(' || t == '[') {
            depth++;
        } else if (t == '}' || t == ')' || t == ']') {
            depth--;
            if (depth == 0) {
                if (next_token(s))
                    return -1;
                return 1;
            }
        } else if (depth == 1 &&
                   (t == TOK_CONST || t == TOK_LET || t == TOK_VAR ||
                    t == TOK_FUNCTION || t == TOK_CLASS || t == TOK_ENUM)) {
            return js_parse_error(s, "a namespace that declares values is not "
                                  "supported; use a module or an object");
        }
        if (next_token(s))
            return -1;
    }
}

/* An `interface` / `type` / `declare` / `namespace` statement. Returns 1 when
   a declaration was consumed, 0 when the statement is not TypeScript-only. */
static int ts_try_type_decl(JSParseState *s)
{
    JSParsePos pos;
    int tok;

    if (!s->ts)
        return 0;

    /* `interface Foo<T> extends A, B { ... }` */
    if (s->token.val == TOK_INTERFACE || ts_is_word(s, "interface")) {
        tok = peek_token(s, FALSE);
        if (tok != TOK_IDENT && !(tok >= TOK_FIRST_KEYWORD && tok <= TOK_LAST_KEYWORD))
            return 0;
        if (next_token(s))
            return -1;
        if (next_token(s))                  /* the name */
            return -1;
        if (ts_type_params(s))
            return -1;
        if (s->token.val == TOK_EXTENDS) {
            if (next_token(s))
                return -1;
            for (;;) {
                if (ts_skip_type(s))
                    return -1;
                if (s->token.val != ',')
                    break;
                if (next_token(s))
                    return -1;
            }
        }
        if (s->token.val != '{')
            return ts_error(s, "'{' expected in interface declaration");
        if (ts_skip_bracketed(s))
            return -1;
        return 1;
    }

    /* `type Foo<T> = ...;` -- `type` is contextual, so only when the shape
       matches (`type` followed by a name followed by '<' or '='). */
    if (ts_is_word(s, "type")) {
        js_parse_get_pos(s, &pos);
        if (next_token(s))
            return -1;
        if (s->token.val != TOK_IDENT || s->got_lf) {
            if (js_parse_seek_token(s, &pos))
                return -1;
            return 0;
        }
        if (next_token(s))
            return -1;
        if (s->token.val != '=' && s->token.val != '<') {
            if (js_parse_seek_token(s, &pos))
                return -1;
            return 0;
        }
        if (ts_type_params(s))
            return -1;
        if (ts_expect(s, '='))
            return -1;
        if (ts_skip_type(s))
            return -1;
        if (s->token.val == ';' && next_token(s))
            return -1;
        return 1;
    }

    /* `declare ...`: ambient, nothing is emitted for the whole statement. */
    if (ts_is_word(s, "declare")) {
        js_parse_get_pos(s, &pos);
        if (next_token(s))
            return -1;
        if (s->got_lf ||
            !(s->token.val == TOK_IDENT || s->token.val == TOK_CONST ||
              s->token.val == TOK_VAR || s->token.val == TOK_LET ||
              s->token.val == TOK_FUNCTION || s->token.val == TOK_CLASS ||
              s->token.val == TOK_ENUM || s->token.val == TOK_INTERFACE)) {
            if (js_parse_seek_token(s, &pos))
                return -1;
            return 0;
        }
        for (;;) {
            if (s->token.val == TOK_EOF)
                break;
            if (s->token.val == '(' || s->token.val == '[') {
                if (ts_skip_bracketed(s))    /* a signature, keep going */
                    return -1;
                continue;
            }
            if (s->token.val == '{') {
                if (ts_skip_bracketed(s))    /* the declaration body ends it */
                    return -1;
                break;
            }
            if (s->token.val == ';') {
                if (next_token(s))
                    return -1;
                break;
            }
            if (next_token(s))
                return -1;
            if (s->got_lf)
                break;
        }
        return 1;
    }

    /* `namespace X { ... }` / `module X { ... }`: erased. A namespace that
       declares values needs an IIFE; see README.md. */
    if (ts_is_word(s, "namespace") || ts_is_word(s, "module")) {
        js_parse_get_pos(s, &pos);
        if (next_token(s))
            return -1;
        if (s->token.val != TOK_IDENT || s->got_lf) {
            if (js_parse_seek_token(s, &pos))
                return -1;
            return 0;
        }
        for (;;) {
            if (next_token(s))
                return -1;
            if (s->token.val != '.')
                break;
            if (next_token(s))
                return -1;
        }
        if (s->token.val != '{') {
            if (js_parse_seek_token(s, &pos))
                return -1;
            return 0;
        }
        return ts_skip_namespace_body(s);
    }

    return 0;
}

/* `abstract class ...`: swallow the modifier. Returns 1 when consumed. */
static int ts_try_abstract_class(JSParseState *s)
{
    JSParsePos pos;

    if (!s->ts || !ts_is_word(s, "abstract"))
        return 0;
    js_parse_get_pos(s, &pos);
    if (next_token(s))
        return -1;
    if (s->token.val == TOK_CLASS)
        return 1;
    if (js_parse_seek_token(s, &pos))
        return -1;
    return 0;
}

/* Class member modifiers. `static` is left to QuickJS; ordering is tsc's
   problem, not ours. */
static __exception int ts_member_modifiers(JSParseState *s)
{
    JSParsePos pos;

    if (!s->ts)
        return 0;
    for (;;) {
        BOOL erases = ts_is_word(s, "abstract") || ts_is_word(s, "declare");
        BOOL is_mod = erases ||
            s->token.val == TOK_PUBLIC || s->token.val == TOK_PRIVATE ||
            s->token.val == TOK_PROTECTED ||
            ts_is_word(s, "public") || ts_is_word(s, "private") ||
            ts_is_word(s, "protected") || ts_is_word(s, "readonly") ||
            ts_is_word(s, "override");
        if (!is_mod)
            return 0;
        /* `private` is also a legal member name: `private = 1`, `private()`. */
        js_parse_get_pos(s, &pos);
        if (next_token(s))
            return -1;
        if (s->token.val == '=' || s->token.val == '(' || s->token.val == ';' ||
            s->token.val == '}' || s->token.val == ':' || s->token.val == '?' ||
            s->token.val == '<' || s->got_lf) {
            if (js_parse_seek_token(s, &pos))
                return -1;
            return 0;
        }
        /* `abstract x: T` and `declare x: T` declare nothing at runtime:
           the whole member is erased by ts_try_skip_member_signature(). */
        if (erases)
            s->ts_member_erase = TRUE;
    }
}

/* Bodiless class members are erased whole: overload signatures
   (`find(id: string): Item;`), abstract methods, and `abstract` / `declare`
   fields. A field with `abstract` left in place would define an own property
   set to undefined, shadowing the subclass accessor it was declared for --
   so this is correctness, not tidiness.

   Runs before js_parse_class emits anything for the member. Returns 1 when
   a member was erased, 0 when the member is real and untouched. */
static int ts_try_skip_member_signature(JSParseState *s)
{
    JSParsePos pos;
    BOOL erase_field = s->ts_member_erase;
    int tok;

    s->ts_member_erase = FALSE;
    if (!s->ts)
        return 0;
    js_parse_get_pos(s, &pos);
    s->ts_quiet++;

    /* get / set / async prefix, unless that word is the member's own name */
    if (ts_is_word(s, "get") || ts_is_word(s, "set") || ts_is_word(s, "async")) {
        if (next_token(s))
            goto back;
        if (s->token.val == '(' || s->token.val == ':' || s->token.val == ';' ||
            s->token.val == '=' || s->token.val == '}' || s->token.val == '?' ||
            s->token.val == '!' || s->token.val == '<')
            goto have_name;
    }
    if (s->token.val == '*' && next_token(s))
        goto back;
    if (s->token.val == '[') {
        if (ts_skip_bracketed(s))
            goto back;
    } else if (token_is_ident(s->token.val) || s->token.val == TOK_STRING ||
               s->token.val == TOK_NUMBER || s->token.val == TOK_PRIVATE_NAME) {
        if (next_token(s))
            goto back;
    } else {
        goto back;
    }
 have_name:
    if ((s->token.val == '?' || s->token.val == '!') && next_token(s))
        goto back;
    if (s->token.val == '<' && ts_skip_bracketed(s))
        goto back;
    if (s->token.val == '(') {
        /* the token after the parameter list and its return type */
        tok = js_parse_skip_parens_token(s, NULL, FALSE);
        if (tok == '{')
            goto back;                  /* a method with a body */
        s->ts_quiet--;
        if (ts_skip_bracketed(s))       /* the ( ... ) */
            return -1;
        if (ts_annotation(s))
            return -1;
        if (s->token.val == ';' && next_token(s))
            return -1;
        return 1;
    }
    if (!erase_field)
        goto back;
    s->ts_quiet--;
    if (ts_annotation(s))
        return -1;
    if (s->token.val == ';' && next_token(s))
        return -1;
    return 1;

 back:
    s->ts_quiet--;
    ts_clear_error(s);
    if (js_parse_seek_token(s, &pos))
        return -1;
    return 0;
}

/* `function f(a: string): void;` -- an overload signature at statement level
   (also `export function`, `async function`). Called at the top of
   js_parse_function_decl2 before it creates anything. Returns 1 when a
   signature was erased. */
static int ts_try_skip_function_signature(JSParseState *s)
{
    JSParsePos pos;
    int tok;

    if (!s->ts)
        return 0;
    js_parse_get_pos(s, &pos);
    s->ts_quiet++;
    if (ts_is_word(s, "async") && next_token(s))
        goto back;
    if (s->token.val != TOK_FUNCTION || next_token(s))
        goto back;
    if (s->token.val == '*' && next_token(s))
        goto back;
    if (!token_is_ident(s->token.val) || next_token(s))
        goto back;
    if (s->token.val == '<' && ts_skip_bracketed(s))
        goto back;
    if (s->token.val != '(')
        goto back;
    tok = js_parse_skip_parens_token(s, NULL, FALSE);
    if (tok == '{')
        goto back;
    s->ts_quiet--;
    if (ts_skip_bracketed(s))
        return -1;
    if (ts_annotation(s))
        return -1;
    if (s->token.val == ';' && next_token(s))
        return -1;
    return 1;

 back:
    s->ts_quiet--;
    ts_clear_error(s);
    if (js_parse_seek_token(s, &pos))
        return -1;
    return 0;
}

/* js_parse_skip_parens_token() for the arrow-function test, telling the
   return-type extension whether it is inside the `?` branch of a
   conditional (see ts_arrow_body_then_colon). */
static int ts_skip_parens_arrow(JSParseState *s, BOOL in_cond_true)
{
    int tok;

    s->ts_arrow_in_cond = in_cond_true;
    tok = js_parse_skip_parens_token(s, NULL, TRUE);
    s->ts_arrow_in_cond = FALSE;
    return tok;
}

/* ------------------------------------- constructor parameter properties */

/* `constructor(public readonly x: number)` also assigns to `this`, so this
   is one of the three constructs here that emit code rather than erasing
   it. Returns 1 when a modifier was consumed. */
static int ts_param_modifiers(JSParseState *s)
{
    JSParsePos pos;
    int seen = 0;

    if (!s->ts)
        return 0;
    for (;;) {
        BOOL is_mod = s->token.val == TOK_PUBLIC || s->token.val == TOK_PRIVATE ||
            s->token.val == TOK_PROTECTED ||
            ts_is_word(s, "public") || ts_is_word(s, "private") ||
            ts_is_word(s, "protected") || ts_is_word(s, "readonly") ||
            ts_is_word(s, "override");
        if (!is_mod)
            return seen;
        js_parse_get_pos(s, &pos);
        if (next_token(s))
            return -1;
        /* a parameter that happens to be *named* `private` etc. */
        if (!(s->token.val == TOK_IDENT || s->token.val == TOK_THIS ||
              s->token.val == '{' || s->token.val == '[' ||
              ts_is_word(s, "readonly") || ts_is_word(s, "override"))) {
            if (js_parse_seek_token(s, &pos))
                return -1;
            return seen;
        }
        seen = 1;
    }
}

static void ts_record_param_prop(JSParseState *s, JSAtom name, int arg_idx)
{
    JSFunctionDef *fd = s->cur_func;
    TSParamProp *props;

    props = js_realloc(s->ctx, fd->ts_pprops,
                       sizeof(*props) * (fd->ts_pprop_count + 1));
    if (!props)
        return;
    fd->ts_pprops = props;
    props[fd->ts_pprop_count].name = JS_DupAtom(s->ctx, name);
    props[fd->ts_pprop_count].arg = arg_idx;
    fd->ts_pprop_count++;
}

/* Emit `this.<name> = <arg>` for each recorded parameter property. Called at
   the top of a base-class constructor body, and after `super(...)` in a
   derived one -- the same two places QuickJS initialises class fields. */
static void ts_emit_param_props(JSParseState *s)
{
    JSFunctionDef *fd = s->cur_func;
    int i;

    for (i = 0; i < fd->ts_pprop_count; i++) {
        emit_op(s, OP_scope_get_var);
        emit_atom(s, JS_ATOM_this);
        emit_u16(s, 0);
        emit_op(s, OP_get_arg);
        emit_u16(s, fd->ts_pprops[i].arg);
        emit_op(s, OP_put_field);
        emit_atom(s, fd->ts_pprops[i].name);
    }
}

/* `[key: string]: T;`: an index signature, erased whole. Returns 1 when one
   was consumed. */
static int ts_try_index_signature(JSParseState *s)
{
    JSParsePos pos;

    if (!s->ts || s->token.val != '[')
        return 0;
    js_parse_get_pos(s, &pos);
    if (next_token(s))
        return -1;
    if (s->token.val != TOK_IDENT || peek_token(s, FALSE) != ':') {
        if (js_parse_seek_token(s, &pos))
            return -1;
        return 0;
    }
    if (next_token(s))          /* the key name */
        return -1;
    if (next_token(s))          /* ':' */
        return -1;
    if (ts_skip_type(s))
        return -1;
    if (ts_expect(s, ']'))
        return -1;
    if (ts_annotation(s))
        return -1;
    if (s->token.val == ';' && next_token(s))
        return -1;
    return 1;
}

/* Constructs that emit code instead of erasing it. */
#include "quickts_enum.h"
#include "quickts_jsx.h"
