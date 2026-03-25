/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Swap( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *var = NULL;
    char *to = NULL;
    char *type = NULL;
    char *tmp = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty SWAP at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    var = F_CHOP(var,LEFT(arg, INSTR(arg, ",") - 1));
    to = F_CHOP(to,MID(arg, INSTR(arg, ",") + 1));
    if( Check_String_Type(var)  AND  NOT(Check_String_Type(to)) ){
    fprintf(g_CFILE, "b2c_assign = calloc(%s+1, sizeof(char)); if (floor(%s) == %s) { b2c_ctr = snprintf(b2c_assign, %s, \"%ld\", (long) %s); }\n", STR( g_MAX_DIGITS), to, to, STR( g_MAX_DIGITS), to);
    fprintf(g_CFILE, "else { b2c_ctr = snprintf (b2c_assign, %s, \"%g\", (double) %s); } %s = VAL(%s);%s = b2c_CopyString(%s, b2c_assign); free(b2c_assign);\n", STR( g_MAX_DIGITS), to, to, var, var, var);
    } else if( NOT(Check_String_Type(var))  AND  Check_String_Type(to) ){
    fprintf(g_CFILE, "b2c_assign = calloc(%s+1, sizeof(char)); if (floor(%s) == %s) { b2c_ctr = snprintf(b2c_assign, %s, \"%ld\", (long) %s); }\n", STR( g_MAX_DIGITS), var, var, STR( g_MAX_DIGITS), var);
    fprintf(g_CFILE, "else { b2c_ctr = snprintf (b2c_assign, %s, \"%g\", (double) %s); } %s = VAL(%s);%s = b2c_CopyString(%s, b2c_assign); free(b2c_assign);\n", STR( g_MAX_DIGITS), var, var, to, to, to);
    } else {
        if( Check_String_Type(var) ){
            type = b2c_CopyString(type, (char*) "char *");
        } else {
            type = b2c_CopyString(type, (char*) Get_Var(var, g_FUNCNAME));
            if( LEN(type) == 0 ){
            fprintf(stderr, "%sSyntax error: cannot determine type of variables in SWAP at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            }
            type = b2c_CopyString(type, (char*) LEFT(type, INSTR(type, "*")-1));
        }
        tmp = b2c_CopyString(tmp, (char*) IIF(INSTR(var, "["), LEFT(var, INSTR(var, "[")-1), var));
        if( (LEN(g_FUNCNAME) )> 0 ){
            if( NOT(LEN(Get_Var( CONCAT("__b2c__" , tmp , "_swap") , g_FUNCNAME))) ){
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " " , type , " __b2c__" , tmp , "_swap;") ;
                Save_Func_Var( CONCAT("__b2c__" , tmp , "_swap") , g_FUNCNAME, type);
            }
        } else {
            if( NOT(LEN(Get_Var( CONCAT("__b2c__" , tmp , "_swap") ))) ){
            fprintf(g_HFILE, "%s __b2c__%s_swap;\n", type, tmp);
                Save_Main_Var( CONCAT("__b2c__" , tmp , "_swap") , type);
            }
        }
    fprintf(g_CFILE, "__b2c__%s_swap = %s; %s = %s; %s = __b2c__%s_swap;\n", tmp, var, var, to, to, tmp);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(to);
    __b2c__STRFREE(type);
    __b2c__STRFREE(tmp);
    b2c_catch_set = b2c_catch_set_backup;
}
