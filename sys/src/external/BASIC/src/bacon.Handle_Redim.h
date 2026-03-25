/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Redim( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *type = NULL;
    char *var = NULL;
    char *to = NULL;
    if( NOT(INSTR(arg, " TO ")) ){
    fprintf(stderr, "%sSyntax error: missing TO in REDIM statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    var = F_CHOP(var,LEFT(arg, INSTR(arg, " TO ") - 1));
    to = F_CHOP(to,MID(arg, INSTR(arg, " TO ") + 4));
    type = F_CHOP(type,Get_Var(var, g_FUNCNAME));
    if( NOT(LEN(type))  AND  NOT(Check_String_Type(var)) ){
    fprintf(stderr, "%sSyntax error: cannot REDIM array which is not declared previously at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( Check_String_Type(var) ){
    fprintf(g_CFILE, "if(%s<%s__b2c_array) {for(b2c_ctr=%s; b2c_ctr<%s__b2c_array; b2c_ctr++) {__b2c__STRFREE(%s[b2c_ctr+%s]);} }\n", to, var, to, var, var, STR( g_OPTION_BASE));
        type = b2c_CopyString(type, (char*) "char*");
    }
fprintf(g_CFILE, "%s = (%s*)realloc(%s, (%s+%s)*sizeof(%s));\n", var, type, var, to, STR( g_OPTION_BASE), type);
    if( REGEX(type, "_type$")  OR  REGEX(type, "_TYPE$") ){
    fprintf(g_CFILE, "if(__b2c_record_%s < %s) { for(b2c_ctr=__b2c_record_%s+%s; b2c_ctr<%s+%s; b2c_ctr++) memset(&%s[b2c_ctr], 0, sizeof(%s));}\n", MID(var, INSTR(var, ".")+1), to, MID(var, INSTR(var, ".")+1), STR( g_OPTION_BASE), to, STR( g_OPTION_BASE), var, type);
    fprintf(g_CFILE, "__b2c_record_%s = %s;\n", MID(var, INSTR(var, ".")+1), to);
    } else {
        if( Check_String_Type(var) ){
        fprintf(g_CFILE, "if(%s>%s__b2c_array) {for(b2c_ctr=%s__b2c_array; b2c_ctr<%s; b2c_ctr++) %s[b2c_ctr+%s] = (char*)calloc(1, sizeof(char));}\n", to, var, var, to, var, STR( g_OPTION_BASE));
        }
    fprintf(g_CFILE, "%s__b2c_array = %s;\n", var, to);
    }

    __b2c__STRFREE(arg);
    __b2c__STRFREE(type);
    __b2c__STRFREE(var);
    __b2c__STRFREE(to);
    b2c_catch_set = b2c_catch_set_backup;
}
