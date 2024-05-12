# 1 "lex.m"
struct _PRIVATE { struct _PRIVATE *isa; };
typedef struct _PRIVATE *id;
struct _SHARED {
  id isa;
  id clsSuper;
  char *clsName;
  char *clsTypes;
  short clsSizInstance;
  short clsSizDict;
  struct _SLT *clsDispTable;
  long clsStatus;
  struct modDescriptor *clsMod;
  unsigned clsVersion;
  id clsCats;
  id *clsGlbl;
};
extern id  (* _imp(id,char*))();
extern id  (* _impSuper(id,char*))();
extern struct modDescriptor  *_OBJCBIND_lex(void);
static char **selTransTbl;
struct _SLT {char *_cmd;id (*_imp)();};
struct modDescriptor {
  char *modName;
  char *modVersion;
  long modStatus;
  char *modMinSel;
  char *modMaxSel;
  id *modClsLst;
  short modSelRef;
  char **modSelTbl;
  struct methodDescriptor *modMapTbl;
};
extern struct modDescriptor lex_modDesc;

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//string.h"
#include <string.h>

# 1 "../../util//errno.h"
#include <errno.h>

# 1 "../../util//stdlib.h"
#include <stdlib.h>

# 50 "lex.yy.c"
typedef signed char flex_int8_t;
typedef short int flex_int16_t;
typedef int flex_int32_t;
typedef unsigned char flex_uint8_t;
typedef unsigned short int flex_uint16_t;
typedef unsigned int flex_uint32_t;
# 161 "lex.yy.c"
typedef struct yy_buffer_state*YY_BUFFER_STATE;
# 166 "lex.yy.c"
typedef size_t yy_size_t;


extern yy_size_t yyleng;

extern FILE*yyin,*yyout;
# 177 "lex.yy.c"
#define YY_LESS_LINENO(n)


# 178 "lex.yy.c"
#define YY_LINENO_REWIND_TO(ptr)

# 198 "lex.yy.c"
struct yy_buffer_state
{
FILE*yy_input_file;

char*yy_ch_buf;
char*yy_buf_pos;
# 208 "lex.yy.c"
yy_size_t yy_buf_size;
# 213 "lex.yy.c"
yy_size_t yy_n_chars;
# 219 "lex.yy.c"
int yy_is_our_buffer;
# 226 "lex.yy.c"
int yy_is_interactive;
# 232 "lex.yy.c"
int yy_at_bol;

int yy_bs_lineno;
int yy_bs_column;
# 240 "lex.yy.c"
int yy_fill_buffer;

int yy_buffer_status;
# 258 "lex.yy.c"
};
# 262 "lex.yy.c"
static size_t yy_buffer_stack_top=0;
static size_t yy_buffer_stack_max=0;
static YY_BUFFER_STATE*yy_buffer_stack=0;
# 282 "lex.yy.c"
static char yy_hold_char;
static yy_size_t yy_n_chars;
yy_size_t yyleng;


static char*yy_c_buf_p=(char*)0;
static int yy_init=0;
static int yy_start=0;
# 294 "lex.yy.c"
static int yy_did_buffer_switch_on_eof;

void yyrestart(FILE*input_file);
void yy_switch_to_buffer(YY_BUFFER_STATE new_buffer);
YY_BUFFER_STATE yy_create_buffer(FILE*file,int size);
void yy_delete_buffer(YY_BUFFER_STATE b);
void yy_flush_buffer(YY_BUFFER_STATE b);
void yypush_buffer_state(YY_BUFFER_STATE new_buffer);
void yypop_buffer_state(void);

static void yyensure_buffer_stack(void);
static void yy_load_buffer_state(void);
static void yy_init_buffer(YY_BUFFER_STATE b,FILE*file);
# 310 "lex.yy.c"
YY_BUFFER_STATE yy_scan_buffer(char*base,yy_size_t size);
YY_BUFFER_STATE yy_scan_string(char*yy_str);
YY_BUFFER_STATE yy_scan_bytes(char*bytes,yy_size_t len);

void*yyalloc(yy_size_t);
void*yyrealloc(void*,yy_size_t);
void yyfree(void*);
# 344 "lex.yy.c"
typedef unsigned char YY_CHAR;

FILE*yyin=(FILE*)0,*yyout=(FILE*)0;

typedef int yy_state_type;

extern int yylineno;

int yylineno=1;

extern char*yytext;
# 360 "lex.yy.c"
static yy_state_type yy_get_previous_state(void);
static yy_state_type yy_try_NUL_trans(yy_state_type current_state);
static int yy_get_next_buffer(void);
# 366 "lex.yy.c"
static void yy_fatal_error(char msg[]);
# 382 "lex.yy.c"
struct yy_trans_info
{
flex_int32_t yy_verify;
flex_int32_t yy_nxt;
};
static flex_int16_t yy_accept[747]=
{0,
0,0,182,180,165,166,166,124,180,180,
178,130,141,180,118,119,128,131,159,132,
123,129,174,174,147,160,135,148,137,146,
180,120,121,142,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,
178,161,143,162,125,165,166,140,0,168,
0,0,167,167,178,153,144,154,0,171,
0,151,126,149,127,150,122,0,177,179,
152,175,172,174,0,174,0,133,136,164,
139,138,134,0,0,0,0,0,0,156,

178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,
178,178,178,178,10,178,178,178,178,178,
178,178,49,20,178,178,178,178,178,178,
178,178,178,178,178,178,178,155,145,0,
0,0,0,0,0,163,0,177,179,175,
0,175,172,0,176,174,173,157,158,0,
0,0,0,0,0,0,0,178,178,178,
178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,

178,178,178,178,178,178,178,178,178,178,
178,178,178,55,178,178,178,178,178,178,
178,178,178,178,178,86,178,18,178,178,
22,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,0,
0,0,0,0,0,0,177,177,0,0,
175,0,175,175,172,176,174,173,0,0,
47,0,0,0,0,0,0,0,178,178,
178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,

178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,85,
178,178,178,178,1,36,178,4,7,178,
178,178,178,12,13,178,178,19,178,23,
178,178,178,178,178,178,178,178,178,178,
178,178,178,34,178,178,178,0,0,0,
0,0,0,177,169,0,175,175,175,172,
176,173,43,0,0,0,0,0,0,0,
0,178,2,178,178,178,178,178,178,178,
178,178,178,178,178,70,178,178,178,178,

178,178,178,178,84,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,
178,178,178,178,178,178,178,178,88,178,
178,3,39,178,178,178,178,17,178,178,
178,178,178,26,178,178,178,178,178,178,
32,178,178,178,35,0,0,175,176,173,
0,0,0,0,0,0,0,0,178,178,
178,178,178,178,178,178,178,111,178,178,
178,0,178,0,178,178,178,178,178,178,
178,178,178,178,178,100,178,178,178,178,

178,87,178,178,178,178,178,103,178,178,
178,178,178,178,178,178,82,178,178,178,
178,178,11,16,54,89,178,178,25,41,
27,28,29,30,178,178,178,178,48,0,
0,0,0,51,0,0,5,178,178,178,
178,178,178,178,104,117,178,178,0,71,
0,56,178,95,83,64,178,178,178,178,
110,178,178,178,99,178,178,178,178,178,
178,178,178,178,178,178,178,178,178,178,
178,72,90,178,178,9,0,178,178,31,

178,178,37,0,0,53,0,0,0,116,
6,178,81,178,178,115,178,178,0,178,
0,178,178,178,93,178,178,178,74,178,
107,178,178,178,178,178,178,65,178,178,
58,76,178,178,178,91,8,0,24,40,
33,42,0,0,0,50,44,178,60,80,
178,178,0,178,0,112,61,94,178,178,
178,105,178,178,178,0,178,178,101,102,
178,92,109,178,178,178,38,0,0,45,
52,21,178,178,0,178,96,178,97,73,

178,178,0,113,78,108,66,77,67,62,
14,0,0,178,178,0,0,178,0,178,
106,98,178,178,178,0,0,178,170,57,
0,178,0,114,178,79,68,63,15,0,
59,69,75,0,46,0
};

static YY_CHAR yy_ec[256]=
{0,
1,1,1,1,1,1,1,1,2,3,
1,1,4,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,5,6,7,8,9,10,11,12,13,
14,15,16,17,18,19,20,21,22,23,
23,24,23,25,23,26,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,
40,40,41,40,40,42,40,43,44,45,
40,40,46,47,48,40,40,49,40,40,
50,51,52,53,54,1,55,56,57,58,

59,60,61,62,63,40,64,65,66,67,
68,69,70,71,72,73,74,75,76,77,
78,79,80,81,82,83,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,

1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1
};

static YY_CHAR yy_meta[84]=
{0,
1,2,3,3,2,1,4,1,5,1,
1,6,1,1,1,1,7,1,1,1,
8,8,8,8,8,9,1,1,1,1,
1,4,1,10,10,10,10,10,10,11,
11,11,11,11,11,11,11,11,12,1,
4,1,1,5,13,13,10,10,10,13,
11,11,11,11,11,11,12,11,11,11,
12,11,12,11,12,11,12,11,11,2,
1,1,1
};

