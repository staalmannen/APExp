/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Input( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *type = NULL;
    char *lft = NULL;
    char *str = NULL;
    char *token = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty INPUT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    while( LEN(arg) ){
        token = b2c_CopyString(token, (char*) Mini_Parser(arg));
        arg = F_MID(arg,arg, LEN(token)+1);
        if( LEN(arg) ){
            if( __b2c__STRCMP(LEFT(arg) ,  ",") != 0  OR  __b2c__STRCMP(CHOP(arg) ,  ",") == 0 ){
            fprintf(stderr, "%sSyntax error: malformed expression in INPUT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            } else {
                Print_Element(CHOP(token), "stdout");
            }
        }
        arg = F_MID(arg,arg, 2);
    }
fputs("fflush(stdout);\n", g_CFILE);
    arg = F_CHOP(arg,token);
    if( NOT(REGEX(arg, "^[a-zA-Z]+.*")) ){
    fprintf(stderr, "%sSyntax error: argument in INPUT statement at line %s in file '%s' is not a variable!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( REGEX(arg, CONCAT( g_STRINGSIGN , "$") ) ){
        Register_Pointer(arg, "char*");
    } else {
        Register_Numeric(arg, "default");
    }
fprintf(g_CFILE, "b2c_input(__LINE__, __FILE__, &b2c_assign, %s);\n", g_OPTION_INPUT);
    if( Check_String_Type(arg) ){
        Assign_To_String("b2c_assign", arg, NULL);
    } else {
        Assign_To_Number("b2c_assign", arg, 1);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(type);
    __b2c__STRFREE(lft);
    __b2c__STRFREE(str);
    __b2c__STRFREE(token);
    b2c_catch_set = b2c_catch_set_backup;
}
