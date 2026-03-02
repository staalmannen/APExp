/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval 0
char* Parse_Equation__b2c__string_var( char *__b2c_current__b2c__string_var) {
 char*current__b2c__string_var = NULL; current__b2c__string_var = __b2c_Copy_String(NULL, __b2c_current__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_element__b2c__string_var_ptr = 0; char* __b2c__forin_element__b2c__string_var_string = NULL; char* __b2c__forin_element__b2c__string_var_string_org = NULL; char* __b2c__forin_element__b2c__string_var_step = NULL; char *__b2c__select_6696__b2c__string_var = NULL;
#line 6546 "bacon.bac"
long i = 0;
long is_string = 0;
long is_escaped = 0;
long is_equation = 0;
long opctr = 0;
long check = 0;
long is_pointer = 0;
long flag = 0;
#line 6547 "bacon.bac"
char *chunk__b2c__string_var = NULL;
char *token__b2c__string_var = NULL;
char *term__b2c__string_var = NULL;
char *eq__b2c__string_var = NULL;
char *total__b2c__string_var = NULL;
char *element__b2c__string_var = NULL;
char *last__b2c__string_var = NULL;
char *v1__b2c__string_var = NULL;
char *v2__b2c__string_var = NULL;
char *lb__b2c__string_var = NULL;
char *rb__b2c__string_var = NULL;
#line 6548 "bacon.bac"
char *logop__b2c__string_var[(uint64_t)32+1] = { NULL };
#line 6551 "bacon.bac"
is_string=(
long)( FALSE);
#line 6552 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6553 "bacon.bac"
opctr=(
long)( 1);
#line 6556 "bacon.bac"
for(i=1; i <= LEN(current__b2c__string_var); i+=1){
#line 6557 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 9) ,  CONCAT__b2c__string_var( " " , g_RANGEOP1__b2c__string_var )) == 0 ){
#line 6558 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6559 "bacon.bac"
flag=(
long)( 1);
#line 6560 "bacon.bac"
}
#line 6561 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , " ") ;
#line 6562 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 8) ,  CONCAT__b2c__string_var( " " , g_RANGEOP2__b2c__string_var )) == 0 ){
#line 6563 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6564 "bacon.bac"
flag=(
long)( 1);
#line 6565 "bacon.bac"
}
#line 6566 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , " ") ;
#line 6567 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 5) ,  " AND ") == 0 ){
#line 6568 "bacon.bac"
if( NOT(flag) ){
#line 6569 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6570 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , CHR__b2c__string_var(10)) ;
#line 6571 "bacon.bac"
logop__b2c__string_var[(uint64_t)opctr] = __b2c_Copy_String(logop__b2c__string_var[(uint64_t)opctr], (char*) " AND ");
#line 6572 "bacon.bac"
opctr = opctr + (1);
i = i + ( 4);
#line 6573 "bacon.bac"
} else {
#line 6574 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , " ") ;
#line 6575 "bacon.bac"
}
#line 6576 "bacon.bac"
} else {
#line 6577 "bacon.bac"
flag=(
long)( 0);
#line 6578 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , " ") ;
#line 6579 "bacon.bac"
}
#line 6580 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 4) ,  " OR ") == 0 ){
#line 6581 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6582 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , CHR__b2c__string_var(10)) ;
#line 6583 "bacon.bac"
logop__b2c__string_var[(uint64_t)opctr] = __b2c_Copy_String(logop__b2c__string_var[(uint64_t)opctr], (char*) " OR ");
#line 6584 "bacon.bac"
opctr = opctr + (1);
i = i + ( 3);
#line 6585 "bacon.bac"
} else {
#line 6586 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , " ") ;
#line 6587 "bacon.bac"
}
#line 6588 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 1) ,  CHR__b2c__string_var(59)) == 0  OR  __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 1) ,  CHR__b2c__string_var(44)) == 0 ){
#line 6589 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6590 "bacon.bac"
if( flag ){
#line 6591 "bacon.bac"
flag=(
long)( 0);
#line 6592 "bacon.bac"
}
#line 6593 "bacon.bac"
}
#line 6594 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , MID__b2c__string_var(current__b2c__string_var, i, 1)) ;
#line 6595 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 1) ,  CHR__b2c__string_var(92)) == 0 ){
#line 6596 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , CHR__b2c__string_var(92)) ;
#line 6597 "bacon.bac"
is_escaped=(
long)( NOT(is_escaped));
#line 6598 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 1) ,  CHR__b2c__string_var(34)) == 0 ){
#line 6599 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , CHR__b2c__string_var(34)) ;
#line 6600 "bacon.bac"
if( ISFALSE(is_escaped) ){
is_string=(
long)( NOT(is_string));
}
#line 6601 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6602 "bacon.bac"
} else {
#line 6603 "bacon.bac"
chunk__b2c__string_var = F_CONCAT__b2c__string_var(chunk__b2c__string_var, chunk__b2c__string_var , MID__b2c__string_var(current__b2c__string_var, i, 1)) ;
#line 6604 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6605 "bacon.bac"
}
#line 6606 "bacon.bac"
}
#line 6607 "bacon.bac"
logop__b2c__string_var[(uint64_t)opctr] = __b2c_Copy_String(logop__b2c__string_var[(uint64_t)opctr], (char*) "");
#line 6608 "bacon.bac"
opctr=(
long)( 1);
#line 6611 "bacon.bac"
__b2c__forin_element__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_element__b2c__string_var_string, CHOP__b2c__string_var(chunk__b2c__string_var)); __b2c__forin_element__b2c__string_var_string_org = __b2c__forin_element__b2c__string_var_string;
__b2c__forin_element__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_element__b2c__string_var_step, CHR__b2c__string_var(10));
__b2c__forin_element__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_element__b2c__string_var_string, __b2c__forin_element__b2c__string_var_step);
for(; __b2c__forin_element__b2c__string_var_ptr > 0; __b2c__forin_element__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_element__b2c__string_var_string_org, __b2c__forin_element__b2c__string_var_step, &element__b2c__string_var);
#line 6614 "bacon.bac"
eq__b2c__string_var = __b2c_Copy_String(eq__b2c__string_var, (char*) "");
lb__b2c__string_var = __b2c_Copy_String(lb__b2c__string_var, (char*) "");
rb__b2c__string_var = __b2c_Copy_String(rb__b2c__string_var, (char*) "");
#line 6615 "bacon.bac"
is_equation=(
long)( 0);
#line 6616 "bacon.bac"
is_string=(
long)( 0);
#line 6617 "bacon.bac"
is_escaped=(
long)( 0);
#line 6618 "bacon.bac"
is_pointer=(
long)( 0);
#line 6621 "bacon.bac"
check=(
long)( Check_String_Type(element__b2c__string_var));
#line 6624 "bacon.bac"
while( __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var) ,  "(") == 0 ){
#line 6625 "bacon.bac"
element__b2c__string_var = F_MID__b2c__string_var(element__b2c__string_var,element__b2c__string_var, 2);
#line 6626 "bacon.bac"
lb__b2c__string_var = F_CONCAT__b2c__string_var(lb__b2c__string_var, lb__b2c__string_var , "(") ;
#line 6627 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6628 "bacon.bac"
if( check ){
#line 6629 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(element__b2c__string_var));
#line 6630 "bacon.bac"
rb__b2c__string_var = F_MID__b2c__string_var(rb__b2c__string_var,element__b2c__string_var, LEN(token__b2c__string_var)+1);
#line 6631 "bacon.bac"
element__b2c__string_var = __b2c_Copy_String(element__b2c__string_var, (char*) LEFT__b2c__string_var(element__b2c__string_var, LEN(element__b2c__string_var)-LEN(rb__b2c__string_var)));
#line 6632 "bacon.bac"
} else {
#line 6633 "bacon.bac"
while( __b2c__STRCMP(RIGHT__b2c__string_var(element__b2c__string_var) ,  ")") == 0 ){
#line 6634 "bacon.bac"
element__b2c__string_var = __b2c_Copy_String(element__b2c__string_var, (char*) LEFT__b2c__string_var(element__b2c__string_var, LEN(element__b2c__string_var)-1));
#line 6635 "bacon.bac"
rb__b2c__string_var = F_CONCAT__b2c__string_var(rb__b2c__string_var, rb__b2c__string_var , ")") ;
#line 6636 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6637 "bacon.bac"
}
#line 6638 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 6641 "bacon.bac"
for(i=1; i <= LEN(element__b2c__string_var); i+=1){
#line 6642 "bacon.bac"
if( (LEN(MID__b2c__string_var(element__b2c__string_var, i)) )> 8  AND  __b2c__STRCMP(MID__b2c__string_var(element__b2c__string_var, i, 8) ,  g_RANGEOP1__b2c__string_var) == 0 ){
#line 6643 "bacon.bac"
term__b2c__string_var = __b2c_Copy_String(term__b2c__string_var, (char*) TOKEN__b2c__string_var(element__b2c__string_var, 2, g_RANGEOP1__b2c__string_var));
#line 6644 "bacon.bac"
v1__b2c__string_var = __b2c_Copy_String(v1__b2c__string_var, (char*) Mini_Parser__b2c__string_var(term__b2c__string_var, "AND"));
#line 6645 "bacon.bac"
term__b2c__string_var = F_MID__b2c__string_var(term__b2c__string_var,term__b2c__string_var, LEN(v1__b2c__string_var)+1);
#line 6646 "bacon.bac"
if( REGEX(term__b2c__string_var, "AND.*") ){
#line 6647 "bacon.bac"
v2__b2c__string_var = F_MID__b2c__string_var(v2__b2c__string_var,term__b2c__string_var, 4);
#line 6648 "bacon.bac"
} else {
#line 6649 "bacon.bac"
v2__b2c__string_var = F_MID__b2c__string_var(v2__b2c__string_var,term__b2c__string_var, 2);
#line 6650 "bacon.bac"
}
#line 6651 "bacon.bac"
if( check ){
#line 6652 "bacon.bac"
if( REGEX(v2__b2c__string_var, "EXCL$") ){
#line 6653 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(__b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__min_str(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , "))" , rb__b2c__string_var , " > 0 && __b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__max_str(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , "))" , rb__b2c__string_var , " < 0 ? 1 : 0)") ;
#line 6654 "bacon.bac"
} else {
#line 6655 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(__b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__min_str(" , v1__b2c__string_var , "," , v2__b2c__string_var , "))" , rb__b2c__string_var , " >= 0 && " , "__b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__max_str(" , v1__b2c__string_var , "," , v2__b2c__string_var , "))" , rb__b2c__string_var , " <= 0 ? 1 : 0)") ;
#line 6656 "bacon.bac"
}
#line 6657 "bacon.bac"
check=(
long)( 0);
#line 6658 "bacon.bac"
} else {
#line 6659 "bacon.bac"
if( REGEX(v2__b2c__string_var, "EXCL$") ){
#line 6660 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(" , lb__b2c__string_var , token__b2c__string_var , " > fmin(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , ")" , rb__b2c__string_var , " && " , lb__b2c__string_var , token__b2c__string_var , " < fmax(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , ")" , rb__b2c__string_var , " ? 1 : 0)") ;
#line 6661 "bacon.bac"
} else {
#line 6662 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(" , lb__b2c__string_var , token__b2c__string_var , " >= fmin(" , v1__b2c__string_var , "," , v2__b2c__string_var , ")" , rb__b2c__string_var , " && " , lb__b2c__string_var , token__b2c__string_var , " <= fmax(" , v1__b2c__string_var , "," , v2__b2c__string_var , ")" , rb__b2c__string_var , " ? 1 : 0)") ;
#line 6663 "bacon.bac"
}
#line 6664 "bacon.bac"
}
#line 6665 "bacon.bac"
lb__b2c__string_var = __b2c_Copy_String(lb__b2c__string_var, (char*) "");
rb__b2c__string_var = __b2c_Copy_String(rb__b2c__string_var, (char*) "");
#line 6666 "bacon.bac"
break;
#line 6667 "bacon.bac"
}
#line 6669 "bacon.bac"
if( (LEN(MID__b2c__string_var(element__b2c__string_var, i)) )> 7  AND  __b2c__STRCMP(MID__b2c__string_var(element__b2c__string_var, i, 7) ,  g_RANGEOP2__b2c__string_var) == 0 ){
#line 6670 "bacon.bac"
term__b2c__string_var = __b2c_Copy_String(term__b2c__string_var, (char*) TOKEN__b2c__string_var(element__b2c__string_var, 2, g_RANGEOP2__b2c__string_var));
#line 6671 "bacon.bac"
v1__b2c__string_var = __b2c_Copy_String(v1__b2c__string_var, (char*) Mini_Parser__b2c__string_var(term__b2c__string_var, "AND"));
#line 6672 "bacon.bac"
term__b2c__string_var = F_MID__b2c__string_var(term__b2c__string_var,term__b2c__string_var, LEN(v1__b2c__string_var)+1);
#line 6673 "bacon.bac"
if( REGEX(term__b2c__string_var, "AND.*") ){
#line 6674 "bacon.bac"
v2__b2c__string_var = F_MID__b2c__string_var(v2__b2c__string_var,term__b2c__string_var, 4);
#line 6675 "bacon.bac"
} else {
#line 6676 "bacon.bac"
v2__b2c__string_var = F_MID__b2c__string_var(v2__b2c__string_var,term__b2c__string_var, 2);
#line 6677 "bacon.bac"
}
#line 6678 "bacon.bac"
if( check ){
#line 6679 "bacon.bac"
if( REGEX(v2__b2c__string_var, "EXCL$") ){
#line 6680 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(__b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__min_str(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , "))" , rb__b2c__string_var , " > 0 && __b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__max_str(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , "))" , rb__b2c__string_var , " < 0 ? 0 : 1)") ;
#line 6681 "bacon.bac"
} else {
#line 6682 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(__b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__min_str(" , v1__b2c__string_var , "," , v2__b2c__string_var , "))" , rb__b2c__string_var , " >= 0 && __b2c__STRCMP(" , lb__b2c__string_var , token__b2c__string_var , ", __b2c__max_str(" , v1__b2c__string_var , "," , v2__b2c__string_var , "))" , rb__b2c__string_var , " <= 0 ? 0 : 1)") ;
#line 6683 "bacon.bac"
}
#line 6684 "bacon.bac"
check=(
long)( 0);
#line 6685 "bacon.bac"
} else {
#line 6686 "bacon.bac"
if( REGEX(v2__b2c__string_var, "EXCL$") ){
#line 6687 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(" , lb__b2c__string_var , token__b2c__string_var , " > fmin(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , ")" , rb__b2c__string_var , " && " , lb__b2c__string_var , token__b2c__string_var , " < fmax(" , v1__b2c__string_var , "," , LEFT__b2c__string_var(v2__b2c__string_var, LEN(v2__b2c__string_var)-4) , ")" , rb__b2c__string_var , " ? 0 : 1)") ;
#line 6688 "bacon.bac"
} else {
#line 6689 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(" , lb__b2c__string_var , token__b2c__string_var , " >= fmin(" , v1__b2c__string_var , "," , v2__b2c__string_var , ")" , rb__b2c__string_var , " && " , lb__b2c__string_var , token__b2c__string_var , " <= fmax(" , v1__b2c__string_var , "," , v2__b2c__string_var , ")" , rb__b2c__string_var , " ? 0 : 1)") ;
#line 6690 "bacon.bac"
}
#line 6691 "bacon.bac"
}
#line 6692 "bacon.bac"
lb__b2c__string_var = __b2c_Copy_String(lb__b2c__string_var, (char*) "");
rb__b2c__string_var = __b2c_Copy_String(rb__b2c__string_var, (char*) "");
#line 6693 "bacon.bac"
break;
#line 6694 "bacon.bac"
}
#line 6696 "bacon.bac"
__b2c__select_6696__b2c__string_var = __b2c_Copy_String(__b2c__select_6696__b2c__string_var, MID__b2c__string_var(element__b2c__string_var, i, 2));
#line 6697 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_6696__b2c__string_var, "==")){
#line 6698 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6699 "bacon.bac"
element__b2c__string_var = F_CONCAT__b2c__string_var(element__b2c__string_var, LEFT__b2c__string_var(element__b2c__string_var, i-1) , "= " , MID__b2c__string_var(element__b2c__string_var, i+2)) ;
#line 6700 "bacon.bac"
}
#line 6701 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_6696__b2c__string_var, "<>")){
#line 6702 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6703 "bacon.bac"
element__b2c__string_var = F_CONCAT__b2c__string_var(element__b2c__string_var, LEFT__b2c__string_var(element__b2c__string_var, i-1) , "!=" , MID__b2c__string_var(element__b2c__string_var, i+2)) ;
#line 6704 "bacon.bac"
}
#line 6705 "bacon.bac"
}
#line 6707 "bacon.bac"
__b2c__select_6707 = (double)ASC(MID__b2c__string_var(element__b2c__string_var, i, 1));
#line 6709 "bacon.bac"
 if ( (__b2c__select_6707) == (61)){
#line 6710 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6711 "bacon.bac"
if( check  OR  __b2c__STRCMP(Get_Var__b2c__string_var(token__b2c__string_var, g_FUNCNAME__b2c__string_var) ,  "char*") == 0 ){
#line 6712 "bacon.bac"
if( LEN(eq__b2c__string_var) ){
#line 6713 "bacon.bac"
eq__b2c__string_var = F_CONCAT__b2c__string_var(eq__b2c__string_var, eq__b2c__string_var , "=") ;
#line 6714 "bacon.bac"
} else {
#line 6715 "bacon.bac"
term__b2c__string_var = __b2c_Copy_String(term__b2c__string_var, (char*) token__b2c__string_var);
#line 6716 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 6717 "bacon.bac"
check=(
long)( TRUE);
#line 6718 "bacon.bac"
eq__b2c__string_var = __b2c_Copy_String(eq__b2c__string_var, (char*) "==");
#line 6719 "bacon.bac"
}
#line 6720 "bacon.bac"
} else if( NOT(is_equation) ){
#line 6721 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "==") ;
#line 6722 "bacon.bac"
} else {
#line 6723 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "=") ;
#line 6724 "bacon.bac"
is_equation=(
long)( 0);
#line 6725 "bacon.bac"
}
#line 6726 "bacon.bac"
} else {
#line 6727 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "=") ;
#line 6728 "bacon.bac"
}
#line 6730 "bacon.bac"
} else  if ( (__b2c__select_6707) == (33)){
#line 6731 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6732 "bacon.bac"
if( check  OR  __b2c__STRCMP(Get_Var__b2c__string_var(token__b2c__string_var, g_FUNCNAME__b2c__string_var) ,  "char*") == 0 ){
#line 6733 "bacon.bac"
term__b2c__string_var = __b2c_Copy_String(term__b2c__string_var, (char*) token__b2c__string_var);
#line 6734 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 6735 "bacon.bac"
check=(
long)( TRUE);
#line 6736 "bacon.bac"
eq__b2c__string_var = __b2c_Copy_String(eq__b2c__string_var, (char*) "!");
#line 6737 "bacon.bac"
} else if( NOT(is_equation) ){
#line 6738 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "!=") ;
#line 6739 "bacon.bac"
i = i + (1);
#line 6740 "bacon.bac"
} else {
#line 6741 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "!") ;
#line 6742 "bacon.bac"
is_equation=(
long)( 0);
#line 6743 "bacon.bac"
}
#line 6744 "bacon.bac"
} else {
#line 6745 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "!") ;
#line 6746 "bacon.bac"
}
#line 6748 "bacon.bac"
} else  if ( (__b2c__select_6707) == (60)){
#line 6749 "bacon.bac"
if( ISFALSE(is_string) ){
#line 6750 "bacon.bac"
if( check  OR  __b2c__STRCMP(Get_Var__b2c__string_var(token__b2c__string_var, g_FUNCNAME__b2c__string_var) ,  "char*") == 0 ){
#line 6751 "bacon.bac"
term__b2c__string_var = __b2c_Copy_String(term__b2c__string_var, (char*) token__b2c__string_var);
#line 6752 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 6753 "bacon.bac"
check=(
long)( TRUE);
#line 6754 "bacon.bac"
eq__b2c__string_var = __b2c_Copy_String(eq__b2c__string_var, (char*) "<");
#line 6755 "bacon.bac"
} else {
#line 6756 "bacon.bac"
if( is_equation ){
#line 6757 "bacon.bac"
is_equation=(
long)( 0);
#line 6758 "bacon.bac"
} else {
#line 6759 "bacon.bac"
is_equation=(
long)( 1);
#line 6760 "bacon.bac"
}
#line 6761 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "<") ;
#line 6762 "bacon.bac"
}
#line 6763 "bacon.bac"
} else {
#line 6764 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "<") ;
#line 6765 "bacon.bac"
}
#line 6766 "bacon.bac"
} else  if ( (__b2c__select_6707) == (62)){
#line 6767 "bacon.bac"
if( NOT(is_string)  AND  NOT(is_pointer) ){
#line 6768 "bacon.bac"
if( check  OR  __b2c__STRCMP(Get_Var__b2c__string_var(token__b2c__string_var, g_FUNCNAME__b2c__string_var) ,  "char*") == 0 ){
#line 6769 "bacon.bac"
term__b2c__string_var = __b2c_Copy_String(term__b2c__string_var, (char*) token__b2c__string_var);
#line 6770 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 6771 "bacon.bac"
check=(
long)( TRUE);
#line 6772 "bacon.bac"
eq__b2c__string_var = __b2c_Copy_String(eq__b2c__string_var, (char*) ">");
#line 6773 "bacon.bac"
} else {
#line 6774 "bacon.bac"
if( is_equation ){
#line 6775 "bacon.bac"
is_equation=(
long)( 0);
#line 6776 "bacon.bac"
} else {
#line 6777 "bacon.bac"
is_equation=(
long)( 1);
#line 6778 "bacon.bac"
}
#line 6779 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , ">") ;
#line 6780 "bacon.bac"
}
#line 6781 "bacon.bac"
} else {
#line 6782 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , ">") ;
#line 6783 "bacon.bac"
is_pointer=(
long)( 0);
#line 6784 "bacon.bac"
}
#line 6786 "bacon.bac"
} else  if ( (__b2c__select_6707) == (45)){
#line 6787 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(45)) ;
#line 6788 "bacon.bac"
if( NOT(is_string)  AND  NOT(is_pointer) ){
#line 6789 "bacon.bac"
is_pointer=(
long)( 1);
#line 6790 "bacon.bac"
}
#line 6792 "bacon.bac"
} else  if ( (__b2c__select_6707) == (92)){
#line 6793 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(92)) ;
#line 6794 "bacon.bac"
is_escaped=(
long)( NOT(is_escaped));
#line 6796 "bacon.bac"
} else  if ( (__b2c__select_6707) == (34)){
#line 6797 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(34)) ;
#line 6798 "bacon.bac"
if( ISFALSE(is_escaped) ){
is_string=(
long)( NOT(is_string));
}
#line 6799 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6800 "bacon.bac"
} else {
#line 6802 "bacon.bac"
if( is_equation ){
#line 6803 "bacon.bac"
is_equation=(
long)( 0);
#line 6804 "bacon.bac"
last__b2c__string_var = __b2c_Copy_String(last__b2c__string_var, (char*) RIGHT__b2c__string_var(token__b2c__string_var, 1));
#line 6805 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, "(" , LEFT__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-1) , ")" , last__b2c__string_var) ;
#line 6806 "bacon.bac"
}
#line 6807 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , MID__b2c__string_var(element__b2c__string_var, i, 1)) ;
#line 6808 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6809 "bacon.bac"
is_pointer=(
long)( FALSE);
#line 6810 "bacon.bac"
}
#line 6811 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6814 "bacon.bac"
if( check ){
#line 6815 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , lb__b2c__string_var , "__b2c__STRCMP(" , term__b2c__string_var , "," , token__b2c__string_var , ") " , eq__b2c__string_var , " 0" , rb__b2c__string_var) ;
#line 6816 "bacon.bac"
} else {
#line 6817 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , lb__b2c__string_var , token__b2c__string_var , rb__b2c__string_var) ;
#line 6818 "bacon.bac"
}
#line 6821 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , logop__b2c__string_var[opctr]) ;
#line 6822 "bacon.bac"
opctr = opctr + (1);
#line 6823 "bacon.bac"
}
#line 6825 "bacon.bac"
__b2c__assign = __b2c__return(total__b2c__string_var);
 for(__b2c__ctr=0; __b2c__ctr<(uint64_t)32; __b2c__ctr++) { __b2c__STRFREE(logop__b2c__string_var[__b2c__ctr]); } __b2c__STRFREE(__b2c__forin_element__b2c__string_var_string); __b2c__forin_element__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_element__b2c__string_var_step); __b2c__forin_element__b2c__string_var_step = NULL;
__b2c__STRFREE(current__b2c__string_var);
__b2c__STRFREE(chunk__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(term__b2c__string_var);
__b2c__STRFREE(eq__b2c__string_var);
__b2c__STRFREE(total__b2c__string_var);
__b2c__STRFREE(element__b2c__string_var);
__b2c__STRFREE(last__b2c__string_var);
__b2c__STRFREE(v1__b2c__string_var);
__b2c__STRFREE(v2__b2c__string_var);
__b2c__STRFREE(lb__b2c__string_var);
__b2c__STRFREE(rb__b2c__string_var);
__b2c__STRFREE(__b2c__select_6696__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(__b2c__assign);
#line 6827 "bacon.bac"
__b2c__catch_set = __b2c__catch_set_backup;
return (NULL);}