static flex_uint16_t yy_base[765]=
{0,
0,0,1317,1318,82,1318,1313,1285,78,85,
0,1284,75,79,1318,1318,1283,74,1318,76,
74,72,112,171,1318,1318,79,83,81,1318,
56,1318,1318,1282,212,29,49,77,81,76,
87,1243,98,1242,1254,1249,100,1229,1239,1237,
59,1318,88,1318,1318,121,1318,1318,115,1318,
157,143,1318,1301,0,1318,1318,1318,132,1318,
177,1318,1318,1318,1318,1318,1318,1284,264,0,
1318,271,163,0,199,168,0,1272,1318,1318,
1318,1318,1271,1241,1232,101,77,1239,1238,1318,

1223,96,1227,1228,117,1224,1237,125,1229,298,
1232,1234,1221,1228,1231,1212,1218,1210,1214,1222,
1208,1224,1211,1217,1202,1203,1200,1200,1201,1203,
1199,1196,0,0,162,1201,1195,171,1198,96,
117,1202,1195,166,176,1201,1199,1318,1318,326,
293,0,364,240,0,1318,374,262,0,423,
386,299,234,357,395,278,385,1318,1318,1201,
150,1191,1186,205,1202,1187,1191,1187,1186,1190,
1186,1196,147,1185,1176,1191,1186,1174,1174,1196,
177,1188,202,1183,1164,119,1166,1172,1170,1178,

1165,1176,380,189,1167,1165,1175,1172,1159,1164,
1173,1155,1168,0,1157,1159,1168,1163,1150,205,
1165,1163,1159,1151,1157,0,1160,0,1146,1150,
0,1151,1154,1147,1136,1134,1136,1139,1146,1131,
1129,1129,1142,1132,1136,1140,1142,1141,1130,445,
490,530,451,579,619,468,497,438,483,554,
498,509,586,532,436,587,1318,585,1122,1125,
1318,1127,1132,1115,1116,1123,1113,1127,1119,1119,
1118,1113,1120,1113,1120,1113,1112,1112,1153,1101,
1114,1129,1105,1097,1097,1109,1100,1101,1108,238,

263,1093,1102,267,338,1107,1106,1088,1084,260,
1097,1099,1084,1084,1085,1081,1087,1089,1093,0,
1086,1077,1090,1089,0,0,1081,0,0,1071,
1080,1068,1076,0,0,1069,1066,0,1071,0,
1082,1064,1064,1063,1060,1073,1063,1067,1072,1071,
1069,1059,1064,0,1051,1052,1063,291,0,659,
268,0,699,1318,598,639,647,648,1318,1318,
667,697,1318,1063,1061,1048,1063,1058,1053,1052,
1057,1050,0,1039,1046,1047,1035,1035,1052,1043,
1046,1079,1044,1047,1065,686,1029,1040,1041,1025,

1022,1030,1026,1034,1070,1018,1017,1030,1025,280,
1029,1025,1014,1023,1010,1023,279,1021,1013,1022,
1021,1018,1017,1012,1019,1018,1007,1004,0,1015,
1014,0,0,1001,1002,1007,998,0,1005,998,
989,998,993,0,1001,998,1000,983,993,995,
0,986,989,997,0,355,372,1318,1318,1318,
991,983,988,974,989,988,973,970,985,978,
981,972,973,963,980,968,976,0,967,974,
984,420,976,947,965,969,961,952,952,951,
951,954,995,962,947,0,950,992,944,956,

959,0,946,940,939,950,953,0,948,951,
950,949,935,941,928,929,0,940,933,932,
922,922,0,989,0,0,934,935,0,0,
0,0,0,0,931,931,924,915,1318,928,
931,926,911,1318,924,914,0,914,903,924,
913,906,911,911,0,0,920,932,0,0,
890,1318,915,957,0,915,899,898,870,849,
0,865,862,819,0,806,804,810,819,810,
813,802,802,805,797,792,798,782,770,773,
781,0,0,768,772,0,820,755,752,0,

765,762,0,742,743,1318,740,702,699,0,
0,698,0,701,708,0,700,720,389,689,
747,706,688,693,0,688,685,682,694,673,
0,678,731,686,681,658,671,674,646,645,
0,651,645,638,629,0,0,665,0,0,
0,0,627,640,634,1318,1318,589,0,0,
598,606,424,575,618,1318,0,0,574,538,
534,0,540,524,516,568,500,489,0,0,
506,0,0,505,486,484,0,267,487,1318,
1318,0,481,463,579,440,482,420,0,0,

413,424,467,1318,425,0,0,0,417,410,
1318,441,383,385,384,724,426,382,418,376,
0,0,370,360,347,361,303,263,0,449,
593,258,217,1318,150,0,0,0,1318,91,
0,0,0,57,1318,1318,771,784,793,806,
816,826,839,845,851,857,869,882,888,901,
914,927,940,953
};

static flex_int16_t yy_def[765]=
{0,
746,1,746,746,746,746,746,746,747,748,
749,746,746,750,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,746,746,746,746,746,746,746,747,746,
751,748,746,746,749,746,746,746,750,746,
752,746,746,746,746,746,746,746,746,753,
746,746,23,24,746,746,754,746,746,746,
746,746,746,746,746,746,746,746,746,746,

749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,746,746,747,
747,755,750,750,756,746,746,746,753,746,
746,746,746,746,746,746,754,746,746,746,
746,746,746,746,746,746,746,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,

749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,747,
747,251,750,750,254,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,

749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,747,252,252,
750,255,255,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,

749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,747,750,746,746,746,
746,746,746,746,746,746,746,746,749,749,
749,749,749,749,749,749,749,749,749,749,
749,757,749,758,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,

749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,746,746,
746,746,746,746,746,746,749,749,749,749,
749,749,749,749,749,749,749,749,759,749,
758,746,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,746,749,749,749,

749,749,749,746,746,746,746,746,746,749,
749,749,749,749,749,749,749,749,759,749,
760,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,749,749,749,
749,749,749,749,749,749,749,746,749,749,
749,749,746,746,746,746,746,749,749,749,
749,749,761,749,760,746,749,749,749,749,
749,749,749,749,749,762,749,749,749,749,
749,749,749,749,749,749,749,746,746,746,
746,749,749,749,761,749,749,749,749,749,

749,749,762,746,749,749,749,749,749,749,
746,746,746,749,749,746,763,749,764,749,
749,749,749,749,749,746,746,749,749,763,
763,749,764,746,749,749,749,749,746,746,
749,749,749,746,746,0,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746
};

static flex_uint16_t yy_nxt[1402]=
{0,
4,5,6,7,5,8,9,10,11,12,
13,14,15,16,17,18,19,20,21,22,
23,24,24,24,24,24,25,26,27,28,
29,30,31,11,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,32,
4,33,34,35,36,37,38,39,40,41,
42,11,43,11,44,11,11,11,45,11,
46,47,48,49,50,51,11,11,11,52,
53,54,55,56,60,67,56,63,64,73,
70,80,78,75,79,79,79,79,79,79,

117,81,118,74,68,76,77,88,89,90,
92,93,91,94,95,146,119,148,96,120,
147,60,56,745,97,56,98,99,61,71,
82,121,83,83,83,83,83,84,122,124,
126,129,127,70,123,63,64,174,125,85,
175,130,128,86,131,133,238,134,744,86,
87,139,140,179,135,61,172,173,149,180,
85,240,141,301,239,142,86,150,151,151,
151,151,71,187,183,86,302,241,87,82,
184,84,84,84,84,84,84,153,154,154,

154,154,188,743,163,152,270,271,85,166,
163,746,86,284,164,166,164,285,86,165,
165,165,165,165,165,155,230,163,244,85,
734,234,166,152,231,86,163,245,246,746,
247,166,235,236,86,101,102,103,293,294,
314,70,104,155,105,106,107,108,109,296,
253,253,253,253,253,110,315,274,111,297,
298,112,275,711,113,265,330,331,114,70,
115,265,712,116,79,79,79,79,79,79,
71,160,160,160,160,160,160,60,265,60,

258,157,158,258,498,158,403,265,161,162,
404,742,162,250,250,250,250,250,71,267,
417,258,157,158,418,267,258,741,158,161,
162,409,60,405,406,162,190,264,499,410,
264,61,267,61,506,507,250,250,250,250,
250,267,191,192,193,194,195,196,264,197,
198,60,199,264,200,740,201,739,202,203,
204,205,206,207,251,70,61,165,165,165,
165,165,165,70,253,253,253,253,253,256,
663,256,411,663,257,257,257,257,257,257,

738,262,251,262,412,61,263,263,263,263,
263,263,254,737,71,165,165,165,165,165,
165,482,71,736,482,663,268,731,663,735,
731,734,268,266,309,732,266,729,310,728,
254,259,311,160,160,160,160,160,160,268,
746,60,312,746,266,727,726,313,268,266,
260,261,70,725,261,358,358,358,358,358,
724,361,361,361,361,361,364,370,723,364,
704,260,261,370,722,721,720,261,257,257,
257,257,257,257,719,61,60,364,718,484,

370,71,364,365,365,365,365,365,365,370,
359,359,359,359,359,359,715,257,257,257,
257,257,257,359,359,359,359,359,359,263,
263,263,263,263,263,158,368,714,158,368,
61,713,710,709,359,359,359,359,359,359,
360,360,360,360,360,360,158,368,708,707,
706,158,368,360,360,360,360,360,360,366,
369,366,705,369,367,367,367,367,367,367,
716,704,702,716,360,360,360,360,360,360,
70,369,701,700,731,717,369,731,699,362,

362,362,362,362,362,698,263,263,263,263,
263,263,362,362,362,362,362,362,365,365,
365,365,365,365,162,371,372,162,371,71,
697,666,372,362,362,362,362,362,362,363,
363,363,363,363,363,162,371,696,694,372,
162,371,363,363,363,363,363,363,372,367,
367,367,367,367,367,693,692,367,367,367,
367,367,367,363,363,363,363,363,363,456,
456,456,456,456,456,261,458,482,261,458,
482,691,456,456,456,456,456,456,690,689,

688,687,686,685,684,459,261,458,459,683,
682,261,458,456,456,456,456,456,456,457,
457,457,457,457,457,716,459,681,716,680,
679,459,457,457,457,457,457,457,460,483,
717,678,677,676,460,675,674,673,672,671,
670,669,668,457,457,457,457,457,457,667,
666,460,664,662,661,484,660,659,658,657,
460,59,59,656,59,59,59,59,59,59,
59,59,59,59,62,62,62,62,62,62,
62,62,62,62,62,62,62,65,655,654,

65,65,65,65,65,65,69,69,653,69,
69,69,69,69,69,69,69,69,69,59,
652,59,651,59,650,649,648,59,59,69,
647,69,646,69,645,644,643,69,69,159,
159,642,159,159,159,159,159,159,159,159,
159,159,167,167,167,641,640,167,252,252,
252,639,638,252,255,255,255,637,636,255,
559,635,634,633,632,631,630,629,559,559,
559,559,561,561,561,561,561,561,561,561,
561,561,561,561,561,619,619,619,619,619,

619,665,665,665,665,665,665,665,665,665,
665,665,665,665,695,695,628,695,695,627,
626,695,695,695,695,695,695,703,703,703,
703,703,703,703,703,703,703,703,703,703,
730,730,625,730,730,730,730,730,730,730,
730,730,730,733,733,733,733,733,733,733,
733,733,733,733,733,733,624,623,622,621,
620,562,618,617,616,615,614,613,612,611,
610,609,608,607,606,605,604,603,602,601,
600,599,598,597,596,595,594,593,592,591,

590,589,588,587,586,585,584,583,582,581,
580,579,578,577,576,575,574,573,572,571,
570,569,568,567,566,565,564,563,562,560,
558,557,556,555,554,553,552,551,550,549,
548,547,546,545,544,543,542,541,540,539,
538,537,536,535,534,533,532,531,530,529,
528,527,526,525,524,523,522,521,520,519,
518,517,516,515,514,513,512,511,510,509,
508,505,504,503,502,501,500,497,496,495,
494,493,492,491,490,489,488,487,486,485,

481,480,479,478,477,476,475,474,473,472,
471,470,469,468,467,466,465,464,463,462,
461,455,454,453,452,451,450,449,448,447,
446,445,444,443,442,441,440,439,438,437,
436,435,434,433,432,431,430,429,428,427,
426,425,424,423,422,421,420,419,416,415,
414,413,408,407,402,401,400,399,398,397,
396,395,394,393,392,391,390,389,388,387,
386,385,384,383,382,381,380,379,378,377,
376,375,374,373,357,356,355,354,353,352,

351,350,349,348,347,346,345,344,343,342,
341,340,339,338,337,336,335,334,333,332,
329,328,327,326,325,324,323,322,321,320,
319,318,317,316,308,307,306,305,304,303,
300,299,295,292,291,290,289,288,287,286,
283,282,281,280,279,278,277,276,273,272,
269,249,248,243,242,237,233,232,229,228,
227,226,225,224,223,222,221,220,219,218,
217,216,215,214,213,212,211,210,209,208,
189,186,185,182,181,178,177,176,171,170,

169,168,156,63,145,144,143,138,137,136,
132,100,72,66,58,57,746,3,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,

746
};

