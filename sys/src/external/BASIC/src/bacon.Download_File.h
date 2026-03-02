/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Download_File( char *__b2c_name__b2c__string_var) {
 char*name__b2c__string_var = NULL; name__b2c__string_var = __b2c_Copy_String(NULL, __b2c_name__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 6833 "bacon.bac"
char *total__b2c__string_var = NULL;
char *dat__b2c__string_var = NULL;
char *proxy__b2c__string_var = NULL;
char *unpw__b2c__string_var = NULL;
long length = 0;
long size = 0;
long mynet = 0;
#line 6835 "bacon.bac"
__b2c__catch_set = 1;
#line 6838 "bacon.bac"
proxy__b2c__string_var = __b2c_Copy_String(proxy__b2c__string_var, (char*) GETENVIRON__b2c__string_var("HTTP_PROXY"));
#line 6839 "bacon.bac"
if( LEN(proxy__b2c__string_var) == 0 ){
proxy__b2c__string_var = __b2c_Copy_String(proxy__b2c__string_var, (char*) GETENVIRON__b2c__string_var("http_proxy"));
}
#line 6842 "bacon.bac"
if( LEN(proxy__b2c__string_var) ){
#line 6843 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(proxy__b2c__string_var, 7) ,  "http://") != 0 ){
#line 6844 "bacon.bac"
__b2c__assign = (char*)"System error: proxy '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) proxy__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' not supported! Redefine to default HTTP proxy or undefine."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 6845 "bacon.bac"
exit(1);
#line 6846 "bacon.bac"
}
#line 6848 "bacon.bac"
proxy__b2c__string_var = F_MID__b2c__string_var(proxy__b2c__string_var,proxy__b2c__string_var, 8);
#line 6849 "bacon.bac"
if( TALLY(proxy__b2c__string_var, "@") ){
#line 6850 "bacon.bac"
unpw__b2c__string_var = __b2c_Copy_String(unpw__b2c__string_var, (char*) B64ENC__b2c__string_var(TOKEN__b2c__string_var(proxy__b2c__string_var, 1, "@")));
#line 6851 "bacon.bac"
proxy__b2c__string_var = __b2c_Copy_String(proxy__b2c__string_var, (char*) TOKEN__b2c__string_var(proxy__b2c__string_var, 2, "@"));
#line 6852 "bacon.bac"
}
#line 6855 "bacon.bac"
ERROR = __b2c__network_init((uintptr_t*)&mynet, proxy__b2c__string_var, NULL, SOCK_STREAM, 5, "TCP", 1, 1, __b2c__capeer, __b2c__cacerts, __b2c__caprivate, __b2c__caserver);
if(ERROR){ RUNTIMEERROR("OPEN FOR NETWORK", 6855, "../bacon.bac", ERROR, network_error); }
#line 6857 "bacon.bac"
if((__b2c__counter = send(mynet, (void*)(CONCAT__b2c__string_var( "CONNECT " , TOKEN__b2c__string_var(name__b2c__string_var, 1, "/") , ":80 HTTP/1.1" , "\r\n" )), __b2c__len(CONCAT__b2c__string_var( "CONNECT " , TOKEN__b2c__string_var(name__b2c__string_var, 1, "/") , ":80 HTTP/1.1" , "\r\n" )), 0)) < 0) {
ERROR = 15; RUNTIMEERROR("SEND", 6857, "../bacon.bac", ERROR, network_error); }
#line 6858 "bacon.bac"
if( LEN(unpw__b2c__string_var) ){
if((__b2c__counter = send(mynet, (void*)(CONCAT__b2c__string_var( "Proxy-Authorization: Basic " , B64ENC__b2c__string_var(unpw__b2c__string_var) , "\r\n" )), __b2c__len(CONCAT__b2c__string_var( "Proxy-Authorization: Basic " , B64ENC__b2c__string_var(unpw__b2c__string_var) , "\r\n" )), 0)) < 0) {
ERROR = 15; RUNTIMEERROR("SEND", 6858, "../bacon.bac", ERROR, network_error); }
}
#line 6859 "bacon.bac"
if((__b2c__counter = send(mynet, (void*)("\r\n"), __b2c__len("\r\n"), 0)) < 0) {
ERROR = 15; RUNTIMEERROR("SEND", 6859, "../bacon.bac", ERROR, network_error); }
#line 6862 "bacon.bac"
__b2c__assign = (char*)calloc((512+1), sizeof(char));
if((__b2c__counter = recv(mynet, (void*)__b2c__assign, 512, 0)) < 0) {
ERROR = 14; RUNTIMEERROR("RECEIVE", 6862, "../bacon.bac", ERROR, network_error); }
dat__b2c__string_var = __b2c_Copy_String(dat__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 6863 "bacon.bac"
if( NOT(TALLY(dat__b2c__string_var, " 200 ")) ){
#line 6864 "bacon.bac"
__b2c__assign = (char*)"System error: proxy '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) proxy__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) CONCAT__b2c__string_var( "' returns error: " , dat__b2c__string_var) ; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 6865 "bacon.bac"
exit(1);
#line 6866 "bacon.bac"
}
#line 6867 "bacon.bac"
} else {
#line 6869 "bacon.bac"
ERROR = __b2c__network_init((uintptr_t*)&mynet, CONCAT__b2c__string_var( TOKEN__b2c__string_var(name__b2c__string_var, 1, "/") , ":80" ), NULL, SOCK_STREAM, 5, "TCP", 1, 1, __b2c__capeer, __b2c__cacerts, __b2c__caprivate, __b2c__caserver);
if(ERROR){ RUNTIMEERROR("OPEN FOR NETWORK", 6869, "../bacon.bac", ERROR, network_error); }
#line 6870 "bacon.bac"
}
#line 6872 "bacon.bac"
__b2c__assign = (char*)"Fetching file..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 6874 "bacon.bac"
if((__b2c__counter = send(mynet, (void*)(CONCAT__b2c__string_var( "HEAD /" , MID__b2c__string_var(name__b2c__string_var, INSTR(name__b2c__string_var, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN__b2c__string_var(name__b2c__string_var, 1, "/") , "\r\n\r\n" )), __b2c__len(CONCAT__b2c__string_var( "HEAD /" , MID__b2c__string_var(name__b2c__string_var, INSTR(name__b2c__string_var, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN__b2c__string_var(name__b2c__string_var, 1, "/") , "\r\n\r\n" )), 0)) < 0) {
ERROR = 15; RUNTIMEERROR("SEND", 6874, "../bacon.bac", ERROR, network_error); }
#line 6875 "bacon.bac"
__b2c__assign = (char*)calloc((512+1), sizeof(char));
if((__b2c__counter = recv(mynet, (void*)__b2c__assign, 512, 0)) < 0) {
ERROR = 14; RUNTIMEERROR("RECEIVE", 6875, "../bacon.bac", ERROR, network_error); }
dat__b2c__string_var = __b2c_Copy_String(dat__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 6878 "bacon.bac"
if( NOT(INSTR(dat__b2c__string_var, "Content-Length:")) ){
#line 6879 "bacon.bac"
__b2c__assign = (char*)"System error: file not found! Check URL and try again."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 6880 "bacon.bac"
exit(1);
#line 6881 "bacon.bac"
}
#line 6883 "bacon.bac"
dat__b2c__string_var = F_MID__b2c__string_var(dat__b2c__string_var,dat__b2c__string_var, INSTR(dat__b2c__string_var, "Content-Length:")+15);
#line 6884 "bacon.bac"
length=(
long)( VAL(LEFT__b2c__string_var(dat__b2c__string_var, INSTR(dat__b2c__string_var, NL__b2c__string_var))));
#line 6887 "bacon.bac"
if((__b2c__counter = send(mynet, (void*)(CONCAT__b2c__string_var( "GET /" , MID__b2c__string_var(name__b2c__string_var, INSTR(name__b2c__string_var, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN__b2c__string_var(name__b2c__string_var, 1, "/") , "\r\n\r\n" )), __b2c__len(CONCAT__b2c__string_var( "GET /" , MID__b2c__string_var(name__b2c__string_var, INSTR(name__b2c__string_var, "/")+1) , " HTTP/1.1\r\nHost: " , TOKEN__b2c__string_var(name__b2c__string_var, 1, "/") , "\r\n\r\n" )), 0)) < 0) {
ERROR = 15; RUNTIMEERROR("SEND", 6887, "../bacon.bac", ERROR, network_error); }
#line 6888 "bacon.bac"
while( WAIT(mynet, 2000) ){
#line 6889 "bacon.bac"
__b2c__assign = (char*)calloc((128+1), sizeof(char));
if((size = recv(mynet, (void*)__b2c__assign, 128, 0)) < 0) {
ERROR = 14; RUNTIMEERROR("RECEIVE", 6889, "../bacon.bac", ERROR, network_error); }
dat__b2c__string_var = __b2c_Copy_String(dat__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 6890 "bacon.bac"
if( size == 0 ){
break;
}
#line 6891 "bacon.bac"
__b2c__assign = (char*)"."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fflush(stderr);
#line 6892 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , dat__b2c__string_var) ;
#line 6893 "bacon.bac"
}
#line 6894 "bacon.bac"
shutdown((uintptr_t)mynet, SHUT_RDWR);
close((uintptr_t)mynet);
#line 6897 "bacon.bac"
total__b2c__string_var = F_MID__b2c__string_var(total__b2c__string_var,total__b2c__string_var, INSTR(total__b2c__string_var, "\r\n\r\n")+4);
#line 6900 "bacon.bac"
if( LEN(total__b2c__string_var) != length ){
#line 6901 "bacon.bac"
__b2c__assign = (char*)"System error: file "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) name__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " could not be downloaded probably due to a timeout. Try again later."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 6902 "bacon.bac"
exit(1);
#line 6903 "bacon.bac"
}
#line 6906 "bacon.bac"
ERROR = __b2c__save(0, 0, MID__b2c__string_var(name__b2c__string_var, INSTRREV(name__b2c__string_var, "/")+1), total__b2c__string_var, NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 6906, "../bacon.bac", ERROR, network_error); }
#line 6908 "bacon.bac"
__b2c__assign = (char*)"done."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 6909 "bacon.bac"

__b2c__STRFREE(name__b2c__string_var);
__b2c__STRFREE(total__b2c__string_var);
__b2c__STRFREE(dat__b2c__string_var);
__b2c__STRFREE(proxy__b2c__string_var);
__b2c__STRFREE(unpw__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return __b2c__exitval;
#line 6911 "bacon.bac"
network_error:
;
#line 6912 "bacon.bac"
shutdown((uintptr_t)mynet, SHUT_RDWR);
close((uintptr_t)mynet);
#line 6913 "bacon.bac"
__b2c__assign = (char*)"System error: the site http://"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) LEFT__b2c__string_var(name__b2c__string_var, INSTR(name__b2c__string_var, "/")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " is not reachable! Try again later."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 6914 "bacon.bac"
exit(1);
#line 6916 "bacon.bac"

__b2c__STRFREE(name__b2c__string_var);
__b2c__STRFREE(total__b2c__string_var);
__b2c__STRFREE(dat__b2c__string_var);
__b2c__STRFREE(proxy__b2c__string_var);
__b2c__STRFREE(unpw__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
