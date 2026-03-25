/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Read( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_element_ptr = 0; char* b2c_forin_element_string = NULL; char* b2c_forin_element_string_org = NULL; char* b2c_forin_element_step = NULL;
    char *type = NULL;
    char *element = NULL;
    char *lft = NULL;
    char *str = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty READ at at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    b2c_forin_element_string = b2c_CopyString(b2c_forin_element_string, EXTRACT(arg, " ")); b2c_forin_element_string_org = b2c_forin_element_string;
    b2c_forin_element_step = b2c_CopyString(b2c_forin_element_step, ",");
    b2c_forin_element_ptr = b2c_for_amount(b2c_forin_element_string, b2c_forin_element_step);
    for(; b2c_forin_element_ptr > 0; b2c_forin_element_ptr--) { b2c_for_item(&b2c_forin_element_string_org, b2c_forin_element_step, &element);
        if( REGEX(element, CONCAT( g_STRINGSIGN , "$") ) ){
            Register_Pointer(element, "char*");
            type = b2c_CopyString(type, (char*) "char*");
        } else {
            Register_Numeric(element, "default");
            type = b2c_CopyString(type, (char*) Get_Var(element, g_FUNCNAME));
        }
        if( Check_String_Type(element) ){
        fputs("b2c_assign = b2c_CopyString(NULL, b2c_stringarray[b2c_stringarray_ptr]); b2c_stringarray_ptr++;\n", g_CFILE);
            Assign_To_String("b2c_assign", element, NULL);
        } else {
            Assign_To_Number("b2c_floatarray[b2c_floatarray_ptr]", element, 0);
        fputs("b2c_floatarray_ptr++;\n", g_CFILE);
        }
    }
    __b2c__STRFREE(b2c_forin_element_string); b2c_forin_element_string = NULL; __b2c__STRFREE(b2c_forin_element_step); b2c_forin_element_step = NULL;
    __b2c__STRFREE(arg);
    __b2c__STRFREE(type);
    __b2c__STRFREE(element);
    __b2c__STRFREE(lft);
    __b2c__STRFREE(str);
    b2c_catch_set = b2c_catch_set_backup;
}