static flex_int16_t yy_chk[1402]=
{0,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,5,9,13,5,10,10,18,
14,22,21,20,21,21,21,21,21,21,

36,22,36,18,13,20,20,27,27,28,
29,29,28,31,31,51,37,53,31,37,
51,59,56,744,31,56,31,31,9,14,
23,38,23,23,23,23,23,23,38,39,
40,41,40,69,38,62,62,97,39,23,
97,41,40,23,41,43,140,43,740,23,
23,47,47,102,43,59,96,96,53,102,
23,141,47,196,140,47,23,61,61,61,
61,61,69,108,105,23,196,141,23,24,
105,24,24,24,24,24,24,71,71,71,

71,71,108,735,83,61,171,171,24,86,
83,83,24,183,85,86,85,183,24,85,
85,85,85,85,85,71,135,83,144,24,
733,138,86,61,135,24,83,144,145,83,
145,86,138,138,24,35,35,35,191,191,
204,154,35,71,35,35,35,35,35,193,
154,154,154,154,154,35,204,174,35,193,
193,35,174,688,35,163,220,220,35,361,
35,163,688,35,79,79,79,79,79,79,
154,82,82,82,82,82,82,358,163,151,

158,79,79,158,410,79,300,163,82,82,
300,732,82,151,151,151,151,151,361,166,
310,158,79,79,310,166,158,728,79,82,
82,304,150,301,301,82,110,162,410,304,
162,358,166,151,417,417,150,150,150,150,
150,166,110,110,110,110,110,110,162,110,
110,456,110,162,110,727,110,726,110,110,
110,110,110,110,150,153,150,164,164,164,
164,164,164,457,153,153,153,153,153,157,
619,157,305,619,157,157,157,157,157,157,

725,161,150,161,305,456,161,161,161,161,
161,161,153,724,153,165,165,165,165,165,
165,482,457,723,482,663,167,717,663,720,
717,719,167,165,203,718,165,715,203,714,
153,160,203,160,160,160,160,160,160,167,
730,250,203,730,165,713,712,203,167,165,
160,160,253,710,160,250,250,250,250,250,
709,253,253,253,253,253,258,265,705,258,
703,160,160,265,702,701,698,160,256,256,
256,256,256,256,697,250,251,258,696,482,

265,253,258,259,259,259,259,259,259,265,
251,251,251,251,251,251,694,257,257,257,
257,257,257,251,251,251,251,251,251,262,
262,262,262,262,262,257,261,693,257,261,
251,689,686,685,251,251,251,251,251,251,
252,252,252,252,252,252,257,261,684,681,
678,257,261,252,252,252,252,252,252,260,
264,260,677,264,260,260,260,260,260,260,
695,676,675,695,252,252,252,252,252,252,
254,264,674,673,731,695,264,731,671,254,

254,254,254,254,254,670,263,263,263,263,
263,263,254,254,254,254,254,254,365,365,
365,365,365,365,263,266,268,263,266,254,
669,665,268,254,254,254,254,254,254,255,
255,255,255,255,255,263,266,664,662,268,
263,266,255,255,255,255,255,255,268,366,
366,366,366,366,366,661,658,367,367,367,
367,367,367,255,255,255,255,255,255,360,
360,360,360,360,360,367,368,396,367,368,
396,655,360,360,360,360,360,360,654,653,

648,645,644,643,642,371,367,368,371,640,
639,367,368,360,360,360,360,360,360,363,
363,363,363,363,363,716,371,638,716,637,
636,371,363,363,363,363,363,363,372,396,
716,635,634,633,372,632,630,629,628,627,
626,624,623,363,363,363,363,363,363,622,
621,372,620,618,617,396,615,614,612,609,
372,747,747,608,747,747,747,747,747,747,
747,747,747,747,748,748,748,748,748,748,
748,748,748,748,748,748,748,749,607,605,

749,749,749,749,749,749,750,750,604,750,
750,750,750,750,750,750,750,750,750,751,
602,751,601,751,599,598,597,751,751,752,
595,752,594,752,591,590,589,752,752,753,
753,588,753,753,753,753,753,753,753,753,
753,753,754,754,754,587,586,754,755,755,
755,585,584,755,756,756,756,583,582,756,
757,581,580,579,578,577,576,574,757,757,
757,757,758,758,758,758,758,758,758,758,
758,758,758,758,758,759,759,759,759,759,

759,760,760,760,760,760,760,760,760,760,
760,760,760,760,761,761,573,761,761,572,
570,761,761,761,761,761,761,762,762,762,
762,762,762,762,762,762,762,762,762,762,
763,763,569,763,763,763,763,763,763,763,
763,763,763,764,764,764,764,764,764,764,
764,764,764,764,764,764,568,567,566,564,
563,561,558,557,554,553,552,551,550,549,
548,546,545,543,542,541,540,538,537,536,
535,528,527,524,522,521,520,519,518,516,

515,514,513,512,511,510,509,507,506,505,
504,503,501,500,499,498,497,495,494,493,
492,491,490,489,488,487,486,485,484,483,
481,480,479,477,476,475,474,473,472,471,
470,469,468,467,466,465,464,463,462,461,
454,453,452,450,449,448,447,446,445,443,
442,441,440,439,437,436,435,434,431,430,
428,427,426,425,424,423,422,421,420,419,
418,416,415,414,413,412,411,409,408,407,
406,405,404,403,402,401,400,399,398,397,

395,394,393,392,391,390,389,388,387,386,
385,384,382,381,380,379,378,377,376,375,
374,357,356,355,353,352,351,350,349,348,
347,346,345,344,343,342,341,339,337,336,
333,332,331,330,327,324,323,322,321,319,
318,317,316,315,314,313,312,311,309,308,
307,306,303,302,299,298,297,296,295,294,
293,292,291,290,289,288,287,286,285,284,
283,282,281,280,279,278,277,276,275,274,
273,272,270,269,249,248,247,246,245,244,

243,242,241,240,239,238,237,236,235,234,
233,232,230,229,227,225,224,223,222,221,
219,218,217,216,215,213,212,211,210,209,
208,207,206,205,202,201,200,199,198,197,
195,194,192,190,189,188,187,186,185,184,
182,181,180,179,178,177,176,175,173,172,
170,147,146,143,142,139,137,136,132,131,
130,129,128,127,126,125,124,123,122,121,
120,119,118,117,116,115,114,113,112,111,
109,107,106,104,103,101,99,98,95,94,

93,88,78,64,50,49,48,46,45,44,
42,34,17,12,8,7,3,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,
746,746,746,746,746,746,746,746,746,746,

746
};

static yy_state_type yy_last_accepting_state;
static char*yy_last_accepting_cpos;

extern int yy_flex_debug;
int yy_flex_debug=0;
# 1025 "lex.yy.c"
char*yytext;
# 1 "../../util//stdarg.h"
#include <stdarg.h>

# 1 "../../util//assert.h"
#include <assert.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stdio.h"
#include <stdio.h>

# 1 "../../util//stddef.h"
#include <stddef.h>

# 53 "./../../include/objcrt/objcrt.h"
typedef char*SEL;
typedef char*STR;
typedef char BOOL;
typedef FILE*IOD;
typedef id SHR;
# 62 "./../../include/objcrt/objcrt.h"
typedef id(*IMP)();


