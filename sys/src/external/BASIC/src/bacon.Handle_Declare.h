/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Declare( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_i_ptr = 0; char* b2c_forin_i_string = NULL; char* b2c_forin_i_string_org = NULL; char* b2c_forin_i_step = NULL;
    char *var = NULL;
    char *type = NULL;
    char *array = NULL;
    char *str = NULL;
    char *i = NULL;
    long opt = 0;
    long self_declared = 0;
    if( (LEN(g_RECORDNAME) )> 0 ){
    fprintf(stderr, "%sSyntax error: DECLARE/GLOBAL cannot be used within a RECORD at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "RECORD") ){
        g_RECORDNAME = F_CONCAT(g_RECORDNAME, "RECORD_" , STR(g_COUNTER)) ;
    fputs("typedef struct {\n", g_HFILE);
        g_RECORDVAR = F_MID(g_RECORDVAR,CHOP(arg), INSTR(CHOP(arg), " ") + 1);
        if( ISTOKEN(g_RECORDVAR, "ARRAY") ){
            g_RECORDARRAY = F_MID(g_RECORDARRAY,g_RECORDVAR, INSTR(g_RECORDVAR, "ARRAY")+5);
            g_RECORDVAR = F_CONCAT(g_RECORDVAR, LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "ARRAY")-1) , "[" , g_RECORDARRAY , "]") ;
        }
        if( (LEN(g_FUNCNAME) )> 0 ){
            g_RECORDCACHE = b2c_CopyString(g_RECORDCACHE, (char*) g_FUNCNAME);
            g_FUNCNAME = b2c_CopyString(g_FUNCNAME, (char*) "");
        }
    } else {
        if( ISTOKEN(arg, "TYPE") ){
            var = F_CHOP(var,TOKEN(arg, 1, "TYPE"));
            type = F_CHOP(type,TOKEN(arg, 2, "TYPE"));
            if( ISTOKEN(type, "ARRAY") ){
                array = b2c_CopyString(array, (char*) TOKEN(type, 2, "ARRAY"));
                type = F_CHOP(type,TOKEN(type, 1, "ARRAY"));
            }
        } else if( ISTOKEN(arg, "ASSOC") ){
            var = F_CHOP(var,TOKEN(arg, 1, "ASSOC"));
            type = F_CHOP(type,TOKEN(arg, 2, "ASSOC"));
        } else if( ISTOKEN(arg, "TREE") ){
            var = F_CHOP(var,TOKEN(arg, 1, "TREE"));
            type = F_CHOP(type,TOKEN(arg, 2, "TREE"));
        } else if( ISTOKEN(arg, "ARRAY") ){
            array = b2c_CopyString(array, (char*) TOKEN(arg, 2, "ARRAY"));
            var = b2c_CopyString(var, (char*) TOKEN(arg, 1, "ARRAY"));
            type = b2c_CopyString(type, (char*) IIF(INSTR(var, g_STRINGSIGN), "char*", IIF(INSTR(var, g_FLOATSIGN), "double", g_VARTYPE)));
        } else {
            var = F_CHOP(var,arg);
            self_declared=(
            long)( TRUE);
        }
        while( LEN(var) ){
            str = b2c_CopyString(str, (char*) Mini_Parser(var));
            var = F_MID(var,var, LEN(str)+2);
            str = F_CHOP(str,str);
            if( self_declared ){
                i = b2c_CopyString(i, (char*) EXTRACT(TOKEN(str, 1, "="), " "));
                if( INSTR(i, g_STRINGSIGN) ){
                    type = b2c_CopyString(type, (char*) "char*");
                } else if( INSTR(i, g_FLOATSIGN) ){
                    type = b2c_CopyString(type, (char*) "double");
                } else if( INSTR(i, g_LONGSIGN) ){
                    type = b2c_CopyString(type, (char*) "long");
                } else {
                    type = b2c_CopyString(type, (char*) g_VARTYPE);
                }
            }
            if( NOT(INSTR(str, "."))  AND  __b2c__STRCMP(LEFT(str, 1) ,  "(") != 0 ){
                if( REGEX(str, g_C_KEYWORDS) ){
                fprintf(stderr, "%sSyntax error: variable '%s' in DECLARE/GLOBAL statement at line %s in file '%s' is a C keyword or function!\n", NL, str, STR( g_COUNTER), g_CURFILE);
                    exit(1);
                }
                if( LEN(Get_Var(str)) ){
                fprintf(stderr, "%sSyntax error: variable '%s' in DECLARE/GLOBAL statement at line %s in file '%s' was defined previously!\n", NL, str, STR( g_COUNTER), g_CURFILE);
                    exit(1);
                }
            }
            if( ISTOKEN(arg, "ASSOC") ){
                Assoc_Array(str, type, 0);
            } else if( ISTOKEN(arg, "TREE") ){
                Binary_Tree(str, type, 0);
            } else if( ISTRUE(LEN(array)) ){
                Normal_Dyn_Array(type, str, array, FALSE, FALSE);
            } else if( NOT(REGEX(EXTRACT(type, "*"), "DIR|FILE|short$|int$|long$|float$|double$|char$|void|STRING|NUMBER|FLOATING")) ){
                if( INSTR(str, "=") ){
                fprintf(g_HFILE, "%s %s;\n", type, str);
                    Save_Main_Var(str, type);
                } else {
                fprintf(g_HFILE, "%s %s;\n", type, str);
                    Save_Main_Var(str, type);
                }
            } else if( ( INSTR(str, g_STRINGSIGN)  OR  REGEX(type, "STRING|char\\*$") )  AND  NOT(INSTR(str, "=")) ){
                if( NOT(LEN(Get_Var(str))) ){
                    if( INSTR(str, "[") ){
                    fprintf(g_HFILE, "char *%s = { NULL };\n", REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                        Save_Main_Var(str, "char*");
                    } else if( INSTR(str, "(") ){
                    fprintf(g_HFILE, "%s %s;\n", type, str);
                        str = b2c_CopyString(str, (char*) LEFT(str, INSTRREV(str, "(")-1));
                        Save_Main_Var(EXTRACT(str, "[\\(\\*\\)]", TRUE), "void*");
                    } else {
                    fprintf(g_HFILE, "char *%s = NULL;\n", str);
                        Save_Main_Var(str, "char*");
                    }
                }
            } else if( ( INSTR(str, g_STRINGSIGN)  OR  REGEX(type, "STRING|char\\*$") )  AND  INSTR(str, "=") ){
                if( NOT(LEN(Get_Var(str))) ){
                    if( REGEX(TOKEN(str, 1, "="), "\\[.*\\].*") ){
                        if( REGEX(str, "\\[.*\\]\\[") ){
                        fprintf(stderr, "%sSyntax error: multidimensional stringarrays at line %s in file '%s' are not supported!\n", NL, STR( g_COUNTER), g_CURFILE);
                            exit(1);
                        }
                    fprintf(g_HFILE, "char *%s[%s] = { NULL };\n", LEFT(str, INSTR(str, "[") - 1), STR(COUNT(str, 44)+1+g_OPTION_BASE));
                        Save_Main_Var(str, "char*");
                        opt=(
                        long)( g_OPTION_BASE);
                        array = F_MID(array,str, INSTR(str, "{")+1);
                        while( LEN(array) ){
                            i = b2c_CopyString(i, (char*) Mini_Parser(array));
                        fprintf(g_CFILE, "%s[%s] = b2c_CopyString(%s[%s], %s);\n", LEFT(str, INSTR(str, "[")-1), STR( opt), LEFT(str, INSTR(str, "[")-1), STR( opt), CHOP(i, "}", 2));
                            array = F_MID(array,array, LEN(i)+2);
                            opt = opt + (1);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    } else {
                        while( LEN(str) ){
                            i = b2c_CopyString(i, (char*) Mini_Parser(str));
                        fprintf(g_HFILE, "char *%s = NULL;\n", LEFT(i, INSTR(i, "=")-1));
                        fprintf(g_CFILE, "%s%s = b2c_CopyString(%s%s, %s);\n", g_WITHVAR, LEFT(i, INSTR(i, "=")-1), g_WITHVAR, LEFT(i, INSTR(i, "=")-1), MID(i, INSTR(i, "=")+1));
                            Save_Main_Var(LEFT(i, INSTR(i, "=")-1), "char*");
                            str = F_MID(str,str, LEN(i)+2);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    }
                }
            } else {
                if( INSTR(str, "[")  AND  NOT(INSTR(str, "=")) ){
                fprintf(g_HFILE, "%s %s = { 0 };\n", type, REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                    Save_Main_Var(str, type);
                } else if( INSTR(str, "[")  AND  INSTR(str, "=") ){
                fprintf(g_HFILE, "%s %s\n", type, MID(str, 1, INSTR(str, "{")));
                    opt=(
                    long)( g_OPTION_BASE);
                    if( (opt )> 0  AND  (COUNT(str, 91) )> 1 ){
                    fprintf(stderr, "%sWARNING: OPTION BASE has no impact on multidimensional array '%s' in DECLARE/GLOBAL statement at line %s in file '%s'!\n", NL, MID(str, 1, INSTR(str, "[")-1), STR( g_COUNTER), g_CURFILE);
                    }
                    while( (opt )> 0  AND  COUNT(str, 91) == 1 ){
                    fputs(" 0, \n", g_HFILE);
                        opt = opt - (1);
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                fprintf(g_HFILE, "%s;\n", MID(str, INSTR(str, "{")+1));
                    Save_Main_Var(str, type);
                } else if( INSTR(str, "(") ){
                fprintf(g_HFILE, "%s %s;\n", type, str);
                    str = b2c_CopyString(str, (char*) LEFT(str, INSTRREV(str, "(")-1));
                    Save_Main_Var(EXTRACT(str, "[\\(\\*\\)]", TRUE), "void*");
                } else {
                    b2c_forin_i_string = b2c_CopyString(b2c_forin_i_string, EXTRACT(str, " ")); b2c_forin_i_string_org = b2c_forin_i_string;
                    b2c_forin_i_step = b2c_CopyString(b2c_forin_i_step, ",");
                    b2c_forin_i_ptr = b2c_for_amount(b2c_forin_i_string, b2c_forin_i_step);
                    for(; b2c_forin_i_ptr > 0; b2c_forin_i_ptr--) { b2c_for_item(&b2c_forin_i_string_org, b2c_forin_i_step, &i);
                        if( INSTR(i, "=") ){
                        fprintf(g_HFILE, "%s %s;\n", type, i);
                        } else if( __b2c__STRCMP(RIGHT(type) ,  "*") == 0  OR  __b2c__STRCMP(LEFT(str) ,  "*") == 0 ){
                        fprintf(g_HFILE, "%s %s = NULL;\n", type, i);
                        } else {
                        fprintf(g_HFILE, "%s %s = 0;\n", type, i);
                        }
                        Save_Main_Var(i, type);
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                }
            }
        }
    }
    __b2c__STRFREE(b2c_forin_i_string); b2c_forin_i_string = NULL; __b2c__STRFREE(b2c_forin_i_step); b2c_forin_i_step = NULL;
    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(type);
    __b2c__STRFREE(array);
    __b2c__STRFREE(str);
    __b2c__STRFREE(i);
    b2c_catch_set = b2c_catch_set_backup;
}
