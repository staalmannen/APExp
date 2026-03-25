/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Join( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *source = NULL;
    char *by = NULL;
    char *to = NULL;
    char *size = NULL;
    char *type = NULL;
    long total = 0;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in JOIN statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "BY") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "JOIN * BY * TO * SIZE *", b2c_option_delim);
        by = b2c_CopyString(by, (char*) match[(uint64_t)2]);
        arg = F_APPEND(arg,HEAD(arg, ISTOKEN(arg, "BY")-1), 0, LAST(arg, ISTOKEN(arg, "TO")-1));
    } else {
        by = b2c_CopyString(by, (char*) "__b2c_EMPTYSTRING");
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "JOIN * TO * SIZE *", b2c_option_delim);
    total = match__b2c_array;
    source = b2c_CopyString(source, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
    size = b2c_CopyString(size, (char*) IIF((total )> 2, match[(uint64_t)3]));
    if( NOT(LEN(size)) ){
        if( ISTOKEN(g_DYNAMICARRAYS, CONCAT( source , "@" , g_FUNCNAME) ) ){
            size = F_CONCAT(size, source , "__b2c_array") ;
        } else {
            type = b2c_CopyString(type, (char*) Get_Var(source, g_FUNCNAME));
            size = F_CONCAT(size, "(sizeof(" , source , ")/sizeof(" , type , ")-" , STR(g_OPTION_BASE) , ")") ;
        }
    }
    if( Check_String_Type(to) == 0 ){
    fprintf(stderr, "%sSyntax error: variable %s in JOIN statement must be string at line %s in file '%s'!\n", NL, to, STR( g_COUNTER), g_CURFILE);
        exit(1);
    } else {
        if( REGEX(to, CONCAT( g_STRINGSIGN , "$") ) ){
            Register_Pointer(to, "char*");
        }
    }
fprintf(g_CFILE, "b2c_join(&b2c_assign, %s, %s, %s, %s);\n", source, STR( g_OPTION_BASE), size, by);
    Assign_To_String("b2c_assign", to, NULL);
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(source);
    __b2c__STRFREE(by);
    __b2c__STRFREE(to);
    __b2c__STRFREE(size);
    __b2c__STRFREE(type);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
