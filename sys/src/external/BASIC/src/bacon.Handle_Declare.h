/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Declare( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_i__b2c__string_var_ptr = 0; char* __b2c__forin_i__b2c__string_var_string = NULL; char* __b2c__forin_i__b2c__string_var_string_org = NULL; char* __b2c__forin_i__b2c__string_var_step = NULL;
#line 1609 "bacon.bac"
char *var__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *array__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *i__b2c__string_var = NULL;
long opt = 0;
long self_declared = 0;
#line 1611 "bacon.bac"
if( (LEN(g_RECORDNAME__b2c__string_var) )> 0 ){
#line 1612 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: DECLARE/GLOBAL cannot be used within a RECORD at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1613 "bacon.bac"
exit(1);
#line 1614 "bacon.bac"
}
#line 1617 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "RECORD") ){
#line 1619 "bacon.bac"
g_RECORDNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDNAME__b2c__string_var, "RECORD_" , STR__b2c__string_var(g_COUNTER)) ;
#line 1620 "bacon.bac"
__b2c__assign = (char*)"typedef struct {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1621 "bacon.bac"
g_RECORDVAR__b2c__string_var = F_MID__b2c__string_var(g_RECORDVAR__b2c__string_var,CHOP__b2c__string_var(arg__b2c__string_var), INSTR(CHOP__b2c__string_var(arg__b2c__string_var), " ") + 1);
#line 1622 "bacon.bac"
if( ISTOKEN(g_RECORDVAR__b2c__string_var, "ARRAY") ){
#line 1623 "bacon.bac"
g_RECORDARRAY__b2c__string_var = F_MID__b2c__string_var(g_RECORDARRAY__b2c__string_var,g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "ARRAY")+5);
#line 1624 "bacon.bac"
g_RECORDVAR__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDVAR__b2c__string_var, LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "ARRAY")-1) , "[" , g_RECORDARRAY__b2c__string_var , "]") ;
#line 1625 "bacon.bac"
}
#line 1627 "bacon.bac"
if( (LEN(g_FUNCNAME__b2c__string_var) )> 0 ){
#line 1628 "bacon.bac"
g_RECORDCACHE__b2c__string_var = __b2c_Copy_String(g_RECORDCACHE__b2c__string_var, (char*) g_FUNCNAME__b2c__string_var);
#line 1629 "bacon.bac"
g_FUNCNAME__b2c__string_var = __b2c_Copy_String(g_FUNCNAME__b2c__string_var, (char*) "");
#line 1630 "bacon.bac"
}
#line 1631 "bacon.bac"
} else {
#line 1633 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "TYPE") ){
#line 1634 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 1, "TYPE"));
#line 1635 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 2, "TYPE"));
#line 1636 "bacon.bac"
if( ISTOKEN(type__b2c__string_var, "ARRAY") ){
#line 1637 "bacon.bac"
array__b2c__string_var = __b2c_Copy_String(array__b2c__string_var, (char*) TOKEN__b2c__string_var(type__b2c__string_var, 2, "ARRAY"));
#line 1638 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(type__b2c__string_var, 1, "ARRAY"));
#line 1639 "bacon.bac"
}
#line 1640 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "ASSOC") ){
#line 1641 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 1, "ASSOC"));
#line 1642 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 2, "ASSOC"));
#line 1643 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "TREE") ){
#line 1644 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 1, "TREE"));
#line 1645 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 2, "TREE"));
#line 1646 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "ARRAY") ){
#line 1647 "bacon.bac"
array__b2c__string_var = __b2c_Copy_String(array__b2c__string_var, (char*) TOKEN__b2c__string_var(arg__b2c__string_var, 2, "ARRAY"));
#line 1648 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) TOKEN__b2c__string_var(arg__b2c__string_var, 1, "ARRAY"));
#line 1649 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) IIF__b2c__string_var(INSTR(var__b2c__string_var, g_STRINGSIGN__b2c__string_var), "char*", IIF__b2c__string_var(INSTR(var__b2c__string_var, g_FLOATSIGN__b2c__string_var), "double", g_VARTYPE__b2c__string_var)));
#line 1650 "bacon.bac"
} else {
#line 1651 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,arg__b2c__string_var);
#line 1652 "bacon.bac"
self_declared=(
long)( TRUE);
#line 1653 "bacon.bac"
}
#line 1655 "bacon.bac"
while( LEN(var__b2c__string_var) ){
#line 1656 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) Mini_Parser__b2c__string_var(var__b2c__string_var));
#line 1657 "bacon.bac"
var__b2c__string_var = F_MID__b2c__string_var(var__b2c__string_var,var__b2c__string_var, LEN(str__b2c__string_var)+2);
#line 1658 "bacon.bac"
str__b2c__string_var = F_CHOP__b2c__string_var(str__b2c__string_var,str__b2c__string_var);
#line 1660 "bacon.bac"
if( self_declared ){
#line 1661 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) EXTRACT__b2c__string_var(TOKEN__b2c__string_var(str__b2c__string_var, 1, "="), " "));
#line 1662 "bacon.bac"
if( INSTR(i__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 1663 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "char*");
#line 1664 "bacon.bac"
} else if( INSTR(i__b2c__string_var, g_FLOATSIGN__b2c__string_var) ){
#line 1665 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "double");
#line 1666 "bacon.bac"
} else if( INSTR(i__b2c__string_var, g_LONGSIGN__b2c__string_var) ){
#line 1667 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "long");
#line 1668 "bacon.bac"
} else {
#line 1669 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) g_VARTYPE__b2c__string_var);
#line 1670 "bacon.bac"
}
#line 1671 "bacon.bac"
}
#line 1674 "bacon.bac"
if( NOT(INSTR(str__b2c__string_var, "."))  AND  __b2c__STRCMP(LEFT__b2c__string_var(str__b2c__string_var, 1) ,  "(") != 0 ){
#line 1676 "bacon.bac"
if( REGEX(str__b2c__string_var, g_C_KEYWORDS__b2c__string_var) ){
#line 1677 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in DECLARE/GLOBAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' is a C keyword or function!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1678 "bacon.bac"
exit(1);
#line 1679 "bacon.bac"
}
#line 1681 "bacon.bac"
if( LEN(Get_Var__b2c__string_var(str__b2c__string_var)) ){
#line 1682 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in DECLARE/GLOBAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was defined previously!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1683 "bacon.bac"
exit(1);
#line 1684 "bacon.bac"
}
#line 1685 "bacon.bac"
}
#line 1688 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "ASSOC") ){
#line 1689 "bacon.bac"
Assoc_Array(str__b2c__string_var, type__b2c__string_var, 0);
#line 1692 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "TREE") ){
#line 1693 "bacon.bac"
Binary_Tree(str__b2c__string_var, type__b2c__string_var, 0);
#line 1696 "bacon.bac"
} else if( ISTRUE(LEN(array__b2c__string_var)) ){
#line 1697 "bacon.bac"
Normal_Dyn_Array(type__b2c__string_var, str__b2c__string_var, array__b2c__string_var, FALSE, FALSE);
#line 1700 "bacon.bac"
} else if( NOT(REGEX(EXTRACT__b2c__string_var(type__b2c__string_var, "*"), "DIR|FILE|short$|int$|long$|float$|double$|char$|void|STRING|NUMBER|FLOATING")) ){
#line 1701 "bacon.bac"
if( INSTR(str__b2c__string_var, "=") ){
#line 1702 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1703 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 1704 "bacon.bac"
} else {
#line 1705 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1706 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 1707 "bacon.bac"
}
#line 1710 "bacon.bac"
} else if( ( INSTR(str__b2c__string_var, g_STRINGSIGN__b2c__string_var)  OR  REGEX(type__b2c__string_var, "STRING|char\\*$") )  AND  NOT(INSTR(str__b2c__string_var, "=")) ){
#line 1711 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(str__b2c__string_var))) ){
#line 1712 "bacon.bac"
if( INSTR(str__b2c__string_var, "[") ){
#line 1713 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1715 "bacon.bac"
Save_Main_Var(str__b2c__string_var, "char*");
#line 1716 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "(") ){
#line 1718 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1719 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTRREV(str__b2c__string_var, "(")-1));
#line 1720 "bacon.bac"
Save_Main_Var(EXTRACT__b2c__string_var(str__b2c__string_var, "[\\(\\*\\)]", TRUE), "void*");
#line 1721 "bacon.bac"
} else {
#line 1722 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1723 "bacon.bac"
Save_Main_Var(str__b2c__string_var, "char*");
#line 1724 "bacon.bac"
}
#line 1725 "bacon.bac"
}
#line 1727 "bacon.bac"
} else if( ( INSTR(str__b2c__string_var, g_STRINGSIGN__b2c__string_var)  OR  REGEX(type__b2c__string_var, "STRING|char\\*$") )  AND  INSTR(str__b2c__string_var, "=") ){
#line 1728 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(str__b2c__string_var))) ){
#line 1729 "bacon.bac"
if( REGEX(TOKEN__b2c__string_var(str__b2c__string_var, 1, "="), "\\[.*\\].*") ){
#line 1731 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]\\[") ){
#line 1732 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: multidimensional stringarrays at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' are not supported!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1733 "bacon.bac"
exit(1);
#line 1734 "bacon.bac"
}
#line 1735 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[") - 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) STR__b2c__string_var(COUNT(str__b2c__string_var, 44)+1+g_OPTION_BASE); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "] = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1737 "bacon.bac"
Save_Main_Var(str__b2c__string_var, "char*");
#line 1739 "bacon.bac"
opt=(
long)( g_OPTION_BASE);
#line 1740 "bacon.bac"
array__b2c__string_var = F_MID__b2c__string_var(array__b2c__string_var,str__b2c__string_var, INSTR(str__b2c__string_var, "{")+1);
#line 1741 "bacon.bac"
while( LEN(array__b2c__string_var) ){
#line 1742 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) Mini_Parser__b2c__string_var(array__b2c__string_var));
#line 1743 "bacon.bac"
__b2c__assign = (char*)LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( opt), g_CFILE);
__b2c__assign = (char*) "] = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( opt), g_CFILE);
__b2c__assign = (char*) "], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(i__b2c__string_var, "}", 2); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1744 "bacon.bac"
array__b2c__string_var = F_MID__b2c__string_var(array__b2c__string_var,array__b2c__string_var, LEN(i__b2c__string_var)+2);
#line 1745 "bacon.bac"
opt = opt + (1);
#line 1746 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 1747 "bacon.bac"
} else {
#line 1748 "bacon.bac"
while( LEN(str__b2c__string_var) ){
#line 1749 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) Mini_Parser__b2c__string_var(str__b2c__string_var));
#line 1750 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1751 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1752 "bacon.bac"
Save_Main_Var(LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1), "char*");
#line 1753 "bacon.bac"
str__b2c__string_var = F_MID__b2c__string_var(str__b2c__string_var,str__b2c__string_var, LEN(i__b2c__string_var)+2);
#line 1754 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 1755 "bacon.bac"
}
#line 1756 "bacon.bac"
}
#line 1759 "bacon.bac"
} else {
#line 1760 "bacon.bac"
if( INSTR(str__b2c__string_var, "[")  AND  NOT(INSTR(str__b2c__string_var, "=")) ){
#line 1761 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { 0 };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1763 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 1764 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "[")  AND  INSTR(str__b2c__string_var, "=") ){
#line 1765 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) MID__b2c__string_var(str__b2c__string_var, 1, INSTR(str__b2c__string_var, "{")); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1766 "bacon.bac"
opt=(
long)( g_OPTION_BASE);
#line 1767 "bacon.bac"
if( (opt )> 0  AND  (COUNT(str__b2c__string_var, 91) )> 1 ){
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "WARNING: OPTION BASE has no impact on multidimensional array '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) MID__b2c__string_var(str__b2c__string_var, 1, INSTR(str__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in DECLARE/GLOBAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 1768 "bacon.bac"
while( (opt )> 0  AND  COUNT(str__b2c__string_var, 91) == 1 ){
#line 1769 "bacon.bac"
__b2c__assign = (char*)" 0, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1770 "bacon.bac"
opt = opt - (1);
#line 1771 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 1772 "bacon.bac"
__b2c__assign = (char*)MID__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "{")+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1774 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 1775 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "(") ){
#line 1777 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1778 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTRREV(str__b2c__string_var, "(")-1));
#line 1779 "bacon.bac"
Save_Main_Var(EXTRACT__b2c__string_var(str__b2c__string_var, "[\\(\\*\\)]", TRUE), "void*");
#line 1780 "bacon.bac"
} else {
#line 1781 "bacon.bac"
__b2c__forin_i__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_i__b2c__string_var_string, EXTRACT__b2c__string_var(str__b2c__string_var, " ")); __b2c__forin_i__b2c__string_var_string_org = __b2c__forin_i__b2c__string_var_string;
__b2c__forin_i__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_i__b2c__string_var_step, ",");
__b2c__forin_i__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_i__b2c__string_var_string, __b2c__forin_i__b2c__string_var_step);
for(; __b2c__forin_i__b2c__string_var_ptr > 0; __b2c__forin_i__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_i__b2c__string_var_string_org, __b2c__forin_i__b2c__string_var_step, &i__b2c__string_var);
#line 1782 "bacon.bac"
if( INSTR(i__b2c__string_var, "=") ){
#line 1783 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1784 "bacon.bac"
} else if( __b2c__STRCMP(RIGHT__b2c__string_var(type__b2c__string_var) ,  "*") == 0  OR  __b2c__STRCMP(LEFT__b2c__string_var(str__b2c__string_var) ,  "*") == 0 ){
#line 1785 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1786 "bacon.bac"
} else {
#line 1787 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1788 "bacon.bac"
}
#line 1789 "bacon.bac"
Save_Main_Var(i__b2c__string_var, type__b2c__string_var);
#line 1790 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 1791 "bacon.bac"
}
#line 1792 "bacon.bac"
}
#line 1793 "bacon.bac"
}
#line 1794 "bacon.bac"
}
#line 1796 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_i__b2c__string_var_string); __b2c__forin_i__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_i__b2c__string_var_step); __b2c__forin_i__b2c__string_var_step = NULL;
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(array__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(i__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
