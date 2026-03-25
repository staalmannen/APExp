/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Handle_SubFunc( char *arg_in) {
    char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char **match = NULL; long match__b2c_array = 0; char **element = NULL; long element__b2c_array = 0;
    long x = 0;
    long dim = 0;
    long total = 0;
    char *dim = NULL;
    char *arr = NULL;
    char *size = NULL;
    char *var = NULL;
    char *no_arg = NULL;
    char *type = NULL;
    if( AMOUNT(arg) == 1 ){
    fprintf(stderr, "%sSyntax error: empty SUB/FUNCTION at at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    arg = b2c_CopyString(arg, (char*) LAST(arg));
    if( (LEN(g_FUNCNAME) )> 0 ){
    fprintf(stderr, "%sSyntax error: cannot define a SUB/FUNCTION within a SUB/FUNCTION at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( MATCH(COLLAPSE(arg), "* ( * ) *") ){
        no_arg = b2c_CopyString(no_arg, (char*) OUTBETWEEN(arg, "(", ")", 1));
    } else {
        no_arg = b2c_CopyString(no_arg, (char*) arg);
    }
    if( ISTOKEN(no_arg, "TYPE") ){
        b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(no_arg), "* TYPE *", b2c_option_delim);
        total = match__b2c_array;
        g_FUNCTYPE = F_CHOP(g_FUNCTYPE,match[(uint64_t)2]);
        arg = b2c_CopyString(arg, (char*) FIRST(arg, 1, "TYPE"));
    }
    if( INSTR(arg, "(") ){
        g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, CHOP(TOKEN(arg, 1, "(")) , "(") ;
        g_PROTOTYPE = b2c_CopyString(g_PROTOTYPE, (char*) g_ORIGFUNCNAME);
        g_FUNCNAME = F_CHOP(g_FUNCNAME,TOKEN(arg, 1, "("));
    } else {
        g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, CHOP(arg) , "(") ;
        g_PROTOTYPE = b2c_CopyString(g_PROTOTYPE, (char*) g_ORIGFUNCNAME);
        g_FUNCNAME = F_CHOP(g_FUNCNAME,arg);
    }
    if( INSTR(g_FUNCNAME, "::") ){
        g_FUNCNAME = b2c_CopyString(g_FUNCNAME, (char*) REPLACE(g_FUNCNAME, "::", "__"));
    }
    if( ISTOKEN(g_IMPORTED, g_FUNCNAME) ){
    fprintf(stderr, "%sSyntax error: duplicate SUB or FUNCTION name at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
        exit(1);
    }
    if( INSTR(arg, "(") ){
        b2c_split_by(&element, 1, &element__b2c_array, CHOP(MID(arg, INSTR(arg, "(")), "() "), ",");
        dim = element__b2c_array;
    }
    if( dim == 0 ){
        g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , " void)") ;
        g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , " void)") ;
    }
    for(x=1; x <= dim; x+=1){
        element[(uint64_t)x] = F_CHOP(element[(uint64_t)x],element[(uint64_t)x]);
        if( __b2c__STRCMP(TOKEN(element[(uint64_t)x], 1) ,  "VAR") == 0 ){
            if( (dim )> 1 ){
            fprintf(stderr, "%sSyntax error: variable argument list cannot be followed by other arguments at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            } else if( INSTR(g_PROTOTYPE, ",") ){
            fprintf(stderr, "%sSyntax error: variable argument list cannot be preceded by other arguments at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            }
            if( NOT(ISTOKEN(element[(uint64_t)x], "SIZE")) ){
            fprintf(stderr, "%sSyntax error: variable argument list lacks SIZE argument at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            }
            b2c_parse(&match, 1, &match__b2c_array, COLLAPSE(element[(uint64_t)x]), CONCAT( "VAR * " , IIF(ISTOKEN(element[x], "TYPE"), "TYPE * ") , "SIZE *" ), b2c_option_delim);
            total = match__b2c_array;
            arr = b2c_CopyString(arr, (char*) match[(uint64_t)1]);
            if( total == 2 ){
                type = b2c_CopyString(type, (char*) "long");
                size = b2c_CopyString(size, (char*) match[(uint64_t)2]);
            } else {
                type = b2c_CopyString(type, (char*) match[(uint64_t)2]);
                size = b2c_CopyString(size, (char*) match[(uint64_t)3]);
            }
            g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " long " , size , ";") ;
            Save_Func_Var(size, g_FUNCNAME, "long");
            if( Check_String_Type(arr)  OR  REGEX(type, "STRING|char\\*$") ){
                Save_Func_Var(arr, g_FUNCNAME, "char*");
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "long b2c_var_" , arr , " = " , STR(g_OPTION_BASE) , "; va_list b2c_ap; char **" , arr , " = NULL;" , arr , " = (char **)calloc(b2c_arg_tot+" , STR(g_OPTION_BASE) , ", sizeof(char*));") ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , size , " = b2c_arg_tot; va_start(b2c_ap, b2c_arg_tot); while(b2c_arg_tot)") ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "{" , arr , "[b2c_var_" , arr , "] = b2c_CopyString(" , arr , "[b2c_var_" , arr , "], va_arg(b2c_ap, char*)); b2c_var_" , arr , "++; b2c_arg_tot--; } va_end(b2c_ap);") ;
                g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, "__" , g_PROTOTYPE , "int, ...") ;
                g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , "int b2c_arg_tot, ...") ;
                g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " b2c_free_str_array_members(&" , arr , ", " , STR(g_OPTION_BASE) , ", " , size , "); free(" , arr , ");") ;
            fprintf(g_HFILE, "#define %s(...) __%s(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), (char*)__VA_ARGS__)\n", g_FUNCNAME, g_FUNCNAME);
            } else {
                if( INSTR(arr, g_FLOATSIGN)  OR  __b2c__STRCMP(type ,  "float") == 0 ){
                    type = b2c_CopyString(type, (char*) "double");
                }
                Save_Func_Var(arr, g_FUNCNAME, CONCAT( type , "*") );
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "long b2c_var_" , arr , " = " , STR(g_OPTION_BASE) , "; va_list b2c_ap; " , type , "*" , arr , " = NULL;" , arr , " = (" , type , "*)calloc(b2c_arg_tot+" , STR(g_OPTION_BASE) , ", sizeof(" , type , "));") ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , size , " = b2c_arg_tot; va_start(b2c_ap, b2c_arg_tot); while(b2c_arg_tot)") ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "{" , arr , "[b2c_var_" , arr , "] = va_arg(b2c_ap, " , type , "); b2c_var_" , arr , "++; b2c_arg_tot--; } va_end(b2c_ap);") ;
                g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, "__" , g_PROTOTYPE , "int, ...") ;
                g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , "int b2c_arg_tot, ...") ;
                g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , " free(" , arr , ");") ;
            fprintf(g_HFILE, "#define %s(...) __%s%s\n", g_FUNCNAME, g_FUNCNAME, CONCAT( "(sizeof((const " , type , "[]) {__VA_ARGS__}) / sizeof(" , type , "), (" , type , ")__VA_ARGS__)" ));
            }
            g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, "__" , g_ORIGFUNCNAME) ;
        } else if( INSTR(element[(uint64_t)x], "STRING ")  OR  INSTR(element[(uint64_t)x], "char* ")  OR  INSTR(element[(uint64_t)x], g_STRINGSIGN) ){
            if( NOT(HASDELIM(element[(uint64_t)x])) ){
                element[(uint64_t)x] = F_CONCAT(element[(uint64_t)x], "char* " , element[(uint64_t)x]);
            }
            if( REGEX(TAIL(element[(uint64_t)x]), g_C_KEYWORDS) ){
            fprintf(stderr, "%sSyntax error: variable '%s' in SUB/FUNCTION statement at line %s in file '%s' is a C keyword or function!\n", NL, TAIL(element[(uint64_t)x]), STR( g_COUNTER), g_CURFILE);
                exit(1);
            } else if( NOT(LEN(Get_Var(TAIL(element[(uint64_t)x]), g_FUNCNAME))) ){
                Save_Func_Var(TAIL(element[(uint64_t)x]), g_FUNCNAME, FIRST(element[(uint64_t)x]));
            } else {
                if( g_SEMANTIC == 0 ){
                fprintf(stderr, "%sWARNING: variable '%s' in function header at line %s in file '%s' was defined previously!\n", NL, TAIL(element[(uint64_t)x]), STR( g_COUNTER), g_CURFILE);
                }
            }
            arr = F_MID(arr,element[(uint64_t)x], INSTR(element[(uint64_t)x], " ")+1, INSTR(element[(uint64_t)x], "[") - INSTR(element[(uint64_t)x], " ")-1);
            dim = F_MID(dim,element[(uint64_t)x], INSTR(element[(uint64_t)x], "[")+1, INSTR(element[(uint64_t)x], "]") - INSTR(element[(uint64_t)x], "[")-1);
            if( NOT(INSTR(element[(uint64_t)x], g_STRINGSIGN))  AND  REGEX(element[(uint64_t)x], ".*\\[.*\\].*") ){
                g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , "char *__b2c_" , arr , "[" , dim , "+" , STR(g_OPTION_BASE) ,"]") ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " char** " , arr , " = __b2c_" , arr , ";") ;
                g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , " " , element[x]) ;
            } else if( NOT(INSTR(element[(uint64_t)x], g_STRINGSIGN)) ){
                g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , HEAD(element[x], AMOUNT(element[x])-1) , " __b2c_" , TAIL(element[x])) ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , HEAD(element[x], AMOUNT(element[x])-1) , " " , TAIL(element[x]) , " = __b2c_" , TAIL(element[x]) , ";") ;
                g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , " " , element[x]) ;
            } else if( REGEX(element[(uint64_t)x], ".*\\[.*\\].*") ){
                if( (LEN(dim) )< 1 ){
                    g_ORIGFUNCNAME = F_CHOP(g_ORIGFUNCNAME, CONCAT(g_ORIGFUNCNAME , " " , element[x]) );
                    g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , " " , element[x]) ;
                } else {
                    g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , "char *__b2c_" , arr , "[" , dim , "+" , STR(g_OPTION_BASE) ,"]") ;
                    g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "char *" , arr , "[" , dim , "+" , STR(g_OPTION_BASE) , "] = { NULL };") ;
                    g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "for(b2c_ctr=0; b2c_ctr<" , dim , "+" , STR(g_OPTION_BASE) , "; b2c_ctr++){if(__b2c_" , arr , "[b2c_ctr]!=NULL) " , arr , "[b2c_ctr] = b2c_CopyString(" , arr , "[b2c_ctr], __b2c_" , arr , "[b2c_ctr]); }") ;
                    g_STRINGARRAYS = F_CONCAT(g_STRINGARRAYS, g_STRINGARRAYS , "for(b2c_ctr=0; b2c_ctr<" , dim , "+" , STR(g_OPTION_BASE) , "; b2c_ctr++) { __b2c__STRFREE(" , arr , "[b2c_ctr]); }") ;
                    g_PROTOTYPE = F_CONCAT(g_PROTOTYPE,g_PROTOTYPE , "char *__b2c_" , CHOP(MID(element[x], INSTR(element[x], " ")))) ;
                }
            } else {
                g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , "char *__b2c_" , CHOP(MID(element[x], INSTR(element[x], " ")))) ;
                var = F_CHOP(var,MID(element[(uint64_t)x], INSTR(element[(uint64_t)x], " ")));
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "char *" , var , " = NULL;" , var , " = b2c_CopyString(NULL, __b2c_" , var , ");") ;
                g_LOCALSTRINGS = F_CONCAT(g_LOCALSTRINGS, g_LOCALSTRINGS , " " , CHOP(MID(element[x], INSTR(element[x], " ")))) ;
                g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , " " , element[x]) ;
            }
        } else {
            if( NOT(HASDELIM(element[(uint64_t)x]))  AND  NOT(REGEX(element[(uint64_t)x], "^DIR|^FILE|^short|^int|^long|^float|^double|^char|^void|^STRING|^NUMBER|^FLOATING")) ){
                element[(uint64_t)x] = F_CONCAT(element[(uint64_t)x], IIF(REGEX(element[(uint64_t)x], CONCAT( g_FLOATSIGN , "$") ), "double ", CONCAT( g_VARTYPE , " ") ) , element[(uint64_t)x]) ;
            }
            if( REGEX(TAIL(element[(uint64_t)x]), g_C_KEYWORDS) ){
            fprintf(stderr, "%sSyntax error: variable '%s' in SUB/FUNCTION statement at line %s in file '%s' is a C keyword or function!\n", NL, TAIL(element[(uint64_t)x]), STR( g_COUNTER), g_CURFILE);
                exit(1);
            } else if( NOT(LEN(Get_Var(TAIL(element[(uint64_t)x]), g_FUNCNAME))) ){
                Save_Func_Var(TAIL(element[(uint64_t)x]), g_FUNCNAME, FIRST(element[(uint64_t)x]));
            } else {
                if( g_SEMANTIC == 0 ){
                fprintf(stderr, "%sWARNING: variable '%s' in function header at line %s in file '%s' was defined previously!\n", NL, TAIL(element[(uint64_t)x]), STR( g_COUNTER), g_CURFILE);
                }
            }
            if( REGEX(element[(uint64_t)x], ".*\\[.*\\].*\\].*") ){
            fprintf(stderr, "%sSyntax error: cannot pass multidimensional numeric array at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                exit(1);
            } else if( REGEX(element[(uint64_t)x], ".*\\[\\].*") ){
                g_ORIGFUNCNAME = F_CHOP(g_ORIGFUNCNAME, CONCAT(g_ORIGFUNCNAME , " " , element[x]) );
            } else if( REGEX(element[(uint64_t)x], ".*\\[.*\\].*") ){
                dim = F_MID(dim,element[(uint64_t)x], INSTR(element[(uint64_t)x], "[")+1, INSTR(element[(uint64_t)x], "]") - INSTR(element[(uint64_t)x], "[")-1);
                arr = F_MID(arr,element[(uint64_t)x], INSTRREV(element[(uint64_t)x], " ")+1, INSTR(element[(uint64_t)x], "[") - INSTRREV(element[(uint64_t)x], " ")-1);
                g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , TOKEN(element[(uint64_t)x], 1) , " __b2c_" , arr , "[" , dim , "+" , STR(g_OPTION_BASE) , "]") ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , TOKEN(element[(uint64_t)x], 1) , " " , arr , "[" , dim , "+" , STR(g_OPTION_BASE) , "] = { 0 };") ;
                g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , "memmove(" , arr , ", __b2c_" , arr , ", (" , dim , "+" , STR(g_OPTION_BASE) , ")*sizeof(" , TOKEN(element[(uint64_t)x], 1) , "));") ;
            } else {
                g_ORIGFUNCNAME = F_CHOP(g_ORIGFUNCNAME, CONCAT(g_ORIGFUNCNAME , " " , element[x]) );
            }
            g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , " " , element[x]) ;
        }
        if( (x )< dim ){
            g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , ",") ;
            g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , ",") ;
        } else {
            g_ORIGFUNCNAME = F_CONCAT(g_ORIGFUNCNAME, g_ORIGFUNCNAME , ")") ;
            g_PROTOTYPE = F_CONCAT(g_PROTOTYPE, g_PROTOTYPE , ")") ;
        }
    }
    fclose(g_CFILE);
    g_IMPORTED = F_CONCAT(g_IMPORTED, g_FUNCNAME , " " , g_IMPORTED) ;
    g_ORIGCATCHGOTO = b2c_CopyString(g_ORIGCATCHGOTO, (char*) g_CATCHGOTO);
    g_ORIGCATCH_USED=(long)( g_CATCH_USED);
    g_CATCHGOTO = b2c_CopyString(g_CATCHGOTO, (char*) "__B2C__PROGRAM__EXIT");
    g_CATCH_USED=(long)( 0);
    g_STRINGARGS = F_CONCAT(g_STRINGARGS, g_STRINGARGS , " b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;") ;
    g_COPY_CFILE = b2c_CopyString(g_COPY_CFILE, (char*) g_CFILE);
    g_COPY_COUNTER=(long)( g_COUNTER);
    g_CFILE = F_CONCAT(g_CFILE, LEFT(g_CFILE, INSTR(g_CFILE, ".c")) , g_FUNCNAME , ".tmp") ;
    g_CFILE = fopen((const char*)g_CFILE, "w");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 2615, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    b2c_free_str_array_members(&match, 1, match__b2c_array); b2c_free_str_array_members(&element, 1, element__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(dim);
    __b2c__STRFREE(arr);
    __b2c__STRFREE(size);
    __b2c__STRFREE(var);
    __b2c__STRFREE(no_arg);
    __b2c__STRFREE(type);
    __b2c__STRFREE(match);
    __b2c__STRFREE(element);
    __B2C__PROGRAM__EXIT: ;
    b2c_catch_set = b2c_catch_set_backup;
}
