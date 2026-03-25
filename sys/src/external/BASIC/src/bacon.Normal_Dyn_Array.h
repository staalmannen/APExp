/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Normal_Dyn_Array( char *__b2c_t, char *__b2c_var, char *__b2c_array, int is_static, int is_local) {
    char*t = NULL; t = b2c_CopyString(NULL, __b2c_t); char*var = NULL; var = b2c_CopyString(NULL, __b2c_var); char*array = NULL; array = b2c_CopyString(NULL, __b2c_array); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_i_ptr = 0; char* b2c_forin_i_string = NULL; char* b2c_forin_i_string_org = NULL; char* b2c_forin_i_step = NULL; int b2c_forin_j_ptr = 0; char* b2c_forin_j_string = NULL; char* b2c_forin_j_string_org = NULL; char* b2c_forin_j_step = NULL;
    char *i = NULL;
    char *j = NULL;
    char *old = NULL;
    char *end = NULL;
    char *tmp_arr = NULL;
    char *idx = NULL;
    char *type = NULL;
    char *org_type = NULL;
    char *global = NULL;
    long nr = 0;
    b2c_forin_i_string = b2c_CopyString(b2c_forin_i_string, var); b2c_forin_i_string_org = b2c_forin_i_string;
    b2c_forin_i_step = b2c_CopyString(b2c_forin_i_step, ",");
    b2c_forin_i_ptr = b2c_for_amount(b2c_forin_i_string, b2c_forin_i_step);
    for(; b2c_forin_i_ptr > 0; b2c_forin_i_ptr--) { b2c_for_item(&b2c_forin_i_string_org, b2c_forin_i_step, &i);
        type = b2c_CopyString(type, (char*) t);
        g_DYNAMICARRAYS = F_APPEND(g_DYNAMICARRAYS,g_DYNAMICARRAYS, 0, CONCAT( CHOP(i) , "@" , g_FUNCNAME) );
        if( REGEX(type, "STRING|char\\*$")  OR  INSTR(i, g_STRINGSIGN) ){
            if( INSTR(IIF(TALLY(array, "("), TOKEN(array, 1, "("), array), ",") ){
            fprintf(stderr, "%sSyntax error: string array cannot have more than one dimension line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            }
            if( is_local ){
            fprintf(g_CFILE, "%s* %s = { NULL };\n", type, i);
                Save_Func_Var(i, g_FUNCNAME, type);
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " long " , CHOP(i) , "__b2c_array;") ;
                Save_Func_Var( CONCAT(CHOP(i) , "__b2c_array") , g_FUNCNAME, "long");
                if( NOT(is_static) ){
                    g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_free_str_array_members(&" , CHOP(i) , ", " , STR(g_OPTION_BASE) , ", " , CHOP(i) , "__b2c_array);") ;
                    g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , i) ;
                }
            } else {
            fprintf(g_HFILE, "%s* %s = { NULL };\n", type, i);
                Save_Main_Var(i, type);
            fprintf(g_HFILE, "long %s__b2c_array;\n", CHOP(i));
                Save_Main_Var( CONCAT(CHOP(i) , "__b2c_array") , "long");
                if( NOT(is_static) ){
                    g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , "free(" , CHOP(i) , ");") ;
                }
            }
        fprintf(g_CFILE, "%s = (%s*)calloc(%s+%s, sizeof(%s));\n", i, type, array, STR( g_OPTION_BASE), type);
        fprintf(g_CFILE, "%s__b2c_array = %s;\n", CHOP(i), array);
        } else {
            org_type = b2c_CopyString(org_type, (char*) type);
            nr=(
            long)( 0);
            b2c_forin_j_string = b2c_CopyString(b2c_forin_j_string, array); b2c_forin_j_string_org = b2c_forin_j_string;
            b2c_forin_j_step = b2c_CopyString(b2c_forin_j_step, ",");
            b2c_forin_j_ptr = b2c_for_amount(b2c_forin_j_string, b2c_forin_j_step);
            for(; b2c_forin_j_ptr > 0; b2c_forin_j_ptr--) { b2c_for_item(&b2c_forin_j_string_org, b2c_forin_j_step, &j);
                nr = nr + (1);
                type = F_CONCAT(type, type , "*") ;
            }
    if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
            if( is_local ){
            fprintf(g_CFILE, "%s %s = { NULL };\n", type, i);
                Save_Func_Var(i, g_FUNCNAME, org_type);
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " long " , CHOP(i) , "__b2c_array;") ;
                Save_Func_Var( CONCAT(CHOP(i) , "__b2c_array") , g_FUNCNAME, "long");
                if( NOT(is_static) ){
                    g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , CHOP(i)) ;
                } else {
                    g_STATICARRAYS = F_CONCAT(g_STATICARRAYS, g_STATICARRAYS , " " , CHOP(i) , ":" , STR(COUNT(type, 42))) ;
                }
            } else {
            fprintf(g_HFILE, "%s %s = { NULL };\n", type, i);
                Save_Main_Var(i, org_type);
            fprintf(g_HFILE, "long %s__b2c_array;\n", CHOP(i));
                Save_Main_Var( CONCAT(CHOP(i) , "__b2c_array") , "long");
                if( nr == 1 ){
                    g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , "free(" , CHOP(i) , ");");
                }
            }
        fprintf(g_CFILE, "%s__b2c_array = %s;\n", CHOP(i), TOKEN(array, 1, ","));
        fprintf(g_CFILE, "%s = (%s)calloc((size_t)%s+%s, sizeof(%s));\n", i, type, TOKEN(array, 1, ","), STR( g_OPTION_BASE), LEFT(type, LEN(type)-1));
            if( (nr )> 1 ){
                old = b2c_CopyString(old, (char*) LEFT(array, INSTR(array, ",")-1));
                tmp_arr = F_MID(tmp_arr,array, INSTR(array, ",")+1);
                nr=(
                long)( 0);
                idx = b2c_CopyString(idx, (char*) i);
                end = b2c_CopyString(end, (char*) "");
                b2c_forin_j_string = b2c_CopyString(b2c_forin_j_string, tmp_arr); b2c_forin_j_string_org = b2c_forin_j_string;
                b2c_forin_j_step = b2c_CopyString(b2c_forin_j_step, ",");
                b2c_forin_j_ptr = b2c_for_amount(b2c_forin_j_string, b2c_forin_j_step);
                for(; b2c_forin_j_ptr > 0; b2c_forin_j_ptr--) { b2c_for_item(&b2c_forin_j_string_org, b2c_forin_j_step, &j);
                    nr = nr + (1);
                    if( is_local ){
                        g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " int __b2c_" , CHOP(i) , STR(nr) , ";") ;
                    } else {
                    fprintf(g_HFILE, "int __b2c_%s%s;\n", CHOP(i), STR( nr));
                    }
                    idx = F_CONCAT(idx, idx , "[__b2c_" , CHOP(i) , STR(nr) , "]") ;
                fprintf(g_CFILE, "for(__b2c_%s%s = 0; __b2c_%s%s < %s+%s; __b2c_%s%s++){\n", CHOP(i), STR( nr), CHOP(i), STR(nr), old, STR( g_OPTION_BASE), CHOP(i), STR( nr));
                    type = b2c_CopyString(type, (char*) LEFT(type, LEN(type)-1));
                fprintf(g_CFILE, "%s = (%s)calloc((size_t)%s+%s, sizeof(%s));\n", idx, type, j, STR( g_OPTION_BASE), LEFT(type, LEN(type)-1));
                    end = F_CONCAT(end, end , " }") ;
                    old = b2c_CopyString(old, (char*) j);
                }
        if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
            fprintf(g_CFILE, "%s\n", end);
                type = b2c_CopyString(type, (char*) LEFT(type, LEN(type)-1));
                if( (nr )> 0 ){
                    nr=(
                    long)( 1);
                    end = b2c_CopyString(end, (char*) "");
                    b2c_forin_j_string = b2c_CopyString(b2c_forin_j_string, LEFT(array, INSTRREV(array, ",")-1)); b2c_forin_j_string_org = b2c_forin_j_string;
                    b2c_forin_j_step = b2c_CopyString(b2c_forin_j_step, ",");
                    b2c_forin_j_ptr = b2c_for_amount(b2c_forin_j_string, b2c_forin_j_step);
                    for(; b2c_forin_j_ptr > 0; b2c_forin_j_ptr--) { b2c_for_item(&b2c_forin_j_string_org, b2c_forin_j_step, &j);
                        if( NOT(is_static) ){
                            if( is_local ){
                                g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " for(__b2c_" , CHOP(i) , STR(nr) , " = 0; __b2c_" , CHOP(i) , STR(nr) , " < " , j , "+" , STR(g_OPTION_BASE) , "; __b2c_" , CHOP(i) , STR(nr) , "++){") ;
                            } else {
                                g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " for(__b2c_" , CHOP(i) , STR(nr) , " = 0; __b2c_" , CHOP(i) , STR(nr) , " < " , j , "+" , STR(g_OPTION_BASE) , "; __b2c_" , CHOP(i) , STR(nr) , "++){") ;
                            }
                            end = F_CONCAT(end, end , " __b2c__STRFREE(" , idx , "); }") ;
                            idx = b2c_CopyString(idx, (char*) LEFT(idx, INSTRREV(idx, "[")-1));
                            nr = nr + (1);
                        }
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    if( NOT(is_static) ){
                        if( is_local ){
                            g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " " , end) ;
                        } else {
                            g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " " , end , "free(" , CHOP(i) , ");") ;
                        }
                    }
                }
            }
        }
    }
    __b2c__STRFREE(b2c_forin_i_string); b2c_forin_i_string = NULL; __b2c__STRFREE(b2c_forin_i_step); b2c_forin_i_step = NULL; __b2c__STRFREE(b2c_forin_j_string); b2c_forin_j_string = NULL; __b2c__STRFREE(b2c_forin_j_step); b2c_forin_j_step = NULL;
    __b2c__STRFREE(t);
    __b2c__STRFREE(var);
    __b2c__STRFREE(array);
    __b2c__STRFREE(i);
    __b2c__STRFREE(j);
    __b2c__STRFREE(old);
    __b2c__STRFREE(end);
    __b2c__STRFREE(tmp_arr);
    __b2c__STRFREE(idx);
    __b2c__STRFREE(type);
    __b2c__STRFREE(org_type);
    __b2c__STRFREE(global);
    b2c_catch_set = b2c_catch_set_backup;
}
