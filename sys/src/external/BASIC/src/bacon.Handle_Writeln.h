/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Writeln( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *var = NULL;
    char *to = NULL;
    char *token = NULL;
    char *org = NULL;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in WRITELN statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "WRITELN * TO *", b2c_option_delim);
    var = b2c_CopyString(var, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
    org = b2c_CopyString(org, (char*) var);
    while( LEN(var) ){
        token = b2c_CopyString(token, (char*) Mini_Parser(var));
        Print_Element(CHOP(token), to);
        var = F_MID(var,var, LEN(token)+2);
    }
    if( __b2c__STRCMP(RIGHT(org, 1) ,  ";") != 0 ){
    fprintf(g_CFILE, "fputs(\"\\n\", %s);\n", to);
    } else {
    fprintf(g_CFILE, "fflush(%s);\n", to);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(to);
    __b2c__STRFREE(token);
    __b2c__STRFREE(org);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
