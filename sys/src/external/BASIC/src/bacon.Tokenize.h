/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Tokenize( char *__b2c_current) {
    char*current = NULL; current = b2c_CopyString(NULL, __b2c_current); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; int b2c_forin_str_ptr = 0; char* b2c_forin_str_string = NULL; char* b2c_forin_str_string_org = NULL; char* b2c_forin_str_step = NULL;
    long i = 0;
    long is_string = 0;
    long is_escaped = 0;
    long in_func = 0;
    long in_char = 0;
    long j = 0;
    long in_str = 0;
    long in_spac = 0;
    long bracket = 0;
    long direct = 0;
    long inescaped = 0;
    long isquote = 0;
    long sftot = 0;
    char *token = NULL;
    char *item1 = NULL;
    char *item2 = NULL;
    char *part = NULL;
    char *result = NULL;
    char *txt = NULL;
    char *sep = NULL;
    char *str = NULL;
    if( __b2c__STRCMP(LEFT(current, 5) ,  "CLASS") == 0  OR  g_COMMENT == TRUE ){
        Parse_Line(CHOP(current));

        __b2c__STRFREE(current);
        __b2c__STRFREE(token);
        __b2c__STRFREE(item1);
        __b2c__STRFREE(item2);
        __b2c__STRFREE(part);
        __b2c__STRFREE(result);
        __b2c__STRFREE(txt);
        __b2c__STRFREE(sep);
        __b2c__STRFREE(str);
        b2c_catch_set = b2c_catch_set_backup;
        return b2c_exitval;
    }
    if( g_TRACE == 1 ){
        if( NOT(REGEX(CHOP(current), "^FUNCTION|^SUB|^ELIF|^ELSE"))  AND  NOT(LEN(g_TRACE_PREFIX)) ){
        fputs("if(b2c_getch() == 27) {fprintf(stderr, \"TRACE OFF - exiting trace mode.\\n\"); exit(EXIT_SUCCESS);}\n", g_CFILE);
            txt = b2c_CopyString(txt, (char*) REPLACE(current, CONCAT( CHR(34) , CHR(92) , CHR(37)) , CONCAT( CHR(39) , CHR(47) , CHR(35)) , 2));
        fprintf(g_CFILE, "fprintf(stderr, \"File '%s' line %d: %s\\n\", %s);\n", g_CURFILE, txt, STR( g_COUNTER));
            if( LEN(g_MONITOR) ){
            fprintf(g_CFILE, "%s;\n", CHOP(g_MONITOR, "&&"));
            }
        }
        g_TRACE_PREFIX = b2c_CopyString(g_TRACE_PREFIX, (char*) "");
    }
    current = b2c_CopyString(current, (char*) Pre_Tokenize_Functions(current));
    while( TRUE ){
        in_func=(
        long)( 0);
        is_string=(
        long)( FALSE);
        is_escaped=(
        long)( FALSE);
        token = b2c_CopyString(token, (char*) "");
        for(i=1; i <= LEN(current); i+=1){
            in_char=(
            long)( ASC(MID(current, i, 1)));
            b2c_select_6288 = (double)in_char;
            if ( (b2c_select_6288) == (58)){
                if( NOT(is_string)  AND  ASC(MID(current, i+1, 1)) == 58 ){
                    i = i + (1);
                    token = F_CONCAT(token, token , "::") ;
                } else if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H)  AND  NOT(in_func) ){
                    Tokenize(CHOP(token));
                    token = b2c_CopyString(token, (char*) "");
                } else {
                    token = F_CONCAT(token, token , ":") ;
                }
            } else  if ( (b2c_select_6288) == (9)){
                token = F_CONCAT(token, token , IIF(NOT(is_string), CHR(32), CHR(9))) ;
            } else  if ( (b2c_select_6288) == (36)){
                if( NOT(is_string)  OR  MATCH(current, "IMPORT * FROM * TYPE *") ){
                    token = F_CONCAT(token, token , g_STRINGSIGN) ;
                    is_escaped=(
                    long)( FALSE);
                } else {
                    token = F_CONCAT(token, token , "$") ;
                }
            } else  if ( (b2c_select_6288) == (40)){
                if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
                    in_func = in_func + (1);
                }
                token = F_CONCAT(token, token , CHR(40)) ;
            } else  if ( (b2c_select_6288) == (41)){
                if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
                    in_func = in_func - (1);
                }
                token = F_CONCAT(token, token , CHR(41)) ;
            } else  if ( (b2c_select_6288) == (63)){
                if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H)  AND  NOT(in_func) ){
                    token = F_CONCAT(token, token , "PRINT ");
                }
                else {
                    token = F_CONCAT(token, token , CHR(63));
                }
            } else  if ( (b2c_select_6288) == (91)){
                if( NOT(is_string)  AND  __b2c__STRCMP(MID(current, i, 2) ,  "[]") != 0  AND  __b2c__STRCMP(MID(current, i, 11) ,  "[(uint64_t)") != 0 ){
                    token = F_CONCAT(token, token , "[(uint64_t)");
                }
                else {
                    token = F_CONCAT(token, token , CHR(91));
                }
            } else  if ( (b2c_select_6288) == (37)){
                if( NOT(is_string)  AND  REGEX(RIGHT(token, 1), "[a-zA-Z0-9_]+") ){
                    token = F_CONCAT(token, token , g_LONGSIGN) ;
                    is_escaped=(
                    long)( FALSE);
                } else {
                    token = F_CONCAT(token, token , "%") ;
                }
            } else  if ( (b2c_select_6288) == (35)){
                if( NOT(is_string)  AND  REGEX(RIGHT(token, 1), "[a-zA-Z0-9_]+")  AND  (i )> 1 ){
                    token = F_CONCAT(token, token , g_FLOATSIGN) ;
                    is_escaped=(
                    long)( FALSE);
                } else {
                    token = F_CONCAT(token, token , "#") ;
                }
            } else  if ( (b2c_select_6288) == (92)){
                token = F_CONCAT(token, token , CHR(92)) ;
                is_escaped=(
                long)( NOT(is_escaped));
            } else  if ( (b2c_select_6288) == (34)){
                token = F_CONCAT(token, token , CHR(34)) ;
                if( NOT(is_escaped) ){
                    if( NOT(is_string) ){
                        is_string=(
                        long)( TRUE);
                    } else {
                        is_string=(
                        long)( FALSE);
                    }
                }
                is_escaped=(
                long)( FALSE);
            } else  if ( (b2c_select_6288) == (38) || (b2c_select_6288) == ( 43)){
                if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
                    item1 = b2c_CopyString(item1, (char*) "");
                    bracket=(
                    long)( 0);
                    in_spac=(
                    long)( 0);
                    in_str=(
                    long)( 0);
                    direct=(
                    long)( 0);
                    isquote=(
                    long)( 0);
                    for(j=1; j <= LEN(token); j+=1){
                        b2c_select_6364 = (double)ASC(MID(token, LEN(token)-j+1, 1));
                        if ( (b2c_select_6364) == (41) || (b2c_select_6364) == ( 93)){
                            isquote=(
                            long)( 0);
                            direct = direct + (1);
                            if( NOT(in_str) ){
                                bracket = bracket + (1);
                            }
                        } else  if ( (b2c_select_6364) == (40) || (b2c_select_6364) == ( 91)){
                            isquote=(
                            long)( 0);
                            direct = direct + (1);
                            if( NOT(in_str) ){
                                bracket = bracket - (1);
                                if( (bracket )< 0 ){
                                    break;
                                }
                            }
                        } else  if ( (b2c_select_6364) == (61)){
                            isquote=(
                            long)( 0);
                            if( NOT(in_str) ){
                                break;
                            }
                        } else  if ( (b2c_select_6364) == (62)){
                            if( ASC(MID(token, LEN(token)-j, 1)) != 45 ){
                                isquote=(
                                long)( 0);
                                if( NOT(in_str) ){
                                    break;
                                }
                            }
                        } else  if ( (b2c_select_6364) == (44) || (b2c_select_6364) == ( 45) || (b2c_select_6364) == ( 42) || (b2c_select_6364) == ( 47) || (b2c_select_6364) == ( 37) || (b2c_select_6364) == ( 60)){
                            isquote=(
                            long)( 0);
                            if( NOT(in_str)  AND  NOT(bracket) ){
                                break;
                            }
                        } else  if ( (b2c_select_6364) == (92)){
                            if( isquote ){
                                in_str=(
                                long)( 1);
                            }
                            isquote=(
                            long)( 0);
                        } else  if ( (b2c_select_6364) == (34)){
                            isquote=(
                            long)( 1);
                            direct = direct + (1);
                            in_str=(
                            long)( NOT(in_str));
                        } else  if ( (b2c_select_6364) == (32)){
                            isquote=(
                            long)( 0);
                            if( NOT(in_str)  AND  NOT(bracket) ){
                                if( (direct )> 0 ){
                                    in_spac = in_spac + (1);
                                }
                            }
                        } else  if ( (b2c_select_6364) == (58)){
                            if( NOT(bracket) ){
                                isquote=(
                                long)( 0);
                                if( NOT(in_str) ){
                                    break;
                                }
                            }
                        }
                        if( (__b2c__STRCMP(MID(token, LEN(token)-j+1, 1) , b2c_min_str( "a" , "z")) >= 0 && __b2c__STRCMP(MID(token, LEN(token)-j+1, 1) , b2c_max_str( "a" , "z")) <= 0 ? 1 : 0)  OR  (__b2c__STRCMP(MID(token, LEN(token)-j+1, 1) , b2c_min_str( "A" , "Z")) >= 0 && __b2c__STRCMP(MID(token, LEN(token)-j+1, 1) , b2c_max_str( "A" , "Z")) <= 0 ? 1 : 0) ){
                            isquote=(
                            long)( 0);
                            direct = direct + (1);
                            if( NOT(in_str)  AND  NOT(bracket) ){
                                if( (in_spac )> 0 ){
                                    break;
                                }
                            }
                        }
                        item1 = F_CONCAT(item1, MID(token, LEN(token)-j+1, 1) , item1) ;
                    }
            if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    if( Check_String_Type(item1) ){
                        part = F_MID(part,token, 1, LEN(token)-j+1);
                        item2 = b2c_CopyString(item2, (char*) "");
                        bracket=(
                        long)( 0);
                        in_str=(
                        long)( 0);
                        inescaped=(
                        long)( 0);
                        in_spac=(
                        long)( 0);
                        direct=(
                        long)( 0);
                        for(j=i+1; j <= LEN(current); j+=1){
                            b2c_select_6438 = (double)ASC(MID(current, j, 1));
                            if ( (b2c_select_6438) == (40)){
                                direct = direct + (1);
                                if( NOT(in_str) ){
                                    bracket = bracket + (1);
                                }
                            } else  if ( (b2c_select_6438) == (41)){
                                direct = direct + (1);
                                if( NOT(in_str) ){
                                    bracket = bracket - (1);
                                    if( (bracket )< 0 ){
                                        break;
                                    }
                                }
                            } else  if ( (b2c_select_6438) == (44) || (b2c_select_6438) == ( 60) || (b2c_select_6438) == ( 61) || (b2c_select_6438) == ( 33) || (b2c_select_6438) == ( 45) || (b2c_select_6438) == ( 42) || (b2c_select_6438) == ( 47) || (b2c_select_6438) == ( 37)){
                                if( NOT(in_str)  AND  NOT(bracket) ){
                                    break;
                                }
                            } else  if ( (b2c_select_6438) == (38) || (b2c_select_6438) == ( 43)){
                                if( NOT(in_str)  AND  NOT(bracket) ){
                                    in_spac=(
                                    long)( 0);
                                    direct=(
                                    long)( 0);
                                }
                            } else  if ( (b2c_select_6438) == (92)){
                                inescaped=(
                                long)( NOT(inescaped));
                            } else  if ( (b2c_select_6438) == (34)){
                                direct = direct + (1);
                                if( NOT(inescaped) ){
                                    in_str=(
                                    long)( NOT(in_str));
                                }
                                inescaped=(
                                long)( 0);
                            } else  if ( (b2c_select_6438) == (32)){
                                if( NOT(in_str)  AND  NOT(bracket) ){
                                    if( (direct )> 0 ){
                                        in_spac = in_spac + (1);
                                    }
                                }
                            } else  if ( (b2c_select_6438) == (58) || (b2c_select_6438) == ( 59)){
                                if( NOT(in_str)  AND  NOT(bracket) ){
                                    break;
                                }
                            }
                            if( (__b2c__STRCMP(MID(current, j, 1) , b2c_min_str( "a" , "z")) >= 0 && __b2c__STRCMP(MID(current, j, 1) , b2c_max_str( "a" , "z")) <= 0 ? 1 : 0)  OR  (__b2c__STRCMP(MID(current, j, 1) , b2c_min_str( "A" , "Z")) >= 0 && __b2c__STRCMP(MID(current, j, 1) , b2c_max_str( "A" , "Z")) <= 0 ? 1 : 0) ){
                                direct = direct + (1);
                                if( NOT(in_str)  AND  NOT(bracket) ){
                                    if( (in_spac )> 0 ){
                                        break;
                                    }
                                }
                            }
                            if( __b2c__STRCMP(MID(current, j, 1) ,  "$") == 0 ){
                                if( NOT(in_str)  OR  MATCH(current, "IMPORT * FROM * TYPE *") ){
                                    item2 = F_CONCAT(item2, item2 , g_STRINGSIGN) ;
                                } else {
                                    item2 = F_CONCAT(item2, item2 , "$") ;
                                }
                            } else if( __b2c__STRCMP(MID(current, j, 1) ,  "&") == 0  OR  __b2c__STRCMP(MID(current, j, 1) ,  "+") == 0 ){
                                if( NOT(in_str)  AND  NOT(bracket) ){
                                    item2 = F_CONCAT(item2, item2 , ",") ;
                                } else {
                                    item2 = F_CONCAT(item2, item2 , MID(current, j, 1)) ;
                                }
                            } else {
                                item2 = F_CONCAT(item2, item2 , MID(current, j, 1)) ;
                            }
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        if( Check_String_Type(CHOP(Mini_Parser(item2))) ){
                            token = F_CONCAT(token, part , " CONCAT" , g_STRINGSIGN , "(" , item1 , "," , item2 , ") ") ;
                            i=(
                            long)( j-1);
                        } else {
                            token = F_CONCAT(token, token , CHR(in_char)) ;
                        }
                    } else {
                        token = F_CONCAT(token, token , CHR(in_char)) ;
                    }
                } else {
                    token = F_CONCAT(token, token , CHR(in_char)) ;
                }
                is_escaped=(
                long)( FALSE);
            } else {
                token = F_CONCAT(token, token , MID(current, i, 1)) ;
                is_escaped=(
                long)( FALSE);
            }
        }
