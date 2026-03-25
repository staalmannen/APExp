/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Download_File( char *__b2c_name) {
    char*name = NULL; name = b2c_CopyString(NULL, __b2c_name); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *total = NULL;
    char *dat = NULL;
    char *proxy = NULL;
    char *unpw = NULL;
    long length = 0;
    long size = 0;
    long mynet = 0;
    b2c_catch_set = 1;
    proxy = b2c_CopyString(proxy, (char*) GETENVIRON("HTTP_PROXY"));
    if( LEN(proxy) == 0 ){
        proxy = b2c_CopyString(proxy, (char*) GETENVIRON("http_proxy"));
    }
    if( LEN(proxy) ){
        if( __b2c__STRCMP(LEFT(proxy, 7) ,  "http://") != 0 ){
        fprintf(stderr, "System error: proxy '%s' not supported! Redefine to default HTTP proxy or undefine.\n", proxy);
            exit(1);
        }
        proxy = F_MID(proxy,proxy, 8);
        if( TALLY(proxy, "@") ){
            unpw = b2c_CopyString(unpw, (char*) B64ENC(TOKEN(proxy, 1, "@")));
            proxy = b2c_CopyString(proxy, (char*) TOKEN(proxy, 2, "@"));
        }
        ERROR = b2c_network_init((uintptr_t*)&mynet, proxy, NULL, SOCK_STREAM, 5, "TCP", 1, 1, b2c_capeer, b2c_cacerts, b2c_caprivate, b2c_caserver);
    if(ERROR){ RUNTIMEERROR("OPEN FOR NETWORK", 6855, "../bacon.bac", ERROR, network_error); }
        if((b2c_counter = send(mynet, (void*)(CONCAT( "CONNECT " , TOKEN(name, 1, "/") , ":80 HTTP/1.1" , "\r\n" )), b2c_len(CONCAT( "CONNECT " , TOKEN(name, 1, "/") , ":80 HTTP/1.1" , "\r\n" )), 0)) < 0) {
        ERROR = 15; RUNTIMEERROR("SEND", 6857, "../bacon.bac", ERROR, network_error); }
        if( LEN(unpw) ){
            if((b2c_counter = send(mynet, (void*)(CONCAT( "Proxy-Authorization: Basic " , B64ENC(unpw) , "\r\n" )), b2c_len(CONCAT( "Proxy-Authorization: Basic " , B64ENC(unpw) , "\r\n" )), 0)) < 0) {
            ERROR = 15; RUNTIMEERROR("SEND", 6858, "../bacon.bac", ERROR, network_error); }
        }
        if((b2c_counter = send(mynet, (void*)("\r\n"), b2c_len("\r\n"), 0)) < 0) {
        ERROR = 15; RUNTIMEERROR("SEND", 6859, "../bacon.bac", ERROR, network_error); }
        b2c_assign = (char*)calloc((512+1), sizeof(char));
        if((b2c_counter = recv(mynet, (void*)b2c_assign, 512, 0)) < 0) {
        ERROR = 14; RUNTIMEERROR("RECEIVE", 6862, "../bacon.bac", ERROR, network_error); }
        dat = b2c_CopyString(dat, b2c_assign);
        __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
        if( NOT(TALLY(dat, " 200 ")) ){
        fprintf(stderr, "System error: proxy '%s%s\n", proxy, CONCAT( "' returns error: " , dat));
            exit(1);
        }
    } else {
        ERROR = b2c_network_init((uintptr_t*)&mynet, CONCAT( TOKEN(name, 1, "/") , ":80" ), NULL, SOCK_STREAM, 5, "TCP", 1, 1, b2c_capeer, b2c_cacerts, b2c_caprivate, b2c_caserver);
    if(ERROR){ RUNTIMEERROR("OPEN FOR NETWORK", 6869, "../bacon.bac", ERROR, network_error); }
    }
fputs("Fetching file...", stdout);
    fflush(stdout);
    if((b2c_counter = send(mynet, (void*)(CONCAT( "HEAD /" , MID(name, INSTR(name, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN(name, 1, "/") , "\r\n\r\n" )), b2c_len(CONCAT( "HEAD /" , MID(name, INSTR(name, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN(name, 1, "/") , "\r\n\r\n" )), 0)) < 0) {
    ERROR = 15; RUNTIMEERROR("SEND", 6874, "../bacon.bac", ERROR, network_error); }
    b2c_assign = (char*)calloc((512+1), sizeof(char));
    if((b2c_counter = recv(mynet, (void*)b2c_assign, 512, 0)) < 0) {
    ERROR = 14; RUNTIMEERROR("RECEIVE", 6875, "../bacon.bac", ERROR, network_error); }
    dat = b2c_CopyString(dat, b2c_assign);
    __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
    if( NOT(INSTR(dat, "Content-Length:")) ){
    fputs("System error: file not found! Check URL and try again.\n", stderr);
        exit(1);
    }
    dat = F_MID(dat,dat, INSTR(dat, "Content-Length:")+15);
    length=(
    long)( VAL(LEFT(dat, INSTR(dat, NL))));
    if((b2c_counter = send(mynet, (void*)(CONCAT( "GET /" , MID(name, INSTR(name, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN(name, 1, "/") , "\r\n\r\n" )), b2c_len(CONCAT( "GET /" , MID(name, INSTR(name, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN(name, 1, "/") , "\r\n\r\n" )), 0)) < 0) {
    ERROR = 15; RUNTIMEERROR("SEND", 6887, "../bacon.bac", ERROR, network_error); }
    while( WAIT(mynet, 2000) ){
        b2c_assign = (char*)calloc((128+1), sizeof(char));
        if((size = recv(mynet, (void*)b2c_assign, 128, 0)) < 0) {
        ERROR = 14; RUNTIMEERROR("RECEIVE", 6889, "../bacon.bac", ERROR, network_error); }
        dat = b2c_CopyString(dat, b2c_assign);
        __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
        if( size == 0 ){
            break;
        }
    fputs(".", stderr);
        fflush(stderr);
        total = F_CONCAT(total, total , dat) ;
    }
    shutdown((uintptr_t)mynet, SHUT_RDWR);
    close((uintptr_t)mynet);
    total = F_MID(total,total, INSTR(total, "\r\n\r\n")+4);
    if( LEN(total) != length ){
    fprintf(stderr, "System error: file %s could not be downloaded probably due to a timeout. Try again later.\n", name);
        exit(1);
    }
    ERROR = b2c_save(0, 0, MID(name, INSTRREV(name, "/")+1), total, NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 6906, "../bacon.bac", ERROR, network_error); }
fputs("done.\n", stdout);

    __b2c__STRFREE(name);
    __b2c__STRFREE(total);
    __b2c__STRFREE(dat);
    __b2c__STRFREE(proxy);
    __b2c__STRFREE(unpw);
    b2c_catch_set = b2c_catch_set_backup;
    return b2c_exitval;
    network_error:
    ;
    shutdown((uintptr_t)mynet, SHUT_RDWR);
    close((uintptr_t)mynet);
fprintf(stderr, "System error: the site http://%s is not reachable! Try again later.\n", LEFT(name, INSTR(name, "/")-1));
    exit(1);

    __b2c__STRFREE(name);
    __b2c__STRFREE(total);
    __b2c__STRFREE(dat);
    __b2c__STRFREE(proxy);
    __b2c__STRFREE(unpw);
    b2c_catch_set = b2c_catch_set_backup;
}
