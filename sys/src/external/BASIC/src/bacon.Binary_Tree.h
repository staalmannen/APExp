/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Binary_Tree( char *__b2c_var, char *__b2c_type, int by_local) {
    char*var = NULL; var = b2c_CopyString(NULL, __b2c_var); char*type = NULL; type = b2c_CopyString(NULL, __b2c_type); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_str_ptr = 0; char* b2c_forin_str_string = NULL; char* b2c_forin_str_string_org = NULL; char* b2c_forin_str_step = NULL;
    char *str = NULL;
    char *value = NULL;
    b2c_forin_str_string = b2c_CopyString(b2c_forin_str_string, var); b2c_forin_str_string_org = b2c_forin_str_string;
    b2c_forin_str_step = b2c_CopyString(b2c_forin_str_step, ",");
    b2c_forin_str_ptr = b2c_for_amount(b2c_forin_str_string, b2c_forin_str_step);
    for(; b2c_forin_str_ptr > 0; b2c_forin_str_ptr--) { b2c_for_item(&b2c_forin_str_string_org, b2c_forin_str_step, &str);
        value = F_CHOP(value,str);
        if( LEN(g_FUNCNAME)  AND  LEN(Get_Var( CONCAT("b2c_tree_" , value) )) ){
        fprintf(stderr, "%sSyntax error: tree variable '%s' in LOCAL statement at line %s in file '%s' was defined previously!\n", NL, value, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
        if( REGEX(type, "STRING|char\\*$") ){
            type = b2c_CopyString(type, (char*) "b2c_sortstr2:char*");
        } else if( INSTR(type, "double")  OR  INSTR(type, "FLOATING") ){
            type = b2c_CopyString(type, (char*) "b2c_sortnrd:double");
        } else if( INSTR(type, "float") ){
            type = b2c_CopyString(type, (char*) "b2c_sortnrf:float");
        } else if( INSTR(type, "long")  OR  INSTR(type, "NUMBER") ){
            type = b2c_CopyString(type, (char*) "b2c_sortnrl:long");
        } else if( INSTR(type, "int") ){
            type = b2c_CopyString(type, (char*) "b2c_sortnri:int");
        } else if( INSTR(type, "short") ){
            type = b2c_CopyString(type, (char*) "b2c_sortnrs:short");
        } else if( INSTR(type, "short") ){
            type = b2c_CopyString(type, (char*) "b2c_sortnrc:char");
        } else {
        fprintf(stderr, "%sSyntax error: unsupported TREE type at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
        if( by_local ){
        fprintf(g_CFILE, "void* %s = NULL;\n", value);
            Save_Func_Var( CONCAT("b2c_tree_" , value) , g_FUNCNAME, type);
        } else {
        fprintf(g_HFILE, "void* %s = NULL;\n", value);
            Save_Main_Var( CONCAT("b2c_tree_" , value) , type);
        }
    }
    __b2c__STRFREE(b2c_forin_str_string); b2c_forin_str_string = NULL; __b2c__STRFREE(b2c_forin_str_step); b2c_forin_str_step = NULL;
    __b2c__STRFREE(var);
    __b2c__STRFREE(type);
    __b2c__STRFREE(str);
    __b2c__STRFREE(value);
    b2c_catch_set = b2c_catch_set_backup;
}
