/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Parse_Line( char *__b2c_statement) {
    char*statement = NULL; statement = b2c_CopyString(NULL, __b2c_statement); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **element = NULL; long element__b2c_array = 0; char *b2c_select_4250 = NULL; char *b2c_select_4459 = NULL; char *b2c_select_4580 = NULL; int b2c_forin_str_ptr = 0; char* b2c_forin_str_string = NULL; char* b2c_forin_str_string_org = NULL; char* b2c_forin_str_step = NULL; char **match = NULL; long match__b2c_array = 0; int b2c_forin_sym_ptr = 0; char* b2c_forin_sym_string = NULL; char* b2c_forin_sym_string_org = NULL; char* b2c_forin_sym_step = NULL; char *b2c_select_5433 = NULL; char **symbol = NULL; long symbol__b2c_array = 0; int b2c_forin_exp_ptr = 0; char* b2c_forin_exp_string = NULL; char* b2c_forin_exp_string_org = NULL; char* b2c_forin_exp_step = NULL;
    char *inc = NULL;
    char *copy_curfile = NULL;
    char *total = NULL;
    char *txt = NULL;
    char *sym = NULL;
    char *exp = NULL;
    char *then = NULL;
    char *lft = NULL;
    char *str = NULL;
    char *newfeed = NULL;
    char *token = NULL;
    char *rel = NULL;
    char *uniq = NULL;
    long dim = 0;
    long i = 0;
    long found = 0;
    long copy_counter = 0;
    long to_parse = 0;
    long size = 0;
    long trc_backup = 0;
    FILE* newfile = NULL;
    FILE* src_tmp = NULL;
    FILE* src_in = NULL;
    FILE* src_out = NULL;
    b2c_split_by(&element, 1, &element__b2c_array, statement, b2c_option_delim);
    dim = element__b2c_array;
    if( (dim )> 0 ){
        if( ISTRUE(g_USE_C) ){
            if( __b2c__STRCMP(LEFT(statement, 8) ,  "END USEC") == 0  OR  __b2c__STRCMP(element[(uint64_t)1] ,  "ENDUSEC") == 0 ){
                g_USE_C=(long)( 0);
            } else if( __b2c__STRCMP(LEFT(statement, 8) ,  "END ENUM") == 0  OR  __b2c__STRCMP(element[(uint64_t)1] ,  "ENDENUM") == 0 ){
                g_USE_C=(long)( 0);
            fputs("};\n", g_CFILE);
            } else {
            fprintf(g_CFILE, "%s\n", statement);
            }
        } else if( ISTRUE(g_USE_H) ){
            if( REGEX(statement, "END.*USEH") ){
                g_USE_H=(long)( 0);
            } else if( REGEX(statement, "END.*ENUM")  OR  REGEX(statement, "END.*CLASS") ){
                g_USE_H=(long)( 0);
            fputs("};\n", g_HFILE);
            } else {
            fprintf(g_HFILE, "%s\n", statement);
            }
        } else if( __b2c__STRCMP(LEFT(element[(uint64_t)1], 2) ,  "#!") == 0 ){
        } else if( __b2c__STRCMP(LEFT(element[(uint64_t)1], 1) ,  "'") == 0 ){
        } else if( __b2c__STRCMP(RIGHT(element[(uint64_t)dim], 2) ,  "*/") == 0 ){
            g_COMMENT=(long)( FALSE);
        } else if( __b2c__STRCMP(LEFT(element[(uint64_t)1], 2) ,  "/*") == 0 ){
            g_COMMENT=(long)( TRUE);
            } else if( g_COMMENT == FALSE ){
            b2c_select_4250 = b2c_CopyString(b2c_select_4250, element[(uint64_t)1]);
            if ( !b2c_strcmp(b2c_select_4250, "USEC")){
            g_USE_C=(long)( 1);
            } else  if ( !b2c_strcmp(b2c_select_4250, "USEH")){
            g_USE_H=(long)( 1);
            } else  if ( !b2c_strcmp(b2c_select_4250, "CLASS")){
            g_USE_H=(long)( 1);
            fprintf(g_HFILE, "class %s{\n", LAST(statement));
            } else  if ( !b2c_strcmp(b2c_select_4250, "PRINT")){
            Handle_Print(statement, "stdout");
            } else  if ( !b2c_strcmp(b2c_select_4250, "EPRINT")){
            Handle_Print(MID(statement, 2), "stderr");
            } else  if ( !b2c_strcmp(b2c_select_4250, "INPUT")){
            Handle_Input(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "FOR")){
            g_LOOPCTR = g_LOOPCTR + (1);
            Handle_For(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "NEXT")){
            fputs("}\n", g_CFILE);
            if( (g_LOOPCTR )> 0  AND  g_OPTION_BREAK ){
            g_LOOPCTR = g_LOOPCTR - (1);
            if( (g_LOOPCTR )> 0 ){
            fputs("if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }\n", g_CFILE);
            }
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "IF")){
            if( NOT(ISTOKEN(statement, "THEN")) ){
            fprintf(stderr, "%sSyntax error: missing THEN in IF statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            then = F_CHOP(then,LAST(statement, ISTOKEN(statement, "THEN")));
            sym = b2c_CopyString(sym, (char*) HEAD(statement, ISTOKEN(statement, "THEN")-1));
            exp = F_CHOP(exp,LAST(sym, ISTOKEN(sym, "IF")));
            fprintf(g_CFILE, "if(%s){\n", Parse_Equation(exp));
            if( (LEN(then) )> 0 ){
            trc_backup=(
            long)( g_TRACE);
            g_TRACE=(long)( 0);
            Tokenize(then);
            g_TRACE=(long)( trc_backup);
            fputs("}\n", g_CFILE);
            }
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "ELIF")){
            if( NOT(ISTOKEN(statement, "THEN")) ){
            fprintf(stderr, "%sSyntax error: missing THEN in ELIF statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            then = F_CHOP(then,LAST(statement, ISTOKEN(statement, "THEN")));
            sym = b2c_CopyString(sym, (char*) HEAD(statement, ISTOKEN(statement, "THEN")-1));
            exp = F_CHOP(exp,LAST(sym, ISTOKEN(sym, "ELIF")));
            if( (LEN(then) )> 0 ){
            if( g_TRACE == 1 ){
            g_TRACE_PREFIX = F_CONCAT(g_TRACE_PREFIX, "RUNTIMEDEBUG(" , g_CURFILE , ", " , STR(g_COUNTER) , ", \"" , REPLACE(statement, CONCAT( CHR(34) , CHR(92)) , CONCAT( CHR(39) , CHR(47)) , 2) , "\")") ;
            fprintf(g_CFILE, "else if(!(%s)){ ; }\n", g_TRACE_PREFIX);
            }
            fprintf(g_CFILE, "else if(%s){\n", Parse_Equation(exp));
            Tokenize(then);
            fputs("}\n", g_CFILE);
            } else {
            if( g_TRACE == 1 ){
            g_TRACE_PREFIX = F_CONCAT(g_TRACE_PREFIX, "RUNTIMEDEBUG(" , g_CURFILE , ", " , STR(g_COUNTER) , ", \"ELIF " , REPLACE(exp, CONCAT( CHR(34) , CHR(92)) , CONCAT( CHR(39) , CHR(47)) , 2) , "\")") ;
            fprintf(g_CFILE, "} else if(!(%s)){ ;\n", g_TRACE_PREFIX);
            }
            fprintf(g_CFILE, "} else if(%s){\n", Parse_Equation(exp));
            if( g_TRACE == 1 ){
            g_TRACE_PREFIX = b2c_CopyString(g_TRACE_PREFIX, (char*) "");
            }
            }
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "ELSE")){
            exp = F_CHOP(exp,LAST(statement, ISTOKEN(statement, "ELSE")));
            if( (LEN(exp) )> 0 ){
            if( g_TRACE == 1 ){
            g_TRACE_PREFIX = F_CONCAT(g_TRACE_PREFIX, "RUNTIMEDEBUG(" , g_CURFILE , ", " , STR(g_COUNTER) , ", \"" , REPLACE(statement, CONCAT( CHR(34) , CHR(92)) , CONCAT( CHR(39) , CHR(47)) , 2) , "\")") ;
            fprintf(g_CFILE, "else if(!(%s)){ ; }\n", g_TRACE_PREFIX);
            }
            fputs("else {\n", g_CFILE);
            Tokenize(exp);
            fputs("}\n", g_CFILE);
            } else {
            if( g_TRACE == 1 ){
            g_TRACE_PREFIX = F_CONCAT(g_TRACE_PREFIX, "RUNTIMEDEBUG(" , g_CURFILE , ", " , STR(g_COUNTER) , ", \"ELSE\")") ;
            fprintf(g_CFILE, "} else if(!(%s)){ ;\n", g_TRACE_PREFIX);
            }
            fputs("} else {\n", g_CFILE);
            if( g_TRACE == 1 ){
            g_TRACE_PREFIX = b2c_CopyString(g_TRACE_PREFIX, (char*) "");
            }
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "FI")){
            fputs("}\n", g_CFILE);
            } else  if ( !b2c_strcmp(b2c_select_4250, "DOTIMES")){
            if( dim == 1 ){
            fprintf(stderr, "%sSyntax error: empty DOTIMES at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fprintf(g_HFILE, "long __do_times_%s = 0;\n", STR( g_DOTIMES));
            fprintf(g_CFILE, "for(__do_times_%s = 0; __do_times_%s<%s; __do_times_%s++) { _ = __do_times_%s+1;\n", STR( g_DOTIMES), STR( g_DOTIMES), MID(statement, INSTR(statement, "DOTIMES") + 7), STR( g_DOTIMES), STR( g_DOTIMES));
            g_DOTIMES = g_DOTIMES + (1);
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "DO")){
            fputs("{\n", g_CFILE);
            } else  if ( !b2c_strcmp(b2c_select_4250, "DONE")){
            fputs("}\n", g_CFILE);
            } else  if ( !b2c_strcmp(b2c_select_4250, "WHILE")){
            g_LOOPCTR = g_LOOPCTR + (1);
            Handle_While(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "WEND")){
            fputs("}\n", g_CFILE);
            if( (g_LOOPCTR )> 0  AND  g_OPTION_BREAK ){
            g_LOOPCTR = g_LOOPCTR - (1);
            if( (g_LOOPCTR )> 0 ){
            fputs("if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }\n", g_CFILE);
            }
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "BREAK")){
            if( g_OPTION_BREAK ){
            if( (dim )> 1  AND  VAL(MID(statement, INSTR(statement, "BREAK") + 5)) != 0 ){
            fprintf(g_CFILE, "b2c_break_ctr = %s-1; b2c_break_flag = 1;\n", MID(statement, INSTR(statement, "BREAK") + 5));
            }
            fputs("break;\n", g_CFILE);
            } else {
            fprintf(stderr, "%sSyntax error: use of BREAK at line %s in file '%s' was disbaled!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "CONTINUE")){
            if( (dim )> 1  AND  VAL(MID(statement, INSTR(statement, "CONTINUE") + 8)) != 0 ){
            fprintf(g_CFILE, "b2c_break_ctr = %s-1; b2c_break_flag = 2;\n", MID(statement, INSTR(statement, "CONTINUE") + 8));
            }
            if( (VAL(MID(statement, INSTR(statement, "CONTINUE") + 8)) )> 1 ){
            fputs("break;\n", g_CFILE);
            } else {
            fputs("continue;\n", g_CFILE);
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "REPEAT")){
            g_LOOPCTR = g_LOOPCTR + (1);
            fputs("do{\n", g_CFILE);
            } else  if ( !b2c_strcmp(b2c_select_4250,  "UNTIL")){
            if( dim == 1 ){
            fprintf(stderr, "%sSyntax error: empty UNTIL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            exp = b2c_CopyString(exp, (char*) Parse_Equation(MID(statement, INSTR(statement, "UNTIL") + 5) ));
            fprintf(g_CFILE, "} while(!(%s));\n", exp);
            if( (g_LOOPCTR )> 0  AND  g_OPTION_BREAK ){
            g_LOOPCTR = g_LOOPCTR - (1);
            if( (g_LOOPCTR )> 0 ){
            fputs("if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }\n", g_CFILE);
            }
            }
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "LET")){
            Handle_Let(MID(statement, INSTR(statement, "LET") + 3));
            } else  if ( !b2c_strcmp(b2c_select_4250, "SYSTEM")){
            if( dim == 1 ){
            fprintf(stderr, "%sSyntax error: empty SYSTEM at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fprintf(g_CFILE, "RETVAL = system(%s); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }\n", LAST(statement));
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "SLEEP")){
            if( dim == 1 ){
            fprintf(stderr, "%sSyntax error: empty SLEEP at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fprintf(g_CFILE, "usleep(%s*1000);\n", MID(statement, INSTR(statement, "SLEEP") + 5));
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "OPEN")){
            Handle_Open(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "CLOSE")){
            if( (dim )< 3 ){
            fprintf(stderr, "%sSyntax error: empty CLOSE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            exp = b2c_CopyString(exp, (char*) LAST(statement));
            b2c_select_4459 = b2c_CopyString(b2c_select_4459, element[(uint64_t)2]);
            if ( !b2c_strcmp(b2c_select_4459, "FILE")){
            exp = b2c_CopyString(exp, (char*) LAST(exp));
            while( LEN(exp) ){
            token = b2c_CopyString(token, (char*) Mini_Parser(exp));
            fprintf(g_CFILE, "fclose(%s);\n", token);
            exp = F_MID(exp,exp, LEN(token)+2);
            token = F_CHOP(token,token);
            b2c_hash_del(assoc_g_SEMANTIC_OPENCLOSE, token);
            }
            } else  if ( !b2c_strcmp(b2c_select_4459, "DIRECTORY")){
            exp = b2c_CopyString(exp, (char*) LAST(exp));
            while( LEN(exp) ){
            token = b2c_CopyString(token, (char*) Mini_Parser(exp));
            fprintf(g_CFILE, "closedir(%s);\n", token);
            exp = F_MID(exp,exp, LEN(token)+2);
            token = F_CHOP(token,token);
            b2c_hash_del(assoc_g_SEMANTIC_OPENCLOSE, token);
            }
            } else  if ( !b2c_strcmp(b2c_select_4459, "MEMORY")){
            exp = b2c_CopyString(exp, (char*) LAST(exp));
            while( LEN(exp) ){
            token = b2c_CopyString(token, (char*) Mini_Parser(exp));
            fprintf(g_CFILE, "%s = NULL;\n", token);
            exp = F_MID(exp,exp, LEN(token)+2);
            token = F_CHOP(token,token);
            b2c_hash_del(assoc_g_SEMANTIC_OPENCLOSE, token);
            }
            } else  if ( !b2c_strcmp(b2c_select_4459, "LIBRARY")){
            exp = b2c_CopyString(exp, (char*) LAST(exp));
            while( LEN(exp) ){
            token = b2c_CopyString(token, (char*) Mini_Parser(exp));
            fprintf(g_CFILE, "if(b2c_dlopen__pointer_%s != NULL) {dlclose(b2c_dlopen__pointer_%s); b2c_dlopen__pointer_%s = NULL;}\n", EXTRACT(token, "[[:punct:]]", TRUE), EXTRACT(token, "[[:punct:]]", TRUE), EXTRACT(token, "[[:punct:]]", TRUE));
            exp = F_MID(exp,exp, LEN(token)+2);
            token = F_CHOP(token,token);
            }
            } else  if ( !b2c_strcmp(b2c_select_4459, "NETWORK") || !b2c_strcmp(b2c_select_4459, "SERVER") || !b2c_strcmp(b2c_select_4459, "UDP") || !b2c_strcmp(b2c_select_4459, "DEVICE")){
            exp = b2c_CopyString(exp, (char*) LAST(exp));
            while( LEN(exp) ){
            token = b2c_CopyString(token, (char*) Mini_Parser(exp));
            if( g_OPTION_TLS ){
            if( NOT(TALLY(g_LIB_TLS, "gnutls")) ){
            fprintf(g_CFILE, "if(fcntl((uintptr_t)%s,F_GETFL,0) == -1 && errno == EBADF) { close(SSL_get_fd((SSL*)(uintptr_t)%s));\n", token, token);
            fprintf(g_CFILE, "SSL_CTX_free(SSL_get_SSL_CTX((SSL*)(uintptr_t)%s)); SSL_shutdown((SSL*)(uintptr_t)%s);\n", token, token);
            fprintf(g_CFILE, "SSL_free((SSL*)(uintptr_t)%s); } else { close((uintptr_t)%s); }\n", token, token);
            } else {
            fprintf(g_CFILE, "if(fcntl((uintptr_t)%s,F_GETFL,0) == -1 && errno == EBADF) { BIO_get_fd( ((SSL*)(uintptr_t)%s)->gnutls_state, &b2c_counter);\n", token, token);
            fprintf(g_CFILE, "close(b2c_counter); free(((SSL*)(uintptr_t)%s)->ctx->certfile); free(((SSL*)(uintptr_t)%s)->ctx->keyfile);\n", token, token);
            fprintf(g_CFILE, "SSL_CTX_free(((SSL*)(uintptr_t)%s)->ctx); SSL_shutdown((SSL*)(uintptr_t)%s); SSL_free((SSL*)(uintptr_t)%s); gnutls_global_deinit(); }\n", token, token, token);
            fprintf(g_CFILE, "else { close((uintptr_t)%s); }\n", token);
            }
            } else {
            fprintf(g_CFILE, "shutdown((uintptr_t)%s, SHUT_RDWR);\n", token);
            fprintf(g_CFILE, "close((uintptr_t)%s);\n", token);
            }
            exp = F_MID(exp,exp, LEN(token)+2);
            token = F_CHOP(token,token);
            b2c_hash_del(assoc_g_SEMANTIC_OPENCLOSE, token);
            }
            } else {
            fprintf(stderr, "%sSyntax error: erroneous CLOSE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            }
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "REWIND")){
            if( dim == 1 ){
            fprintf(stderr, "%sSyntax error: empty REWIND at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fprintf(g_CFILE, "rewind(%s);\n", element[(uint64_t)2]);
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "MEMREWIND")){
            if( dim == 1 ){
            fprintf(stderr, "%sSyntax error: empty MEMREWIND at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fprintf(g_CFILE, "%s = (char*)__b2c_mem_%s;\n", element[(uint64_t)2], element[(uint64_t)2]);
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "SEEK")){
            Handle_Seek(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "READLN")){
            Handle_Readln(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "WRITELN")){
            Handle_Writeln(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "GETBYTE")){
            Handle_Getbyte(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "PUTBYTE")){
            Handle_Putbyte(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "GETFILE")){
            Handle_Getfile(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "GETLINE")){
            Handle_Getline(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "PUTLINE")){
            Handle_Putline(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "END") || !b2c_strcmp(b2c_select_4250, "ENDIF") || !b2c_strcmp(b2c_select_4250, "ENDSUB") || !b2c_strcmp(b2c_select_4250, "ENDFUNC") || !b2c_strcmp(b2c_select_4250, "ENDWITH") || !b2c_strcmp(b2c_select_4250, "ENDFORK") || !b2c_strcmp(b2c_select_4250, "ENDRECORD") || !b2c_strcmp(b2c_select_4250, "ENDSELECT") || !b2c_strcmp(b2c_select_4250, "ENDFUNCTION")){
            exp = b2c_CopyString(exp, (char*) IIF((dim )> 1, element[(uint64_t)2], MID(element[(uint64_t)1], 4)));
            b2c_select_4580 = b2c_CopyString(b2c_select_4580, exp);
            if ( !b2c_strcmp(b2c_select_4580, "IF")){
            fputs("}\n", g_CFILE);
            } else  if ( !b2c_strcmp(b2c_select_4580, "RECORD")){
            if( (LEN(g_FUNCNAME) )> 0 ){
            fprintf(g_CFILE, "}%s;\n", g_RECORDNAME);
            fprintf(g_CFILE, "typedef %s %s_type;\n", g_RECORDNAME, EXTRACT(g_RECORDNAME, "_TYPE"));
            if( LEN(g_RECORDARRAY) ){
            fprintf(g_CFILE, "%s *%s = (%s*)calloc(%s+%s, sizeof(%s));\n", g_RECORDNAME, LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1), g_RECORDNAME, g_RECORDARRAY, STR( g_OPTION_BASE), g_RECORDNAME);
            g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1)) ;
            g_RECORDEND_BODY = F_CONCAT(g_RECORDEND_BODY, " long __b2c_record_" , EXTRACT(g_RECORDNAME, "_TYPE") , " = " , g_RECORDARRAY , "+" , STR(g_OPTION_BASE) , ";" , g_RECORDEND_BODY) ;
            } else {
            fprintf(g_CFILE, "%s %s = { 0 } ;\n", g_RECORDNAME, REPLACE(g_RECORDVAR, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
            }
            } else {
            fprintf(g_HFILE, "}%s;\n", g_RECORDNAME);
            fprintf(g_HFILE, "typedef %s %s_type;\n", g_RECORDNAME, EXTRACT(g_RECORDNAME, "_TYPE"));
            if( LEN(g_RECORDARRAY) ){
            fprintf(g_HFILE, "%s *%s;\n", g_RECORDNAME, LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1));
            fprintf(g_CFILE, "%s = (%s*)calloc(%s+%s, sizeof(%s));\n", LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1), g_RECORDNAME, g_RECORDARRAY, STR( g_OPTION_BASE), g_RECORDNAME);
            g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , "free(" , LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1) , ");") ;
            fprintf(g_HFILE, "%s\n", CONCAT( "long __b2c_record_" , EXTRACT(g_RECORDNAME, "_TYPE") , ";" ));
            g_RECORDEND_BODY = F_CONCAT(g_RECORDEND_BODY, g_RECORDEND_BODY , " __b2c_record_" , EXTRACT(g_RECORDNAME, "_TYPE") , " = " , g_RECORDARRAY , "+" , STR(g_OPTION_BASE) , ";") ;
            } else {
            fprintf(g_HFILE, "%s %s = { 0 } ;\n", g_RECORDNAME, REPLACE(g_RECORDVAR, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
            }
            fprintf(g_HFILE, "%s\n", g_RECORDEND_HEADER);
            }
            fprintf(g_CFILE, "%s\n", g_RECORDEND_BODY);
            g_RECORDNAME = b2c_CopyString(g_RECORDNAME, (char*) "");
            g_RECORDVAR = b2c_CopyString(g_RECORDVAR, (char*) "");
            g_RECORDEND_BODY = b2c_CopyString(g_RECORDEND_BODY, (char*) "");
            g_RECORDEND_HEADER = b2c_CopyString(g_RECORDEND_HEADER, (char*) "");
            g_RECORDARRAY = b2c_CopyString(g_RECORDARRAY, (char*) "");
            if( (LEN(g_RECORDCACHE) )> 0 ){
            g_FUNCNAME = b2c_CopyString(g_FUNCNAME, (char*) g_RECORDCACHE);
            g_RECORDCACHE = b2c_CopyString(g_RECORDCACHE, (char*) "");
            }
            } else  if ( !b2c_strcmp(b2c_select_4580, "FUNC") || !b2c_strcmp(b2c_select_4580,  "FUNCTION")){
            Handle_Endfunction();
            } else  if ( !b2c_strcmp(b2c_select_4580, "SUB")){
            Handle_Endsub();
            } else  if ( !b2c_strcmp(b2c_select_4580, "WITH")){
            g_WITHVAR = b2c_CopyString(g_WITHVAR, (char*) "");
            } else  if ( !b2c_strcmp(b2c_select_4580, "SELECT")){
            if( g_SELECTVAR_CTR == 0 ){
            fprintf(stderr, "%sSyntax error: invalid END SELECT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fputs("}\n", g_CFILE);
            g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR] = b2c_CopyString(g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR], (char*) "");
            g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 0;
            g_CASE_FALL = b2c_CopyString(g_CASE_FALL, (char*) "");
            g_CASE_CONT = b2c_CopyString(g_CASE_CONT, (char*) "");
            g_SELECTVAR_CTR = g_SELECTVAR_CTR - (1);
            }
            } else  if ( !b2c_strcmp(b2c_select_4580, "FORK")){
            if( g_DEBUG == 1 ){
            fputs("__b2c_str_realloc_debug_string();\n", g_CFILE);
            fputs("__b2c_mempool_realloc_debug();\n", g_CFILE);
            }
            fputs("__b2c_str_free();\n", g_CFILE);
            if( (dim )> 2 ){
            fprintf(g_CFILE, "_exit(%s);\n", MID(statement, INSTR(statement, "FORK")+4));
            } else {
            fputs("_exit(EXIT_SUCCESS);\n", g_CFILE);
            }
            } else {
            if( g_DEBUG == 1 ){
            fputs("__b2c_str_realloc_debug_string();\n", g_CFILE);
            fputs("__b2c_mempool_realloc_debug();\n", g_CFILE);
            }
            fprintf(g_CFILE, "exit(%s);\n", IIF((dim )> 1, MID(statement, INSTR(statement, "END")+3), "EXIT_SUCCESS"));
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "SUB")){
            Handle_SubFunc(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "CALL")){
            Handle_Call(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "FUNCTION")){
            Handle_SubFunc(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "FUNC")){
            Handle_SubFunc(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "RETURN")){
            Handle_Return(MID(statement, INSTR(statement, "RETURN") + 6));
            } else  if ( !b2c_strcmp(b2c_select_4250, "IMPORT")){
            Handle_Import(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "DECLARE")){
            Handle_Declare(MID(statement, INSTR(statement, "DECLARE") + 7));
            } else  if ( !b2c_strcmp(b2c_select_4250, "GLOBAL")){
            Handle_Declare(MID(statement, INSTR(statement, "GLOBAL") + 6));
            } else  if ( !b2c_strcmp(b2c_select_4250, "LOCAL")){
            Handle_Local(MID(statement, INSTR(statement, "LOCAL") + 5));
            } else  if ( !b2c_strcmp(b2c_select_4250, "DATA")){
            Handle_Data(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "RESTORE")){
            if( dim == 1 ){
            fputs("b2c_floatarray_ptr = 0;\n", g_CFILE);
            fputs("b2c_stringarray_ptr = 0;\n", g_CFILE);
            } else {
            fprintf(g_CFILE, "b2c_floatarray_ptr = b2c_label_floatarray_%s;\n", element[(uint64_t)2]);
            fprintf(g_CFILE, "b2c_stringarray_ptr = b2c_label_stringarray_%s;\n", element[(uint64_t)2]);
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "READ")){
            Handle_Read(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "PUSH")){
            Handle_Push(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "PULL")){
            Handle_Pull(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "SEED")){
            if( dim == 1 ){
            fprintf(stderr, "%sSyntax error: empty SEED at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fprintf(g_CFILE, "srandom((unsigned int)%s);\n", MID(statement, INSTR(statement, " ")+1));
            }
            } else  if ( !b2c_strcmp(b2c_select_4250, "DEF")){
            Handle_Deffn(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "CONST")){
            Handle_Const(statement);
            } else  if ( !b2c_strcmp(b2c_select_4250, "INCLUDE")){
            inc = b2c_CopyString(inc, (char*) EXTRACT((CHOP(MID(statement, INSTR(statement, " ") + 1))), CHR(34)));
            if( INSTR(inc, ",") ){
            b2c_split_by(&element, 1, &element__b2c_array, MID(inc, INSTR(inc, ",")+1), ",");
            size = element__b2c_array;
            for(i=1; i <= size; i+=1){
            element[(uint64_t)i] = b2c_CopyString(element[(uint64_t)i], (char*) EXTRACT(element[(uint64_t)i], g_STRINGSIGN));
            }
            inc = F_MID(inc,inc, 1, INSTR(inc, ",")-1);
            } else {
            to_parse=(
            long)( 2);
            }
            if( __b2c__STRCMP(RIGHT(inc, 4) ,  ".bac") != 0 ){
            inc = F_CONCAT(inc, inc , ".bac");
            }
            if( NOT(FILEEXISTS(inc))  OR  dim == 1  OR  (FILETYPE(inc) != 1  AND  FILETYPE(inc) != 6) ){
            fprintf(stderr, "%sSystem error: missing file '%s' for INCLUDE at line %s in file '%s'!\n", NL, inc, STR( g_COUNTER), g_CURFILE);
            exit(1);
            } else {
            fprintf(stdout, "%s%s", CR, EL);
            fflush(stdout);
            if( ISTRUE(g_CPP) ){
            if( ISTRUE(LEN(EXEC("command -v cpp 2>/dev/null"))) ){
            fprintf(stdout, "Preprocessing '%s'... ", inc);
            fflush(stdout);
            src_tmp = fopen((const char*)CONCAT( inc , ".tmp" ), "w");
            if(src_tmp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 4747, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            src_in = fopen((const char*)inc, "r");
            if(src_in == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 4748, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            while( NOT(ENDFILE(src_in)) ){
            b2c_readln(&b2c_assign, src_in);
            txt = b2c_CopyString(txt, b2c_assign);
            __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
            if( __b2c__STRCMP(LEFT(txt, 1) ,  "#") == 0 ){
            fprintf(src_tmp, "%s\n", txt);
            } else {
            fprintf(src_tmp, "%s\n", CONCAT( "@" , txt , "@" ));
            }
            }
            fclose(src_in);
            fclose( src_tmp);
            RETVAL = system(CONCAT( "cpp -P -w " , inc , ".tmp " , inc , ".cpp") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
            src_cpp = fopen((const char*)CONCAT( inc , ".cpp" ), "r");
            if(src_cpp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 4760, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            src_out = fopen((const char*)CONCAT( inc , ".bac2" ), "w");
            if(src_out == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 4761, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            while( NOT(ENDFILE(src_cpp)) ){
            b2c_readln(&b2c_assign, src_cpp);
            txt = b2c_CopyString(txt, b2c_assign);
            __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
            fprintf(src_out, "%s\n", MID(txt, 2, LEN(txt)-2));
            }
            fclose(src_out);
            fclose( src_cpp);
            newfeed = F_CONCAT(newfeed, inc , ".bac2") ;
            g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , inc , ".cpp" , " " , inc , ".tmp" , " " , inc , ".bac2") ;
            fputs("done.\n", stdout);
            } else {
            fputs("System error: the C Preprocessor 'cpp' not found on this system! Exiting...\n", stderr);
            exit(1);
            }
            } else {
            newfeed = b2c_CopyString(newfeed, (char*) inc);
            }
            g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , inc) ;
            copy_counter=(
            long)( g_COUNTER);
            g_COUNTER=(long)( 1);
            copy_curfile = b2c_CopyString(copy_curfile, (char*) g_CURFILE);
            g_CURFILE = b2c_CopyString(g_CURFILE, (char*) newfeed);
            newfile = fopen((const char*)newfeed, "r");
            if(newfile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 4786, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            do{
            b2c_readln(&b2c_assign, newfile);
            txt = b2c_CopyString(txt, b2c_assign);
            __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
            txt = F_CHOP(txt,txt);
            if( (size )> 0 ){
            for(i=1; i <= size; i+=1){
            if( ( to_parse == 0  AND  REGEX(CHOP(MID(txt, INSTR(txt, " "))), CONCAT( "^" , CHOP(element[(uint64_t)i])) )  AND  REGEX(txt, "SUB|FUNCTION") )  OR  REGEX(txt, "INCLUDE$") ){
            to_parse=(
            long)( 1);
            break;
            }
            }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
            }
            if( (LEN(txt) )> 0  AND  (to_parse )> 0 ){
            if( NOT(g_QUIET) ){
            fprintf(stdout, "\rConverting '%s'... %s%s", newfeed, STR( g_COUNTER), EL);
            fflush(stdout);
            }
            if( __b2c__STRCMP(RIGHT(txt, 2) ,  " \\") == 0  AND  __b2c__STRCMP(LEFT(txt, 1) ,  CHR(39)) != 0  AND  NOT(REGEX(line, "^REM[[:space:]]+")) ){
            total = F_CONCAT(total, total , LEFT(txt, LEN(txt)-1)) ;
            } else {
            total = F_CONCAT(total, total , txt) ;
            if( __b2c__STRCMP(LEFT(total, 1) ,  CHR(39)) != 0 ){
            if( g_DEBUG ){
            fprintf(g_CFILE, "/* line %s \"%s\" */\n", STR( g_COUNTER), newfeed);
        fprintf(g_HFILE, "/* line %s \"%s\" */\n", STR( g_COUNTER), newfeed);
        } else {
        fprintf(g_CFILE, "#line %s \"%s\"\n", STR( g_COUNTER), newfeed);
        fprintf(g_HFILE, "#line %s \"%s\"\n", STR( g_COUNTER), newfeed);
        }
        Tokenize(total);
        total = b2c_CopyString(total, (char*) EXTRACT(total, "\\\\"));
        total = b2c_CopyString(total, (char*) EXTRACT(total, "\\\""));
        g_DEPEND = F_CONCAT(g_DEPEND, g_DEPEND , EXTRACT(total, "\"[^\"]*\"", TRUE) , NL) ;
    }
    total = b2c_CopyString(total, (char*) "");
}
}
if( to_parse == 1  AND  INSTR(txt, "END")  AND  REGEX(txt, "SUB|FUNCTION") ){
    to_parse=(
    long)( 0);
}
g_COUNTER = g_COUNTER + (1);
} while(!( ENDFILE(newfile) ));
fclose(newfile);
g_TOTAL_LINES = g_TOTAL_LINES + ( g_COUNTER);
g_COUNTER=(long)( copy_counter);
g_CURFILE = b2c_CopyString(g_CURFILE, (char*) copy_curfile);
fprintf(g_CFILE, "b2c_stringarray_ptr = %s;\n", STR( g_CCTR));
fprintf(g_CFILE, "b2c_floatarray_ptr = %s;\n", STR( g_FCTR));
}
} else  if ( !b2c_strcmp(b2c_select_4250, "POKE")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty POKE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    exp = F_MID(exp,statement, INSTR(statement, "POKE") + 4);
    if( TALLY(exp, " SIZE ") ){
        str = b2c_CopyString(str, (char*) TOKEN(exp, 2, " SIZE "));
        exp = b2c_CopyString(exp, (char*) TOKEN(exp, 1, " SIZE "));
        token = b2c_CopyString(token, (char*) Mini_Parser(exp));
        exp = F_MID(exp,exp, LEN(token)+2);
    fprintf(g_CFILE, "if(!b2c_memory__check((char*)%s%s%s, \"%s\", ERROR, %s); }\n", token, CONCAT( ", (" , str , ")*sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"POKE\", "), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    fprintf(g_CFILE, "%s\n", CONCAT( "memset((void*)(__b2c__MEMTYPE*)(" , token , "), " , exp , ", (" , str , ")*sizeof(__b2c__MEMTYPE));" ));
    } else {
        token = b2c_CopyString(token, (char*) Mini_Parser(exp));
        exp = F_MID(exp,exp, LEN(token)+2);
    fprintf(g_CFILE, "if(!b2c_memory__check((char*)%s, sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"POKE\", %s, \"%s\", ERROR, %s); }\n", token, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    fprintf(g_CFILE, "*(__b2c__MEMTYPE*)(%s) = ( __b2c__MEMTYPE)(%s);\n", token, exp);
    }
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "RESIZE")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty RESIZE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    exp = F_MID(exp,statement, INSTR(statement, "RESIZE") + 6);
    lft = F_CHOP(lft,TOKEN(exp, 1, " TO "));
    str = F_CHOP(str,TOKEN(exp, 2, " TO "));
fprintf(g_CFILE, "if(!b2c_memory__check((char*)%s, sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"RESIZE\", %s, \"%s\", ERROR, %s); }\n", lft, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
fprintf(g_CFILE, "%s = (%s)realloc((void*)%s, sizeof(__b2c__MEMTYPE)*(%s+1));\n", lft, Get_Var(EXTRACT(lft, "."), g_FUNCNAME), lft, str);
fprintf(g_CFILE, "if((void*)%s == NULL) { ERROR=6; RUNTIMEERROR(\"RESIZE\", %s, \"%s\", ERROR, %s); }\n", lft, STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "COPY")){
Handle_Copy(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "DELETE")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty DELETE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "FILE") == 0 ){
    fprintf(g_CFILE, "if(unlink(%s)==-1){ ERROR = 7; RUNTIMEERROR(\"DELETE\", %s, \"%s\", ERROR, %s); }\n", MID(statement, INSTR(statement, " FILE ") + 6), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
            g_CATCH_USED=(long)( 1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "DIRECTORY") == 0 ){
    fprintf(g_CFILE, "if(rmdir(%s) == -1){ ERROR = 20; RUNTIMEERROR(\"DELETE\", %s, \"%s\", ERROR, %s); }\n", MID(statement, INSTR(statement, " DIRECTORY ") + 11), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
            g_CATCH_USED=(long)( 1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "RECURSIVE") == 0 ){
    fprintf(g_CFILE, "b2c_rmrecursive(__LINE__, __FILE__, %s);\n", MID(statement, INSTR(statement, " RECURSIVE ") + 11));
    } else if( ISTOKEN(statement, "FROM") ){
        sym = F_CHOP(sym,LAST(statement, ISTOKEN(statement, "FROM")));
        exp = b2c_CopyString(exp, (char*) HEAD(statement, ISTOKEN(statement, "FROM")-1));
        exp = b2c_CopyString(exp, (char*) LAST(exp, ISTOKEN(exp, "DELETE")));
        txt = b2c_CopyString(txt, (char*) Get_Var( CONCAT("b2c_tree_" , sym) , g_FUNCNAME));
        uniq = F_CONCAT(uniq, "__b2c__" , sym , "_" , STR(g_COUNTER) , "_" , STR(RND)) ;
        if( __b2c__STRCMP(TOKEN(txt, 2, ":") ,  "char*") == 0 ){
        fprintf(g_CFILE, "char *%s = %s; b2c_assign2 = tfind((void*)%s, &%s, %s); if(b2c_assign2) { b2c_assign = *b2c_assign2; tdelete((void*)%s, &%s, %s); __b2c__STRFREE(b2c_assign); }\n", uniq, exp, uniq, sym, TOKEN(txt, 1, ":"), uniq, sym, TOKEN(txt, 1, ":"));
        } else {
        fprintf(g_CFILE, "%s *%s = (%s*)malloc(sizeof(%s)); *%s = (%s)%s; b2c_assign2 = tfind((void*)%s, &%s, %s); if(b2c_assign2) { b2c_assign = *b2c_assign2; tdelete((void*)%s, &%s, %s); free(b2c_assign); } free(%s);\n", TOKEN(txt, 2, ":"), uniq, TOKEN(txt, 2, ":"), TOKEN(txt, 2, ":"), uniq, TOKEN(txt, 2, ":"), exp, uniq, sym, TOKEN(txt, 1, ":"), uniq, sym, TOKEN(txt, 1, ":"), uniq);
        }
    } else {
    fprintf(stderr, "%sSyntax error: erronuous argument for DELETE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "RENAME")){
Handle_Rename(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "MAKEDIR")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty MAKEDIR at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
fprintf(g_CFILE, "ERROR = b2c_makedir(%s); if(ERROR){ RUNTIMEERROR(\"MAKEDIR\", %s, \"%s\", ERROR, %s); }\n", LAST(statement), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "CHANGEDIR")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty CHANGEDIR at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
fprintf(g_CFILE, "if(%s == NULL || chdir(%s) == -1){ ERROR = 22; RUNTIMEERROR(\"CHANGEDIR\", %s, \"%s\", ERROR, %s); }\n", LAST(statement), LAST(statement), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "FREE")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty FREE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( REGEX(statement, "[a-zA-Z]+\\(.*\\)$") ){
        exp = b2c_CopyString(exp, (char*) LAST(statement));
        while( LEN(exp) ){
            token = F_CHOP(token,LEFT(exp, INSTR(exp, "(")-1));
            str = F_CHOP(str,Mini_Parser(exp));
            txt = F_MID(txt,str, INSTR(str, "(")+1);
        fprintf(g_CFILE, "b2c_hash_del(assoc_%s, %s);\n", token, LEFT(txt, LEN(txt)-1));
            exp = F_MID(exp,exp, LEN(str)+2);
        }
    } else {
        b2c_forin_str_string = b2c_CopyString(b2c_forin_str_string, EXTRACT(LAST(statement), " ")); b2c_forin_str_string_org = b2c_forin_str_string;
        b2c_forin_str_step = b2c_CopyString(b2c_forin_str_step, ",");
        b2c_forin_str_ptr = b2c_for_amount(b2c_forin_str_string, b2c_forin_str_step);
        for(; b2c_forin_str_ptr > 0; b2c_forin_str_ptr--) { b2c_for_item(&b2c_forin_str_string_org, b2c_forin_str_step, &str);
            if( LEN(Get_Var( CONCAT("assoc_" , str) ))  OR  LEN(Get_Var( CONCAT("assoc_" , str) , g_FUNCNAME)) ){
            fprintf(g_CFILE, "b2c_hash_clear(assoc_%s);\n", str);
            } else {
            fprintf(g_CFILE, "if(!b2c_memory__check((char *)%s, sizeof(__b2c__MEMTYPE)))\n", str);
            fprintf(g_CFILE, "{ ERROR=1; RUNTIMEERROR(\"FREE\", %s, \"%s\", ERROR, %s); } free((void*)%s);\n", STR( g_COUNTER), g_CURFILE, g_CATCHGOTO, str);
                b2c_hash_del(assoc_g_SEMANTIC_MEMFREE, str);
            }
        }
        if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
            g_CATCH_USED=(long)( 1);
        }
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "ON")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty ON at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else if( NOT(ISTOKEN(statement, "GOTO"))  AND  NOT(INSTR(statement, "CALL")) ){
fprintf(stderr, "%sSyntax error: ON without CALL/GOTO at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(statement), CONCAT( "ON * " , IIF(ISTOKEN(statement, "CALL"), "CALL", "GOTO") , " *" ), b2c_option_delim);
    i=(
    long)( 1);
fprintf(g_CFILE, "switch(%s){\n", match[(uint64_t)1]);
    while( LEN(match[(uint64_t)2]) ){
        token = b2c_CopyString(token, (char*) Mini_Parser(match[(uint64_t)2]));
        if( ISTOKEN(statement, "GOTO") ){
        fprintf(g_CFILE, "case %s: goto %s; break;\n", STR( i), token);
        } else {
            if( NOT(REGEX(token, "\\(.*\\)$")) ){
            fprintf(g_CFILE, "case %s: %s(); break;\n", STR( i), token);
            } else {
            fprintf(g_CFILE, "case %s: %s; break;\n", STR( i), token);
            }
        }
        match[(uint64_t)2] = F_MID(match[(uint64_t)2],match[(uint64_t)2], LEN(token)+2);
        i = i + (1);
    }
fputs("}\n", g_CFILE);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "GOTO")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty GOTO at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
fprintf(g_CFILE, "goto %s;\n", element[(uint64_t)2]);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "GOSUB")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty GOSUB at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
fprintf(g_CFILE, "b2c_gosub_buffer_ptr++; if (b2c_gosub_buffer_ptr >= %s) { ERROR=31; RUNTIMEERROR(\"GOSUB\", %s, \"%s\", ERROR, %s); }\n", STR( g_MAX_RBUFFERS), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
fprintf(g_CFILE, "if(!setjmp(b2c_gosub_buffer[b2c_gosub_buffer_ptr])) goto %s;\n", element[(uint64_t)2]);
fputs("b2c_gosub_buffer_ptr--; if(b2c_gosub_buffer_ptr < -1) b2c_gosub_buffer_ptr = -1;\n", g_CFILE);
    if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
        g_CATCH_USED=(long)( 1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "LABEL")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty LABEL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
fprintf(g_CFILE, "%s:\n", element[(uint64_t)2]);
fputs(";\n", g_CFILE);
fprintf(g_HFILE, "#undef b2c_label_floatarray_%s \n", element[(uint64_t)2]);
fprintf(g_HFILE, "#define b2c_label_floatarray_%s %s\n", element[(uint64_t)2], STR( g_FCTR));
fprintf(g_HFILE, "#undef b2c_label_stringarray_%s \n", element[(uint64_t)2]);
fprintf(g_HFILE, "#define b2c_label_stringarray_%s %s\n", element[(uint64_t)2], STR( g_CCTR));
}
} else  if ( !b2c_strcmp(b2c_select_4250, "TRAP")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty TRAP at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "LOCAL") == 0 ){
    fputs("/* Error catching is enabled */\n", g_CFILE);
    fputs("b2c_trap = 1;\n", g_CFILE);
    fputs("signal(SIGILL, b2c_catch_signal);\n", g_CFILE);
    fputs("signal(SIGABRT, b2c_catch_signal);\n", g_CFILE);
    fputs("signal(SIGFPE, b2c_catch_signal);\n", g_CFILE);
    fputs("signal(SIGSEGV, b2c_catch_signal);\n", g_CFILE);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "SYSTEM") == 0 ){
    fputs("/* Error catching is disabled */\n", g_CFILE);
    fputs("b2c_trap = 0;\n", g_CFILE);
    fputs("signal(SIGILL, SIG_DFL);\n", g_CFILE);
    fputs("signal(SIGABRT, SIG_DFL);\n", g_CFILE);
    fputs("signal(SIGFPE, SIG_DFL);\n", g_CFILE);
    fputs("signal(SIGSEGV, SIG_DFL);\n", g_CFILE);
    } else {
    fprintf(stderr, "%sSyntax error: invalid argument for TRAP at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "CATCH")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty CATCH at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else if( __b2c__STRCMP(element[(uint64_t)2] ,  "GOTO") == 0 ){
fputs("b2c_catch_set = 1;\n", g_CFILE);
    g_CATCHGOTO = b2c_CopyString(g_CATCHGOTO, (char*) element[(uint64_t)3]);
} else if( __b2c__STRCMP(element[(uint64_t)2] ,  "ERROR") == 0 ){
fprintf(g_CFILE, "b2c_error_callback = & %s;\n", element[(uint64_t)3]);
} else if( __b2c__STRCMP(element[(uint64_t)2] ,  "RESET") == 0 ){
fputs("b2c_catch_set = 0;\n", g_CFILE);
    g_CATCHGOTO = b2c_CopyString(g_CATCHGOTO, (char*) "__B2C__PROGRAM__EXIT");
} else {
fprintf(stderr, "%sSyntax error: CATCH without GOTO or RESET at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "RESUME")){
fputs("if(jmp_buf_is_used(b2c_jump)) { longjmp(b2c_jump, 1); }\n", g_CFILE);
} else  if ( !b2c_strcmp(b2c_select_4250, "CLEAR")){
fputs("fprintf(stdout,\"\\033[2J\"); fprintf(stdout,\"\\033[0;0f\");fflush(stdout);\n", g_CFILE);
} else  if ( !b2c_strcmp(b2c_select_4250, "COLOR")){
Handle_Color(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "TYPE")){
Handle_Type(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "SCREEN")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty SCREEN at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "SAVE") == 0 ){
    fputs("fprintf(stdout,\"\\033[?47h\"); fflush(stdout);\n", g_CFILE);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "RESTORE") == 0 ){
    fputs("fprintf(stdout,\"\\033[?47l\"); fflush(stdout);\n", g_CFILE);
    } else {
    fprintf(stderr, "%sSyntax error: invalid argument for SCREEN at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "GOTOXY")){
Handle_Gotoxy(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "RECEIVE")){
Handle_Receive(CHOP(MID(statement, INSTR(statement, "RECEIVE") + 7)));
} else  if ( !b2c_strcmp(b2c_select_4250, "SEND")){
Handle_Send(MID(statement, INSTR(statement, "SEND") + 4));
} else  if ( !b2c_strcmp(b2c_select_4250, "RECORD")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty RECORD at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else if( ISTRUE(LEN(g_RECORDNAME)) ){
fprintf(stderr, "%sSyntax error: cannot define a record within a record!\n", NL);
    exit(1);
} else {
    g_RECORDVAR = F_MID(g_RECORDVAR,statement, INSTR(statement, "RECORD")+6);
    if( INSTR(g_RECORDVAR, " ARRAY ") ){
        g_RECORDARRAY = F_MID(g_RECORDARRAY,g_RECORDVAR, INSTR(g_RECORDVAR, "ARRAY")+5);
        g_RECORDVAR = F_CONCAT(g_RECORDVAR, CHOP(LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "ARRAY")-1)) , "[" , g_RECORDARRAY , "]") ;
    }
    if( ISTRUE(LEN(g_FUNCNAME)) ){
        g_RECORDNAME = F_CONCAT(g_RECORDNAME, LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1) , "_TYPE") ;
    fputs("typedef struct {\n", g_CFILE);
        Save_Func_Var("", g_FUNCNAME, g_RECORDNAME);
    } else {
        g_RECORDNAME = F_CONCAT(g_RECORDNAME, LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1) , "_TYPE") ;
    fputs("typedef struct {\n", g_HFILE);
        Save_Main_Var("", g_RECORDNAME);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "WITH")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty WITH at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else if( ISTRUE(LEN(g_RECORDNAME)) ){
fprintf(stderr, "%sSyntax error: cannot define a WITH within a WITH!\n", NL);
    exit(1);
} else {
    g_WITHVAR = b2c_CopyString(g_WITHVAR, (char*) element[(uint64_t)2]);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "SPLIT")){
Handle_Split(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "JOIN")){
Handle_Join(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "SELECT")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty SELECT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    g_SELECTVAR_CTR = g_SELECTVAR_CTR + (1);
    if( Check_String_Type(MID(statement, INSTR(statement, "SELECT") + 6)) ){
        g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR] = F_CONCAT(g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR], "b2c_select_" , STR(g_COUNTER) , g_STRINGSIGN) ;
        if( LEN(g_FUNCNAME) ){
            g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " char* " , g_SELECTVAR[g_SELECTVAR_CTR] , " = NULL;") ;
            g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , g_SELECTVAR[g_SELECTVAR_CTR]) ;
        } else {
        fprintf(g_HFILE, "char* %s = NULL;\n", g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR]);
        }
    fprintf(g_CFILE, "%s= b2c_CopyString(%s,%s);\n", g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR], g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR], MID(statement, INSTR(statement, "SELECT") + 6));
    } else {
        g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR] = F_CONCAT(g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR], "b2c_select_" , STR(g_COUNTER)) ;
    fprintf(g_HFILE, "double %s = 0;\n", g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR]);
    fprintf(g_CFILE, "%s = (double)%s;\n", g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR], MID(statement, INSTR(statement, "SELECT") + 6));
    }
    g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 0;
    g_CASE_FALL = b2c_CopyString(g_CASE_FALL, (char*) "");
    g_CASE_CONT = b2c_CopyString(g_CASE_CONT, (char*)"");
}
} else  if ( !b2c_strcmp(b2c_select_4250, "CASE")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty CASE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( ISTRUE(g_IN_CASE[(uint64_t)g_SELECTVAR_CTR]) ){
        g_CASE_CONT = b2c_CopyString(g_CASE_CONT, (char*) "} else ");
    }
    if( Check_String_Type(g_SELECTVAR[(uint64_t)g_SELECTVAR_CTR]) ){
        exp = F_MID(exp,statement, INSTR(statement, "CASE") + 4);
        if( __b2c__STRCMP(RIGHT(statement, 1) ,  ";") == 0 ){
            g_CASE_FALL = F_CONCAT(g_CASE_FALL, g_CASE_FALL , "!b2c_strcmp(" , g_SELECTVAR[g_SELECTVAR_CTR] , ", " , LEFT(exp, LEN(exp)-1) , ") ||") ;
        } else {
            while( LEN(exp) ){
                str = b2c_CopyString(str, (char*) Mini_Parser(exp));
                g_CASE_FALL = F_CONCAT(g_CASE_FALL, g_CASE_FALL , "!b2c_strcmp(" , g_SELECTVAR[g_SELECTVAR_CTR] , ", " , str , ") ") ;
                exp = F_MID(exp,exp, LEN(str)+2);
                if( LEN(exp) ){
                    g_CASE_FALL = F_CONCAT(g_CASE_FALL, g_CASE_FALL , "||");
                }
            }
        fprintf(g_CFILE, "%s%s){\n", CONCAT( g_CASE_CONT , "if ("), g_CASE_FALL);
            g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 1;
            g_CASE_FALL = b2c_CopyString(g_CASE_FALL, (char*) "");
        }
    } else {
        exp = F_MID(exp,statement, INSTR(statement, "CASE") + 4);
        if( __b2c__STRCMP(RIGHT(statement, 1) ,  ";") == 0 ){
            g_CASE_FALL = F_CONCAT(g_CASE_FALL, g_CASE_FALL , "(" , g_SELECTVAR[g_SELECTVAR_CTR] , ") == (" , LEFT(exp, LEN(exp)-1) , ") ||") ;
        } else {
            while( LEN(exp) ){
                str = b2c_CopyString(str, (char*) Mini_Parser(exp));
                g_CASE_FALL = F_CONCAT(g_CASE_FALL, g_CASE_FALL , "(" , g_SELECTVAR[g_SELECTVAR_CTR] , ") == (" , str , ")") ;
                exp = F_MID(exp,exp, LEN(str)+2);
                if( LEN(exp) ){
                    g_CASE_FALL = F_CONCAT(g_CASE_FALL, g_CASE_FALL , "||");
                }
            }
        fprintf(g_CFILE, "%s%s){\n", CONCAT( g_CASE_CONT , "if ("), g_CASE_FALL);
            g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 1;
            g_CASE_FALL = b2c_CopyString(g_CASE_FALL, (char*) "");
        }
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "DEFAULT")){
if( ISTRUE(g_IN_CASE[(uint64_t)g_SELECTVAR_CTR]) ){
fputs("} else {\n", g_CFILE);
} else {
fprintf(stderr, "%sSyntax error: cannot use DEFAULT without previous CASE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
}
g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 0;
g_CASE_FALL = b2c_CopyString(g_CASE_FALL, (char*) "");
} else  if ( !b2c_strcmp(b2c_select_4250, "SETENVIRON")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty SETENVIRON at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
fprintf(g_CFILE, "SETENVIRON(%s);\n", LAST(statement));
}
} else  if ( !b2c_strcmp(b2c_select_4250, "SORT")){
Handle_Sort(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "STOP")){
if( dim == 1 ){
fputs("kill(getpid(), SIGSTOP);\n", g_CFILE);
} else {
fprintf(g_CFILE, "kill(getpid(),%s);\n", EXTRACT(LAST(statement), CHR(34)));
}
} else  if ( !b2c_strcmp(b2c_select_4250, "TRACE")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty TRACE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "MONITOR") == 0 ){
        g_TRACE=(long)( 1);
    fprintf(g_CFILE, "fprintf(stderr, \"File '%s' line %d: TRACE ON - press <SPACE> to execute the program step by step, <ESC> to exit.\\n\", %s);\n", g_CURFILE, STR( g_COUNTER));
        g_MONITOR = b2c_CopyString(g_MONITOR, (char*) "");
        b2c_forin_sym_string = b2c_CopyString(b2c_forin_sym_string, MID(statement, INSTR(statement, "MONITOR")+7)); b2c_forin_sym_string_org = b2c_forin_sym_string;
        b2c_forin_sym_step = b2c_CopyString(b2c_forin_sym_step, ",");
        b2c_forin_sym_ptr = b2c_for_amount(b2c_forin_sym_string, b2c_forin_sym_step);
        for(; b2c_forin_sym_ptr > 0; b2c_forin_sym_ptr--) { b2c_for_item(&b2c_forin_sym_string_org, b2c_forin_sym_step, &sym);
            sym = F_CHOP(sym,EXTRACT(sym,"\\(.*", TRUE));
            if( Check_String_Type(sym) ){
                exp = b2c_CopyString(exp, (char*) REPLACE(sym, g_STRINGSIGN, "$"));
                g_MONITOR = F_CONCAT(g_MONITOR, g_MONITOR , "&& (" , sym , "== NULL ? fprintf(stderr, \"MONITOR: " , exp , " = NULL\\n\") : fprintf(stderr, \"MONITOR: " , exp , " = %s\\n\", " , sym , ") )") ;
            } else {
                exp = b2c_CopyString(exp, (char*) REPLACE(sym, g_FLOATSIGN, "#"));
                exp = b2c_CopyString(exp, (char*) REPLACE(exp, g_LONGSIGN, "%"));
                g_MONITOR = F_CONCAT(g_MONITOR, g_MONITOR , "&& fprintf(stderr, \"MONITOR: " , exp , " = %s\\n\", STR" , g_STRINGSIGN , "(" , sym , "))") ;
            }
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "ON") == 0 ){
        g_TRACE=(long)( 1);
    fprintf(g_CFILE, "fprintf(stderr, \"File '%s' line %d: TRACE ON - press <SPACE> to execute the program step by step, <ESC> to exit.\\n\", %s);\n", g_CURFILE, STR( g_COUNTER));
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "OFF") == 0 ){
        g_MONITOR = b2c_CopyString(g_MONITOR, (char*) "");
        g_TRACE=(long)( 0);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "OPTION")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty OPTION at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "BASE") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-9]") ){
            g_OPTION_BASE=(long)( VAL(element[(uint64_t)3]));
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION BASE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "COMPARE") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
        fprintf(g_CFILE, "b2c_option_compare = %s;\n", element[(uint64_t)3]);
        fputs("#undef __b2c__STRCMP\n", g_CFILE);
            if( REGEX(element[(uint64_t)3], "1|TRUE") ){
            fputs("#define __b2c__STRCMP b2c_strcasecmp\n", g_CFILE);
            } else {
            fputs("#define __b2c__STRCMP b2c_strcmp\n", g_CFILE);
            }
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION COMPARE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "QUOTED") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
        fprintf(g_CFILE, "b2c_option_quoted = %s;\n", element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION QUOTED at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "UTF8") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
        fprintf(g_CFILE, "b2c_option_utf8 = %s;\n", element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION UTF8 at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "TLS") == 0  AND  dim >= 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
            if( __b2c__STRCMP(element[(uint64_t)3] ,  "1") == 0  OR  __b2c__STRCMP(element[(uint64_t)3] ,  "TRUE") == 0 ){
                g_OPTION_TLS=(long)( TRUE);
            fputs("b2c_option_tls = 1;\n", g_CFILE);
                g_INC_TLS = F_CONCAT(g_INC_TLS, "#include <openssl/ssl.h>" , NL , "#include <openssl/err.h>") ;
                g_LIB_TLS = F_CHOP(g_LIB_TLS,EXEC("pkg-config --libs openssl"));
            } else {
                g_OPTION_TLS=(long)( FALSE);
            fputs("b2c_option_tls = 0;\n", g_CFILE);
            }
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION TLS at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "EVAL") == 0  AND  dim >= 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
            g_CCFLAGS = F_CONCAT(g_CCFLAGS, g_CCFLAGS , " " , CHOP(EXEC("pkg-config --cflags libmatheval"))) ;
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " " , CHOP(EXEC("pkg-config --libs libmatheval"))) ;
            g_OPTION_EVAL=(long)( TRUE);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION EVAL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "PROPER") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
        fprintf(g_CFILE, "b2c_option_proper = %s;\n", element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION PROPER at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "DELIM") == 0  AND  (dim )> 2 ){
    fprintf(g_CFILE, "b2c_option_delim = %s;\n", MID(statement, INSTR(statement, "DELIM") + 6));
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "INPUT") == 0  AND  (dim )> 2 ){
        g_OPTION_INPUT = b2c_CopyString(g_OPTION_INPUT, (char*) element[(uint64_t)3]);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "DQ") == 0  AND  (dim )> 2 ){
    fprintf(g_CFILE, "b2c_option_dq = %s&255;\n", MID(statement, INSTR(statement, "DQ") + 3));
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "NO_C_ESC") == 0  AND  (dim )> 2 ){
        if( __b2c__STRCMP(element[(uint64_t)3] ,  "TRUE") == 0  OR  __b2c__STRCMP(element[(uint64_t)3] ,  "1") == 0 ){
            g_OPTION_DISABLE_C_ESCAPE=(long)( 1);
        } else {
            g_OPTION_DISABLE_C_ESCAPE=(long)( 0);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "ESC") == 0  AND  (dim )> 2 ){
    fprintf(g_CFILE, "b2c_option_esc = %s&255;\n", MID(statement, INSTR(statement, "ESC") + 4));
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "SOCKET") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-9]") ){
            g_OPTION_SOCKET=(long)( VAL(element[(uint64_t)3]));
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION SOCKET at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "BREAK") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
            g_OPTION_BREAK=(long)( IIF(__b2c__STRCMP(element[(uint64_t)3] ,  "TRUE") == 0, 1, VAL(element[(uint64_t)3])));
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION BREAK at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "MEMSTREAM") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
        fprintf(g_CFILE, "b2c_option_memstream = %s;\n", element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION MEMSTREAM at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "MEMTYPE") == 0  AND  (dim )> 2 ){
    fputs("#undef __b2c__MEMTYPE\n", g_CFILE);
    fprintf(g_CFILE, "#define __b2c__MEMTYPE %s\n", MID(statement, INSTR(statement, "MEMTYPE")+8));
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "PRIORITY") == 0  AND  (dim )> 2 ){
        g_PRIORITY = b2c_CopyString(g_PRIORITY, (char*) element[(uint64_t)3]);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "COLLAPSE") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
        fprintf(g_CFILE, "b2c_collapse = %s;\n", element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION COLLAPSE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "DEVICE") == 0  AND  dim >= 3 ){
    fprintf(g_CFILE, "b2c_option_open = (%s);\n", element[(uint64_t)3]);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "STARTPOINT") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
        fprintf(g_CFILE, "b2c_option_startpoint = %s;\n", element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION STARTPOINT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "INTERNATIONAL") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "1|TRUE") ){
        fputs("#include <libintl.h>\n", g_HFILE);
        fputs("setlocale(LC_ALL, \"\");\n", g_CFILE);
        fprintf(g_CFILE, "if(bindtextdomain(\"%s\",\"/usr/share/locale\")==NULL){ ERROR = 6; RUNTIMEERROR(\"OPTION INTERNATIONAL\", %s, \"%s\", ERROR, %s); }\n", LEFT(g_SOURCEFILE, INSTR(g_SOURCEFILE, ".")-1), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        fprintf(g_CFILE, "if(textdomain(\"%s\")==NULL){ ERROR = 6; RUNTIMEERROR(\"OPTION INTERNATIONAL\", %s, \"%s\", ERROR, %s); }\n", LEFT(g_SOURCEFILE, INSTR(g_SOURCEFILE, ".")-1), STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
            if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
                g_CATCH_USED=(long)( 1);
            }
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION INTERNATIONAL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "NETWORK") == 0  AND  dim >= 3 ){
        b2c_select_5433 = b2c_CopyString(b2c_select_5433, element[(uint64_t)3]);
        if ( !b2c_strcmp(b2c_select_5433, "TCP")){
            g_NETWORKTYPE = b2c_CopyString(g_NETWORKTYPE, (char*) "TCP");
            g_SOCKTYPE = b2c_CopyString(g_SOCKTYPE, (char*) "SOCK_STREAM");
        } else  if ( !b2c_strcmp(b2c_select_5433, "UDP")){
            g_NETWORKTYPE = b2c_CopyString(g_NETWORKTYPE, (char*) "UDP");
            g_SOCKTYPE = b2c_CopyString(g_SOCKTYPE, (char*) "SOCK_DGRAM");
        } else  if ( !b2c_strcmp(b2c_select_5433, "BROADCAST")){
            g_NETWORKTYPE = b2c_CopyString(g_NETWORKTYPE, (char*) "BROADCAST");
            g_SOCKTYPE = b2c_CopyString(g_SOCKTYPE, (char*) "SOCK_DGRAM");
        } else  if ( !b2c_strcmp(b2c_select_5433, "MULTICAST")){
            g_NETWORKTYPE = b2c_CopyString(g_NETWORKTYPE, (char*) "MULTICAST");
            g_SOCKTYPE = b2c_CopyString(g_SOCKTYPE, (char*) "SOCK_DGRAM");
            if( dim == 4  AND  REGEX(element[(uint64_t)4], "[0-9]") ){
                g_MULTICAST_TTL=(long)( VAL(element[(uint64_t)4]));
            }
        } else  if ( !b2c_strcmp(b2c_select_5433, "SCTP")){
            g_INCFILES = F_CONCAT(g_INCFILES, g_INCFILES , " <netinet/sctp.h>") ;
        fputs("struct sctp_initmsg b2c_initmsg;\n", g_HFILE);
            g_NETWORKTYPE = b2c_CopyString(g_NETWORKTYPE, (char*) "SCTP");
            g_SOCKTYPE = b2c_CopyString(g_SOCKTYPE, (char*) "SOCK_STREAM");
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " -lsctp") ;
            if( dim == 4  AND  REGEX(element[(uint64_t)4], "[0-9]") ){
                g_SCTP_STREAMS=(long)( VAL(element[(uint64_t)4]));
            }
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION NETWORK at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "PARSE") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
            g_IGNORE_PARSE = b2c_CopyString(g_IGNORE_PARSE, (char*) element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION PARSE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "EXPLICIT") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
            g_OPTION_EXPLICIT = b2c_CopyString(g_OPTION_EXPLICIT, (char*) element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION EXPLICIT at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "LOCAL") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
            g_OPTION_LOCAL = b2c_CopyString(g_OPTION_LOCAL, (char*) element[(uint64_t)3]);
        } else {
        fprintf(stderr, "%sSyntax error: invalid argument to OPTION LOCAL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "VARTYPE") == 0  AND  (dim )> 2 ){
        g_VARTYPE = F_MID(g_VARTYPE,statement, INSTR(statement, "VARTYPE")+8);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "GUI") == 0  AND  dim == 3 ){
        if( REGEX(element[(uint64_t)3], "1|TRUE") ){
        fputs("#define b2c_gui_xaw\n", g_GENERIC);
        fputs("#ifdef b2c_gui_xaw\n", g_HFILE);
        fputs("#include <AllWidgets.h>\n", g_HFILE);
        fputs("#include <AsciiText.h>\n", g_HFILE);
        fputs("#include <Box.h>\n", g_HFILE);
        fputs("#include <Dialog.h>\n", g_HFILE);
        fputs("#include <Command.h>\n", g_HFILE);
        fputs("#include <Form.h>\n", g_HFILE);
        fputs("#include <Grip.h>\n", g_HFILE);
        fputs("#include <List.h>\n", g_HFILE);
        fputs("#include <MenuButton.h>\n", g_HFILE);
        fputs("#include <MultiSink.h>\n", g_HFILE);
        fputs("#include <Paned.h>\n", g_HFILE);
        fputs("#include <Panner.h>\n", g_HFILE);
        fputs("#include <Porthole.h>\n", g_HFILE);
        fputs("#include <Repeater.h>\n", g_HFILE);
        fputs("#include <Scrollbar.h>\n", g_HFILE);
        fputs("#include <SimpleMenu.h>\n", g_HFILE);
        fputs("#include <SmeBSB.h>\n", g_HFILE);
        fputs("#include <SmeLine.h>\n", g_HFILE);
        fputs("#include <StripChart.h>\n", g_HFILE);
        fputs("#include <Tip.h>\n", g_HFILE);
        fputs("#include <Toggle.h>\n", g_HFILE);
        fputs("#include <Tree.h>\n", g_HFILE);
        fputs("#include <Viewport.h>\n", g_HFILE);
        fputs("#include <X11/Intrinsic.h>\n", g_HFILE);
        fputs("#include <X11/Shell.h>\n", g_HFILE);
        fputs("#include <X11/StringDefs.h>\n", g_HFILE);
        fputs("#endif\n", g_HFILE);
            g_CCFLAGS = F_CONCAT(g_CCFLAGS, g_CCFLAGS , " -I/usr/include/X11/Xaw") ;
            g_INCLUDE_FILES = F_CONCAT(g_INCLUDE_FILES, g_INCLUDE_FILES , " " , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".gui.h") ;
            g_LDFLAGS = F_CONCAT(g_LDFLAGS,  g_LDFLAGS , " -lXaw -lXmu -lXt -lX11") ;
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "ERROR") == 0  AND  dim == 3 ){
    fputs("WARNING: OPTION ERROR is deprecated.\n", stdout);
    } else {
    fprintf(stderr, "%sSyntax error: argument to OPTION at line %s in file '%s' not recognized!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "PROTO")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty PROTO at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    exp = b2c_CopyString(exp, (char*) EXTRACT(LAST(statement), CHR(34)));
    if( ISTOKEN(exp, "ALIAS") ){
    fprintf(g_HFILE, "#define %s %s\n", CHOP(TOKEN(exp, 2, "ALIAS")), CHOP(TOKEN(exp, 1, "ALIAS")));
        g_IMPORTED = F_CONCAT(g_IMPORTED, TOKEN(exp, 2, "ALIAS") , " " , g_IMPORTED) ;
        g_IMPORTED = F_CONCAT(g_IMPORTED, TOKEN(exp, 1, "ALIAS") , " " , g_IMPORTED) ;
    } else if( ISTOKEN(exp, "TYPE") ){
    fprintf(g_HFILE, "%s %s;\n", TOKEN(exp, 2, "TYPE"), TOKEN(exp, 1, "TYPE"));
    } else {
        g_IMPORTED = F_CONCAT(g_IMPORTED, REPLACE(exp, ",", " ") , " " , g_IMPORTED) ;
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "INCR")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty INCR at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    token = b2c_CopyString(token, (char*) Mini_Parser(statement));
    exp = F_CHOP(exp,MID(statement, LEN(token)+2));
    if( NOT(LEN(exp)) ){
        exp = b2c_CopyString(exp, (char*) "1");
    }
    token = F_CHOP(token,MID(token, INSTR(token, " ")));
    if( REGEX(token, "[a-zA-Z]+\\(.*\\)$") ){
        lft = b2c_CopyString(lft, (char*) LEFT(token, INSTR(token, "(") - 1));
        str = b2c_CopyString(str, (char*) INBETWEEN(token, "(", ")", 2));
    fprintf(g_CFILE, "assoc_%s_eval = %s + (%s); b2c_hash_add(assoc_%s, &assoc_%s_eval, %s);\n", lft, token, exp, lft, lft, str);
        Relate_Recurse(lft, str, CONCAT( token , "+(" , exp , ")") , -1);
    } else {
        if( REGEX(exp, "[0-9]\\.[0-9]") ){
            Register_Numeric(token, "double");
        } else if( NOT(LEN(Get_Var(token, g_FUNCNAME))) ){
            Register_Numeric(token, "default");
        }
    fprintf(g_CFILE, "%s = %s + (%s);\n", token, token, exp);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "DECR")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty DECR at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    token = b2c_CopyString(token, (char*) Mini_Parser(statement));
    exp = F_CHOP(exp,MID(statement, LEN(token)+2));
    if( NOT(LEN(exp)) ){
        exp = b2c_CopyString(exp, (char*) "1");
    }
    token = F_CHOP(token,MID(token, INSTR(token, " ")));
    if( REGEX(token, "[a-zA-Z]+\\(.*\\)$") ){
        lft = b2c_CopyString(lft, (char*) LEFT(token, INSTR(token, "(") - 1));
        str = b2c_CopyString(str, (char*) INBETWEEN(token, "(", ")", 2));
    fprintf(g_CFILE, "assoc_%s_eval = %s - (%s); b2c_hash_add(assoc_%s, &assoc_%s_eval, %s);\n", lft, token, exp, lft, lft, str);
        Relate_Recurse(lft, str, CONCAT( token , "+(" , exp , ")") , -1);
    } else {
        if( REGEX(exp, "[0-9]\\.[0-9]") ){
            Register_Numeric(token, "double");
        } else if( NOT(LEN(Get_Var(token, g_FUNCNAME))) ){
            Register_Numeric(token, "default");
        }
    fprintf(g_CFILE, "%s = %s - (%s);\n", token, token, exp);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "ALARM")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty ALARM at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    str = b2c_CopyString(str, (char*) EXTRACT(TOKEN(statement, 1, ","), "^ALARM ", TRUE));
    exp = b2c_CopyString(exp, (char*) TOKEN(statement, 2, ","));
fprintf(g_CFILE, "b2c_alarm((void*)(uintptr_t)(&%s), %s);\n", str, exp);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "SIGNAL")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty SIGNAL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    b2c_split_by(&symbol, 1, &symbol__b2c_array, LAST(statement), ",");
    dim = symbol__b2c_array;
    if( dim == 2 ){
        if( ISTOKEN(symbol[(uint64_t)1], "SIG_DFL")  OR  ISTOKEN(symbol[(uint64_t)1], "SIG_IGN") ){
        fprintf(g_CFILE, "b2c_signal((void*)(uintptr_t)%s, %s);\n", symbol[(uint64_t)1], symbol[(uint64_t)2]);
        } else {
        fprintf(g_CFILE, "b2c_signal((void*)(uintptr_t)(&%s), %s);\n", symbol[(uint64_t)1], symbol[(uint64_t)2]);
        }
    } else {
    fprintf(stderr, "%sSyntax error: missing argument in SIGNAL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "CURSOR")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty CURSOR at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    exp = b2c_CopyString(exp, (char*) IIF(dim == 3, element[(uint64_t)3], "1"));
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "ON") == 0 ){
    fputs("fprintf(stdout,\"\\033[?25h\"); fflush(stdout);\n", g_CFILE);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "OFF") == 0 ){
    fputs("fprintf(stdout,\"\\033[?25l\"); fflush(stdout);\n", g_CFILE);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "UP") == 0 ){
    fprintf(g_CFILE, "fprintf(stdout,\"\\033[%ldA\", (long)%s); fflush(stdout);\n", exp);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "DOWN") == 0 ){
    fprintf(g_CFILE, "fprintf(stdout,\"\\033[%ldB\", (long)%s); fflush(stdout);\n", exp);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "FORWARD") == 0 ){
    fprintf(g_CFILE, "fprintf(stdout,\"\\033[%ldC\", (long)%s); fflush(stdout);\n", exp);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "BACK") == 0 ){
    fprintf(g_CFILE, "fprintf(stdout,\"\\033[%ldD\", (long)%s); fflush(stdout);\n", exp);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "SCROLL")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty SCROLL at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    exp = b2c_CopyString(exp, (char*) IIF(dim == 3, element[(uint64_t)3], "1"));
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "UP") == 0 ){
    fprintf(g_CFILE, "fprintf(stdout,\"\\033[%ldS\", (long)%s); fflush(stdout);\n", exp);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "DOWN") == 0 ){
    fprintf(g_CFILE, "fprintf(stdout,\"\\033[%ldT\", (long)%s); fflush(stdout);\n", exp);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "ALIAS")){
Handle_Alias(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "LOOKUP")){
Handle_Lookup(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "RELATE")){
Handle_Relate(CHOP(MID(statement, INSTR(statement, "RELATE") + 6)));
} else  if ( !b2c_strcmp(b2c_select_4250, "TEXTDOMAIN")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty TEXTDOMAIN at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    b2c_split_by(&symbol, 1, &symbol__b2c_array, CHOP(MID(statement, INSTR(statement, "TEXTDOMAIN") + 10)), ",");
    dim = symbol__b2c_array;
    if( dim == 2 ){
    fprintf(g_CFILE, "if(bindtextdomain(%s,%s)==NULL){ ERROR = 6; RUNTIMEERROR(\"TEXTDOMAIN\", %s, \"%s\", ERROR, %s); }\n", symbol[(uint64_t)1], symbol[(uint64_t)2], STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
    fprintf(g_CFILE, "if(textdomain(%s)==NULL){ ERROR = 6; RUNTIMEERROR(\"TEXTDOMAIN\", %s, \"%s\", ERROR, %s); }\n", symbol[(uint64_t)1], STR( g_COUNTER), g_CURFILE, g_CATCHGOTO);
        if( __b2c__STRCMP(g_CATCHGOTO ,  "__B2C__PROGRAM__EXIT") == 0 ){
            g_CATCH_USED=(long)( 1);
        }
    } else {
    fprintf(stderr, "%sSyntax error: missing argument in TEXTDOMAIN at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "REDIM")){
Handle_Redim(CHOP(MID(statement, INSTR(statement, "REDIM") + 5)));
} else  if ( !b2c_strcmp(b2c_select_4250, "EXIT")){
if( LEN(g_FUNCNAME) == 0 ){
fprintf(stderr, "%sSyntax error: EXIT not in FUNCTION or SUB at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
}
fprintf(g_CFILE, "%s\n", g_STRINGARRAYS);
b2c_forin_exp_string = b2c_CopyString(b2c_forin_exp_string, g_LOCALSTRINGS); b2c_forin_exp_string_org = b2c_forin_exp_string;
b2c_forin_exp_step = b2c_CopyString(b2c_forin_exp_step, b2c_option_delim);
b2c_forin_exp_ptr = b2c_for_amount(b2c_forin_exp_string, b2c_forin_exp_step);
for(; b2c_forin_exp_ptr > 0; b2c_forin_exp_ptr--) { b2c_for_item(&b2c_forin_exp_string_org, b2c_forin_exp_step, &exp);
fprintf(g_CFILE, "__b2c__STRFREE(%s);\n", exp);
}
fputs("b2c_catch_set = b2c_catch_set_backup;\n", g_CFILE);
if( INSTR(g_FUNCNAME, g_STRINGSIGN) ){
fputs("return(NULL);\n", g_CFILE);
} else {
fputs("return b2c_exitval;\n", g_CFILE);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "PRAGMA")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty PRAGMA at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    if( __b2c__STRCMP(element[(uint64_t)2] ,  "OPTIONS") == 0  AND  dim >= 3 ){
        for(i=3; i <= dim; i+=1){
            g_CCFLAGS = F_CONCAT(g_CCFLAGS, g_CCFLAGS , " " , element[i]) ;
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "COMPILER") == 0  AND  dim == 3 ){
        g_CCNAME = b2c_CopyString(g_CCNAME, (char*) element[(uint64_t)3]);
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "FRAMEWORK") == 0  AND  dim >= 3 ){
        for(i=3; i <= dim; i+=1){
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " -framework " , element[i]) ;
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "RE") == 0  AND  dim >= 3 ){
        g_PRAGMA_REGEX = F_MID(g_PRAGMA_REGEX,statement, INSTR(statement, "RE")+3);
        if( NOT(REGEX(g_PRAGMA_REGEX, " LDFLAGS ")) ){
            exp = b2c_CopyString(exp, (char*) HEAD(g_PRAGMA_REGEX));
            if( INSTR(exp, "tre") ){
                g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " " , CHOP(EXEC("pkg-config --libs tre"))) ;
            } else if( INSTR(exp, "pcre") ){
                g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " " , CHOP(EXEC("pkg-config --libs libpcreposix"))) ;
            } else if( INSTR(exp, "onig") ){
                g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " " , CHOP(EXEC("pkg-config --libs oniguruma"))) ;
            }
        } else {
            exp = F_MID(exp,g_PRAGMA_REGEX, INSTR(g_PRAGMA_REGEX, " LDFLAGS ")+9);
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, exp , " " , g_LDFLAGS) ;
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "TLS") == 0  AND  dim >= 3 ){
        g_LIB_TLS = F_MID(g_LIB_TLS,statement, INSTR(statement, "TLS")+4);
        g_OPTION_TLS=(long)( TRUE);
    fputs("b2c_option_tls = 1;\n", g_CFILE);
        if( NOT(REGEX(g_LIB_TLS, " LDFLAGS ")) ){
            exp = b2c_CopyString(exp, (char*) HEAD(g_LIB_TLS));
            if( TALLY(exp, "openssl") ){
                g_LIB_TLS = F_CHOP(g_LIB_TLS,EXEC("pkg-config --libs openssl"));
                g_INC_TLS = F_CONCAT(g_INC_TLS, "#include <openssl/ssl.h>" , NL , "#include <openssl/err.h>") ;
            } else if( TALLY(exp, "gnutls") ){
                g_LIB_TLS = F_CONCAT(g_LIB_TLS, CHOP(EXEC("pkg-config --libs gnutls")) , " -lgnutls-openssl") ;
                g_INC_TLS = b2c_CopyString(g_INC_TLS, (char*) "#include <gnutls/openssl.h>");
            } else if( INSTR(exp, "wolfssl") ){
                g_LIB_TLS = F_CHOP(g_LIB_TLS,EXEC("pkg-config --libs wolfssl"));
                g_INC_TLS = F_CONCAT(g_INC_TLS, "#include <wolfssl/options.h>" , NL , "#include <wolfssl/openssl/ssl.h>") ;
            }
        } else {
            g_INC_TLS = b2c_CopyString(g_INC_TLS, (char*) LEFT(g_LIB_TLS, INSTR(g_LIB_TLS, " LDFLAGS ")-1));
            g_LIB_TLS = F_MID(g_LIB_TLS,g_LIB_TLS, INSTR(g_LIB_TLS, " LDFLAGS ")+9);
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "GUI") == 0  AND  dim >= 3 ){
        exp = F_MID(exp,statement, INSTR(statement, "GUI")+4);
        if( NOT(INSTR(exp, " LDFLAGS ")) ){
            if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "xaw3d") == 0 ){
            fputs("#include <ThreeD.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw", "-lXaw3d"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) REPLACE(g_CCFLAGS, "-I/usr/include/X11/Xaw", "-I/usr/include/X11/Xaw3d"));
            } else if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "motif") == 0 ){
            fputs("#undef b2c_gui_xaw\n", g_GENERIC);
            fputs("#include <Xm/XmAll.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw", "-lXm"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) EXTRACT(g_CCFLAGS, "-I/usr/include/X11/Xaw"));
            } else if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "uil") == 0 ){
            fputs("#undef b2c_gui_xaw\n", g_GENERIC);
            fputs("#define b2c_gui_uil\n", g_GENERIC);
            fputs("#include <Xm/XmAll.h>\n", g_HFILE);
            fputs("#include <Mrm/MrmAppl.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw", "-lMrm -lXm"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) EXTRACT(g_CCFLAGS, "-I/usr/include/X11/Xaw"));
            } else if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "gtk2") == 0 ){
            fputs("#undef b2c_gui_xaw\n", g_GENERIC);
            fputs("#include <gtk/gtk.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs gtk+-2.0`"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) REPLACE(g_CCFLAGS, "-I/usr/include/X11/Xaw", "`pkg-config --cflags gtk+-2.0`"));
                g_WHICH_GUI=(long)( 1);
            } else if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "gtk3") == 0 ){
            fputs("#undef b2c_gui_xaw\n", g_GENERIC);
            fputs("#include <gtk/gtk.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs gtk+-3.0`"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) REPLACE(g_CCFLAGS, "-I/usr/include/X11/Xaw", "`pkg-config --cflags gtk+-3.0`"));
                g_WHICH_GUI=(long)( 1);
            } else if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "gtk4") == 0 ){
            fputs("#undef b2c_gui_xaw\n", g_GENERIC);
            fputs("#include <gtk/gtk.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs gtk4`"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) REPLACE(g_CCFLAGS, "-I/usr/include/X11/Xaw", "`pkg-config --cflags gtk4`"));
                g_WHICH_GUI=(long)( 3);
            } else if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "cdk") == 0 ){
            fputs("#undef b2c_gui_xaw\n", g_GENERIC);
            fputs("#include <cdk.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw -lXmu -lXt -lX11", "-lncurses -lcdk"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) REPLACE(g_CCFLAGS, "-I/usr/include/X11/Xaw", "-I/usr/include/cdk"));
                g_WHICH_GUI=(long)( 2);
            } else if( __b2c__STRCMP(LCASE(HEAD(exp)) ,  "tk") == 0 ){
            fputs("#undef b2c_gui_xaw\n", g_GENERIC);
            fputs("#include <tcl.h>\n", g_HFILE);
            fputs("#include <tk.h>\n", g_HFILE);
                g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs tk tcl`"));
                g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) REPLACE(g_CCFLAGS, "-I/usr/include/X11/Xaw", "`pkg-config --cflags tk tcl`"));
                g_WHICH_GUI=(long)( 4);
            }
            if( g_WHICH_GUI == 1 ){
            fputs("#define GTKINIT gtk_init(NULL,NULL)\n", g_HFILE);
            fputs("#define GTKMAINITERATION gtk_main_iteration()\n", g_HFILE);
            fputs("#define GTKWIDGETSHOW gtk_widget_show_all\n", g_HFILE);
            fputs("#define GTKCONTAINERADD(x,y) gtk_container_add(GTK_CONTAINER(x), GTK_WIDGET(y))\n", g_HFILE);
            } else if( g_WHICH_GUI == 3 ){
            fputs("#define GTKINIT gtk_init()\n", g_HFILE);
            fputs("#define GTKMAINITERATION g_main_context_iteration(NULL,1)\n", g_HFILE);
            fputs("#define GTKWIDGETSHOW gtk_widget_show\n", g_HFILE);
            fputs("#define GTKCONTAINERADD(x,y) (GTK_IS_BOX(x) ? gtk_box_append(GTK_BOX(x), GTK_WIDGET(y)) : g_object_set(GTK_WIDGET(x), \"child\", GTK_WIDGET(y), NULL))\n", g_HFILE);
            }
        } else {
            g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) REPLACE(g_LDFLAGS, "-lXaw", TOKEN(exp, 2, " LDFLAGS ")));
            g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) REPLACE(g_CCFLAGS, "-I/usr/include/X11/Xaw", TOKEN(TOKEN(exp, 1, " LDFLAGS "), 2, " OPTIONS ")));
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "LDFLAGS") == 0  AND  dim >= 3 ){
        if( TALLY(TOKEN(statement, 2, "LDFLAGS"), "pkg-config")  OR  TALLY(TOKEN(statement, 2, "LDFLAGS"), "fltk-config") ){
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, TOKEN(statement, 2, "LDFLAGS") , " " , g_LDFLAGS) ;
        } else {
            for(i=3; i <= dim; i+=1){
                if( __b2c__STRCMP(element[(uint64_t)i] ,  "TRUE") == 0 ){
                    found=(
                    long)( TRUE);
                    break;
                } else if( __b2c__STRCMP(LEFT(element[(uint64_t)i], 1) ,  "-") == 0  OR  __b2c__STRCMP(RIGHT(element[(uint64_t)i], 2) ,  ".a") == 0 ){
                    exp = F_CONCAT(exp, exp , " " , element[i]) ;
                } else {
                    exp = F_CONCAT(exp, exp , " -l" , element[i]) ;
                }
            }
            if( found ){
                g_LDFLAGS = F_CONCAT(g_LDFLAGS, exp , " " , g_LDFLAGS) ;
            } else {
                g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " " , exp) ;
            }
        }
    } else if( __b2c__STRCMP(element[(uint64_t)2] ,  "INCLUDE") == 0  AND  dim >= 3 ){
        for(i=3; i <= dim; i+=1){
            if( __b2c__STRCMP(LEFT(element[(uint64_t)i], 1) ,  "/") == 0  OR  __b2c__STRCMP(LEFT(element[(uint64_t)i], 2) ,  "./") == 0 ){
                g_PRAGMA_INCLUDE = F_CONCAT(g_PRAGMA_INCLUDE, g_PRAGMA_INCLUDE , NL , "#include " , CHR(34) , element[(uint64_t)i] , CHR(34)) ;
            } else if( __b2c__STRCMP(LEFT(element[(uint64_t)i], 1) ,  "<") == 0 ){
                g_PRAGMA_INCLUDE = F_CONCAT(g_PRAGMA_INCLUDE, g_PRAGMA_INCLUDE , NL , "#include " , element[(uint64_t)i]) ;
            } else {
                g_PRAGMA_INCLUDE = F_CONCAT(g_PRAGMA_INCLUDE, g_PRAGMA_INCLUDE , NL , "#include " , CHR(34) , CURDIR , "/" , element[(uint64_t)i] , CHR(34)) ;
            }
        }
    } else {
    fprintf(g_CFILE, "#pragma %s\n", CHOP(MID(statement, INSTR(statement, "PRAGMA") + 6)));
    }
}
} else  if ( !b2c_strcmp(b2c_select_4250, "SWAP")){
Handle_Swap(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "SETSERIAL")){
Handle_Setserial(CHOP(MID(statement, INSTR(statement, "SETSERIAL") + 9)));
} else  if ( !b2c_strcmp(b2c_select_4250, "ENUM")){
if( NOT(LEN(g_FUNCNAME)) ){
fputs("enum {\n", g_HFILE);
    g_USE_H=(long)( 1);
} else {
fputs("enum {\n", g_CFILE);
    g_USE_C=(long)( 1);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "RUN")){
Handle_Run(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "SAVE")){
Handle_Save(0, CHOP(MID(statement, INSTR(statement, "SAVE") + 4)));
} else  if ( !b2c_strcmp(b2c_select_4250, "BSAVE")){
Handle_Save(1, CHOP(MID(statement, INSTR(statement, "BSAVE") + 5)));
} else  if ( !b2c_strcmp(b2c_select_4250, "APPEND")){
exp = F_MID(exp,statement, INSTR(statement, "APPEND") + 6);
if( NOT(ISTOKEN(exp, "TO"))  AND  HASDELIM(exp, ",") ){
fprintf(g_CFILE, "%s= F_CONCAT%s(%s,%s);\n", TOKEN(exp, 1, ","), g_STRINGSIGN, TOKEN(exp, 1, ","), exp);
} else {
    Handle_Save(2, CHOP(MID(statement, INSTR(statement, "APPEND") + 6)));
}
} else  if ( !b2c_strcmp(b2c_select_4250, "BAPPEND")){
Handle_Save(3, CHOP(MID(statement, INSTR(statement, "BAPPEND") + 7)));
} else  if ( !b2c_strcmp(b2c_select_4250, "MAP")){
Handle_Map(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "RESET")){
fputs("fprintf(stdout,\"\\033c\"); fflush(stdout);\n", g_CFILE);
} else  if ( !b2c_strcmp(b2c_select_4250, "CERTIFICATE")){
if( dim == 1 ){
fprintf(stderr, "%sSyntax error: empty CERTIFICATE at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
    exit(1);
} else {
    exp = F_MID(exp,statement, INSTR(statement, "CERTIFICATE") + 11);
    token = b2c_CopyString(token, (char*) Mini_Parser(exp));
fputs("#undef b2c_caprivate\n", g_CFILE);
fprintf(g_CFILE, "#define b2c_caprivate %s\n", token);
    exp = F_MID(exp,exp, LEN(token)+2);
    token = b2c_CopyString(token, (char*) Mini_Parser(exp));
fputs("#undef b2c_caserver\n", g_CFILE);
fprintf(g_CFILE, "#define b2c_caserver %s\n", token);
}
} else  if ( !b2c_strcmp(b2c_select_4250, "TREE")){
Handle_Tree(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "COLLECT")){
Handle_Collect(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "PARSE")){
Handle_Parse(statement);
} else  if ( !b2c_strcmp(b2c_select_4250, "GETKEY")){
fputs("b2c_getch();\n", g_CFILE);
} else {
if( INSTR(element[(uint64_t)1], "(") ){
    element[(uint64_t)1] = b2c_CopyString(element[(uint64_t)1], (char*) TOKEN(element[(uint64_t)1], 1, "("));
}
if( ISTOKEN(g_IMPORTED, element[(uint64_t)1]) ){
    if( REGEX(statement, "\\(.*\\)") ){
    fprintf(g_CFILE, "%s;\n", statement);
    } else {
    fprintf(g_CFILE, "%s();\n", statement);
    }
} else {
    Handle_Let(statement);
}
}
}
}
b2c_free_str_array_members(&element, 1, element__b2c_array); __b2c__STRFREE(b2c_forin_str_string); b2c_forin_str_string = NULL; __b2c__STRFREE(b2c_forin_str_step); b2c_forin_str_step = NULL; b2c_free_str_array_members(&match, 1, match__b2c_array); __b2c__STRFREE(b2c_forin_sym_string); b2c_forin_sym_string = NULL; __b2c__STRFREE(b2c_forin_sym_step); b2c_forin_sym_step = NULL; b2c_free_str_array_members(&symbol, 1, symbol__b2c_array); __b2c__STRFREE(b2c_forin_exp_string); b2c_forin_exp_string = NULL; __b2c__STRFREE(b2c_forin_exp_step); b2c_forin_exp_step = NULL;
__b2c__STRFREE(statement);
__b2c__STRFREE(inc);
__b2c__STRFREE(copy_curfile);
__b2c__STRFREE(total);
__b2c__STRFREE(txt);
__b2c__STRFREE(sym);
__b2c__STRFREE(exp);
__b2c__STRFREE(then);
__b2c__STRFREE(lft);
__b2c__STRFREE(str);
__b2c__STRFREE(newfeed);
__b2c__STRFREE(token);
__b2c__STRFREE(rel);
__b2c__STRFREE(uniq);
__b2c__STRFREE(element);
__b2c__STRFREE(b2c_select_4250);
__b2c__STRFREE(b2c_select_4459);
__b2c__STRFREE(b2c_select_4580);
__b2c__STRFREE(match);
__b2c__STRFREE(b2c_select_5433);
__b2c__STRFREE(symbol);
__B2C__PROGRAM__EXIT: ;
b2c_catch_set = b2c_catch_set_backup;
}
