/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_Tree( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0;
    char *tree = NULL;
    char *node = NULL;
    char *type = NULL;
    char *func = NULL;
    char *uniq = NULL;
    long total = 0;
    if( NOT(ISTOKEN(arg, "NODE"))  AND  NOT(ISTOKEN(arg, "ADD")) ){
    fprintf(stderr, "%sSyntax error: missing NODE/ADD in TREE statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( ISTOKEN(arg, "NODE") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "TREE * NODE * TYPE *", b2c_option_delim);
        total = match__b2c_array;
    } else {
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(arg), "TREE * ADD * TYPE *", b2c_option_delim);
        total = match__b2c_array;
    }
    tree = b2c_CopyString(tree, (char*) match[(uint64_t)1]);
    node = b2c_CopyString(node, (char*) match[(uint64_t)2]);
    type = b2c_CopyString(type, (char*) IIF((total )> 2, match[(uint64_t)3]));
    if( NOT(LEN(type)) ){
        func = b2c_CopyString(func, (char*) Get_Var( CONCAT("b2c_tree_" , tree) , g_FUNCNAME));
        type = b2c_CopyString(type, (char*) TOKEN(func, 2, ":"));
    }
    if( __b2c__STRCMP(type ,  "char*") == 0 ){
    fprintf(g_CFILE, "b2c_assign = b2c_CopyString(NULL, %s); b2c_tree_add((void*)b2c_assign, &%s, %s);\n", node, tree, TOKEN(func, 1, ":"));
    } else {
        uniq = F_CONCAT(uniq, "__b2c__" , tree , "_" , STR(g_COUNTER) , "_" , STR(RND)) ;
    fprintf(g_CFILE, "%s *%s = (%s*)malloc(sizeof(%s)); *%s = (%s)%s; b2c_tree_add((void*)%s, &%s, %s);\n", type, uniq, type, type, uniq, type, node, uniq, tree, TOKEN(func, 1, ":"));
    }
    if( ISTRUE(LEN(g_FUNCNAME)) ){
        if( NOT(INSTR(g_STRINGARRAYS, CONCAT( "b2c_binary_tree_free(" , tree , ",") )) ){
            g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_binary_tree_free(" , tree , ", " , TOKEN(func, 1, ":") , ");") ;
        }
    } else {
        if( NOT(INSTR(g_GLOBALARRAYS, CONCAT( "b2c_binary_tree_free(" , tree , ",") )) ){
            g_GLOBALARRAYS = F_CONCAT(g_GLOBALARRAYS, g_GLOBALARRAYS , " b2c_binary_tree_free(" , tree , ", " , TOKEN(func, 1, ":") , ");") ;
        }
    }
    b2c_free_str_array_members(&match, 1, match__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(tree);
    __b2c__STRFREE(node);
    __b2c__STRFREE(type);
    __b2c__STRFREE(func);
    __b2c__STRFREE(uniq);
    __b2c__STRFREE(match);
    b2c_catch_set = b2c_catch_set_backup;
}
