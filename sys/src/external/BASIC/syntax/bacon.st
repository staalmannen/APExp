/* 
 * File: Enscript Syntax file for BaCon
 * Name: BaCon
 * Description: Basic Converter syntax highlighting
 * Author: Peter van Eerten <peter@basic-converter.org>
 * Usage: Copy this file to /usr/share/enscript/hl/
 * Date: March 6, 2024
 * 
 *    Console output: enscript --color --tabsize=4 --style=emacs --language=ansi --highlight=bacon prog.bac -p -
 *    HTML output: enscript --color --tabsize=4 --style=emacs --language=html --highlight=bacon prog.bac -p prog.html
 *    RTF output: enscript --color --tabsize=4 --style=emacs --language=rtf --highlight=bacon prog.bac -p prog.rtf
 *    PostScript output: enscript --color --tabsize=4 --style=emacs --highlight=bacon prog.bac -p prog.ps
 */

state bacon extends HighlightEntry
{
  /* Comments. */
  /[\']|REM/ {
    comment_face (true);
    language_print ($0);
    call (eat_one_line);
    comment_face (false);
  }

  /\/\*/ {
    comment_face (true);
    language_print ($0);
    call (c_comment);
    comment_face (false);
  }

  /* String constants. */
  /\"/ {
    string_face (true);
    language_print ($0);
    call (c_string);
    string_face (false);
  }

  /* Pre-processor lines. */
  /^#/ {
    language_print ($0);
    call (c_ppline);
  }

  /* Keywords:
     (build-re '(add alarm alias appending array as assoc baconlib back base bg black blue break broadcast by call
     case catch changedir chunk clear close cmode collapse color const compare compiler continue copy current
     cursor cyan data declare decr default def delete device directory do down downto elif else endfunction endif
     end endselect endsub endusec enduseh endenum endwith enum eprint eq exit fg fi file fn for format forward
     free from function ge getbyte getfile getline global gosub goto gotoxy green gt if imode import in include
     incr input intense international inverse is isnot join label ldflags le let lmode local lookup lt magenta makedir
     map memrewind memstream memtype multicast ne network next normal off offset omode on open option options other
     parse poke pragma print proto pull push putbyte putline reading read readln readwrite receive record
     recursive red redim relate rem rename repeat reset resize restore resume return rewind scroll sctp seed
     seek select send server setenviron setserial size sleep socket sort speed split start startpoint step
     stop sub swap system tcp textdomain then to trace trap type udp until up usec useh var wend whence while
     white with writeln writing yellow))
  */
