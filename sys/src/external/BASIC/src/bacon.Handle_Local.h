/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Local( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 1802 "bacon.bac"
char *var__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *dim__b2c__string_var = NULL;
char *dim2__b2c__string_var = NULL;
char *array__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *i__b2c__string_var = NULL;
long opt = 0;
long self_declared = 0;
#line 1805 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "TYPE") ){
#line 1806 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 1, "TYPE"));
#line 1807 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 2, "TYPE"));
#line 1808 "bacon.bac"
if( ISTOKEN(type__b2c__string_var, "ARRAY") ){
#line 1809 "bacon.bac"
array__b2c__string_var = __b2c_Copy_String(array__b2c__string_var, (char*) TOKEN__b2c__string_var(type__b2c__string_var, 2, "ARRAY"));
#line 1810 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(type__b2c__string_var, 1, "ARRAY"));
#line 1811 "bacon.bac"
}
#line 1812 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "ASSOC") ){
#line 1813 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 1, "ASSOC"));
#line 1814 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 2, "ASSOC"));
#line 1815 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "TREE") ){
#line 1816 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 1, "TREE"));
#line 1817 "bacon.bac"
type__b2c__string_var = F_CHOP__b2c__string_var(type__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 2, "TREE"));
#line 1818 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "ARRAY") ){
#line 1819 "bacon.bac"
array__b2c__string_var = __b2c_Copy_String(array__b2c__string_var, (char*) TOKEN__b2c__string_var(arg__b2c__string_var, 2, "ARRAY"));
#line 1820 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) TOKEN__b2c__string_var(arg__b2c__string_var, 1, "ARRAY"));
#line 1821 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) IIF__b2c__string_var(INSTR(var__b2c__string_var, g_STRINGSIGN__b2c__string_var), "char*", IIF__b2c__string_var(INSTR(var__b2c__string_var, g_FLOATSIGN__b2c__string_var), "double", g_VARTYPE__b2c__string_var)));
#line 1822 "bacon.bac"
} else {
#line 1823 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,arg__b2c__string_var);
#line 1824 "bacon.bac"
self_declared=(
long)( TRUE);
#line 1825 "bacon.bac"
}
#line 1827 "bacon.bac"
while( LEN(var__b2c__string_var) ){
#line 1828 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) Mini_Parser__b2c__string_var(var__b2c__string_var));
#line 1829 "bacon.bac"
var__b2c__string_var = F_MID__b2c__string_var(var__b2c__string_var,var__b2c__string_var, LEN(str__b2c__string_var)+2);
#line 1830 "bacon.bac"
str__b2c__string_var = F_CHOP__b2c__string_var(str__b2c__string_var,str__b2c__string_var);
#line 1832 "bacon.bac"
if( self_declared ){
#line 1833 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) EXTRACT__b2c__string_var(TOKEN__b2c__string_var(str__b2c__string_var, 1, "="), " "));
#line 1834 "bacon.bac"
if( INSTR(i__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 1835 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "char*");
#line 1836 "bacon.bac"
} else if( INSTR(i__b2c__string_var, g_FLOATSIGN__b2c__string_var) ){
#line 1837 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "double");
#line 1838 "bacon.bac"
} else if( INSTR(i__b2c__string_var, g_LONGSIGN__b2c__string_var) ){
#line 1839 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "long");
#line 1840 "bacon.bac"
} else {
#line 1841 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) g_VARTYPE__b2c__string_var);
#line 1842 "bacon.bac"
}
#line 1843 "bacon.bac"
}
#line 1846 "bacon.bac"
if( NOT(INSTR(str__b2c__string_var, "."))  AND  __b2c__STRCMP(LEFT__b2c__string_var(str__b2c__string_var, 1) ,  "(") != 0 ){
#line 1848 "bacon.bac"
if( REGEX(str__b2c__string_var, g_C_KEYWORDS__b2c__string_var) ){
#line 1849 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in LOCAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' is a C keyword or function!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1850 "bacon.bac"
exit(1);
#line 1851 "bacon.bac"
}
#line 1853 "bacon.bac"
if( LEN(Get_Var__b2c__string_var(str__b2c__string_var, g_FUNCNAME__b2c__string_var)) ){
#line 1854 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in LOCAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was defined previously!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1855 "bacon.bac"
exit(1);
#line 1856 "bacon.bac"
}
#line 1857 "bacon.bac"
}
#line 1860 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "ASSOC") ){
#line 1861 "bacon.bac"
Assoc_Array(str__b2c__string_var, type__b2c__string_var, IIF(LEN(g_FUNCNAME__b2c__string_var), 1, 0));
#line 1864 "bacon.bac"
} else if( ISTOKEN(arg__b2c__string_var, "TREE") ){
#line 1865 "bacon.bac"
Binary_Tree(str__b2c__string_var, type__b2c__string_var, IIF(LEN(g_FUNCNAME__b2c__string_var), 1, 0));
#line 1868 "bacon.bac"
} else if( ISTRUE(LEN(array__b2c__string_var)) ){
#line 1869 "bacon.bac"
if( INSTR(array__b2c__string_var, "STATIC") ){
#line 1870 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var) ){
#line 1871 "bacon.bac"
Normal_Dyn_Array(type__b2c__string_var, str__b2c__string_var, MID__b2c__string_var(array__b2c__string_var, 1, INSTR(array__b2c__string_var, "STATIC")-1), TRUE, TRUE);
#line 1872 "bacon.bac"
} else {
#line 1873 "bacon.bac"
Normal_Dyn_Array(type__b2c__string_var, str__b2c__string_var, MID__b2c__string_var(array__b2c__string_var, 1, INSTR(array__b2c__string_var, "STATIC")-1), TRUE, FALSE);
#line 1874 "bacon.bac"
}
#line 1875 "bacon.bac"
} else {
#line 1876 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var) ){
#line 1877 "bacon.bac"
Normal_Dyn_Array(type__b2c__string_var, str__b2c__string_var, array__b2c__string_var, FALSE, TRUE);
#line 1878 "bacon.bac"
} else {
#line 1879 "bacon.bac"
Normal_Dyn_Array(type__b2c__string_var, str__b2c__string_var, array__b2c__string_var, FALSE, FALSE);
#line 1880 "bacon.bac"
}
#line 1881 "bacon.bac"
}
#line 1884 "bacon.bac"
} else if( NOT(REGEX(EXTRACT__b2c__string_var(type__b2c__string_var, "*"), "DIR|FILE|short$|int$|long$|float$|double$|char$|void|STRING|NUMBER|FLOATING"))  AND  NOT(LEN(g_RECORDNAME__b2c__string_var)) ){
#line 1885 "bacon.bac"
if( INSTR(str__b2c__string_var, "=") ){
#line 1886 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1887 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var) ){
#line 1888 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 1889 "bacon.bac"
} else {
#line 1890 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 1891 "bacon.bac"
}
#line 1892 "bacon.bac"
} else {
#line 1893 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var) ){
#line 1894 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1895 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 1896 "bacon.bac"
} else {
#line 1897 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1898 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 1899 "bacon.bac"
}
#line 1900 "bacon.bac"
}
#line 1903 "bacon.bac"
} else if( ( REGEX(type__b2c__string_var, "STRING|char\\*$")  OR  INSTR(str__b2c__string_var, g_STRINGSIGN__b2c__string_var) )  AND  NOT(INSTR(str__b2c__string_var, "="))  AND  NOT(REGEX(type__b2c__string_var, CONCAT__b2c__string_var( ".+\\[.+" , g_STRINGSIGN__b2c__string_var , "\\]") )) ){
#line 1904 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(str__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 1906 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]\\[") ){
#line 1907 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: multidimensional stringarrays at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' are not supported!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1908 "bacon.bac"
exit(1);
#line 1909 "bacon.bac"
}
#line 1911 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 1912 "bacon.bac"
if( ISTRUE(LEN(g_RECORDNAME__b2c__string_var)) ){
#line 1913 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]") ){
#line 1914 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*)  REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1915 "bacon.bac"
dim__b2c__string_var = F_MID__b2c__string_var(dim__b2c__string_var,str__b2c__string_var, INSTR(str__b2c__string_var, "[") + 1);
#line 1916 "bacon.bac"
if( REGEX(g_RECORDVAR__b2c__string_var, "\\[.*\\]") ){
#line 1917 "bacon.bac"
if( LEN(g_RECORDARRAY__b2c__string_var) ){
#line 1918 "bacon.bac"
dim2__b2c__string_var = F_CONCAT__b2c__string_var(dim2__b2c__string_var, "__b2c_record_" , EXTRACT__b2c__string_var(g_RECORDNAME__b2c__string_var, "_TYPE")) ;
#line 1919 "bacon.bac"
} else {
#line 1920 "bacon.bac"
dim2__b2c__string_var = F_MID__b2c__string_var(dim2__b2c__string_var,g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[") + 1);
#line 1921 "bacon.bac"
}
#line 1922 "bacon.bac"
g_RECORDEND_BODY__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDEND_BODY__b2c__string_var, g_RECORDEND_BODY__b2c__string_var , " for(__b2c__counter=0; __b2c__counter<" , LEFT__b2c__string_var(dim2__b2c__string_var, INSTR(dim2__b2c__string_var, "]") - 1) , ";__b2c__counter++) {for(__b2c__ctr=0; __b2c__ctr<" , LEFT__b2c__string_var(dim__b2c__string_var, INSTR(dim__b2c__string_var, "]") - 1) , "; __b2c__ctr++)" , LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1) , "[__b2c__counter]." , LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[")-1) , "[__b2c__ctr] = NULL;}") ;
#line 1923 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " for(__b2c__counter=0; __b2c__counter<" , LEFT__b2c__string_var(dim2__b2c__string_var, INSTR(dim2__b2c__string_var, "]") - 1) , ";__b2c__counter++) {for(__b2c__ctr=0; __b2c__ctr<" , LEFT__b2c__string_var(dim__b2c__string_var, INSTR(dim__b2c__string_var, "]") - 1) , "; __b2c__ctr++) { __b2c__STRFREE(" , LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1) , "[__b2c__counter]." , LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[")-1) , "[__b2c__ctr]);} }") ;
#line 1924 "bacon.bac"
} else {
#line 1925 "bacon.bac"
g_RECORDEND_BODY__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDEND_BODY__b2c__string_var, g_RECORDEND_BODY__b2c__string_var , " for(__b2c__ctr=0; __b2c__ctr<" , LEFT__b2c__string_var(dim__b2c__string_var, INSTR(dim__b2c__string_var, "]") - 1) , "; __b2c__ctr++)" , g_RECORDVAR__b2c__string_var , "." , LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[")-1) , "[__b2c__ctr] = NULL;") ;
#line 1926 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , TOKEN__b2c__string_var(str__b2c__string_var, 1, "[") , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , g_RECORDVAR__b2c__string_var , "." , TOKEN__b2c__string_var(dim__b2c__string_var, 1, "]") , ");") ;
#line 1927 "bacon.bac"
}
#line 1928 "bacon.bac"
} else {
#line 1929 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1931 "bacon.bac"
if( INSTR(str__b2c__string_var, g_STRINGSIGN__b2c__string_var)  AND  NOT(REGEX(g_RECORDVAR__b2c__string_var, "\\[.*\\]"))  AND  NOT(LEN(g_RECORDARRAY__b2c__string_var)) ){
#line 1932 "bacon.bac"
g_RECORDEND_BODY__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDEND_BODY__b2c__string_var, g_RECORDEND_BODY__b2c__string_var , " " , g_RECORDVAR__b2c__string_var , "." , str__b2c__string_var , " = NULL;") ;
#line 1933 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , g_RECORDVAR__b2c__string_var , "." , str__b2c__string_var) ;
#line 1934 "bacon.bac"
}
#line 1935 "bacon.bac"
}
#line 1936 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 1937 "bacon.bac"
} else {
#line 1938 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]") ){
#line 1939 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1941 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 1942 "bacon.bac"
dim__b2c__string_var = F_MID__b2c__string_var(dim__b2c__string_var,str__b2c__string_var, INSTR(str__b2c__string_var, "[") + 1);
#line 1943 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " for(__b2c__ctr=0; __b2c__ctr<" , TOKEN__b2c__string_var(dim__b2c__string_var, 1, "]") , "; __b2c__ctr++) { __b2c__STRFREE(" , g_WITHVAR__b2c__string_var , TOKEN__b2c__string_var(str__b2c__string_var, 1, "[") , "[__b2c__ctr]); }") ;
#line 1944 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "(") ){
#line 1946 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1947 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTRREV(str__b2c__string_var, "(")-1));
#line 1948 "bacon.bac"
Save_Func_Var(EXTRACT__b2c__string_var(str__b2c__string_var, "[\\(\\*\\)]", TRUE), g_FUNCNAME__b2c__string_var, "void*");
#line 1949 "bacon.bac"
} else {
#line 1950 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1951 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 1953 "bacon.bac"
if( INSTR(str__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 1954 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , str__b2c__string_var) ;
#line 1955 "bacon.bac"
}
#line 1956 "bacon.bac"
}
#line 1957 "bacon.bac"
}
#line 1959 "bacon.bac"
} else {
#line 1960 "bacon.bac"
if( ISTRUE(LEN(g_RECORDNAME__b2c__string_var)) ){
#line 1961 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]") ){
#line 1962 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1963 "bacon.bac"
} else {
#line 1964 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1966 "bacon.bac"
if( INSTR(str__b2c__string_var, g_STRINGSIGN__b2c__string_var)  AND  NOT(REGEX(g_RECORDVAR__b2c__string_var, "\\[.*\\]"))  AND  NOT(LEN(g_RECORDARRAY__b2c__string_var)) ){
g_RECORDEND_BODY__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDEND_BODY__b2c__string_var, g_RECORDEND_BODY__b2c__string_var , " " , g_RECORDVAR__b2c__string_var , "." , CHOP__b2c__string_var(str__b2c__string_var) , " = NULL;");
}
#line 1967 "bacon.bac"
}
#line 1968 "bacon.bac"
Save_Main_Var(str__b2c__string_var, "char*");
#line 1969 "bacon.bac"
} else {
#line 1970 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]") ){
#line 1971 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*)  REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1973 "bacon.bac"
Save_Main_Var(str__b2c__string_var, "char*");
#line 1974 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "(") ){
#line 1976 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1977 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTRREV(str__b2c__string_var, "(")-1));
#line 1978 "bacon.bac"
Save_Main_Var(EXTRACT__b2c__string_var(str__b2c__string_var, "[\\(\\*\\)]", TRUE), "void*");
#line 1979 "bacon.bac"
} else {
#line 1980 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL; "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1981 "bacon.bac"
Save_Main_Var(str__b2c__string_var, "char*");
#line 1982 "bacon.bac"
}
#line 1983 "bacon.bac"
}
#line 1984 "bacon.bac"
}
#line 1985 "bacon.bac"
}
#line 1986 "bacon.bac"
} else if( ( INSTR(str__b2c__string_var, g_STRINGSIGN__b2c__string_var)  OR  REGEX(type__b2c__string_var, "STRING|char\\*") )  AND  INSTR(str__b2c__string_var, "=") ){
#line 1987 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 1988 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(str__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 1990 "bacon.bac"
if( REGEX(TOKEN__b2c__string_var(str__b2c__string_var, 1, "="), "\\[.*\\].*") ){
#line 1992 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]\\[") ){
#line 1993 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: multidimensional stringarrays at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' are not supported!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1994 "bacon.bac"
exit(1);
#line 1995 "bacon.bac"
}
#line 1996 "bacon.bac"
__b2c__assign = (char*)"static char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[") - 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) STR__b2c__string_var(COUNT(str__b2c__string_var, 44)+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) STR__b2c__string_var(g_OPTION_BASE); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "] = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1997 "bacon.bac"
if( LEN(g_RECORDVAR__b2c__string_var) ){
#line 1998 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: C does not allow initialization of an array within a struct at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1999 "bacon.bac"
exit(1);
#line 2000 "bacon.bac"
}
#line 2002 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 2004 "bacon.bac"
opt=(
long)( g_OPTION_BASE);
#line 2005 "bacon.bac"
array__b2c__string_var = F_MID__b2c__string_var(array__b2c__string_var,str__b2c__string_var, INSTR(str__b2c__string_var, "{")+1);
#line 2006 "bacon.bac"
while( LEN(array__b2c__string_var) ){
#line 2007 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) Mini_Parser__b2c__string_var(array__b2c__string_var));
#line 2008 "bacon.bac"
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
#line 2009 "bacon.bac"
array__b2c__string_var = F_MID__b2c__string_var(array__b2c__string_var,array__b2c__string_var, LEN(i__b2c__string_var)+2);
#line 2010 "bacon.bac"
opt = opt + (1);
#line 2011 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 2012 "bacon.bac"
} else {
#line 2013 "bacon.bac"
while( LEN(str__b2c__string_var) ){
#line 2014 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) Mini_Parser__b2c__string_var(str__b2c__string_var));
#line 2015 "bacon.bac"
__b2c__assign = (char*)"static char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2016 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2017 "bacon.bac"
Save_Func_Var(LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1), g_FUNCNAME__b2c__string_var, "char*");
#line 2018 "bacon.bac"
str__b2c__string_var = F_MID__b2c__string_var(str__b2c__string_var,str__b2c__string_var, LEN(i__b2c__string_var)+2);
#line 2019 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 2020 "bacon.bac"
}
#line 2021 "bacon.bac"
}
#line 2022 "bacon.bac"
} else {
#line 2023 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(str__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 2024 "bacon.bac"
if( REGEX(TOKEN__b2c__string_var(str__b2c__string_var, 1, "="), "\\[.*\\].*") ){
#line 2026 "bacon.bac"
if( REGEX(str__b2c__string_var, "\\[.*\\]\\[") ){
#line 2027 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: multidimensional stringarrays at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' are not supported!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2028 "bacon.bac"
exit(1);
#line 2029 "bacon.bac"
}
#line 2030 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "[") - 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) STR__b2c__string_var(COUNT(str__b2c__string_var, 44)+1+g_OPTION_BASE); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "] = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2031 "bacon.bac"
if( LEN(g_RECORDVAR__b2c__string_var) ){
#line 2032 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: C does not allow initialization of an array within a struct at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2033 "bacon.bac"
exit(1);
#line 2034 "bacon.bac"
}
#line 2036 "bacon.bac"
Save_Main_Var(str__b2c__string_var, "char*");
#line 2038 "bacon.bac"
opt=(
long)( g_OPTION_BASE);
#line 2039 "bacon.bac"
array__b2c__string_var = F_MID__b2c__string_var(array__b2c__string_var,str__b2c__string_var, INSTR(str__b2c__string_var, "{")+1);
#line 2040 "bacon.bac"
while( LEN(array__b2c__string_var) ){
#line 2041 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) Mini_Parser__b2c__string_var(array__b2c__string_var));
#line 2042 "bacon.bac"
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
#line 2043 "bacon.bac"
array__b2c__string_var = F_MID__b2c__string_var(array__b2c__string_var,array__b2c__string_var, LEN(i__b2c__string_var)+2);
#line 2044 "bacon.bac"
opt = opt + (1);
#line 2045 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 2046 "bacon.bac"
} else {
#line 2047 "bacon.bac"
while( LEN(str__b2c__string_var) ){
#line 2048 "bacon.bac"
i__b2c__string_var = __b2c_Copy_String(i__b2c__string_var, (char*) Mini_Parser__b2c__string_var(str__b2c__string_var));
#line 2049 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2050 "bacon.bac"
__b2c__assign = (char*)g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_WITHVAR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2051 "bacon.bac"
Save_Main_Var(LEFT__b2c__string_var(i__b2c__string_var, INSTR(i__b2c__string_var, "=")-1), "char*");
#line 2052 "bacon.bac"
str__b2c__string_var = F_MID__b2c__string_var(str__b2c__string_var,str__b2c__string_var, LEN(i__b2c__string_var)+2);
#line 2053 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 2054 "bacon.bac"
}
#line 2055 "bacon.bac"
}
#line 2056 "bacon.bac"
}
#line 2058 "bacon.bac"
} else {
#line 2059 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 2060 "bacon.bac"
if( INSTR(str__b2c__string_var, "[")  AND  NOT(INSTR(str__b2c__string_var, "=")) ){
#line 2061 "bacon.bac"
if( NOT(LEN(g_RECORDNAME__b2c__string_var)) ){
#line 2062 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = { 0 };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2063 "bacon.bac"
} else {
#line 2064 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2065 "bacon.bac"
}
#line 2067 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 2068 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "[")  AND  INSTR(str__b2c__string_var, "=") ){
#line 2070 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(str__b2c__string_var, 1, INSTR(str__b2c__string_var, "{")); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2071 "bacon.bac"
opt=(
long)( g_OPTION_BASE);
#line 2072 "bacon.bac"
if( (opt )> 0  AND  (COUNT(str__b2c__string_var, 91) )> 1 ){
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "WARNING: OPTION BASE has no impact on multidimensional array '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) MID__b2c__string_var(str__b2c__string_var, 1, INSTR(str__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in LOCAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 2073 "bacon.bac"
while( (opt )> 0  AND  COUNT(str__b2c__string_var, 91) == 1 ){
#line 2074 "bacon.bac"
__b2c__assign = (char*)" 0, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2075 "bacon.bac"
opt = opt - (1);
#line 2076 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 2077 "bacon.bac"
__b2c__assign = (char*)MID__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "{")+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2078 "bacon.bac"
if( LEN(g_RECORDVAR__b2c__string_var) ){
#line 2079 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: C does not allow initialization of an array within a struct at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2080 "bacon.bac"
exit(1);
#line 2081 "bacon.bac"
}
#line 2083 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 2084 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "(") ){
#line 2086 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2087 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTRREV(str__b2c__string_var, "(")-1));
#line 2088 "bacon.bac"
Save_Func_Var(EXTRACT__b2c__string_var(str__b2c__string_var, "[\\(\\*\\)]", TRUE), g_FUNCNAME__b2c__string_var, "void*");
#line 2089 "bacon.bac"
} else {
#line 2090 "bacon.bac"
if( INSTR(str__b2c__string_var, "=")  OR  LEN(g_RECORDVAR__b2c__string_var) ){
#line 2091 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2092 "bacon.bac"
} else if( __b2c__STRCMP(RIGHT__b2c__string_var(type__b2c__string_var) ,  "*") == 0  OR  __b2c__STRCMP(LEFT__b2c__string_var(str__b2c__string_var) ,  "*") == 0 ){
#line 2093 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2094 "bacon.bac"
} else {
#line 2095 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2096 "bacon.bac"
}
#line 2097 "bacon.bac"
Save_Func_Var(str__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 2098 "bacon.bac"
}
#line 2099 "bacon.bac"
} else {
#line 2100 "bacon.bac"
if( INSTR(str__b2c__string_var, "[")  AND  NOT(INSTR(str__b2c__string_var, "=")) ){
#line 2101 "bacon.bac"
if( NOT(LEN(g_RECORDNAME__b2c__string_var)) ){
#line 2102 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { 0 };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2103 "bacon.bac"
} else {
#line 2104 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(str__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2105 "bacon.bac"
}
#line 2107 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 2108 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "[")  AND  INSTR(str__b2c__string_var, "=") ){
#line 2110 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) MID__b2c__string_var(str__b2c__string_var, 1, INSTR(str__b2c__string_var, "{")); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2111 "bacon.bac"
opt=(
long)( g_OPTION_BASE);
#line 2112 "bacon.bac"
if( (opt )> 0  AND  (COUNT(str__b2c__string_var, 91) )> 1 ){
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "WARNING: OPTION BASE has no impact on multidimensional array '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) MID__b2c__string_var(str__b2c__string_var, 1, INSTR(str__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in LOCAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 2113 "bacon.bac"
while( (opt )> 0  AND  COUNT(str__b2c__string_var, 91) == 1 ){
#line 2114 "bacon.bac"
__b2c__assign = (char*)" 0, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2115 "bacon.bac"
opt = opt - (1);
#line 2116 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 2117 "bacon.bac"
__b2c__assign = (char*)MID__b2c__string_var(str__b2c__string_var, INSTR(str__b2c__string_var, "{")+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2118 "bacon.bac"
if( LEN(g_RECORDVAR__b2c__string_var) ){
#line 2119 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: C does not allow initialization of an array within a struct at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2120 "bacon.bac"
exit(1);
#line 2121 "bacon.bac"
}
#line 2123 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 2124 "bacon.bac"
} else if( INSTR(str__b2c__string_var, "(") ){
#line 2126 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2127 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) LEFT__b2c__string_var(str__b2c__string_var, INSTRREV(str__b2c__string_var, "(")-1));
#line 2128 "bacon.bac"
Save_Main_Var(EXTRACT__b2c__string_var(str__b2c__string_var, "[\\(\\*\\)]", TRUE), "void*");
#line 2129 "bacon.bac"
} else {
#line 2130 "bacon.bac"
if( INSTR(str__b2c__string_var, "=")  OR  LEN(g_RECORDVAR__b2c__string_var) ){
#line 2131 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2132 "bacon.bac"
} else if( __b2c__STRCMP(RIGHT__b2c__string_var(type__b2c__string_var) ,  "*") == 0  OR  __b2c__STRCMP(LEFT__b2c__string_var(str__b2c__string_var) ,  "*") == 0 ){
#line 2133 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2134 "bacon.bac"
} else {
#line 2135 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2136 "bacon.bac"
}
#line 2137 "bacon.bac"
Save_Main_Var(str__b2c__string_var, type__b2c__string_var);
#line 2138 "bacon.bac"
}
#line 2139 "bacon.bac"
}
#line 2140 "bacon.bac"
}
#line 2141 "bacon.bac"
}
#line 2143 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(dim__b2c__string_var);
__b2c__STRFREE(dim2__b2c__string_var);
__b2c__STRFREE(array__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(i__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
