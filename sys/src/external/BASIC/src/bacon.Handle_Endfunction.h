/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Endfunction( void) {
    b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    char *line = NULL;
    char *tfil = NULL;
    FILE* tmp_HFILE = NULL;
    if( NOT(LEN(g_FUNCNAME)) ){
    fprintf(stderr, "%sSyntax error: ENDFUNC(TION) outside FUNCTION at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISFALSE(LEN(g_FUNCTYPE)) ){
    fprintf(stderr, "%sSyntax error: function '%s' was defined without returning a value or string!\n", NL, g_FUNCNAME);
        exit(1);
    }
    fclose(g_CFILE);
    if( NOT(INSTR(g_PROTOTYPE, "::")) ){
    fprintf(g_HFILE, "%s %s;\n", g_FUNCTYPE, g_PROTOTYPE);
    }
    g_PROTOTYPE = b2c_CopyString(g_PROTOTYPE, (char*) "");
    tfil = F_MID(tfil,g_CURFILE, INSTRREV(g_CURFILE, "/") + 1);
    tmp_HFILE = fopen((const char*)CONCAT( g_TEMPDIR , "/" , LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h" ), "w");
if(tmp_HFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 2210, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(tmp_HFILE, "/* Created with BaCon %s - (c) Peter van Eerten - MIT License */\n", g_VERSION);
fputs("#undef b2c_exitval\n", tmp_HFILE);
fputs("#define b2c_exitval 0\n", tmp_HFILE);
    if( NOT(INSTR(g_ORIGFUNCNAME, "(")) ){
    fprintf(tmp_HFILE, "%s %s(void) {\n", g_FUNCTYPE, g_FUNCNAME);
    } else {
    fprintf(tmp_HFILE, "%s %s {\n", g_FUNCTYPE, g_ORIGFUNCNAME);
    }
fprintf(tmp_HFILE, "%s\n", g_STRINGARGS);
    g_CFILE = fopen((const char*)g_CFILE, "r");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 2224, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    while( NOT(ENDFILE(g_CFILE)) ){
        b2c_readln(&b2c_assign, g_CFILE);
        line = b2c_CopyString(line, b2c_assign);
        __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
        if( NOT(ENDFILE(g_CFILE)) ){
        fprintf(tmp_HFILE, "%s\n", line);
        }
    }
    fclose(g_CFILE);
    if( g_CATCH_USED == 1 ){
    fputs("__B2C__PROGRAM__EXIT: ;\n", tmp_HFILE);
    }
fputs("b2c_catch_set = b2c_catch_set_backup;\n", tmp_HFILE);
    if( REGEX(g_FUNCTYPE, "char\\*$|STRING$") ){
    fputs("return (NULL);}\n", tmp_HFILE);
    } else if( REGEX(g_FUNCTYPE, "char$|short$|int$|long$|double$|float$|NUMBER$|FLOATING$") ){
    fputs("return (0);}\n", tmp_HFILE);
    } else {
    fputs("}\n", tmp_HFILE);
    }
    fclose(tmp_HFILE);
    if( NOT(INSTR(g_INCLUDE_FILES, CONCAT( LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h") )) ){
        g_INCLUDE_FILES = F_CONCAT(g_INCLUDE_FILES, g_INCLUDE_FILES , " " , LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h") ;
    }
    g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_TEMPDIR , "/" , LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h") ;
if(unlink(g_CFILE)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 2256, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    g_CFILE = b2c_CopyString(g_CFILE, (char*) g_COPY_CFILE);
    g_CFILE = fopen((const char*)g_CFILE, "a");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR APPENDING", 2260, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    g_CATCHGOTO = b2c_CopyString(g_CATCHGOTO, (char*) g_ORIGCATCHGOTO);
    g_CATCH_USED=(long)( g_ORIGCATCH_USED);
    g_ORIGFUNCNAME = b2c_CopyString(g_ORIGFUNCNAME, (char*) "");
    g_FUNCNAME = b2c_CopyString(g_FUNCNAME, (char*) "");
    g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) "");
    g_LOCALSTRINGS = b2c_CopyString(g_LOCALSTRINGS, (char*) "");
    g_STRINGARRAYS = b2c_CopyString(g_STRINGARRAYS, (char*) "");
    g_STRINGARGS = b2c_CopyString(g_STRINGARGS, (char*) "");

    __b2c__STRFREE(line);
    __b2c__STRFREE(tfil);
    __B2C__PROGRAM__EXIT: ;
    b2c_catch_set = b2c_catch_set_backup;
}
