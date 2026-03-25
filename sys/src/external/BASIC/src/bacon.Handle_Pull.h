/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Pull( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty PULL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    if( NOT(REGEX(arg, "^[a-zA-Z]+.*")) ){
    fprintf(stderr, "%sSyntax error: argument in PULL statement at line %s in file '%s' is not a variable!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( REGEX(arg, CONCAT( g_STRINGSIGN , "$") ) ){
        Register_Pointer(arg, "char*");
    } else {
        Register_Numeric(arg, "default");
    }
fputs("SP--; if(SP >= 0) {\n", g_CFILE);
    if( Check_String_Type(arg) ){
        Assign_To_String("b2c_stack[SP]", arg, NULL);
    } else {
        Assign_To_Number("b2c_stack[SP]", arg, 1);
    }
fputs("} else { SP = 0; }\n", g_CFILE);

    __b2c__STRFREE(arg);
    b2c_catch_set = b2c_catch_set_backup;
}
