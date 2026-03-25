/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Relate_Recurse( char *__b2c_var, char *__b2c_str, char *__b2c_tmp, NUMBER lvl) {
    char*var = NULL; var = b2c_CopyString(NULL, __b2c_var); char*str = NULL; str = b2c_CopyString(NULL, __b2c_str); char*tmp = NULL; tmp = b2c_CopyString(NULL, __b2c_tmp); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *rel = NULL;
    long ctr = 0;
    lvl = lvl + (1);
    if( (lvl )> g_RELATE_CTR ){
    fprintf(stderr, "%sSyntax error: endless recursion in RELATE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    for(ctr=0; ctr <= g_RELATE_CTR; ctr+=1){
        if( __b2c__STRCMP(TOKEN(g_RELATE[(uint64_t)ctr], 1) ,  var) == 0 ){
            rel = b2c_CopyString(rel, (char*) TOKEN(g_RELATE[(uint64_t)ctr], 2));
            if( INSTR(rel, g_STRINGSIGN) ){
            fprintf(g_CFILE, "b2c_hash_add_str(assoc_%s, %s, %s);\n", rel, tmp, str);
            } else {
            fprintf(g_CFILE, "assoc_%s_eval = %s; b2c_hash_add(assoc_%s, &assoc_%s_eval, %s);\n", rel, tmp, rel, rel, str);
            }
            Relate_Recurse(rel, str, tmp, lvl);
        }
    }

    __b2c__STRFREE(var);
    __b2c__STRFREE(str);
    __b2c__STRFREE(tmp);
    __b2c__STRFREE(rel);
    b2c_catch_set = b2c_catch_set_backup;
}
