/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Setserial( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *desc = NULL;
    char *value = NULL;
    static char *param  = NULL;
    param  = b2c_CopyString(param ,  "0");
    static char *not  = NULL;
    not  = b2c_CopyString(not ,  "0");
    long which = 0;
    if( NOT(REGEX(arg, " IMODE | OMODE | CMODE | LMODE | OTHER | SPEED ")) ){
    fprintf(stderr, "%sSyntax error: no mode specified in SETSERIAL statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    desc = b2c_CopyString(desc, (char*) LEFT(arg, INSTR(arg, " ")));
    if( INSTR(arg, " OTHER ") ){
        value = F_MID(value,arg, INSTRREV(arg, "OTHER ")+6);
    } else if( INSTR(arg, " SPEED ") ){
        value = F_MID(value,arg, INSTRREV(arg, "SPEED ")+6);
    } else {
        value = F_MID(value,arg, INSTRREV(arg, "MODE ")+5);
    }
    if( INSTR(arg, "IMODE") ){
        which=(
        long)( 0);
    } else if( INSTR(arg, "OMODE") ){
        which=(
        long)( 1);
    } else if( INSTR(arg, "CMODE") ){
        which=(
        long)( 2);
    } else if( INSTR(arg, "LMODE") ){
        which=(
        long)( 3);
    } else if( INSTR(arg, "OTHER") ){
        which=(
        long)( 4);
        param = b2c_CopyString(param, (char*) TOKEN(value, 1, "="));
        value = b2c_CopyString(value, (char*) TOKEN(value, 2, "="));
    } else if( INSTR(arg, "SPEED") ){
        which=(
        long)( 5);
    }
    if( INSTR(value, "~") ){
        not = b2c_CopyString(not, (char*) "1");
    }
fprintf(g_CFILE, "ERROR = __b2c_setserial(%s, %s, %s, %s, %s);\n", desc, STR( which), param, value, not);
fprintf(g_CFILE, "if(ERROR){ RUNTIMEERROR(\"SETSERIAL\", %s, \"%s\", ERROR, %s); }\n", STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(desc);
    __b2c__STRFREE(value);
    b2c_catch_set = b2c_catch_set_backup;
}
