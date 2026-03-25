/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_For( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *var = NULL;
    char *in = NULL;
    char *from = NULL;
    char *to = NULL;
    char *step = NULL;
    long total = 0;
    if( NOT(ISTOKEN(arg, "TO"))  AND  NOT(ISTOKEN(arg, "DOWNTO"))  AND  NOT(ISTOKEN(arg, "IN")) ){
    fprintf(stderr, "%sSyntax error: missing IN/TO/DOWNTO in FOR statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "TO")  OR  ISTOKEN(arg, "DOWNTO") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), CONCAT( "FOR * " , IIF(ISTOKEN(arg, "TO"), "TO", "DOWNTO") , " * STEP *" ), b2c_option_delim);
        total = match__b2c_array;
        var = F_CHOP(var,TOKEN(match[(uint64_t)1], 1, "="));
        from = F_CHOP(from,TOKEN(match[(uint64_t)1], 2, "="));
        to = b2c_CopyString(to, (char*) match[(uint64_t)2]);
        step = b2c_CopyString(step, (char*) IIF((total )> 2, match[(uint64_t)3], "1"));
        if( ISTOKEN(arg, "DOWNTO") ){
            step = F_CONCAT(step, "-" , step);
        }
    } else {
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "FOR * IN * STEP *", b2c_option_delim);
        total = match__b2c_array;
        var = b2c_CopyString(var, (char*) match[(uint64_t)1]);
        in = b2c_CopyString(in, (char*) match[(uint64_t)2]);
        step = b2c_CopyString(step, (char*) IIF((total )> 2, match[(uint64_t)3], "b2c_option_delim"));
        if( (LEN(g_FUNCNAME) )> 0 ){
            if( NOT(INSTR(g_STRINGARGS, CONCAT( "b2c_forin_" , var , "_ptr") )) ){
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " int b2c_forin_" , var , "_ptr = 0;") ;
                Save_Func_Var( CONCAT("b2c_forin_" , var , "_ptr") , g_FUNCNAME, "int");
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " char* b2c_forin_" , var , "_string = NULL;") ;
                Save_Func_Var( CONCAT("b2c_forin_" , var , "_string") , g_FUNCNAME, "char*");
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " char* b2c_forin_" , var , "_string_org = NULL;") ;
                Save_Func_Var( CONCAT("b2c_forin_" , var , "_string_org") , g_FUNCNAME, "char*");
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " char* b2c_forin_" , var , "_step = NULL;") ;
                Save_Func_Var( CONCAT("b2c_forin_" , var , "_step") , g_FUNCNAME, "char*");
                g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " __b2c__STRFREE(b2c_forin_" , var , "_string); b2c_forin_" , var , "_string = NULL;") ;
                g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " __b2c__STRFREE(b2c_forin_" , var , "_step); b2c_forin_" , var , "_step = NULL;") ;
            }
        } else {
            if( NOT(LEN(Get_Var( CONCAT("b2c_forin_" , var , "_ptr") ))) ){
            fprintf(g_HFILE, "int b2c_forin_%s_ptr = 0;\n", var);
                Save_Main_Var( CONCAT("b2c_forin_" , var , "_ptr") , "int");
            fprintf(g_HFILE, "char* b2c_forin_%s_string = NULL;\n", var);
                Save_Main_Var( CONCAT("b2c_forin_" , var , "_string") , "char*");
            fprintf(g_HFILE, "char* b2c_forin_%s_string_org = NULL;\n", var);
                Save_Main_Var( CONCAT("b2c_forin_" , var , "_string_org") , "char*");
            fprintf(g_HFILE, "char* b2c_forin_%s_step = NULL;\n", var);
                Save_Main_Var( CONCAT("b2c_forin_" , var , "_step") , "char*");
            }
        }
    }
    if( REGEX(var, CONCAT( g_STRINGSIGN , "$") ) ){
        Register_Pointer(var, "char*");
    } else if( REGEX( CONCAT(from , to , step) , "[0-9]\\.[0-9]")  OR  REGEX(Get_Var(step, g_FUNCNAME), "double|float|FLOATING") ){
        Register_Numeric(var, "double");
    } else {
        Register_Numeric(var, "default");
    }
    if( Check_String_Type(var) ){
    fprintf(g_CFILE, "b2c_forin_%s_string = b2c_CopyString(b2c_forin_%s_string, %s); b2c_forin_%s_string_org = b2c_forin_%s_string;\n", var, var, in, var, var);
    fprintf(g_CFILE, "b2c_forin_%s_step = b2c_CopyString(b2c_forin_%s_step, %s);\n", var, var, step);
    fprintf(g_CFILE, "b2c_forin_%s_ptr = b2c_for_amount(b2c_forin_%s_string, b2c_forin_%s_step);\n", var, var, var);
    fprintf(g_CFILE, "for(; b2c_forin_%s_ptr > 0; b2c_forin_%s_ptr--) { b2c_for_item(&b2c_forin_%s_string_org, b2c_forin_%s_step, &%s);\n", var, var, var, var, var);
    } else {
        if( (VAL(step) )< 0 ){
        fprintf(g_CFILE, "for(%s = %s; %s >= %s;%s += %s){\n", var, from, var, to, var, step);
        } else {
        fprintf(g_CFILE, "for(%s = %s; %s <= %s;%s += %s){\n", var, from, var, to, var, step);
        }
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(in);
    __b2c__STRFREE(from);
    __b2c__STRFREE(to);
    __b2c__STRFREE(step);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
