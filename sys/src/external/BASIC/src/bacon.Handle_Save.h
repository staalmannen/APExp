/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Save( long type, char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *var = NULL;
    char *to = NULL;
    char *size = NULL;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: SAVE/BSAVE/APPEND/BAPPEND without TO at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "SIZE") ){
        size = b2c_CopyString(size, (char*) LAST(arg, ISTOKEN(arg, "SIZE")));
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "SIZE")-1));
    } else {
        size = b2c_CopyString(size, (char*) "0");
    }
    to = b2c_CopyString(to, (char*) LAST(arg, ISTOKEN(arg, "TO")));
    arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "TO")-1));
    var = F_CHOP(var,arg);
fprintf(g_CFILE, "ERROR = b2c_save(%s, %s, %s, %s, NULL);\n", STR( type), size, to, var);
fprintf(g_CFILE, "if(ERROR) { RUNTIMEERROR(\"SAVE/BSAVE/APPEND/BAPPEND\", %s, \"%s\", ERROR, %s); }\n", STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(to);
    __b2c__STRFREE(size);
    b2c_catch_set = b2c_catch_set_backup;
}
