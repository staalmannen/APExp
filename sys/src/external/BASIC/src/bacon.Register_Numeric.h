/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Register_Numeric( char *arg_in, char *__b2c_type) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); char*type = NULL; type = b2c_CopyString(NULL, __b2c_type); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    if( NOT(LEN(Get_Var(arg, g_FUNCNAME))) ){
        if( NOT(INSTR(arg, "::"))  AND  NOT(REGEX(arg, "\\[.*\\]"))  AND  NOT(TALLY(arg, "."))  AND  NOT(REGEX(arg, "\\(.*\\)"))  AND  NOT(TALLY(arg, "->")) ){
            if( __b2c__STRCMP(g_OPTION_EXPLICIT ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_EXPLICIT ,  "TRUE") == 0 ){
            fprintf(stderr, "%sSyntax error: OPTION EXPLICIT forces explicit variable declaration at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            }
            if( __b2c__STRCMP(g_OPTION_LOCAL ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_LOCAL ,  "TRUE") == 0 ){
                if( __b2c__STRCMP(type ,  "default") != 0 ){
                fprintf(g_CFILE, "%s %s = 0;\n", type, arg);
                    Save_Func_Var(arg, g_FUNCNAME, type);
                } else {
                    if( REGEX(arg, CONCAT( g_FLOATSIGN , "$") ) ){
                    fprintf(g_CFILE, "double %s = 0.0;\n", arg);
                        Save_Func_Var(arg, g_FUNCNAME, "double");
                    } else if( REGEX(arg, CONCAT( g_LONGSIGN , "$") ) ){
                    fprintf(g_CFILE, "long %s = 0;\n", arg);
                        Save_Func_Var(arg, g_FUNCNAME, "long");
                    } else {
                    fprintf(g_CFILE, "%s %s = 0;\n", g_VARTYPE, arg);
                        Save_Func_Var(arg, g_FUNCNAME, g_VARTYPE);
                    }
                }
            } else {
                if( __b2c__STRCMP(type ,  "default") != 0 ){
                fprintf(g_HFILE, "%s %s = 0;\n", type, arg);
                    Save_Main_Var(arg, type);
                } else {
                    if( REGEX(arg, CONCAT( g_FLOATSIGN , "$") ) ){
                    fprintf(g_HFILE, "double %s = 0.0;\n", arg);
                        Save_Main_Var(arg, "double");
                    } else if( REGEX(arg, CONCAT( g_LONGSIGN , "$") ) ){
                    fprintf(g_HFILE, "long %s = 0;\n", arg);
                        Save_Main_Var(arg, "long");
                    } else {
                    fprintf(g_HFILE, "%s %s = 0;\n", g_VARTYPE, arg);
                        Save_Main_Var(arg, g_VARTYPE);
                    }
                }
            }
        }
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(type);
    b2c_catch_set = b2c_catch_set_backup;
}
