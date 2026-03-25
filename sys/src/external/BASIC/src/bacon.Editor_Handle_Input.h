/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Editor_Handle_Input( char *__b2c_file, char *__b2c_text) {
    char*file = NULL; file = b2c_CopyString(NULL, __b2c_file); char*text = NULL; text = b2c_CopyString(NULL, __b2c_text); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_line_input_ptr = 0; char* b2c_forin_line_input_string = NULL; char* b2c_forin_line_input_string_org = NULL; char* b2c_forin_line_input_step = NULL; char *b2c_select_7896 = NULL;
    long visual_xpos = 1;
    long real_xpos = 1;
    long ypos = 1;
    long start = 1;
    long visual_begin_pos = 1;
    long display_columns = 0;
    long do_print = 0;
    long key = 0;
    long special = 0;
    long cursor = 0;
    long delkey = 0;
    long page = 0;
    long total = 0;
    long line = 0;
    long next = 0;
    long x = 0;
    long myposition = 0;
    long nextposition = 0;
    long label_active = 0;
    long wrap_active = 0;
    long digits = 0;
    long copy_flag = 0;
    long cksum = 0;
    char *line = NULL;
    char *prog = NULL;
    char *answer = NULL;
    char *option = NULL;
    char *man = NULL;
    char *str = NULL;
    char *result = NULL;
    char *copy_line = NULL;
    char *word = NULL;
    char *arg = NULL;
    char *line_input = NULL;
    b2c_option_dq = 1&255;
    b2c_collapse = FALSE;
    ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, ~IXON, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7151, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7152, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  17, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7153, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    b2c_signal((void*)(uintptr_t)(&Editor_Restore_Normal),  SIGINT);
    g_CURSOR_X=(long)( GETX);
    g_CURSOR_Y=(long)( GETY);
    fprintf(stdout,"\033[?47h"); fflush(stdout);
    fprintf(stdout,"\033[2J"); fprintf(stdout,"\033[0;0f"); fflush(stdout);
    Editor_Print_Text(text, 1, 1);
    cksum=(
    long)( HASH(text));
    while( TRUE ){
        do{
            if( Line_Number_Active ){
                digits=(
                long)( LEN(STR(AMOUNT(text, NL))));
                display_columns=(
                long)( COLUMNS-digits-1);
                fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(visual_xpos+digits+1));fflush(stdout);
            } else {
                display_columns=(
                long)( COLUMNS);
                fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(visual_xpos));fflush(stdout);
            }
            key=(
            long)( WAIT(STDIN_FILENO, 100));
            b2c_select_7182 = (double)key;
            if ( (b2c_select_7182) == (0)){
                continue;
            } else  if ( (b2c_select_7182) == (3)){
                copy_line = b2c_CopyString(copy_line, (char*) TOKEN(text, start+ypos-1, NL));
                copy_flag=(
                long)( 1);
            } else  if ( (b2c_select_7182) == (24)){
                copy_line = b2c_CopyString(copy_line, (char*) TOKEN(text, start+ypos-1, NL));
                text = b2c_CopyString(text, (char*) DEL(text, start+ypos-1, NL));
                do_print=(
                long)( TRUE);
                copy_flag=(
                long)( 1);
            } else  if ( (b2c_select_7182) == (22)){
                if( (ypos )< ROWS  AND  LEN(copy_line) ){
                    text = F_APPEND(text,text, start+ypos-1, copy_line, NL);
                    do_print=(
                    long)( TRUE);
                }
                line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                x=(
                long)( 1);
                real_xpos=(
                long)( 1);
                while( (x )< visual_begin_pos - 1 + visual_xpos ){
                    x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                    real_xpos = real_xpos + (1);
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                copy_flag=(
                long)( 0);
            } else  if ( (b2c_select_7182) == (4)){
                myposition=(
                long)( real_xpos);
                line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                while( NOT(REGEX(MID(line, myposition, 1), "[[:space:]]|[=,?;:+-/\\(\\)\\*]")) ){
                    myposition = myposition - (1);
                    if( myposition == 0 ){
                        break;
                    }
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                myposition = myposition + (1);
                total=(
                long)( 1);
                while( NOT(REGEX(MID(line, myposition+total, 1), "[[:space:]]|[=,?;:+-/\\(\\)\\*]")) ){
                    total = total + (1);
                    if( (myposition+total )> LEN(line) ){
                        break;
                    }
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                word = F_MID(word,line, myposition, total);
                fprintf(stdout,"\033[2J"); fprintf(stdout,"\033[0;0f"); fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                fprintf(stdout, "\033[%ld;%ldH",(long)( 1),(long)(1));fflush(stdout);
                if( ISTRUE(LEN(EXEC("command -v less 2>/dev/null"))) ){
                    fprintf(stdout,"\033[?47l"); fflush(stdout);
                RETVAL = system(CONCAT( "man bacon | less -P\"[Press space to continue, 'q' to quit.]\" -p '^     " , REPLACE(word, "$", "\\$") , "'") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
                    fprintf(stdout,"\033[?47h"); fflush(stdout);
                } else {
                RETVAL = system(CONCAT( "man bacon | more -d -p +/'^     " , REPLACE(word, "$", "\\$") , "'") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
                }
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (18)){
                Line_Number_Active=(long)( 1 - Line_Number_Active);
                if( FILEEXISTS( CONCAT(GETENVIRON("HOME") , "/.bacon/bacon.cfg" ) ) ){
                    arg = b2c_CopyString(arg, (char*) COLLAPSE(LOAD( CONCAT(GETENVIRON("HOME") , "/.bacon/bacon.cfg") ), NL));
                    for(x=1; x <= AMOUNT(arg, NL); x+=1){
                        if( REGEX(TOKEN(arg, x, NL), "^linenr") ){
                            arg = b2c_CopyString(arg, (char*) DEL(arg, x, NL));
                        }
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    ERROR = b2c_save(0, 0, CONCAT( GETENVIRON("HOME") , "/.bacon/bacon.cfg"), APPEND(arg, 0, CONCAT( "linenr " , STR(Line_Number_Active)) , NL), NULL);
                if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7250, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                } else {
                    ERROR = b2c_save(0, 0, CONCAT( GETENVIRON("HOME") , "/.bacon/bacon.cfg"), CONCAT( "linenr " , STR(Line_Number_Active) ), NULL);
                if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7252, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                }
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (7)){
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
            if(ERROR){ RUNTIMEERROR("SETSERIAL", 7261, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            fprintf(stdout, "%sEnter line number... ", CL);
                fflush(stdout);
                b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                key = atol(b2c_assign);
                free(b2c_assign); b2c_assign = NULL;
                ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
            if(ERROR){ RUNTIMEERROR("SETSERIAL", 7263, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                if( (key )> AMOUNT(text, NL) ){
                    key=(
                    long)( AMOUNT(text, NL));
                }
                if( (key )< ROWS ){
                    start=(
                    long)( 1);
                    ypos=(
                    long)( key);
                } else if( (key )> AMOUNT(text, NL)-(ROWS/2) ){
                    start=(
                    long)( AMOUNT(text, NL)-ROWS);
                    ypos=(
                    long)( ROWS - (AMOUNT(text, NL)-key));
                } else {
                    start=(
                    long)( key-(ROWS/2));
                    ypos=(
                    long)( key-start+1);
                }
                fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(visual_xpos));fflush(stdout);
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (1)){
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                result = b2c_CopyString(result, (char*) "");
                myposition = nextposition = label_active = wrap_active = 0;
                b2c_forin_line_input_string = b2c_CopyString(b2c_forin_line_input_string, text); b2c_forin_line_input_string_org = b2c_forin_line_input_string;
                b2c_forin_line_input_step = b2c_CopyString(b2c_forin_line_input_step, NL);
                b2c_forin_line_input_ptr = b2c_for_amount(b2c_forin_line_input_string, b2c_forin_line_input_step);
                for(; b2c_forin_line_input_ptr > 0; b2c_forin_line_input_ptr--) { b2c_for_item(&b2c_forin_line_input_string_org, b2c_forin_line_input_step, &line_input);
                    myposition=(
                    long)( nextposition);
                    line_input = F_CHOP(line_input,line_input);
                    if( LEN(line_input) == 0  AND  label_active ){
                        label_active=(
                        long)( FALSE);
                        myposition = myposition - (1);
                        nextposition=(
                        long)( myposition);
                    }
                    if( REGEX(line_input, "^(CASE|UNTIL)[ \\t]|^(DEFAULT|FI|NEXT|WEND|DONE)|^ELSE$|^ELIF.+THEN$|^END.+") ){
                        if( NOT(REGEX(line_input, "^END.+[0-9]+|^ENDFORK")) ){
                            myposition = myposition - (1);
                        }
                        if( REGEX(line_input, "SELECT$") ){
                            myposition = myposition - (1);
                        }
                        if( (myposition )< 0 ){
                            myposition=(
                            long)( 0);
                        }
                        nextposition=(
                        long)( myposition);
                    }
                    if( REGEX(line_input, "^(CASE|ENUM|FOR|FUNCTION|FUNC|GLOBAL RECORD|LABEL|RECORD|SELECT|SUB|WHILE|DOTIMES|WITH)[ \\t]|^(DEFAULT|REPEAT|USEC|USEH|DO$)|^IF.+THEN$|^ELIF.+THEN$|^ELSE$") ){
                        nextposition = nextposition + (1);
                        if( REGEX(line_input, "^SELECT") ){
                            nextposition = nextposition + (1);
                        }
                        if( __b2c__STRCMP(LEFT(line_input, 5) ,  "LABEL") == 0 ){
                            label_active=(
                            long)( TRUE);
                        }
                    }
                    if( __b2c__STRCMP(RIGHT(line_input, 2) ,  CONCAT( CHR(32) , CHR(92) )) == 0  AND  NOT(REGEX(line_input, "^(REM|')")) ){
                        if( NOT(wrap_active) ){
                            nextposition = nextposition + (1);
                        }
                        wrap_active=(
                        long)( TRUE);
                    } else {
                        if( wrap_active ){
                            nextposition = nextposition - (1);
                        }
                        wrap_active=(
                        long)( FALSE);
                    }
                    if( REGEX(previous, "^(REM|')") ){
                        result = b2c_CopyString(result, (char*) CHANGE(result, AMOUNT(result, NL)-1, CONCAT( TAB(myposition) , previous) , NL));
                    }
                    if( LEN(line_input) ){
                        result = F_CONCAT(result, result , TAB(myposition) , line_input , NL) ;
                    } else {
                        result = F_CONCAT(result, result , NL) ;
                    }
                    previous = b2c_CopyString(previous, (char*) line_input);
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                text = F_CHOP(text,result);
                Editor_Print_Text(text, start, visual_begin_pos);
                fprintf(stdout,"\033[?25l"); fflush(stdout);
                fputs("\033[5m", stdout); fflush(stdout);
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
            fprintf(stdout, "%sIndentation done, press a key to continue...", CL);
                fflush(stdout);
                key=(
                long)( GETKEY);
                fputs("\033[25m", stdout); fflush(stdout);
                fprintf(stdout,"\033[?25h"); fflush(stdout);
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (5)){
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                prog = F_CONCAT(prog, DIRNAME(file) , "/" , BASENAME(file, 1)) ;
                if( FILEEXISTS(prog) ){
                if(unlink(prog)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 7337, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                }
                ERROR = b2c_save(0, 0, file, CHOP(text), NULL);
            if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7338, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            fprintf(stdout, "Current BaCon command line options: %s\n", IIF(LEN(option)==0, "<none set>", option));
            fputs("Do you want to set new options (y/[n]) ? ", stdout);
                fflush(stdout);
                if( GETKEY == ASC("y") ){
                    ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
                if(ERROR){ RUNTIMEERROR("SETSERIAL", 7342, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                fprintf(stdout, "%sEnter new options: ", NL);
                    fflush(stdout);
                    b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                    option = b2c_CopyString(option, b2c_assign);
                    __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
                    ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
                if(ERROR){ RUNTIMEERROR("SETSERIAL", 7344, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                }
            fprintf(stdout, "%s%s\n", NL, CONCAT( "Executing 'bacon " , option , " -d " , DIRNAME(file) , " " , file , "'..."));
            RETVAL = system(CONCAT( "bacon " , option , " -d " , DIRNAME(file) , " " , file) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
                if( FILEEXISTS(prog) ){
                fputs("Execute ([y]/n) ? ", stdout);
                    fflush(stdout);
                    key=(
                    long)( GETKEY);
                    fputs("\n", stdout);
                    if( key == ASC("y")  OR  key == 10 ){
                    fprintf(stdout, "Current program arguments: %s\n", IIF(LEN(arg)==0, "<none set>", arg));
                    fputs("Do you want to set new program arguments (y/[n]) ? ", stdout);
                        fflush(stdout);
                        if( GETKEY == ASC("y") ){
                            ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
                        if(ERROR){ RUNTIMEERROR("SETSERIAL", 7356, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                        fprintf(stdout, "%sEnter new arguments (<enter> means none)... ", NL);
                            fflush(stdout);
                            b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                            arg = b2c_CopyString(arg, b2c_assign);
                            __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
                            ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
                        if(ERROR){ RUNTIMEERROR("SETSERIAL", 7358, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                        }
                        fprintf(stdout,"\033[?47l"); fflush(stdout);
                        fprintf(stdout, "\033[%ld;%ldH",(long)( GETY),(long)(1));fflush(stdout);
                        ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, IXON, 0);
                    if(ERROR){ RUNTIMEERROR("SETSERIAL", 7362, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                        ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  3, 0);
                    if(ERROR){ RUNTIMEERROR("SETSERIAL", 7363, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                        ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
                    if(ERROR){ RUNTIMEERROR("SETSERIAL", 7364, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    RETVAL = system(CONCAT( prog , " " , arg) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
                        ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, ~IXON, 1);
                    if(ERROR){ RUNTIMEERROR("SETSERIAL", 7366, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                        ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  17, 0);
                    if(ERROR){ RUNTIMEERROR("SETSERIAL", 7367, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                        ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
                    if(ERROR){ RUNTIMEERROR("SETSERIAL", 7368, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    }
                }
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
            fprintf(stdout, "%sPress a key to continue...", CL);
                fflush(stdout);
                key=(
                long)( GETKEY);
                fputs("\n", stdout);
                fprintf(stdout,"\033[?47h"); fflush(stdout);
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (6)){
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
            if(ERROR){ RUNTIMEERROR("SETSERIAL", 7384, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            fprintf(stdout, "%sEnter term... ", CL);
                fflush(stdout);
                b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                word = b2c_CopyString(word, b2c_assign);
                __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
                ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
            if(ERROR){ RUNTIMEERROR("SETSERIAL", 7386, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            fputs("Searching...", stdout);
                fflush(stdout);
                total=(
                long)( WHERE(text, start+ypos-1, NL)+visual_xpos-1);
                next=(
                long)( INSTR(MID(text, total), word));
                while( (next )> 0 ){
                    line=(
                    long)( AMOUNT(MID(text, 1, total+next), NL));
                    start=(
                    long)( IIF((line-ROWS/2 )< 1, 1, line-ROWS/2));
                    fputs("\033[0m", stdout); fflush(stdout);
                    if( Color_Intense ){
                        fputs("\033[1m", stdout); fflush(stdout);
                    }
                    Editor_Print_Text(text, start, visual_begin_pos);
                    ypos=(
                    long)( ROWS/2+1);
                    fprintf(stdout, "\033[%ld;%ldH",(long)( IIF(start == 1, line, ypos)),(long)(1));fflush(stdout);
                    Editor_Print_Line(TOKEN(text, IIF(start == 1, start+line-1, start+ypos-1), NL), 1, IIF(start == 1, start+line-1, start+ypos-1), TRUE, digits, TRUE);
                    fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                    fputs("\033[0m", stdout); fflush(stdout);
                    if( Color_Intense ){
                        fputs("\033[1m", stdout); fflush(stdout);
                    }
                    fputs("\033[7m", stdout); fflush(stdout);
                fprintf(stdout, "%sPress [n] for next item, any other key to quit...", CL);
                    fflush(stdout);
                    if( GETKEY != ASC("n") ){
                        key=(
                        long)( 255);
                        break;
                    }
                    fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fprintf(stdout, "%sSearching...", CL);
                    fflush(stdout);
                    total = total + ( next);
                    next=(
                    long)( INSTR(MID(text, total+1), word));
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                if( key != 255 ){
                    fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fprintf(stdout, "%sSearch ended. Press a key to continue...", CL);
                    fflush(stdout);
                    key=(
                    long)( GETKEY);
                }
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (14)){
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                if( HASH(text) != cksum ){
                fprintf(stdout, "%sCode has changed! Save current to file '%s' first (y/n)?", CL, file);
                    fflush(stdout);
                    if( GETKEY == ASC("y") ){
                        ERROR = b2c_save(0, 0, file, CHOP(text), NULL);
                    if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7430, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    fprintf(stdout, "%s", CONCAT( " File '" , BASENAME(file) , "' saved! Press a key to continue..."));
                        fflush(stdout);
                        key=(
                        long)( GETKEY);
                    }
                }
                start=(
                long)( 1);
                visual_begin_pos=(
                long)( 1);
                visual_xpos=(
                long)( 1);
                ypos=(
                long)( 1);
                text = b2c_CopyString(text, (char*) "");
                file = b2c_CopyString(file, (char*) "");
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (12)){
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                if( HASH(text) != cksum ){
                fprintf(stdout, "%sCode has changed! Save current to file '%s' first (y/n)?", CL, file);
                    fflush(stdout);
                    if( GETKEY == ASC("y") ){
                        ERROR = b2c_save(0, 0, file, CHOP(text), NULL);
                    if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7451, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    fprintf(stdout, "%s", CONCAT( " File '" , BASENAME(file) , "' saved! Press a key to continue..."));
                        fflush(stdout);
                        key=(
                        long)( GETKEY);
                    }
                    fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                }
                ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
            if(ERROR){ RUNTIMEERROR("SETSERIAL", 7457, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            fprintf(stdout, "%sEnter file name to load... ", CL);
                fflush(stdout);
                b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                answer = b2c_CopyString(answer, b2c_assign);
                __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
                ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
            if(ERROR){ RUNTIMEERROR("SETSERIAL", 7459, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                if( NOT(FILEEXISTS(answer)) ){
                    fprintf(stdout,"\033[%ld%ldm", (long)3, (long)1); fflush(stdout);
                fputs("WARNING: File does not exist!\n", stdout);
                    fputs("\033[0m", stdout); fflush(stdout);
                    if( Color_Intense ){
                        fputs("\033[1m", stdout); fflush(stdout);
                    }
                fprintf(stdout, "%sPress a key to continue...", CL);
                    fflush(stdout);
                    key=(
                    long)( GETKEY);
                } else {
                    file = b2c_CopyString(file, (char*) answer);
                    text = b2c_CopyString(text, (char*) LOAD(file));
                    start=(
                    long)( 1);
                    visual_begin_pos=(
                    long)( 1);
                }
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (19)){
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                if( LEN(file) ){
                    ERROR = b2c_save(0, 0, file, CHOP(text), NULL);
                if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7481, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                fprintf(stdout, "%s%s", CL, CONCAT( "File '" , BASENAME(file) , "' saved!"));
                    fflush(stdout);
                    cksum=(
                    long)( HASH(text));
                } else {
                    answer = b2c_CopyString(answer, (char*) "y");
                    ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
                if(ERROR){ RUNTIMEERROR("SETSERIAL", 7487, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                fprintf(stdout, "%sEnter file name... ", CL);
                    fflush(stdout);
                    b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                    file = b2c_CopyString(file, b2c_assign);
                    __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
                    ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
                if(ERROR){ RUNTIMEERROR("SETSERIAL", 7489, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    if( FILEEXISTS(file) ){
                    fprintf(stdout, "File '%s' exists! Overwrite (y/n)?\n", file);
                    }
                    fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
                    if( GETKEY == ASC("y") ){
                        ERROR = b2c_save(0, 0, file, CHOP(text), NULL);
                    if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7493, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    fprintf(stdout, "%s", CONCAT( "File '" , BASENAME(file) , "' saved!"));
                        fflush(stdout);
                        cksum=(
                        long)( HASH(text));
                    } else {
                    fputs("File NOT saved.", stdout);
                        fflush(stdout);
                    }
                }
            fputs(" Press a key to continue...", stdout);
                fflush(stdout);
                key=(
                long)( GETKEY);
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (2)){
                Color_Intense=(long)( NOT(Color_Intense));
                if( FILEEXISTS( CONCAT(GETENVIRON("HOME") , "/.bacon/bacon.cfg" ) ) ){
                    result = b2c_CopyString(result, (char*) COLLAPSE(LOAD( CONCAT(GETENVIRON("HOME") , "/.bacon/bacon.cfg") ), NL));
                    for(x=1; x <= AMOUNT(result, NL); x+=1){
                        if( REGEX(TOKEN(result, x, NL), "^intense") ){
                            result = b2c_CopyString(result, (char*) DEL(result, x, NL));
                        }
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    ERROR = b2c_save(0, 0, CONCAT( GETENVIRON("HOME") , "/.bacon/bacon.cfg"), APPEND(result, 0, CONCAT( "intense " , STR(Color_Intense)) , NL), NULL);
                if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7512, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                } else {
                    ERROR = b2c_save(0, 0, CONCAT( GETENVIRON("HOME") , "/.bacon/bacon.cfg"), CONCAT( "intense " , STR(Color_Intense) ), NULL);
                if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7514, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                }
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (23)){
                text = b2c_CopyString(text, (char*) DEL(text, start+ypos-1, NL));
                if( (ypos )> AMOUNT(text, NL)-start+1  AND  (ypos )> 1 ){
                    ypos = ypos - (1);
                }
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (8)){
                fprintf(stdout,"\033[?25l"); fflush(stdout);
                Editor_Show_Help();
                fprintf(stdout,"\033[?25h"); fflush(stdout);
                do_print=(
                long)( TRUE);
            } else  if ( (b2c_select_7182) == (27)){
                special=(
                long)( WAIT(STDIN_FILENO, 100));
                b2c_select_7534 = (double)special;
                if ( (b2c_select_7534) == (79) || (b2c_select_7534) == ( 91)){
                    cursor=(
                    long)( WAIT(STDIN_FILENO, 100));
                    b2c_select_7538 = (double)cursor;
                    if ( (b2c_select_7538) == (66)){
                        if( start+ypos-1 == AMOUNT(text, NL)  AND  (LEN(TOKEN(text, start+ypos-1, NL)) )> 0 ){
                            text = F_APPEND(text,text, 0, "", NL);
                            ypos=(
                            long)( AMOUNT(text, NL));
                            if( (ypos )> ROWS ){
                                start=(
                                long)( AMOUNT(text, NL) - ROWS + 1);
                            }
                            do_print=(
                            long)( TRUE);
                        } else if( (start+ypos-1 )< AMOUNT(text, NL) ){
                            ypos = ypos + (1);
                        }
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        x=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        while( (x )< visual_begin_pos - 1 + visual_xpos ){
                            x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                            real_xpos = real_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        x=(
                        long)( 1);
                        visual_xpos=(
                        long)( 1);
                        while( (x )< real_xpos ){
                            visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID(line, x, 1) ,  CHR(9)) == 0, 4, 1));
                            x = x + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        visual_xpos = visual_xpos - ( visual_begin_pos-1);
                    } else  if ( (b2c_select_7538) == (65)){
                        ypos = ypos - (1);
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        x=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        while( (x )< visual_begin_pos - 1 + visual_xpos ){
                            x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                            real_xpos = real_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        x=(
                        long)( 1);
                        visual_xpos=(
                        long)( 1);
                        while( (x )< real_xpos ){
                            visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID(line, x, 1) ,  CHR(9)) == 0, 4, 1));
                            x = x + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        visual_xpos = visual_xpos - ( visual_begin_pos-1);
                    } else  if ( (b2c_select_7538) == (67)){
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                        real_xpos = real_xpos + (1);
                    } else  if ( (b2c_select_7538) == (68)){
                        real_xpos = real_xpos - (1);
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        visual_xpos = visual_xpos - ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                    } else  if ( (b2c_select_7538) == (51)){
                        delkey=(
                        long)( WAIT(STDIN_FILENO, 100));
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        if( delkey == 126 ){
                            if( (real_xpos )> LEN(line) ){
                                text = b2c_CopyString(text, (char*) CHANGE(text, start+ypos-1, CONCAT( line , SPC(real_xpos-LEN(line)-1) , TOKEN(text, start+ypos, NL)) , NL));
                                text = b2c_CopyString(text, (char*) DEL(text, start+ypos, NL));
                                do_print=(
                                long)( TRUE);
                            } else {
                                line = b2c_CopyString(line, (char*) RIP(line, real_xpos, 1));
                                text = b2c_CopyString(text, (char*) CHANGE(text, start+ypos-1, line, NL));
                                line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                                if( real_xpos == LEN(line)+1  AND  (real_xpos )> 1 ){
                                    real_xpos = real_xpos - (1);
                                }
                                x=(
                                long)( 1);
                                visual_xpos=(
                                long)( 1);
                                while( (x )< real_xpos ){
                                    visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID(line, x, 1) ,  CHR(9)) == 0, 4, 1));
                                    x = x + (1);
                                }
                        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                                visual_xpos = visual_xpos - ( visual_begin_pos-1);
                                do_print=(
                                long)( TRUE);
                            }
                        } else if( delkey == 59 ){
                            delkey=(
                            long)( WAIT(STDIN_FILENO, 100));
                            delkey=(
                            long)( WAIT(STDIN_FILENO, 100));
                            text = b2c_CopyString(text, (char*) DEL(text, start+ypos-1, NL));
                            if( (ypos )> AMOUNT(text, NL)-start+1  AND  (ypos )> 1 ){
                                ypos = ypos - (1);
                            }
                            do_print=(
                            long)( TRUE);
                        }
                    } else  if ( (b2c_select_7538) == (72) || (b2c_select_7538) == ( 49)){
                        if( cursor == 49 ){
                            delkey=(
                            long)( WAIT(STDIN_FILENO, 100));
                        }
                        visual_xpos=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        visual_begin_pos=(
                        long)( 1);
                        do_print=(
                        long)( TRUE);
                    } else  if ( (b2c_select_7538) == (70) || (b2c_select_7538) == ( 52)){
                        if( cursor == 52 ){
                            delkey=(
                            long)( WAIT(STDIN_FILENO, 100));
                        }
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        line = b2c_CopyString(line, (char*) REPLACE(line, CHR(9), SPC(4)));
                        visual_xpos=(
                        long)( LEN(line) - visual_begin_pos + 1);
                        if( (visual_xpos )> display_columns ){
                            visual_begin_pos=(
                            long)( LEN(line) - display_columns + 1);
                            visual_xpos=(
                            long)( display_columns);
                            do_print=(
                            long)( TRUE);
                        }
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        x=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        while( (x )< visual_begin_pos - 1 + visual_xpos ){
                            x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                            real_xpos = real_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    } else  if ( (b2c_select_7538) == (53)){
                        page=(
                        long)( WAIT(STDIN_FILENO, 100));
                        if( page == 126 ){
                            if( (start )> ROWS ){
                                start = start - ( ROWS);
                            } else {
                                start=(
                                long)( 1);
                            }
                            do_print=(
                            long)( TRUE);
                        }
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        x=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        while( (x )< visual_begin_pos - 1 + visual_xpos ){
                            x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                            real_xpos = real_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        x=(
                        long)( 1);
                        visual_xpos=(
                        long)( 1);
                        while( (x )< real_xpos ){
                            visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID(line, x, 1) ,  CHR(9)) == 0, 4, 1));
                            x = x + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        visual_xpos = visual_xpos - ( visual_begin_pos-1);
                    } else  if ( (b2c_select_7538) == (54)){
                        page=(
                        long)( WAIT(STDIN_FILENO, 100));
                        if( page == 126 ){
                            if( (start + 2*ROWS - 1 )< AMOUNT(text, NL) ){
                                start = start + ( ROWS);
                            } else {
                                start=(
                                long)( AMOUNT(text, NL)-ROWS+1);
                                if( (start )< 1 ){
                                    start=(
                                    long)( 1);
                                }
                            }
                            do_print=(
                            long)( TRUE);
                        }
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        x=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        while( (x )< visual_begin_pos - 1 + visual_xpos ){
                            x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                            real_xpos = real_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        x=(
                        long)( 1);
                        visual_xpos=(
                        long)( 1);
                        while( (x )< real_xpos ){
                            visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID(line, x, 1) ,  CHR(9)) == 0, 4, 1));
                            x = x + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        visual_xpos = visual_xpos - ( visual_begin_pos-1);
                    }
                    if( (ypos )< 1 ){
                        start = start - (1);
                        ypos=(
                        long)( 1);
                        if( (start )< 1 ){
                            start=(
                            long)( 1);
                        } else {
                            fprintf(stdout,"\033[%ldT", (long)1); fflush(stdout);
                            line = b2c_CopyString(line, (char*) TOKEN(text, start, NL));
                            do_print=(
                            long)( TRUE);
                        }
                    }
                    if( (ypos )> ROWS ){
                        start = start + (1);
                        ypos=(
                        long)( ROWS);
                        if( (start+ROWS-1 )> AMOUNT(text, NL) ){
                            start=(
                            long)( AMOUNT(text, NL) - ROWS + 1);
                        } else {
                            fprintf(stdout,"\033[%ldS", (long)1); fflush(stdout);
                            line = b2c_CopyString(line, (char*) TOKEN(text, start+ROWS-1, NL));
                            do_print=(
                            long)( TRUE);
                        }
                    }
                    if( (visual_xpos )< 1 ){
                        while( (visual_begin_pos )> 1  AND  (visual_xpos )< 1 ){
                            visual_begin_pos = visual_begin_pos - (1);
                            visual_xpos = visual_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        if( (visual_begin_pos )< 1 ){
                            visual_begin_pos=(
                            long)( 1);
                        }
                        visual_xpos=(
                        long)( 1);
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        x=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        while( (x )< visual_begin_pos - 1 + visual_xpos ){
                            x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                            real_xpos = real_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        do_print=(
                        long)( TRUE);
                    }
                    if( (visual_xpos )> display_columns ){
                        visual_begin_pos = visual_begin_pos + (1);
                        visual_xpos=(
                        long)( display_columns);
                        line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                        x=(
                        long)( 1);
                        real_xpos=(
                        long)( 1);
                        while( (x )< visual_begin_pos - 1 + visual_xpos ){
                            x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                            real_xpos = real_xpos + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        if( (visual_begin_pos - 1 + visual_xpos )> display_columns  AND  __b2c__STRCMP(MID(line, real_xpos-1, 1) ,  CHR(9)) == 0 ){
                            visual_begin_pos = visual_begin_pos + ( 3);
                        }
                        do_print=(
                        long)( TRUE);
                    }
                }
            } else  if ( (b2c_select_7182) == (127)){
                if( (real_xpos )> 1 ){
                    line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                    if( real_xpos <= LEN(line)+1 ){
                        line = F_CONCAT(line, LEFT(line, real_xpos-2) , MID(line, real_xpos)) ;
                        text = b2c_CopyString(text, (char*) CHANGE(text, start+ypos-1, line, NL));
                    }
                    real_xpos = real_xpos - (1);
                    line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                    x=(
                    long)( 1);
                    visual_xpos=(
                    long)( 1);
                    while( (x )< real_xpos ){
                        visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID(line, x, 1) ,  CHR(9)) == 0, 4, 1));
                        x = x + (1);
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    visual_xpos = visual_xpos - ( visual_begin_pos-1);
                    if( (visual_xpos )< 1 ){
                        while( (visual_begin_pos )> 1 ){
                            visual_begin_pos = visual_begin_pos - (1);
                            visual_xpos = visual_xpos + (1);
                            if( visual_xpos == 1 ){
                                break;
                            }
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    }
                    do_print=(
                    long)( TRUE);
                } else if( NOT(ypos == 1  AND  start == 1) ){
                    line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-2, NL));
                    line = b2c_CopyString(line, (char*) REPLACE(line, CHR(9), SPC(4)));
                    visual_xpos=(
                    long)( LEN(line) - visual_begin_pos + 2);
                    line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                    text = b2c_CopyString(text, (char*) CHANGE(text, start+ypos-2, CONCAT( TOKEN(text, start+ypos-2, NL) , line) , NL));
                    text = b2c_CopyString(text, (char*) DEL(text, start+ypos-1, NL));
                    if( AMOUNT(text, NL) <= ROWS ){
                        ypos = ypos + ( start-1);
                        start=(
                        long)( 1);
                    }
                    if( (ypos )> 1 ){
                        ypos = ypos - (1);
                    } else {
                        start = start - ( IIF((start )> 1, 1, 0));
                    }
                    line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                    line = b2c_CopyString(line, (char*) REPLACE(line, CHR(9), SPC(4)));
                    if( (visual_xpos )> display_columns ){
                        visual_begin_pos=(
                        long)( visual_xpos - display_columns + 1);
                        visual_xpos=(
                        long)( display_columns);
                    }
                    line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                    x=(
                    long)( 1);
                    real_xpos=(
                    long)( 1);
                    while( (x )< visual_begin_pos - 1 + visual_xpos ){
                        x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                        real_xpos = real_xpos + (1);
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    do_print=(
                    long)( TRUE);
                }
            } else  if ( (b2c_select_7182) == (10)){
                line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                if( (visual_xpos )> LEN(REPLACE(line, CHR(9), SPC(4))) ){
                    text = F_APPEND(text,text, start+ypos, "", NL);
                } else {
                    text = b2c_CopyString(text, (char*) CHANGE(text, start+ypos-1, LEFT(line, real_xpos-1), NL));
                    text = F_APPEND(text,text, start+ypos, MID(line, real_xpos), NL);
                }
                if( ypos == ROWS ){
                    start = start + (1);
                }
                if( (ypos )< ROWS ){
                    ypos = ypos + (1);
                }
                visual_xpos=(
                long)( 1);
                real_xpos=(
                long)( 1);
                visual_begin_pos=(
                long)( 1);
                do_print=(
                long)( TRUE);
            } else {
                line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                if( (key )< 32  AND  key != 9 ){
                    key=(
                    long)( 32);
                }
                if( (real_xpos )> LEN(line) ){
                    line = F_CONCAT(line, line , SPC(real_xpos-LEN(line)-1) , CHR(key)) ;
                } else {
                    line = b2c_CopyString(line, (char*) INSERT(line, real_xpos, CHR(key)));
                }
                text = b2c_CopyString(text, (char*) CHANGE(text, start+ypos-1, line, NL));
                if( (visual_xpos )< display_columns ){
                    visual_xpos = visual_xpos + ( IIF(key == 9, 4, 1));
                } else {
                    visual_begin_pos = visual_begin_pos + ( IIF(key == 9, 4, 1));
                }
                line = b2c_CopyString(line, (char*) TOKEN(text, start+ypos-1, NL));
                x=(
                long)( 1);
                real_xpos=(
                long)( 1);
                while( (x )< visual_begin_pos - 1 + visual_xpos ){
                    x = x + ( IIF(__b2c__STRCMP(MID(line, real_xpos, 1) ,  CHR(9)) == 0, 4, 1));
                    real_xpos = real_xpos + (1);
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(1));fflush(stdout);
                if( __b2c__STRCMP(RIGHT(TOKEN(text, start+ypos-2, NL), 2) ,  CONCAT( CHR(32) , CHR(92) )) == 0 ){
                    do_print=(
                    long)( TRUE);
                } else {
                    Editor_Print_Line(line, visual_begin_pos, start+ypos-1, FALSE, digits, TRUE);
                }
            }
            if( do_print ){
                Editor_Print_Text(text, start, visual_begin_pos);
            }
            do_print=(
            long)( FALSE);
            if( copy_flag ){
                fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(COLUMNS/2-15));fflush(stdout);
                fputs("\033[0m", stdout); fflush(stdout);
                if( Color_Intense ){
                    fputs("\033[1m", stdout); fflush(stdout);
                }
                fputs("\033[5m", stdout); fflush(stdout);
            fprintf(stdout, "%s---=== line copied to clipboard ===---", CL);
                fflush(stdout);
                fputs("\033[25m", stdout); fflush(stdout);
            }
        } while(!( special == 0  AND  key == 27 ));
if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
        fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
        fputs("\033[0m", stdout); fflush(stdout);
        if( Color_Intense ){
            fputs("\033[1m", stdout); fflush(stdout);
        }
    fprintf(stdout, "%sPress (H) for Help, (Q) to quit, any other key to continue...", CL);
        fflush(stdout);
        key=(
        long)( GETKEY);
        b2c_select_7896 = b2c_CopyString(b2c_select_7896, LCASE(CHR(key)));
        if ( !b2c_strcmp(b2c_select_7896, "h")){
            Editor_Show_Help();
        } else  if ( !b2c_strcmp(b2c_select_7896, "q")){
            break;
        }
        Editor_Print_Text(text, start, visual_begin_pos);
    }
    Editor_Restore_Normal();
    __b2c__STRFREE(b2c_forin_line_input_string); b2c_forin_line_input_string = NULL; __b2c__STRFREE(b2c_forin_line_input_step); b2c_forin_line_input_step = NULL;
    __b2c__STRFREE(file);
    __b2c__STRFREE(text);
    __b2c__STRFREE(line);
    __b2c__STRFREE(prog);
    __b2c__STRFREE(answer);
    __b2c__STRFREE(option);
    __b2c__STRFREE(man);
    __b2c__STRFREE(str);
    __b2c__STRFREE(result);
    __b2c__STRFREE(copy_line);
    __b2c__STRFREE(word);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(line_input);
    __b2c__STRFREE(b2c_select_7896);
    __B2C__PROGRAM__EXIT: ;
    b2c_catch_set = b2c_catch_set_backup;
}
