/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval 0
char* Pre_Tokenize_Functions( char *arg_in) {
char*arg = NULL; arg = b2c_CopyString(NULL, arg_in); b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0; char *b2c_select_6023 = NULL; char *b2c_select_6073 = NULL; char *b2c_select_6101 = NULL; char **funcvar = { NULL }; long funcvar__b2c_array = 0; char **mainvar = { NULL }; long mainvar__b2c_array = 0;
    char *token = NULL;
    char *it = NULL;
    char *var = NULL;
    char *val = NULL;
    char *type = NULL;
    char *first = NULL;
    char *second = NULL;
    char *delim = NULL;
    char *intoken = NULL;
    char *uniq = NULL;
    long is_escaped = 0;
    long is_string = 0;
    long i = 0;
    long j = 0;
    long mem = 0;
    long nr = 1;
    long many = 0;
    long pos = 0;
    FILE* out = NULL;
    if( ISTRUE(g_LOWERCASE) ){
        if( REGEX(arg, "^const[[:space:]]")  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
            arg = F_CONCAT(arg, "CONST " , MID(arg, 6));
        }
        if( REGEX(arg, "[[:space:]]static$")  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
            arg = F_CONCAT(arg, LEFT(arg, LEN(arg)-7) , " STATIC");
        }
    }
    if( g_OPTION_DISABLE_C_ESCAPE ){
        for(i=1; i <= LEN(arg); i+=1){
            b2c_select_5978 = (double)ASC(MID(arg, i, 1));
            if ( (b2c_select_5978) == (92)){
                if( is_string ){
                    token = F_CONCAT(token, token , CHR(92));
                }
            } else  if ( (b2c_select_5978) == (34)){
                is_string=(
                long)( NOT(is_string));
            }
            token = F_CONCAT(token, token , MID(arg, i, 1)) ;
        }
        arg = b2c_CopyString(arg, (char*) token);
        is_string=(
        long)( 0);
        token = b2c_CopyString(token, (char*) "");
    }
    if( REGEX(arg, "TYPEOF\\$|SOURCE\\$|OBTAIN\\$|IIF\\(|IIF\\$\\(|FIND\\(|EVAL\\(|VERIFY|REM|LOOP|COIL\\$|GUIDEFINE|UBOUND\\(|INVERT\\(|INDEX|[^a-zA-Z0-9_]int\\(") ){
        for(i=1; i <= LEN(arg); i+=1){
            if( NOT(is_string) ){
                if( __b2c__STRCMP(MID(arg, i, 7) ,  "TYPEOF$") == 0 ){
                    it = F_MID(it,arg, i, INSTR(MID(arg, i), ")")-1);
                    token = F_CONCAT(token, token , CHR(34) , Get_Var(MID(it, INSTR(it, "(")+1), g_FUNCNAME) , CHR(34)) ;
                    i = i + ( LEN(it)+1);
                } else if( __b2c__STRCMP(MID(arg, i, 7) ,  "SOURCE$") == 0 ){
                    if( NOT(FILEEXISTS(SRCARRAYFILE)) ){
                        mem=(
                        long)( BLOAD(g_SOURCEFILE));
#undef __b2c__MEMTYPE
#define __b2c__MEMTYPE unsigned char
                        out = fopen((const char*)SRCARRAYFILE, "w");
                    if(out == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 6005, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    fprintf(out, "char SOURCE%s[]={", g_STRINGSIGN);
                        fflush(out);
                        for(j=0; j <= FILELEN(g_SOURCEFILE)-1; j+=1){
                            if( MOD(j, 16) == 0 ){
                            fputs("\n", out);
                            }
                            fputs(STR(PEEK(mem+j)), out);
                        fputs(",", out);
                            fflush(out);
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    fputs("0 };\n", out);
                        fclose(out);
                        if(!b2c_memory__check((char *)mem, sizeof(__b2c__MEMTYPE)))
                    { ERROR=1; RUNTIMEERROR("FREE", 6013, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); } free((void*)mem);
                    }
                } else if( __b2c__STRCMP(MID(arg, i, 7) ,  "OBTAIN$") == 0 ){
                    pos=(
                    long)( INSTR(MID(arg, i), "("));
                    intoken = b2c_CopyString(intoken, (char*) Mini_Parser(MID(arg, i+pos)));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "$", g_STRINGSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "#", g_FLOATSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "%", g_LONGSIGN));
                    type = b2c_CopyString(type, (char*) Get_Var( CONCAT("assoc_" , intoken) , g_FUNCNAME));
                fprintf(g_CFILE, "#undef b2c_obtain_type_%s\n", intoken);
                    b2c_select_6023 = b2c_CopyString(b2c_select_6023, type);
                    if ( !b2c_strcmp(b2c_select_6023, "char*") || !b2c_strcmp(b2c_select_6023,  "STRING")){
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s 0\n", intoken);
                    } else  if ( !b2c_strcmp(b2c_select_6023, "double") || !b2c_strcmp(b2c_select_6023,  "FLOATING")){
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s 1\n", intoken);
                    } else  if ( !b2c_strcmp(b2c_select_6023, "float")){
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s 2\n", intoken);
                    } else  if ( !b2c_strcmp(b2c_select_6023, "long") || !b2c_strcmp(b2c_select_6023,  "NUMBER")){
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s 3\n", intoken);
                    } else  if ( !b2c_strcmp(b2c_select_6023, "int")){
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s 4\n", intoken);
                    } else  if ( !b2c_strcmp(b2c_select_6023, "short")){
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s 5\n", intoken);
                    } else  if ( !b2c_strcmp(b2c_select_6023, "char")){
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s 6\n", intoken);
                    } else {
                    fprintf(g_CFILE, "#define b2c_obtain_type_%s -1\n", intoken);
                    }
                    token = F_CONCAT(token, token , "OBTAIN$") ;
                    i = i + ( 7);
                } else if( __b2c__STRCMP(MID(arg, i, 7) ,  "VERIFY(") == 0 ){
                    var = F_MID(var,arg, INSTR(arg, "(")+1);
                    intoken = b2c_CopyString(intoken, (char*) Mini_Parser(var));
                    intoken = F_MID(intoken,var, LEN(intoken)+2);
                fputs("#undef b2c_cacerts\n", g_HFILE);
                fprintf(g_HFILE, "#define b2c_cacerts %s\n", TOKEN(intoken, 1, ")"));
                    if( TALLY(g_LIB_TLS, "wolfssl") ){
                    fputs("#undef b2c_capeer\n", g_HFILE);
                    fputs("#define b2c_capeer SSL_VERIFY_PEER\n", g_HFILE);
                    }
                    token = F_CONCAT(token, token , "VERIFY(") ;
                    i = i + ( 7);
                } else if( __b2c__STRCMP(MID(arg, i, 6) ,  "UBOUND") == 0 ){
                    it = F_MID(it,arg, i, INSTR(MID(arg, i), ")")-1);
                    i = i + ( LEN(it)+1);
                    it = b2c_CopyString(it, (char*) REPLACE(it, "$", g_STRINGSIGN));
                    it = b2c_CopyString(it, (char*) REPLACE(it, "#", g_FLOATSIGN));
                    it = b2c_CopyString(it, (char*) REPLACE(it, "%", g_LONGSIGN));
                    if( LEN(Get_Var( CONCAT("assoc_" , TOKEN(it, 2, "(")) , g_FUNCNAME)) ){
                        token = F_CONCAT(token, token , "NRKEYS(" , TOKEN(it, 2, "(") , ")") ;
                    } else if( ISTOKEN(g_DYNAMICARRAYS, CONCAT( TOKEN(it, 2, "(") , "@" , g_FUNCNAME) ) ){
                        token = F_CONCAT(token, token , TOKEN(it, 2, "(") , "__b2c_array") ;
                    } else {
                        type = b2c_CopyString(type, (char*) Get_Var(TOKEN(it, 2, "("), g_FUNCNAME));
                        token = F_CONCAT(token, token , "(sizeof(" , TOKEN(it, 2, "(") , ")/sizeof(" , type , ")-" , STR(g_OPTION_BASE) , ")") ;
                    }
                } else if( __b2c__STRCMP(MID(arg, i, 7) ,  "INVERT(") == 0 ){
                    pos=(
                    long)( INSTR(MID(arg, i), "("));
                    intoken = b2c_CopyString(intoken, (char*) Mini_Parser(MID(arg, i+pos)));
                    type = b2c_CopyString(type, (char*) Get_Var( CONCAT("assoc_" , intoken) , g_FUNCNAME));
                    b2c_select_6073 = b2c_CopyString(b2c_select_6073, type);
                    if ( !b2c_strcmp(b2c_select_6073, "char*") || !b2c_strcmp(b2c_select_6073,  "STRING")){
                        nr=(
                        long)( 0);
                    } else  if ( !b2c_strcmp(b2c_select_6073, "double") || !b2c_strcmp(b2c_select_6073,  "FLOATING")){
                        nr=(
                        long)( 1);
                    } else  if ( !b2c_strcmp(b2c_select_6073, "float")){
                        nr=(
                        long)( 2);
                    } else  if ( !b2c_strcmp(b2c_select_6073, "long") || !b2c_strcmp(b2c_select_6073,  "NUMBER")){
                        nr=(
                        long)( 3);
                    } else  if ( !b2c_strcmp(b2c_select_6073, "int")){
                        nr=(
                        long)( 4);
                    } else  if ( !b2c_strcmp(b2c_select_6073, "short")){
                        nr=(
                        long)( 5);
                    } else  if ( !b2c_strcmp(b2c_select_6073, "char")){
                        nr=(
                        long)( 6);
                    } else {
                        nr=(
                        long)( -1);
                    }
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "$", g_STRINGSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "#", g_FLOATSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "%", g_LONGSIGN));
                    token = F_CONCAT(token, token , "INVERT(" , STR(nr) , ",") ;
                    i = i + ( 7);
                } else if( __b2c__STRCMP(MID(arg, i, 6) ,  "INDEX(") == 0  OR  __b2c__STRCMP(MID(arg, i, 7) ,  "INDEX$(") == 0 ){
                    pos=(
                    long)( INSTR(MID(arg, i), "("));
                    intoken = b2c_CopyString(intoken, (char*) Mini_Parser(MID(arg, i+pos)));
                    type = b2c_CopyString(type, (char*) Get_Var( CONCAT("assoc_" , intoken) , g_FUNCNAME));
                    if( NOT(LEN(type)) ){
                        type = b2c_CopyString(type, (char*) Get_Var(intoken, g_FUNCNAME));
                    }
                    b2c_select_6101 = b2c_CopyString(b2c_select_6101, type);
                    if ( !b2c_strcmp(b2c_select_6101, "char*") || !b2c_strcmp(b2c_select_6101,  "STRING")){
                        nr=(
                        long)( 0);
                    } else  if ( !b2c_strcmp(b2c_select_6101, "double") || !b2c_strcmp(b2c_select_6101,  "FLOATING")){
                        nr=(
                        long)( 1);
                    } else  if ( !b2c_strcmp(b2c_select_6101, "float")){
                        nr=(
                        long)( 2);
                    } else  if ( !b2c_strcmp(b2c_select_6101, "long") || !b2c_strcmp(b2c_select_6101,  "NUMBER")){
                        nr=(
                        long)( 3);
                    } else  if ( !b2c_strcmp(b2c_select_6101, "int")){
                        nr=(
                        long)( 4);
                    } else  if ( !b2c_strcmp(b2c_select_6101, "short")){
                        nr=(
                        long)( 5);
                    } else  if ( !b2c_strcmp(b2c_select_6101, "char")){
                        nr=(
                        long)( 6);
                    } else {
                        nr=(
                        long)( -1);
                    }
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "$", g_STRINGSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "#", g_FLOATSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "%", g_LONGSIGN));
                    if( LEN(Get_Var( CONCAT("assoc_" , intoken) , g_FUNCNAME)) ){
                        token = F_CONCAT(token, token , "INDEX$(" , STR(nr) , ",") ;
                        i = i + ( 7);
                    } else if( ISTOKEN(g_DYNAMICARRAYS, CONCAT( intoken , "@" , g_FUNCNAME) ) ){
                        token = F_CONCAT(token, token , "INDEX(" , intoken , "__b2c_array," , STR(nr) , ",") ;
                        i = i + ( 6);
                    } else {
                        type = b2c_CopyString(type, (char*) Get_Var(intoken, g_FUNCNAME));
                        token = F_CONCAT(token, token , "INDEX(sizeof(" , intoken , ")/sizeof(" , type , ")-" , STR(g_OPTION_BASE) , "," , STR(nr) , ",") ;
                        i = i + ( 6);
                    }
                } else if( __b2c__STRCMP(MID(arg, i, 9) ,  "GUIDEFINE") == 0 ){
                    pos=(
                    long)( INSTR(MID(arg, i), "("));
                    intoken = b2c_CopyString(intoken, (char*) Mini_Parser(MID(arg, i+pos)));
                    guiGenerate(CHOP(intoken, CONCAT( "\n\r\t " , CHR(34)) ));
                    token = F_CONCAT(token, token , "GUIDEFINE") ;
                    i = i + ( 9);
                } else if( __b2c__STRCMP(MID(arg, i, 6) ,  "LOOP$(") == 0  OR  __b2c__STRCMP(MID(arg, i, 6) ,  "COIL$(") == 0  OR  __b2c__STRCMP(MID(arg, i, 5) ,  "LOOP(") == 0 ){
                    delim = b2c_CopyString(delim, (char*) "b2c_option_delim");
                    pos=(
                    long)( INSTR(MID(arg, i), "("));
                    first = b2c_CopyString(first, (char*) Mini_Parser(MID(arg, i+pos)));
                    second = b2c_CopyString(second, (char*) Mini_Parser(MID(arg, i+pos+LEN(first)+1)));
                    if( __b2c__STRCMP(MID(arg, i+pos+LEN(first)+1+LEN(second), 1) ,  ",") == 0 ){
                        intoken = b2c_CopyString(intoken, (char*) Mini_Parser(MID(arg, i+pos+LEN(first)+1+LEN(second)+1)));
                        if( __b2c__STRCMP(MID(arg, i+pos+LEN(first)+1+LEN(second)+1+LEN(intoken), 1) ,  ",") == 0 ){
                            delim = b2c_CopyString(delim, (char*) Mini_Parser(MID(arg, i+pos+LEN(first)+1+LEN(second)+1+LEN(intoken)+1)));
                        }
                    } else {
                        intoken = b2c_CopyString(intoken, (char*) second);
                        second = b2c_CopyString(second, (char*) first);
                        first = b2c_CopyString(first, (char*) "_");
                    }
                    if( INSTR(intoken, "LOOP")  OR  INSTR(intoken, "COIL$")  OR  (TALLY(arg, "LOOP") )> 1  OR  (TALLY(arg, "COIL$") )> 1 ){
                    fprintf(stderr, "%sSyntax error: multiple LOOP$/COIL$/LOOP functions in one statement at line %s in file '%s'!\n", NL, STR( g_COUNTER), g_CURFILE);
                        exit(1);
                    }
                    if( __b2c__STRCMP(MID(arg, i, pos) ,  "LOOP$(") == 0 ){
                        token = b2c_CopyString(token, (char*) Pre_Tokenize_Functions( CONCAT("IF setjmp(b2c_loop2) THEN:FOR " , first , "=1 TO " , second , ":b2c_loop_result$ = CONCAT$(b2c_loop_result$, " , intoken , "):NEXT:CALL longjmp(b2c_loop1, 1):ENDIF:" , token) ));
                    } else if( __b2c__STRCMP(MID(arg, i, pos) ,  "COIL$(") == 0 ){
                        token = b2c_CopyString(token, (char*) Pre_Tokenize_Functions( CONCAT("IF setjmp(b2c_loop2) THEN:FOR " , first , "=1 TO " , second , ":b2c_loop_result$ = APPEND$(b2c_loop_result$, 0, " , intoken , "," , delim , "):NEXT:CALL longjmp(b2c_loop1, 1):ENDIF:" , token) ));
                    } else {
                        token = b2c_CopyString(token, (char*) Pre_Tokenize_Functions( CONCAT("IF setjmp(b2c_loop2) THEN:FOR " , first , "=1 TO " , second , ":b2c_loop_result = b2c_loop_result + (" , intoken , "):NEXT:CALL longjmp(b2c_loop1, 1):ENDIF:" , token) ));
                    }
                } else if( __b2c__STRCMP(MID(arg, i, 4) ,  "IIF(") == 0 ){
                    intoken = b2c_CopyString(intoken, (char*) Mini_Parser(MID(arg, i+4)));
                    if( REGEX(arg, CONCAT( ".* " , g_RANGEOP1 , ".*;.*") )  OR  REGEX(arg, CONCAT( ".* " , g_RANGEOP2 , ".*;.*") ) ){
                        intoken = F_CONCAT(intoken, intoken , ";" , Mini_Parser(MID(arg, i+4+LEN(intoken)+1)));
                    }
                    i = i + ( 4+LEN(intoken));
                    token = F_CONCAT(token, token , "IIF(" , Pre_Tokenize_Functions(Parse_Equation(intoken))) ;
                } else if( __b2c__STRCMP(MID(arg, i, 5) ,  "IIF$(") == 0 ){
                    intoken = b2c_CopyString(intoken, (char*) Mini_Parser(MID(arg, i+5)));
                    if( REGEX(arg, CONCAT( ".* " , g_RANGEOP1 , ".*;.*") )  OR  REGEX(arg, CONCAT( ".* " , g_RANGEOP2 , ".*;.*") ) ){
                        intoken = F_CONCAT(intoken, intoken , ";" , Mini_Parser(MID(arg, i+5+LEN(intoken)+1)));
                    }
                    i = i + ( 5+LEN(intoken));
                    token = F_CONCAT(token, token , "IIF$(" , Pre_Tokenize_Functions(Parse_Equation(intoken))) ;
                } else if( __b2c__STRCMP(MID(arg, i, 5) ,  "EVAL(") == 0 ){
                    if( nr == 1 ){
                        var = F_CONCAT(var, "char *__b2c_evalvars_" , g_FUNCNAME , "_" , STR(g_COUNTER) , "_" , STR(HASH(token)>>8) , "[] = {") ;
                        val = F_CONCAT(val, "double __b2c_evalvals_" , g_FUNCNAME , "_" , STR(g_COUNTER) , "_" , STR(HASH(token)>>8) , "[] = {") ;
                        funcvar__b2c_array = b2c_lookup_by_order(assoc_g_ALL_FUNC_VARS, &funcvar, funcvar__b2c_array, 1);
                        many = funcvar__b2c_array;
                        for(j=1; j <= many; j+=1){
                            if( __b2c__STRCMP(TOKEN(funcvar[(uint64_t)j], 2) ,  g_FUNCNAME) == 0 ){
                                type = b2c_CopyString(type, (char*) Get_Var(TOKEN(funcvar[(uint64_t)j], 1), g_FUNCNAME));
                                if( NOT(TALLY(type, "*"))  AND  REGEX(type, "double$|FLOATING$") ){
                                    var = F_CONCAT(var, var , CHR(34) , TOKEN(funcvar[j], 1) , CHR(34) , ",") ;
                                    val = F_CONCAT(val, val , TOKEN(funcvar[j], 1) , ",") ;
                                    nr = nr + (1);
                                }
                            }
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                        mainvar__b2c_array = b2c_lookup_by_order(assoc_g_ALL_MAIN_VARS, &mainvar, mainvar__b2c_array, 1);
                        many = mainvar__b2c_array;
                        for(j=1; j <= many; j+=1){
                            type = b2c_CopyString(type, (char*) Get_Var(mainvar[(uint64_t)j]));
                            if( NOT(TALLY(type, "*"))  AND  REGEX(type, "double$|FLOATING$") ){
                                var = F_CONCAT(var, var , CHR(34) , TOKEN(mainvar[j], 1) , CHR(34) , ",") ;
                                val = F_CONCAT(val, val , TOKEN(mainvar[j], 1) , ",") ;
                                nr = nr + (1);
                            }
                        }
                if(b2c_break_ctr) {b2c_break_ctr--; if (!b2c_break_ctr){if(b2c_break_flag == 1) break; else continue;} else break; }
                    fprintf(g_CFILE, "%s NULL};\n", var);
                    fprintf(g_CFILE, "%s 0};\n", val);
                    }
                    i = i + ( 5);
                    token = F_CONCAT(token, token , "EVAL(__b2c_evalvars_" , g_FUNCNAME , "_" , STR(g_COUNTER) , "_" , STR(HASH(token)>>8) , ",__b2c_evalvals_" , g_FUNCNAME , "_" , STR(g_COUNTER) , "_" , STR(HASH(token)>>8) , "," , STR(nr) , "-1,") ;
                } else if( __b2c__STRCMP(MID(arg, i, 5) ,  "FIND(") == 0 ){
                    pos=(
                    long)( INSTR(MID(arg, i), "("));
                    first = b2c_CopyString(first, (char*) Mini_Parser(MID(arg, i+pos)));
                    intoken = F_CHOP(intoken,REPLACE(first, "$", g_STRINGSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "#", g_FLOATSIGN));
                    intoken = b2c_CopyString(intoken, (char*) REPLACE(intoken, "%", g_LONGSIGN));
                    type = b2c_CopyString(type, (char*) Get_Var( CONCAT("b2c_tree_" , intoken) , g_FUNCNAME));
                    second = b2c_CopyString(second, (char*) Mini_Parser(MID(arg, i+pos+LEN(first)+1)));
                    uniq = F_CONCAT(uniq, "__b2c__" , intoken , "_" , STR(g_COUNTER) , "_" , STR(RND)) ;
                    if( __b2c__STRCMP(TOKEN(type, 2, ":") ,  "char*") == 0 ){
                    fprintf(g_CFILE, "char *%s = (char*)%s;\n", uniq, second);
                        token = F_CONCAT(token, token , "FIND(" , TOKEN(type, 1, ":") , "," , first , "," , "(void**)" , uniq , ",0") ;
                    } else {
                    fprintf(g_CFILE, "%s *%s = (%s*)malloc(sizeof(%s)); *%s = (%s)%s;\n", TOKEN(type, 2, ":"), uniq, TOKEN(type, 2, ":"), TOKEN(type, 2, ":"), uniq, TOKEN(type, 2, ":"), second);
                        token = F_CONCAT(token, token , "FIND(" , TOKEN(type, 1, ":") , "," , first , "," , "(void*)" , uniq , ",1") ;
                    }
                    i = i + ( 6+LEN(first)+LEN(second));
                } else if( REGEX(MID(arg, i, 4), "REM[[:space:]]")  OR  __b2c__STRCMP(arg ,  "REM") == 0 ){
                    break;
                } else if( ISTRUE(g_LOWERCASE)  AND  __b2c__STRCMP(MID(arg, i, 4) ,  "int(") == 0 ){
                    token = F_CONCAT(token, token , "INT(") ;
                    i = i + ( 4);
                }
            }
            b2c_select_6228 = (double)ASC(MID(arg, i, 1));
            if ( (b2c_select_6228) == (92)){
                token = F_CONCAT(token, token , CHR(92)) ;
                is_escaped=(
                long)( NOT(is_escaped));
            } else  if ( (b2c_select_6228) == (34)){
                token = F_CONCAT(token, token , CHR(34)) ;
                if( NOT(is_escaped) ){
                    is_string=(
                    long)( NOT(is_string));
                }
                is_escaped=(
                long)( FALSE);
            } else {
                token = F_CONCAT(token, token , MID(arg, i, 1)) ;
                is_escaped=(
                long)( FALSE);
            }
        }
    } else {
        token = b2c_CopyString(token, (char*) arg);
    }
    b2c_assign = b2c_return(token);
    b2c_free_str_array_members(&funcvar, 1, funcvar__b2c_array); b2c_free_str_array_members(&mainvar, 1, mainvar__b2c_array);
    __b2c__STRFREE(arg);
    __b2c__STRFREE(token);
    __b2c__STRFREE(it);
    __b2c__STRFREE(var);
    __b2c__STRFREE(val);
    __b2c__STRFREE(type);
    __b2c__STRFREE(first);
    __b2c__STRFREE(second);
    __b2c__STRFREE(delim);
    __b2c__STRFREE(intoken);
    __b2c__STRFREE(uniq);
    __b2c__STRFREE(b2c_select_6023);
    __b2c__STRFREE(b2c_select_6073);
    __b2c__STRFREE(b2c_select_6101);
    __b2c__STRFREE(funcvar);
    __b2c__STRFREE(mainvar);
    b2c_catch_set = b2c_catch_set_backup;
    return(b2c_assign);
    __B2C__PROGRAM__EXIT: ;
    b2c_catch_set = b2c_catch_set_backup;
return (NULL);}
