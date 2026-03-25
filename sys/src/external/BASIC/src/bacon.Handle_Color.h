/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Color( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0; char *b2c_select_2852 = NULL; char *b2c_select_2866 = NULL; char *b2c_select_2883 = NULL;
    char *bfg = NULL;
    char *col = NULL;
    long total = 0;
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "COLOR * TO *", b2c_option_delim);
    total = match__b2c_array;
    b2c_select_2852 = b2c_CopyString(b2c_select_2852, match[(uint64_t)1]);
    if ( !b2c_strcmp(b2c_select_2852, "RESET")){
    fputs("fputs(\"\\033[0m\", stdout); fflush(stdout);\n", g_CFILE);
    } else  if ( !b2c_strcmp(b2c_select_2852, "INTENSE")){
    fputs("fputs(\"\\033[1m\", stdout); fflush(stdout);\n", g_CFILE);
    } else  if ( !b2c_strcmp(b2c_select_2852, "INVERSE")){
    fputs("fputs(\"\\033[7m\", stdout); fflush(stdout);\n", g_CFILE);
    } else  if ( !b2c_strcmp(b2c_select_2852, "NORMAL")){
    fputs("fputs(\"\\033[22m\", stdout); fflush(stdout);\n", g_CFILE);
    } else {
        if( total <= 1 ){
        fprintf(stderr, "%sSyntax error: missing TO in COLOR statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        } else {
            b2c_select_2866 = b2c_CopyString(b2c_select_2866, match[(uint64_t)1]);
            if ( !b2c_strcmp(b2c_select_2866, "FG")){
                bfg = b2c_CopyString(bfg, (char*) "3");
            } else  if ( !b2c_strcmp(b2c_select_2866, "BG")){
                bfg = b2c_CopyString(bfg, (char*) "4");
            } else {
                if( REGEX(match[(uint64_t)1], "0|1") ){
                    bfg = b2c_CopyString(bfg, (char*) STR(VAL(match[(uint64_t)1]) + 3));
                }
                else {
                    bfg = b2c_CopyString(bfg, (char*) match[(uint64_t)1]);
                }
            }
            if( ISTOKEN(match[(uint64_t)2], "INTENSE") ){
            fputs("fputs(\"\\033[1m\", stdout); fflush(stdout);\n", g_CFILE);
                match[(uint64_t)2] = b2c_CopyString(match[(uint64_t)2], (char*) DEL(match[(uint64_t)2], ISTOKEN(match[(uint64_t)2], "INTENSE")));
            }
            if( ISTOKEN(match[(uint64_t)2], "NORMAL") ){
            fputs("fputs(\"\\033[22m\", stdout); fflush(stdout);\n", g_CFILE);
                match[(uint64_t)2] = b2c_CopyString(match[(uint64_t)2], (char*) DEL(match[(uint64_t)2], ISTOKEN(match[(uint64_t)2], "NORMAL")));
            }
            b2c_select_2883 = b2c_CopyString(b2c_select_2883, match[(uint64_t)2]);
            if ( !b2c_strcmp(b2c_select_2883, "BLACK")){
                col = b2c_CopyString(col, (char*) "0");
            } else  if ( !b2c_strcmp(b2c_select_2883, "RED")){
                col = b2c_CopyString(col, (char*) "1");
            } else  if ( !b2c_strcmp(b2c_select_2883, "GREEN")){
                col = b2c_CopyString(col, (char*) "2");
            } else  if ( !b2c_strcmp(b2c_select_2883, "YELLOW")){
                col = b2c_CopyString(col, (char*) "3");
            } else  if ( !b2c_strcmp(b2c_select_2883, "BLUE")){
                col = b2c_CopyString(col, (char*) "4");
            } else  if ( !b2c_strcmp(b2c_select_2883, "MAGENTA")){
                col = b2c_CopyString(col, (char*) "5");
            } else  if ( !b2c_strcmp(b2c_select_2883, "CYAN")){
                col = b2c_CopyString(col, (char*) "6");
            } else  if ( !b2c_strcmp(b2c_select_2883, "WHITE")){
                col = b2c_CopyString(col, (char*) "7");
            } else {
                col = b2c_CopyString(col, (char*) match[(uint64_t)2]);
            }
        fprintf(g_CFILE, "fprintf(stdout,\"\\033[%ld%ldm\", (long)%s, (long)%s); fflush(stdout);\n", bfg, col);
        }
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(bfg);
    __b2c__STRFREE(col);
    __b2c__STRFREE(match);
    __b2c__STRFREE(b2c_select_2852);
    __b2c__STRFREE(b2c_select_2866);
    __b2c__STRFREE(b2c_select_2883);
    b2c_catch_set = b2c_catch_set_backup;
}
