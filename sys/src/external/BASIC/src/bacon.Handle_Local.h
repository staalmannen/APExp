/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Local( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *var = NULL;
    char *type = NULL;
    char *dim = NULL;
    char *dim2 = NULL;
    char *array = NULL;
    char *str = NULL;
    char *i = NULL;
    long opt = 0;
    long self_declared = 0;
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
            fprintf(stderr, "%sSyntax error: variable '%s' in LOCAL statement at line %s in file '%s' is a C keyword or function!\n", NL, str, STR( g_COUNTER), g_CURFILE);
                exit(1);
            }
            if( LEN(Get_Var(str, g_FUNCNAME)) ){
            fprintf(stderr, "%sSyntax error: variable '%s' in LOCAL statement at line %s in file '%s' was defined previously!\n", NL, str, STR( g_COUNTER), g_CURFILE);
                exit(1);
            }
        }
        if( ISTOKEN(arg, "ASSOC") ){
            Assoc_Array(str, type, IIF(LEN(g_FUNCNAME), 1, 0));
        } else if( ISTOKEN(arg, "TREE") ){
            Binary_Tree(str, type, IIF(LEN(g_FUNCNAME), 1, 0));
        } else if( ISTRUE(LEN(array)) ){
            if( INSTR(array, "STATIC") ){
                if( LEN(g_FUNCNAME) ){
                    Normal_Dyn_Array(type, str, MID(array, 1, INSTR(array, "STATIC")-1), TRUE, TRUE);
                } else {
                    Normal_Dyn_Array(type, str, MID(array, 1, INSTR(array, "STATIC")-1), TRUE, FALSE);
                }
            } else {
                if( LEN(g_FUNCNAME) ){
                    Normal_Dyn_Array(type, str, array, FALSE, TRUE);
                } else {
                    Normal_Dyn_Array(type, str, array, FALSE, FALSE);
                }
            }
        } else if( NOT(REGEX(EXTRACT(type, "*"), "DIR|FILE|short$|int$|long$|float$|double$|char$|void|STRING|NUMBER|FLOATING"))  AND  NOT(LEN(g_RECORDNAME)) ){
            if( INSTR(str, "=") ){
            fprintf(g_CFILE, "%s %s;\n", type, str);
                if( LEN(g_FUNCNAME) ){
                    Save_Func_Var(str, g_FUNCNAME, type);
                } else {
                    Save_Main_Var(str, type);
                }
            } else {
                if( LEN(g_FUNCNAME) ){
                fprintf(g_CFILE, "%s %s;\n", type, str);
                    Save_Func_Var(str, g_FUNCNAME, type);
                } else {
                fprintf(g_HFILE, "%s %s;\n", type, str);
                    Save_Main_Var(str, type);
                }
            }
        } else if( ( REGEX(type, "STRING|char\\*$")  OR  INSTR(str, g_STRINGSIGN) )  AND  NOT(INSTR(str, "="))  AND  NOT(REGEX(type, CONCAT( ".+\\[.+" , g_STRINGSIGN , "\\]") )) ){
            if( NOT(LEN(Get_Var(str, g_FUNCNAME))) ){
                if( REGEX(str, "\\[.*\\]\\[") ){
                fprintf(stderr, "%sSyntax error: multidimensional stringarrays at line %s in file '%s' are not supported!\n", NL, STR( g_COUNTER), g_CURFILE);
                    exit(1);
                }
                if( ISTRUE(LEN(g_FUNCNAME)) ){
                    if( ISTRUE(LEN(g_RECORDNAME)) ){
                        if( REGEX(str, "\\[.*\\]") ){
                        fprintf(g_CFILE, "char *%s;\n", REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                            dim = F_MID(dim,str, INSTR(str, "[") + 1);
                            if( REGEX(g_RECORDVAR, "\\[.*\\]") ){
                                if( LEN(g_RECORDARRAY) ){
                                    dim2 = F_CONCAT(dim2, "__b2c_record_" , EXTRACT(g_RECORDNAME, "_TYPE")) ;
                                } else {
                                    dim2 = F_MID(dim2,g_RECORDVAR, INSTR(g_RECORDVAR, "[") + 1);
                                }
                                g_RECORDEND_BODY = F_CONCAT(g_RECORDEND_BODY, g_RECORDEND_BODY , " for(b2c_counter=0; b2c_counter<" , LEFT(dim2, INSTR(dim2, "]") - 1) , ";b2c_counter++) {for(b2c_ctr=0; b2c_ctr<" , LEFT(dim, INSTR(dim, "]") - 1) , "; b2c_ctr++)" , LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1) , "[b2c_counter]." , LEFT(str, INSTR(str, "[")-1) , "[b2c_ctr] = NULL;}") ;
                                g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " for(b2c_counter=0; b2c_counter<" , LEFT(dim2, INSTR(dim2, "]") - 1) , ";b2c_counter++) {for(b2c_ctr=0; b2c_ctr<" , LEFT(dim, INSTR(dim, "]") - 1) , "; b2c_ctr++) { __b2c__STRFREE(" , LEFT(g_RECORDVAR, INSTR(g_RECORDVAR, "[")-1) , "[b2c_counter]." , LEFT(str, INSTR(str, "[")-1) , "[b2c_ctr]);} }") ;
                            } else {
                                g_RECORDEND_BODY = F_CONCAT(g_RECORDEND_BODY, g_RECORDEND_BODY , " for(b2c_ctr=0; b2c_ctr<" , LEFT(dim, INSTR(dim, "]") - 1) , "; b2c_ctr++)" , g_RECORDVAR , "." , LEFT(str, INSTR(str, "[")-1) , "[b2c_ctr] = NULL;") ;
                                g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_free_str_array_members(&" , TOKEN(str, 1, "[") , ", " , STR(g_OPTION_BASE) , ", " , g_RECORDVAR , "." , TOKEN(dim, 1, "]") , ");") ;
                            }
                        } else {
                        fprintf(g_CFILE, "char *%s;\n", str);
                            if( INSTR(str, g_STRINGSIGN)  AND  NOT(REGEX(g_RECORDVAR, "\\[.*\\]"))  AND  NOT(LEN(g_RECORDARRAY)) ){
                                g_RECORDEND_BODY = F_CONCAT(g_RECORDEND_BODY, g_RECORDEND_BODY , " " , g_RECORDVAR , "." , str , " = NULL;") ;
                                g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , g_RECORDVAR , "." , str) ;
                            }
                        }
                        Save_Func_Var(str, g_FUNCNAME, "char*");
                    } else {
                        if( REGEX(str, "\\[.*\\]") ){
                        fprintf(g_CFILE, "char *%s = { NULL };\n", REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                            Save_Func_Var(str, g_FUNCNAME, "char*");
                            dim = F_MID(dim,str, INSTR(str, "[") + 1);
                            g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " for(b2c_ctr=0; b2c_ctr<" , TOKEN(dim, 1, "]") , "; b2c_ctr++) { __b2c__STRFREE(" , g_WITHVAR , TOKEN(str, 1, "[") , "[b2c_ctr]); }") ;
                        } else if( INSTR(str, "(") ){
                        fprintf(g_CFILE, "%s %s;\n", type, str);
                            str = b2c_CopyString(str, (char*) LEFT(str, INSTRREV(str, "(")-1));
                            Save_Func_Var(EXTRACT(str, "[\\(\\*\\)]", TRUE), g_FUNCNAME, "void*");
                        } else {
                        fprintf(g_CFILE, "char *%s = NULL;\n", str);
                            Save_Func_Var(str, g_FUNCNAME, "char*");
                            if( INSTR(str, g_STRINGSIGN) ){
                                g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , str) ;
                            }
                        }
                    }
                } else {
                    if( ISTRUE(LEN(g_RECORDNAME)) ){
                        if( REGEX(str, "\\[.*\\]") ){
                        fprintf(g_HFILE, "char *%s;\n", REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                        } else {
                        fprintf(g_HFILE, "char *%s;\n", str);
                            if( INSTR(str, g_STRINGSIGN)  AND  NOT(REGEX(g_RECORDVAR, "\\[.*\\]"))  AND  NOT(LEN(g_RECORDARRAY)) ){
                                g_RECORDEND_BODY = F_CONCAT(g_RECORDEND_BODY, g_RECORDEND_BODY , " " , g_RECORDVAR , "." , CHOP(str) , " = NULL;");
                            }
                        }
                        Save_Main_Var(str, "char*");
                    } else {
                        if( REGEX(str, "\\[.*\\]") ){
                        fprintf(g_HFILE, "char *%s = { NULL };\n", REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                            Save_Main_Var(str, "char*");
                        } else if( INSTR(str, "(") ){
                        fprintf(g_HFILE, "%s %s;\n", type, str);
                            str = b2c_CopyString(str, (char*) LEFT(str, INSTRREV(str, "(")-1));
                            Save_Main_Var(EXTRACT(str, "[\\(\\*\\)]", TRUE), "void*");
                        } else {
                        fprintf(g_HFILE, "char *%s = NULL; \n", str);
                            Save_Main_Var(str, "char*");
                        }
                    }
                }
            }
        } else if( ( INSTR(str, g_STRINGSIGN)  OR  REGEX(type, "STRING|char\\*") )  AND  INSTR(str, "=") ){
            if( ISTRUE(LEN(g_FUNCNAME)) ){
                if( NOT(LEN(Get_Var(str, g_FUNCNAME))) ){
                    if( REGEX(TOKEN(str, 1, "="), "\\[.*\\].*") ){
                        if( REGEX(str, "\\[.*\\]\\[") ){
                        fprintf(stderr, "%sSyntax error: multidimensional stringarrays at line %s in file '%s' are not supported!\n", NL, STR( g_COUNTER), g_CURFILE);
                            exit(1);
                        }
                    fprintf(g_CFILE, "static char *%s[%s+%s] = { NULL };\n", LEFT(str, INSTR(str, "[") - 1), STR(COUNT(str, 44)+1), STR(g_OPTION_BASE));
                        if( LEN(g_RECORDVAR) ){
                        fprintf(stderr, "%sSyntax error: C does not allow initialization of an array within a struct at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                            exit(1);
                        }
                        Save_Func_Var(str, g_FUNCNAME, "char*");
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
                        fprintf(g_CFILE, "static char *%s = NULL;\n", LEFT(i, INSTR(i, "=")-1));
                        fprintf(g_CFILE, "%s%s = b2c_CopyString(%s%s, %s);\n", g_WITHVAR, LEFT(i, INSTR(i, "=")-1), g_WITHVAR, LEFT(i, INSTR(i, "=")-1), MID(i, INSTR(i, "=")+1));
                            Save_Func_Var(LEFT(i, INSTR(i, "=")-1), g_FUNCNAME, "char*");
                            str = F_MID(str,str, LEN(i)+2);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    }
                }
            } else {
                if( NOT(LEN(Get_Var(str, g_FUNCNAME))) ){
                    if( REGEX(TOKEN(str, 1, "="), "\\[.*\\].*") ){
                        if( REGEX(str, "\\[.*\\]\\[") ){
                        fprintf(stderr, "%sSyntax error: multidimensional stringarrays at line %s in file '%s' are not supported!\n", NL, STR( g_COUNTER), g_CURFILE);
                            exit(1);
                        }
                    fprintf(g_HFILE, "char *%s[%s] = { NULL };\n", LEFT(str, INSTR(str, "[") - 1), STR(COUNT(str, 44)+1+g_OPTION_BASE));
                        if( LEN(g_RECORDVAR) ){
                        fprintf(stderr, "%sSyntax error: C does not allow initialization of an array within a struct at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                            exit(1);
                        }
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
            }
        } else {
            if( ISTRUE(LEN(g_FUNCNAME)) ){
                if( INSTR(str, "[")  AND  NOT(INSTR(str, "=")) ){
                    if( NOT(LEN(g_RECORDNAME)) ){
                    fprintf(g_CFILE, "%s %s = { 0 };\n", type, REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                    } else {
                    fprintf(g_CFILE, "%s %s;\n", type, REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                    }
                    Save_Func_Var(str, g_FUNCNAME, type);
                } else if( INSTR(str, "[")  AND  INSTR(str, "=") ){
                fprintf(g_CFILE, "%s %s\n", type, MID(str, 1, INSTR(str, "{")));
                    opt=(
                    long)( g_OPTION_BASE);
                    if( (opt )> 0  AND  (COUNT(str, 91) )> 1 ){
                    fprintf(stderr, "%sWARNING: OPTION BASE has no impact on multidimensional array '%s' in LOCAL statement at line %s in file '%s'!\n", NL, MID(str, 1, INSTR(str, "[")-1), STR( g_COUNTER), g_CURFILE);
                    }
                    while( (opt )> 0  AND  COUNT(str, 91) == 1 ){
                    fputs(" 0, \n", g_CFILE);
                        opt = opt - (1);
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                fprintf(g_CFILE, "%s;\n", MID(str, INSTR(str, "{")+1));
                    if( LEN(g_RECORDVAR) ){
                    fprintf(stderr, "%sSyntax error: C does not allow initialization of an array within a struct at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                        exit(1);
                    }
                    Save_Func_Var(str, g_FUNCNAME, type);
                } else if( INSTR(str, "(") ){
                fprintf(g_CFILE, "%s %s;\n", type, str);
                    str = b2c_CopyString(str, (char*) LEFT(str, INSTRREV(str, "(")-1));
                    Save_Func_Var(EXTRACT(str, "[\\(\\*\\)]", TRUE), g_FUNCNAME, "void*");
                } else {
                    if( INSTR(str, "=")  OR  LEN(g_RECORDVAR) ){
                    fprintf(g_CFILE, "%s %s;\n", type, str);
                    } else if( __b2c__STRCMP(RIGHT(type) ,  "*") == 0  OR  __b2c__STRCMP(LEFT(str) ,  "*") == 0 ){
                    fprintf(g_CFILE, "%s %s = NULL;\n", type, str);
                    } else {
                    fprintf(g_CFILE, "%s %s = 0;\n", type, str);
                    }
                    Save_Func_Var(str, g_FUNCNAME, type);
                }
            } else {
                if( INSTR(str, "[")  AND  NOT(INSTR(str, "=")) ){
                    if( NOT(LEN(g_RECORDNAME)) ){
                    fprintf(g_HFILE, "%s %s = { 0 };\n", type, REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                    } else {
                    fprintf(g_HFILE, "%s %s;\n", type, REPLACE(str, "]", CONCAT( "+" , STR(g_OPTION_BASE) , "]") ));
                    }
                    Save_Main_Var(str, type);
                } else if( INSTR(str, "[")  AND  INSTR(str, "=") ){
                fprintf(g_HFILE, "%s %s\n", type, MID(str, 1, INSTR(str, "{")));
                    opt=(
                    long)( g_OPTION_BASE);
                    if( (opt )> 0  AND  (COUNT(str, 91) )> 1 ){
                    fprintf(stderr, "%sWARNING: OPTION BASE has no impact on multidimensional array '%s' in LOCAL statement at line %s in file '%s'!\n", NL, MID(str, 1, INSTR(str, "[")-1), STR( g_COUNTER), g_CURFILE);
                    }
                    while( (opt )> 0  AND  COUNT(str, 91) == 1 ){
                    fputs(" 0, \n", g_HFILE);
                        opt = opt - (1);
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                fprintf(g_HFILE, "%s;\n", MID(str, INSTR(str, "{")+1));
                    if( LEN(g_RECORDVAR) ){
                    fprintf(stderr, "%sSyntax error: C does not allow initialization of an array within a struct at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                        exit(1);
                    }
                    Save_Main_Var(str, type);
                } else if( INSTR(str, "(") ){
                fprintf(g_HFILE, "%s %s;\n", type, str);
                    str = b2c_CopyString(str, (char*) LEFT(str, INSTRREV(str, "(")-1));
                    Save_Main_Var(EXTRACT(str, "[\\(\\*\\)]", TRUE), "void*");
                } else {
                    if( INSTR(str, "=")  OR  LEN(g_RECORDVAR) ){
                    fprintf(g_HFILE, "%s %s;\n", type, str);
                    } else if( __b2c__STRCMP(RIGHT(type) ,  "*") == 0  OR  __b2c__STRCMP(LEFT(str) ,  "*") == 0 ){
                    fprintf(g_HFILE, "%s %s = NULL;\n", type, str);
                    } else {
                    fprintf(g_HFILE, "%s %s = 0;\n", type, str);
                    }
                    Save_Main_Var(str, type);
                }
            }
        }
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(type);
    __b2c__STRFREE(dim);
    __b2c__STRFREE(dim2);
    __b2c__STRFREE(array);
    __b2c__STRFREE(str);
    __b2c__STRFREE(i);
    b2c_catch_set = b2c_catch_set_backup;
}
