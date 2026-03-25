/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Print_Element ( char *arg_in, char *__b2c_std) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); char*std = NULL; std = b2c_CopyString(NULL, __b2c_std); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    if( Check_String_Type(arg) ){
    fprintf(g_CFILE, "b2c_assign = (char*)%s; if(b2c_assign != NULL) { fputs(b2c_assign, %s); }\n", arg, std);
    } else {
    fprintf(g_CFILE, "fputs(STR%s(%s), %s);\n", g_STRINGSIGN, arg, std);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(std);
    b2c_catch_set = b2c_catch_set_backup;
}
