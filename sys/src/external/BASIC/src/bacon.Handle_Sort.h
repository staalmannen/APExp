/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Sort( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *source = NULL;
    char *size = NULL;
    char *type = NULL;
    char *down = NULL;
    long total = 0;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty SORT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "DOWN") ){
        down = b2c_CopyString(down, (char*) "_down");
        arg = b2c_CopyString(arg, (char*) DEL(arg, ISTOKEN(arg, "DOWN")));
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "SORT * SIZE *", b2c_option_delim);
    total = match__b2c_array;
    source = b2c_CopyString(source, (char*) match[(uint64_t)1]);
    size = b2c_CopyString(size, (char*) IIF((total )> 2, match[(uint64_t)2]));
    type = b2c_CopyString(type, (char*) Get_Var( CONCAT("assoc_" , source) , g_FUNCNAME));
    if( LEN(type) ){
        if( REGEX(type, "char\\*|STRING") ){
        fprintf(g_CFILE, "assoc_sort(&assoc_%s, 0, b2c_sortstr%s);\n", source, down);
        } else if( REGEX(type, "double|FLOATING") ){
        fprintf(g_CFILE, "assoc_sort(&assoc_%s, 1, b2c_sortnrd_wrap%s);\n", source, down);
        } else if( REGEX(type, "float") ){
        fprintf(g_CFILE, "assoc_sort(&assoc_%s, 2, b2c_sortnrf_wrap%s);\n", source, down);
        } else if( REGEX(type, "long|NUMBER") ){
        fprintf(g_CFILE, "assoc_sort(&assoc_%s, 3, b2c_sortnrl_wrap%s);\n", source, down);
        } else if( REGEX(type, "int") ){
        fprintf(g_CFILE, "assoc_sort(&assoc_%s, 4, b2c_sortnri_wrap%s);\n", source, down);
        } else if( REGEX(type, "short") ){
        fprintf(g_CFILE, "assoc_sort(&assoc_%s, 5, b2c_sortnrs_wrap%s);\n", source, down);
        } else if( REGEX(type, "char") ){
        fprintf(g_CFILE, "assoc_sort(&assoc_%s, 6, b2c_sortnrc_wrap%s);\n", source, down);
        } else {
        fprintf(stderr, "%sSyntax error: unsupported associative array type in SORT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else {
        type = b2c_CopyString(type, (char*) Get_Var(source, g_FUNCNAME));
        if( LEN(type) ){
            if( LEN(size) == 0 ){
                if( ISTOKEN(g_DYNAMICARRAYS, CONCAT( source , "@" , g_FUNCNAME) ) ){
                    size = F_CONCAT(size, source , "__b2c_array") ;
                } else {
                    size = F_CONCAT(size, "(sizeof(" , source , ")/sizeof(" , type , ")-" , STR(g_OPTION_BASE) , ")") ;
                }
            }
        } else {
        fprintf(stderr, "%sSyntax error: unknown array '%s' in SORT at line %s in file '%s'!\n", NL, source, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    fprintf(g_CFILE, "if((%s-%s) < 0) { ERROR=36; RUNTIMEERROR(\"SORT\",%s, \"%s\", ERROR, %s); }\n", size, STR( g_OPTION_BASE), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
            g_CATCH_USED=(long)( 1);
        }
        if( REGEX(source, CONCAT( g_STRINGSIGN , "$") ) ){
        fprintf(g_CFILE, "qsort(&%s[%s], %s, sizeof(char*), b2c_sortstr%s);\n", source, STR( g_OPTION_BASE), size, down);
        } else if( INSTR(type, "double")  OR  INSTR(type, "FLOATING") ){
        fprintf(g_CFILE, "qsort(&%s[%s], %s, sizeof(double), b2c_sortnrd%s);\n", source, STR( g_OPTION_BASE), size, down);
        } else if( INSTR(type, "float") ){
        fprintf(g_CFILE, "qsort(&%s[%s], %s, sizeof(float), b2c_sortnrf%s);\n", source, STR( g_OPTION_BASE), size, down);
        } else if( INSTR(type, "long")  OR  INSTR(type, "NUMBER") ){
        fprintf(g_CFILE, "qsort(&%s[%s], %s, sizeof(long), b2c_sortnrl%s);\n", source, STR( g_OPTION_BASE), size, down);
        } else if( INSTR(type, "int") ){
        fprintf(g_CFILE, "qsort(&%s[%s], %s, sizeof(int), b2c_sortnri%s);\n", source, STR( g_OPTION_BASE), size, down);
        } else if( INSTR(type, "short") ){
        fprintf(g_CFILE, "qsort(&%s[%s], %s, sizeof(short), b2c_sortnrs%s);\n", source, STR( g_OPTION_BASE), size, down);
        } else if( INSTR(type, "short") ){
        fprintf(g_CFILE, "qsort(&%s[%s], %s, sizeof(char), b2c_sortnrc%s);\n", source, STR( g_OPTION_BASE), size, down);
        } else {
        fprintf(stderr, "%sSyntax error: unsupported array type in SORT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(source);
    __b2c__STRFREE(size);
    __b2c__STRFREE(type);
    __b2c__STRFREE(down);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
