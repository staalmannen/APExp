/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Collect( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0; char *b2c_select_3829 = NULL;
    char *source = NULL;
    char *to = NULL;
    char *size = NULL;
    char *sort = NULL;
    char *func = NULL;
    char *type = NULL;
    long total = 0;
    long nr = 0;
    long use_static = 0;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in COLLECT statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "STATIC") ){
        use_static=(
        long)( 1);
        arg = b2c_CopyString(arg, (char*) DEL(arg, ISTOKEN(arg, "STATIC")));
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "COLLECT * TO * SIZE *", b2c_option_delim);
    total = match__b2c_array;
    source = b2c_CopyString(source, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
    size = b2c_CopyString(size, (char*) IIF((total )> 2, match[(uint64_t)3]));
    if( LEN(size) ){
        Register_Numeric(size, "default");
    }
    func = b2c_CopyString(func, (char*) Get_Var( CONCAT("b2c_tree_" , source) , g_FUNCNAME));
    type = b2c_CopyString(type, (char*) TOKEN(func, 2, ":"));
    if( ISTRUE(LEN(g_FUNCNAME)) ){
        if( NOT(LEN(Get_Var(to, g_FUNCNAME))) ){
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
            g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , type , "* " , to , " = { NULL }; long " , to , "__b2c_array = " , STR(g_OPTION_BASE) , ";") ;
            Save_Func_Var(to, g_FUNCNAME, CONCAT( type , "*") );
            Save_Func_Var( CONCAT(to , "__b2c_array") , g_FUNCNAME, "long");
        }
    } else {
        if( NOT(LEN(Get_Var(to))) ){
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
        fprintf(g_HFILE, "%s%s = { NULL }; long %s__b2c_array = %s;\n", CONCAT( type , "* "), to, to, STR( g_OPTION_BASE));
            Save_Main_Var(to, CONCAT( type , "*") );
            Save_Main_Var( CONCAT(to , "__b2c_array") , "long");
        }
    }
    b2c_select_3829 = b2c_CopyString(b2c_select_3829, type);
    if ( !b2c_strcmp(b2c_select_3829, "char*") || !b2c_strcmp(b2c_select_3829,  "STRING")){
        nr=(
        long)( 0);
    } else  if ( !b2c_strcmp(b2c_select_3829, "double") || !b2c_strcmp(b2c_select_3829,  "FLOATING")){
        nr=(
        long)( 1);
    } else  if ( !b2c_strcmp(b2c_select_3829, "float")){
        nr=(
        long)( 2);
    } else  if ( !b2c_strcmp(b2c_select_3829, "long") || !b2c_strcmp(b2c_select_3829,  "NUMBER")){
        nr=(
        long)( 3);
    } else  if ( !b2c_strcmp(b2c_select_3829, "int")){
        nr=(
        long)( 4);
    } else  if ( !b2c_strcmp(b2c_select_3829, "short")){
        nr=(
        long)( 5);
    } else  if ( !b2c_strcmp(b2c_select_3829, "char")){
        nr=(
        long)( 6);
    }
fprintf(g_CFILE, "%s__b2c_array = b2c_collect(%s, (void***)&%s, %s, %s);\n", to, source, to, STR( g_OPTION_BASE), STR( nr));
    if( LEN(size) ){
    fprintf(g_CFILE, "%s = %s__b2c_array;\n", size, to);
    }
    if( NOT(use_static) ){
        if( ISTRUE(LEN(g_FUNCNAME))  AND  NOT(INSTR(g_STRINGARRAYS, CONCAT( "(" , to , ")") )) ){
            g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " free(" , to , ");") ;
        } else if( ISFALSE(LEN(g_FUNCNAME))  AND  NOT(INSTR(g_GLOBALARRAYS, CONCAT( "(" , to , ")") )) ){
            g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " free(" , to , ");") ;
        }
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(source);
    __b2c__STRFREE(to);
    __b2c__STRFREE(size);
    __b2c__STRFREE(sort);
    __b2c__STRFREE(func);
    __b2c__STRFREE(type);
    __b2c__STRFREE(match);
    __b2c__STRFREE(b2c_select_3829);
    b2c_catch_set = b2c_catch_set_backup;
}
