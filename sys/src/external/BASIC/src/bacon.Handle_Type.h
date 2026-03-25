/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Type( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *type = NULL;
    long offset = 0;
    long cfg = 0;
    if( NOT(ISTOKEN(arg, "SET"))  AND  NOT(ISTOKEN(arg, "UNSET"))  AND  NOT(ISTOKEN(arg, "RESET")) ){
    fprintf(stderr, "%sSyntax error: missing SET/UNSET/RESET in TYPE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "RESET") ){
    fputs("fputs(\"\\033[21m\\033[23m\\033[24m\\033[25m\\033[27m\\033[29m\", stdout); fflush(stdout);\n", g_CFILE);
    } else {
        if( ISTOKEN(arg, "UNSET") ){
            offset=(
            long)( 20);
        }
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), CONCAT( "TYPE " , IIF(ISTOKEN(arg, "SET"), "SET", "UNSET") , " *" ), b2c_option_delim);
        if( ISTOKEN(match[(uint64_t)1], "BOLD") ){
            cfg=(
            long)( 1 + offset);
            type = F_CONCAT(type, type , "\\033[" , STR(cfg) , "m") ;
        }
        if( ISTOKEN(match[(uint64_t)1], "ITALIC") ){
            cfg=(
            long)( 3 + offset);
            type = F_CONCAT(type, type , "\\033[" , STR(cfg) , "m") ;
        }
        if( ISTOKEN(match[(uint64_t)1], "UNDERLINE") ){
            cfg=(
            long)( 4 + offset);
            type = F_CONCAT(type, type , "\\033[" , STR(cfg) , "m") ;
        }
        if( ISTOKEN(match[(uint64_t)1], "BLINK") ){
            cfg=(
            long)( 5 + offset);
            type = F_CONCAT(type, type , "\\033[" , STR(cfg) , "m") ;
        }
        if( ISTOKEN(match[(uint64_t)1], "INVERSE") ){
            cfg=(
            long)( 7 + offset);
            type = F_CONCAT(type, type , "\\033[" , STR(cfg) , "m") ;
        }
        if( ISTOKEN(match[(uint64_t)1], "STRIKE") ){
            cfg=(
            long)( 9 + offset);
            type = F_CONCAT(type, type , "\\033[" , STR(cfg) , "m") ;
        }
        if( NOT(LEN(type)) ){
        fprintf(stderr, "%sSyntax error: argument in TYPE statement not recognized at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
    fprintf(g_CFILE, "fputs(\"%s\", stdout); fflush(stdout);\n", type);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(type);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