/\b(ADD|ALARM|ALIAS|APPEND|APPENDING|ARRAY|AS|ASSOC|BACK|BAPPEND|BASE|BG|BLACK|BLINK|BLUE|BOLD|BREAK|BROADCAST|BSAVE|BY|CALL|CASE|CERTIFICATE\
|CATCH|CHANGEDIR|CHUNK|CLASS|CLEAR|CLOSE|CMODE|COLLAPSE|COLOR|CONST|COMPARE|COMPILER|CONTINUE|COPY|CURRENT|CURSOR|CYAN|DATA|DECLARE\
|DOWNTO|DECR|DEFAULT|DEF|DELETE|DEVICE|DIRECTORY|DO|DOWN|DQ|ELIF|ELSE|ENDFUNCTION|ENDRECORD|ENDIF|END|ENDSELECT|ENDSUB|ENDUSEC|ENDUSEH\
|ENDENUM|ENDWITH|ENDFUNC|ENDCLASS|ENUM|EPRINT|EQ|ESC|EXIT|FG|FI|FILE|LDFLAGS|FN|FOR|FORMAT|FORWARD|FREE|FROM|FTYPE|FUNCTION|GE|GETBYTE|FRAMEWORK\
|EXPLICIT|GETFILE|GETLINE|GLOBAL|GOSUB|GOTO|GOTOXY|GREEN|GT|GUI|IF|IMODE|IMPORT|IN|INCLUDE|INCR|INPUT|INTENSE|INTERNATIONAL|PROPER|QUOTED\
|INVERSE|IS|ISNOT|ITALIC|JOIN|LABEL|LE|LET|LIBRARY|LMODE|LOCAL|LOOKUP|LT|MAGENTA|MAKEDIR|MEMREWIND|MEMSTREAM|MEMTYPE|MULTICAST|TREE\
|NE|NETWORK|NEXT|NORMAL|OFF|OFFSET|OMODE|ON|OPEN|OPTION|OPTIONS|OTHER|PARSE|POKE|PRAGMA|PRINT|PROTO|PULL|PUSH|ENDFORK|NO_C_ESC|NODE\
|PUTBYTE|PUTLINE|PRIORITY|READING|READ|READLN|READWRITE|RECEIVE|RECORD|RECURSIVE|RED|REDIM|RELATE|REM|RENAME|REPEAT|RESET|DELIM|COLLECT\
|RESIZE|RESTORE|RESUME|RETURN|REWIND|RUN|SCREEN|SCROLL|SCTP|SEED|SEEK|SELECT|SEND|SERVER|SET|SETENVIRON|SETSERIAL|SIZE|SLEEP|RE|FUNC\
|SOCKET|SORT|SPEED|SPLIT|START|STARTPOINT|STEP|STOP|STRIKE|SUB|SWAP|SYSTEM|TCP|TEXTDOMAIN|THEN|TLS|TO|TRACE|TRAP|TYPE|UDP|SAVE|UNSET\
|UNDERLINE|UNTIL|UP|USEC|USEH|UTF8|VAR|VARTYPE|WEND|WHENCE|WHERE|WHILE|WHITE|WITH|WRITELN|WRITING|YELLOW|MONITOR|SIGNAL|DOTIMES|DONE)\b/ {
    keyword_face (true);
    language_print ($0);
    keyword_face (false);
  }

  /* Functions:
     (build-re '(abs acos address and asc asin atn cmdline columns cos count day dec deg endfile equal error even
     exp fileexists filelen filetime filetype floor fp getkey getx gety hour iif instr instrrev int isfalse iskey
     istrue len log maxnum memcheck memory memtell minute mod month not now odd or peek pow rad random regex
     rnd round rows search second sgn sin sizeof sqr tan tell timer timevalue total val wait week year chop$ chr$
     concat$ curdir$ err$ exec$ extract$ fill$ getenviron$ getpeer$ hex$ host$ hostname$ intl$ lcase$ left$
     mid$ month$ nntl$ os$ replace$ reverse$ right$ spc$ str$ tab$ typeof$ ucase$ weekday$))
  */
/\b(ABS|ACCEPT|ACOS|ADDRESS|AND|ASC|ASIN|ATN|ATN2|BIT|BLOAD|CEIL|CMDLINE|COLUMNS|COS|COUNT|DAY|DEC|DEG|ENDFILE|EQUAL|EVAL|EVEN|EXP|FILEEXISTS\
|FILELEN|FILETIME|FILETYPE|FLOOR|FORK|FP|GETKEY|GETX|GETY|HOUR|IIF|INSTR|INSTRREV|INT|INVERT|ISFALSE|ISKEY|ISTRUE|LEN|LOG|LOOP|MAX|MAXNUM|BETWEEN|HASDELIM\
|HASBOM|MATCH|MEMORY|MEMTELL|MIN|MINUTE|MOD|MONTH|MYPID|NANOTIMER|NOT|NOW|ODD|OR|PEEK|POW|RAD|RANDOM|REAP|REGEX|RND|ROL|ROR|ROUND|ROWS|SEARCH|SECOND|EXCL|HASH|ISUTF8\
|MEMCHECK|SGN|SIN|SIZEOF|SQR|TAN|TALLY|TELL|TIMER|TIMEVALUE|TOTAL|UCS|ULEN|VAL|VERIFY|WAIT|WEEK|YEAR|AMOUNT|ISTOKEN|BYTELEN|ISASCII|SUM|SUMF|NRKEYS|BEYOND\
|GUIDEFINE|GUIGET|GUISET|GUIWIDGET|GUIFN|UBOUND|FIND|INDEX)\b/ {
    function_name_face (true);
    language_print ($0);
    function_name_face (false);
  }

