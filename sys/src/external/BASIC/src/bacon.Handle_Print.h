/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Print( char *arg_in, char *__b2c_std) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); char*std = NULL; std = b2c_CopyString(NULL, __b2c_std); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *exp = NULL;
    char *form = NULL;
    char *to = NULL;
    char *token = NULL;
    char *str = NULL;
    char *lft = NULL;
    long size = 0;
    long total = 0;
    if( ISTRUE(LEN(arg)) ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "PRINT * FORMAT * TO * SIZE *", b2c_option_delim);
        total = match__b2c_array;
        exp = b2c_CopyString(exp, (char*) IIF((total )> 0, match[(uint64_t)1]));
        form = b2c_CopyString(form, (char*) IIF((total )> 1, match[(uint64_t)2]));
        to = b2c_CopyString(to, (char*) IIF((total )> 2, match[(uint64_t)3]));
        size=(
        long)( IIF((total )> 3, VAL(match[(uint64_t)4]), g_BUFFER_SIZE));
        if( LEN(form) ){
            if( LEN(to) ){
                if( REGEX(to, CONCAT( g_STRINGSIGN , "$") ) ){
                    Register_Pointer(to, "char*");
                } else if( NOT(REGEX(to, CONCAT( g_STRINGSIGN , "\\(.*\\)$") )) ){
                fprintf(stderr, "%sSyntax error: variable for PRINT at line %s in file '%s' must be string!\n", NL, STR( g_COUNTER), g_CURFILE);
                    exit(1);
                }
                if( REGEX(to, "\\(.*\\)$") ){
                    str = b2c_CopyString(str, (char*) INBETWEEN(to, "(", ")", 2));
                    lft = F_MID(lft,to, 1, INSTR(to, "(")-1);
                fprintf(g_CFILE, "snprintf(b2c_hash_realloc_str_value(assoc_%s, %s+1, %s), %s+1, %s, %s);\n", lft, STR( size), str, STR( size), form, exp);
                    Relate_Recurse(lft, str, to, -1);
                } else {
                fprintf(g_CFILE, "%s = (char*)__b2c_str_realloc(%s, (%s+1)*sizeof(char));\n", to, to, STR( size));
                fprintf(g_CFILE, "snprintf(%s, %s+1, %s, %s); __b2c__SETLEN(%s, strlen(%s));\n", to, STR( size), form, exp, to, to);
                }
            } else {
            fprintf(g_CFILE, "fprintf(%s, %s, %s);\n", std, CHOP(form, ";", 2), exp);
            }
        } else {
            while( LEN(exp) ){
                token = b2c_CopyString(token, (char*) Mini_Parser(exp));
                Print_Element(CHOP(token), std);
                exp = F_MID(exp,exp, LEN(token)+1);
                if( (LEN(exp)  AND  __b2c__STRCMP(LEFT(exp) ,  ",") != 0  AND  __b2c__STRCMP(LEFT(exp) ,  ";") != 0)  OR  __b2c__STRCMP(CHOP(exp) ,  ",") == 0 ){
                fprintf(stderr, "%sSyntax error: malformed expression in PRINT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                    exit(1);
                }
                exp = F_MID(exp,exp, 2);
            }
            if( __b2c__STRCMP(RIGHT(arg, 1) ,  ";") != 0 ){
            fprintf(g_CFILE, "fputs(\"\\n\", %s);\n", std);
            } else {
            fprintf(g_CFILE, "fflush(%s);\n", std);
            }
        }
    } else {
    fprintf(g_CFILE, "fputs(\"\\n\", %s);\n", std);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(std);
    __b2c__STRFREE(exp);
    __b2c__STRFREE(form);
    __b2c__STRFREE(to);
    __b2c__STRFREE(token);
    __b2c__STRFREE(str);
    __b2c__STRFREE(lft);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
