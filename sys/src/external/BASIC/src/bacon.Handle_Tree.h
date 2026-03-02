/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Tree( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 3740 "bacon.bac"
char *tree__b2c__string_var = NULL;
char *node__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *func__b2c__string_var = NULL;
char *uniq__b2c__string_var = NULL;
long total = 0;
#line 3743 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "NODE"))  AND  NOT(ISTOKEN(arg__b2c__string_var, "ADD")) ){
#line 3744 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing NODE/ADD in TREE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3745 "bacon.bac"
exit(1);
#line 3746 "bacon.bac"
}
#line 3749 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "NODE") ){
#line 3750 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "TREE * NODE * TYPE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3751 "bacon.bac"
} else {
#line 3752 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "TREE * ADD * TYPE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3753 "bacon.bac"
}
#line 3754 "bacon.bac"
tree__b2c__string_var = __b2c_Copy_String(tree__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 3755 "bacon.bac"
node__b2c__string_var = __b2c_Copy_String(node__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3756 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3]));
#line 3758 "bacon.bac"
if( NOT(LEN(type__b2c__string_var)) ){
#line 3759 "bacon.bac"
func__b2c__string_var = __b2c_Copy_String(func__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__tree_" , tree__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 3760 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) TOKEN__b2c__string_var(func__b2c__string_var, 2, ":"));
#line 3761 "bacon.bac"
}
#line 3763 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "char*") == 0 ){
#line 3764 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = __b2c_Copy_String(NULL, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) node__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); __b2c__tree_add((void*)__b2c__assign, &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tree__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(func__b2c__string_var, 1, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3765 "bacon.bac"
} else {
#line 3766 "bacon.bac"
uniq__b2c__string_var = F_CONCAT__b2c__string_var(uniq__b2c__string_var, "__b2c__" , tree__b2c__string_var , "_" , STR__b2c__string_var(g_COUNTER) , "_" , STR__b2c__string_var(RND)) ;
#line 3767 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*)malloc(sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")); *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) node__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; __b2c__tree_add((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tree__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(func__b2c__string_var, 1, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3768 "bacon.bac"
}
#line 3770 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 3771 "bacon.bac"
if( NOT(INSTR(g_STRINGARRAYS__b2c__string_var, CONCAT__b2c__string_var( "__b2c__binary_tree_free(" , tree__b2c__string_var , ",") )) ){
#line 3772 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__binary_tree_free(" , tree__b2c__string_var , ", " , TOKEN__b2c__string_var(func__b2c__string_var, 1, ":") , ");") ;
#line 3773 "bacon.bac"
}
#line 3774 "bacon.bac"
} else {
#line 3775 "bacon.bac"
if( NOT(INSTR(g_GLOBALARRAYS__b2c__string_var, CONCAT__b2c__string_var( "__b2c__binary_tree_free(" , tree__b2c__string_var , ",") )) ){
#line 3776 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " __b2c__binary_tree_free(" , tree__b2c__string_var , ", " , TOKEN__b2c__string_var(func__b2c__string_var, 1, ":") , ");") ;
#line 3777 "bacon.bac"
}
#line 3778 "bacon.bac"
}
#line 3780 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(tree__b2c__string_var);
__b2c__STRFREE(node__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(func__b2c__string_var);
__b2c__STRFREE(uniq__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
