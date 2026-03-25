/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Rename( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *from = NULL;
    char *to = NULL;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in RENAME statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "RENAME * TO * ", b2c_option_delim);
    from = b2c_CopyString(from, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
fprintf(g_CFILE, "if(rename(%s, %s) < 0) { ERROR = 9; RUNTIMEERROR(\"RENAME\", %s, \"%s\", ERROR, %s); }\n", from, to, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(from);
    __b2c__STRFREE(to);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
