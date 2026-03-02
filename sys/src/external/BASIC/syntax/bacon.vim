" Vim syntax file
" Language:	BaCon
" Maintainer: Peter van Eerten
" Last Change: April 16, 2024

if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

" syntax case ignore

setlocal iskeyword+=$

" BACON string functions
syn match basicstrFunction	"CHOP\$\|CA\$\|CN\$\|CHR\$\|CONCAT\$\|CURDIR\$\|ERR\$\|EXEC\$\|FILL\$\|HOST\$\|TYPEOF\$\|IIF\$\|REALPATH\$\|RUN\$\|LAST\$\|TOASCII\$\|ME\$"
syn match basicstrFunction	"OBTAIN\$\|GETENVIRON\$\|HEX\$\|LCASE\$\|LEFT\$\|MID\$\|MIN\$\|MONTH\$\|MAX\$\|OS\$\|REPLACE\$\|GETPEER\$\|HOSTNAME\$\|EXPLODE\$\|LOOP\$"
syn match basicstrFunction	"DIRNAME\$\|REVERSE\$\|RIGHT\$\|SPC\$\|STR\$\|TAB\$\|UCASE\$\|WEEKDAY\$\|INTL\$\|NNTL\$\|EXTRACT\$\|BASENAME\$\|B64ENC\$\|CIPHER\$\|COIL\$"
syn match basicstrFunction	"INBETWEEN\$\|OUTBETWEEN\$\|BIN\$\|TOKEN\$\|FLATTEN\$\|UNFLATTEN\$\|EXCHANGE\$\|LOAD\$\|INSERT\$\|CHANGE\$\|FIRST\$\|B64DEC\$\|RIP\$\|REV\$"
syn match basicstrFunction	"UNIQ\$\|SORT\$\|DELIM\$\|HEAD\$\|TAIL\$\|APPEND\$\|DEL\$\|CUT\$\|ALIGN\$\|UTF8\$\|PROPER\$\|ROTATE\$\|MERGE\$\|WALK\$\|GUIEVENT\$"
syn match basicstrFunction	"ESCAPE\$\|UNESCAPE\$\|COLLAPSE\$\|INDEX\$\|EDITBOM\$"

" BACON keywords
syn keyword basicStatement	WHILE DO WEND REPEAT UNTIL FOR TO NEXT SELECT OFF INTERNATIONAL COMPILER BSAVE SAVE SET ADD
syn keyword basicStatement	IF THEN ELSE ELIF ENDIF PRINT FORMAT INPUT TRACE STOP CONTINUE INCLUDE DOTIMES APPEND UNSET
syn keyword basicStatement	LET END OPEN READING WRITING AS STEP BREAK DEFAULT ALIAS VAR PRAGMA IN ENDFORK BAPPEND SCREEN
syn keyword basicStatement	APPENDING READWRITE CLOSE REWIND MEMREWIND READLN CURSOR LOOKUP LDFLAGS LIBRARY QUOTED FTYPE
syn keyword basicStatement	FROM WRITELN SUB READ ENDSUB CALL IMPORT GETLINE INCR DECR FI EXIT EPRINT DONE MAP DQ ESC
syn keyword basicStatement	DECLARE TYPE INCLUDE SYSTEM DATA RESTORE PUTLINE COLLAPSE ARRAY OPTIONS SIGNAL UTF8 FUNCTION
syn keyword basicStatement	ENDFUNCTION ENDFUNC ENDRECORD RETURN POKE PUSH PULL SEEK ON ALARM STARTPOINT SWAP RUN FUNC
syn keyword basicStatement	SLEEP SEED GETBYTE CONST COPY DELETE SETENVIRON CASE RELATE SCTP FORWARD VARTYPE EXPLICIT
syn keyword basicStatement	OFFSET WHENCE RESUME START CURRENT PUTBYTE ENDWITH SOCKET MULTICAST JOIN DOWNTO PROPER NO_C_ESC
syn keyword basicStatement	SIZE GOTO LABEL TRAP CATCH USEC WITH SPLIT BY COMPARE CHUNK REDIM BACK PARSE RE TLS CLASS
syn keyword basicStatement	ENDUSEC ENDUSEH FILE DIRECTORY GETFILE RENAME CLEAR IS EQ PROTO GOSUB USEH LT LE ENDCLASS
syn keyword basicStatement	COLOR RESET INTENSE NORMAL BLACK RED GREEN RECORD ASSOC TEXTDOMAIN RECURSIVE DELIM TREE
syn keyword basicStatement	YELLOW BLUE MAGENTA CYAN WHITE FG BG GOTOXY NE ISNOT BASE BROADCAST GT GE FRAMEWORK NODE
syn keyword basicStatement	MAKEDIR CHANGEDIR LOCAL GLOBAL RESIZE ENDSELECT OPTION MEMTYPE TCP UP GUI CERTIFICATE BOLD PRIORITY
syn keyword basicStatement	DEF FN FREE NETWORK SEND RECEIVE SERVER SORT DOWN MEMSTREAM UDP SCROLL INVERSE COLLECT BLINK STRIKE
syn keyword basicStatement	SETSERIAL DEVICE SPEED IMODE OTHER OMODE CMODE LMODE STATIC ENUM ENDENUM MONITOR ITALIC UNDERLINE

