/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Getfile( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *var = NULL;
    char *from = NULL;
    char *type = NULL;
    char *ftype = NULL;
    if( NOT(ISTOKEN(arg, "FROM")) ){
    fprintf(stderr, "%sSyntax error: missing FROM in GETFILE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "FTYPE") ){
        ftype = b2c_CopyString(ftype, (char*) LAST(arg, ISTOKEN(arg, "FTYPE")));
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "FTYPE")-1));
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "GETFILE * FROM *", b2c_option_delim);
    var = b2c_CopyString(var, (char*) match[(uint64_t)1]);
    from = b2c_CopyString(from, (char*) match[(uint64_t)2]);
    if( NOT(Check_String_Type(var)) ){
    fprintf(stderr, "%sSyntax error: variable for GETFILE at line %s in file '%s' must be string!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( REGEX(var, CONCAT( g_STRINGSIGN , "$") ) ){
        Register_Pointer(var, "char*");
    }
    if( LEN(ftype) ){
        Register_Numeric(ftype, "default");
        type = b2c_CopyString(type, (char*) Get_Var(ftype, g_FUNCNAME));
    }
fprintf(g_CFILE, "b2c_getfile(__LINE__, __FILE__, &b2c_assign, %s, &b2c_counter);\n", from);
    Assign_To_String("b2c_assign", var, NULL);
    if( LEN(ftype) ){
    fprintf(g_CFILE, "%s = (%s)b2c_counter;\n", ftype, type);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(from);
    __b2c__STRFREE(type);
    __b2c__STRFREE(ftype);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
