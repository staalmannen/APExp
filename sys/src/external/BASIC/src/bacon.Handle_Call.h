/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Call( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *var = NULL;
    char *lft = NULL;
    char *str = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty CALL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    if( NOT(REGEX(TOKEN(arg, 1, " TO "), "\\(.*\\)")) ){
        if( INSTR(arg, " TO ") ){
            arg = F_CONCAT(arg, TOKEN(arg, 1, " TO ") , "() TO " , TOKEN(arg, 2, " TO ")) ;
        } else {
            arg = F_CONCAT(arg, arg , "()") ;
        }
    }
    if( NOT(INSTR(arg, " TO ")) ){
    fprintf(g_CFILE, "%s;\n", arg);
    } else {
        var = F_CHOP(var,TOKEN(arg, 2, " TO "));
        if( REGEX(var, CONCAT( g_STRINGSIGN , "$") ) ){
            Register_Pointer(var, "char*");
        } else {
            Register_Numeric(var, "default");
        }
        if( Check_String_Type(var) ){
        fprintf(g_CFILE, "b2c_assign = %s;\n", TOKEN(arg, 1, " TO "));
            Assign_To_String("b2c_assign", var, NULL);
        } else {
            Assign_To_Number(TOKEN(arg, 1, " TO "), var, 0);
        }
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(lft);
    __b2c__STRFREE(str);
    b2c_catch_set = b2c_catch_set_backup;
}