typedef void(*ARGIMP)(id,SEL,void*);
# 85 "./../../include/objcrt/objcrt.h"
extern BOOL msgFlag;
extern FILE*msgIOD;
extern FILE*dbgIOD;
extern BOOL allocFlag;
extern BOOL dbgFlag;
extern BOOL noCacheFlag;
extern BOOL noNilRcvr;
# 98 "./../../include/objcrt/objcrt.h"
SEL selUid(STR);
STR selName(SEL);
void dbg(char*fmt,...);
void loadobjc(void*modPtr);
void unloadobjc(void*modPtr);
# 106 "./../../include/objcrt/objcrt.h"
IMP fwdimp(id,SEL,IMP);
IMP fwdimpSuper(id,SEL,IMP);
void fwdmsg(id,SEL,void*,ARGIMP);
id selptrfwd(id,SEL,id,id,id,id);


id idincref(id obj);
id idassign(id*lhs,id rhs);
id iddecref(id obj);

extern id(*_fileIn)(FILE*);
extern BOOL(*_fileOut)(FILE*,id);
extern BOOL(*_storeOn)(STR,id);
extern id(*_readFrom)(STR);
void setfilein(id(*f)(FILE*));
void setfileout(BOOL(*f)(FILE*,id));

extern id(*_showOn)(id,unsigned);

void*OC_Malloc(size_t);
void*OC_MallocAtomic(size_t);
void*OC_Calloc(size_t);
void*OC_Realloc(void*,size_t);
void*OC_Free(void*data);
# 1 "../../util//string.h"
#include <string.h>

# 32 "./../../include/objpak/ocstring.h"
typedef struct objstr
{
int count;
int capacity;
char*ptr;
}*
objstr_t;
# 22 "./../oclib/symbol.h"
extern id s_void;
extern id s_char;
extern id s_bool;
extern id s_int;
extern id s_uns;
extern id s_long;
extern id s_double;
extern id s_str;
extern id s_sel;
extern id s_newblock;
extern id s_main;
extern id s_objcmain;
extern id s_id;
extern id s_nil;
extern id s_self;
extern id s_cmd;
extern id s_super;
extern id s_type;
extern id s_aFiler;
extern id s_fileIn;
extern id s_fileOut;
extern id s_fileInIdsFrom;
extern id s_fileOutIdsFor;
extern id s_returnval;
extern id s_returnflag;
extern id s_increfs;
extern id s_decrefs;
extern id s_idincref;
extern id s_iddecref;

BOOL istypeword(id sym);
BOOL isbuiltinfun(id sym);
int pragmatoggle(char*s);
void definebuiltintype(char*s);
void definebuiltinfun(char*s);
void definebuiltinvar(char*s);
# 22 "./../oclib/node.h"
extern FILE*gfile;
extern int inlineno;
extern id infilename;
extern int outlineno;
extern char*outfilename;
extern int exitstatus;
extern id loadedmodules;

void gc(char c);
void gextc(void);
void gcom(char*cm);
void gvarlist(id c,char*sp,char*iz);
void gcommalist(id c);
void gs(char*str);
void gf(char*fmt,...);
void gl(int no,char*fn);
void g_otbvars(void);
void gstderr(void);
void gnormal(void);
char*browsepath(char*filename);

void warn(char*fmt,...);
void warnat(id sym,char*fmt,...);
void fatal(char*fmt,...);
void fatalat(id sym,char*fmt,...);
# 23 "./../oclib/util.h"
extern FILE*yyin;
extern int yyparse();

FILE*openfile(STR name,STR modfs);
FILE*reopenfile(STR name,STR modfs,FILE*of);

extern int okblock;

id mkcppdirect(char*s);
id mkexprstmt(id expr);
id mklabeledstmt(id label,id stmt);
id mkcasestmt(id keyw,id expr,id stmt);
id mkdefaultstmt(id keyw,id stmt);
id mkifstmt(id keyw,id expr,id stmt);
id mkifelsestmt(id keyw,id expr,id stmt,id ekeyw,id estmt);
id mkswitchstmt(id keyw,id expr,id stmt);
id mkwhilestmt(id keyw,id expr,id stmt);
id mkdostmt(id keyw,id stmt,id wkeyw,id expr);
id mkforstmt(id keyw,id a,id b,id c,id stmt);
id mkgotostmt(id keyw,id label);
id mkcontinuestmt(id keyw);
id mkbreakstmt(id keyw);
id mkreturnstmt(id keyw,id expr);
id mkcastexpr(id a,id b);
id mkcondexpr(id a,id b,id c);
id mkunaryexpr(STR op,id a);
id mksizeof(id a);
id mktypeof(id kw,id a);
id mkaddressof(id a);
id mkdereference(id a);
id mkbinexpr(id a,STR op,id b);
id mkcommaexpr(id a,id b);
id mkrelexpr(id a,STR op,id b);
id mkassignexpr(id a,STR op,id b);
id mkfuncall(id funname,id args);
id mkbuiltincall(id funname,id args);
id mkfunbody(id datadefs,id compound);
void declarefun(id specs,id decl);
void declaremeth(BOOL factory,id decl);
id mkfundef(id specs,id decl,id body);
id mkmethdef(BOOL factory,id decl,id body);
id mkmesgexpr(id receiver,id args);
id mkdecl(id ident);
id mkprecdecl(id tquals,id decl);
id mkarraydecl(id lhs,id ix);
id mkfundecl(id lhs,id args);
id mkprefixdecl(id lhs,id rhs);
id mkpostfixdecl(id lhs,id rhs);
id mkpointer(id specs,id pointer);
id mkbitfielddecl(id decl,id expr);
id mkstardecl(id pointer,id decl);
id mkasmop(id string,id expr);
id mkasmstmt(id keyw,id tqual,id expr,id asmop1,id asmop2,id clobbers);
id mkcompstmt(id lb,id datadefs,id stmtlist,id subblock,id rb);
id mklist(id c,id s);
id mklist2(id c,id s,id t);
id atdefsaddall(id c,id n);
id mkblockexpr(id lb,id parms,id datadefs,id stmts,id expr,id rb);
id mkclassdef(id keyw,id name,id sname,id ivars,id cvars);
id mkdatadef(id datadef,id specs,id decl,id initializer);
id mkencodeexpr(id name);
id mkenumspec(id keyw,id name,id lb,id list,id rb);
id mkenumerator(id name,id value);
id mkgnuattrib(id anyword,id exprlist);
id mkgnuattribdecl(id keyw,id list);
id mklistexpr(id lb,id x,id rb);
id mktypename(id specs,id decl);
id mkcomponentdef(id cdef,id specs,id decl);
id mkstructspec(id keyw,id name,id lb,id defs,id rb);
id mkkeywarg(id sel,id arg);
id mkkeywdecl(id sel,id cast,id arg);
id mkmethproto(id cast,id usel,id ksel,BOOL varargs);
id mkidentexpr(id name);
id mkconstexpr(id name,id schain);
id mkprecexpr(id expr);
id mkbracedgroup(id expr);
id mkarrowexpr(id array,id ix);
id mkdotexpr(id array,id ix);
id mkindexexpr(id array,id ix);
id mkpostfixexpr(id expr,id pf);
id mkparmdef(id parmdef,id specs,id decl);
id mkparmdeflist(id idents,id parmdefs,BOOL varargs);
id mkselarg(id selarg,id usel,int ncols);
id mkselectorexpr(id expr);

void procextdef(id def);
void finclassdef(void);
void datadefokblock(id datadef,id specs,id decl);

id mkfileinmeth(id classdef,id ivarnames,id ivartypes);
id mkfileoutmeth(id classdef,id ivarnames,id ivartypes);

id mkincrefsmeth(id classdef,id ivarnames,id ivartypes);
id mkdecrefsmeth(id classdef,id ivarnames,id ivartypes);
# 22 "./../oclib/type.h"
extern id t_unknown;
extern id t_void;
extern id t_char;
extern id t_bool;
extern id t_int;
extern id t_long;
extern id t_uns;
extern id t_double;
extern id t_str;
extern id t_sel;
extern id t_id;
# 22 "./../oclib/options.h"
void defoptions(void);

extern int o_warnings;
extern int o_gnu;
extern int o_darwin;
extern int o_m64;
extern int o_sunstudio;
extern int o_hpux;
extern int o_vms;
extern int o_refcnt;
extern int o_ppi;
extern int o_watcom;
extern int o_ibmvac;
extern int o_msdos;
extern int o_enableasm;
extern int o_nolinetags;
extern int o_buffered;
extern int o_quiet;
extern int o_outputcode;
extern int o_version;
extern int o_otb;
extern int o_llkeyw;
extern int o_comments;
extern int o_duptypedefs;
extern int o_seltranslation;
extern int o_categories;
extern int o_blocks;
extern int o_fwd;
extern int o_selptr;
extern int o_cache;
extern int o_filer;
extern int o_selfassign;
extern char*o_bind;
extern char*o_browsedir;
extern int o_refbind;
extern int o_inlinecache;
extern int o_cplus;
extern int o_gencode;
extern int o_st80;
extern int o_selfassign;
extern int o_nilrcvr;
extern int o_shareddata;
extern int o_oneperfile;
extern int o_cvars;
extern int o_warnlex;
extern int o_warnfwd;
extern int o_warnsuggest;
extern int o_warnintvar;
extern int o_warnclasstype;
extern int o_warntypeconflict;
extern int o_warnundefined;
extern int o_warnlocalnst;
extern int o_warnnotfound;
extern int o_warnmissingmethods;
extern int o_attrcommon;
extern int o_postlink;
extern char*o_infile;
extern char*o_outfile;
extern char*o_srcfilename;
extern char*o_initcall;
extern char*o_tagformat;
extern char*o_mainfun;
extern char*o_pathsep;
extern int o_debuginfo;
extern int o_checkbind;
extern int o_linemax;
extern int o_structassign;
extern id o_stepbreak;
extern int o_stepnext;
# 45 "lex.lm"
extern id yylval;

