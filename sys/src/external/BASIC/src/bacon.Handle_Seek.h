/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Seek( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0; char *b2c_select_2773 = NULL;
    char *descriptor = NULL;
    char *offset = NULL;
    char *whence = NULL;
    long total = 0;
    if( NOT(ISTOKEN(arg, "OFFSET")) ){
    fprintf(stderr, "%sSyntax error: missing OFFSET in SEEK statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "SEEK * OFFSET * WHENCE *", b2c_option_delim);
    total = match__b2c_array;
    descriptor = b2c_CopyString(descriptor, (char*) match[(uint64_t)1]);
    offset = b2c_CopyString(offset, (char*) match[(uint64_t)2]);
    whence = b2c_CopyString(whence, (char*) IIF((total )> 2, match[(uint64_t)3]));
    b2c_select_2773 = b2c_CopyString(b2c_select_2773, whence);
    if ( !b2c_strcmp(b2c_select_2773, "START")){
    fprintf(g_CFILE, "fseek(%s, %s, SEEK_SET);\n", descriptor, offset);
    } else  if ( !b2c_strcmp(b2c_select_2773, "CURRENT")){
    fprintf(g_CFILE, "fseek(%s, %s, SEEK_CUR);\n", descriptor, offset);
    } else  if ( !b2c_strcmp(b2c_select_2773, "END")){
    fprintf(g_CFILE, "fseek(%s, %s, SEEK_END);\n", descriptor, offset);
    } else {
    fprintf(g_CFILE, "fseek(%s, %s, SEEK_SET);\n", descriptor, offset);
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(descriptor);
    __b2c__STRFREE(offset);
    __b2c__STRFREE(whence);
    __b2c__STRFREE(match);
    __b2c__STRFREE(b2c_select_2773);
    b2c_catch_set = b2c_catch_set_backup;
}
