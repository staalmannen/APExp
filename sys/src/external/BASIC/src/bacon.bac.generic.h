/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <libgen.h>
#include <limits.h>
#include <float.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/utsname.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <setjmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <regex.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>
#include <dlfcn.h>
#include <errno.h>
#include <termios.h>
#include <time.h>
#include <fts.h>
#define ENTRY ENTRY_libc
#include <search.h>
#undef ENTRY
/* Undefine all symbols which happen to be BaCon keywords */
#undef ABS
#undef ACCEPT
#undef ACOS
#undef ADD
#undef ADDRESS
#undef ALARM
#undef ALIAS
#undef AMOUNT
#undef AND
#undef APPEND
#undef APPENDING
#undef ARRAY
#undef AS
#undef ASC
#undef ASIN
#undef ASSOC
#undef ATN
#undef ATN2
#undef BACK
#undef BAPPEND
#undef BASE
#undef BETWEEN
#undef BEYOND
#undef BG
#undef BIT
#undef BLACK
#undef BLINK
#undef BLOAD
#undef BLUE
#undef BOLD
#undef BREAK
#undef BROADCAST
#undef BSAVE
#undef BY
#undef BYTELEN
#undef CALL
#undef CASE
#undef CATCH
#undef CEIL
#undef CERTIFICATE
#undef CHANGEDIR
#undef CHUNK
#undef CLASS
#undef CLEAR
#undef CLOSE
#undef CMDLINE
#undef CMODE
#undef COLLAPSE
#undef COLLECT
#undef COLOR
#undef COLUMNS
#undef COMPARE
#undef COMPILER
#undef CONST
#undef CONTINUE
#undef COPY
#undef COS
#undef COUNT
#undef CURRENT
#undef CURSOR
#undef CYAN
#undef DATA
#undef DAY
#undef DEC
#undef DECLARE
#undef DECR
#undef DEF
#undef DEFAULT
#undef DEG
#undef DELETE
#undef DELIM
#undef DEVICE
#undef DIRECTORY
#undef DO
#undef DONE
#undef DOTIMES
#undef DOWN
#undef DOWNTO
#undef DQ
#undef ELIF
#undef ELSE
#undef END
#undef ENDCLASS
#undef ENDENUM
#undef ENDFILE
#undef ENDFORK
#undef ENDFUNC
#undef ENDFUNCTION
#undef ENDIF
#undef ENDRECORD
#undef ENDSELECT
#undef ENDSUB
#undef ENDUSEC
#undef ENDUSEH
#undef ENDWITH
#undef ENUM
#undef EPRINT
#undef EQ
#undef EQUAL
#undef ERROR
#undef ESC
#undef EVAL
#undef EVEN
#undef EXCL
#undef EXIT
#undef EXP
#undef EXPLICIT
#undef FALSE
#undef FG
#undef FI
#undef FILE
#undef FILEEXISTS
#undef FILELEN
#undef FILETIME
#undef FILETYPE
#undef FIND
#undef FLOATING
#undef FLOOR
#undef FN
#undef FOR
#undef FORK
#undef FORMAT
#undef FORWARD
#undef FP
#undef FRAMEWORK
#undef FREE
#undef FROM
#undef FTYPE
#undef FUNC
#undef FUNCTION
#undef GE
#undef GETBYTE
#undef GETFILE
#undef GETKEY
#undef GETLINE
#undef GETX
#undef GETY
#undef GLOBAL
#undef GOSUB
#undef GOTO
#undef GOTOXY
#undef GREEN
#undef GT
#undef GUI
#undef HASBOM
#undef HASDELIM
#undef HASH
#undef HOUR
#undef IF
#undef IIF
#undef IMODE
#undef IMPORT
#undef IN
#undef INCLUDE
#undef INCR
#undef INDEX
#undef INPUT
#undef INSTR
#undef INSTRREV
#undef INT
#undef INTENSE
#undef INTERNATIONAL
#undef INVERSE
#undef INVERT
#undef IS
#undef ISASCII
#undef ISFALSE
#undef ISKEY
#undef ISNOT
#undef ISTOKEN
#undef ISTRUE
#undef ISUTF8
#undef ITALIC
#undef JOIN
#undef LABEL
#undef LDFLAGS
#undef LE
#undef LEN
#undef LET
#undef LIBRARY
#undef LINENO
#undef LMODE
#undef LOCAL
#undef LOG
#undef LOOKUP
#undef LOOP
#undef LT
#undef MAGENTA
#undef MAKEDIR
#undef MAP
#undef MATCH
#undef MAX
#undef MAXNUM
#undef MAXRANDOM
#undef MEMCHECK
#undef MEMORY
#undef MEMREWIND
#undef MEMSTREAM
#undef MEMTELL
#undef MEMTYPE
#undef MIN
#undef MINUTE
#undef MOD
#undef MONITOR
#undef MONTH
#undef MULTICAST
#undef MYPID
#undef NANOTIMER
#undef NE
#undef NETWORK
#undef NEXT
#undef NO_C_ESC
#undef NODE
#undef NORMAL
#undef NOT
#undef NOW
#undef NRKEYS
#undef NUMBER
#undef ODD
#undef OFF
#undef OFFSET
#undef OMODE
#undef ON
#undef OPEN
#undef OPTION
#undef OPTIONS
#undef OR
#undef OTHER
#undef PARSE
#undef PEEK
#undef PI
#undef POKE
#undef POW
#undef PRAGMA
#undef PRINT
#undef PRIORITY
#undef PROPER
#undef PROTO
#undef PULL
#undef PUSH
#undef PUTBYTE
#undef PUTLINE
#undef QUOTED
#undef RAD
#undef RANDOM
#undef RE
#undef READ
#undef READING
#undef READLN
#undef READWRITE
#undef REAP
#undef RECEIVE
#undef RECORD
#undef RECURSIVE
#undef RED
#undef REDIM
#undef REGEX
#undef REGLEN
#undef RELATE
#undef REM
#undef RENAME
#undef REPEAT
#undef RESET
#undef RESIZE
#undef RESTORE
#undef RESUME
#undef RETURN
#undef RETVAL
#undef REWIND
#undef RND
#undef ROL
#undef ROR
#undef ROUND
#undef ROWS
#undef RUN
#undef SAVE
#undef SCREEN
#undef SCROLL
#undef SCTP
#undef SEARCH
#undef SECOND
#undef SEED
#undef SEEK
#undef SELECT
#undef SEND
#undef SERVER
#undef SET
#undef SETENVIRON
#undef SETSERIAL
#undef SGN
#undef SIGNAL
#undef SIN
#undef SIZE
#undef SIZEOF
#undef SLEEP
#undef SOCKET
#undef SORT
#undef SP
#undef SPEED
#undef SPLIT
#undef SQR
#undef START
#undef STARTPOINT
#undef STATIC
#undef STEP
#undef STOP
#undef STRIKE
#undef STRING
#undef SUB
#undef SUM
#undef SUMF
#undef SWAP
#undef SYSTEM
#undef TALLY
#undef TAN
#undef TCP
#undef TELL
#undef TEXTDOMAIN
#undef THEN
#undef TIMER
#undef TIMEVALUE
#undef TLS
#undef TO
#undef TOTAL
#undef TRACE
#undef TRAP
#undef TREE
#undef TRUE
#undef TYPE
#undef UBOUND
#undef UCS
#undef UDP
#undef ULEN
#undef UNDERLINE
#undef UNSET
#undef UNTIL
#undef UP
#undef USEC
#undef USEH
#undef UTF8
#undef VAL
#undef VAR
#undef VARTYPE
#undef VERIFY
#undef WAIT
#undef WEEK
#undef WEND
#undef WHENCE
#undef WHERE
#undef WHILE
#undef WHITE
#undef WITH
#undef WRITELN
#undef WRITING
#undef YEAR
#undef YELLOW
/* Declarations for internal variables */
jmp_buf b2c_jump = { 0 };
int b2c_trap = 1;
int b2c_catch_set_backup = 0, b2c_catch_set = 0;
void (*b2c_error_callback)(char*, char*, long) = NULL;
int b2c_option_compare = 0;
int b2c_option_quoted = 1;
int b2c_option_dq = 34;
int b2c_option_esc = 92;
int b2c_option_utf8 = 0;
int b2c_option_proper = 0;
int b2c_option_tls = 0;
char *b2c_option_delim = " ";
int b2c_option_memstream = 0;
int b2c_option_startpoint = 0;
int b2c_option_open = O_RDWR|O_NOCTTY|O_SYNC;
int b2c_collapse = 0;
int b2c_break_ctr = 0;
int b2c_break_flag = 0;
char b2c_chop_default[] = "\r\n\t\f\v ";
int b2c_stringarray_ptr = 0;
int b2c_floatarray_ptr = 0;
long b2c_ctr = 0;
#define __b2c_STRING_FUNC (9)
#define __b2c_EMPTYSTRING (char*)""
jmp_buf b2c_gosub_buffer[64];
int b2c_gosub_buffer_ptr = -1;
char* b2c_loop_result = NULL;
long b2c_loop_result = 0;
jmp_buf b2c_data_jump, b2c_loop1, b2c_loop2;
char *b2c_assign = NULL;
void **b2c_assign2 = NULL;
int b2c_counter = 0;
char **b2c_stack = NULL;
void **b2c_twalk_array = NULL; int b2c_twalk_idx = 0;
extern char *b2c_stringarray[];
extern double b2c_floatarray[];
char *b2c_me_var = NULL;
/* Declarations for BaCon variables */
char *ARGUMENT = NULL;
int ERROR = 0;
int RETVAL = 0;
int REGLEN = 0;
int SP = 0;
long _ = 0;
char VERSION[] = "5.0.3";
/* Prototypes for internal functions */
int b2c_strcmp(const char*, const char*);
char *b2c_strdup(char*);
char *b2c_strndup(char*, size_t);
void *__b2c_mempool_realloc_core(void*, size_t, int);
void *__b2c_str_realloc_core(char*, size_t, int);
long b2c_delim_engine_core(int, int, long*, char*, char*, long, int);
/* Prototypes for BaCon functions */
char *ERR(int);
int __b2c_utf8_conv(int,char*);
char *__b2c_Copy_String_core(char*, char*, int);
char* __b2c_Swap_String(char**, char**);
unsigned long b2c_len(const char*);
unsigned long b2c_ulen(int,char*,char*,char*,int);
unsigned long b2c_blen(int,char*,char*,char*,long,int);
unsigned long b2c_ucs2_clen(int,char*,char*,char*,int);
long b2c_regex_core(int, int, char*, char*, char*);
char *b2c_extract_core(int, int, char*, char*, char*, int);
char *b2c_replace_core(int, int, char*, char*, char*, char*, int);
char *b2c_walk_core(int, int, char*, char*, int, char*, int, char*);
void __b2c_str_free(void);
void s_free(void);
void b2c_twalk_free(void);
int b2c_collect(void*, void***, int, int);
/* Internal macro definitions */
#define __b2c__MEMTYPE char
#define __b2c__STRCMP b2c_strcmp
#define __b2c__BUFOFFSET 16
#define __b2c__LBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+8))
#define __b2c__RBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+4))
#define __b2c__STRFREE(x) if(__b2c_str_realloc_get_string(x)) { if(!__b2c_mempool_realloc_free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x))) { free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x)); } __b2c_str_realloc_del_string(x); } else { if(x) { free(x); } }
#define __b2c__SETLEN(x,y) *(uint32_t*)(x-__b2c__BUFOFFSET) = y;
#define __b2c__FUNCSELECT2(_1, _2, x, ...) x
#define __b2c__FUNCSELECT3(_1, _2, _3, x, ...) x
#define __b2c__FUNCSELECT4(_1, _2, _3, _4, x, ...) x
#define __b2c__FUNCSELECT5(_1, _2, _3, _4, _5, x, ...) x
#define __b2c_mempool_realloc_debug() __b2c_mempool_realloc_core(NULL, 0, 0)
#define __b2c_mempool_realloc_free(x) __b2c_mempool_realloc_core(x, 0, 1)
#define __b2c_mempool_realloc_in_block(x) __b2c_mempool_realloc_core(x, 0, 2)
#define __b2c_mempool_realloc(x, y) __b2c_mempool_realloc_core(x, y, 3)
#define __b2c_str_realloc(x, y) __b2c_str_realloc_core(x, y, 0)
#define __b2c_str_realloc_left(x, y) __b2c_str_realloc_core(x, y, 1)
#define __b2c_str_realloc_add_string(x) __b2c_str_realloc_core((char*)x, 0, 2)
#define __b2c_str_realloc_del_string(x) __b2c_str_realloc_core((char*)x, 0, 3)
#define __b2c_str_realloc_get_string(x) (x!=NULL && __b2c_str_realloc_core((char*)x, 0, 4))
#define __b2c_str_realloc_free_string() __b2c_str_realloc_core(NULL, 0, 6)
#define __b2c_str_realloc_debug_string() __b2c_str_realloc_core(NULL, 0, 5)
#define b2c_CopyString(x, y) __b2c_Copy_String_core(x, y, -1)
#define __b2c_Copy_N_String(x, y, z) __b2c_Copy_String_core(x, y, z)
#define b2c_delim_engine(x, y, z, a, b) b2c_delim_engine_core(1, x, y, z, a, b, 0)
#define b2c_delim_engine_cache(x, y, z, a, b) b2c_delim_engine_core(1, x, y, z, a, b, 1)
#define b2c_delim_engine_free() b2c_delim_engine_core(0, 0, NULL, NULL, NULL, 0, 0)
#define b2c_regex(x, y, z, q) b2c_regex_core(1, x, y, z, q)
#define b2c_regex_free() b2c_regex_core(0, 0, NULL, NULL, NULL)
#define b2c_extract(x, y, z, q, r) b2c_extract_core(1, x, y, z, q, r)
#define b2c_extract_free() b2c_extract_core(0, 0, NULL, NULL, NULL, 0)
#define b2c_replace(x, y, z, q, r, s) b2c_replace_core(1, x, y, z, q, r, s)
#define b2c_replace_free() b2c_replace_core(0, 0, NULL, NULL, NULL, NULL, 0)
#define b2c_walk(x, y, z, a, b, c, d) b2c_walk_core(1, x, y, z, a, b, c, d)
#define b2c_walk_free() b2c_walk_core(0, 0, NULL, NULL, 0, NULL, 0, NULL)
#if INTPTR_MAX == INT64_MAX
#define HASH_FUNC (uint64_t)__b2c__HashFNV1a_64
#elif INTPTR_MAX == INT32_MAX
#define HASH_FUNC (uint32_t)__b2c__HashFNV1a_32
#else
#define HASH_FUNC (uint16_t)__b2c__HashFNV1a_16_new
#endif
#define COMPILED_BY_WHICH_BACON "Shell Script BaCon 5.0.3 in BASH 5.3.0(1)-release"
#define RUNTIMEERROR(a, x, y, z, q) do { if(!b2c_catch_set) { if(b2c_trap) { fprintf(stderr, "Runtime error: statement '%s' at line %d in '%s': %s\n", a, x, y, ERR(z)); exit(z); } if(b2c_error_callback){ (*b2c_error_callback)(a,y,x); } } else { if(!setjmp(b2c_jump)) { goto q; } } } while(0)
#define RUNTIMEFERR(a, x, y, z) do { if(b2c_trap) { fprintf(stderr, "Runtime error: function '%s' at line %d in '%s': %s\n", a, z, y, ERR(x)); exit(x); } if(b2c_error_callback){ (*b2c_error_callback)(a,y,z); } } while(0)
#define RUNTIMEDEBUG(x, y, z) (b2c_getch() == 27 ? fprintf(stderr, "TRACE OFF - exiting trace mode.\n") && b2c_stop_program() : fprintf(stderr, "File '%s' line %d: %s\n", #x, y, z) )
int b2c_stop_program(void) { exit(EXIT_SUCCESS); return(1); }
/* BaCon functions */
#define ABS(x) fabs((double)x)
#define ACOS(x) acos((double)x)
#define ADDRESS(x) (uintptr_t)(&x)
#define __b2c__ALIGN3(x, y, z) b2c_align(__LINE__, __FILE__, x, y, z, 0)
#define __b2c__ALIGN4(x, y, z, f) b2c_align(__LINE__, __FILE__, x, y, z, f)
#define ALIGN(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__ALIGN4, __b2c__ALIGN3)(__VA_ARGS__)
#define __b2c__AMOUNT1(x) b2c_amount(x, NULL)
#define __b2c__AMOUNT2(x, y) b2c_amount(x, y)
#define AMOUNT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__AMOUNT2, __b2c__AMOUNT1)(__VA_ARGS__)
#define AND &&
#define __b2c__APPEND3(x, y, z) b2c_append(NULL, 0, x, y, z, NULL)
#define __b2c__APPEND4(x, y, z, f) b2c_append(NULL, 0, x, y, z, f)
#define APPEND(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__APPEND4, __b2c__APPEND3)(__VA_ARGS__)
#define __b2c__FAPPEND4(s, x, y, z) b2c_append(&s, 1, x, y, z, NULL)
#define __b2c__FAPPEND5(s, x, y, z, f) b2c_append(&s, 1, x, y, z, f)
#define F_APPEND(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__FAPPEND5, __b2c__FAPPEND4)(__VA_ARGS__)
#define ASC(x) b2c_asc(x)
#define ASIN(x) asin((double)(x))
#define ATN(x) atan((double)(x))
#define ATN2(x,y) atan2((double)(x),(double)(y))
#define B64DEC(x) b2c_b64dec(__LINE__, __FILE__, x)
#define __b2c__B64ENC1(x) b2c_b64enc(x, 0)
#define __b2c__B64ENC2(x, y) b2c_b64enc((char*)x, y)
#define B64ENC(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__B64ENC2, __b2c__B64ENC1)(__VA_ARGS__)
#define __b2c__BASENAME1(x) b2c_dirname(__LINE__, __FILE__, 1, x, 0)
#define __b2c__BASENAME2(x, y) b2c_dirname(__LINE__, __FILE__, 1, x, y)
#define BASENAME(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__BASENAME2, __b2c__BASENAME1)(__VA_ARGS__)
#define BIN(x) b2c_bin(sizeof(__b2c__MEMTYPE), x)
#define BIT(x) b2c_bit(x)
#define BLOAD(x) (void*)b2c_load(1, __LINE__, __FILE__, x)
#define __b2c__BYTELEN2(x, y) b2c_blen(__LINE__, __FILE__, "BYTELEN", x, y, 0)
#define __b2c__BYTELEN3(x, y, z) b2c_blen(__LINE__, __FILE__, "BYTELEN", x, y, z)
#define BYTELEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__BYTELEN3, __b2c__BYTELEN2)(__VA_ARGS__)
#define CA(x) b2c_ca(__LINE__, __FILE__, x)
#define CN(x) b2c_cn(__LINE__, __FILE__, x)
#define CIPHER(x) b2c_cipher(__LINE__, __FILE__, x)
#define VERIFY(x, y) ((SSL*)x == NULL ? -1 : (long)SSL_get_verify_result((SSL*)x) )
#define ACCEPT(x) b2c_accept(__LINE__, __FILE__, b2c_caprivate, b2c_caserver, x)
#define CEIL(x) (double)ceil(x)
#define __b2c__CHANGE3(x, y, z) b2c_change(x, y, z, NULL)
#define __b2c__CHANGE4(x, y, z, f) b2c_change(x, y, z, f)
#define CHANGE(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CHANGE4, __b2c__CHANGE3)(__VA_ARGS__)
#define __b2c__CHOP1(x) b2c_chop(NULL, 0, x, NULL, 0)
#define __b2c__CHOP2(x, y) b2c_chop(NULL, 0, x, y, 0)
#define __b2c__CHOP3(x, y, z) b2c_chop(NULL, 0, x, y, z)
#define CHOP(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__CHOP3, __b2c__CHOP2, __b2c__CHOP1)(__VA_ARGS__)
#define __b2c__FCHOP2(s, x) b2c_chop(&s, 1, x, NULL, 0)
#define __b2c__FCHOP3(s, x, y) b2c_chop(&s, 1, x, y, 0)
#define __b2c__FCHOP4(s, x, y, z) b2c_chop(&s, 1, x, y, z)
#define F_CHOP(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FCHOP4, __b2c__FCHOP3, __b2c__FCHOP2)(__VA_ARGS__)
#define CHR(x) b2c_asc2char(x)
#define UTF8(x) b2c_asc2utf8(x)
#define CL "\033[2K"
#define CMDLINE(x) b2c_getopt(argc, argv, x)
#define COIL(...) ( !setjmp(b2c_loop1) ? b2c_loop_helper(b2c_loop2) : b2c_loop_result )
#define __b2c__COLLAPSE1(x) b2c_collapse_func(x, NULL)
#define __b2c__COLLAPSE2(x, y) b2c_collapse_func(x, y)
#define COLLAPSE(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__COLLAPSE2, __b2c__COLLAPSE1)(__VA_ARGS__)
#define COLUMNS b2c_screen(0)
#define CONCAT(...) b2c_concat(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)
#define F_CONCAT(...) b2c_concat2(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)
#define COS(x) cos((double)(x))
#define COUNT(x, y) b2c_count(__LINE__, __FILE__, x, y)
#define CR "\r"
#define CURDIR b2c_curdir()
#define __b2c__CUT3(x, y, z) b2c_cut(x, y, z, NULL)
#define __b2c__CUT4(x, y, z, f) b2c_cut(x, y, z, f)
#define CUT(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CUT4, __b2c__CUT3)(__VA_ARGS__)
#define DAY(x) b2c_time(x, 1)
#define __b2c__DEC1(x) b2c_hex2dec(__LINE__, __FILE__, x, 0)
#define __b2c__DEC2(x, y) b2c_hex2dec(__LINE__, __FILE__, x, y)
#define DEC(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__DEC2, __b2c__DEC1)(__VA_ARGS__)
#define DEG(x) (x*180/PI)
#define __b2c__DEL2(x, y) b2c_del(x, y, NULL)
#define __b2c__DEL3(x, y, z) b2c_del(x, y, z)
#define DEL(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__DEL3, __b2c__DEL2)(__VA_ARGS__)
#define DELIM(x, y, z) b2c_delim(x, y, z)
#define DIRNAME(x) b2c_dirname(__LINE__, __FILE__, 2, x, 0)
#define DLE "\r\n"
#define EDITBOM(x, y) b2c_editbom(x, y)
#define EL "\033[0K"
#define ENDFILE(x) feof(x)
#define EQ ==
#define EQUAL(x, y) !__b2c__STRCMP(x, y)
#define ESCAPE(x) b2c_escape(__LINE__, __FILE__, x)
#define EVAL(x, y, z, q) b2c_eval(__LINE__, __FILE__, x, y, z, q)
#define EVEN(x) (((long)(x) % 2 == 0) ? 1 : 0)
#define __b2c__EXCHANGE3(x, y, z) b2c_exchange(x, y, z, NULL)
#define __b2c__EXCHANGE4(x, y, z, f) b2c_exchange(x, y, z, f)
#define EXCHANGE(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__EXCHANGE4, __b2c__EXCHANGE3)(__VA_ARGS__)
#define __b2c__EXEC1(x) b2c_exec(0, __LINE__, __FILE__, x, NULL, 0)
#define __b2c__EXEC2(x, y) b2c_exec(0, __LINE__, __FILE__, x, y, 0)
#define __b2c__EXEC3(x, y, z) b2c_exec(0, __LINE__, __FILE__, x, y, z)
#define EXEC(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXEC3, __b2c__EXEC2, __b2c__EXEC1)(__VA_ARGS__)
#define EXP(x) exp((double)x)
#define __b2c__EXPLODE1(x) b2c_explode(__LINE__, __FILE__, x, 1, NULL)
#define __b2c__EXPLODE2(x, y) b2c_explode(__LINE__, __FILE__, x, y, NULL)
#define __b2c__EXPLODE3(x, y, z) b2c_explode(__LINE__, __FILE__, x, y, z)
#define EXPLODE(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXPLODE3, __b2c__EXPLODE2, __b2c__EXPLODE1)(__VA_ARGS__)
#define __b2c__EXTRACT2(x, y) b2c_extract(__LINE__, __FILE__, x, y, 0)
#define __b2c__EXTRACT3(x, y, z) b2c_extract(__LINE__, __FILE__, x, y, z)
#define EXTRACT(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXTRACT3, __b2c__EXTRACT2)(__VA_ARGS__)
#define FALSE 0
#define FILEEXISTS(x) b2c_filestat(__LINE__, __FILE__, x, 1)
#define FILELEN(x) b2c_filestat(__LINE__, __FILE__, x, 0)
#define FILETIME(x, y) b2c_filetime(__LINE__, __FILE__, x, y)
#define FILETYPE(x) b2c_filetype(__LINE__, __FILE__, x)
#define FILL(x, y) b2c_fill(x, y)
#define FIND(x, y, z, a) b2c_find(x, y, z, a)
#define __b2c__FIRST1(x) b2c_first(x, 1, NULL)
#define __b2c__FIRST2(x, y) b2c_first(x, y, NULL)
#define __b2c__FIRST3(x, y, z) b2c_first(x, y, z)
#define FIRST(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__FIRST3, __b2c__FIRST2, __b2c__FIRST1)(__VA_ARGS__)
#define __b2c__FLATTEN1(x) b2c_flatten(x, NULL)
#define __b2c__FLATTEN2(x, y) b2c_flatten(x, y)
#define FLATTEN(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__FLATTEN2, __b2c__FLATTEN1)(__VA_ARGS__)
#define FLOATING double
#define FLOOR(x) (long)floor(x)
#define FORK fork()
#define FP(x) (void*)(&x)
#define GE >=
#define GETENVIRON(x) b2c_getenv(x)
#define GETKEY b2c_getch()
#define GETPEER(x) b2c_getpeer(__LINE__, __FILE__, (uintptr_t)x)
#define GETX b2c_getxy(0)
#define GETY b2c_getxy(1)
#define GT >
#define HASBOM(x) b2c_hasbom(x)
#define __b2c__HASDELIM1(x) b2c_hasdelim(x, NULL)
#define __b2c__HASDELIM2(x, y) b2c_hasdelim(x, y)
#define HASDELIM(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASDELIM2, __b2c__HASDELIM1)(__VA_ARGS__)
#define __b2c__HASH1(x) HASH_FUNC((char*)x, 0)
#define __b2c__HASH2(x, y) HASH_FUNC((char*)x, y)
#define HASH(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASH2, __b2c__HASH1)(__VA_ARGS__)
#define __b2c__HEAD1(x) b2c_head(x, 1, NULL)
#define __b2c__HEAD2(x, y) b2c_head(x, y, NULL)
#define __b2c__HEAD3(x, y, z) b2c_head(x, y, z)
#define HEAD(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__HEAD3, __b2c__HEAD2, __b2c__HEAD1)(__VA_ARGS__)
#define HEX(x) b2c_dec2hex(x)
#define HOST(x) b2c_nethost(__LINE__, __FILE__, x)
#define HOSTNAME b2c_hostname(__LINE__, __FILE__)
#define HOUR(x) b2c_time(x, 4)
#define __b2c__IIF2(x, y) (x ? y : 0)
#define __b2c__IIF3(x, y, z) (x ? y : z)
#define IIF(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIF3, __b2c__IIF2)(__VA_ARGS__)
#define __b2c__IIFS2(x, y) (char*)(x ? y : NULL)
#define __b2c__IIFS3(x, y, z) (char*)(x ? y : z)
#define IIF(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIFS3, __b2c__IIFS2)(__VA_ARGS__)
#define __b2c__INBETWEEN3(x, y, z) b2c_inbetween(0, x, y, z, 0)
#define __b2c__INBETWEEN4(x, y, z, f) b2c_inbetween(0, x, y, z, f)
#define INBETWEEN(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__INBETWEEN4, __b2c__INBETWEEN3)(__VA_ARGS__)
#define __b2c__INDEX4(r, t, x, y) b2c_index(__LINE__, __FILE__, r+1, t, (void*)x, 0, y)
#define __b2c__INDEX5(r, t, x, y, z) b2c_index(__LINE__, __FILE__, r+1, t, (void*)x, z, y)
#define INDEX(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__INDEX5, __b2c__INDEX4)(__VA_ARGS__)
#define INDEX(t, x, y) b2c_index_assoc(__LINE__, __FILE__, t, (b2c_htable*)assoc_ ## x, y)
#define INSERT(x, y, z) b2c_insert(__LINE__, __FILE__, x, y, z)
#define __b2c__INSTR2(x, y) b2c_instr(__LINE__, __FILE__, x, y, -1)
#define __b2c__INSTR3(x, y, z) b2c_instr(__LINE__, __FILE__, x, y, z)
#define INSTR(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTR3, __b2c__INSTR2)(__VA_ARGS__)
#define __b2c__INSTRREV2(x, y) b2c_instrrev(__LINE__, __FILE__, x, y, -1)
#define __b2c__INSTRREV3(x, y, z) b2c_instrrev(__LINE__, __FILE__, x, y, z)
#define INSTRREV(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTRREV3, __b2c__INSTRREV2)(__VA_ARGS__)
#define INT(x) lrint((double)x)
#define INTL(x) gettext(x)
#define INVERT(t, x) b2c_invert(__LINE__, __FILE__, t, &assoc_ ## x)
#define IS ==
#define ISASCII(x) b2c_isascii(x)
#define ISFALSE(x) ((x) == 0)
#define ISKEY(x, ...) (b2c_hash_find_key_do(assoc_ ## x, 0, __b2c__KEYCOLLECT(__VA_ARGS__)) == NULL ? 0 : 1)
#define ISNOT !=
#define __b2c__ISTOKEN2(x, y) b2c_istoken(x, y, NULL)
#define __b2c__ISTOKEN3(x, y, z) b2c_istoken(x, y, z)
#define ISTOKEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ISTOKEN3, __b2c__ISTOKEN2)(__VA_ARGS__)
#define ISTRUE(x) ((x) != 0)
#define ISUTF8(x) b2c_isutf8(x)
#define LCASE(x) b2c_lcase(__LINE__, __FILE__, x)
#define LE <=
#define __b2c__LEFT1(x) b2c_left(__LINE__, __FILE__, x, 1)
#define __b2c__LEFT2(x, y) b2c_left(__LINE__, __FILE__, x, y)
#define LEFT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__LEFT2, __b2c__LEFT1)(__VA_ARGS__)
#define LEN(x) (b2c_option_utf8 ? b2c_ulen(__LINE__, __FILE__, "LEN", (char*)x, -1) : b2c_len(x))
#define __b2c__ULEN1(x) b2c_ulen(__LINE__, __FILE__, "ULEN", (char*)x, -1)
#define __b2c__ULEN2(x, y) b2c_ulen(__LINE__, __FILE__, "ULEN", (char*)x, y)
#define ULEN(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__ULEN2, __b2c__ULEN1)(__VA_ARGS__)
#define __b2c__LAST1(x) b2c_last(x, 1, NULL)
#define __b2c__LAST2(x, y) b2c_last(x, y, NULL)
#define __b2c__LAST3(x, y, z) b2c_last(x, y, z)
#define LAST(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__LAST3, __b2c__LAST2, __b2c__LAST1)(__VA_ARGS__)
#define LINENO __LINE__
#define LOAD(x) b2c_load(0, __LINE__, __FILE__, x)
#define LOG(x) log((double)x)
#define LOOP(...) ( !setjmp(b2c_loop1) ? b2c_loop_helper(b2c_loop2) : b2c_loop_result )
#define LOOP(...) ( !setjmp(b2c_loop1) ? b2c_loop_helper2(b2c_loop2) : b2c_loop_result )
#define LT <
#define __b2c__MATCH2(x, y) b2c_match(x, y, -1, NULL)
#define __b2c__MATCH3(x, y, z) b2c_match(x, y, z, NULL)
#define __b2c__MATCH4(x, y, z, f) b2c_match(x, y, z, f)
#define MATCH(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__MATCH4, __b2c__MATCH3, __b2c__MATCH2)(__VA_ARGS__)
#define MAX(x, y) fmax(x, y)
#define MAX(x, y) b2c_max_str(x, y)
#define MAXNUM(x) (x)POW(2, SIZEOF(x)*8)
#define MAXRANDOM RAND_MAX
#define ME b2c_me_var
#define MEMCHECK(x) b2c_memory__check((char*)x, sizeof(__b2c__MEMTYPE))
#define MEMORY(x) (calloc(x+b2c_option_memstream, sizeof(__b2c__MEMTYPE)))
#define MEMTELL(x) (long)x
#define __b2c__MERGE1(x) b2c_merge(x, NULL)
#define __b2c__MERGE2(x, y) b2c_merge(x, y)
#define MERGE(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__MERGE2, __b2c__MERGE1)(__VA_ARGS__)
#define __b2c__MID2(x, y) b2c_mid(__LINE__, __FILE__, NULL, 0, x, y, -1)
#define __b2c__MID3(x, y, z) b2c_mid(__LINE__, __FILE__, NULL, 0, x, y, z)
#define MID(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MID3, __b2c__MID2)(__VA_ARGS__)
#define __b2c__FMID3(s, x, y) b2c_mid(__LINE__, __FILE__, &s, 1, x, y, -1)
#define __b2c__FMID4(s, x, y, z) b2c_mid(__LINE__, __FILE__, &s, 1, x, y, z)
#define F_MID(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FMID4, __b2c__FMID3)(__VA_ARGS__)
#define MIN(x, y) fmin(x, y)
#define MIN(x, y) b2c_min_str(x, y)
#define MINUTE(x) b2c_time(x, 5)
#define __b2c__MOD2(x, y) ((long)(x) % (long)(y))
#define __b2c__MOD3(x, y, z) (z == 0 ? ((long)(x) % (long)(y)) : fmod((double)x, (double)y))
#define MOD(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MOD3, __b2c__MOD2)(__VA_ARGS__)
#define MONTH(x) b2c_time(x, 2)
#define MONTH(x) b2c_datename(x, 2)
#define MYPID getpid()
#define NANOTIMER b2c_nanotimer(0)
#define NE !=
#define NL "\n"
#define NNTL(x,y,z) ngettext(x,y,z)
#define NOT(x) (!(x))
#define NOW (long)time(NULL)
#define NRKEYS(x) b2c_hash_nrkeys(assoc_ ## x)
#define NUMBER long
#define __b2c__OBTAIN1(x) b2c_hash_obtain(assoc_ ## x, NULL)
#define __b2c__OBTAIN2(x, y) b2c_hash_obtain(assoc_ ## x, y)
#define __b2c__OBTAIN3(x, y, z) b2c_hash_obtain_by_sort(__LINE__, __FILE__, assoc_ ## x, y, z, b2c_obtain_type_ ## x)
#define OBTAIN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__OBTAIN3, __b2c__OBTAIN2, __b2c__OBTAIN1)(__VA_ARGS__)
#define ODD(x) (((long)(x) % 2 != 0) ? 1 : 0)
#define OR ||
#define OS b2c_os(__LINE__, __FILE__)
#define __b2c__OUTBETWEEN3(x, y, z) b2c_inbetween(1, x, y, z, 0)
#define __b2c__OUTBETWEEN4(x, y, z, f) b2c_inbetween(1, x, y, z, f)
#define OUTBETWEEN(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__OUTBETWEEN4, __b2c__OUTBETWEEN3)(__VA_ARGS__)
#define PEEK(x) *(__b2c__MEMTYPE*)b2c_peek_check(__LINE__, __FILE__, (char*)x, sizeof(__b2c__MEMTYPE))
#define PI 3.14159265358979323846
#define POW(x, y) pow((double)x, (double)y)
#define __b2c__PROPER1(x) b2c_proper(__LINE__, __FILE__, x, NULL)
#define __b2c__PROPER2(x, y) b2c_proper(__LINE__, __FILE__, x, y)
#define PROPER(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__PROPER2, __b2c__PROPER1)(__VA_ARGS__)
#define RAD(x) (x*PI/180)
#define RANDOM(x) (long)((x+0.0)*random()/(MAXRANDOM+0.0))
#define REALPATH(x) b2c_dirname(__LINE__, __FILE__, 0, x, 0)
#define REAP(x) waitpid(x, NULL, WNOHANG)
#define REGEX(x, y) b2c_regex(__LINE__, __FILE__, x, y)
#define __b2c__REPLACE3(x, y, z) b2c_replace(__LINE__, __FILE__, x, y, z, 0)
#define __b2c__REPLACE4(x, y, z, f) b2c_replace(__LINE__, __FILE__, x, y, z, f)
#define REPLACE(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__REPLACE4, __b2c__REPLACE3)(__VA_ARGS__)
#define __b2c__REV1(x) b2c_rev(x, NULL)
#define __b2c__REV2(x, y) b2c_rev(x, y)
#define REV(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__REV2, __b2c__REV1)(__VA_ARGS__)
#define REVERSE(x) b2c_reverse(__LINE__, __FILE__, x)
#define __b2c__RIGHT1(x) b2c_right(__LINE__, __FILE__, x, 1)
#define __b2c__RIGHT2(x, y) b2c_right(__LINE__, __FILE__, x, y)
#define RIGHT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__RIGHT2, __b2c__RIGHT1)(__VA_ARGS__)
#define __b2c__RIP2(x, y) b2c_rip(__LINE__, __FILE__, x, y, -1)
#define __b2c__RIP3(x, y, z) b2c_rip(__LINE__, __FILE__, x, y, z)
#define RIP(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RIP3, __b2c__RIP2)(__VA_ARGS__)
#define RND random()
#define ROL(x) b2c_rol(sizeof(__b2c__MEMTYPE), x)
#define ROR(x) b2c_ror(sizeof(__b2c__MEMTYPE), x)
#define __b2c__ROTATE2(x, y) b2c_rotate(x, y, NULL)
#define __b2c__ROTATE3(x, y, z) b2c_rotate(x, y, z)
#define ROTATE(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ROTATE3, __b2c__ROTATE2)(__VA_ARGS__)
#define ROUND(x) lrint((double)x)
#define ROWS b2c_screen(1)
#define __b2c__RUN1(x) b2c_exec(1, __LINE__, __FILE__, x, NULL, 0)
#define __b2c__RUN2(x, y) b2c_exec(1, __LINE__, __FILE__, x, y, 0)
#define __b2c__RUN3(x, y, z) b2c_exec(1, __LINE__, __FILE__, x, y, z)
#define RUN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RUN3, __b2c__RUN2, __b2c__RUN1)(__VA_ARGS__)
#define __b2c__SEARCH2(x, y) b2c_search(__LINE__, __FILE__, x, y, -1)
#define __b2c__SEARCH3(x, y, z) b2c_search(__LINE__, __FILE__, x, y, z)
#define SEARCH(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__SEARCH3, __b2c__SEARCH2)(__VA_ARGS__)
#define SECOND(x) b2c_time(x, 6)
#define SETENVIRON(x, y) b2c_setenviron(x, y)
#define SGN(x) b2c_sgn((double)(x))
#define SIN(x) sin((double)(x))
#define SIZEOF(x) sizeof(x)
#define __b2c__SORT1(x) b2c_sort(x, NULL)
#define __b2c__SORT2(x, y) b2c_sort(x, y)
#define SORT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__SORT2, __b2c__SORT1)(__VA_ARGS__)
#define SPC(x) b2c_spc(x)
#define SQR(x) sqrt((double)(x))
#define STR(x) b2c_str(x)
#define STRING char*
#define SUM(x,...) b2c_sum(1, x, __VA_ARGS__, LONG_MAX)
#define SUMF(x,...) b2c_sumf(1, x, __VA_ARGS__, DBL_MAX)
#define TAB(x) b2c_tab(x)
#define __b2c__TAIL1(x) b2c_tail(x, 1, NULL)
#define __b2c__TAIL2(x, y) b2c_tail(x, y, NULL)
#define __b2c__TAIL3(x, y, z) b2c_tail(x, y, z)
#define TAIL(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TAIL3, __b2c__TAIL2, __b2c__TAIL1)(__VA_ARGS__)
#define __b2c__TALLY2(x, y) b2c_tally(x, y, -1)
#define __b2c__TALLY3(x, y, z) b2c_tally(x, y, z)
#define TALLY(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TALLY3, __b2c__TALLY2)(__VA_ARGS__)
#define TAN(x) tan((double)(x))
#define TELL(x) ftell(x)
#define TIMER b2c_timer(0)
#define TIMEVALUE(x,y,z,a,b,c) b2c_epoch(x,y,z,a,b,c)
#define TOASCII(x) b2c_toascii(x)
#define __b2c__TOKEN2(x, y) b2c_token(x, y, NULL)
#define __b2c__TOKEN3(x, y, z) b2c_token(x, y, z)
#define TOKEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TOKEN3, __b2c__TOKEN2)(__VA_ARGS__)
#define TOTAL(x) b2c_total(x)
#define TRUE 1
#define UCASE(x) b2c_ucase(__LINE__, __FILE__, x)
#define UCS(x) (unsigned int)b2c_utf8toasc(x)
#define UNESCAPE(x) b2c_unescape(__LINE__, __FILE__, x)
#define __b2c__UNFLATTEN1(x) b2c_unflatten(x, NULL)
#define __b2c__UNFLATTEN2(x, y) b2c_unflatten(x, y)
#define UNFLATTEN(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNFLATTEN2, __b2c__UNFLATTEN1)(__VA_ARGS__)
#define __b2c__UNIQ1(x) b2c_uniq(x, NULL)
#define __b2c__UNIQ2(x, y) b2c_uniq(x, y)
#define UNIQ(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNIQ2, __b2c__UNIQ1)(__VA_ARGS__)
#define VAL(x) b2c_val(x)
#define WAIT(x, y) b2c_netpeek(__LINE__, __FILE__, (uintptr_t)x, y)
#define __b2c__WALK4(x, y, z, q) b2c_walk(__LINE__, __FILE__, x, y, z, q, NULL)
#define __b2c__WALK5(x, y, z, q, f) b2c_walk(__LINE__, __FILE__, x, y, z, q, f)
#define WALK(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__WALK5, __b2c__WALK4)(__VA_ARGS__)
#define WEEK(x) b2c_time(x, 7)
#define WEEKDAY(x) b2c_datename(x, 1)
#define __b2c__WHERE2(x, y) b2c_where(x, y, NULL)
#define __b2c__WHERE3(x, y, z) b2c_where(x, y, z)
#define WHERE(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__WHERE3, __b2c__WHERE2)(__VA_ARGS__)
#define YEAR(x) b2c_time(x, 3)
#define b2c_cacerts NULL
#define b2c_capeer 0
#define b2c_caprivate NULL
#define b2c_caserver NULL
