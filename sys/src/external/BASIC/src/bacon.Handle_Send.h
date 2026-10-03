/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Send( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 1210 "bacon.bac"
char *var__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *chunk__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
#line 1213 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 1214 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in SEND statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1215 "bacon.bac"
exit(1);
#line 1216 "bacon.bac"
}
#line 1219 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "SIZE") ){
#line 1220 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "SIZE")));
#line 1221 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "SIZE")-1));
#line 1222 "bacon.bac"
}
#line 1223 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "CHUNK") ){
#line 1224 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "CHUNK")));
#line 1225 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "CHUNK")-1));
#line 1226 "bacon.bac"
}
#line 1227 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "TO")));
#line 1228 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "TO")-1));
#line 1229 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,arg__b2c__string_var);
#line 1231 "bacon.bac"
if( LEN(chunk__b2c__string_var) == 0 ){
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, "__b2c__len(" , var__b2c__string_var , ")");
}
#line 1234 "bacon.bac"
if( LEN(size__b2c__string_var) ){
#line 1235 "bacon.bac"
Register_Numeric(size__b2c__string_var, "default");
#line 1236 "bacon.bac"
} else {
#line 1237 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) "__b2c__counter");
#line 1238 "bacon.bac"
}
#line 1241 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "SCTP") == 0 ){
#line 1242 "bacon.bac"
__b2c__assign = (char*)"if(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = sctp_sendmsg("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", NULL, 0, 0, 0, 0, 0, 0)) < 0) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1243 "bacon.bac"
} else {
#line 1245 "bacon.bac"
if( g_OPTION_TLS ){
#line 1246 "bacon.bac"
__b2c__assign = (char*)size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = SSL_write((SSL*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (const void*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " <= 0) { fprintf(stderr, \"SSL WRITE error: %s\\n\", ERR_error_string(SSL_get_error((SSL*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), NULL));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1247 "bacon.bac"
} else {
#line 1248 "bacon.bac"
__b2c__assign = (char*)"if(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = send("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", 0)) < 0) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1249 "bacon.bac"
}
#line 1250 "bacon.bac"
}
#line 1251 "bacon.bac"
__b2c__assign = (char*)"ERROR = 15; RUNTIMEERROR(\"SEND\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1252 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 1254 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(chunk__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
