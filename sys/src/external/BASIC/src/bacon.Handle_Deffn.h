/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Deffn( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *var = NULL;
    char *str = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty DEF FN at at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "DEF FN *", b2c_option_delim);
    var = F_CHOP(var,TOKEN(match[(uint64_t)1], 1, "="));
    str = F_CHOP(str,LAST(match[(uint64_t)1], 1, "="));
fprintf(g_HFILE, "#define %s (%s)\n", var, str);
    if( REGEX(TOKEN(var, 1, "("), CONCAT( g_STRINGSIGN , "$") ) ){
        b2c_hash_add_str(assoc_g_MACRO_STRINGS, str, TOKEN(var, 1, "("));
    }
    g_IMPORTED = F_CONCAT(g_IMPORTED, TOKEN(var, 1, "(") , " " , g_IMPORTED) ;
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(str);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
