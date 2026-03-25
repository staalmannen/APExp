/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Lookup( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *source = NULL;
    char *to = NULL;
    char *size = NULL;
    char *sort = NULL;
    char *down = NULL;
    char *type = NULL;
    long total = 0;
    long use_sort = 0;
    long use_static = 0;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in LOOKUP statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( MATCH(COLLAPSE(arg), "* SORT *") ){
        use_sort=(
        long)( 1);
        arg = b2c_CopyString(arg, (char*) DEL(arg, ISTOKEN(arg, "SORT")));
    }
    if( ISTOKEN(arg, "DOWN") ){
        down = b2c_CopyString(down, (char*) "_down");
        arg = b2c_CopyString(arg, (char*) DEL(arg, ISTOKEN(arg, "DOWN")));
    }
    if( ISTOKEN(arg, "STATIC") ){
        use_static=(
        long)( 1);
        arg = b2c_CopyString(arg, (char*) DEL(arg, ISTOKEN(arg, "STATIC")));
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "LOOKUP * TO * SIZE *", b2c_option_delim);
    total = match__b2c_array;
    source = b2c_CopyString(source, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
    size = b2c_CopyString(size, (char*) IIF((total )> 2, match[(uint64_t)3]));
    if( Check_String_Type(to) == 0 ){
    fprintf(stderr, "%sSyntax error: variable %s in LOOKUP statement must be string at line %s in file '%s'!\n", NL, to, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( LEN(size) ){
        Register_Numeric(size, "default");
    }
    if( ISTRUE(LEN(g_FUNCNAME)) ){
        if( NOT(LEN(Get_Var(to, g_FUNCNAME))) ){
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
            g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " char **" , to , " = { NULL }; long " , to , "__b2c_array = 0;") ;
            Save_Func_Var(to, g_FUNCNAME, "char*");
            Save_Func_Var( CONCAT(to , "__b2c_array") , g_FUNCNAME, "long");
        }
    } else {
        if( NOT(LEN(Get_Var(to))) ){
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
        fprintf(g_HFILE, "char **%s = { NULL }; long %s__b2c_array = 0;\n", to, to);
            Save_Main_Var(to, "char*");
            Save_Main_Var( CONCAT(to , "__b2c_array") , "long");
        }
    }
    if( NOT(use_sort) ){
    fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_order(assoc_%s, &%s, %s__b2c_array, %s);\n", to, source, to, to, STR( g_OPTION_BASE));
    } else {
        type = b2c_CopyString(type, (char*) Get_Var( CONCAT("assoc_" , source) , g_FUNCNAME));
        if( REGEX(type, "char\\*|STRING") ){
        fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_sort(assoc_%s, &%s, %s__b2c_array, %s, 0, b2c_sortstr%s);\n", to, source, to, to, STR( g_OPTION_BASE), down);
        } else if( REGEX(type, "double|FLOATING") ){
        fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_sort(assoc_%s, &%s, %s__b2c_array, %s, 1, b2c_sortnrd_wrap%s);\n", to, source, to, to, STR( g_OPTION_BASE), down);
        } else if( REGEX(type, "float") ){
        fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_sort(assoc_%s, &%s, %s__b2c_array, %s, 2, b2c_sortnrf_wrap%s);\n", to, source, to, to, STR( g_OPTION_BASE), down);
        } else if( REGEX(type, "long|NUMBER") ){
        fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_sort(assoc_%s, &%s, %s__b2c_array, %s, 3, b2c_sortnrl_wrap%s);\n", to, source, to, to, STR( g_OPTION_BASE), down);
        } else if( REGEX(type, "int") ){
        fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_sort(assoc_%s, &%s, %s__b2c_array, %s, 4, b2c_sortnri_wrap%s);\n", to, source, to, to, STR( g_OPTION_BASE), down);
        } else if( REGEX(type, "short") ){
        fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_sort(assoc_%s, &%s, %s__b2c_array, %s, 5, b2c_sortnrs_wrap%s);\n", to, source, to, to, STR( g_OPTION_BASE), down);
        } else if( REGEX(type, "char") ){
        fprintf(g_CFILE, "%s__b2c_array = b2c_lookup_by_sort(assoc_%s, &%s, %s__b2c_array, %s, 6, b2c_sortnrc_wrap%s);\n", to, source, to, to, STR( g_OPTION_BASE), down);
        } else {
        fprintf(stderr, "%sSyntax error: unsupported array type in LOOKUP at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    }
    if( LEN(size) ){
    fprintf(g_CFILE, "%s = %s__b2c_array;\n", size, to);
    }
    if( NOT(use_static) ){
        if( ISTRUE(LEN(g_FUNCNAME))  AND  NOT(INSTR(g_STRINGARRAYS, CONCAT( to , "__b2c_array") )) ){
            g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_free_str_array_members(&" , to , ", " , STR(g_OPTION_BASE) , ", " , to , "__b2c_array);") ;
            g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , to) ;
        } else if( ISFALSE(LEN(g_FUNCNAME))  AND  NOT(INSTR(g_GLOBALARRAYS, CONCAT( to , "__b2c_array") )) ){
            g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " b2c_free_str_array_members(&" , to , ", " , STR(g_OPTION_BASE) , ", " , to , "__b2c_array); free(" , to , ");") ;
        }
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(source);
    __b2c__STRFREE(to);
    __b2c__STRFREE(size);
    __b2c__STRFREE(sort);
    __b2c__STRFREE(down);
    __b2c__STRFREE(type);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
