/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Gotoxy( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *token = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty GOTOXY at at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    if( INSTR(arg, ",") ){
        token = b2c_CopyString(token, (char*) Mini_Parser(arg));
        arg = F_MID(arg,arg, LEN(token)+2);
    } else {
    fprintf(stderr, "%sSyntax error: missing coordinate in GOTOXY at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
fprintf(g_CFILE, "fprintf(stdout, \"\\033[%ld;%ldH\",(long)(%s), (long)(%s)); fflush(stdout);\n", CHOP(arg), CHOP(token));

    __b2c__STRFREE(arg);
    __b2c__STRFREE(token);
    b2c_catch_set = b2c_catch_set_backup;
}