int identif(void);
int keyw(int x);
int tkeyw(int x,id t);
int gnukeyw(int x);
int msdoskeyw(int x);
int watcomkeyw(int x);
int ibmvackeyw(int x);


int okblock;
# 1 "../../util//unistd.h"
#include <unistd.h>

# 1105 "lex.yy.c"
static int yy_init_globals(void);
# 1110 "lex.yy.c"
int yylex_destroy(void);

int yyget_debug(void);

void yyset_debug(int debug_flag);

void*yyget_extra(void);

void yyset_extra(void*user_defined);

FILE*yyget_in(void);

void yyset_in(FILE*_in_str);

FILE*yyget_out(void);

void yyset_out(FILE*_out_str);

yy_size_t yyget_leng(void);

char*yyget_text(void);

int yyget_lineno(void);

void yyset_lineno(int _line_number);
# 1144 "lex.yy.c"
extern int yywrap(void);
# 1150 "lex.yy.c"
static void yyunput(int c,char*buf_ptr);
# 1167 "lex.yy.c"
static int input(void);

# 22 "./../oclib/dasmstmt.h"
extern id  DosAsmStmt;

# 1274 "lex.yy.c"
int yylex_raw()
{
yy_state_type yy_current_state;
char*yy_cp,*yy_bp;
int yy_act;

if( !(yy_init))
{
(yy_init)=1;
# 1288 "lex.yy.c"
if( !(yy_start))
(yy_start)=1;

if( !yyin)
yyin=stdin;

if( !yyout)
yyout=stdout;

if( !((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){
yyensure_buffer_stack();
(yy_buffer_stack)[(yy_buffer_stack_top)]=
yy_create_buffer(yyin,16384);
}

yy_load_buffer_state();
}

{
# 1312 "lex.yy.c"
while(1)
{
yy_cp=(yy_c_buf_p); *


yy_cp=(yy_hold_char);
# 1322 "lex.yy.c"
yy_bp=yy_cp;

yy_current_state=(yy_start);
yy_match:
do
{
YY_CHAR yy_c=yy_ec[((unsigned int)(unsigned char) *yy_cp)];
if(yy_accept[yy_current_state])
{
(yy_last_accepting_state)=yy_current_state;
(yy_last_accepting_cpos)=yy_cp;
}
while(yy_chk[yy_base[yy_current_state]+yy_c]!=yy_current_state)
{
yy_current_state=(int)yy_def[yy_current_state];
if(yy_current_state>=747)
yy_c=yy_meta[(unsigned int)yy_c];
}
yy_current_state=yy_nxt[yy_base[yy_current_state]+(unsigned int)yy_c]; ++
yy_cp;
}
while(yy_base[yy_current_state]!=1318);

yy_find_action:
yy_act=yy_accept[yy_current_state];
if(yy_act==0)
{
yy_cp=(yy_last_accepting_cpos);
yy_current_state=(yy_last_accepting_state);
yy_act=yy_accept[yy_current_state];
}

(yytext)=yy_bp;yyleng=(size_t)(yy_cp-yy_bp);(yy_hold_char)= *yy_cp; *yy_cp='\0';(yy_c_buf_p)=yy_cp;;

do_action:

switch(yy_act)
{
case 0: *

yy_cp=(yy_hold_char);
yy_cp=(yy_last_accepting_cpos);
yy_current_state=(yy_last_accepting_state);
goto yy_find_action;

case 1:
# 93 "lex.lm"
{return keyw(262);}
break;
case 2:
# 94 "lex.lm"
{return keyw(261);}
break;
case 3:
# 95 "lex.lm"
{return keyw(277);}
break;
case 4:
# 96 "lex.lm"
{return keyw(275);}
break;
case 5:
# 97 "lex.lm"
{return keyw(261);}
break;
case 6:
# 98 "lex.lm"
{return keyw(261);}
break;
case 7:
# 99 "lex.lm"
{return keyw(261);}
break;
case 8:
# 100 "lex.lm"
{return keyw(278);}
break;
case 9:
# 101 "lex.lm"
{return keyw(276);}
break;
case 10:
# 102 "lex.lm"
{return keyw(272);}
break;
case 11:
# 103 "lex.lm"
{return keyw(261);}
break;
case 12:
# 104 "lex.lm"
{return keyw(270);}
break;
case 13:
# 105 "lex.lm"
{return keyw(267);}
break;
case 14:
# 106 "lex.lm"
{if(o_cplus)return keyw(265);}
break;
case 15:
# 107 "lex.lm"
{if(o_cplus)return keyw(265);}
break;
case 16:
# 108 "lex.lm"
{return keyw(262);}
break;
case 17:
# 109 "lex.lm"
{return keyw(261);}
break;
case 18:
# 110 "lex.lm"
{return keyw(273);}
break;
case 19:
# 111 "lex.lm"
{return keyw(280);}
break;
case 20:
# 112 "lex.lm"
{return keyw(269);}
break;
case 21:
# 113 "lex.lm"
{return keyw(261);}
break;
case 22:
# 114 "lex.lm"
{return keyw(261);}
break;
case 23:
# 115 "lex.lm"
{return keyw(261);}
break;
case 24:
# 116 "lex.lm"
{return keyw(262);}
break;
case 25:
# 117 "lex.lm"
{return keyw(279);}
break;
case 26:
# 118 "lex.lm"
{return keyw(261);}
break;
case 27:
# 119 "lex.lm"
{return keyw(282);}
break;
case 28:
# 120 "lex.lm"
{return keyw(262);}
break;
case 29:
# 121 "lex.lm"
{return keyw(268);}
break;
case 30:
# 122 "lex.lm"
{return keyw(274);}
break;
case 31:
# 123 "lex.lm"
{return keyw((o_duptypedefs)?263:262);}
break;
case 32:
# 124 "lex.lm"
{return keyw(268);}
break;
case 33:
# 125 "lex.lm"
{return keyw(261);}
break;
case 34:
# 126 "lex.lm"
{return keyw(261);}
break;
case 35:
# 127 "lex.lm"
{return keyw(271);}
break;
case 36:
# 129 "lex.lm"
{return(o_cplus)?keyw(261):identif();}
break;
case 37:
# 130 "lex.lm"
{return(o_cplus)?keyw(261):identif();}
break;
case 38:
# 131 "lex.lm"
{return(o_cplus)?keyw(261):identif();}
break;
case 39:
# 133 "lex.lm"
{return keyw(264);}
break;
case 40:
# 134 "lex.lm"
{return keyw(264);}
break;
case 41:
# 135 "lex.lm"
{return keyw(261);}
break;
case 42:
# 136 "lex.lm"
{return keyw(264);}
break;
case 43:
# 138 "lex.lm"
{return keyw(294);}
break;
case 44:
# 139 "lex.lm"
{return keyw(295);}
break;
case 45:
# 140 "lex.lm"
{return keyw(296);}
break;
case 46:
# 141 "lex.lm"
{return keyw(296);}
break;
case 47:
# 142 "lex.lm"
{return keyw(297);}
break;
case 48:
# 143 "lex.lm"
{return keyw(298);}
break;
case 49:
# 144 "lex.lm"
{return keyw(261);}
break;
case 50:
# 145 "lex.lm"
{return keyw(299);}
break;
case 51:
# 146 "lex.lm"
{warn("ignoring @public.");}
break;
case 52:
# 147 "lex.lm"
{warn("ignoring @protected.");}
break;
case 53:
# 148 "lex.lm"
{warn("ignoring @private.");}
break;
case 54:
# 150 "lex.lm"
{return keyw(262);}
break;
case 55:
# 152 "lex.lm"
{return(o_enableasm)?keyw(281):identif();}
break;
case 56:
# 153 "lex.lm"
{
id objcT0;

# 153 "lex.lm"
yylval=(objcT0=DosAsmStmt,(*(id(*)(id,SEL,STR))_imp(objcT0,selTransTbl[0]))(objcT0,selTransTbl[0],yytext));return 285;}
break;
case 57:
# 155 "lex.lm"
{
id objcT1;

# 155 "lex.lm"
yylval=(objcT1=DosAsmStmt,(*(id(*)(id,SEL,STR))_imp(objcT1,selTransTbl[0]))(objcT1,selTransTbl[0],yytext));return 285;}
break;
case 58:
# 157 "lex.lm"
{return gnukeyw(264);}
break;
case 59:
# 158 "lex.lm"
{return gnukeyw(264);}
break;
case 60:
# 159 "lex.lm"
{return gnukeyw(264);}
break;
case 61:
# 160 "lex.lm"
{return gnukeyw(264);}
break;
case 62:
# 161 "lex.lm"
{return gnukeyw(264);}
break;
case 63:
# 162 "lex.lm"
{return gnukeyw(264);}
break;
case 64:
# 163 "lex.lm"
{return gnukeyw(264);}
break;
case 65:
# 164 "lex.lm"
{return gnukeyw(261);}
break;
case 66:
# 165 "lex.lm"
{return gnukeyw(261);}
break;
case 67:
# 166 "lex.lm"
{return gnukeyw(261);}
break;
case 68:
# 167 "lex.lm"
{return gnukeyw(261);}
break;
case 69:
# 168 "lex.lm"
{return gnukeyw(302);}
break;
case 70:
# 169 "lex.lm"
{return keyw(281);}
break;
case 71:
# 170 "lex.lm"
{return keyw(281);}
break;
case 72:
# 171 "lex.lm"
{return keyw(262);}
break;
case 73:
# 172 "lex.lm"
{return keyw(262);}
break;
case 74:
# 173 "lex.lm"
{return keyw(262);}
break;
case 75:
# 174 "lex.lm"
{return gnukeyw(301);}
break;
case 76:
# 175 "lex.lm"
{return gnukeyw(283);}
break;
case 77:
# 176 "lex.lm"
{return gnukeyw(283);}
break;
case 78:
# 177 "lex.lm"
{return gnukeyw(264);}
break;
case 79:
# 178 "lex.lm"
{return gnukeyw(264);}
break;
case 80:
# 179 "lex.lm"
{return gnukeyw(264);}
break;
case 81:
# 180 "lex.lm"
{return gnukeyw(264);}
break;
case 82:
# 182 "lex.lm"
{return msdoskeyw(264);}
break;
case 83:
# 183 "lex.lm"
{return msdoskeyw(264);}
break;
case 84:
# 184 "lex.lm"
{return msdoskeyw(264);}
break;
case 85:
# 185 "lex.lm"
{return msdoskeyw(264);}
break;
case 86:
# 186 "lex.lm"
{return msdoskeyw(264);}
break;
case 87:
# 187 "lex.lm"
{return msdoskeyw(264);}
break;
case 88:
# 188 "lex.lm"
{return msdoskeyw(264);}
break;
case 89:
# 189 "lex.lm"
{return msdoskeyw(264);}
break;
case 90:
# 190 "lex.lm"
{return msdoskeyw(264);}
break;
case 91:
# 191 "lex.lm"
{return msdoskeyw(264);}
break;
case 92:
# 192 "lex.lm"
{return msdoskeyw(264);}
break;
case 93:
# 193 "lex.lm"
{return msdoskeyw(264);}
break;
case 94:
# 194 "lex.lm"
{return msdoskeyw(264);}
break;
case 95:
# 195 "lex.lm"
{return msdoskeyw(264);}
break;
case 96:
# 196 "lex.lm"
{return msdoskeyw(264);}
break;
case 97:
# 197 "lex.lm"
{return msdoskeyw(264);}
break;
case 98:
# 199 "lex.lm"
{

return(o_llkeyw)?keyw(261):identif();
}
break;
case 99:
# 204 "lex.lm"
{

return watcomkeyw(261);
}
break;
case 100:
# 208 "lex.lm"
{return watcomkeyw(264);}
break;
case 101:
# 209 "lex.lm"
{return watcomkeyw(264);}
break;
case 102:
# 210 "lex.lm"
{return watcomkeyw(264);}
break;
case 103:
# 211 "lex.lm"
{return watcomkeyw(264);}
break;
case 104:
# 212 "lex.lm"
{return watcomkeyw(264);}
break;
case 105:
# 213 "lex.lm"
{return watcomkeyw(264);}
break;
case 106:
# 214 "lex.lm"
{return watcomkeyw(264);}
break;
case 107:
# 215 "lex.lm"
{return watcomkeyw(264);}
break;
case 108:
# 216 "lex.lm"
{return watcomkeyw(264);}
break;
case 109:
# 217 "lex.lm"
{return watcomkeyw(264);}
break;
case 110:
# 218 "lex.lm"
{return watcomkeyw(264);}
break;
case 111:
# 219 "lex.lm"
{return watcomkeyw(264);}
break;
case 112:
# 220 "lex.lm"
{return watcomkeyw(264);}
break;
case 113:
# 221 "lex.lm"
{return watcomkeyw(264);}
break;
case 114:
# 222 "lex.lm"
{return watcomkeyw(264);}
break;
case 115:
# 224 "lex.lm"
{return ibmvackeyw(264);}
break;
case 116:
# 225 "lex.lm"
{return ibmvackeyw(264);}
break;
case 117:
# 226 "lex.lm"
{return ibmvackeyw(264);}
break;
case 118:
# 228 "lex.lm"
{
okblock=0;
return'(';
}
break;
case 119:
# 232 "lex.lm"
{return')';}
break;
case 120:
# 233 "lex.lm"
{return'[';}
break;
case 121:
# 234 "lex.lm"
{return']';}
break;
case 122:
# 235 "lex.lm"
{return keyw(293);}
break;
case 123:
# 236 "lex.lm"
{return'.';}
break;
case 124:
# 237 "lex.lm"
{return'!';}
break;
case 125:
# 238 "lex.lm"
{return'~';}
break;
case 126:
# 239 "lex.lm"
{return keyw(290);}
break;
case 127:
# 240 "lex.lm"
{return keyw(290);}
break;
case 128:
# 241 "lex.lm"
{return'*';}
break;
case 129:
# 242 "lex.lm"
{return'/';}
break;
case 130:
# 243 "lex.lm"
{return'%';}
break;
case 131:
# 244 "lex.lm"
{return'+';}
break;
case 132:
# 245 "lex.lm"
{return'-';}
break;
case 133:
# 246 "lex.lm"
{return keyw(289);}
break;
case 134:
# 247 "lex.lm"
{return keyw(289);}
break;
case 135:
# 248 "lex.lm"
{return keyw(288);}
break;
case 136:
# 249 "lex.lm"
{return keyw(288);}
break;
case 137:
# 250 "lex.lm"
{return keyw(288);}
break;
case 138:
# 251 "lex.lm"
{return keyw(288);}
break;
case 139:
# 252 "lex.lm"
{return keyw(287);}
break;
case 140:
# 253 "lex.lm"
{return keyw(288);}
break;
case 141:
# 254 "lex.lm"
{return'&';}
break;
case 142:
# 255 "lex.lm"
{return'^';}
break;
case 143:
# 256 "lex.lm"
{return'|';}
break;
case 144:
# 257 "lex.lm"
{return 291;}
break;
case 145:
# 258 "lex.lm"
{return 292;}
break;
case 146:
# 259 "lex.lm"
{return'?';}
break;
case 147:
# 260 "lex.lm"
{return':';}
break;
case 148:
# 261 "lex.lm"
{return'=';}
break;
case 149:
# 262 "lex.lm"
{return keyw(286);}
break;
case 150:
# 263 "lex.lm"
{return keyw(286);}
break;
case 151:
# 264 "lex.lm"
{return keyw(286);}
break;
case 152:
# 265 "lex.lm"
{return keyw(286);}
break;
case 153:
# 266 "lex.lm"
{return keyw(286);}
break;
case 154:
# 267 "lex.lm"
{return keyw(286);}
break;
case 155:
# 268 "lex.lm"
{return keyw(286);}
break;
case 156:
# 269 "lex.lm"
{return keyw(286);}
break;
case 157:
# 270 "lex.lm"
{return keyw(286);}
break;
case 158:
# 271 "lex.lm"
{return keyw(286);}
break;
case 159:
# 272 "lex.lm"
{return',';}
break;
case 160:
# 273 "lex.lm"
{return';';}
break;
case 161:
# 274 "lex.lm"
{return keyw((okblock)?(okblock=0,300):('{'));}
break;
case 162:
# 275 "lex.lm"
{return keyw('}');}
break;
case 163:
# 277 "lex.lm"
{return keyw(284);}
break;
case 164:
# 279 "lex.lm"
{return keyw(297);}
break;
case 165:
# 281 "lex.lm"
{;}
break;
case 166:
# 283 "lex.lm"
{inlineno++;}
break;
case 167:
# 285 "lex.lm"
{

yylval=mkcppdirect(yytext);
if(yylval){inlineno++;return 266;}
}
break;
case 168:
# 291 "lex.lm"
{
return tkeyw(259,t_str);
}
break;
case 169:
# 295 "lex.lm"
{

return tkeyw(259,t_str);
}
break;
case 170:
# 300 "lex.lm"
{
return(o_gnu)?tkeyw(259,t_str):identif();
}
break;
case 171:
# 304 "lex.lm"
{


return tkeyw(258,t_char);
}
break;
case 172:
# 310 "lex.lm"
{
return tkeyw(258,t_int);
}
break;
case 173:
# 314 "lex.lm"
{
return tkeyw(258,t_int);
}
break;
case 174:
# 318 "lex.lm"
{
return tkeyw(258,t_int);
}
break;
case 175:
# 322 "lex.lm"
{
return tkeyw(258,t_double);
}
break;
case 176:
# 326 "lex.lm"
{
return tkeyw(258,t_double);
}
break;
case 177:
# 330 "lex.lm"
{
return tkeyw(258,t_double);
}
break;
case 178:
# 334 "lex.lm"
{
return identif();
}
break;
case 179:
# 338 "lex.lm"
{;

}
break;
case 180:
# 342 "lex.lm"
{
if(o_warnlex){
char c=(yytext)[0];
warn("lex ignoring '0x%x' (%c)",(int)c,c);
}
}
break;
case 181:
# 349 "lex.lm"
do{if(fwrite(yytext,yyleng,1,yyout)){}}while(0);
break;
# 2324 "lex.yy.c"
case(182+0+1):
return 0;

case 182:
{

int yy_amount_of_matched_text=(int)(yy_cp-(yytext))-1; *


yy_cp=(yy_hold_char);


if((yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status==0)
{
# 2347 "lex.yy.c"
(yy_n_chars)=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars;
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_input_file=yyin;
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status=1;
}
# 2359 "lex.yy.c"
if((yy_c_buf_p)<= &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)])
{
yy_state_type yy_next_state;

(yy_c_buf_p)=(yytext)+yy_amount_of_matched_text;

yy_current_state=yy_get_previous_state();
# 2376 "lex.yy.c"
yy_next_state=yy_try_NUL_trans(yy_current_state);

yy_bp=(yytext)+0;

if(yy_next_state)
{

yy_cp= ++(yy_c_buf_p);
yy_current_state=yy_next_state;
goto yy_match;
}

else
{
yy_cp=(yy_c_buf_p);
goto yy_find_action;
}
}

else switch(yy_get_next_buffer())
{
case 1:
{
(yy_did_buffer_switch_on_eof)=0;

if(yywrap())
{
# 2412 "lex.yy.c"
(yy_c_buf_p)=(yytext)+0;

yy_act=(182+(((yy_start)-1)/2)+1);
goto do_action;
}

else
{
if( !(yy_did_buffer_switch_on_eof))
yyrestart(yyin);
}
break;
}

case 0:
(yy_c_buf_p)=
(yytext)+yy_amount_of_matched_text;

yy_current_state=yy_get_previous_state();

yy_cp=(yy_c_buf_p);
yy_bp=(yytext)+0;
goto yy_match;

case 2:
(yy_c_buf_p)= &
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)];

yy_current_state=yy_get_previous_state();

yy_cp=(yy_c_buf_p);
yy_bp=(yytext)+0;
goto yy_find_action;
}
break;
}

default:

yy_fatal_error("fatal flex scanner internal error--no action found");
}
}
}
}

