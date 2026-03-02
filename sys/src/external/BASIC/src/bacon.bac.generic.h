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
jmp_buf __b2c__jump = { 0 };
int __b2c__trap = 1;
int __b2c__catch_set_backup = 0, __b2c__catch_set = 0;
void (*__b2c__error_callback)(char*, char*, long) = NULL;
int __b2c__option_compare = 0;
int __b2c__option_quoted = 1;
int __b2c__option_dq = 34;
int __b2c__option_esc = 92;
int __b2c__option_utf8 = 0;
int __b2c__option_proper = 0;
int __b2c__option_tls = 0;
char *__b2c__option_delim = " ";
int __b2c__option_memstream = 0;
int __b2c__option_startpoint = 0;
int __b2c__option_open = O_RDWR|O_NOCTTY|O_SYNC;
int __b2c__collapse = 0;
int __b2c__break_ctr = 0;
int __b2c__break_flag = 0;
char __b2c__chop_default[] = "\r\n\t\f\v ";
int __b2c__stringarray_ptr = 0;
int __b2c__floatarray_ptr = 0;
long __b2c__ctr = 0;
#define __b2c_STRING_FUNC (9)
#define __b2c_EMPTYSTRING (char*)""
jmp_buf __b2c__gosub_buffer[64];
int __b2c__gosub_buffer_ptr = -1;
char* __b2c__loop_result__b2c__string_var = NULL;
long __b2c__loop_result = 0;
jmp_buf __b2c__data_jump, __b2c__loop1, __b2c__loop2;
char *__b2c__assign = NULL;
void **__b2c__assign2 = NULL;
int __b2c__counter = 0;
char **__b2c__stack = NULL;
void **__b2c__twalk_array = NULL; int __b2c__twalk_idx = 0;
extern char *__b2c__stringarray[];
extern double __b2c__floatarray[];
char *__b2c__me_var__b2c__string_var = NULL;
/* Declarations for BaCon variables */
char *ARGUMENT__b2c__string_var = NULL;
int ERROR = 0;
int RETVAL = 0;
int REGLEN = 0;
int SP = 0;
long _ = 0;
char VERSION__b2c__string_var[] = "5.0.3";
/* Prototypes for internal functions */
int __b2c__strcmp(const char*, const char*);
char *__b2c__strdup(char*);
char *__b2c__strndup(char*, size_t);
void *__b2c_mempool_realloc_core(void*, size_t, int);
void *__b2c_str_realloc_core(char*, size_t, int);
long __b2c__delim_engine_core(int, int, long*, char*, char*, long, int);
/* Prototypes for BaCon functions */
char *ERR__b2c__string_var(int);
int __b2c_utf8_conv(int,char*);
char *__b2c_Copy_String_core(char*, char*, int);
char* __b2c_Swap_String(char**, char**);
unsigned long __b2c__len(const char*);
unsigned long __b2c__ulen(int,char*,char*,char*,int);
unsigned long __b2c__blen(int,char*,char*,char*,long,int);
unsigned long __b2c__ucs2_clen(int,char*,char*,char*,int);
long __b2c__regex_core(int, int, char*, char*, char*);
char *__b2c__extract_core(int, int, char*, char*, char*, int);
char *__b2c__replace_core(int, int, char*, char*, char*, char*, int);
char *__b2c__walk_core(int, int, char*, char*, int, char*, int, char*);
void __b2c_str_free(void);
void __b2c__arrays_free(void);
void __b2c__twalk_free(void);
int __b2c__collect(void*, void***, int, int);
/* Internal macro definitions */
#define __b2c__MEMTYPE char
#define __b2c__STRCMP __b2c__strcmp
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
#define __b2c_Copy_String(x, y) __b2c_Copy_String_core(x, y, -1)
#define __b2c_Copy_N_String(x, y, z) __b2c_Copy_String_core(x, y, z)
#define __b2c__delim_engine(x, y, z, a, b) __b2c__delim_engine_core(1, x, y, z, a, b, 0)
#define __b2c__delim_engine_cache(x, y, z, a, b) __b2c__delim_engine_core(1, x, y, z, a, b, 1)
#define __b2c__delim_engine_free() __b2c__delim_engine_core(0, 0, NULL, NULL, NULL, 0, 0)
#define __b2c__regex(x, y, z, q) __b2c__regex_core(1, x, y, z, q)
#define __b2c__regex_free() __b2c__regex_core(0, 0, NULL, NULL, NULL)
#define __b2c__extract(x, y, z, q, r) __b2c__extract_core(1, x, y, z, q, r)
#define __b2c__extract_free() __b2c__extract_core(0, 0, NULL, NULL, NULL, 0)
#define __b2c__replace(x, y, z, q, r, s) __b2c__replace_core(1, x, y, z, q, r, s)
#define __b2c__replace_free() __b2c__replace_core(0, 0, NULL, NULL, NULL, NULL, 0)
#define __b2c__walk(x, y, z, a, b, c, d) __b2c__walk_core(1, x, y, z, a, b, c, d)
#define __b2c__walk_free() __b2c__walk_core(0, 0, NULL, NULL, 0, NULL, 0, NULL)
#if INTPTR_MAX == INT64_MAX
#define HASH_FUNC (uint64_t)__b2c__HashFNV1a_64
#elif INTPTR_MAX == INT32_MAX
#define HASH_FUNC (uint32_t)__b2c__HashFNV1a_32
#else
#define HASH_FUNC (uint16_t)__b2c__HashFNV1a_16_new
#endif
#define COMPILED_BY_WHICH_BACON__b2c__string_var "Shell Script BaCon 5.0.3 in BASH 5.3.0(1)-release"
#define RUNTIMEERROR(a, x, y, z, q) do { if(!__b2c__catch_set) { if(__b2c__trap) { fprintf(stderr, "Runtime error: statement '%s' at line %d in '%s': %s\n", a, x, y, ERR__b2c__string_var(z)); exit(z); } if(__b2c__error_callback){ (*__b2c__error_callback)(a,y,x); } } else { if(!setjmp(__b2c__jump)) { goto q; } } } while(0)
#define RUNTIMEFERR(a, x, y, z) do { if(__b2c__trap) { fprintf(stderr, "Runtime error: function '%s' at line %d in '%s': %s\n", a, z, y, ERR__b2c__string_var(x)); exit(x); } if(__b2c__error_callback){ (*__b2c__error_callback)(a,y,z); } } while(0)
#define RUNTIMEDEBUG(x, y, z) (__b2c__getch() == 27 ? fprintf(stderr, "TRACE OFF - exiting trace mode.\n") && __b2c__stop_program() : fprintf(stderr, "File '%s' line %d: %s\n", #x, y, z) )
int __b2c__stop_program(void) { exit(EXIT_SUCCESS); return(1); }
/* BaCon functions */
#define ABS(x) fabs((double)x)
#define ACOS(x) acos((double)x)
#define ADDRESS(x) (uintptr_t)(&x)
#define __b2c__ALIGN3(x, y, z) __b2c__align(__LINE__, __FILE__, x, y, z, 0)
#define __b2c__ALIGN4(x, y, z, f) __b2c__align(__LINE__, __FILE__, x, y, z, f)
#define ALIGN__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__ALIGN4, __b2c__ALIGN3)(__VA_ARGS__)
#define __b2c__AMOUNT1(x) __b2c__amount(x, NULL)
#define __b2c__AMOUNT2(x, y) __b2c__amount(x, y)
#define AMOUNT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__AMOUNT2, __b2c__AMOUNT1)(__VA_ARGS__)
#define AND &&
#define __b2c__APPEND3(x, y, z) __b2c__append(NULL, 0, x, y, z, NULL)
#define __b2c__APPEND4(x, y, z, f) __b2c__append(NULL, 0, x, y, z, f)
#define APPEND__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__APPEND4, __b2c__APPEND3)(__VA_ARGS__)
#define __b2c__FAPPEND4(s, x, y, z) __b2c__append(&s, 1, x, y, z, NULL)
#define __b2c__FAPPEND5(s, x, y, z, f) __b2c__append(&s, 1, x, y, z, f)
#define F_APPEND__b2c__string_var(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__FAPPEND5, __b2c__FAPPEND4)(__VA_ARGS__)
#define ASC(x) __b2c__asc(x)
#define ASIN(x) asin((double)(x))
#define ATN(x) atan((double)(x))
#define ATN2(x,y) atan2((double)(x),(double)(y))
#define B64DEC__b2c__string_var(x) __b2c__b64dec(__LINE__, __FILE__, x)
#define __b2c__B64ENC1(x) __b2c__b64enc(x, 0)
#define __b2c__B64ENC2(x, y) __b2c__b64enc((char*)x, y)
#define B64ENC__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__B64ENC2, __b2c__B64ENC1)(__VA_ARGS__)
#define __b2c__BASENAME1(x) __b2c__dirname(__LINE__, __FILE__, 1, x, 0)
#define __b2c__BASENAME2(x, y) __b2c__dirname(__LINE__, __FILE__, 1, x, y)
#define BASENAME__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__BASENAME2, __b2c__BASENAME1)(__VA_ARGS__)
#define BIN__b2c__string_var(x) __b2c__bin(sizeof(__b2c__MEMTYPE), x)
#define BIT(x) __b2c__bit(x)
#define BLOAD(x) (void*)__b2c__load(1, __LINE__, __FILE__, x)
#define __b2c__BYTELEN2(x, y) __b2c__blen(__LINE__, __FILE__, "BYTELEN", x, y, 0)
#define __b2c__BYTELEN3(x, y, z) __b2c__blen(__LINE__, __FILE__, "BYTELEN", x, y, z)
#define BYTELEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__BYTELEN3, __b2c__BYTELEN2)(__VA_ARGS__)
#define CA__b2c__string_var(x) __b2c__ca(__LINE__, __FILE__, x)
#define CN__b2c__string_var(x) __b2c__cn(__LINE__, __FILE__, x)
#define CIPHER__b2c__string_var(x) __b2c__cipher(__LINE__, __FILE__, x)
#define VERIFY(x, y) ((SSL*)x == NULL ? -1 : (long)SSL_get_verify_result((SSL*)x) )
#define ACCEPT(x) __b2c__accept(__LINE__, __FILE__, __b2c__caprivate, __b2c__caserver, x)
#define CEIL(x) (double)ceil(x)
#define __b2c__CHANGE3(x, y, z) __b2c__change(x, y, z, NULL)
#define __b2c__CHANGE4(x, y, z, f) __b2c__change(x, y, z, f)
#define CHANGE__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CHANGE4, __b2c__CHANGE3)(__VA_ARGS__)
#define __b2c__CHOP1(x) __b2c__chop(NULL, 0, x, NULL, 0)
#define __b2c__CHOP2(x, y) __b2c__chop(NULL, 0, x, y, 0)
#define __b2c__CHOP3(x, y, z) __b2c__chop(NULL, 0, x, y, z)
#define CHOP__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__CHOP3, __b2c__CHOP2, __b2c__CHOP1)(__VA_ARGS__)
#define __b2c__FCHOP2(s, x) __b2c__chop(&s, 1, x, NULL, 0)
#define __b2c__FCHOP3(s, x, y) __b2c__chop(&s, 1, x, y, 0)
#define __b2c__FCHOP4(s, x, y, z) __b2c__chop(&s, 1, x, y, z)
#define F_CHOP__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FCHOP4, __b2c__FCHOP3, __b2c__FCHOP2)(__VA_ARGS__)
#define CHR__b2c__string_var(x) __b2c__asc2char(x)
#define UTF8__b2c__string_var(x) __b2c__asc2utf8(x)
#define CL__b2c__string_var "\033[2K"
#define CMDLINE(x) __b2c__getopt(argc, argv, x)
#define COIL__b2c__string_var(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper(__b2c__loop2) : __b2c__loop_result__b2c__string_var )
#define __b2c__COLLAPSE1(x) __b2c__collapse_func(x, NULL)
#define __b2c__COLLAPSE2(x, y) __b2c__collapse_func(x, y)
#define COLLAPSE__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__COLLAPSE2, __b2c__COLLAPSE1)(__VA_ARGS__)
#define COLUMNS __b2c__screen(0)
#define CONCAT__b2c__string_var(...) __b2c__concat(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)
#define F_CONCAT__b2c__string_var(...) __b2c__concat2(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)
#define COS(x) cos((double)(x))
#define COUNT(x, y) __b2c__count(__LINE__, __FILE__, x, y)
#define CR__b2c__string_var "\r"
#define CURDIR__b2c__string_var __b2c__curdir()
#define __b2c__CUT3(x, y, z) __b2c__cut(x, y, z, NULL)
#define __b2c__CUT4(x, y, z, f) __b2c__cut(x, y, z, f)
#define CUT__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CUT4, __b2c__CUT3)(__VA_ARGS__)
#define DAY(x) __b2c__time(x, 1)
#define __b2c__DEC1(x) __b2c__hex2dec(__LINE__, __FILE__, x, 0)
#define __b2c__DEC2(x, y) __b2c__hex2dec(__LINE__, __FILE__, x, y)
#define DEC(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__DEC2, __b2c__DEC1)(__VA_ARGS__)
#define DEG(x) (x*180/PI)
#define __b2c__DEL2(x, y) __b2c__del(x, y, NULL)
#define __b2c__DEL3(x, y, z) __b2c__del(x, y, z)
#define DEL__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__DEL3, __b2c__DEL2)(__VA_ARGS__)
#define DELIM__b2c__string_var(x, y, z) __b2c__delim(x, y, z)
#define DIRNAME__b2c__string_var(x) __b2c__dirname(__LINE__, __FILE__, 2, x, 0)
#define DLE__b2c__string_var "\r\n"
#define EDITBOM__b2c__string_var(x, y) __b2c__editbom(x, y)
#define EL__b2c__string_var "\033[0K"
#define ENDFILE(x) feof(x)
#define EQ ==
#define EQUAL(x, y) !__b2c__STRCMP(x, y)
#define ESCAPE__b2c__string_var(x) __b2c__escape(__LINE__, __FILE__, x)
#define EVAL(x, y, z, q) __b2c__eval(__LINE__, __FILE__, x, y, z, q)
#define EVEN(x) (((long)(x) % 2 == 0) ? 1 : 0)
#define __b2c__EXCHANGE3(x, y, z) __b2c__exchange(x, y, z, NULL)
#define __b2c__EXCHANGE4(x, y, z, f) __b2c__exchange(x, y, z, f)
#define EXCHANGE__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__EXCHANGE4, __b2c__EXCHANGE3)(__VA_ARGS__)
#define __b2c__EXEC1(x) __b2c__exec(0, __LINE__, __FILE__, x, NULL, 0)
#define __b2c__EXEC2(x, y) __b2c__exec(0, __LINE__, __FILE__, x, y, 0)
#define __b2c__EXEC3(x, y, z) __b2c__exec(0, __LINE__, __FILE__, x, y, z)
#define EXEC__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXEC3, __b2c__EXEC2, __b2c__EXEC1)(__VA_ARGS__)
#define EXP(x) exp((double)x)
#define __b2c__EXPLODE1(x) __b2c__explode(__LINE__, __FILE__, x, 1, NULL)
#define __b2c__EXPLODE2(x, y) __b2c__explode(__LINE__, __FILE__, x, y, NULL)
#define __b2c__EXPLODE3(x, y, z) __b2c__explode(__LINE__, __FILE__, x, y, z)
#define EXPLODE__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXPLODE3, __b2c__EXPLODE2, __b2c__EXPLODE1)(__VA_ARGS__)
#define __b2c__EXTRACT2(x, y) __b2c__extract(__LINE__, __FILE__, x, y, 0)
#define __b2c__EXTRACT3(x, y, z) __b2c__extract(__LINE__, __FILE__, x, y, z)
#define EXTRACT__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXTRACT3, __b2c__EXTRACT2)(__VA_ARGS__)
#define FALSE 0
#define FILEEXISTS(x) __b2c__filestat(__LINE__, __FILE__, x, 1)
#define FILELEN(x) __b2c__filestat(__LINE__, __FILE__, x, 0)
#define FILETIME(x, y) __b2c__filetime(__LINE__, __FILE__, x, y)
#define FILETYPE(x) __b2c__filetype(__LINE__, __FILE__, x)
#define FILL__b2c__string_var(x, y) __b2c__fill(x, y)
#define FIND(x, y, z, a) __b2c__find(x, y, z, a)
#define __b2c__FIRST1(x) __b2c__first(x, 1, NULL)
#define __b2c__FIRST2(x, y) __b2c__first(x, y, NULL)
#define __b2c__FIRST3(x, y, z) __b2c__first(x, y, z)
#define FIRST__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__FIRST3, __b2c__FIRST2, __b2c__FIRST1)(__VA_ARGS__)
#define __b2c__FLATTEN1(x) __b2c__flatten(x, NULL)
#define __b2c__FLATTEN2(x, y) __b2c__flatten(x, y)
#define FLATTEN__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__FLATTEN2, __b2c__FLATTEN1)(__VA_ARGS__)
#define FLOATING double
#define FLOOR(x) (long)floor(x)
#define FORK fork()
#define FP(x) (void*)(&x)
#define GE >=
#define GETENVIRON__b2c__string_var(x) __b2c__getenv(x)
#define GETKEY __b2c__getch()
#define GETPEER__b2c__string_var(x) __b2c__getpeer(__LINE__, __FILE__, (uintptr_t)x)
#define GETX __b2c__getxy(0)
#define GETY __b2c__getxy(1)
#define GT >
#define HASBOM(x) __b2c__hasbom(x)
#define __b2c__HASDELIM1(x) __b2c__hasdelim(x, NULL)
#define __b2c__HASDELIM2(x, y) __b2c__hasdelim(x, y)
#define HASDELIM(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASDELIM2, __b2c__HASDELIM1)(__VA_ARGS__)
#define __b2c__HASH1(x) HASH_FUNC((char*)x, 0)
#define __b2c__HASH2(x, y) HASH_FUNC((char*)x, y)
#define HASH(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASH2, __b2c__HASH1)(__VA_ARGS__)
#define __b2c__HEAD1(x) __b2c__head(x, 1, NULL)
#define __b2c__HEAD2(x, y) __b2c__head(x, y, NULL)
#define __b2c__HEAD3(x, y, z) __b2c__head(x, y, z)
#define HEAD__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__HEAD3, __b2c__HEAD2, __b2c__HEAD1)(__VA_ARGS__)
#define HEX__b2c__string_var(x) __b2c__dec2hex(x)
#define HOST__b2c__string_var(x) __b2c__nethost(__LINE__, __FILE__, x)
#define HOSTNAME__b2c__string_var __b2c__hostname(__LINE__, __FILE__)
#define HOUR(x) __b2c__time(x, 4)
#define __b2c__IIF2(x, y) (x ? y : 0)
#define __b2c__IIF3(x, y, z) (x ? y : z)
#define IIF(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIF3, __b2c__IIF2)(__VA_ARGS__)
#define __b2c__IIFS2(x, y) (char*)(x ? y : NULL)
#define __b2c__IIFS3(x, y, z) (char*)(x ? y : z)
#define IIF__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIFS3, __b2c__IIFS2)(__VA_ARGS__)
#define __b2c__INBETWEEN3(x, y, z) __b2c__inbetween(0, x, y, z, 0)
#define __b2c__INBETWEEN4(x, y, z, f) __b2c__inbetween(0, x, y, z, f)
#define INBETWEEN__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__INBETWEEN4, __b2c__INBETWEEN3)(__VA_ARGS__)
#define __b2c__INDEX4(r, t, x, y) __b2c__index(__LINE__, __FILE__, r+1, t, (void*)x, 0, y)
#define __b2c__INDEX5(r, t, x, y, z) __b2c__index(__LINE__, __FILE__, r+1, t, (void*)x, z, y)
#define INDEX(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__INDEX5, __b2c__INDEX4)(__VA_ARGS__)
#define INDEX__b2c__string_var(t, x, y) __b2c__index_assoc(__LINE__, __FILE__, t, (__b2c__htable*)__b2c__assoc_ ## x, y)
#define INSERT__b2c__string_var(x, y, z) __b2c__insert(__LINE__, __FILE__, x, y, z)
#define __b2c__INSTR2(x, y) __b2c__instr(__LINE__, __FILE__, x, y, -1)
#define __b2c__INSTR3(x, y, z) __b2c__instr(__LINE__, __FILE__, x, y, z)
#define INSTR(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTR3, __b2c__INSTR2)(__VA_ARGS__)
#define __b2c__INSTRREV2(x, y) __b2c__instrrev(__LINE__, __FILE__, x, y, -1)
#define __b2c__INSTRREV3(x, y, z) __b2c__instrrev(__LINE__, __FILE__, x, y, z)
#define INSTRREV(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTRREV3, __b2c__INSTRREV2)(__VA_ARGS__)
#define INT(x) lrint((double)x)
#define INTL__b2c__string_var(x) gettext(x)
#define INVERT(t, x) __b2c__invert(__LINE__, __FILE__, t, &__b2c__assoc_ ## x)
#define IS ==
#define ISASCII(x) __b2c__isascii(x)
#define ISFALSE(x) ((x) == 0)
#define ISKEY(x, ...) (__b2c__hash_find_key_do(__b2c__assoc_ ## x, 0, __b2c__KEYCOLLECT(__VA_ARGS__)) == NULL ? 0 : 1)
#define ISNOT !=
#define __b2c__ISTOKEN2(x, y) __b2c__istoken(x, y, NULL)
#define __b2c__ISTOKEN3(x, y, z) __b2c__istoken(x, y, z)
#define ISTOKEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ISTOKEN3, __b2c__ISTOKEN2)(__VA_ARGS__)
#define ISTRUE(x) ((x) != 0)
#define ISUTF8(x) __b2c__isutf8(x)
#define LCASE__b2c__string_var(x) __b2c__lcase(__LINE__, __FILE__, x)
#define LE <=
#define __b2c__LEFT1(x) __b2c__left(__LINE__, __FILE__, x, 1)
#define __b2c__LEFT2(x, y) __b2c__left(__LINE__, __FILE__, x, y)
#define LEFT__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__LEFT2, __b2c__LEFT1)(__VA_ARGS__)
#define LEN(x) (__b2c__option_utf8 ? __b2c__ulen(__LINE__, __FILE__, "LEN", (char*)x, -1) : __b2c__len(x))
#define __b2c__ULEN1(x) __b2c__ulen(__LINE__, __FILE__, "ULEN", (char*)x, -1)
#define __b2c__ULEN2(x, y) __b2c__ulen(__LINE__, __FILE__, "ULEN", (char*)x, y)
#define ULEN(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__ULEN2, __b2c__ULEN1)(__VA_ARGS__)
#define __b2c__LAST1(x) __b2c__last(x, 1, NULL)
#define __b2c__LAST2(x, y) __b2c__last(x, y, NULL)
#define __b2c__LAST3(x, y, z) __b2c__last(x, y, z)
#define LAST__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__LAST3, __b2c__LAST2, __b2c__LAST1)(__VA_ARGS__)
#define LINENO __LINE__
#define LOAD__b2c__string_var(x) __b2c__load(0, __LINE__, __FILE__, x)
#define LOG(x) log((double)x)
#define LOOP__b2c__string_var(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper(__b2c__loop2) : __b2c__loop_result__b2c__string_var )
#define LOOP(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper2(__b2c__loop2) : __b2c__loop_result )
#define LT <
#define __b2c__MATCH2(x, y) __b2c__match(x, y, -1, NULL)
#define __b2c__MATCH3(x, y, z) __b2c__match(x, y, z, NULL)
#define __b2c__MATCH4(x, y, z, f) __b2c__match(x, y, z, f)
#define MATCH(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__MATCH4, __b2c__MATCH3, __b2c__MATCH2)(__VA_ARGS__)
#define MAX(x, y) fmax(x, y)
#define MAX__b2c__string_var(x, y) __b2c__max_str(x, y)
#define MAXNUM(x) (x)POW(2, SIZEOF(x)*8)
#define MAXRANDOM RAND_MAX
#define ME__b2c__string_var __b2c__me_var__b2c__string_var
#define MEMCHECK(x) __b2c__memory__check((char*)x, sizeof(__b2c__MEMTYPE))
#define MEMORY(x) (calloc(x+__b2c__option_memstream, sizeof(__b2c__MEMTYPE)))
#define MEMTELL(x) (long)x
#define __b2c__MERGE1(x) __b2c__merge(x, NULL)
#define __b2c__MERGE2(x, y) __b2c__merge(x, y)
#define MERGE__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__MERGE2, __b2c__MERGE1)(__VA_ARGS__)
#define __b2c__MID2(x, y) __b2c__mid(__LINE__, __FILE__, NULL, 0, x, y, -1)
#define __b2c__MID3(x, y, z) __b2c__mid(__LINE__, __FILE__, NULL, 0, x, y, z)
#define MID__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MID3, __b2c__MID2)(__VA_ARGS__)
#define __b2c__FMID3(s, x, y) __b2c__mid(__LINE__, __FILE__, &s, 1, x, y, -1)
#define __b2c__FMID4(s, x, y, z) __b2c__mid(__LINE__, __FILE__, &s, 1, x, y, z)
#define F_MID__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FMID4, __b2c__FMID3)(__VA_ARGS__)
#define MIN(x, y) fmin(x, y)
#define MIN__b2c__string_var(x, y) __b2c__min_str(x, y)
#define MINUTE(x) __b2c__time(x, 5)
#define __b2c__MOD2(x, y) ((long)(x) % (long)(y))
#define __b2c__MOD3(x, y, z) (z == 0 ? ((long)(x) % (long)(y)) : fmod((double)x, (double)y))
#define MOD(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MOD3, __b2c__MOD2)(__VA_ARGS__)
#define MONTH(x) __b2c__time(x, 2)
#define MONTH__b2c__string_var(x) __b2c__datename(x, 2)
#define MYPID getpid()
#define NANOTIMER __b2c__nanotimer(0)
#define NE !=
#define NL__b2c__string_var "\n"
#define NNTL__b2c__string_var(x,y,z) ngettext(x,y,z)
#define NOT(x) (!(x))
#define NOW (long)time(NULL)
#define NRKEYS(x) __b2c__hash_nrkeys(__b2c__assoc_ ## x)
#define NUMBER long
#define __b2c__OBTAIN1(x) __b2c__hash_obtain(__b2c__assoc_ ## x, NULL)
#define __b2c__OBTAIN2(x, y) __b2c__hash_obtain(__b2c__assoc_ ## x, y)
#define __b2c__OBTAIN3(x, y, z) __b2c__hash_obtain_by_sort(__LINE__, __FILE__, __b2c__assoc_ ## x, y, z, __b2c__obtain_type_ ## x)
#define OBTAIN__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__OBTAIN3, __b2c__OBTAIN2, __b2c__OBTAIN1)(__VA_ARGS__)
#define ODD(x) (((long)(x) % 2 != 0) ? 1 : 0)
#define OR ||
#define OS__b2c__string_var __b2c__os(__LINE__, __FILE__)
#define __b2c__OUTBETWEEN3(x, y, z) __b2c__inbetween(1, x, y, z, 0)
#define __b2c__OUTBETWEEN4(x, y, z, f) __b2c__inbetween(1, x, y, z, f)
#define OUTBETWEEN__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__OUTBETWEEN4, __b2c__OUTBETWEEN3)(__VA_ARGS__)
#define PEEK(x) *(__b2c__MEMTYPE*)__b2c__peek_check(__LINE__, __FILE__, (char*)x, sizeof(__b2c__MEMTYPE))
#define PI 3.14159265358979323846
#define POW(x, y) pow((double)x, (double)y)
#define __b2c__PROPER1(x) __b2c__proper(__LINE__, __FILE__, x, NULL)
#define __b2c__PROPER2(x, y) __b2c__proper(__LINE__, __FILE__, x, y)
#define PROPER__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__PROPER2, __b2c__PROPER1)(__VA_ARGS__)
#define RAD(x) (x*PI/180)
#define RANDOM(x) (long)((x+0.0)*random()/(MAXRANDOM+0.0))
#define REALPATH__b2c__string_var(x) __b2c__dirname(__LINE__, __FILE__, 0, x, 0)
#define REAP(x) waitpid(x, NULL, WNOHANG)
#define REGEX(x, y) __b2c__regex(__LINE__, __FILE__, x, y)
#define __b2c__REPLACE3(x, y, z) __b2c__replace(__LINE__, __FILE__, x, y, z, 0)
#define __b2c__REPLACE4(x, y, z, f) __b2c__replace(__LINE__, __FILE__, x, y, z, f)
#define REPLACE__b2c__string_var(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__REPLACE4, __b2c__REPLACE3)(__VA_ARGS__)
#define __b2c__REV1(x) __b2c__rev(x, NULL)
#define __b2c__REV2(x, y) __b2c__rev(x, y)
#define REV__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__REV2, __b2c__REV1)(__VA_ARGS__)
#define REVERSE__b2c__string_var(x) __b2c__reverse(__LINE__, __FILE__, x)
#define __b2c__RIGHT1(x) __b2c__right(__LINE__, __FILE__, x, 1)
#define __b2c__RIGHT2(x, y) __b2c__right(__LINE__, __FILE__, x, y)
#define RIGHT__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__RIGHT2, __b2c__RIGHT1)(__VA_ARGS__)
#define __b2c__RIP2(x, y) __b2c__rip(__LINE__, __FILE__, x, y, -1)
#define __b2c__RIP3(x, y, z) __b2c__rip(__LINE__, __FILE__, x, y, z)
#define RIP__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RIP3, __b2c__RIP2)(__VA_ARGS__)
#define RND random()
#define ROL(x) __b2c__rol(sizeof(__b2c__MEMTYPE), x)
#define ROR(x) __b2c__ror(sizeof(__b2c__MEMTYPE), x)
#define __b2c__ROTATE2(x, y) __b2c__rotate(x, y, NULL)
#define __b2c__ROTATE3(x, y, z) __b2c__rotate(x, y, z)
#define ROTATE__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ROTATE3, __b2c__ROTATE2)(__VA_ARGS__)
#define ROUND(x) lrint((double)x)
#define ROWS __b2c__screen(1)
#define __b2c__RUN1(x) __b2c__exec(1, __LINE__, __FILE__, x, NULL, 0)
#define __b2c__RUN2(x, y) __b2c__exec(1, __LINE__, __FILE__, x, y, 0)
#define __b2c__RUN3(x, y, z) __b2c__exec(1, __LINE__, __FILE__, x, y, z)
#define RUN__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RUN3, __b2c__RUN2, __b2c__RUN1)(__VA_ARGS__)
#define __b2c__SEARCH2(x, y) __b2c__search(__LINE__, __FILE__, x, y, -1)
#define __b2c__SEARCH3(x, y, z) __b2c__search(__LINE__, __FILE__, x, y, z)
#define SEARCH(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__SEARCH3, __b2c__SEARCH2)(__VA_ARGS__)
#define SECOND(x) __b2c__time(x, 6)
#define SETENVIRON(x, y) __b2c__setenviron(x, y)
#define SGN(x) __b2c__sgn((double)(x))
#define SIN(x) sin((double)(x))
#define SIZEOF(x) sizeof(x)
#define __b2c__SORT1(x) __b2c__sort(x, NULL)
#define __b2c__SORT2(x, y) __b2c__sort(x, y)
#define SORT__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__SORT2, __b2c__SORT1)(__VA_ARGS__)
#define SPC__b2c__string_var(x) __b2c__spc(x)
#define SQR(x) sqrt((double)(x))
#define STR__b2c__string_var(x) __b2c__str(x)
#define STRING char*
#define SUM(x,...) __b2c__sum(1, x, __VA_ARGS__, LONG_MAX)
#define SUMF(x,...) __b2c__sumf(1, x, __VA_ARGS__, DBL_MAX)
#define TAB__b2c__string_var(x) __b2c__tab(x)
#define __b2c__TAIL1(x) __b2c__tail(x, 1, NULL)
#define __b2c__TAIL2(x, y) __b2c__tail(x, y, NULL)
#define __b2c__TAIL3(x, y, z) __b2c__tail(x, y, z)
#define TAIL__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TAIL3, __b2c__TAIL2, __b2c__TAIL1)(__VA_ARGS__)
#define __b2c__TALLY2(x, y) __b2c__tally(x, y, -1)
#define __b2c__TALLY3(x, y, z) __b2c__tally(x, y, z)
#define TALLY(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TALLY3, __b2c__TALLY2)(__VA_ARGS__)
#define TAN(x) tan((double)(x))
#define TELL(x) ftell(x)
#define TIMER __b2c__timer(0)
#define TIMEVALUE(x,y,z,a,b,c) __b2c__epoch(x,y,z,a,b,c)
#define TOASCII__b2c__string_var(x) __b2c__toascii(x)
#define __b2c__TOKEN2(x, y) __b2c__token(x, y, NULL)
#define __b2c__TOKEN3(x, y, z) __b2c__token(x, y, z)
#define TOKEN__b2c__string_var(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TOKEN3, __b2c__TOKEN2)(__VA_ARGS__)
#define TOTAL(x) __b2c__total(x)
#define TRUE 1
#define UCASE__b2c__string_var(x) __b2c__ucase(__LINE__, __FILE__, x)
#define UCS(x) (unsigned int)__b2c__utf8toasc(x)
#define UNESCAPE__b2c__string_var(x) __b2c__unescape(__LINE__, __FILE__, x)
#define __b2c__UNFLATTEN1(x) __b2c__unflatten(x, NULL)
#define __b2c__UNFLATTEN2(x, y) __b2c__unflatten(x, y)
#define UNFLATTEN__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNFLATTEN2, __b2c__UNFLATTEN1)(__VA_ARGS__)
#define __b2c__UNIQ1(x) __b2c__uniq(x, NULL)
#define __b2c__UNIQ2(x, y) __b2c__uniq(x, y)
#define UNIQ__b2c__string_var(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNIQ2, __b2c__UNIQ1)(__VA_ARGS__)
#define VAL(x) __b2c__val(x)
#define WAIT(x, y) __b2c__netpeek(__LINE__, __FILE__, (uintptr_t)x, y)
#define __b2c__WALK4(x, y, z, q) __b2c__walk(__LINE__, __FILE__, x, y, z, q, NULL)
#define __b2c__WALK5(x, y, z, q, f) __b2c__walk(__LINE__, __FILE__, x, y, z, q, f)
#define WALK__b2c__string_var(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__WALK5, __b2c__WALK4)(__VA_ARGS__)
#define WEEK(x) __b2c__time(x, 7)
#define WEEKDAY__b2c__string_var(x) __b2c__datename(x, 1)
#define __b2c__WHERE2(x, y) __b2c__where(x, y, NULL)
#define __b2c__WHERE3(x, y, z) __b2c__where(x, y, z)
#define WHERE(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__WHERE3, __b2c__WHERE2)(__VA_ARGS__)
#define YEAR(x) __b2c__time(x, 3)
#define __b2c__cacerts NULL
#define __b2c__capeer 0
#define __b2c__caprivate NULL
#define __b2c__caserver NULL
