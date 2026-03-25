/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#include "bacon.bac.generic.h"
#include "bacon.bac.functions.h"
#define g_VERSION ("5.0.3")
char* g_LDFLAGS = NULL;
#define g_STRINGSIGN ("")
#define g_LONGSIGN ("")
#define g_FLOATSIGN ("")
#define g_RANGEOP1 ("BETWEEN ")
#define g_RANGEOP2 ("BEYOND ")
long Color_Intense = 0;
long Line_Number_Active = 0;
long Stat_Col = 2;
long Func_Col = 6;
long Var_Col = 3;
long Type_Col = 3;
long Num_Col = 1;
long Comm_Col = 4;
long Quot_Col = 5;
long Def_Col = 7;
#define g_C_KEYWORDS ("^(asm|auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|inline|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|y0|y1|yn|y0f|y1f|ynf|y0l|y1l|ynl)$")
STRING assoc_g_ALL_MAIN_VARS_eval;
b2c_htable *assoc_g_ALL_MAIN_VARS, *assoc_g_ALL_MAIN_VARS_orig;
STRING assoc_g_ALL_MAIN_VARS_func(const char *key){void *result; result = b2c_hash_find_value(assoc_g_ALL_MAIN_VARS, key);
if(result == NULL) { return(NULL); } return((STRING)result); }
#define g_ALL_MAIN_VARS(...) assoc_g_ALL_MAIN_VARS_func(__b2c__KEYCOLLECT(__VA_ARGS__))
STRING assoc_g_ALL_FUNC_VARS_eval;
b2c_htable *assoc_g_ALL_FUNC_VARS, *assoc_g_ALL_FUNC_VARS_orig;
STRING assoc_g_ALL_FUNC_VARS_func(const char *key){void *result; result = b2c_hash_find_value(assoc_g_ALL_FUNC_VARS, key);
if(result == NULL) { return(NULL); } return((STRING)result); }
#define g_ALL_FUNC_VARS(...) assoc_g_ALL_FUNC_VARS_func(__b2c__KEYCOLLECT(__VA_ARGS__))
STRING assoc_g_ALL_DIM_VARS_eval;
b2c_htable *assoc_g_ALL_DIM_VARS, *assoc_g_ALL_DIM_VARS_orig;
STRING assoc_g_ALL_DIM_VARS_func(const char *key){void *result; result = b2c_hash_find_value(assoc_g_ALL_DIM_VARS, key);
if(result == NULL) { return(NULL); } return((STRING)result); }
#define g_ALL_DIM_VARS(...) assoc_g_ALL_DIM_VARS_func(__b2c__KEYCOLLECT(__VA_ARGS__))
STRING assoc_g_SEMANTIC_MEMFREE_eval;
b2c_htable *assoc_g_SEMANTIC_MEMFREE, *assoc_g_SEMANTIC_MEMFREE_orig;
STRING assoc_g_SEMANTIC_MEMFREE_func(const char *key){void *result; result = b2c_hash_find_value(assoc_g_SEMANTIC_MEMFREE, key);
if(result == NULL) { return(NULL); } return((STRING)result); }
#define g_SEMANTIC_MEMFREE(...) assoc_g_SEMANTIC_MEMFREE_func(__b2c__KEYCOLLECT(__VA_ARGS__))
STRING assoc_g_SEMANTIC_OPENCLOSE_eval;
b2c_htable *assoc_g_SEMANTIC_OPENCLOSE, *assoc_g_SEMANTIC_OPENCLOSE_orig;
STRING assoc_g_SEMANTIC_OPENCLOSE_func(const char *key){void *result; result = b2c_hash_find_value(assoc_g_SEMANTIC_OPENCLOSE, key);
if(result == NULL) { return(NULL); } return((STRING)result); }
#define g_SEMANTIC_OPENCLOSE(...) assoc_g_SEMANTIC_OPENCLOSE_func(__b2c__KEYCOLLECT(__VA_ARGS__))
STRING assoc_g_MACRO_STRINGS_eval;
b2c_htable *assoc_g_MACRO_STRINGS, *assoc_g_MACRO_STRINGS_orig;
STRING assoc_g_MACRO_STRINGS_func(const char *key){void *result; result = b2c_hash_find_value(assoc_g_MACRO_STRINGS, key);
if(result == NULL) { return(NULL); } return((STRING)result); }
#define g_MACRO_STRINGS(...) assoc_g_MACRO_STRINGS_func(__b2c__KEYCOLLECT(__VA_ARGS__))
#define Get_Var(...) __Get_Var(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), (char*)__VA_ARGS__)
char* __Get_Var(int, ...);
void Save_Main_Var( STRING var, STRING type);
void Save_Func_Var( STRING var, STRING func, STRING type);
void Debug_Vars( void);
void Register_Numeric( char* arg, char* type);
void Register_Pointer( char* arg, char* type);
#define Mini_Parser(...) __Mini_Parser(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), (char*)__VA_ARGS__)
double b2c_select_293 = 0;
char* __Mini_Parser(int, ...);
long Check_String_Type( char* arg);
void Assign_To_String( char* from, char* to, char* memsize);
void Assign_To_Number( char* from, char* to, long flag);
void Print_Element ( STRING arg, STRING std);
void Handle_Print( STRING arg, STRING std);
void Handle_Input( STRING arg);
char* g_STRINGARGS = NULL;
char* g_STRINGARRAYS = NULL;
void Handle_For( STRING arg);
void Handle_While( char* arg);
void Relate_Recurse( STRING var, STRING str, STRING tmp, NUMBER lvl);
double b2c_select_691 = 0;
char* g_LOCALSTRINGS = NULL;
void Handle_Let( STRING arg);
long g_CATCH_USED = 0;
void Handle_Open( STRING arg);
void Handle_Readln( STRING arg);
void Handle_Writeln( STRING arg);
void Handle_Getbyte( STRING arg);
void Handle_Putbyte( STRING arg);
void Handle_Getfile( STRING arg);
void Handle_Receive( STRING arg);
void Handle_Send( STRING arg);
void Handle_Getline( STRING arg);
void Handle_Putline( STRING arg);
char* g_IMPORTED = NULL;
void Handle_Import( STRING arg);
char* g_DYNAMICARRAYS = NULL;
char* g_GLOBALARRAYS = NULL;
char* g_STATICARRAYS = NULL;
void Normal_Dyn_Array( STRING t, STRING var, STRING array, int is_static, int is_local);
void Assoc_Array( STRING var, STRING type, int by_local);
void Binary_Tree( STRING var, STRING type, int by_local);
char* g_RECORDNAME = NULL;
char* g_RECORDVAR = NULL;
char* g_RECORDARRAY = NULL;
char* g_RECORDCACHE = NULL;
char* g_FUNCNAME = NULL;
void Handle_Declare( STRING arg);
char* g_RECORDEND_BODY = NULL;
void Handle_Local( STRING arg);
void Handle_Read( STRING arg);
char* g_PROTOTYPE = NULL;
FILE* g_CFILE = NULL;
char* g_INCLUDE_FILES = NULL;
char* g_TMP_FILES = NULL;
char* g_CFILE = NULL;
char* g_CATCHGOTO = NULL;
char* g_ORIGFUNCNAME = NULL;
char* g_FUNCTYPE = NULL;
void Handle_Endfunction( void);
void Handle_Return( STRING arg);
void Handle_Push( STRING arg);
void Handle_Pull( STRING arg);
char* g_ORIGCATCHGOTO = NULL;
long g_ORIGCATCH_USED = 0;
char* g_COPY_CFILE = NULL;
long g_COPY_COUNTER = 0;
void Handle_SubFunc( STRING arg);
void Handle_Endsub( void);
void Handle_Deffn( STRING arg);
void Handle_Const( STRING arg);
void Handle_Seek( STRING arg);
void Handle_Copy( STRING arg);
void Handle_Rename( STRING arg);
void Handle_Color( STRING arg);
void Handle_Type( STRING arg);
void Handle_Gotoxy( STRING arg);
void Handle_Split( STRING arg);
void Handle_Join( STRING arg);
void Handle_Sort( STRING arg);
void Handle_Alias( STRING arg);
void Handle_Lookup( STRING arg);
long g_RELATE_CTR = 0;
void Handle_Relate( STRING arg);
long g_CCTR = 0;
long g_FCTR = 0;
void Handle_Data( STRING arg);
void Handle_Redim( STRING arg);
void Handle_Swap( STRING arg);
void Handle_Setserial( STRING arg);
void Handle_Call( STRING arg);
void Handle_Run( STRING arg);
void Handle_Save( long type, char* arg);
void Handle_Map( STRING arg);
void Handle_Tree( STRING arg);
void Handle_Collect( STRING arg);
void Handle_Parse( STRING arg);
char* item = NULL;
void guiGenerate( char* data);
long g_USE_C = 0;
long g_USE_H = 0;
long g_COMMENT = 0;
long g_LOOPCTR = 0;
long g_TRACE = 0;
char* g_TRACE_PREFIX = NULL;
long g_DOTIMES = 0;
char* g_RECORDEND_HEADER = NULL;
char* g_WITHVAR = NULL;
char* g_CASE_FALL = NULL;
char* g_CASE_CONT = NULL;
long g_SELECTVAR_CTR = 0;
FILE* src_cpp = NULL;
long g_COUNTER = 0;
char* g_CURFILE = NULL;
char* g_DEPEND = NULL;
long g_TOTAL_LINES = 0;
char* g_MONITOR = NULL;
long g_OPTION_BASE = 0;
long g_OPTION_TLS = 0;
char* g_INC_TLS = NULL;
char* g_LIB_TLS = NULL;
char* g_CCFLAGS = NULL;
long g_OPTION_EVAL = 0;
char* g_OPTION_INPUT = NULL;
long g_OPTION_DISABLE_C_ESCAPE = 0;
long g_OPTION_SOCKET = 0;
long g_OPTION_BREAK = 0;
char* g_PRIORITY = NULL;
char* g_NETWORKTYPE = NULL;
char* g_SOCKTYPE = NULL;
long g_MULTICAST_TTL = 0;
char* g_INCFILES = NULL;
long g_SCTP_STREAMS = 0;
char* g_IGNORE_PARSE = NULL;
char* g_OPTION_EXPLICIT = NULL;
char* g_OPTION_LOCAL = NULL;
char* g_VARTYPE = NULL;
char* g_CCNAME = NULL;
char* g_PRAGMA_REGEX = NULL;
long g_WHICH_GUI = 0;
char* g_PRAGMA_INCLUDE = NULL;
void Parse_Line( STRING statement);
double b2c_select_5978 = 0;
double b2c_select_6228 = 0;
char* Pre_Tokenize_Functions( char* arg);
double b2c_select_6288 = 0;
double b2c_select_6364 = 0;
double b2c_select_6438 = 0;
long g_STRING_FUNC = 0;
void Tokenize( STRING current);
double b2c_select_6707 = 0;
char* Parse_Equation( STRING current);
#undef b2c_label_floatarray_network_error
#define b2c_label_floatarray_network_error 0
#undef b2c_label_stringarray_network_error
#define b2c_label_stringarray_network_error 0
void Download_File( STRING name);
void Editor_Print_Line( char* text, long vpos, long linenr, long inverse, int digits, long do_print);
void Editor_Print_Text( char* txt, long line, long verticalpos);
void Editor_Restore_Normal( void);
void Editor_Show_Help( void);
long g_CURSOR_X = 0;
long g_CURSOR_Y = 0;
double b2c_select_7182 = 0;
char* previous = NULL;
double b2c_select_7534 = 0;
double b2c_select_7538 = 0;
void Editor_Handle_Input( char* file, char* text);
long g_MAX_DIGITS = 0;
long g_BUFFER_SIZE = 0;
long g_MAX_RBUFFERS = 0;
char* g_TEMPDIR = NULL;
char* g_BINEXT = NULL;
char* g_CCNAME_TMP = NULL;
char* g_TEMPDIR_TMP = NULL;
char* g_INCFILES_TMP = NULL;
char* g_LDFLAGS_TMP = NULL;
char* g_CCFLAGS_TMP = NULL;
long g_NO_COMPILE = 0;
long g_TMP_PRESERVE = 0;
long g_QUIET = 0;
long g_EXEC = 0;
long g_SEMANTIC = 0;
long g_NO_QUESTION = 0;
long g_CPP = 0;
long g_XGETTEXT = 0;
long g_SAVE_CONFIG = 0;
long g_DEBUG = 0;
long g_LOWERCASE = 0;
long g_MAX_BACKLOG = 0;
char* g_SOURCEFILE = NULL;
char* g_ERRORTXT = NULL;
char* g_OBJ_FILES = NULL;
char* g_MAKE_LINE = NULL;
char* g_LOCAL_SBUFFER = NULL;
char* g_TWEAK = NULL;
char *g_SELECTVAR[(uint64_t)16+1] = { NULL };
long g_IN_CASE[(uint64_t)16+1] = { 0 };
char *g_RELATE[(uint64_t)256+1] = { NULL };
long starttime = 0;
long ttime = 0;
long RETURN_CODE = 0;
char *msec_time = NULL;
char *old_curdir = NULL;
char *mapping = NULL;
FILE* cfgfile = NULL;
char* line = NULL;
char *b2c_select_8045 = NULL;
long g_LOWERCASE_TMP = 0;
long opt = 0;
double b2c_select_8085 = 0;
char *b2c_select_8119 = NULL;
char* g_HFILE = NULL;
char* g_GENERIC = NULL;
char* g_FUNCTIONS = NULL;
char* STRINGARRAYFILE = NULL;
char* FLOATARRAYFILE = NULL;
char* SRCARRAYFILE = NULL;
char* total = NULL;
int b2c_forin_tmpfile_ptr = 0;
char *b2c_forin_tmpfile_string = NULL;
char *b2c_forin_tmpfile_string_org = NULL;
char *b2c_forin_tmpfile_step = NULL;
char* tmpfile = NULL;
char* response = NULL;
FILE* g_HFILE = NULL;
FILE* g_GENERIC = NULL;
FILE* STRINGARRAYFILE = NULL;
FILE* FLOATARRAYFILE = NULL;
#define Stat ("|ADD|ALARM|ALIAS|APPEND|APPENDING|ARRAY|AS|ASSOC|BACK|BAPPEND|BASE|BG|BLACK|BLINK|BLUE|BOLD|BREAK|BROADCAST|BSAVE|BY|CALL|CASE|CATCH|CERTIFICATE|" "CHANGEDIR|CHUNK|CLASS|CLEAR|CLOSE|CMODE|COLLAPSE|COLOR|COMPARE|COMPILER|COLLECT|CONST|CONTINUE|COPY|CURRENT|CURSOR|CYAN|DATA|DECLARE|DECR|DEF|DEFAULT|" "DELETE|DELIM|DEVICE|DIRECTORY|DO|DONE|DOTIMES|DOWN|DOWNTO|DQ|ELIF|ELSE|END|ENDCLASS|ENDENUM|ENDFORK|ENDFUNCTION|ENDIF|ENDRECORD|ENDSELECT|ENDSUB|ENDUSEC|" "ENDUSEH|ENDWITH|ENDFUNC|ENUM|EPRINT|EQ|ESC|EXIT|EXPLICIT|FG|FI|FILE|FN|FOR|FORMAT|FORWARD|FRAMEWORK|FREE|FROM|FTYPE|FUNC|FUNCTION|GE|GETBYTE|GETFILE|GETLINE|" "GLOBAL|GOSUB|GOTO|GOTOXY|GREEN|GT|GUI|IF|IMODE|IMPORT|IN|INCLUDE|INCR|INPUT|INTENSE|INTERNATIONAL|INVERSE|IS|ISNOT|ITALIC|JOIN|LABEL|LDFLAGS|LE|LET|LIBRARY|" "LMODE|LOCAL|LOOKUP|LT|MAGENTA|MAKEDIR|MAP|MEMREWIND|MEMSTREAM|MEMTYPE|MONITOR|MULTICAST|NE|NETWORK|NEXT|NORMAL|OFF|OFFSET|NO_C_ESC|NODE|OMODE|ON|OPEN|OPTION|OPTIONS|" "OTHER|PARSE|POKE|PRAGMA|PRINT|PRIORITY|PROPER|PROTO|PULL|PUSH|PUTBYTE|PUTLINE|QUOTED|RE|READ|READING|READLN|READWRITE|RECEIVE|RECORD|RECURSIVE|RED|REDIM|RELATE|REM|" "RENAME|REPEAT|RESET|RESIZE|TREE|RESTORE|RESUME|RETURN|REWIND|RUN|SAVE|SCREEN|SCROLL|SCTP|SEED|SEEK|SELECT|SEND|SERVER|SET|SETENVIRON|SETSERIAL|SIGNAL|" "SIZE|SLEEP|SOCKET|SORT|SPEED|SPLIT|START|STARTPOINT|STATIC|STEP|STOP|STRIKE|SUB|SWAP|SYSTEM|TCP|TEXTDOMAIN|THEN|TLS|TO|TRACE|TRAP|TYPE|UDP|UNDERLINE|UNSET|" "UNTIL|UP|USEC|USEH|UTF8|VAR|VARTYPE|WEND|WHENCE|WHILE|WHITE|WITH|WRITELN|WRITING|YELLOW|")
#define Func ("|ABS|ACCEPT|ACOS|ADDRESS|ALIGN\\$|AMOUNT|AND|APPEND\\$|ASC|ASIN|ATN|ATN2|B64DEC\\$|B64ENC\\$|BASENAME\\$|COIL\\$|BETWEEN|BEYOND|BIN\\$|BIT|BLOAD|" "BYTELEN|CEIL|CA\\$|CN\\$|CHANGE\\$|COLLAPSE\\$|CHOP\\$|CHR\\$|CIPHER\\$|CMDLINE|COLUMNS|CONCAT\\$|COS|COUNT|CURDIR\\$|CUT\\$|DAY|DEC|DEG|DEL\\$|DELIM\\$|" "DIRNAME\\$|EDITBOM\\$|ENDFILE|EQUAL|ERR\\$|ESCAPE\\$|EVAL|EVEN|EXCHANGE\\$|EXCL|EXEC\\$|EXP|EXPLODE\\$|EXTRACT\\$|FILEEXISTS|FILELEN|FILETIME|FILETYPE|FILL\\$|" "FIRST\\$|FLATTEN\\$|FLOOR|FORK|FP|GUICB|GUIFN|GUIDEFINE|GUIGET|GUISET|GUIEVENT\\$|GUIWIDGET|GETENVIRON\\$|GETKEY|GETPEER\\$|GETX|GETY|HASBOM|HASDELIM|HASH|HEAD\\$|HEX\\$|" "HOST\\$|HOSTNAME\\$|HOUR|IIF|IIF\\$|INBETWEEN\\$|INDEX|INDEX\\$|INSERT\\$|INSTR|INSTRREV|INT|INTL\\$|INVERT|ISASCII|ISFALSE|ISKEY|ISTOKEN|ISTRUE|ISUTF8|LAST\\$|" "LCASE\\$|LEFT\\$|LEN|LOAD\\$|LOG|LOOP|LOOP\\$|MATCH|MAX|MAX\\$|MAXNUM|ME\\$|MEMCHECK|MEMORY|MEMTELL|MERGE\\$|MID\\$|MIN|MIN\\$|MINUTE|MOD|MONTH|MONTH\\$|" "MYPID|NANOTIMER|NNTL\\$|NOT|NOW|NRKEYS|OBTAIN\\$|ODD|OR|OS\\$|OUTBETWEEN\\$|PEEK|POW|PROPER\\$|RAD|RANDOM|REALPATH\\$|REAP|RIP\\$|REGEX|REPLACE\\$|REV\\$|REVERSE\\$|" "RIGHT\\$|RND|ROL|ROR|ROTATE\\$|ROUND|ROWS|RUN\\$|SEARCH|SECOND|SGN|SIN|SIZEOF|FIND|SORT\\$|SPC\\$|SQR|STR\\$|SUM|SUMF|TAB\\$|TAIL\\$|TALLY|TAN|TELL|TIMER|" "TIMEVALUE|TOASCII\\$|TOKEN\\$|TOTAL|TYPEOF\\$|UCASE\\$|UBOUND|UCS|ULEN|UNFLATTEN\\$|UNESCAPE\\$|UNIQ\\$|UTF8\\$|VAL|VERIFY|WAIT|WALK\\$|WEEK|WEEKDAY\\$|WHERE|YEAR|")
#define Var ("|FALSE|TRUE|PI|MAXRANDOM|ERROR|RETVAL|REGLEN|LINENO|SP|NL\\$|CR\\$|EL\\$|CL\\$|DLE\\$|VERSION\\$|ARGUMENT\\$|SOURCE\\$|NULL|NUMBER|STRING|FLOATING|")
#define Type ("|const|int|double|float|long|char|short|void|signed|unsigned|static|volatile|struct|extern|public|private|virtual|uint8_t|uint16_t|uint32_t|uint64_t|uintptr_t|int8_t|int16_t|int32_t|int64_t|intptr_t|size_t|")
#define Num ("|0|1|2|3|4|5|6|7|8|9|")
#define Comm ("|REM|'|/\\*|")
#define Mlc ("\\*/")
int b2c_forin_kwd_ptr = 0;
char *b2c_forin_kwd_string = NULL;
char *b2c_forin_kwd_string_org = NULL;
char *b2c_forin_kwd_step = NULL;
char* kwd = NULL;
FILE* src_tmp = NULL;
FILE* src_in = NULL;
FILE* src_out = NULL;
char* FEED = NULL;
FILE* g_SOURCEFILE = NULL;
int b2c_forin_incfiles_ptr = 0;
char *b2c_forin_incfiles_string = NULL;
char *b2c_forin_incfiles_string_org = NULL;
char *b2c_forin_incfiles_step = NULL;
char* incfiles = NULL;
FILE* g_FUNCTIONS = NULL;
long COUNTER = 0;
char **semantic = { NULL }; long semantic__b2c_array = 0;
FILE* makefile = NULL;
int b2c_forin_line_ptr = 0;
char *b2c_forin_line_string = NULL;
char *b2c_forin_line_string_org = NULL;
char *b2c_forin_line_step = NULL;
#include "bacon.Get_Var.h"
#include "bacon.Save_Main_Var.h"
#include "bacon.Save_Func_Var.h"
#include "bacon.Debug_Vars.h"
#include "bacon.Register_Numeric.h"
#include "bacon.Register_Pointer.h"
#include "bacon.Mini_Parser.h"
#include "bacon.Check_String_Type.h"
#include "bacon.Assign_To_String.h"
#include "bacon.Assign_To_Number.h"
#include "bacon.Print_Element.h"
#include "bacon.Handle_Print.h"
#include "bacon.Handle_Input.h"
#include "bacon.Handle_For.h"
#include "bacon.Handle_While.h"
#include "bacon.Relate_Recurse.h"
#include "bacon.Handle_Let.h"
#include "bacon.Handle_Open.h"
#include "bacon.Handle_Readln.h"
#include "bacon.Handle_Writeln.h"
#include "bacon.Handle_Getbyte.h"
#include "bacon.Handle_Putbyte.h"
#include "bacon.Handle_Getfile.h"
#include "bacon.Handle_Receive.h"
#include "bacon.Handle_Send.h"
#include "bacon.Handle_Getline.h"
#include "bacon.Handle_Putline.h"
#include "bacon.Handle_Import.h"
#include "bacon.Normal_Dyn_Array.h"
#include "bacon.Assoc_Array.h"
#include "bacon.Binary_Tree.h"
#include "bacon.Handle_Declare.h"
#include "bacon.Handle_Local.h"
#include "bacon.Handle_Read.h"
#include "bacon.Handle_Endfunction.h"
#include "bacon.Handle_Return.h"
#include "bacon.Handle_Push.h"
#include "bacon.Handle_Pull.h"
#include "bacon.Handle_SubFunc.h"
#include "bacon.Handle_Endsub.h"
#include "bacon.Handle_Deffn.h"
#include "bacon.Handle_Const.h"
#include "bacon.Handle_Seek.h"
#include "bacon.Handle_Copy.h"
#include "bacon.Handle_Rename.h"
#include "bacon.Handle_Color.h"
#include "bacon.Handle_Type.h"
#include "bacon.Handle_Gotoxy.h"
#include "bacon.Handle_Split.h"
#include "bacon.Handle_Join.h"
#include "bacon.Handle_Sort.h"
#include "bacon.Handle_Alias.h"
#include "bacon.Handle_Lookup.h"
#include "bacon.Handle_Relate.h"
#include "bacon.Handle_Data.h"
#include "bacon.Handle_Redim.h"
#include "bacon.Handle_Swap.h"
#include "bacon.Handle_Setserial.h"
#include "bacon.Handle_Call.h"
#include "bacon.Handle_Run.h"
#include "bacon.Handle_Save.h"
#include "bacon.Handle_Map.h"
#include "bacon.Handle_Tree.h"
#include "bacon.Handle_Collect.h"
#include "bacon.Handle_Parse.h"
#include "bacon.guiGenerate.h"
#include "bacon.Parse_Line.h"
#include "bacon.Pre_Tokenize_Functions.h"
#include "bacon.Tokenize.h"
#include "bacon.Parse_Equation.h"
#include "bacon.Download_File.h"
#include "bacon.Editor_Print_Line.h"
#include "bacon.Editor_Print_Text.h"
#include "bacon.Editor_Restore_Normal.h"
#include "bacon.Editor_Show_Help.h"
#include "bacon.Editor_Handle_Input.h"
void b2c_set_stack_size(void) { struct rlimit rl; getrlimit (RLIMIT_STACK, &rl); rl.rlim_cur = RLIM_INFINITY; setrlimit (RLIMIT_STACK, &rl); }
void s_free(void) {  b2c_hash_clear(assoc_g_ALL_MAIN_VARS); free(assoc_g_ALL_MAIN_VARS); assoc_g_ALL_MAIN_VARS = NULL; b2c_hash_clear(assoc_g_ALL_FUNC_VARS); free(assoc_g_ALL_FUNC_VARS); assoc_g_ALL_FUNC_VARS = NULL; b2c_hash_clear(assoc_g_ALL_DIM_VARS); free(assoc_g_ALL_DIM_VARS); assoc_g_ALL_DIM_VARS = NULL; b2c_hash_clear(assoc_g_SEMANTIC_MEMFREE); free(assoc_g_SEMANTIC_MEMFREE); assoc_g_SEMANTIC_MEMFREE = NULL; b2c_hash_clear(assoc_g_SEMANTIC_OPENCLOSE); free(assoc_g_SEMANTIC_OPENCLOSE); assoc_g_SEMANTIC_OPENCLOSE = NULL; b2c_hash_clear(assoc_g_MACRO_STRINGS); free(assoc_g_MACRO_STRINGS); assoc_g_MACRO_STRINGS = NULL; b2c_free_str_array_members(&semantic, 1, semantic__b2c_array); free(semantic); }
