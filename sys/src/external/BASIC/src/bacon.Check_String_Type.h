/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval 0
long Check_String_Type( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *type = NULL;
    arg = b2c_CopyString(arg, (char*) EXTRACT(arg, "\\(uint64_t\\)", TRUE));
    arg = b2c_CopyString(arg, (char*) IIF(TALLY(arg, "("), TOKEN(arg, 1, "("), arg));
    if( INSTR(arg, CHR(34))  OR  __b2c__STRCMP(RIGHT(arg, 1) ,  "$") == 0 ){

        __b2c__STRFREE(arg);
        __b2c__STRFREE(type);
        b2c_catch_set = b2c_catch_set_backup;
        return(TRUE);
    } else {
        type = b2c_CopyString(type, (char*) Get_Var(arg, g_FUNCNAME));
        if( LEN(type) ){
            if( INSTR(type, "char*")  OR  INSTR(type, "STRING") ){

                __b2c__STRFREE(arg);
                __b2c__STRFREE(type);
                b2c_catch_set = b2c_catch_set_backup;
                return(TRUE);
            } else {

                __b2c__STRFREE(arg);
                __b2c__STRFREE(type);
                b2c_catch_set = b2c_catch_set_backup;
                return(FALSE);
            }
        } else if( INSTR(arg, g_STRINGSIGN)  AND  NOT(INSTR(arg, "__b2c_array")) ){

            __b2c__STRFREE(arg);
            __b2c__STRFREE(type);
            b2c_catch_set = b2c_catch_set_backup;
            return(TRUE);
        } else {

            __b2c__STRFREE(arg);
            __b2c__STRFREE(type);
            b2c_catch_set = b2c_catch_set_backup;
            return(FALSE);
        }
    }
    b2c_catch_set = b2c_catch_set_backup;
return(0);}
