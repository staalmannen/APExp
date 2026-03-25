/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Receive( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *var = NULL;
    char *from = NULL;
    char *size = NULL;
    char *chunk = NULL;
    if( NOT(ISTOKEN(arg, "FROM")) ){
    fprintf(stderr, "%sSyntax error: missing FROM in RECEIVE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "SIZE") ){
        size = b2c_CopyString(size, (char*) LAST(arg, ISTOKEN(arg, "SIZE")));
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "SIZE")-1));
    }
    if( ISTOKEN(arg, "CHUNK") ){
        chunk = b2c_CopyString(chunk, (char*) LAST(arg, ISTOKEN(arg, "CHUNK")));
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "CHUNK")-1));
    } else {
        if( g_OPTION_TLS ){
            chunk = b2c_CopyString(chunk, (char*) "32768");
        } else {
            chunk = b2c_CopyString(chunk, (char*) STR(g_BUFFER_SIZE));
        }
    }
    from = b2c_CopyString(from, (char*) LAST(arg, ISTOKEN(arg, "FROM")));
    arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "FROM")-1));
    var = F_CHOP(var,arg);
    if( LEN(size) ){
        Register_Numeric(size, "default");
    } else {
        size = b2c_CopyString(size, (char*) "b2c_counter");
    }
    if( REGEX(var, CONCAT( g_STRINGSIGN , "$") ) ){
        Register_Pointer(var, "char*");
    }
fprintf(g_CFILE, "b2c_assign = (char*)calloc((%s+1), sizeof(char));\n", chunk);
    if( __b2c__STRCMP(g_NETWORKTYPE ,  "SCTP") == 0 ){
    fprintf(g_CFILE, "if((%s = sctp_recvmsg(%s, (void*)b2c_assign, %s, 0, 0, 0, 0)) < 0) {\n", size, from, chunk);
    } else {
        if( g_OPTION_TLS ){
        fprintf(g_CFILE, "if(%s > 0) { %s = SSL_read((SSL*)%s, (void*)b2c_assign, %s); } if(%s <= 0) { fprintf(stderr, \"SSL READ error in line %s: %s\\n\", ERR_error_string(SSL_get_error((SSL*)%s, %s), NULL));\n", from, size, from, chunk, size, STR( g_COUNTER), from, size);
        } else {
        fprintf(g_CFILE, "if((%s = recv(%s, (void*)b2c_assign, %s, 0)) < 0) {\n", size, from, chunk);
        }
    }
fprintf(g_CFILE, "ERROR = 14; RUNTIMEERROR(\"RECEIVE\", %s, \"%s\", ERROR, %s); }\n", STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    Assign_To_String("b2c_assign", var, size);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(from);
    __b2c__STRFREE(size);
    __b2c__STRFREE(chunk);
    b2c_catch_set = b2c_catch_set_backup;
}
