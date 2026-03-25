/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Copy( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *from = NULL;
    char *to = NULL;
    char *size = NULL;
    long total = 0;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in COPY statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "COPY * TO * SIZE *", b2c_option_delim);
    total = match__b2c_array;
    from = b2c_CopyString(from, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
    size = b2c_CopyString(size, (char*) IIF((total )> 2, match[(uint64_t)3]));
    if( LEN(size) == 0 ){
    fprintf(g_CFILE, "if(b2c_copy(%s, %s)){ ERROR = 2; RUNTIMEERROR(\"COPY\", %s, \"%s\", ERROR, %s); }\n", from, to, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else {
    fprintf(g_CFILE, "if(!b2c_memory__check((char*)%s, sizeof(__b2c__MEMTYPE)*%s)) { ERROR=1; RUNTIMEERROR(\"COPY\", %s, \"%s\", ERROR, %s); }\n", to, size, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        if( INSTR(from, g_STRINGSIGN) ){
        fprintf(g_CFILE, "%s\n", CONCAT( "b2c_free_str_array_members(&" , to , ", " , STR(g_OPTION_BASE) , ", " , size , ");" ));
        fprintf(g_CFILE, "if(%s[b2c_ctr+%s]!=NULL) %s[b2c_ctr+%s]=strdup(%s[b2c_ctr+%s]);}\n", from, STR( g_OPTION_BASE), to, STR( g_OPTION_BASE), from, STR( g_OPTION_BASE));
        } else {
        fprintf(g_CFILE, "memmove((void*)%s, (void*)%s, sizeof(__b2c__MEMTYPE)*%s);\n", to, from, size);
        }
    }
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(from);
    __b2c__STRFREE(to);
    __b2c__STRFREE(size);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