/\b(BASENAME\$|CA\$|CN\$|CHOP\$|CHR\$|CONCAT\$|CURDIR\$|DIRNAME\$|ERR\$|ESCAPE\$|EXEC\$|EXTRACT\$|FILL\$|GETENVIRON\$|GETPEER\$|HEX\$|HOST\$\
|HOSTNAME\$|IIF\$|INTL\$|LCASE\$|LEFT\$|MAX\$|MID\$|MIN\$|MONTH\$|NNTL\$|OS\$|REALPATH\$|REPLACE\$|REVERSE\$|RIGHT\$|RUN\$|CIPHER\$|INDEX\$\
|SPC\$|STR\$|TAB\$|TYPEOF\$|UCASE\$|WEEKDAY\$|INBETWEEN\$|TOKEN\$|LOAD\$|OUTBETWEEN\$|FLATTEN\$|INSERT\$|BIN\$|EXCHANGE\$\|TOASCII\$\
|CHANGE\$|UNFLATTEN\$|UNIQ\$|SORT\$|REV\$|DELIM\$|HEAD\$|TAIL\$|APPEND\$|DEL\$|CUT\$|ALIGN\$|UTF8\$|PROPER\$|ROTATE\$|WALK\$|EDITBOM\$\
|LAST\$|FIRST\$|ME\$|EXPLODE\$|OBTAIN\$|B64ENC\$|B64DEC\$|MERGE\$|RIP\$|LOOP\$|COIL\$|GUIEVENT\$|UNESCAPE\$|COLLAPSE\$)/ {
    function_name_face (true);
    language_print ($0);
    function_name_face (false);
  }

  /* Variables:
     (build-re '(argument$ maxrandom nl$ cr$ el$ pi version$ false true retval reglen))
  */
/\b(FALSE|TRUE|PI|MAXRANDOM|RETVAL|REGLEN|ERROR|LINENO|SP|NULL)\b/ {
    variable_name_face (true);
    language_print ($0);
    variable_name_face (false);
  }

/\b(NL\$|CR\$|DLE\$|EL\$|CL\$|VERSION\$|ARGUMENT\$|SOURCE\$)/ {
    variable_name_face (true);
    language_print ($0);
    variable_name_face (false);
  }

  /* Types:
     (build-re '(NUMBER STRING FLOATING FILE* int double float long char short void signed unsigned static extern))
  */
/\b(NUMBER|STRING|FLOATING|FILE|int|double|float|long|char|short|void|signed|unsigned|static|extern|struct|volatile\
|const|public|private|virtual|number|string|floating|intptr_t|uintptr_t|int8_t|uint8_t|int16_t|uint16_t|int32_t\
uint32_t|int64_t|uint64_t)\b/ {
    type_face (true);
    language_print ($0);
    type_face (false);
  }

  /* HUG */

/\b(INIT|HUGOPTIONS|PROPERTY|GETPROPERTY|SETPROPERTY|QUIT|DRAW|HIDE|SHOW|WINDOW|DISPLAY|REGISTER|METHOD|TEXT\
|GET|NOTEBOOK|BUTTON|STOCK|TOGGLE|CHECK|RADIO|ENTRY|PASSWORD|MARK|COMBO|HSEPARATOR|VSEPARATOR|FRAME|EDIT\
|LIST|MSGDIALOG|FILEDIALOG|SPIN|IMAGE|CANVAS|CLIPBOARD|PROGRESSBAR|CALLBACK|CALLBACKX|MOUSE|CIRCLE|PIXEL|LINE\
|SQUARE|OUT|PICTURE|ATTACH|TIMEOUT|FONT|DISABLE|ENABLE|FOCUS|UNFOCUS|SCREENSIZE|KEY|RESETKEY|WIDGET|SYNC\
|INIT|HSLIDER|VSLIDER|SLIDER|SEPARATOR|REMOVE)\b/ {
    reference_face (true);
    language_print ($0);
    reference_face (false);
  }

/\b(GRAB\$|HUGLIB\$|HUGVERSION\$)/ {
    reference_face (true);
    language_print ($0);
    reference_face (false);
  }
}


/*
Local variables:
mode: c
End:
*/
