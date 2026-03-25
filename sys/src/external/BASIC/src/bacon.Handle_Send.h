/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Send( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *var = NULL;
    char *to = NULL;
    char *chunk = NULL;
    char *size = NULL;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in SEND statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "SIZE") ){
        size = b2c_CopyString(size, (char*) LAST(arg, ISTOKEN(arg, "SIZE")));
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "SIZE")-1));
    }
    if( ISTOKEN(arg, "CHUNK") ){
        chunk = b2c_CopyString(chunk, (char*) LAST(arg, ISTOKEN(arg, "CHUNK")));
        arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "CHUNK")-1));
    }
    to = b2c_CopyString(to, (char*) LAST(arg, ISTOKEN(arg, "TO")));
    arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "TO")-1));
    var = F_CHOP(var,arg);
    if( LEN(chunk) == 0 ){
        chunk = F_CONCAT(chunk, "b2c_len(" , var , ")");
    }
    if( LEN(size) ){
        Register_Numeric(size, "default");
    } else {
        size = b2c_CopyString(size, (char*) "b2c_counter");
    }
    if( __b2c__STRCMP(g_NETWORKTYPE ,  "SCTP") == 0 ){
    fprintf(g_CFILE, "if((%s = sctp_sendmsg(%s, (void*)(%s), %s, NULL, 0, 0, 0, 0, 0, 0)) < 0) {\n", size, to, var, chunk);
    } else {
        if( g_OPTION_TLS ){
        fprintf(g_CFILE, "%s = SSL_write((SSL*)%s, (const void*)(%s), %s); if(%s <= 0) { fprintf(stderr, \"SSL WRITE error: %s\\n\", ERR_error_string(SSL_get_error((SSL*)%s, %s), NULL));\n", size, to, var, chunk, size, to, size);
        } else {
        fprintf(g_CFILE, "if((%s = send(%s, (void*)(%s), %s, 0)) < 0) {\n", size, to, var, chunk);
        }
    }
fprintf(g_CFILE, "ERROR = 15; RUNTIMEERROR(\"SEND\", %s, \"%s\", ERROR, %s); }\n", STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(to);
    __b2c__STRFREE(chunk);
    __b2c__STRFREE(size);
    b2c_catch_set = b2c_catch_set_backup;
}
