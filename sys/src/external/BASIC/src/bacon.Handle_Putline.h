/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Putline( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *var = NULL;
    char *to = NULL;
    char *token = NULL;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in PUTLINE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "PUTLINE * TO *", b2c_option_delim);
    var = b2c_CopyString(var, (char*) match[(uint64_t)1]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
    while( LEN(var) ){
        token = b2c_CopyString(token, (char*) Mini_Parser(var));
        if( Check_String_Type(token) ){
        fprintf(g_CFILE, "strcat(%s, %s);%s+=strlen(%s);\n", to, CHOP(token), to, CHOP(token));
        } else {
        fprintf(g_CFILE, "strcat(%s, STR%s(%s));%s+=strlen(STR%s(%s));\n", to, g_STRINGSIGN, CHOP(token), to, g_STRINGSIGN, CHOP(token));
        }
        var = F_MID(var,var, LEN(token)+2);
    }
fprintf(g_CFILE, "strcat(%s, \"\\n\"); %s+=1;\n", to, to);
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(to);
    __b2c__STRFREE(token);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
