/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Save_Main_Var( char *__b2c_var, char *__b2c_type) {
    char*var = NULL; var = b2c_CopyString(NULL, __b2c_var); char*type = NULL; type = b2c_CopyString(NULL, __b2c_type); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    if( __b2c__STRCMP(LEFT(var, 1) ,  "*") == 0 ){
        type = F_CONCAT(type, type , FILL(COUNT(var, 42), 42)) ;
        var = b2c_CopyString(var, (char*) EXTRACT(var, CHR(42)));
    }
    if( INSTR(var, "=") ){
        var = b2c_CopyString(var, (char*) LEFT(var, INSTR(var, "=")-1));
    }
    if( INSTR(var, "[") ){
        var = b2c_CopyString(var, (char*) LEFT(var, INSTR(var, "[")-1));
    }
    if( LEN(g_RECORDVAR) ){
        if( LEN(var) ){
            b2c_hash_add_str(assoc_g_ALL_MAIN_VARS, type,  CONCAT(CHOP(EXTRACT(g_RECORDVAR,"\\[.*", TRUE)) , "." , CHOP(var)) );
        } else {
            b2c_hash_add_str(assoc_g_ALL_MAIN_VARS, type, CHOP(EXTRACT(g_RECORDVAR,"\\[.*", TRUE)));
        }
    } else {
        b2c_hash_add_str(assoc_g_ALL_MAIN_VARS, type, CHOP(var));
    }

    __b2c__STRFREE(var);
    __b2c__STRFREE(type);
    b2c_catch_set = b2c_catch_set_backup;
}