# 2464 "lex.yy.c"
static int yy_get_next_buffer(void)
{
char*dest=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf;
char*source=(yytext);
yy_size_t number_to_move,i;
int ret_val;

if((yy_c_buf_p)> &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)+1])

yy_fatal_error("fatal flex scanner internal error--end of buffer missed");

if((yy_buffer_stack)[(yy_buffer_stack_top)]->yy_fill_buffer==0)
{
if((yy_c_buf_p)-(yytext)-0==1)
{
# 2482 "lex.yy.c"
return 1;
}

else
{
# 2490 "lex.yy.c"
return 2;
}
}
# 2497 "lex.yy.c"
number_to_move=(yy_size_t)((yy_c_buf_p)-(yytext))-1;

for(i=0;i<number_to_move; ++i) *
(dest++)= *(source++);

if((yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status==2)
# 2506 "lex.yy.c"
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars=(yy_n_chars)=0;

else
{
yy_size_t num_to_read=
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size-number_to_move-1;

while(num_to_read<=0)
{


YY_BUFFER_STATE b=(yy_buffer_stack)[(yy_buffer_stack_top)];

int yy_c_buf_p_offset=
(int)((yy_c_buf_p)-b->yy_ch_buf);

if(b->yy_is_our_buffer)
{
yy_size_t new_size=b->yy_buf_size*2;

if(new_size<=0)
b->yy_buf_size+=b->yy_buf_size/8;
else
b->yy_buf_size*=2;

b->yy_ch_buf=(char*)

yyrealloc((void*)b->yy_ch_buf,b->yy_buf_size+2);
}
else

b->yy_ch_buf=0;

if( !b->yy_ch_buf)

yy_fatal_error("fatal error - scanner input buffer overflow");

(yy_c_buf_p)= &b->yy_ch_buf[yy_c_buf_p_offset];

num_to_read=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size-
number_to_move-1;

}

if(num_to_read>8192)
num_to_read=8192;
# 2555 "lex.yy.c"
if((yy_buffer_stack)[(yy_buffer_stack_top)]->yy_is_interactive){int c='*';size_t n;for(n=0;n<num_to_read&&(c=getc(yyin))!=EOF&&c!='\n'; ++n)( &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[number_to_move])[n]=(char)c;if(c=='\n')( &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[number_to_move])[n++]=(char)c;if(c==EOF&&ferror(yyin))yy_fatal_error("input in flex scanner failed");(yy_n_chars)=n;}else{errno=0;while(((yy_n_chars)=fread(( &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[number_to_move]),1,num_to_read,yyin))==0&&ferror(yyin)){if(errno!=EINTR){yy_fatal_error("input in flex scanner failed");break;}errno=0;clearerr(yyin);}};

(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars=(yy_n_chars);
}

if((yy_n_chars)==0)
{
if(number_to_move==0)
{
ret_val=1;
yyrestart(yyin);
}

else
{
ret_val=2;
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buffer_status=
2;
}
}

else
ret_val=0;

if((yy_size_t)((yy_n_chars)+number_to_move)>(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size){

yy_size_t new_size=(yy_n_chars)+number_to_move+((yy_n_chars)>>1);
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf=(char*)yyrealloc((void*)(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf,new_size);
if( !(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf)
yy_fatal_error("out of dynamic memory in yy_get_next_buffer()");
}

(yy_n_chars)+=number_to_move;
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)]=0;
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)+1]=0;

(yytext)= &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[0];

return ret_val;
}



