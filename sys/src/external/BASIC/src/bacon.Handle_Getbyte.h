/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Getbyte( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *var = NULL;
    char *from = NULL;
    char *size = NULL;
    char *type = NULL;
    char *chunk = NULL;
    long total = 0;
    if( NOT(ISTOKEN(arg, "FROM")) ){
    fprintf(stderr, "%sSyntax error: missing FROM in GETBYTE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( MATCH(COLLAPSE(arg), "* CHUNK *") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "GETBYTE * FROM * CHUNK * SIZE *", b2c_option_delim);
        total = match__b2c_array;
        chunk = b2c_CopyString(chunk, (char*) match[(uint64_t)3]);
        size = b2c_CopyString(size, (char*) IIF((total )> 3, match[(uint64_t)4]));
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "CHUNK")-1));
    } else if( MATCH(COLLAPSE(arg), "* SIZE *") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "GETBYTE * FROM * SIZE *", b2c_option_delim);
        size = b2c_CopyString(size, (char*) match[(uint64_t)3]);
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "SIZE")-1));
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "GETBYTE * FROM *", b2c_option_delim);
    var = b2c_CopyString(var, (char*) match[(uint64_t)1]);
    from = b2c_CopyString(from, (char*) match[(uint64_t)2]);
    if( LEN(size) ){
        if( LEN(chunk) == 0 ){
            chunk = b2c_CopyString(chunk, (char*) size);
            size = b2c_CopyString(size, (char*) "b2c_counter");
        }
    } else {
        if( LEN(chunk) == 0 ){
            chunk = b2c_CopyString(chunk, (char*) "1");
        }
        size = b2c_CopyString(size, (char*) "b2c_counter");
    }
    if( LEN(size)  AND  __b2c__STRCMP(size ,  "b2c_counter") != 0 ){
        Register_Numeric(size, "default");
    }
    type = b2c_CopyString(type, (char*) Get_Var(from, g_FUNCNAME));
fprintf(g_CFILE, "if(!b2c_memory__check((char*)%s, sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"GETBYTE\", %s, \"%s\", ERROR, %s); }\n", var, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( INSTR(type, "int") ){
    fprintf(g_CFILE, "if((%s = read(%s, (void*)(%s), %s)) < 0) { ERROR = 34; RUNTIMEERROR(\"GETBYTE\", %s, \"%s\", ERROR, %s); }\n", size, from, var, chunk, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else {
    fprintf(g_CFILE, "%s = fread((void*)(%s), sizeof(__b2c__MEMTYPE), %s, %s);\n", size, var, chunk, from);
    }
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(from);
    __b2c__STRFREE(size);
    __b2c__STRFREE(type);
    __b2c__STRFREE(chunk);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
