/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Assoc_Array( char *__b2c_var, char *__b2c_type, int by_local) {
    char*var = NULL; var = b2c_CopyString(NULL, __b2c_var); char*type = NULL; type = b2c_CopyString(NULL, __b2c_type); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_str_ptr = 0; char* b2c_forin_str_string = NULL; char* b2c_forin_str_string_org = NULL; char* b2c_forin_str_step = NULL;
    char *str = NULL;
    char *value = NULL;
    b2c_forin_str_string = b2c_CopyString(b2c_forin_str_string, var); b2c_forin_str_string_org = b2c_forin_str_string;
    b2c_forin_str_step = b2c_CopyString(b2c_forin_str_step, ",");
    b2c_forin_str_ptr = b2c_for_amount(b2c_forin_str_string, b2c_forin_str_step);
    for(; b2c_forin_str_ptr > 0; b2c_forin_str_ptr--) { b2c_for_item(&b2c_forin_str_string_org, b2c_forin_str_step, &str);
        value = F_CHOP(value,str);
        if( LEN(g_FUNCNAME)  AND  LEN(Get_Var( CONCAT("assoc_" , value) )) ){
        fprintf(stderr, "%sSyntax error: associative array '%s' in LOCAL statement at line %s in file '%s' was defined previously!\n", NL, value, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
        if( by_local ){
        fprintf(g_CFILE, "%s assoc_%s_eval;\n", type, value);
            Save_Func_Var( CONCAT("assoc_" , value) , g_FUNCNAME, type);
            g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_hash_clear(assoc_" , value , "); free(assoc_" , value , "); assoc_" , value , " = NULL;") ;
        } else {
        fprintf(g_HFILE, "%s assoc_%s_eval;\n", type, value);
            Save_Main_Var( CONCAT("assoc_" , value) , type);
            g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " b2c_hash_clear(assoc_" , value , "); free(assoc_" , value , "); assoc_" , value , " = NULL;") ;
        }
    fprintf(g_HFILE, "b2c_htable *assoc_%s, *assoc_%s_orig;\n", value, value);
    fprintf(g_CFILE, "assoc_%s = b2c_hash_new();\n", value);
    fprintf(g_HFILE, "%s assoc_%s_func(const char *key){void *result; result = b2c_hash_find_value(assoc_%s, key);\n", type, value, value);
        if( INSTR(value, g_STRINGSIGN)  OR  REGEX(type, "STRING|char\\*$") ){
        fprintf(g_HFILE, "if(result == NULL) { return(NULL); } return((%s)result); }\n", type);
        } else {
        fprintf(g_HFILE, "if(result == NULL) { return(0); } return(*(%s*)result); }\n", type);
        }
    fprintf(g_HFILE, "#define %s(...) assoc_%s_func(__b2c__KEYCOLLECT(__VA_ARGS__))\n", value, value);
    }
    __b2c__STRFREE(b2c_forin_str_string); b2c_forin_str_string = NULL; __b2c__STRFREE(b2c_forin_str_step); b2c_forin_str_step = NULL;
    __b2c__STRFREE(var);
    __b2c__STRFREE(type);
    __b2c__STRFREE(str);
    __b2c__STRFREE(value);
    b2c_catch_set = b2c_catch_set_backup;
}
