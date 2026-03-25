/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval 0
char* Parse_Equation( char *__b2c_current) {
    char*current = NULL; current = b2c_CopyString(NULL, __b2c_current); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_element_ptr = 0; char* b2c_forin_element_string = NULL; char* b2c_forin_element_string_org = NULL; char* b2c_forin_element_step = NULL; char *b2c_select_6696 = NULL;
    long i = 0;
    long is_string = 0;
    long is_escaped = 0;
    long is_equation = 0;
    long opctr = 0;
    long check = 0;
    long is_pointer = 0;
    long flag = 0;
    char *chunk = NULL;
    char *token = NULL;
    char *term = NULL;
    char *eq = NULL;
    char *total = NULL;
    char *element = NULL;
    char *last = NULL;
    char *v1 = NULL;
    char *v2 = NULL;
    char *lb = NULL;
    char *rb = NULL;
char *logop[(uint64_t)32+1] = { NULL };
    is_string=(
    long)( FALSE);
    is_escaped=(
    long)( FALSE);
    opctr=(
    long)( 1);
    for(i=1; i <= LEN(current); i+=1){
        if( __b2c__STRCMP(MID(current, i, 9) ,  CONCAT( " " , g_RANGEOP1 )) == 0 ){
            if( ISFALSE(is_string) ){
                flag=(
                long)( 1);
            }
            chunk = F_CONCAT(chunk, chunk , " ") ;
        } else if( __b2c__STRCMP(MID(current, i, 8) ,  CONCAT( " " , g_RANGEOP2 )) == 0 ){
            if( ISFALSE(is_string) ){
                flag=(
                long)( 1);
            }
            chunk = F_CONCAT(chunk, chunk , " ") ;
        } else if( __b2c__STRCMP(MID(current, i, 5) ,  " AND ") == 0 ){
            if( NOT(flag) ){
                if( ISFALSE(is_string) ){
                    chunk = F_CONCAT(chunk, chunk , CHR(10)) ;
                    logop[(uint64_t)opctr] = b2c_CopyString(logop[(uint64_t)opctr], (char*) " AND ");
                    opctr = opctr + (1);
                    i = i + ( 4);
                } else {
                    chunk = F_CONCAT(chunk, chunk , " ") ;
                }
            } else {
                flag=(
                long)( 0);
                chunk = F_CONCAT(chunk, chunk , " ") ;
            }
        } else if( __b2c__STRCMP(MID(current, i, 4) ,  " OR ") == 0 ){
            if( ISFALSE(is_string) ){
                chunk = F_CONCAT(chunk, chunk , CHR(10)) ;
                logop[(uint64_t)opctr] = b2c_CopyString(logop[(uint64_t)opctr], (char*) " OR ");
                opctr = opctr + (1);
                i = i + ( 3);
            } else {
                chunk = F_CONCAT(chunk, chunk , " ") ;
            }
        } else if( __b2c__STRCMP(MID(current, i, 1) ,  CHR(59)) == 0  OR  __b2c__STRCMP(MID(current, i, 1) ,  CHR(44)) == 0 ){
            if( ISFALSE(is_string) ){
                if( flag ){
                    flag=(
                    long)( 0);
                }
            }
            chunk = F_CONCAT(chunk, chunk , MID(current, i, 1)) ;
        } else if( __b2c__STRCMP(MID(current, i, 1) ,  CHR(92)) == 0 ){
            chunk = F_CONCAT(chunk, chunk , CHR(92)) ;
            is_escaped=(
            long)( NOT(is_escaped));
        } else if( __b2c__STRCMP(MID(current, i, 1) ,  CHR(34)) == 0 ){
            chunk = F_CONCAT(chunk, chunk , CHR(34)) ;
            if( ISFALSE(is_escaped) ){
                is_string=(
                long)( NOT(is_string));
            }
            is_escaped=(
            long)( FALSE);
        } else {
            chunk = F_CONCAT(chunk, chunk , MID(current, i, 1)) ;
            is_escaped=(
            long)( FALSE);
        }
    }
    logop[(uint64_t)opctr] = b2c_CopyString(logop[(uint64_t)opctr], (char*) "");
    opctr=(
    long)( 1);
    b2c_forin_element_string = b2c_CopyString(b2c_forin_element_string, CHOP(chunk)); b2c_forin_element_string_org = b2c_forin_element_string;
    b2c_forin_element_step = b2c_CopyString(b2c_forin_element_step, CHR(10));
    b2c_forin_element_ptr = b2c_for_amount(b2c_forin_element_string, b2c_forin_element_step);
    for(; b2c_forin_element_ptr > 0; b2c_forin_element_ptr--) { b2c_for_item(&b2c_forin_element_string_org, b2c_forin_element_step, &element);
        eq = b2c_CopyString(eq, (char*) "");
        lb = b2c_CopyString(lb, (char*) "");
        rb = b2c_CopyString(rb, (char*) "");
        is_equation=(
        long)( 0);
        is_string=(
        long)( 0);
        is_escaped=(
        long)( 0);
        is_pointer=(
        long)( 0);
        check=(
        long)( Check_String_Type(element));
        while( __b2c__STRCMP(LEFT(element) ,  "(") == 0 ){
            element = F_MID(element,element, 2);
            lb = F_CONCAT(lb, lb , "(") ;
        }
if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
        if( check ){
            token = b2c_CopyString(token, (char*) Mini_Parser(element));
            rb = F_MID(rb,element, LEN(token)+1);
            element = b2c_CopyString(element, (char*) LEFT(element, LEN(element)-LEN(rb)));
        } else {
            while( __b2c__STRCMP(RIGHT(element) ,  ")") == 0 ){
                element = b2c_CopyString(element, (char*) LEFT(element, LEN(element)-1));
                rb = F_CONCAT(rb, rb , ")") ;
            }
    if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
        }
        token = b2c_CopyString(token, (char*) "");
        for(i=1; i <= LEN(element); i+=1){
            if( (LEN(MID(element, i)) )> 8  AND  __b2c__STRCMP(MID(element, i, 8) ,  g_RANGEOP1) == 0 ){
                term = b2c_CopyString(term, (char*) TOKEN(element, 2, g_RANGEOP1));
                v1 = b2c_CopyString(v1, (char*) Mini_Parser(term, "AND"));
                term = F_MID(term,term, LEN(v1)+1);
                if( REGEX(term, "AND.*") ){
                    v2 = F_MID(v2,term, 4);
                } else {
                    v2 = F_MID(v2,term, 2);
                }
                if( check ){
                    if( REGEX(v2, "EXCL$") ){
                        token = F_CONCAT(token, "(__b2c__STRCMP(" , lb , token , ", b2c_min_str(" , v1 , "," , LEFT(v2, LEN(v2)-4) , "))" , rb , " > 0 && __b2c__STRCMP(" , lb , token , ", b2c_max_str(" , v1 , "," , LEFT(v2, LEN(v2)-4) , "))" , rb , " < 0 ? 1 : 0)") ;
                    } else {
                        token = F_CONCAT(token, "(__b2c__STRCMP(" , lb , token , ", b2c_min_str(" , v1 , "," , v2 , "))" , rb , " >= 0 && " , "__b2c__STRCMP(" , lb , token , ", b2c_max_str(" , v1 , "," , v2 , "))" , rb , " <= 0 ? 1 : 0)") ;
                    }
                    check=(
                    long)( 0);
                } else {
                    if( REGEX(v2, "EXCL$") ){
                        token = F_CONCAT(token, "(" , lb , token , " > fmin(" , v1 , "," , LEFT(v2, LEN(v2)-4) , ")" , rb , " && " , lb , token , " < fmax(" , v1 , "," , LEFT(v2, LEN(v2)-4) , ")" , rb , " ? 1 : 0)") ;
                    } else {
                        token = F_CONCAT(token, "(" , lb , token , " >= fmin(" , v1 , "," , v2 , ")" , rb , " && " , lb , token , " <= fmax(" , v1 , "," , v2 , ")" , rb , " ? 1 : 0)") ;
                    }
                }
                lb = b2c_CopyString(lb, (char*) "");
                rb = b2c_CopyString(rb, (char*) "");
                break;
            }
            if( (LEN(MID(element, i)) )> 7  AND  __b2c__STRCMP(MID(element, i, 7) ,  g_RANGEOP2) == 0 ){
                term = b2c_CopyString(term, (char*) TOKEN(element, 2, g_RANGEOP2));
                v1 = b2c_CopyString(v1, (char*) Mini_Parser(term, "AND"));
                term = F_MID(term,term, LEN(v1)+1);
                if( REGEX(term, "AND.*") ){
                    v2 = F_MID(v2,term, 4);
                } else {
                    v2 = F_MID(v2,term, 2);
                }
                if( check ){
                    if( REGEX(v2, "EXCL$") ){
                        token = F_CONCAT(token, "(__b2c__STRCMP(" , lb , token , ", b2c_min_str(" , v1 , "," , LEFT(v2, LEN(v2)-4) , "))" , rb , " > 0 && __b2c__STRCMP(" , lb , token , ", b2c_max_str(" , v1 , "," , LEFT(v2, LEN(v2)-4) , "))" , rb , " < 0 ? 0 : 1)") ;
                    } else {
                        token = F_CONCAT(token, "(__b2c__STRCMP(" , lb , token , ", b2c_min_str(" , v1 , "," , v2 , "))" , rb , " >= 0 && __b2c__STRCMP(" , lb , token , ", b2c_max_str(" , v1 , "," , v2 , "))" , rb , " <= 0 ? 0 : 1)") ;
                    }
                    check=(
                    long)( 0);
                } else {
                    if( REGEX(v2, "EXCL$") ){
                        token = F_CONCAT(token, "(" , lb , token , " > fmin(" , v1 , "," , LEFT(v2, LEN(v2)-4) , ")" , rb , " && " , lb , token , " < fmax(" , v1 , "," , LEFT(v2, LEN(v2)-4) , ")" , rb , " ? 0 : 1)") ;
                    } else {
                        token = F_CONCAT(token, "(" , lb , token , " >= fmin(" , v1 , "," , v2 , ")" , rb , " && " , lb , token , " <= fmax(" , v1 , "," , v2 , ")" , rb , " ? 0 : 1)") ;
                    }
                }
                lb = b2c_CopyString(lb, (char*) "");
                rb = b2c_CopyString(rb, (char*) "");
                break;
            }
            b2c_select_6696 = b2c_CopyString(b2c_select_6696, MID(element, i, 2));
            if ( !b2c_strcmp(b2c_select_6696, "==")){
                if( ISFALSE(is_string) ){
                    element = F_CONCAT(element, LEFT(element, i-1) , "= " , MID(element, i+2)) ;
                }
            } else  if ( !b2c_strcmp(b2c_select_6696, "<>")){
                if( ISFALSE(is_string) ){
                    element = F_CONCAT(element, LEFT(element, i-1) , "!=" , MID(element, i+2)) ;
                }
            }
            b2c_select_6707 = (double)ASC(MID(element, i, 1));
            if ( (b2c_select_6707) == (61)){
                if( ISFALSE(is_string) ){
                    if( check  OR  __b2c__STRCMP(Get_Var(token, g_FUNCNAME) ,  "char*") == 0 ){
                        if( LEN(eq) ){
                            eq = F_CONCAT(eq, eq , "=") ;
                        } else {
                            term = b2c_CopyString(term, (char*) token);
                            token = b2c_CopyString(token, (char*) "");
                            check=(
                            long)( TRUE);
                            eq = b2c_CopyString(eq, (char*) "==");
                        }
                    } else if( NOT(is_equation) ){
                        token = F_CONCAT(token, token , "==") ;
                    } else {
                        token = F_CONCAT(token, token , "=") ;
                        is_equation=(
                        long)( 0);
                    }
                } else {
                    token = F_CONCAT(token, token , "=") ;
                }
            } else  if ( (b2c_select_6707) == (33)){
                if( ISFALSE(is_string) ){
                    if( check  OR  __b2c__STRCMP(Get_Var(token, g_FUNCNAME) ,  "char*") == 0 ){
                        term = b2c_CopyString(term, (char*) token);
                        token = b2c_CopyString(token, (char*) "");
                        check=(
                        long)( TRUE);
                        eq = b2c_CopyString(eq, (char*) "!");
                    } else if( NOT(is_equation) ){
                        token = F_CONCAT(token, token , "!=") ;
                        i = i + (1);
                    } else {
                        token = F_CONCAT(token, token , "!") ;
                        is_equation=(
                        long)( 0);
                    }
                } else {
                    token = F_CONCAT(token, token , "!") ;
                }
            } else  if ( (b2c_select_6707) == (60)){
                if( ISFALSE(is_string) ){
                    if( check  OR  __b2c__STRCMP(Get_Var(token, g_FUNCNAME) ,  "char*") == 0 ){
                        term = b2c_CopyString(term, (char*) token);
                        token = b2c_CopyString(token, (char*) "");
                        check=(
                        long)( TRUE);
                        eq = b2c_CopyString(eq, (char*) "<");
                    } else {
                        if( is_equation ){
                            is_equation=(
                            long)( 0);
                        } else {
                            is_equation=(
                            long)( 1);
                        }
                        token = F_CONCAT(token, token , "<") ;
                    }
                } else {
                    token = F_CONCAT(token, token , "<") ;
                }
            } else  if ( (b2c_select_6707) == (62)){
                if( NOT(is_string)  AND  NOT(is_pointer) ){
                    if( check  OR  __b2c__STRCMP(Get_Var(token, g_FUNCNAME) ,  "char*") == 0 ){
                        term = b2c_CopyString(term, (char*) token);
                        token = b2c_CopyString(token, (char*) "");
                        check=(
                        long)( TRUE);
                        eq = b2c_CopyString(eq, (char*) ">");
                    } else {
                        if( is_equation ){
                            is_equation=(
                            long)( 0);
                        } else {
                            is_equation=(
                            long)( 1);
                        }
                        token = F_CONCAT(token, token , ">") ;
                    }
                } else {
                    token = F_CONCAT(token, token , ">") ;
                    is_pointer=(
                    long)( 0);
                }
            } else  if ( (b2c_select_6707) == (45)){
                token = F_CONCAT(token, token , CHR(45)) ;
                if( NOT(is_string)  AND  NOT(is_pointer) ){
                    is_pointer=(
                    long)( 1);
                }
            } else  if ( (b2c_select_6707) == (92)){
                token = F_CONCAT(token, token , CHR(92)) ;
                is_escaped=(
                long)( NOT(is_escaped));
            } else  if ( (b2c_select_6707) == (34)){
                token = F_CONCAT(token, token , CHR(34)) ;
                if( ISFALSE(is_escaped) ){
                    is_string=(
                    long)( NOT(is_string));
                }
                is_escaped=(
                long)( FALSE);
            } else {
                if( is_equation ){
                    is_equation=(
                    long)( 0);
                    last = b2c_CopyString(last, (char*) RIGHT(token, 1));
                    token = F_CONCAT(token, "(" , LEFT(token, LEN(token)-1) , ")" , last) ;
                }
                token = F_CONCAT(token, token , MID(element, i, 1)) ;
                is_escaped=(
                long)( FALSE);
                is_pointer=(
                long)( FALSE);
            }
        }
if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
        if( check ){
            total = F_CONCAT(total, total , lb , "__b2c__STRCMP(" , term , "," , token , ") " , eq , " 0" , rb) ;
        } else {
            total = F_CONCAT(total, total , lb , token , rb) ;
        }
        total = F_CONCAT(total, total , logop[opctr]) ;
        opctr = opctr + (1);
    }
    b2c_assign = b2c_return(total);
for(b2c_ctr=0; b2c_ctr<(uint64_t)32; b2c_ctr++) { __b2c__STRFREE(logop[b2c_ctr]); } __b2c__STRFREE(b2c_forin_element_string); b2c_forin_element_string = NULL; __b2c__STRFREE(b2c_forin_element_step); b2c_forin_element_step = NULL;
    __b2c__STRFREE(current);
    __b2c__STRFREE(chunk);
    __b2c__STRFREE(token);
    __b2c__STRFREE(term);
    __b2c__STRFREE(eq);
    __b2c__STRFREE(total);
    __b2c__STRFREE(element);
    __b2c__STRFREE(last);
    __b2c__STRFREE(v1);
    __b2c__STRFREE(v2);
    __b2c__STRFREE(lb);
    __b2c__STRFREE(rb);
    __b2c__STRFREE(b2c_select_6696);
    b2c_catch_set = b2c_catch_set_backup;
    return(b2c_assign);
    b2c_catch_set = b2c_catch_set_backup;
return (NULL);}
