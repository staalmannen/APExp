/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Return( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_name_ptr = 0; char* b2c_forin_name_string = NULL; char* b2c_forin_name_string_org = NULL; char* b2c_forin_name_step = NULL; int b2c_forin_str_ptr = 0; char* b2c_forin_str_string = NULL; char* b2c_forin_str_string_org = NULL; char* b2c_forin_str_step = NULL;
    char *type = NULL;
    char *str = NULL;
    char *name = NULL;
    long x = 0;
    arg = F_CHOP(arg,arg);
    if( ISFALSE(LEN(arg)) ){
    fputs("if(b2c_gosub_buffer_ptr >= 0) longjmp(b2c_gosub_buffer[b2c_gosub_buffer_ptr], 1);\n", g_CFILE);

        __b2c__STRFREE(arg);
        __b2c__STRFREE(type);
        __b2c__STRFREE(str);
        __b2c__STRFREE(name);
        b2c_catch_set = b2c_catch_set_backup;
        return b2c_exitval;
    }
    type = b2c_CopyString(type, (char*) IIF((LEN(g_FUNCTYPE))>0, g_FUNCTYPE, Get_Var(arg, g_FUNCNAME)));
    if( Check_String_Type(arg)  OR  REGEX(g_FUNCTYPE, "char\\*$|STRING$")  OR  REGEX(g_FUNCNAME, CONCAT( g_STRINGSIGN , "$") ) ){
        if( ISTOKEN(g_DYNAMICARRAYS, CONCAT( arg , "@" , g_FUNCNAME) ) ){
            g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) "char**");
        } else {
            g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) "char*");
        fprintf(g_CFILE, "b2c_assign = b2c_return(%s);\n", arg);
            arg = b2c_CopyString(arg, (char*) "b2c_assign");
        }
    } else if( ISTRUE(LEN(type)) ){
        if( INSTR(arg, "[") ){
            for(x=1; x <= COUNT(arg, 91); x+=1){
                if( __b2c__STRCMP(RIGHT(type, 1) ,  "*") == 0 ){
                    type = b2c_CopyString(type, (char*) LEFT(type, LEN(type)-1));
                }
            }
        } else {
            b2c_forin_name_string = b2c_CopyString(b2c_forin_name_string, g_STATICARRAYS); b2c_forin_name_string_org = b2c_forin_name_string;
            b2c_forin_name_step = b2c_CopyString(b2c_forin_name_step, b2c_option_delim);
            b2c_forin_name_ptr = b2c_for_amount(b2c_forin_name_string, b2c_forin_name_step);
            for(; b2c_forin_name_ptr > 0; b2c_forin_name_ptr--) { b2c_for_item(&b2c_forin_name_string_org, b2c_forin_name_step, &name);
                if( INSTR(name, arg) ){
                    type = F_CONCAT(type, type , FILL(VAL(MID(name, INSTR(name, ":")+1)), 42)) ;
                    break;
                }
            }
        }
        g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) type);
    } else if( REGEX(arg, CONCAT( g_LONGSIGN , "$") )  OR  REGEX(g_FUNCNAME, CONCAT( g_LONGSIGN , "$") ) ){
        g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) "long");
    } else if( INSTR(arg, ".")  OR  REGEX(arg, CONCAT( g_FLOATSIGN , "$") )  OR  REGEX(g_FUNCNAME, CONCAT( g_FLOATSIGN , "$") ) ){
        g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) "double");
    } else {
        g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) g_VARTYPE);
    }
fprintf(g_CFILE, "%s\n", g_STRINGARRAYS);
    b2c_forin_str_string = b2c_CopyString(b2c_forin_str_string, g_LOCALSTRINGS); b2c_forin_str_string_org = b2c_forin_str_string;
    b2c_forin_str_step = b2c_CopyString(b2c_forin_str_step, b2c_option_delim);
    b2c_forin_str_ptr = b2c_for_amount(b2c_forin_str_string, b2c_forin_str_step);
    for(; b2c_forin_str_ptr > 0; b2c_forin_str_ptr--) { b2c_for_item(&b2c_forin_str_string_org, b2c_forin_str_step, &str);
    fprintf(g_CFILE, "__b2c__STRFREE(%s);\n", str);
    }
fputs("b2c_catch_set = b2c_catch_set_backup;\n", g_CFILE);
fprintf(g_CFILE, "return(%s);\n", arg);
    __b2c__STRFREE(b2c_forin_name_string); b2c_forin_name_string = NULL; __b2c__STRFREE(b2c_forin_name_step); b2c_forin_name_step = NULL; __b2c__STRFREE(b2c_forin_str_string); b2c_forin_str_string = NULL; __b2c__STRFREE(b2c_forin_str_step); b2c_forin_str_step = NULL;
    __b2c__STRFREE(arg);
    __b2c__STRFREE(type);
    __b2c__STRFREE(str);
    __b2c__STRFREE(name);
    b2c_catch_set = b2c_catch_set_backup;
}