" BACON functions
syn keyword basicFunction	SQR POW SIN COS TAN ABS ROUND NOT ENDFILE TELL REGEX ISTRUE ASIN ACOS BIT ISTOKEN EXCL EVAL GUIDEFINE FIND BEYOND
syn keyword basicFunction	LEN VAL MOD DIR DEC ASC AND OR INSTR FLOOR ISFALSE IIF NOW MEMCHECK COUNT AMOUNT BETWEEN HASDELIM UBOUND WHERE
syn keyword basicFunction	MEMORY PEEK INSTRREV GETX GETY DAY RND EVEN ODD TIMER ISKEY MAXNUM NANOTIMER CEIL BLOAD BYTELEN HASH LOOP GUIGET MATCH
syn keyword basicFunction	SEARCH WEEK MONTH YEAR INT SIZEOF ATN ATN2 LOG EXP SGN GETKEY CMDLINE DEG FORK TALLY SUM SUMF GUISET ACCEPT TOTAL
syn keyword basicFunction	HOUR MINUTE SECOND ADDRESS FILELEN FILETYPE FILEEXISTS RAD MYPID ROL ROR ISASCII VERIFY GUIWIDGET INDEX HASBOM
syn keyword basicFunction	COLUMNS ROWS WAIT TIMEVALUE RANDOM EQUAL MEMTELL FP FILETIME MIN MAX REAP ULEN UCS NRKEYS ISUTF8 GUIFN GUICB INVERT

" BACON constants
syn keyword basicConstant	TRUE FALSE PI MAXRANDOM REGLEN RETVAL ERROR LINENO SP NULL
syn match basicstrConstant	"NL\$\|CR\$\|DLE\$\|EL\$\|CL\$\|VERSION\$\|ARGUMENT\$\|SOURCE\$"

"integer number, or floating point number without a dot.
syn match  basicNumber		"\<\d\+\>"
"floating point number, with dot
syn match  basicNumber		"\<\d\+\.\d*\>"
"floating point number, starting with a dot
syn match  basicNumber		"\.\d\+\>"

" String and Character contstants
syn match   basicSpecial contained "\\\d\d\d\|\\."
syn region  basicString		  start=+"+  skip=+\\\\\|\\"+  end=+"+  contains=basicSpecial

syn region  basicComment        start="/\*" end="\*/" contains=basicTodo
syn region  basicComment	start="REM" end="$" contains=basicTodo
syn region  basicComment	start="'" end="$" contains=basicTodo

syn keyword basicTypeSpecifier	int double float long char short void signed unsigned static extern struct volatile const public private virtual
syn keyword basicTypeSpecifier	intptr_t uintptr_t int8_t uint8_t int16_t uint16_t int32_t uint32_t int64_t uint64_t
syn keyword basicTypeSpecifier  STRING NUMBER FLOATING
syn match   basicTypeSpecifier  "[a-zA-Z0-9]"ms=s+1
syn match   basicMathsOperator   "-\|=\|[:<>+\*^/\\]"

" HUG wrapper functions
syn keyword basicWrapperFunc	INIT HUGOPTIONS QUIT DRAW HIDE SHOW WINDOW DISPLAY TEXT GET VSLIDER
syn keyword basicWrapperFunc	NOTEBOOK BUTTON STOCK TOGGLE CHECK RADIO ENTRY PASSWORD HSLIDER
syn keyword basicWrapperFunc	MARK COMBO HSEPARATOR VSEPARATOR SEPARATOR FRAME EDIT LIST MSGDIALOG SYNC
syn keyword basicWrapperFunc	FILEDIALOG SPIN IMAGE CANVAS CLIPBOARD PROGRESSBAR CALLBACK METHOD
syn keyword basicWrapperFunc	CALLBACKX MOUSE CIRCLE PIXEL LINE SQUARE OUT PICTURE ATTACH REGISTER
syn keyword basicWrapperFunc	TIMEOUT FONT DISABLE ENABLE FOCUS UNFOCUS SCREENSIZE KEY PROPERTY
syn keyword basicWrapperFunc	GETPROPERTY SETPROPERTY RESETKEY WIDGET SLIDER REMOVE
syn match basicWrapperstrFunc	"GRAB\$\|HUGLIB\$\|GETCOLOR$\$\|HUGVERSION\$"

" GMP wrapper functions
syn keyword basicWrapperFunc	INIT PRECISION FCOMPARE ISPRIME
syn match basicWrapperstrFunc	"ADD\$\|SUBSTRACT\$\|MULTIPLY\$\|DIVIDE\$\|MODULO\$\|POWER\$\|SQUARE\$"
syn match basicWrapperstrFunc	"ROOT\$\|FADD\$\|FSUBSTRACT\$\|FMULTIPLY\$\|FDIVIDE\$\|FPOWER\$"
syn match basicWrapperstrFunc	"FIBONACCI\$\|FACTORIAL\$\|NEXTPRIME\$\|FSQUARE\$\|GCD\$"

if version >= 508 || !exists("did_bacon_syntax_inits")
  if version < 508
    let did_bacon_syntax_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif

  hi def link basicFunction		Identifier
  hi def link basicStatement		Statement
  hi def link basicstrFunction		Function
  hi def link basicNumber		Number
  hi def link basicString		String
  hi def link basicComment		Comment
  hi def link basicSpecial		Special
  hi def link basicTodo			Todo
  hi def link basicTypeSpecifier	Type
  hi def link basicWrapperFunc		PreProc
  hi def link basicWrapperstrFunc	PreProc
  hi def link basicConstant		Constant
  hi def link basicstrConstant		Constant
  hi def link basicFilenumber	basicTypeSpecifier
  hi basicMathsOperator term=bold cterm=bold gui=bold

  delcommand HiLink
endif

let b:current_syntax = "bacon"