static yy_state_type yy_get_previous_state(void)
{
yy_state_type yy_current_state;
char*yy_cp;

yy_current_state=(yy_start);

for(yy_cp=(yytext)+0;yy_cp<(yy_c_buf_p); ++yy_cp)
{
YY_CHAR yy_c=( *yy_cp?yy_ec[((unsigned int)(unsigned char) *yy_cp)]:1);
if(yy_accept[yy_current_state])
{
(yy_last_accepting_state)=yy_current_state;
(yy_last_accepting_cpos)=yy_cp;
}
while(yy_chk[yy_base[yy_current_state]+yy_c]!=yy_current_state)
{
yy_current_state=(int)yy_def[yy_current_state];
if(yy_current_state>=747)
yy_c=yy_meta[(unsigned int)yy_c];
}
yy_current_state=yy_nxt[yy_base[yy_current_state]+(unsigned int)yy_c];
}

return yy_current_state;
}

# 2630 "lex.yy.c"
static yy_state_type yy_try_NUL_trans(yy_state_type yy_current_state)
{
int yy_is_jam;
char*yy_cp=(yy_c_buf_p);

YY_CHAR yy_c=1;
if(yy_accept[yy_current_state])
{
(yy_last_accepting_state)=yy_current_state;
(yy_last_accepting_cpos)=yy_cp;
}
while(yy_chk[yy_base[yy_current_state]+yy_c]!=yy_current_state)
{
yy_current_state=(int)yy_def[yy_current_state];
if(yy_current_state>=747)
yy_c=yy_meta[(unsigned int)yy_c];
}
yy_current_state=yy_nxt[yy_base[yy_current_state]+(unsigned int)yy_c];
yy_is_jam=(yy_current_state==746);

return yy_is_jam?0:yy_current_state;
}



