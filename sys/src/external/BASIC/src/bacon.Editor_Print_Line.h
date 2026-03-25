/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Editor_Print_Line( char *__b2c_text, long vpos, long linenr, long inverse, int digits, long do_print) {
    char*text = NULL; text = b2c_CopyString(NULL, __b2c_text); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    long x = 0;
    long in_line_comment = 0;
    long in_escaped = 0;
    long pos = 0;
    long len = 0;
    long display_columns = 0;
    long newcol = 0;
    long lastcol = 0;
    char *term = NULL;
    char *c1 = NULL;
    char *c2 = NULL;
    char *color = NULL;
    static int in_block_comment = 0;
    static int in_string = 0;
    text = b2c_CopyString(text, (char*) REPLACE(text, CHR(9), SPC(4)));
    len=(
    long)( LEN(text));
    for(x=0; x <= len-1; x+=1){
        c1 = F_MID(c1,text, x+1, 1);
        c2 = F_MID(c2,text, x+1, 2);
        if( __b2c__STRCMP(c1 ,  "\\") == 0  AND  NOT(in_line_comment)  AND  NOT(in_block_comment) ){
            if( in_escaped ){
                in_escaped=(
                long)( 0);
            } else {
                in_escaped=(
                long)( 1);
            }
        } else if( __b2c__STRCMP(c1 ,  "\"") == 0  AND  NOT(in_escaped)  AND  NOT(in_line_comment)  AND  NOT(in_block_comment) ){
            in_string=(
            int)( 1 - in_string);
        } else if( __b2c__STRCMP(c2 ,  "/*") == 0  AND  NOT(in_string)  AND  NOT(in_line_comment) ){
            in_block_comment=(
            int)( TRUE);
            in_escaped=(
            long)( FALSE);
            } else if( __b2c__STRCMP(c1 ,  "'") == 0  OR  REGEX(MID(text, x+1, 4), "REM[[:space:]]+")  OR  (__b2c__STRCMP(MID(text, x+1, 3) ,  "REM") == 0  AND  x == LEN(text)-3) ){
            if( NOT(in_string)  AND  NOT(in_block_comment) ){
            in_line_comment=(
            long)( TRUE);
            in_escaped=(
            long)( FALSE);
            }
            } else if( __b2c__STRCMP(c1 ,  NL) == 0  AND  NOT(in_string)  AND  NOT(in_block_comment) ){
            in_line_comment=(
            long)( FALSE);
            in_escaped=(
            long)( FALSE);
            } else {
            in_escaped=(
            long)( FALSE);
            }
            if( in_string ){
            color = F_CONCAT(color, color , STR(Quot_Col)) ;
            } else if( in_block_comment ){
            if( __b2c__STRCMP(MID(text, x+1, 2) ,  "*/") == 0 ){
            color = F_CONCAT(color, color , STR(Comm_Col) , STR(Comm_Col)) ;
            in_block_comment=(
            int)( FALSE);
            x = x + (1);
        } else {
            color = F_CONCAT(color, color , STR(Comm_Col)) ;
        }
    } else if( in_line_comment ){
        color = F_CONCAT(color, color , STR(Comm_Col)) ;
    } else if( (__b2c__STRCMP(MID(text, x+1, 1) , b2c_min_str( CHR(48) , CHR(57))) >= 0 && __b2c__STRCMP(MID(text, x+1, 1) , b2c_max_str( CHR(48) , CHR(57))) <= 0 ? 1 : 0) ){
        color = F_CONCAT(color, color , STR(Num_Col)) ;
    } else if( __b2c__STRCMP(MID(text, x+1, 1) ,  CHR(34)) == 0 ){
        color = F_CONCAT(color, color , STR(Quot_Col)) ;
    } else if( __b2c__STRCMP(MID(text, x+1, 1) ,  CHR(38)) == 0 ){
        color = F_CONCAT(color, color , STR(Func_Col)) ;
    } else {
        pos=(
        long)( REGEX(MID(text, x+1), "[[:space:]]|[=,?;:+-/\\(\\)\\*]|\\||\\[|\\]")-1);
        if( (pos )< 0 ){
            pos=(
            long)( len-x);
        }
        term = F_CONCAT(term, "|" , MID(text, x+1, pos) , "|") ;
        if( TALLY(Stat, term) ){
            color = F_CONCAT(color, color , FILL(pos, ASC(STR(Stat_Col)))) ;
        } else if( TALLY(EXTRACT(Func, "\\"), term) ){
            color = F_CONCAT(color, color , FILL(pos, ASC(STR(Func_Col)))) ;
        } else if( TALLY(EXTRACT(Var, "\\"), term) ){
            color = F_CONCAT(color, color , FILL(pos, ASC(STR(Var_Col)))) ;
        } else if( TALLY(Type, term) ){
            color = F_CONCAT(color, color , FILL(pos, ASC(STR(Type_Col)))) ;
        } else {
            color = F_CONCAT(color, color , FILL(pos, ASC(STR(Def_Col)))) ;
        }
        color = F_CONCAT(color, color , STR(Def_Col)) ;
        x = x + ( pos);
    }
}
if( do_print ){
    fputs("\033[0m", stdout); fflush(stdout);
    if( inverse ){
        fputs("\033[7m", stdout); fflush(stdout);
    }
    if( Color_Intense ){
        fputs("\033[1m", stdout); fflush(stdout);
    }
fprintf(stdout, "%s", CL);
    fflush(stdout);
    if( Line_Number_Active ){
        display_columns=(
        long)( COLUMNS-digits-1);
        fprintf(stdout,"\033[%ld%ldm", (long)3, (long)3); fflush(stdout);
        fprintf(stdout, "%*ld ", digits, linenr);
    } else {
        display_columns=(
        long)( COLUMNS);
    }
    for(x=vpos; x <= len; x+=1){
        if( x-vpos+1 <= display_columns ){
            newcol=(
            long)( VAL(MID(color, x, 1)));
            if( newcol == Comm_Col ){
                fputs("\033[3m", stdout); fflush(stdout);
            } else {
                fputs("\033[23m", stdout); fflush(stdout);
            }
            if( lastcol != newcol ){
                fprintf(stdout,"\033[%ld%ldm", (long)3, (long)newcol); fflush(stdout);
            }
        fprintf(stdout, "%s", MID(text, x, 1));
            fflush(stdout);
            lastcol=(
            long)( newcol);
        }
    }
}
if( in_string  AND  __b2c__STRCMP(RIGHT(text, 2) ,  CONCAT( CHR(32) , CHR(92) )) != 0 ){
    in_string=(
    int)( 0);
}

__b2c__STRFREE(text);
__b2c__STRFREE(term);
__b2c__STRFREE(c1);
__b2c__STRFREE(c2);
__b2c__STRFREE(color);
b2c_catch_set = b2c_catch_set_backup;
}
