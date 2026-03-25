/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Open( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0; char *b2c_select_885 = NULL;
    long check = 0;
    char *var = NULL;
    char *mode = NULL;
    char *handle = NULL;
    static char *from  = NULL;
    from  = b2c_CopyString(from ,  "NULL");
    if( NOT(ISTOKEN(arg, "FOR")) ){
    fprintf(stderr, "%sSyntax error: missing FOR in OPEN statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( NOT(ISTOKEN(arg, "AS")) ){
    fprintf(stderr, "%sSyntax error: missing AS in OPEN statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "FROM") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "OPEN * FOR * FROM * AS *", b2c_option_delim);
        from = b2c_CopyString(from, (char*) match[(uint64_t)3]);
        arg = F_APPEND(arg,HEAD(arg, ISTOKEN(arg, "FROM")-1), 0, LAST(arg, ISTOKEN(arg, "AS")-1));
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "OPEN * FOR * AS *", b2c_option_delim);
    var = b2c_CopyString(var, (char*) match[(uint64_t)1]);
    mode = b2c_CopyString(mode, (char*) match[(uint64_t)2]);
    handle = b2c_CopyString(handle, (char*) match[(uint64_t)3]);
    if( REGEX(handle, CONCAT( g_STRINGSIGN , "$") )  AND  __b2c__STRCMP(mode ,  "MEMORY") != 0 ){
    fprintf(stderr, "%sSyntax error: variable for OPEN at line %s in file '%s' cannot be string!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_hash_add_str(assoc_g_SEMANTIC_OPENCLOSE, CONCAT( "'" , handle , "' at line " , STR(g_COUNTER) , " in file '" , g_CURFILE , "'"), handle);
    if( NOT(INSTR(handle, ".")) ){
        check=(
        long)( LEN(Get_Var(handle, g_FUNCNAME)));
    } else {
        check=(
        long)( TRUE);
    }
    if( ISFALSE(check) ){
        if( __b2c__STRCMP(mode ,  "DIRECTORY") == 0 ){
            Register_Pointer(handle, "DIR*");
        } else if( __b2c__STRCMP(mode ,  "MEMORY") == 0 ){
            Register_Pointer(handle, "char*");
        } else if( __b2c__STRCMP(mode ,  "NETWORK") == 0  OR  __b2c__STRCMP(mode ,  "SERVER") == 0  OR  __b2c__STRCMP(mode ,  "UDP") == 0  OR  __b2c__STRCMP(mode ,  "DEVICE") == 0 ){
            Register_Numeric(handle, "uintptr_t");
        } else {
            Register_Pointer(handle, "FILE*");
        }
    }
    b2c_select_885 = b2c_CopyString(b2c_select_885, mode);
    if ( !b2c_strcmp(b2c_select_885, "READING")){
    fprintf(g_CFILE, "%s = fopen((const char*)%s, \"r\");\n", handle, var);
    fprintf(g_CFILE, "if(%s == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR READING\", %s, \"%s\", ERROR, %s); }\n", handle, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "WRITING")){
    fprintf(g_CFILE, "%s = fopen((const char*)%s, \"w\");\n", handle, var);
    fprintf(g_CFILE, "if(%s == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR WRITING\", %s, \"%s\", ERROR, %s); }\n", handle, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "APPENDING")){
    fprintf(g_CFILE, "%s = fopen((const char*)%s, \"a\");\n", handle, var);
    fprintf(g_CFILE, "if(%s == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR APPENDING\", %s, \"%s\", ERROR, %s); }\n", handle, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "READWRITE")){
    fprintf(g_CFILE, "%s = fopen((const char*)%s, \"r+\");\n", handle, var);
    fprintf(g_CFILE, "if(%s == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR READWRITE\", %s, \"%s\", ERROR, %s); }\n", handle, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "DIRECTORY")){
    fprintf(g_CFILE, "%s = opendir(%s);\n", handle, var);
    fprintf(g_CFILE, "if(%s == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR DIRECTORY\", %s, \"%s\", ERROR, %s); }\n", handle, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "MEMORY")){
        if( NOT(LEN(Get_Var( CONCAT("__b2c_mem_" , handle) , g_FUNCNAME))) ){
        fprintf(g_HFILE, "%s = 0;\n", CONCAT( "long __b2c_mem_" , handle));
            Save_Main_Var( CONCAT("__b2c_mem_" , handle) , "long");
        }
        if( INSTR(handle, g_STRINGSIGN) ){
        fprintf(g_CFILE, "__b2c__STRFREE(%s);\n", handle);
        }
    fprintf(g_CFILE, "%s = (char*)%s; __b2c_mem_%s = (uintptr_t)%s;\n", handle, var, handle, var);
    fprintf(g_CFILE, "if(!b2c_memory__check(%s, sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"OPEN FOR MEMORY\", %s, \"%s\", ERROR, %s); }\n", handle, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "NETWORK")){
    fprintf(g_CFILE, "ERROR = b2c_network_init((uintptr_t*)&%s, %s, %s, %s, %s, \"%s\", %s, %s, b2c_capeer, b2c_cacerts, b2c_caprivate, b2c_caserver);\n", handle, var, from, g_SOCKTYPE, STR( g_OPTION_SOCKET), g_NETWORKTYPE, STR( g_MULTICAST_TTL), STR( g_SCTP_STREAMS));
    fprintf(g_CFILE, "if(ERROR){ RUNTIMEERROR(\"OPEN FOR NETWORK\", %s, \"%s\", ERROR, %s); }\n", STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "SERVER")){
    fprintf(g_CFILE, "ERROR = b2c_server_init((uintptr_t*)&%s, %s, %s, %s, %s);\n", handle, var, g_SOCKTYPE, STR( g_OPTION_SOCKET), STR( g_SCTP_STREAMS));
    fprintf(g_CFILE, "if(ERROR ){ RUNTIMEERROR(\"OPEN FOR SERVER\", %s, \"%s\", ERROR, %s); }\n", STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else  if ( !b2c_strcmp(b2c_select_885, "DEVICE")){
    fprintf(g_CFILE, "%s = open(%s, b2c_option_open, S_IRUSR|S_IWUSR); if(%s < 0){ ERROR = 32; RUNTIMEERROR(\"OPEN FOR DEVICE\", %s, \"%s\", ERROR, %s); }\n", handle, var, handle, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    } else {
    fprintf(stderr, "%sSyntax error: wrong mode '%s' to OPEN statement at line %s in file '%s'!\n", NL, mode, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(mode);
    __b2c__STRFREE(handle);
    __b2c__STRFREE(match);
    __b2c__STRFREE(b2c_select_885);
    b2c_catch_set = b2c_catch_set_backup;
}
