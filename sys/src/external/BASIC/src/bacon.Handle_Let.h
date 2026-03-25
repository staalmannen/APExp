/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Let( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    unsigned long x = 0;
    long in_string = 0;
    long escaped = 0;
    long pos = 0;
    long in_func = 0;
    char *var = NULL;
    char *tmp = NULL;
    char *str = NULL;
    char *lft = NULL;
    char *rel = NULL;
    char *ptr = NULL;
    char *type = NULL;
    char *item = NULL;
    for(x=1; x <= LEN(arg); x+=1){
        b2c_select_691 = (double)ASC(MID(arg, x, 1));
        if ( (b2c_select_691) == (92)){
            if( escaped ){
                escaped=(
                long)( FALSE);
            } else {
                escaped=(
                long)( TRUE);
            }
        } else  if ( (b2c_select_691) == (34)){
            if( ISFALSE(escaped) ){
                in_string=(
                long)( NOT(in_string));
            }
            escaped=(
            long)( FALSE);
        } else  if ( (b2c_select_691) == (40)){
            if( ISFALSE(in_string) ){
                in_func = in_func + (1);
            }
            escaped=(
            long)( FALSE);
        } else  if ( (b2c_select_691) == (41)){
            if( ISFALSE(in_string) ){
                in_func = in_func - (1);
            }
            escaped=(
            long)( FALSE);
        } else  if ( (b2c_select_691) == (61)){
            if( ISFALSE(in_string)  AND  ISFALSE(in_func) ){
                pos=(
                long)( x);
            }
            escaped=(
            long)( FALSE);
        } else {
            escaped=(
            long)( FALSE);
        }
    }
    if( NOT(pos) ){
        if( __b2c__STRCMP(g_IGNORE_PARSE ,  "0") == 0  OR  __b2c__STRCMP(g_IGNORE_PARSE ,  "FALSE") == 0 ){
        fprintf(g_CFILE, "%s;\n", arg);

            __b2c__STRFREE(arg);
            __b2c__STRFREE(var);
            __b2c__STRFREE(tmp);
            __b2c__STRFREE(str);
            __b2c__STRFREE(lft);
            __b2c__STRFREE(rel);
            __b2c__STRFREE(ptr);
            __b2c__STRFREE(type);
            __b2c__STRFREE(item);
            b2c_catch_set = b2c_catch_set_backup;
            return b2c_exitval;
        } else {
        fprintf(stderr, "%sSyntax error: could not parse line %s in file '%s': %s%s%s\n", NL, STR( g_COUNTER), g_CURFILE, CHR(34), arg, CHR(34));
            exit(1);
        }
    }
    var = F_CHOP(var,LEFT(arg, pos - 1));
    tmp = F_CHOP(tmp,MID(arg, pos + 1));
    if( REGEX(tmp, "[ \\t]*MEMORY[ \\t]*\\(")  OR  REGEX(tmp, "[ \\t]*BLOAD[ \\t]*\\(") ){
        b2c_hash_add_str(assoc_g_SEMANTIC_MEMFREE, CONCAT( "'" , var , "' at line " , STR(g_COUNTER) , " in file '" , g_CURFILE , "'"), var);
    }
    if( REGEX(var, CONCAT( g_STRINGSIGN , "$") )  AND  NOT(ISTOKEN(g_DYNAMICARRAYS, CONCAT( var , "@" , g_FUNCNAME) )) ){
        Register_Pointer(var, "char*");
    } else if( NOT(INSTR(var, "="))  AND  NOT(TALLY(var, "->")) ){
        if( REGEX(tmp, "[0-9]\\.[0-9]")  AND  NOT(INSTR(tmp, CHR(34))) ){
            Register_Numeric(EXTRACT(var, "[\\+\\-\\*/% ]", TRUE), "double");
        } else {
            Register_Numeric(EXTRACT(var, "[\\+\\-\\*/% ]", TRUE), "default");
        }
    }
    if( REGEX(var, "\\(.*\\)$") ){
        lft = b2c_CopyString(lft, (char*) LEFT(var, INSTR(var, "(") - 1));
        if( REGEX(var, "\\(\\)$") ){
            str = b2c_CopyString(str, (char*) LEFT(tmp, INSTR(tmp, "(") - 1));
            if( INSTR(lft, g_STRINGSIGN) ){
            fprintf(g_CFILE, "b2c_hash_dup_str(assoc_%s, assoc_%s);\n", str, lft);
            } else {
            fprintf(g_CFILE, "b2c_hash_dup(assoc_%s, assoc_%s);\n", str, lft);
            }
        } else {
            str = b2c_CopyString(str, (char*) INBETWEEN(var, "(", ")", 2));
            if( INSTR(lft, g_STRINGSIGN) ){
            fprintf(g_CFILE, "b2c_hash_add_str(assoc_%s, %s, %s);\n", lft, tmp, str);
            } else {
            fprintf(g_CFILE, "assoc_%s_eval = %s; b2c_hash_add(assoc_%s, &assoc_%s_eval, %s);\n", lft, tmp, lft, lft, str);
            }
            Relate_Recurse(lft, str, tmp, -1);
        }
    } else if( NOT(INSTR(var, "["))  AND  ISTOKEN(g_DYNAMICARRAYS, CONCAT( var , "@" , g_FUNCNAME) ) ){
        if( INSTR(var, g_STRINGSIGN) ){
        fprintf(g_CFILE, "%s\n", CONCAT( "b2c_free_str_array_members(&" , var , ", " , STR(g_OPTION_BASE) , ", " , var , "__b2c_array);" ));
        }
    fprintf(g_CFILE, "free(%s);\n", var);
    fprintf(g_CFILE, "%s%s;\n", g_WITHVAR, arg);
    } else if( Check_String_Type(var)  AND  REGEX(var, g_STRINGSIGN) ){
        type = b2c_CopyString(type, (char*) Get_Var(var, g_FUNCNAME));
        if( INSTR(type, "const") ){
        fprintf(g_CFILE, "%s%s = (char*)b2c_strdup((const char*)%s);\n", g_WITHVAR, var, tmp);
            if( ISTRUE(LEN(g_FUNCNAME)) ){
                Save_Func_Var(var, g_FUNCNAME, CHOP(EXTRACT(type, "const")));
            } else {
                Save_Main_Var(var, CHOP(EXTRACT(type, "const")));
            }
        } else {
            str = b2c_CopyString(str, (char*) HEAD(EXTRACT(tmp, " "), 1, "("));
            if( REGEX(str, CONCAT( "^CONCAT" , g_STRINGSIGN , "|^MID" , g_STRINGSIGN , "|^APPEND" , g_STRINGSIGN , "|^CHOP" , g_STRINGSIGN) ) ){
            fprintf(g_CFILE, "%s%s = F_%s(%s%s,%s;\n", g_WITHVAR, var, str, g_WITHVAR, var, LAST(tmp, 1, "("));
            } else {
            fprintf(g_CFILE, "%s%s = b2c_CopyString(%s%s, (char*)%s);\n", g_WITHVAR, var, g_WITHVAR, var, tmp);
            }
        }
        ptr = b2c_CopyString(ptr, (char*) EXTRACT(var, "[[:punct:]]", TRUE));
        if( LEN(Get_Var( CONCAT("b2c_dlopen__pointer_" , ptr) )) ){
        fprintf(g_CFILE, "b2c_dlopen__pointer_%s = dlopen(%s, RTLD_LAZY); if(b2c_dlopen__pointer_%s == NULL) { ERROR = 3; RUNTIMEERROR(\"IMPORT\", %s, \"%s\", ERROR, %s); }\n", ptr, var, ptr, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        }
        if( INSTR(var, ".")  AND  REGEX(var, "\\[.*\\]\\.")  AND  LEN(g_FUNCNAME)  AND  NOT(LEN(Get_Var(var))) ){
            if( NOT(INSTR(g_LOCALSTRINGS, var))  AND  NOT(REGEX(var, "\\[.*\\]$")) ){
                g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, var , " " , g_LOCALSTRINGS) ;
            }
        }
    } else if( TALLY(var, "->") ){
    fprintf(g_CFILE, "%s%s;\n", g_WITHVAR, arg);
    } else if( NOT(REGEX(var, CONCAT( g_STRINGSIGN , "$") ))  AND  REGEX(tmp, CONCAT( g_STRINGSIGN , "$") ) ){
        type = b2c_CopyString(type, (char*) EXTRACT(Get_Var(var, g_FUNCNAME), "static"));
    fprintf(g_CFILE, "%s%s=(%s)(%s);\n", g_WITHVAR, var, type, tmp);
    } else {
        type = b2c_CopyString(type, (char*) EXTRACT(Get_Var(var, g_FUNCNAME), "static"));
        if( REGEX(type, "float|double|FLOATING")  AND  NOT(INSTR(type, "*")) ){
        fprintf(g_CFILE, "%s%s=(%s)(%s);\n", g_WITHVAR, var, type, DELIM(tmp, "/", CONCAT( "/(" , type , ")") ));
        } else if( REGEX(var, ".*\\[.*\\].*")  AND  REGEX(type, ".*\\*.*") ){
        fprintf(g_CFILE, "%s%s;\n", g_WITHVAR, arg);
        } else if( LEN(type)  AND  __b2c__STRCMP(LEFT(var) ,  "*") != 0 ){
        fprintf(g_CFILE, "%s%s=(%s)(%s);\n", g_WITHVAR, var, type, tmp);
        } else {
        fprintf(g_CFILE, "%s%s;\n", g_WITHVAR, arg);
        }
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(tmp);
    __b2c__STRFREE(str);
    __b2c__STRFREE(lft);
    __b2c__STRFREE(rel);
    __b2c__STRFREE(ptr);
    __b2c__STRFREE(type);
    __b2c__STRFREE(item);
    b2c_catch_set = b2c_catch_set_backup;
}
