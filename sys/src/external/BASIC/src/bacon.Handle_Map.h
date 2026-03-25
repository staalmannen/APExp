/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Map( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0; int b2c_forin_i_ptr = 0; char* b2c_forin_i_string = NULL; char* b2c_forin_i_string_org = NULL; char* b2c_forin_i_step = NULL;
    char *source = NULL;
    char *by = NULL;
    char *to = NULL;
    char *size = NULL;
    char *type = NULL;
    char *i = NULL;
    long use_static = 0;
    long total = 0;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty MAP at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( NOT(ISTOKEN(arg, "BY")) ){
    fprintf(stderr, "%sSyntax error: missing BY in MAP statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( NOT(ISTOKEN(arg, "TO")) ){
    fprintf(stderr, "%sSyntax error: missing TO in MAP statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "STATIC") ){
        use_static=(
        long)( 1);
        arg = b2c_CopyString(arg, (char*) DEL(arg, ISTOKEN(arg, "STATIC")));
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "MAP * BY * TO * SIZE *", b2c_option_delim);
    total = match__b2c_array;
    source = b2c_CopyString(source, (char*) match[(uint64_t)1]);
    by = b2c_CopyString(by, (char*) match[(uint64_t)2]);
    to = b2c_CopyString(to, (char*) match[(uint64_t)3]);
    size = b2c_CopyString(size, (char*) IIF((total )> 3, match[(uint64_t)4]));
    if( NOT(LEN(size)) ){
        if( ISTOKEN(g_DYNAMICARRAYS, CONCAT( CHOP(TOKEN(source, 1, ",")) , "@" , g_FUNCNAME) ) ){
            size = F_CONCAT(size, CHOP(TOKEN(source, 1, ",")) , "__b2c_array") ;
        } else {
            type = b2c_CopyString(type, (char*) Get_Var(CHOP(TOKEN(source, 1, ",")), g_FUNCNAME));
            size = F_CONCAT(size, "(sizeof(" , CHOP(TOKEN(source, 1, ",")) , ")/sizeof(" , type , ")-" , STR(g_OPTION_BASE) , ")") ;
        }
    }
    by = b2c_CopyString(by, (char*) EXTRACT(by, CHR(34)));
    type = b2c_CopyString(type, (char*) "long");
    if( Check_String_Type(by) ){
        type = b2c_CopyString(type, (char*) "char*");
    } else {
        b2c_forin_i_string = b2c_CopyString(b2c_forin_i_string, source); b2c_forin_i_string_org = b2c_forin_i_string;
        b2c_forin_i_step = b2c_CopyString(b2c_forin_i_step, b2c_option_delim);
        b2c_forin_i_ptr = b2c_for_amount(b2c_forin_i_string, b2c_forin_i_step);
        for(; b2c_forin_i_ptr > 0; b2c_forin_i_ptr--) { b2c_for_item(&b2c_forin_i_string_org, b2c_forin_i_step, &i);
            if( REGEX(Get_Var(i, g_FUNCNAME), ".*double.*|.*FLOATING.*") ){
                type = b2c_CopyString(type, (char*) "double");
                break;
            }
        }
    }
    if( NOT(LEN(Get_Var(to, g_FUNCNAME))) ){
        if( __b2c__STRCMP(g_OPTION_EXPLICIT ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_EXPLICIT ,  "TRUE") == 0 ){
        fprintf(stderr, "%sSyntax error: OPTION EXPLICIT forces explicit variable declaration at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
            exit(1);
        }
        if( ISTRUE(LEN(g_FUNCNAME)) ){
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
        fprintf(g_CFILE, "%s* %s; long %s__b2c_array;\n", type, to, to);
            Save_Func_Var(to, g_FUNCNAME, CONCAT( type , "*") );
            Save_Func_Var( CONCAT(to , "__b2c_array") , g_FUNCNAME, "long");
        } else {
            g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( to , "@" , g_FUNCNAME) );
        fprintf(g_HFILE, "%s* %s; long %s__b2c_array;\n", type, to, to);
            Save_Main_Var(to, CONCAT( type , "*") );
            Save_Main_Var( CONCAT(to , "__b2c_array") , "long");
        }
    fprintf(g_CFILE, "%s = (%s*)calloc((size_t)(%s+%s), sizeof(%s));\n", to, type, size, STR( g_OPTION_BASE), type);
    fprintf(g_CFILE, "%s__b2c_array = %s;\n", to, size);
        if( use_static == 0 ){
            if( __b2c__STRCMP(type ,  "char*") == 0 ){
                if( ISTRUE(LEN(g_FUNCNAME)) ){
                    g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_free_str_array_members(&" , to , ", " , STR(g_OPTION_BASE) , ", " , size , ");") ;
                } else {
                    g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , "free(" , to , ");") ;
                }
            }
            g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , to) ;
        }
    }
fprintf(g_CFILE, "for(b2c_ctr=%s; b2c_ctr<%s+%s; b2c_ctr++){\n", STR( g_OPTION_BASE), size, STR( g_OPTION_BASE));
    if( __b2c__STRCMP(type ,  "char*") == 0 ){
    fprintf(g_CFILE, "%s[b2c_ctr] = b2c_CopyString(%s[b2c_ctr], %s(%s[b2c_ctr])); }\n", to, to, by, REPLACE(source, ",", "[b2c_ctr],"));
    } else {
    fprintf(g_CFILE, "%s[b2c_ctr] = %s(%s[b2c_ctr]); }\n", to, by, REPLACE(source, ",", "[b2c_ctr],"));
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array); __b2c__STRFREE(b2c_forin_i_string); b2c_forin_i_string = NULL; __b2c__STRFREE(b2c_forin_i_step); b2c_forin_i_step = NULL;
    __b2c__STRFREE(arg);
    __b2c__STRFREE(source);
    __b2c__STRFREE(by);
    __b2c__STRFREE(to);
    __b2c__STRFREE(size);
    __b2c__STRFREE(type);
    __b2c__STRFREE(i);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