if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
        if( __b2c__STRCMP(token ,  result) == 0 ){
            break;
        }
        result = b2c_CopyString(result, (char*) token);
        if( NOT(REGEX(token, "[&+%#\\$]")) ){
            break;
        }
        current = b2c_CopyString(current, (char*) token);
    }
#undef b2c_obtain_type_g_MACRO_STRINGS
#define b2c_obtain_type_g_MACRO_STRINGS 0
    b2c_forin_str_string = b2c_CopyString(b2c_forin_str_string, OBTAIN(g_MACRO_STRINGS)); b2c_forin_str_string_org = b2c_forin_str_string;
    b2c_forin_str_step = b2c_CopyString(b2c_forin_str_step, b2c_option_delim);
    b2c_forin_str_ptr = b2c_for_amount(b2c_forin_str_string, b2c_forin_str_step);
    for(; b2c_forin_str_ptr > 0; b2c_forin_str_ptr--) { b2c_for_item(&b2c_forin_str_string_org, b2c_forin_str_step, &str);
        result = b2c_CopyString(result, (char*) REPLACE(result, str, g_MACRO_STRINGS(str)));
    }
    sftot=(
    long)( TALLY(result, CONCAT( g_STRINGSIGN , "(") ));
    if( (sftot )> g_STRING_FUNC ){
        g_STRING_FUNC=(long)( sftot);
    }
    Parse_Line(CHOP(token));
    __b2c__STRFREE(b2c_forin_str_string); b2c_forin_str_string = NULL; __b2c__STRFREE(b2c_forin_str_step); b2c_forin_str_step = NULL;
    __b2c__STRFREE(current);
    __b2c__STRFREE(token);
    __b2c__STRFREE(item1);
    __b2c__STRFREE(item2);
    __b2c__STRFREE(part);
    __b2c__STRFREE(result);
    __b2c__STRFREE(txt);
    __b2c__STRFREE(sep);
    __b2c__STRFREE(str);
    b2c_catch_set = b2c_catch_set_backup;
}
