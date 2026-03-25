/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Data( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *token = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty DATA at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    while( LEN(arg) ){
        token = b2c_CopyString(token, (char*) Mini_Parser(arg));
        if( INSTR(token, CHR(34)) ){
        fprintf(STRINGARRAYFILE, "%s, ", CHOP(token));
            fflush(STRINGARRAYFILE);
            g_CCTR = g_CCTR + (1);
        } else {
        fprintf(FLOATARRAYFILE, "%s, ", CHOP(token));
            fflush(FLOATARRAYFILE);
            g_FCTR = g_FCTR + (1);
        }
        arg = F_MID(arg,arg, LEN(token)+2);
    }
    if( INSTR(token, CHR(34)) ){
    fputs("\n", STRINGARRAYFILE);
    } else {
    fputs("\n", FLOATARRAYFILE);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(token);
    b2c_catch_set = b2c_catch_set_backup;
}
