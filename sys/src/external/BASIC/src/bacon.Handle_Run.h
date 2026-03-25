/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Run( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty RUN at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    if( TALLY(arg, CHR(34)) ){
        arg = b2c_CopyString(arg, (char*) EXTRACT(arg, CHR(34)));
    fprintf(g_CFILE, "execlp(%s%s%s,%s%s%s, NULL); fflush(stdout);\n", CHR(34), TOKEN(arg, 1), CHR(34), CHR(34), arg, CHR(34));
    } else {
    fprintf(g_CFILE, "execlp(%s,%s, NULL); fflush(stdout);\n", arg, arg);
    }

    __b2c__STRFREE(arg);
    b2c_catch_set = b2c_catch_set_backup;
}
