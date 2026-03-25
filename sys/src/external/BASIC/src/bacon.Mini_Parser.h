/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval 0
char* __Mini_Parser(int b2c_arg_tot, ...) {
long amount; long b2c_var_exp = 1; va_list b2c_ap; char **exp = NULL; exp = (char **)calloc(b2c_arg_tot+1, sizeof(char*)); amount = b2c_arg_tot; va_start(b2c_ap, b2c_arg_tot); while (b2c_arg_tot) { exp[b2c_var_exp] = b2c_CopyString(exp[b2c_var_exp], va_arg(b2c_ap, char*)); b2c_var_exp++; b2c_arg_tot--; } va_end(b2c_ap); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    unsigned long in_string = 0;
    unsigned long escaped = 0;
    unsigned long x = 0;
    long in_func = 0;
    for(x=1; x <= LEN(exp[(uint64_t)1]); x+=1){
        if( amount == 2 ){
            if( __b2c__STRCMP(MID(exp[(uint64_t)1], x, LEN(exp[(uint64_t)2])) ,  exp[(uint64_t)2]) == 0 ){
                if( ISFALSE(in_string)  AND  ISFALSE(in_func) ){
                    break;
                }
            }
        }
        b2c_select_293 = (double)ASC(MID(exp[(uint64_t)1], x, 1));
        if ( (b2c_select_293) == (44) || (b2c_select_293) == (59)){
            if( ISFALSE(in_string)  AND  ISFALSE(in_func) ){
                break;
            }
        } else  if ( (b2c_select_293) == (92)){
            if( escaped ){
                escaped=(
                unsigned long)( FALSE);
            } else {
                escaped=(
                unsigned long)( TRUE);
            }
        } else  if ( (b2c_select_293) == (34)){
            if( ISFALSE(escaped) ){
                in_string=(
                unsigned long)( NOT(in_string));
            }
            escaped=(
            unsigned long)( FALSE);
        } else  if ( (b2c_select_293) == (40) || (b2c_select_293) == ( 123)){
            if( ISFALSE(in_string) ){
                in_func = in_func + (1);
            }
            escaped=(
            unsigned long)( FALSE);
        } else  if ( (b2c_select_293) == (41) || (b2c_select_293) == ( 125)){
            if( ISFALSE(in_string) ){
                in_func = in_func - (1);
            }
            escaped=(
            unsigned long)( FALSE);
        } else {
            escaped=(
            unsigned long)( FALSE);
        }
        if( (in_func )< 0 ){
            break;
        }
    }
    b2c_assign = b2c_return(LEFT(exp[(uint64_t)1], x-1));
    b2c_free_str_array_members(&exp, 1, amount); free(exp);
    b2c_catch_set = b2c_catch_set_backup;
    return(b2c_assign);
    b2c_catch_set = b2c_catch_set_backup;
return (NULL);}
