/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Receive( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 1149 "bacon.bac"
char *var__b2c__string_var = NULL;
char *from__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *chunk__b2c__string_var = NULL;
#line 1152 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "FROM")) ){
#line 1153 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing FROM in RECEIVE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1154 "bacon.bac"
exit(1);
#line 1155 "bacon.bac"
}
#line 1158 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "SIZE") ){
#line 1159 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "SIZE")));
#line 1160 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "SIZE")-1));
#line 1161 "bacon.bac"
}
#line 1162 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "CHUNK") ){
#line 1163 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "CHUNK")));
#line 1164 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "CHUNK")-1));
#line 1165 "bacon.bac"
} else {
#line 1166 "bacon.bac"
if( g_OPTION_TLS ){
#line 1167 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) "32768");
#line 1168 "bacon.bac"
} else {
#line 1169 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) STR__b2c__string_var(g_BUFFER_SIZE));
#line 1170 "bacon.bac"
}
#line 1171 "bacon.bac"
}
#line 1172 "bacon.bac"
from__b2c__string_var = __b2c_Copy_String(from__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "FROM")));
#line 1173 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "FROM")-1));
#line 1174 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,arg__b2c__string_var);
#line 1177 "bacon.bac"
if( LEN(size__b2c__string_var) ){
#line 1178 "bacon.bac"
Register_Numeric(size__b2c__string_var, "default");
#line 1179 "bacon.bac"
} else {
#line 1180 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) "__b2c__counter");
#line 1181 "bacon.bac"
}
#line 1184 "bacon.bac"
if( REGEX(var__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
Register_Pointer(var__b2c__string_var, "char*");
}
#line 1187 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = (char*)calloc(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+1), sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1188 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "SCTP") == 0 ){
#line 1189 "bacon.bac"
__b2c__assign = (char*)"if(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = sctp_recvmsg("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void*)__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", 0, 0, 0, 0)) < 0) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1190 "bacon.bac"
} else {
#line 1192 "bacon.bac"
if( g_OPTION_TLS ){
#line 1193 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " > 0) { "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = SSL_read((SSL*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void*)__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); } if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " <= 0) { fprintf(stderr, \"SSL READ error in line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ": %s\\n\", ERR_error_string(SSL_get_error((SSL*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), NULL));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1194 "bacon.bac"
} else {
#line 1195 "bacon.bac"
__b2c__assign = (char*)"if(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = recv("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void*)__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*)", 0)) < 0) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1196 "bacon.bac"
}
#line 1197 "bacon.bac"
}
#line 1198 "bacon.bac"
__b2c__assign = (char*)"ERROR = 14; RUNTIMEERROR(\"RECEIVE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1200 "bacon.bac"
Assign_To_String("__b2c__assign", var__b2c__string_var, size__b2c__string_var);
#line 1202 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 1204 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(from__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(chunk__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
