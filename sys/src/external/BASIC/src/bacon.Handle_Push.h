/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Push( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty PUSH at at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    if( NOT(INSTR(g_GLOBALARRAYS, "b2c_stack")) ){
        g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " b2c_free_str_array_members(&b2c_stack, " , STR(g_OPTION_BASE) , ", SP); free(b2c_stack);");
    }
fputs("b2c_stack = (char**)realloc(b2c_stack, (SP+1)*sizeof(char*));\n", g_CFILE);
    if( Check_String_Type(arg) ){
    fprintf(g_CFILE, "b2c_stack[SP] = b2c_CopyString(NULL, %s);\n", arg);
    } else {
    fprintf(g_CFILE, "b2c_stack[SP] = calloc(%s, sizeof(char)); snprintf(b2c_stack[SP], %s, \"%g\", (double)(%s));\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS-1), arg);
    }
fputs("SP++;\n", g_CFILE);

    __b2c__STRFREE(arg);
    b2c_catch_set = b2c_catch_set_backup;
}
