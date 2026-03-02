/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Endfunction( void) {
 __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 2186 "bacon.bac"
char *line__b2c__string_var = NULL;
char *tfil__b2c__string_var = NULL;
#line 2187 "bacon.bac"
FILE* tmp_HFILE = NULL;
#line 2190 "bacon.bac"
if( NOT(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 2191 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: ENDFUNC(TION) outside FUNCTION at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2192 "bacon.bac"
exit(1);
#line 2193 "bacon.bac"
}
#line 2196 "bacon.bac"
if( ISFALSE(LEN(g_FUNCTYPE__b2c__string_var)) ){
#line 2197 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: function '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was defined without returning a value or string!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2198 "bacon.bac"
exit(1);
#line 2199 "bacon.bac"
}
#line 2202 "bacon.bac"
fclose(g_CFILE);
#line 2205 "bacon.bac"
if( NOT(INSTR(g_PROTOTYPE__b2c__string_var, "::")) ){
__b2c__assign = (char*)g_FUNCTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_PROTOTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
}
#line 2206 "bacon.bac"
g_PROTOTYPE__b2c__string_var = __b2c_Copy_String(g_PROTOTYPE__b2c__string_var, (char*) "");
#line 2209 "bacon.bac"
tfil__b2c__string_var = F_MID__b2c__string_var(tfil__b2c__string_var,g_CURFILE__b2c__string_var, INSTRREV(g_CURFILE__b2c__string_var, "/") + 1);
#line 2210 "bacon.bac"
tmp_HFILE = fopen((const char*)CONCAT__b2c__string_var( g_TEMPDIR__b2c__string_var , "/" , LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h" ), "w");
if(tmp_HFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 2210, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2213 "bacon.bac"
__b2c__assign = (char*)"/* Created with BaCon "; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2214 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__exitval"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2215 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__exitval 0"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2216 "bacon.bac"
if( NOT(INSTR(g_ORIGFUNCNAME__b2c__string_var, "(")) ){
#line 2217 "bacon.bac"
__b2c__assign = (char*)g_FUNCTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) "(void) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2218 "bacon.bac"
} else {
#line 2219 "bacon.bac"
__b2c__assign = (char*)g_FUNCTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) g_ORIGFUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) " {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2220 "bacon.bac"
}
#line 2223 "bacon.bac"
__b2c__assign = (char*)g_STRINGARGS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2224 "bacon.bac"
g_CFILE = fopen((const char*)g_CFILE__b2c__string_var, "r");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 2224, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2225 "bacon.bac"
while( NOT(ENDFILE(g_CFILE)) ){
#line 2226 "bacon.bac"
__b2c__readln(&__b2c__assign, g_CFILE);
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 2227 "bacon.bac"
if( NOT(ENDFILE(g_CFILE)) ){
__b2c__assign = (char*)line__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
}
#line 2228 "bacon.bac"
}
#line 2229 "bacon.bac"
fclose(g_CFILE);
#line 2231 "bacon.bac"
if( g_CATCH_USED == 1 ){
__b2c__assign = (char*)"__B2C__PROGRAM__EXIT: ;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
}
#line 2234 "bacon.bac"
__b2c__assign = (char*)"__b2c__catch_set = __b2c__catch_set_backup;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2237 "bacon.bac"
if( REGEX(g_FUNCTYPE__b2c__string_var, "char\\*$|STRING$") ){
#line 2238 "bacon.bac"
__b2c__assign = (char*)"return (NULL);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2239 "bacon.bac"
} else if( REGEX(g_FUNCTYPE__b2c__string_var, "char$|short$|int$|long$|double$|float$|NUMBER$|FLOATING$") ){
#line 2240 "bacon.bac"
__b2c__assign = (char*)"return (0);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2241 "bacon.bac"
} else {
#line 2242 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2243 "bacon.bac"
}
#line 2245 "bacon.bac"
fclose(tmp_HFILE);
#line 2248 "bacon.bac"
if( NOT(INSTR(g_INCLUDE_FILES__b2c__string_var, CONCAT__b2c__string_var( LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h") )) ){
#line 2249 "bacon.bac"
g_INCLUDE_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_INCLUDE_FILES__b2c__string_var, g_INCLUDE_FILES__b2c__string_var , " " , LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h") ;
#line 2250 "bacon.bac"
}
#line 2253 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_TEMPDIR__b2c__string_var , "/" , LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h") ;
#line 2256 "bacon.bac"
if(unlink(g_CFILE__b2c__string_var)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 2256, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2259 "bacon.bac"
g_CFILE__b2c__string_var = __b2c_Copy_String(g_CFILE__b2c__string_var, (char*) g_COPY_CFILE__b2c__string_var);
#line 2260 "bacon.bac"
g_CFILE = fopen((const char*)g_CFILE__b2c__string_var, "a");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR APPENDING", 2260, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2263 "bacon.bac"
g_CATCHGOTO__b2c__string_var = __b2c_Copy_String(g_CATCHGOTO__b2c__string_var, (char*) g_ORIGCATCHGOTO__b2c__string_var);
#line 2264 "bacon.bac"
g_CATCH_USED=(long)( g_ORIGCATCH_USED);
#line 2267 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = __b2c_Copy_String(g_ORIGFUNCNAME__b2c__string_var, (char*) "");
#line 2268 "bacon.bac"
g_FUNCNAME__b2c__string_var = __b2c_Copy_String(g_FUNCNAME__b2c__string_var, (char*) "");
#line 2269 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) "");
#line 2270 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = __b2c_Copy_String(g_LOCALSTRINGS__b2c__string_var, (char*) "");
#line 2271 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = __b2c_Copy_String(g_STRINGARRAYS__b2c__string_var, (char*) "");
#line 2272 "bacon.bac"
g_STRINGARGS__b2c__string_var = __b2c_Copy_String(g_STRINGARGS__b2c__string_var, (char*) "");
#line 2274 "bacon.bac"

__b2c__STRFREE(line__b2c__string_var);
__b2c__STRFREE(tfil__b2c__string_var);
__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
}
