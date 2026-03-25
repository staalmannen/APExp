/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Relate( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_str_ptr = 0; char* b2c_forin_str_string = NULL; char* b2c_forin_str_string_org = NULL; char* b2c_forin_str_step = NULL;
    char *source = NULL;
    char *to = NULL;
    char *str = NULL;
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in RELATE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    to = b2c_CopyString(to, (char*) LAST(arg, ISTOKEN(arg, "TO")));
    arg = b2c_CopyString(arg, (char*) HEAD(arg, ISTOKEN(arg, "TO")-1));
    source = F_CHOP(source,arg);
    if( NOT(LEN(Get_Var( CONCAT("assoc_" , source) )))  AND  NOT(LEN(Get_Var( CONCAT("assoc_" , source) , g_FUNCNAME))) ){
    fprintf(stderr, "%sSyntax error: variable '%s' not declared as ASSOC in RELATE statement at line %s in file '%s'!\n", NL, source, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_forin_str_string = b2c_CopyString(b2c_forin_str_string, EXTRACT(to, " ")); b2c_forin_str_string_org = b2c_forin_str_string;
    b2c_forin_str_step = b2c_CopyString(b2c_forin_str_step, ",");
    b2c_forin_str_ptr = b2c_for_amount(b2c_forin_str_string, b2c_forin_str_step);
    for(; b2c_forin_str_ptr > 0; b2c_forin_str_ptr--) { b2c_for_item(&b2c_forin_str_string_org, b2c_forin_str_step, &str);
        if( NOT(LEN(Get_Var( CONCAT("assoc_" , str) )))  AND  NOT(LEN(Get_Var( CONCAT("assoc_" , str) , g_FUNCNAME))) ){
        fprintf(stderr, "%sSyntax error: variable '%s' not declared as ASSOC in RELATE statement at line %s in file '%s'!\n", NL, str, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
        g_RELATE[(uint64_t)g_RELATE_CTR] = F_CONCAT(g_RELATE[(uint64_t)g_RELATE_CTR], source , " " , str) ;
        g_RELATE_CTR = g_RELATE_CTR + (1);
    }
    __b2c__STRFREE(b2c_forin_str_string); b2c_forin_str_string = NULL; __b2c__STRFREE(b2c_forin_str_step); b2c_forin_str_step = NULL;
    __b2c__STRFREE(arg);
    __b2c__STRFREE(source);
    __b2c__STRFREE(to);
    __b2c__STRFREE(str);
    b2c_catch_set = b2c_catch_set_backup;
}
