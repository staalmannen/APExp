/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Import( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *lib = NULL;
    char *type = NULL;
    char *sym = NULL;
    char *token = NULL;
    char *alias = NULL;
    char *ptr = NULL;
    long total = 0;
    if( NOT(ISTOKEN(arg, "FROM")) ){
    fprintf(stderr, "%sSyntax error: missing FROM in IMPORT statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( NOT(ISTOKEN(arg, "TYPE")) ){
    fprintf(stderr, "%sSyntax error: missing TYPE in IMPORT statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "IMPORT * FROM * TYPE * ALIAS *", b2c_option_delim);
    total = match__b2c_array;
    sym = b2c_CopyString(sym, (char*) EXTRACT(match[(uint64_t)1], CHR(34)));
    lib = b2c_CopyString(lib, (char*) match[(uint64_t)2]);
    type = b2c_CopyString(type, (char*) match[(uint64_t)3]);
    if( (total )> 3 ){
        alias = b2c_CopyString(alias, (char*) match[(uint64_t)4]);
        g_IMPORTED = F_CONCAT(g_IMPORTED, alias , " " , g_IMPORTED) ;
    }
    if( INSTR(sym, "(") ){
        token = b2c_CopyString(token, (char*) INBETWEEN(sym, "(", ")"));
        sym = F_CHOP(sym,TOKEN(sym, 1, "("));
    }
    if( NOT(INSTR(lib, "libc.so") )  AND  NOT(INSTR(lib, "libm.so")) ){
        if( NOT(TALLY(OS, "OSF1"))  AND  NOT(TALLY(OS, "BSD"))  AND  NOT(TALLY(OS, "Haiku"))  AND  NOT(INSTR(g_LDFLAGS, "-ldl")) ){
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " -ldl");
        }
        ptr = b2c_CopyString(ptr, (char*) EXTRACT(lib, "[[:punct:]]", TRUE));
        if( NOT(LEN(Get_Var( CONCAT("b2c_dlopen__pointer_" , ptr) , g_FUNCNAME))) ){
            if( ISTRUE(LEN(g_FUNCNAME)) ){
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "static void *b2c_dlopen__pointer_" , ptr , " = NULL;") ;
                Save_Func_Var( CONCAT("b2c_dlopen__pointer_" , ptr) , g_FUNCNAME, "void*");
            } else {
            fprintf(g_HFILE, "void* b2c_dlopen__pointer_%s = NULL;\n", ptr);
                Save_Main_Var( CONCAT("b2c_dlopen__pointer_" , ptr) , "void*");
            }
        }
    fprintf(g_CFILE, "if(b2c_dlopen__pointer_%s == NULL){b2c_dlopen__pointer_%s = dlopen(%s, RTLD_LAZY); if(b2c_dlopen__pointer_%s == NULL){ ERROR = 3; RUNTIMEERROR(\"IMPORT\", %s, \"%s\", ERROR, %s); } }\n", ptr, ptr, lib, ptr, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        if( __b2c__STRCMP(lib ,  "NULL") != 0 ){
        fprintf(g_HFILE, "%s(*%s)(%s);\n", type, sym, token);
        fprintf(g_CFILE, "*(%s**) (&%s) = (%s*)dlsym(b2c_dlopen__pointer_%s, \"%s\"); if(%s == NULL) { ERROR = 4; RUNTIMEERROR(\"IMPORT\", %s, \"%s\", ERROR, %s); }\n", type, sym, type, ptr, sym, sym, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        } else {
        fprintf(g_HFILE, "%s(*%s)(%s);\n", type, alias, token);
        fprintf(g_CFILE, "*(%s**) (&%s) = (%s*)dlsym(b2c_dlopen__pointer_%s, \"%s\"); if(%s == NULL) { ERROR = 4; RUNTIMEERROR(\"IMPORT\", %s, \"%s\", ERROR, %s); }\n", type, alias, type, ptr, sym, alias, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        }
    }
    if( __b2c__STRCMP(lib ,  "NULL") != 0 ){
        if( ISTOKEN(g_IMPORTED, sym) ){
            if( g_SEMANTIC == 0 ){
            fprintf(stderr, "%sWARNING: duplicate symbol '%s' at line %s in file '%s'!\n", NL, sym, STR( g_COUNTER), g_CURFILE);
            }
        } else {
            g_IMPORTED = F_APPEND(g_IMPORTED,g_IMPORTED, 0, sym);
        }
        if( LEN(alias) ){
        fprintf(g_HFILE, "#define %s %s\n", alias, sym);
        }
    }
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(lib);
    __b2c__STRFREE(type);
    __b2c__STRFREE(sym);
    __b2c__STRFREE(token);
    __b2c__STRFREE(alias);
    __b2c__STRFREE(ptr);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
