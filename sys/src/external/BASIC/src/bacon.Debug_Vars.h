/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Debug_Vars( void) {
b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **mainvar = { NULL }; long mainvar__b2c_array = 0; char **funcvar = { NULL }; long funcvar__b2c_array = 0; int b2c_forin_item_ptr = 0; char* b2c_forin_item_string = NULL; char* b2c_forin_item_string_org = NULL; char* b2c_forin_item_step = NULL;
    long xxx = 0;
    long many = 0;
    char *item = NULL;
    char *total = NULL;
    mainvar__b2c_array = b2c_lookup_by_order(assoc_g_ALL_MAIN_VARS, &mainvar, mainvar__b2c_array, 1);
    many = mainvar__b2c_array;
    if( many ){
        for(xxx=1; xxx <= many; xxx+=1){
        fprintf(stderr, "%s:MAIN:%s ", g_ALL_MAIN_VARS(mainvar[(uint64_t)xxx]), mainvar[(uint64_t)xxx]);
            fflush(stderr);
        }
        fputs("\n", stdout);
    }
    funcvar__b2c_array = b2c_lookup_by_order(assoc_g_ALL_FUNC_VARS, &funcvar, funcvar__b2c_array, 1);
    many = funcvar__b2c_array;
    if( many ){
        for(xxx=1; xxx <= many; xxx+=1){
        fprintf(stderr, "%s:%s:%s ", g_ALL_FUNC_VARS(funcvar[(uint64_t)xxx]), TOKEN(funcvar[(uint64_t)xxx], 2), TOKEN(funcvar[(uint64_t)xxx], 1));
            fflush(stderr);
        }
        fputs("\n", stdout);
    }
    b2c_forin_item_string = b2c_CopyString(b2c_forin_item_string, CONCAT( Stat , Func , Var )); b2c_forin_item_string_org = b2c_forin_item_string;
    b2c_forin_item_step = b2c_CopyString(b2c_forin_item_step, "|");
    b2c_forin_item_ptr = b2c_for_amount(b2c_forin_item_string, b2c_forin_item_step);
    for(; b2c_forin_item_ptr > 0; b2c_forin_item_ptr--) { b2c_for_item(&b2c_forin_item_string_org, b2c_forin_item_step, &item);
        if( REGEX(g_DEPEND, CONCAT( item , "\\(") )  OR  REGEX(g_DEPEND, CONCAT( item , "[[:space:]]") ) ){
            total = F_CONCAT(total, total , EXTRACT(item, "\\") , " ");
        }
    }
fprintf(stderr, "%s\n", SORT(UNIQ(total)));
    b2c_free_str_array_members(&mainvar, 1, mainvar__b2c_array); b2c_free_str_array_members(&funcvar, 1, funcvar__b2c_array); __b2c__STRFREE(b2c_forin_item_string); b2c_forin_item_string = NULL; __b2c__STRFREE(b2c_forin_item_step); b2c_forin_item_step = NULL;
    __b2c__STRFREE(item);
    __b2c__STRFREE(total);
    __b2c__STRFREE(mainvar);
    __b2c__STRFREE(funcvar);
    b2c_catch_set = b2c_catch_set_backup;
}
