/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval 0
char* __Get_Var(int b2c_arg_tot, ...) {
long amount; long b2c_var_arg = 1; va_list b2c_ap; char **arg = NULL; arg = (char **)calloc(b2c_arg_tot+1, sizeof(char*)); amount = b2c_arg_tot; va_start(b2c_ap, b2c_arg_tot); while (b2c_arg_tot) { arg[b2c_var_arg] = b2c_CopyString(arg[b2c_var_arg], va_arg(b2c_ap, char*)); b2c_var_arg++; b2c_arg_tot--; } va_end(b2c_ap); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *var = NULL;
    char *result = NULL;
    char *record = NULL;
    if( INSTR(arg[(uint64_t)1], "=") ){
        var = b2c_CopyString(var, (char*) LEFT(arg[(uint64_t)1], INSTR(arg[(uint64_t)1], "=")-1));
    } else {
        var = b2c_CopyString(var, (char*) arg[(uint64_t)1]);
    }
    var = b2c_CopyString(var, (char*) EXTRACT(var, CHR(42)));
    if( (AMOUNT(var, ".") )> 1 ){
        record = b2c_CopyString(record, (char*) TOKEN(var, 1, "."));
        var = b2c_CopyString(var, (char*) TOKEN(var, 2, "."));
    } else {
        record = b2c_CopyString(record, (char*) g_RECORDVAR);
    }
    record = F_CHOP(record,EXTRACT(record,"\\[.*", TRUE));
    if( LEN(record) ){
        record = F_CONCAT(record, record , ".");
    }
    if( INSTR(var, "[") ){
        var = b2c_CopyString(var, (char*) LEFT(var, INSTR(var, "[")-1));
    }
    if( INSTR(var, "(") ){
        var = b2c_CopyString(var, (char*) LEFT(var, INSTR(var, "(")-1));
    }
    var = b2c_CopyString(var, (char*) REPLACE(var, "$", g_STRINGSIGN));
    var = b2c_CopyString(var, (char*) REPLACE(var, "#", g_FLOATSIGN));
    var = b2c_CopyString(var, (char*) REPLACE(var, "%", g_LONGSIGN));
    result = b2c_CopyString(result, (char*) g_ALL_MAIN_VARS( CONCAT(record , var) ));
    if( (amount )> 1  AND  NOT(LEN(result)) ){
        result = b2c_CopyString(result, (char*) g_ALL_FUNC_VARS( CONCAT(record , var) , arg[(uint64_t)2]));
    }
    b2c_assign = b2c_return(result);
    b2c_free_str_array_members(&arg, 1, amount); free(arg);
    __b2c__STRFREE(var);
    __b2c__STRFREE(result);
    __b2c__STRFREE(record);
    b2c_catch_set = b2c_catch_set_backup;
    return(b2c_assign);
    b2c_catch_set = b2c_catch_set_backup;
return (NULL);}
