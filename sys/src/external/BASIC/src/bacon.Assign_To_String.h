/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Assign_To_String( char *__b2c_from, char *__b2c_to, char *__b2c_memsize) {
    char*from = NULL; from = b2c_CopyString(NULL, __b2c_from); char*to = NULL; to = b2c_CopyString(NULL, __b2c_to); char*memsize = NULL; memsize = b2c_CopyString(NULL, __b2c_memsize); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *lft = NULL;
    char *str = NULL;
    if( REGEX(to, "\\(.*\\)$") ){
        str = b2c_CopyString(str, (char*) INBETWEEN(to, "(", ")", 2));
        lft = F_MID(lft,to, 1, INSTR(to, "(")-1);
    fprintf(g_CFILE, "b2c_hash_add_str(assoc_%s, %s, %s);\n", lft, from, str);
    fprintf(g_CFILE, "__b2c__STRFREE(%s); %s = NULL;\n", from, from);
        Relate_Recurse(lft, str, to, -1);
    } else if( Check_String_Type(to) ){
        if( INSTR(to, g_STRINGSIGN) ){
        fprintf(g_CFILE, "%s = b2c_CopyString(%s, %s);\n", to, to, from);
        fprintf(g_CFILE, "__b2c__STRFREE(%s); %s = NULL;\n", from, from);
        } else {
        fprintf(g_CFILE, "__b2c__STRFREE(%s); %s = %s;\n", to, to, from);
        }
    } else {
    fprintf(g_CFILE, "memcpy((void*)(%s), (void*)%s, %s); free(%s);\n", to, from, memsize, from);
    }

    __b2c__STRFREE(from);
    __b2c__STRFREE(to);
    __b2c__STRFREE(memsize);
    __b2c__STRFREE(lft);
    __b2c__STRFREE(str);
    b2c_catch_set = b2c_catch_set_backup;
}
