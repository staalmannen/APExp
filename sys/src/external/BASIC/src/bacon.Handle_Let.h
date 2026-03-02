/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Let( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 686 "bacon.bac"
unsigned long x = 0;
#line 687 "bacon.bac"
long in_string = 0;
long escaped = 0;
long pos = 0;
long in_func = 0;
char *var__b2c__string_var = NULL;
char *tmp__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *lft__b2c__string_var = NULL;
char *rel__b2c__string_var = NULL;
char *ptr__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *item__b2c__string_var = NULL;
#line 690 "bacon.bac"
for(x=1; x <= LEN(arg__b2c__string_var); x+=1){
#line 691 "bacon.bac"
__b2c__select_691 = (double)ASC(MID__b2c__string_var(arg__b2c__string_var, x, 1));
#line 692 "bacon.bac"
 if ( (__b2c__select_691) == (92)){
#line 693 "bacon.bac"
if( escaped ){
#line 694 "bacon.bac"
escaped=(
long)( FALSE);
#line 695 "bacon.bac"
} else {
#line 696 "bacon.bac"
escaped=(
long)( TRUE);
#line 697 "bacon.bac"
}
#line 698 "bacon.bac"
} else  if ( (__b2c__select_691) == (34)){
#line 699 "bacon.bac"
if( ISFALSE(escaped) ){
in_string=(
long)( NOT(in_string));
}
#line 700 "bacon.bac"
escaped=(
long)( FALSE);
#line 701 "bacon.bac"
} else  if ( (__b2c__select_691) == (40)){
#line 702 "bacon.bac"
if( ISFALSE(in_string) ){
in_func = in_func + (1);
}
#line 703 "bacon.bac"
escaped=(
long)( FALSE);
#line 704 "bacon.bac"
} else  if ( (__b2c__select_691) == (41)){
#line 705 "bacon.bac"
if( ISFALSE(in_string) ){
in_func = in_func - (1);
}
#line 706 "bacon.bac"
escaped=(
long)( FALSE);
#line 707 "bacon.bac"
} else  if ( (__b2c__select_691) == (61)){
#line 708 "bacon.bac"
if( ISFALSE(in_string)  AND  ISFALSE(in_func) ){
pos=(
long)( x);
}
#line 709 "bacon.bac"
escaped=(
long)( FALSE);
#line 710 "bacon.bac"
} else {
#line 711 "bacon.bac"
escaped=(
long)( FALSE);
#line 712 "bacon.bac"
}
#line 713 "bacon.bac"
}
#line 716 "bacon.bac"
if( NOT(pos) ){
#line 717 "bacon.bac"
if( __b2c__STRCMP(g_IGNORE_PARSE__b2c__string_var ,  "0") == 0  OR  __b2c__STRCMP(g_IGNORE_PARSE__b2c__string_var ,  "FALSE") == 0 ){
#line 718 "bacon.bac"
__b2c__assign = (char*)arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 719 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(tmp__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(rel__b2c__string_var);
__b2c__STRFREE(ptr__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(item__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return __b2c__exitval;
#line 720 "bacon.bac"
} else {
#line 721 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: could not parse line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "': "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 722 "bacon.bac"
exit(1);
#line 723 "bacon.bac"
}
#line 724 "bacon.bac"
}
#line 727 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,LEFT__b2c__string_var(arg__b2c__string_var, pos - 1));
#line 728 "bacon.bac"
tmp__b2c__string_var = F_CHOP__b2c__string_var(tmp__b2c__string_var,MID__b2c__string_var(arg__b2c__string_var, pos + 1));
#line 731 "bacon.bac"
if( REGEX(tmp__b2c__string_var, "[ \\t]*MEMORY[ \\t]*\\(")  OR  REGEX(tmp__b2c__string_var, "[ \\t]*BLOAD[ \\t]*\\(") ){
__b2c__hash_add_str(__b2c__assoc_g_SEMANTIC_MEMFREE__b2c__string_var, CONCAT__b2c__string_var( "'" , var__b2c__string_var , "' at line " , STR__b2c__string_var(g_COUNTER) , " in file '" , g_CURFILE__b2c__string_var , "'"), var__b2c__string_var);
}
#line 734 "bacon.bac"
if( REGEX(var__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") )  AND  NOT(ISTOKEN(g_DYNAMICARRAYS__b2c__string_var, CONCAT__b2c__string_var( var__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) )) ){
#line 735 "bacon.bac"
Register_Pointer(var__b2c__string_var, "char*");
#line 736 "bacon.bac"
} else if( NOT(INSTR(var__b2c__string_var, "="))  AND  NOT(TALLY(var__b2c__string_var, "->")) ){
#line 737 "bacon.bac"
if( REGEX(tmp__b2c__string_var, "[0-9]\\.[0-9]")  AND  NOT(INSTR(tmp__b2c__string_var, CHR__b2c__string_var(34))) ){
#line 738 "bacon.bac"
Register_Numeric(EXTRACT__b2c__string_var(var__b2c__string_var, "[\\+\\-\\*/% ]", TRUE), "double");
#line 739 "bacon.bac"
} else {
#line 740 "bacon.bac"
Register_Numeric(EXTRACT__b2c__string_var(var__b2c__string_var, "[\\+\\-\\*/% ]", TRUE), "default");
#line 741 "bacon.bac"
}
#line 742 "bacon.bac"
}
#line 745 "bacon.bac"
if( REGEX(var__b2c__string_var, "\\(.*\\)$") ){
#line 746 "bacon.bac"
lft__b2c__string_var = __b2c_Copy_String(lft__b2c__string_var, (char*) LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "(") - 1));
#line 747 "bacon.bac"
if( REGEX(var__b2c__string_var, "\\(\\)$") ){
#line 748 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) LEFT__b2c__string_var(tmp__b2c__string_var, INSTR(tmp__b2c__string_var, "(") - 1));
#line 749 "bacon.bac"
if( INSTR(lft__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 750 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_dup_str(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", __b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 751 "bacon.bac"
} else {
#line 752 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_dup(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", __b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 753 "bacon.bac"
}
#line 754 "bacon.bac"
} else {
#line 755 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) INBETWEEN__b2c__string_var(var__b2c__string_var, "(", ")", 2));
#line 756 "bacon.bac"
if( INSTR(lft__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 757 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_add_str(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 758 "bacon.bac"
} else {
#line 759 "bacon.bac"
__b2c__assign = (char*)"__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; __b2c__hash_add(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 760 "bacon.bac"
}
#line 762 "bacon.bac"
Relate_Recurse(lft__b2c__string_var, str__b2c__string_var, tmp__b2c__string_var, -1);
#line 763 "bacon.bac"
}
#line 766 "bacon.bac"
} else if( NOT(INSTR(var__b2c__string_var, "["))  AND  ISTOKEN(g_DYNAMICARRAYS__b2c__string_var, CONCAT__b2c__string_var( var__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) ) ){
#line 767 "bacon.bac"
if( INSTR(var__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
__b2c__assign = (char*)CONCAT__b2c__string_var( "__b2c__free_str_array_members(&" , var__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , var__b2c__string_var , "__b2c_array);" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 768 "bacon.bac"
__b2c__assign = (char*)"free("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 769 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 772 "bacon.bac"
} else if( Check_String_Type(var__b2c__string_var)  AND  REGEX(var__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 773 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(var__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 774 "bacon.bac"
if( INSTR(type__b2c__string_var, "const") ){
#line 775 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = (char*)__b2c__strdup((const char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 776 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 777 "bacon.bac"
Save_Func_Var(var__b2c__string_var, g_FUNCNAME__b2c__string_var, CHOP__b2c__string_var(EXTRACT__b2c__string_var(type__b2c__string_var, "const")));
#line 778 "bacon.bac"
} else {
#line 779 "bacon.bac"
Save_Main_Var(var__b2c__string_var, CHOP__b2c__string_var(EXTRACT__b2c__string_var(type__b2c__string_var, "const")));
#line 780 "bacon.bac"
}
#line 781 "bacon.bac"
} else {
#line 783 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) HEAD__b2c__string_var(EXTRACT__b2c__string_var(tmp__b2c__string_var, " "), 1, "("));
#line 784 "bacon.bac"
if( REGEX(str__b2c__string_var, CONCAT__b2c__string_var( "^CONCAT" , g_STRINGSIGN__b2c__string_var , "|^MID" , g_STRINGSIGN__b2c__string_var , "|^APPEND" , g_STRINGSIGN__b2c__string_var , "|^CHOP" , g_STRINGSIGN__b2c__string_var) ) ){
#line 785 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = F_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LAST__b2c__string_var(tmp__b2c__string_var, 1, "("); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 786 "bacon.bac"
} else {
#line 787 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 788 "bacon.bac"
}
#line 789 "bacon.bac"
}
#line 791 "bacon.bac"
ptr__b2c__string_var = __b2c_Copy_String(ptr__b2c__string_var, (char*) EXTRACT__b2c__string_var(var__b2c__string_var, "[[:punct:]]", TRUE));
#line 792 "bacon.bac"
if( LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__dlopen__pointer_" , ptr__b2c__string_var) )) ){
#line 793 "bacon.bac"
__b2c__assign = (char*)"__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = dlopen("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", RTLD_LAZY); if(__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL) { ERROR = 3; RUNTIMEERROR(\"IMPORT\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 794 "bacon.bac"
}
#line 796 "bacon.bac"
if( INSTR(var__b2c__string_var, ".")  AND  REGEX(var__b2c__string_var, "\\[.*\\]\\.")  AND  LEN(g_FUNCNAME__b2c__string_var)  AND  NOT(LEN(Get_Var__b2c__string_var(var__b2c__string_var))) ){
#line 797 "bacon.bac"
if( NOT(INSTR(g_LOCALSTRINGS__b2c__string_var, var__b2c__string_var))  AND  NOT(REGEX(var__b2c__string_var, "\\[.*\\]$")) ){
#line 798 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, var__b2c__string_var , " " , g_LOCALSTRINGS__b2c__string_var) ;
#line 799 "bacon.bac"
}
#line 800 "bacon.bac"
}
#line 802 "bacon.bac"
} else if( TALLY(var__b2c__string_var, "->") ){
#line 803 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 805 "bacon.bac"
} else if( NOT(REGEX(var__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ))  AND  REGEX(tmp__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 806 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) EXTRACT__b2c__string_var(Get_Var__b2c__string_var(var__b2c__string_var, g_FUNCNAME__b2c__string_var), "static"));
#line 807 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "=("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 809 "bacon.bac"
} else {
#line 810 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) EXTRACT__b2c__string_var(Get_Var__b2c__string_var(var__b2c__string_var, g_FUNCNAME__b2c__string_var), "static"));
#line 812 "bacon.bac"
if( REGEX(type__b2c__string_var, "float|double|FLOATING")  AND  NOT(INSTR(type__b2c__string_var, "*")) ){
#line 814 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "=("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) DELIM__b2c__string_var(tmp__b2c__string_var, "/", CONCAT__b2c__string_var( "/(" , type__b2c__string_var , ")") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 815 "bacon.bac"
} else if( REGEX(var__b2c__string_var, ".*\\[.*\\].*")  AND  REGEX(type__b2c__string_var, ".*\\*.*") ){
#line 816 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 818 "bacon.bac"
} else if( LEN(type__b2c__string_var)  AND  __b2c__STRCMP(LEFT__b2c__string_var(var__b2c__string_var) ,  "*") != 0 ){
#line 819 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "=("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 821 "bacon.bac"
} else {
#line 822 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 823 "bacon.bac"
}
#line 824 "bacon.bac"
}
#line 826 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(tmp__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(rel__b2c__string_var);
__b2c__STRFREE(ptr__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(item__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