static void yyunput(int c,char*yy_bp)
{
char*yy_cp;

yy_cp=(yy_c_buf_p); *


yy_cp=(yy_hold_char);

if(yy_cp<(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf+2)
{

yy_size_t number_to_move=(yy_n_chars)+2;
char*dest= &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size+2];
char*source= &
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[number_to_move];

while(source>(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf) * --
dest= * --source;

yy_cp+=(int)(dest-source);
yy_bp+=(int)(dest-source);
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars=
(yy_n_chars)=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_size;

if(yy_cp<(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf+2)
yy_fatal_error("flex scanner push-back overflow");
} * --

yy_cp=(char)c;

(yytext)=yy_bp;
(yy_hold_char)= *yy_cp;
(yy_c_buf_p)=yy_cp;
}

# 2698 "lex.yy.c"
static int input(void)


{
int c; *

(yy_c_buf_p)=(yy_hold_char);

if( *(yy_c_buf_p)==0)
{
# 2712 "lex.yy.c"
if((yy_c_buf_p)< &(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_ch_buf[(yy_n_chars)]) *

(yy_c_buf_p)='\0';

else
{
yy_size_t offset=(yy_c_buf_p)-(yytext); ++
(yy_c_buf_p);

switch(yy_get_next_buffer())
{
case 2:
# 2735 "lex.yy.c"
yyrestart(yyin);
# 2739 "lex.yy.c"
case 1:
{
if(yywrap())
return EOF;

if( !(yy_did_buffer_switch_on_eof))
yyrestart(yyin);
# 2749 "lex.yy.c"
return input();

}

case 0:
(yy_c_buf_p)=(yytext)+offset;
break;
}
}
}

c= *(unsigned char*)(yy_c_buf_p); *
(yy_c_buf_p)='\0';
(yy_hold_char)= * ++(yy_c_buf_p);

return c;
}

# 2773 "lex.yy.c"
void yyrestart(FILE*input_file)
{

if( !((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){
yyensure_buffer_stack();
(yy_buffer_stack)[(yy_buffer_stack_top)]=
yy_create_buffer(yyin,16384);
}

yy_init_buffer(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL),input_file);
yy_load_buffer_state();
}

# 2790 "lex.yy.c"
void yy_switch_to_buffer(YY_BUFFER_STATE new_buffer)
{
# 2798 "lex.yy.c"
yyensure_buffer_stack();
if(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)==new_buffer)
return;

if(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL))
{ *

(yy_c_buf_p)=(yy_hold_char);
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_pos=(yy_c_buf_p);
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars=(yy_n_chars);
}

(yy_buffer_stack)[(yy_buffer_stack_top)]=new_buffer;
yy_load_buffer_state();
# 2818 "lex.yy.c"
(yy_did_buffer_switch_on_eof)=1;
}

static void yy_load_buffer_state(void)
{
(yy_n_chars)=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars;
(yytext)=(yy_c_buf_p)=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_pos;
yyin=(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_input_file;
(yy_hold_char)= *(yy_c_buf_p);
}

# 2835 "lex.yy.c"
YY_BUFFER_STATE yy_create_buffer(FILE*file,int size)
{
YY_BUFFER_STATE b;

b=(YY_BUFFER_STATE)yyalloc(sizeof(struct yy_buffer_state));
if( !b)
yy_fatal_error("out of dynamic memory in yy_create_buffer()");

b->yy_buf_size=(yy_size_t)size;
# 2848 "lex.yy.c"
b->yy_ch_buf=(char*)yyalloc(b->yy_buf_size+2);
if( !b->yy_ch_buf)
yy_fatal_error("out of dynamic memory in yy_create_buffer()");

b->yy_is_our_buffer=1;

yy_init_buffer(b,file);

return b;
}

# 2863 "lex.yy.c"
void yy_delete_buffer(YY_BUFFER_STATE b)
{

if( !b)
return;

if(b==((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL))
(yy_buffer_stack)[(yy_buffer_stack_top)]=(YY_BUFFER_STATE)0;

if(b->yy_is_our_buffer)
yyfree((void*)b->yy_ch_buf);

yyfree((void*)b);
}

# 2882 "lex.yy.c"
static void yy_init_buffer(YY_BUFFER_STATE b,FILE*file)

{
int oerrno=errno;

yy_flush_buffer(b);

b->yy_input_file=file;
b->yy_fill_buffer=1;
# 2896 "lex.yy.c"
if(b!=((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){
b->yy_bs_lineno=1;
b->yy_bs_column=0;
}

b->yy_is_interactive=file?(isatty(fileno(file))>0):0;

errno=oerrno;
}

# 2910 "lex.yy.c"
void yy_flush_buffer(YY_BUFFER_STATE b)
{
if( !b)
return;

b->yy_n_chars=0;
# 2921 "lex.yy.c"
b->yy_ch_buf[0]=0;
b->yy_ch_buf[1]=0;

b->yy_buf_pos= &b->yy_ch_buf[0];

b->yy_at_bol=1;
b->yy_buffer_status=0;

if(b==((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL))
yy_load_buffer_state();
}

# 2939 "lex.yy.c"
void yypush_buffer_state(YY_BUFFER_STATE new_buffer)
{
if(new_buffer==NULL)
return;

yyensure_buffer_stack();


if(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL))
{ *

(yy_c_buf_p)=(yy_hold_char);
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_buf_pos=(yy_c_buf_p);
(yy_buffer_stack)[(yy_buffer_stack_top)]->yy_n_chars=(yy_n_chars);
}


if(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL))
(yy_buffer_stack_top)++;
(yy_buffer_stack)[(yy_buffer_stack_top)]=new_buffer;


yy_load_buffer_state();
(yy_did_buffer_switch_on_eof)=1;
}

# 2969 "lex.yy.c"
void yypop_buffer_state(void)
{
if( !((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL))
return;

yy_delete_buffer(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL));
(yy_buffer_stack)[(yy_buffer_stack_top)]=NULL;
if((yy_buffer_stack_top)>0) --
(yy_buffer_stack_top);

if(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){
yy_load_buffer_state();
(yy_did_buffer_switch_on_eof)=1;
}
}

# 2988 "lex.yy.c"
static void yyensure_buffer_stack(void)
{
yy_size_t num_to_alloc;

if( !(yy_buffer_stack)){
# 2998 "lex.yy.c"
num_to_alloc=1;
(yy_buffer_stack)=(struct yy_buffer_state**)yyalloc(
num_to_alloc*sizeof(struct yy_buffer_state*));

if( !(yy_buffer_stack))
yy_fatal_error("out of dynamic memory in yyensure_buffer_stack()");

memset((yy_buffer_stack),0,num_to_alloc*sizeof(struct yy_buffer_state*));

(yy_buffer_stack_max)=num_to_alloc;
(yy_buffer_stack_top)=0;
return;
}

if((yy_buffer_stack_top)>=((yy_buffer_stack_max))-1){


yy_size_t grow_size=8;

num_to_alloc=(yy_buffer_stack_max)+grow_size;
(yy_buffer_stack)=(struct yy_buffer_state**)yyrealloc(
(yy_buffer_stack),
num_to_alloc*sizeof(struct yy_buffer_state*));

if( !(yy_buffer_stack))
yy_fatal_error("out of dynamic memory in yyensure_buffer_stack()");


memset((yy_buffer_stack)+(yy_buffer_stack_max),0,grow_size*sizeof(struct yy_buffer_state*));
(yy_buffer_stack_max)=num_to_alloc;
}
}

# 3037 "lex.yy.c"
YY_BUFFER_STATE yy_scan_buffer(char*base,yy_size_t size)
{
YY_BUFFER_STATE b;

if(size<2||
base[size-2]!=0||
base[size-1]!=0)

return 0;

b=(YY_BUFFER_STATE)yyalloc(sizeof(struct yy_buffer_state));
if( !b)
yy_fatal_error("out of dynamic memory in yy_scan_buffer()");

b->yy_buf_size=size-2;
b->yy_buf_pos=b->yy_ch_buf=base;
b->yy_is_our_buffer=0;
b->yy_input_file=0;
b->yy_n_chars=b->yy_buf_size;
b->yy_is_interactive=0;
b->yy_at_bol=1;
b->yy_fill_buffer=0;
b->yy_buffer_status=0;

yy_switch_to_buffer(b);

return b;
}

# 3074 "lex.yy.c"
YY_BUFFER_STATE yy_scan_string(char*yystr)
{

return yy_scan_bytes(yystr,strlen(yystr));
}

# 3087 "lex.yy.c"
YY_BUFFER_STATE yy_scan_bytes(char*yybytes,yy_size_t _yybytes_len)
{
YY_BUFFER_STATE b;
char*buf;
yy_size_t n;
yy_size_t i;


n=_yybytes_len+2;
buf=(char*)yyalloc(n);
if( !buf)
yy_fatal_error("out of dynamic memory in yy_scan_bytes()");

for(i=0;i<_yybytes_len; ++i)
buf[i]=yybytes[i];

buf[_yybytes_len]=buf[_yybytes_len+1]=0;

b=yy_scan_buffer(buf,n);
if( !b)
yy_fatal_error("bad buffer in yy_scan_bytes()");
# 3112 "lex.yy.c"
b->yy_is_our_buffer=1;

return b;
}

# 3121 "lex.yy.c"
static void yy_fatal_error(char*msg)
{
(void)fprintf(stderr,"%s\n",msg);
exit(2);
}

# 3149 "lex.yy.c"
int yyget_lineno(void)
{

return yylineno;
}

# 3158 "lex.yy.c"
FILE*yyget_in(void)
{
return yyin;
}

# 3166 "lex.yy.c"
FILE*yyget_out(void)
{
return yyout;
}

# 3174 "lex.yy.c"
yy_size_t yyget_leng(void)
{
return yyleng;
}

# 3183 "lex.yy.c"
char*yyget_text(void)
{
return yytext;
}

# 3192 "lex.yy.c"
void yyset_lineno(int _line_number)
{

yylineno=_line_number;
}

# 3204 "lex.yy.c"
void yyset_in(FILE*_in_str)
{
yyin=_in_str;
}

void yyset_out(FILE*_out_str)
{
yyout=_out_str;
}

int yyget_debug(void)
{
return yy_flex_debug;
}

void yyset_debug(int _bdebug)
{
yy_flex_debug=_bdebug;
}

static int yy_init_globals(void)
{
# 3230 "lex.yy.c"
(yy_buffer_stack)=0;
(yy_buffer_stack_top)=0;
(yy_buffer_stack_max)=0;
(yy_c_buf_p)=(char*)0;
(yy_init)=0;
(yy_start)=0;
# 3242 "lex.yy.c"
yyin=(FILE*)0;
yyout=(FILE*)0;
# 3249 "lex.yy.c"
return 0;
}


int yylex_destroy(void)
{


while(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL)){
yy_delete_buffer(((yy_buffer_stack)?(yy_buffer_stack)[(yy_buffer_stack_top)]:NULL));
(yy_buffer_stack)[(yy_buffer_stack_top)]=NULL;
yypop_buffer_state();
}


yyfree((yy_buffer_stack));
(yy_buffer_stack)=NULL;
# 3269 "lex.yy.c"
yy_init_globals();

return 0;
}

# 3299 "lex.yy.c"
void*yyalloc(yy_size_t size)
{
return(void*)malloc(size);
}

void*yyrealloc(void*ptr,yy_size_t size)
{
# 3314 "lex.yy.c"
return(void*)realloc((char*)ptr,size);
}

void yyfree(void*ptr)
{
free((char*)ptr);
}

# 357 "lex.lm"
void yyerror(char*str)
{
fatal("%s \"%s\"",str,yytext);
}

# 365 "lex.lm"
int yywrap(){return 1;}

# 59 "./../oclib/symbol.h"
extern id  Symbol;

# 368 "lex.lm"
int identif(void)
{
id objcT2;

# 370 "lex.lm"
yylval=(objcT2=Symbol,(*(id(*)(id,SEL,char*,int,id))_imp(objcT2,selTransTbl[1]))(objcT2,selTransTbl[1],yytext,inlineno,infilename));
if( !o_duptypedefs){
if(isbuiltinfun(yylval))return 260;
if(istypeword(yylval))return 261;
}
return 257;
}

# 22 "./../oclib/stclass.h"
extern id  Storageclass;

# 378 "lex.lm"
int keyw(int x)
{
if(x==262||x==263||x==265||x==301){
id objcT3;

# 381 "lex.lm"
yylval=(objcT3=Storageclass,(*(id(*)(id,SEL,char*,int,id))_imp(objcT3,selTransTbl[1]))(objcT3,selTransTbl[1],yytext,inlineno,infilename));
}else{
id objcT4;

# 383 "lex.lm"
yylval=(objcT4=Symbol,(*(id(*)(id,SEL,char*,int,id))_imp(objcT4,selTransTbl[1]))(objcT4,selTransTbl[1],yytext,inlineno,infilename));
}
return x;
}

int tkeyw(int x,id t)
{
id objcT5,objcT6;

# 390 "lex.lm"
yylval=(objcT5=Symbol,(*(id(*)(id,SEL,char*,int,id))_imp(objcT5,selTransTbl[1]))(objcT5,selTransTbl[1],yytext,inlineno,infilename));
(objcT6=yylval,(*_imp(objcT6,selTransTbl[2]))(objcT6,selTransTbl[2],t));
return x;
}

int gnukeyw(int x)
{
return(o_gnu)?keyw(x):identif();
}

int msdoskeyw(int x)
{
return(o_msdos)?keyw(x):identif();
}

int watcomkeyw(int x)
{
return(o_watcom)?keyw(x):identif();
}

int ibmvackeyw(int x)
{
return(o_ibmvac)?keyw(x):identif();
}
static char *_selTransTbl[] ={
"str:",
"str:lineno:filename:",
"type:",
0
};
struct modDescriptor lex_modDesc = {
  "lex",
  "objc3.3.19",
  0L,
  0,
  0,
  0,
  3,
  _selTransTbl,
  0
};
struct modDescriptor *_OBJCBIND_lex(void)
{
  selTransTbl = _selTransTbl;
  return &lex_modDesc;
}
int _OBJCPOSTLINK_lex = 1;


