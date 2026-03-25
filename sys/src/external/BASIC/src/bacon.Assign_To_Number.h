/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Assign_To_Number( char *__b2c_from, char *__b2c_to, long flag) {
    char*from = NULL; from = b2c_CopyString(NULL, __b2c_from); char*to = NULL; to = b2c_CopyString(NULL, __b2c_to); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *type = NULL;
    char *lft = NULL;
    char *str = NULL;
    if( REGEX(to, "\\(.*\\)$") ){
        type = b2c_CopyString(type, (char*) Get_Var( CONCAT("assoc_" , to) , g_FUNCNAME));
    } else {
        type = b2c_CopyString(type, (char*) Get_Var(to, g_FUNCNAME));
    }
    if( REGEX(to, "\\(.*\\)$") ){
        str = b2c_CopyString(str, (char*) INBETWEEN(to, "(", ")", 2));
        lft = F_MID(lft,to, 1, INSTR(to, "(")-1);
        if( flag ){
            if( INSTR(type, "double")  OR  INSTR(type, "float")  OR  INSTR(type, "FLOATING") ){
            fprintf(g_CFILE, "assoc_%s_eval = atof(%s);\n", lft, from);
            } else if( INSTR(type, "long")  OR  INSTR(type, "NUMBER") ){
            fprintf(g_CFILE, "assoc_%s_eval = atol(%s);\n", lft, from);
            } else {
            fprintf(g_CFILE, "assoc_%s_eval = atoi(%s);\n", lft, from);
            }
        fprintf(g_CFILE, "free(%s); %s = NULL;\n", from, from);
        } else {
        fprintf(g_CFILE, "assoc_%s_eval = (%s)(%s);\n", lft, type, from);
        }
    fprintf(g_CFILE, "b2c_hash_add(assoc_%s, &assoc_%s_eval, %s);\n", lft, lft, str);
        Relate_Recurse(lft, str, to, -1);
    } else {
        if( flag ){
            if( INSTR(type, "double")  OR  INSTR(type, "float")  OR  INSTR(type, "FLOATING") ){
            fprintf(g_CFILE, "%s = atof(%s);\n", to, from);
            } else if( INSTR(type, "long")  OR  INSTR(type, "NUMBER") ){
            fprintf(g_CFILE, "%s = atol(%s);\n", to, from);
            } else {
            fprintf(g_CFILE, "%s = atoi(%s);\n", to, from);
            }
        fprintf(g_CFILE, "free(%s); %s = NULL;\n", from, from);
        } else {
        fprintf(g_CFILE, "%s = (%s)(%s);\n", to, type, from);
        }
    }

    __b2c__STRFREE(from);
    __b2c__STRFREE(to);
    __b2c__STRFREE(type);
    __b2c__STRFREE(lft);
    __b2c__STRFREE(str);
    b2c_catch_set = b2c_catch_set_backup;
}
