/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval 0
char* Pre_Tokenize_Functions__b2c__string_var( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char *__b2c__select_6023__b2c__string_var = NULL; char *__b2c__select_6073__b2c__string_var = NULL; char *__b2c__select_6101__b2c__string_var = NULL; char **funcvar__b2c__string_var = { NULL }; long funcvar__b2c__string_var__b2c_array = 0; char **mainvar__b2c__string_var = { NULL }; long mainvar__b2c__string_var__b2c_array = 0;
#line 5965 "bacon.bac"
char *token__b2c__string_var = NULL;
char *it__b2c__string_var = NULL;
char *var__b2c__string_var = NULL;
char *val__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *first__b2c__string_var = NULL;
char *second__b2c__string_var = NULL;
char *delim__b2c__string_var = NULL;
char *intoken__b2c__string_var = NULL;
char *uniq__b2c__string_var = NULL;
#line 5966 "bacon.bac"
long is_escaped = 0;
long is_string = 0;
long i = 0;
long j = 0;
long mem = 0;
long nr = 1;
long many = 0;
long pos = 0;
#line 5967 "bacon.bac"
FILE* out = NULL;
#line 5970 "bacon.bac"
if( ISTRUE(g_LOWERCASE) ){
#line 5971 "bacon.bac"
if( REGEX(arg__b2c__string_var, "^const[[:space:]]")  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
arg__b2c__string_var = F_CONCAT__b2c__string_var(arg__b2c__string_var, "CONST " , MID__b2c__string_var(arg__b2c__string_var, 6));
}
#line 5972 "bacon.bac"
if( REGEX(arg__b2c__string_var, "[[:space:]]static$")  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
arg__b2c__string_var = F_CONCAT__b2c__string_var(arg__b2c__string_var, LEFT__b2c__string_var(arg__b2c__string_var, LEN(arg__b2c__string_var)-7) , " STATIC");
}
#line 5973 "bacon.bac"
}
#line 5976 "bacon.bac"
if( g_OPTION_DISABLE_C_ESCAPE ){
#line 5977 "bacon.bac"
for(i=1; i <= LEN(arg__b2c__string_var); i+=1){
#line 5978 "bacon.bac"
__b2c__select_5978 = (double)ASC(MID__b2c__string_var(arg__b2c__string_var, i, 1));
#line 5979 "bacon.bac"
 if ( (__b2c__select_5978) == (92)){
#line 5980 "bacon.bac"
if( is_string ){
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(92));
}
#line 5981 "bacon.bac"
} else  if ( (__b2c__select_5978) == (34)){
#line 5982 "bacon.bac"
is_string=(
long)( NOT(is_string));
#line 5983 "bacon.bac"
}
#line 5984 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , MID__b2c__string_var(arg__b2c__string_var, i, 1)) ;
#line 5985 "bacon.bac"
}
#line 5986 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) token__b2c__string_var);
#line 5987 "bacon.bac"
is_string=(
long)( 0);
#line 5988 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 5989 "bacon.bac"
}
#line 5992 "bacon.bac"
if( REGEX(arg__b2c__string_var, "TYPEOF\\$|SOURCE\\$|OBTAIN\\$|IIF\\(|IIF\\$\\(|FIND\\(|EVAL\\(|VERIFY|REM|LOOP|COIL\\$|GUIDEFINE|UBOUND\\(|INVERT\\(|INDEX|[^a-zA-Z0-9_]int\\(") ){
#line 5995 "bacon.bac"
for(i=1; i <= LEN(arg__b2c__string_var); i+=1){
#line 5996 "bacon.bac"
if( NOT(is_string) ){
#line 5997 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 7) ,  "TYPEOF$") == 0 ){
#line 5998 "bacon.bac"
it__b2c__string_var = F_MID__b2c__string_var(it__b2c__string_var,arg__b2c__string_var, i, INSTR(MID__b2c__string_var(arg__b2c__string_var, i), ")")-1);
#line 5999 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(34) , Get_Var__b2c__string_var(MID__b2c__string_var(it__b2c__string_var, INSTR(it__b2c__string_var, "(")+1), g_FUNCNAME__b2c__string_var) , CHR__b2c__string_var(34)) ;
#line 6000 "bacon.bac"
i = i + ( LEN(it__b2c__string_var)+1);
#line 6001 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 7) ,  "SOURCE$") == 0 ){
#line 6002 "bacon.bac"
if( NOT(FILEEXISTS(SRCARRAYFILE__b2c__string_var)) ){
#line 6003 "bacon.bac"
mem=(
long)( BLOAD(g_SOURCEFILE__b2c__string_var));
#line 6004 "bacon.bac"
#undef __b2c__MEMTYPE
#define __b2c__MEMTYPE unsigned char
#line 6005 "bacon.bac"
out = fopen((const char*)SRCARRAYFILE__b2c__string_var, "w");
if(out == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 6005, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 6006 "bacon.bac"
__b2c__assign = (char*)"char SOURCE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, out); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, out); }
__b2c__assign = (char*) "[]={"; if(__b2c__assign != NULL) { fputs(__b2c__assign, out); }
fflush(out);
#line 6007 "bacon.bac"
for(j=0; j <= FILELEN(g_SOURCEFILE__b2c__string_var)-1; j+=1){
#line 6008 "bacon.bac"
if( MOD(j, 16) == 0 ){
__b2c__assign = (char*)""; if(__b2c__assign != NULL) { fputs(__b2c__assign, out); }
fputs("\n", out);
}
#line 6009 "bacon.bac"
fputs(STR__b2c__string_var(PEEK(mem+j)), out);
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, out); }
fflush(out);
#line 6010 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6011 "bacon.bac"
__b2c__assign = (char*)"0 };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, out); }
fputs("\n", out);
#line 6012 "bacon.bac"
fclose(out);
#line 6013 "bacon.bac"
if(!__b2c__memory__check((char *)mem, sizeof(__b2c__MEMTYPE)))
{ ERROR=1; RUNTIMEERROR("FREE", 6013, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); } free((void*)mem);
#line 6014 "bacon.bac"
}
#line 6015 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 7) ,  "OBTAIN$") == 0 ){
#line 6016 "bacon.bac"
pos=(
long)( INSTR(MID__b2c__string_var(arg__b2c__string_var, i), "("));
#line 6017 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos)));
#line 6018 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "$", g_STRINGSIGN__b2c__string_var));
#line 6019 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "#", g_FLOATSIGN__b2c__string_var));
#line 6020 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "%", g_LONGSIGN__b2c__string_var));
#line 6021 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , intoken__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 6022 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6023 "bacon.bac"
__b2c__select_6023__b2c__string_var = __b2c_Copy_String(__b2c__select_6023__b2c__string_var, type__b2c__string_var);
#line 6024 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_6023__b2c__string_var, "char*") || !__b2c__strcmp(__b2c__select_6023__b2c__string_var,  "STRING")){
#line 6025 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 0"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6026 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6023__b2c__string_var, "double") || !__b2c__strcmp(__b2c__select_6023__b2c__string_var,  "FLOATING")){
#line 6027 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 1"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6028 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6023__b2c__string_var, "float")){
#line 6029 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 2"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6030 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6023__b2c__string_var, "long") || !__b2c__strcmp(__b2c__select_6023__b2c__string_var,  "NUMBER")){
#line 6031 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 3"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6032 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6023__b2c__string_var, "int")){
#line 6033 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 4"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6034 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6023__b2c__string_var, "short")){
#line 6035 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 5"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6036 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6023__b2c__string_var, "char")){
#line 6037 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 6"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6038 "bacon.bac"
} else {
#line 6039 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__obtain_type_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) intoken__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " -1"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6040 "bacon.bac"
}
#line 6041 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "OBTAIN$") ;
#line 6042 "bacon.bac"
i = i + ( 7);
#line 6043 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 7) ,  "VERIFY(") == 0 ){
#line 6044 "bacon.bac"
var__b2c__string_var = F_MID__b2c__string_var(var__b2c__string_var,arg__b2c__string_var, INSTR(arg__b2c__string_var, "(")+1);
#line 6045 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(var__b2c__string_var));
#line 6046 "bacon.bac"
intoken__b2c__string_var = F_MID__b2c__string_var(intoken__b2c__string_var,var__b2c__string_var, LEN(intoken__b2c__string_var)+2);
#line 6047 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__cacerts"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 6048 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__cacerts "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(intoken__b2c__string_var, 1, ")"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 6049 "bacon.bac"
if( TALLY(g_LIB_TLS__b2c__string_var, "wolfssl") ){
#line 6050 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__capeer"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 6051 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__capeer SSL_VERIFY_PEER"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 6052 "bacon.bac"
}
#line 6053 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "VERIFY(") ;
#line 6054 "bacon.bac"
i = i + ( 7);
#line 6055 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 6) ,  "UBOUND") == 0 ){
#line 6056 "bacon.bac"
it__b2c__string_var = F_MID__b2c__string_var(it__b2c__string_var,arg__b2c__string_var, i, INSTR(MID__b2c__string_var(arg__b2c__string_var, i), ")")-1);
#line 6057 "bacon.bac"
i = i + ( LEN(it__b2c__string_var)+1);
#line 6058 "bacon.bac"
it__b2c__string_var = __b2c_Copy_String(it__b2c__string_var, (char*) REPLACE__b2c__string_var(it__b2c__string_var, "$", g_STRINGSIGN__b2c__string_var));
#line 6059 "bacon.bac"
it__b2c__string_var = __b2c_Copy_String(it__b2c__string_var, (char*) REPLACE__b2c__string_var(it__b2c__string_var, "#", g_FLOATSIGN__b2c__string_var));
#line 6060 "bacon.bac"
it__b2c__string_var = __b2c_Copy_String(it__b2c__string_var, (char*) REPLACE__b2c__string_var(it__b2c__string_var, "%", g_LONGSIGN__b2c__string_var));
#line 6061 "bacon.bac"
if( LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , TOKEN__b2c__string_var(it__b2c__string_var, 2, "(")) , g_FUNCNAME__b2c__string_var)) ){
#line 6062 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "NRKEYS(" , TOKEN__b2c__string_var(it__b2c__string_var, 2, "(") , ")") ;
#line 6063 "bacon.bac"
} else if( ISTOKEN(g_DYNAMICARRAYS__b2c__string_var, CONCAT__b2c__string_var( TOKEN__b2c__string_var(it__b2c__string_var, 2, "(") , "@" , g_FUNCNAME__b2c__string_var) ) ){
#line 6064 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , TOKEN__b2c__string_var(it__b2c__string_var, 2, "(") , "__b2c_array") ;
#line 6065 "bacon.bac"
} else {
#line 6066 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(TOKEN__b2c__string_var(it__b2c__string_var, 2, "("), g_FUNCNAME__b2c__string_var));
#line 6067 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "(sizeof(" , TOKEN__b2c__string_var(it__b2c__string_var, 2, "(") , ")/sizeof(" , type__b2c__string_var , ")-" , STR__b2c__string_var(g_OPTION_BASE) , ")") ;
#line 6068 "bacon.bac"
}
#line 6069 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 7) ,  "INVERT(") == 0 ){
#line 6070 "bacon.bac"
pos=(
long)( INSTR(MID__b2c__string_var(arg__b2c__string_var, i), "("));
#line 6071 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos)));
#line 6072 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , intoken__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 6073 "bacon.bac"
__b2c__select_6073__b2c__string_var = __b2c_Copy_String(__b2c__select_6073__b2c__string_var, type__b2c__string_var);
#line 6074 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_6073__b2c__string_var, "char*") || !__b2c__strcmp(__b2c__select_6073__b2c__string_var,  "STRING")){
#line 6075 "bacon.bac"
nr=(
long)( 0);
#line 6076 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6073__b2c__string_var, "double") || !__b2c__strcmp(__b2c__select_6073__b2c__string_var,  "FLOATING")){
#line 6077 "bacon.bac"
nr=(
long)( 1);
#line 6078 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6073__b2c__string_var, "float")){
#line 6079 "bacon.bac"
nr=(
long)( 2);
#line 6080 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6073__b2c__string_var, "long") || !__b2c__strcmp(__b2c__select_6073__b2c__string_var,  "NUMBER")){
#line 6081 "bacon.bac"
nr=(
long)( 3);
#line 6082 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6073__b2c__string_var, "int")){
#line 6083 "bacon.bac"
nr=(
long)( 4);
#line 6084 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6073__b2c__string_var, "short")){
#line 6085 "bacon.bac"
nr=(
long)( 5);
#line 6086 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6073__b2c__string_var, "char")){
#line 6087 "bacon.bac"
nr=(
long)( 6);
#line 6088 "bacon.bac"
} else {
#line 6089 "bacon.bac"
nr=(
long)( -1);
#line 6090 "bacon.bac"
}
#line 6091 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "$", g_STRINGSIGN__b2c__string_var));
#line 6092 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "#", g_FLOATSIGN__b2c__string_var));
#line 6093 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "%", g_LONGSIGN__b2c__string_var));
#line 6094 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "INVERT(" , STR__b2c__string_var(nr) , ",") ;
#line 6095 "bacon.bac"
i = i + ( 7);
#line 6096 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 6) ,  "INDEX(") == 0  OR  __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 7) ,  "INDEX$(") == 0 ){
#line 6097 "bacon.bac"
pos=(
long)( INSTR(MID__b2c__string_var(arg__b2c__string_var, i), "("));
#line 6098 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos)));
#line 6099 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , intoken__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 6100 "bacon.bac"
if( NOT(LEN(type__b2c__string_var)) ){
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(intoken__b2c__string_var, g_FUNCNAME__b2c__string_var));
}
#line 6101 "bacon.bac"
__b2c__select_6101__b2c__string_var = __b2c_Copy_String(__b2c__select_6101__b2c__string_var, type__b2c__string_var);
#line 6102 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_6101__b2c__string_var, "char*") || !__b2c__strcmp(__b2c__select_6101__b2c__string_var,  "STRING")){
#line 6103 "bacon.bac"
nr=(
long)( 0);
#line 6104 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6101__b2c__string_var, "double") || !__b2c__strcmp(__b2c__select_6101__b2c__string_var,  "FLOATING")){
#line 6105 "bacon.bac"
nr=(
long)( 1);
#line 6106 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6101__b2c__string_var, "float")){
#line 6107 "bacon.bac"
nr=(
long)( 2);
#line 6108 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6101__b2c__string_var, "long") || !__b2c__strcmp(__b2c__select_6101__b2c__string_var,  "NUMBER")){
#line 6109 "bacon.bac"
nr=(
long)( 3);
#line 6110 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6101__b2c__string_var, "int")){
#line 6111 "bacon.bac"
nr=(
long)( 4);
#line 6112 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6101__b2c__string_var, "short")){
#line 6113 "bacon.bac"
nr=(
long)( 5);
#line 6114 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6101__b2c__string_var, "char")){
#line 6115 "bacon.bac"
nr=(
long)( 6);
#line 6116 "bacon.bac"
} else {
#line 6117 "bacon.bac"
nr=(
long)( -1);
#line 6118 "bacon.bac"
}
#line 6119 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "$", g_STRINGSIGN__b2c__string_var));
#line 6120 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "#", g_FLOATSIGN__b2c__string_var));
#line 6121 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "%", g_LONGSIGN__b2c__string_var));
#line 6122 "bacon.bac"
if( LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , intoken__b2c__string_var) , g_FUNCNAME__b2c__string_var)) ){
#line 6123 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "INDEX$(" , STR__b2c__string_var(nr) , ",") ;
#line 6124 "bacon.bac"
i = i + ( 7);
#line 6125 "bacon.bac"
} else if( ISTOKEN(g_DYNAMICARRAYS__b2c__string_var, CONCAT__b2c__string_var( intoken__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) ) ){
#line 6126 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "INDEX(" , intoken__b2c__string_var , "__b2c_array," , STR__b2c__string_var(nr) , ",") ;
#line 6127 "bacon.bac"
i = i + ( 6);
#line 6128 "bacon.bac"
} else {
#line 6129 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(intoken__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 6130 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "INDEX(sizeof(" , intoken__b2c__string_var , ")/sizeof(" , type__b2c__string_var , ")-" , STR__b2c__string_var(g_OPTION_BASE) , "," , STR__b2c__string_var(nr) , ",") ;
#line 6131 "bacon.bac"
i = i + ( 6);
#line 6132 "bacon.bac"
}
#line 6133 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 9) ,  "GUIDEFINE") == 0 ){
#line 6134 "bacon.bac"
pos=(
long)( INSTR(MID__b2c__string_var(arg__b2c__string_var, i), "("));
#line 6135 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos)));
#line 6136 "bacon.bac"
guiGenerate(CHOP__b2c__string_var(intoken__b2c__string_var, CONCAT__b2c__string_var( "\n\r\t " , CHR__b2c__string_var(34)) ));
#line 6137 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "GUIDEFINE") ;
#line 6138 "bacon.bac"
i = i + ( 9);
#line 6139 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 6) ,  "LOOP$(") == 0  OR  __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 6) ,  "COIL$(") == 0  OR  __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 5) ,  "LOOP(") == 0 ){
#line 6140 "bacon.bac"
delim__b2c__string_var = __b2c_Copy_String(delim__b2c__string_var, (char*) "__b2c__option_delim");
#line 6141 "bacon.bac"
pos=(
long)( INSTR(MID__b2c__string_var(arg__b2c__string_var, i), "("));
#line 6142 "bacon.bac"
first__b2c__string_var = __b2c_Copy_String(first__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos)));
#line 6143 "bacon.bac"
second__b2c__string_var = __b2c_Copy_String(second__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos+LEN(first__b2c__string_var)+1)));
#line 6144 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i+pos+LEN(first__b2c__string_var)+1+LEN(second__b2c__string_var), 1) ,  ",") == 0 ){
#line 6145 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos+LEN(first__b2c__string_var)+1+LEN(second__b2c__string_var)+1)));
#line 6146 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i+pos+LEN(first__b2c__string_var)+1+LEN(second__b2c__string_var)+1+LEN(intoken__b2c__string_var), 1) ,  ",") == 0 ){
#line 6147 "bacon.bac"
delim__b2c__string_var = __b2c_Copy_String(delim__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos+LEN(first__b2c__string_var)+1+LEN(second__b2c__string_var)+1+LEN(intoken__b2c__string_var)+1)));
#line 6148 "bacon.bac"
}
#line 6149 "bacon.bac"
} else {
#line 6150 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) second__b2c__string_var);
#line 6151 "bacon.bac"
second__b2c__string_var = __b2c_Copy_String(second__b2c__string_var, (char*) first__b2c__string_var);
#line 6152 "bacon.bac"
first__b2c__string_var = __b2c_Copy_String(first__b2c__string_var, (char*) "_");
#line 6153 "bacon.bac"
}
#line 6154 "bacon.bac"
if( INSTR(intoken__b2c__string_var, "LOOP")  OR  INSTR(intoken__b2c__string_var, "COIL$")  OR  (TALLY(arg__b2c__string_var, "LOOP") )> 1  OR  (TALLY(arg__b2c__string_var, "COIL$") )> 1 ){
#line 6155 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: multiple LOOP$/COIL$/LOOP functions in one statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 6156 "bacon.bac"
exit(1);
#line 6157 "bacon.bac"
}
#line 6158 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, pos) ,  "LOOP$(") == 0 ){
#line 6159 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Pre_Tokenize_Functions__b2c__string_var( CONCAT__b2c__string_var("IF setjmp(__b2c__loop2) THEN:FOR " , first__b2c__string_var , "=1 TO " , second__b2c__string_var , ":__b2c__loop_result$ = CONCAT$(__b2c__loop_result$, " , intoken__b2c__string_var , "):NEXT:CALL longjmp(__b2c__loop1, 1):ENDIF:" , token__b2c__string_var) ));
#line 6160 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, pos) ,  "COIL$(") == 0 ){
#line 6161 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Pre_Tokenize_Functions__b2c__string_var( CONCAT__b2c__string_var("IF setjmp(__b2c__loop2) THEN:FOR " , first__b2c__string_var , "=1 TO " , second__b2c__string_var , ":__b2c__loop_result$ = APPEND$(__b2c__loop_result$, 0, " , intoken__b2c__string_var , "," , delim__b2c__string_var , "):NEXT:CALL longjmp(__b2c__loop1, 1):ENDIF:" , token__b2c__string_var) ));
#line 6162 "bacon.bac"
} else {
#line 6163 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Pre_Tokenize_Functions__b2c__string_var( CONCAT__b2c__string_var("IF setjmp(__b2c__loop2) THEN:FOR " , first__b2c__string_var , "=1 TO " , second__b2c__string_var , ":__b2c__loop_result = __b2c__loop_result + (" , intoken__b2c__string_var , "):NEXT:CALL longjmp(__b2c__loop1, 1):ENDIF:" , token__b2c__string_var) ));
#line 6164 "bacon.bac"
}
#line 6165 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 4) ,  "IIF(") == 0 ){
#line 6166 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+4)));
#line 6167 "bacon.bac"
if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( ".* " , g_RANGEOP1__b2c__string_var , ".*;.*") )  OR  REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( ".* " , g_RANGEOP2__b2c__string_var , ".*;.*") ) ){
intoken__b2c__string_var = F_CONCAT__b2c__string_var(intoken__b2c__string_var, intoken__b2c__string_var , ";" , Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+4+LEN(intoken__b2c__string_var)+1)));
}
#line 6168 "bacon.bac"
i = i + ( 4+LEN(intoken__b2c__string_var));
#line 6169 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "IIF(" , Pre_Tokenize_Functions__b2c__string_var(Parse_Equation__b2c__string_var(intoken__b2c__string_var))) ;
#line 6170 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 5) ,  "IIF$(") == 0 ){
#line 6171 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+5)));
#line 6172 "bacon.bac"
if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( ".* " , g_RANGEOP1__b2c__string_var , ".*;.*") )  OR  REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( ".* " , g_RANGEOP2__b2c__string_var , ".*;.*") ) ){
intoken__b2c__string_var = F_CONCAT__b2c__string_var(intoken__b2c__string_var, intoken__b2c__string_var , ";" , Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+5+LEN(intoken__b2c__string_var)+1)));
}
#line 6173 "bacon.bac"
i = i + ( 5+LEN(intoken__b2c__string_var));
#line 6174 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "IIF$(" , Pre_Tokenize_Functions__b2c__string_var(Parse_Equation__b2c__string_var(intoken__b2c__string_var))) ;
#line 6175 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 5) ,  "EVAL(") == 0 ){
#line 6176 "bacon.bac"
if( nr == 1 ){
#line 6177 "bacon.bac"
var__b2c__string_var = F_CONCAT__b2c__string_var(var__b2c__string_var, "char *__b2c_evalvars_" , g_FUNCNAME__b2c__string_var , "_" , STR__b2c__string_var(g_COUNTER) , "_" , STR__b2c__string_var(HASH(token__b2c__string_var)>>8) , "[] = {") ;
#line 6178 "bacon.bac"
val__b2c__string_var = F_CONCAT__b2c__string_var(val__b2c__string_var, "double __b2c_evalvals_" , g_FUNCNAME__b2c__string_var , "_" , STR__b2c__string_var(g_COUNTER) , "_" , STR__b2c__string_var(HASH(token__b2c__string_var)>>8) , "[] = {") ;
#line 6179 "bacon.bac"
funcvar__b2c__string_var__b2c_array = __b2c__lookup_by_order(__b2c__assoc_g_ALL_FUNC_VARS__b2c__string_var, &funcvar__b2c__string_var, funcvar__b2c__string_var__b2c_array, 1);
many = funcvar__b2c__string_var__b2c_array;
#line 6180 "bacon.bac"
for(j=1; j <= many; j+=1){
#line 6181 "bacon.bac"
if( __b2c__STRCMP(TOKEN__b2c__string_var(funcvar__b2c__string_var[(uint64_t)j], 2) ,  g_FUNCNAME__b2c__string_var) == 0 ){
#line 6182 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(TOKEN__b2c__string_var(funcvar__b2c__string_var[(uint64_t)j], 1), g_FUNCNAME__b2c__string_var));
#line 6183 "bacon.bac"
if( NOT(TALLY(type__b2c__string_var, "*"))  AND  REGEX(type__b2c__string_var, "double$|FLOATING$") ){
#line 6184 "bacon.bac"
var__b2c__string_var = F_CONCAT__b2c__string_var(var__b2c__string_var, var__b2c__string_var , CHR__b2c__string_var(34) , TOKEN__b2c__string_var(funcvar__b2c__string_var[j], 1) , CHR__b2c__string_var(34) , ",") ;
#line 6185 "bacon.bac"
val__b2c__string_var = F_CONCAT__b2c__string_var(val__b2c__string_var, val__b2c__string_var , TOKEN__b2c__string_var(funcvar__b2c__string_var[j], 1) , ",") ;
#line 6186 "bacon.bac"
nr = nr + (1);
#line 6187 "bacon.bac"
}
#line 6188 "bacon.bac"
}
#line 6189 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6190 "bacon.bac"
mainvar__b2c__string_var__b2c_array = __b2c__lookup_by_order(__b2c__assoc_g_ALL_MAIN_VARS__b2c__string_var, &mainvar__b2c__string_var, mainvar__b2c__string_var__b2c_array, 1);
many = mainvar__b2c__string_var__b2c_array;
#line 6191 "bacon.bac"
for(j=1; j <= many; j+=1){
#line 6192 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(mainvar__b2c__string_var[(uint64_t)j]));
#line 6193 "bacon.bac"
if( NOT(TALLY(type__b2c__string_var, "*"))  AND  REGEX(type__b2c__string_var, "double$|FLOATING$") ){
#line 6194 "bacon.bac"
var__b2c__string_var = F_CONCAT__b2c__string_var(var__b2c__string_var, var__b2c__string_var , CHR__b2c__string_var(34) , TOKEN__b2c__string_var(mainvar__b2c__string_var[j], 1) , CHR__b2c__string_var(34) , ",") ;
#line 6195 "bacon.bac"
val__b2c__string_var = F_CONCAT__b2c__string_var(val__b2c__string_var, val__b2c__string_var , TOKEN__b2c__string_var(mainvar__b2c__string_var[j], 1) , ",") ;
#line 6196 "bacon.bac"
nr = nr + (1);
#line 6197 "bacon.bac"
}
#line 6198 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6199 "bacon.bac"
__b2c__assign = (char*)var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " NULL};"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6200 "bacon.bac"
__b2c__assign = (char*)val__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " 0};"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6201 "bacon.bac"
}
#line 6202 "bacon.bac"
i = i + ( 5);
#line 6203 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "EVAL(__b2c_evalvars_" , g_FUNCNAME__b2c__string_var , "_" , STR__b2c__string_var(g_COUNTER) , "_" , STR__b2c__string_var(HASH(token__b2c__string_var)>>8) , ",__b2c_evalvals_" , g_FUNCNAME__b2c__string_var , "_" , STR__b2c__string_var(g_COUNTER) , "_" , STR__b2c__string_var(HASH(token__b2c__string_var)>>8) , "," , STR__b2c__string_var(nr) , "-1,") ;
#line 6204 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 5) ,  "FIND(") == 0 ){
#line 6205 "bacon.bac"
pos=(
long)( INSTR(MID__b2c__string_var(arg__b2c__string_var, i), "("));
#line 6206 "bacon.bac"
first__b2c__string_var = __b2c_Copy_String(first__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos)));
#line 6207 "bacon.bac"
intoken__b2c__string_var = F_CHOP__b2c__string_var(intoken__b2c__string_var,REPLACE__b2c__string_var(first__b2c__string_var, "$", g_STRINGSIGN__b2c__string_var));
#line 6208 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "#", g_FLOATSIGN__b2c__string_var));
#line 6209 "bacon.bac"
intoken__b2c__string_var = __b2c_Copy_String(intoken__b2c__string_var, (char*) REPLACE__b2c__string_var(intoken__b2c__string_var, "%", g_LONGSIGN__b2c__string_var));
#line 6210 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__tree_" , intoken__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 6211 "bacon.bac"
second__b2c__string_var = __b2c_Copy_String(second__b2c__string_var, (char*) Mini_Parser__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, i+pos+LEN(first__b2c__string_var)+1)));
#line 6212 "bacon.bac"
uniq__b2c__string_var = F_CONCAT__b2c__string_var(uniq__b2c__string_var, "__b2c__" , intoken__b2c__string_var , "_" , STR__b2c__string_var(g_COUNTER) , "_" , STR__b2c__string_var(RND)) ;
#line 6213 "bacon.bac"
if( __b2c__STRCMP(TOKEN__b2c__string_var(type__b2c__string_var, 2, ":") ,  "char*") == 0 ){
#line 6214 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = (char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) second__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6215 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "FIND(" , TOKEN__b2c__string_var(type__b2c__string_var, 1, ":") , "," , first__b2c__string_var , "," , "(void**)" , uniq__b2c__string_var , ",0") ;
#line 6216 "bacon.bac"
} else {
#line 6217 "bacon.bac"
__b2c__assign = (char*)TOKEN__b2c__string_var(type__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(type__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*)malloc(sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(type__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")); *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(type__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) second__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6218 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "FIND(" , TOKEN__b2c__string_var(type__b2c__string_var, 1, ":") , "," , first__b2c__string_var , "," , "(void*)" , uniq__b2c__string_var , ",1") ;
#line 6219 "bacon.bac"
}
#line 6220 "bacon.bac"
i = i + ( 6+LEN(first__b2c__string_var)+LEN(second__b2c__string_var));
#line 6221 "bacon.bac"
} else if( REGEX(MID__b2c__string_var(arg__b2c__string_var, i, 4), "REM[[:space:]]")  OR  __b2c__STRCMP(arg__b2c__string_var ,  "REM") == 0 ){
#line 6222 "bacon.bac"
break;
#line 6223 "bacon.bac"
} else if( ISTRUE(g_LOWERCASE)  AND  __b2c__STRCMP(MID__b2c__string_var(arg__b2c__string_var, i, 4) ,  "int(") == 0 ){
#line 6224 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "INT(") ;
#line 6225 "bacon.bac"
i = i + ( 4);
#line 6226 "bacon.bac"
}
#line 6227 "bacon.bac"
}
#line 6228 "bacon.bac"
__b2c__select_6228 = (double)ASC(MID__b2c__string_var(arg__b2c__string_var, i, 1));
#line 6230 "bacon.bac"
 if ( (__b2c__select_6228) == (92)){
#line 6231 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(92)) ;
#line 6232 "bacon.bac"
is_escaped=(
long)( NOT(is_escaped));
#line 6234 "bacon.bac"
} else  if ( (__b2c__select_6228) == (34)){
#line 6235 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(34)) ;
#line 6236 "bacon.bac"
if( NOT(is_escaped) ){
is_string=(
long)( NOT(is_string));
}
#line 6237 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6238 "bacon.bac"
} else {
#line 6239 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , MID__b2c__string_var(arg__b2c__string_var, i, 1)) ;
#line 6240 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6241 "bacon.bac"
}
#line 6242 "bacon.bac"
}
#line 6243 "bacon.bac"
} else {
#line 6244 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) arg__b2c__string_var);
#line 6245 "bacon.bac"
}
#line 6247 "bacon.bac"
__b2c__assign = __b2c__return(token__b2c__string_var);
 __b2c__free_str_array_members(&funcvar__b2c__string_var, 1, funcvar__b2c__string_var__b2c_array); __b2c__free_str_array_members(&mainvar__b2c__string_var, 1, mainvar__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(it__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(val__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(first__b2c__string_var);
__b2c__STRFREE(second__b2c__string_var);
__b2c__STRFREE(delim__b2c__string_var);
__b2c__STRFREE(intoken__b2c__string_var);
__b2c__STRFREE(uniq__b2c__string_var);
__b2c__STRFREE(__b2c__select_6023__b2c__string_var);
__b2c__STRFREE(__b2c__select_6073__b2c__string_var);
__b2c__STRFREE(__b2c__select_6101__b2c__string_var);
__b2c__STRFREE(funcvar__b2c__string_var);
__b2c__STRFREE(mainvar__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(__b2c__assign);
#line 6249 "bacon.bac"
__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
return (NULL);}
