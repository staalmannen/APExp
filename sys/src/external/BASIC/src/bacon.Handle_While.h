/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_While( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "WHILE * DO", b2c_option_delim);
fprintf(g_CFILE, "while(%s){\n", Parse_Equation(match[(uint64_t)1]));
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
