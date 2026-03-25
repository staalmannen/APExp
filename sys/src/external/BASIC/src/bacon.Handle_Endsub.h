/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Endsub( void) {
    b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_element_ptr = 0; char* b2c_forin_element_string = NULL; char* b2c_forin_element_string_org = NULL; char* b2c_forin_element_step = NULL;
    FILE* tmp_HFILE = NULL;
    char *line = NULL;
    char *element = NULL;
    char *tfil = NULL;
    if( NOT(LEN(g_FUNCNAME)) ){
    fprintf(stderr, "%sSyntax error: ENDSUB outside SUB at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    fclose(g_CFILE);
    if( NOT(INSTR(g_PROTOTYPE, "::")) ){
    fprintf(g_HFILE, "void %s;\n", g_PROTOTYPE);
    }
    g_PROTOTYPE = b2c_CopyString(g_PROTOTYPE, (char*) "");
    tfil = F_MID(tfil,g_CURFILE, INSTRREV(g_CURFILE, "/") + 1);
    tmp_HFILE = fopen((const char*)CONCAT( g_TEMPDIR , "/" , LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h" ), "w");
if(tmp_HFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 2641, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(tmp_HFILE, "/* Created with BaCon %s - (c) Peter van Eerten - MIT License */\n", g_VERSION);
fputs("#undef b2c_exitval\n", tmp_HFILE);
fputs("#define b2c_exitval\n", tmp_HFILE);
    if( INSTR(g_ORIGFUNCNAME, " (") ){
    fprintf(tmp_HFILE, "void %s {\n", g_ORIGFUNCNAME);
    } else if( INSTR(g_ORIGFUNCNAME, "(") ){
    fprintf(tmp_HFILE, "void %s {\n", g_ORIGFUNCNAME);
    } else {
    fprintf(tmp_HFILE, "void %s(void) {\n", g_FUNCNAME);
    }
fprintf(tmp_HFILE, "%s\n", g_STRINGARGS);
    g_CFILE = fopen((const char*)g_CFILE, "r");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 2657, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    while( NOT(ENDFILE(g_CFILE)) ){
        b2c_readln(&b2c_assign, g_CFILE);
        line = b2c_CopyString(line, b2c_assign);
        __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
        if( NOT(ENDFILE(g_CFILE)) ){
        fprintf(tmp_HFILE, "%s\n", line);
        }
    }
    fclose(g_CFILE);
fprintf(tmp_HFILE, "%s\n", g_STRINGARRAYS);
    b2c_forin_element_string = b2c_CopyString(b2c_forin_element_string, g_LOCALSTRINGS); b2c_forin_element_string_org = b2c_forin_element_string;
    b2c_forin_element_step = b2c_CopyString(b2c_forin_element_step, b2c_option_delim);
    b2c_forin_element_ptr = b2c_for_amount(b2c_forin_element_string, b2c_forin_element_step);
    for(; b2c_forin_element_ptr > 0; b2c_forin_element_ptr--) { b2c_for_item(&b2c_forin_element_string_org, b2c_forin_element_step, &element);
        if( (LEN(element) )> 0 ){
        fprintf(tmp_HFILE, "__b2c__STRFREE(%s);\n", element);
        }
    }
    if( g_CATCH_USED == 1 ){
    fputs("__B2C__PROGRAM__EXIT: ;\n", tmp_HFILE);
    }
fputs("b2c_catch_set = b2c_catch_set_backup;\n", tmp_HFILE);
fputs("}\n", tmp_HFILE);
    fclose(tmp_HFILE);
    if( NOT(INSTR(g_INCLUDE_FILES, CONCAT( LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h") )) ){
        g_INCLUDE_FILES = F_CONCAT(g_INCLUDE_FILES, g_INCLUDE_FILES , " " , LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h") ;
    }
    g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_TEMPDIR , "/" , LEFT(tfil, INSTR(tfil, ".bac")) , g_FUNCNAME , ".h") ;
if(unlink(g_CFILE)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 2684, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    g_CFILE = b2c_CopyString(g_CFILE, (char*) g_COPY_CFILE);
    g_CFILE = fopen((const char*)g_CFILE, "a");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR APPENDING", 2688, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    g_CATCHGOTO = b2c_CopyString(g_CATCHGOTO, (char*) g_ORIGCATCHGOTO);
    g_CATCH_USED=(long)( g_ORIGCATCH_USED);
    g_ORIGFUNCNAME = b2c_CopyString(g_ORIGFUNCNAME, (char*) "");
    g_FUNCNAME = b2c_CopyString(g_FUNCNAME, (char*) "");
    g_LOCALSTRINGS = b2c_CopyString(g_LOCALSTRINGS, (char*) "");
    g_STRINGARRAYS = b2c_CopyString(g_STRINGARRAYS, (char*) "");
    g_STRINGARGS = b2c_CopyString(g_STRINGARGS, (char*) "");
    __b2c__STRFREE(b2c_forin_element_string); b2c_forin_element_string = NULL; __b2c__STRFREE(b2c_forin_element_step); b2c_forin_element_step = NULL;
    __b2c__STRFREE(line);
    __b2c__STRFREE(element);
    __b2c__STRFREE(tfil);
    __B2C__PROGRAM__EXIT: ;
    b2c_catch_set = b2c_catch_set_backup;
}
