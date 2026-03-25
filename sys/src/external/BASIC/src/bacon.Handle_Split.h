/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Split( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *source = NULL;
    char *by = NULL;
    char *to = NULL;
    char *size = NULL;
    long use_static = 0;
    long total = 0;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in SPLIT statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "STATIC") ){
        use_static=(
        long)( 1);
        arg = b2c_CopyString(arg, (char*) DEL(arg, ISTOKEN(arg, "STATIC")));
    }
    if( ISTOKEN(arg, "BY") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "SPLIT * BY * TO * SIZE *", b2c_option_delim);
        by = b2c_CopyString(by, (char*) match[(uint64_t)2]);
        arg = F_APPEND(arg,HEAD(arg, ISTOKEN(arg, "BY")-1), 0, LAST(arg, ISTOKEN(arg, "TO")-1));
    } else {
        by = b2c_CopyString(by, (char*) "b2c_option_delim");
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "SPLIT * TO * SIZE *", b2c_option_delim);
    total = match__b2c_array;
    source = b2c_CopyString(source, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
    size = b2c_CopyString(size, (char*) IIF((total )> 2, match[(uint64_t)3]));
    if( Check_String_Type(to) == 0 ){
    fprintf(stderr, "%sSyntax error: variable %s in SPLIT statement must be string at line %s in file '%s'!\n", NL, to, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( LEN(size) ){
        Register_Numeric(size, "default");
    }
    if( ISTRUE(LEN(g_FUNCNAME)) ){
        if( NOT(LEN(Get_Var(to, g_FUNCNAME))) ){
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
            g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " char **" , to , " = NULL; long " , CHOP(to) , "__b2c_array = 0;") ;
            Save_Func_Var(to, g_FUNCNAME, "char*");
            Save_Func_Var( CONCAT(to , "__b2c_array") , g_FUNCNAME, "long");
        }
    } else {
        if( NOT(LEN(Get_Var(to))) ){
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
        fprintf(g_HFILE, "char **%s = NULL; long %s__b2c_array = 0;\n", to, CHOP(to));
            Save_Main_Var(to, "char*");
            Save_Main_Var( CONCAT(to , "__b2c_array") , "long");
        }
    }
    if( Check_String_Type(by)  OR  __b2c__STRCMP(by ,  "b2c_option_delim") == 0 ){
    fprintf(g_CFILE, "b2c_split_by(&%s, %s, &%s__b2c_array, %s, %s);\n", to, STR( g_OPTION_BASE), to, source, by);
    } else {
    fprintf(g_CFILE, "b2c_split_with(&%s, %s, &%s__b2c_array, %s, %s);\n", to, STR( g_OPTION_BASE), to, source, by);
    }
    if( LEN(size) ){
    fprintf(g_CFILE, "%s = %s__b2c_array;\n", size, to);
    }
    if( NOT(use_static) ){
        if( ISTRUE(LEN(g_FUNCNAME))  AND  NOT(INSTR(g_STRINGARRAYS, to)) ){
            g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_free_str_array_members(&" , to , ", " , STR(g_OPTION_BASE) , ", " , to , "__b2c_array);") ;
            g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , to) ;
        } else if( ISFALSE(LEN(g_FUNCNAME))  AND  NOT(INSTR(g_GLOBALARRAYS, to)) ){
            g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " b2c_free_str_array_members(&" , to , ", " , STR(g_OPTION_BASE) , ", " , to , "__b2c_array); free(" , to , ");") ;
        }
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(source);
    __b2c__STRFREE(by);
    __b2c__STRFREE(to);
    __b2c__STRFREE(size);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
