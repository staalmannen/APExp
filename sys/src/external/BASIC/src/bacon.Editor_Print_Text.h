/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Editor_Print_Text( char *__b2c_txt, long line, long verticalpos) {
    char*txt = NULL; txt = b2c_CopyString(NULL, __b2c_txt); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    long y = 0;
    long nr = 0;
    long total_lines = 0;
    long digits = 0;
    char *line = NULL;
    total_lines=(
    long)( AMOUNT(txt, NL));
    if( total_lines == 0 ){
        total_lines=(
        long)( 1);
    }
    digits=(
    long)( LEN(STR(AMOUNT(txt, NL))));
    fprintf(stdout,"\033[?25l"); fflush(stdout);
    nr=(
    long)( line);
    while( __b2c__STRCMP(RIGHT(TOKEN(txt, nr-1, NL), 2) ,  CONCAT( CHR(32) , CHR(92))) == 0 ){
        nr = nr - (1);
    }
    if( (nr )< line ){
        for(y=nr; y <= line-1; y+=1){
            line = b2c_CopyString(line, (char*) TOKEN(txt, y, NL));
            Editor_Print_Line(line, 1, y, FALSE, digits, FALSE);
        }
    }
    for(y=1; y <= ROWS; y+=1){
        fprintf(stdout, "\033[%ld;%ldH",(long)( y),(long)(1));fflush(stdout);
        if( line <= total_lines ){
            line = b2c_CopyString(line, (char*) TOKEN(txt, line, NL));
            line = b2c_CopyString(line, (char*) REPLACE(line, CHR(9), SPC(4)));
            Editor_Print_Line(line, verticalpos, line, FALSE, digits, TRUE);
        } else {
        fprintf(stdout, "%s", CL);
            fflush(stdout);
        }
        line = line + (1);
    }
    Editor_Print_Line("", 1, 1, FALSE, 0, FALSE);
    fprintf(stdout,"\033[?25h"); fflush(stdout);

    __b2c__STRFREE(txt);
    __b2c__STRFREE(line);
    b2c_catch_set = b2c_catch_set_backup;
}
