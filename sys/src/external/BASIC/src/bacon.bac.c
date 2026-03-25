/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#include "bacon.bac.h"
#include "bacon.bac.string.h"
#include "bacon.bac.float.h"
/****************************/
/* Main program starts here */
/****************************/
int main(int argc, char **argv){
    setvbuf(stdout, NULL, _IOLBF, 0);
    atexit(__b2c_str_free);
    b2c_set_stack_size();
if(argc>0) { b2c_me_var = b2c_CopyString(b2c_me_var, argv[0]); }
if(argc==2 && !strncmp(argv[1], "-bacon", 6)) { fprintf(stderr, "Converted by %s.\n", COMPILED_BY_WHICH_BACON); exit(EXIT_SUCCESS); }
    /* Setup the reserved variable 'ARGUMENT' */
    b2c_argument(&ARGUMENT, argc, argv);
    /* By default seed random generator */
    srandom((unsigned int)time(NULL));
    /* Determine current moment and keep it for timer function */
    b2c_nanotimer(1); b2c_timer(1);
    /* Setup error signal handling */
    signal(SIGILL, b2c_catch_signal);
    signal(SIGABRT, b2c_catch_signal);
    signal(SIGFPE, b2c_catch_signal);
    signal(SIGSEGV, b2c_catch_signal);
    /* Rest of the program */
    b2c_collapse = TRUE;
    SETENVIRON("LC_NUMERIC", "POSIX");
    if( __b2c__STRCMP(VERSION ,  g_VERSION) != 0 ){
    fputs("System error: this BaCon binary was compiled with a previous BaCon version and therefore may not function correctly.\n", stderr);
    fprintf(stderr, "Recompile BaCon with the Shell implementation version %s.\n", g_VERSION);
        exit(1);
    }
    if( TALLY(OS, "SunOS") ){
        g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) "-lnsl -lsocket");
    }
    if( TALLY(OS, "Haiku") ){
        g_LDFLAGS = b2c_CopyString(g_LDFLAGS, (char*) "-lbsd -lnetwork");
    }
    if( ISTRUE(LEN(EXEC("command -v objdump 2>/dev/null"))) ){
        if( INSTR(EXEC( CONCAT("objdump -p $(command -v " , ME , ")") ), "musl") ){
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " -lfts") ;
        }
    }
    assoc_g_ALL_MAIN_VARS = b2c_hash_new();
    assoc_g_ALL_FUNC_VARS = b2c_hash_new();
    assoc_g_ALL_DIM_VARS = b2c_hash_new();
    assoc_g_SEMANTIC_MEMFREE = b2c_hash_new();
    assoc_g_SEMANTIC_OPENCLOSE = b2c_hash_new();
    assoc_g_MACRO_STRINGS = b2c_hash_new();
    g_MAX_DIGITS=(long)( 32);
    g_BUFFER_SIZE=(long)( 512);
    g_MAX_RBUFFERS=(long)( 64);
    g_CCNAME = b2c_CopyString(g_CCNAME, (char*) "");
    g_TEMPDIR = b2c_CopyString(g_TEMPDIR, (char*) "");
    g_INCFILES = b2c_CopyString(g_INCFILES, (char*) "");
    g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) "");
    g_BINEXT = b2c_CopyString(g_BINEXT, (char*) "");
    g_CCNAME_TMP = b2c_CopyString(g_CCNAME_TMP, (char*) "");
    g_TEMPDIR_TMP = b2c_CopyString(g_TEMPDIR_TMP, (char*) "");
    g_INCFILES_TMP = b2c_CopyString(g_INCFILES_TMP, (char*) "");
    g_LDFLAGS_TMP = b2c_CopyString(g_LDFLAGS_TMP, (char*) "");
    g_CCFLAGS_TMP = b2c_CopyString(g_CCFLAGS_TMP, (char*) "");
    g_NO_COMPILE=(long)( 0);
    g_TMP_PRESERVE=(long)( 0);
    g_QUIET=(long)( 0);
    g_EXEC=(long)( 0);
    g_SEMANTIC=(long)( 0);
    g_NO_QUESTION=(long)( 0);
    g_CPP=(long)( 0);
    g_XGETTEXT=(long)( 0);
    g_SAVE_CONFIG=(long)( 0);
    g_DEBUG=(long)( 0);
    g_LOWERCASE=(long)( 0);
    g_USE_C=(long)( 0);
    g_USE_H=(long)( 0);
    g_MAX_BACKLOG=(long)( 5);
    g_INCLUDE_FILES = b2c_CopyString(g_INCLUDE_FILES, (char*) "");
    g_PRAGMA_INCLUDE = b2c_CopyString(g_PRAGMA_INCLUDE, (char*) "");
    g_PRAGMA_REGEX = b2c_CopyString(g_PRAGMA_REGEX, (char*) "");
    g_TRACE=(long)( 0);
    g_OPTION_BASE=(long)( 0);
    g_OPTION_SOCKET=(long)( 5);
    g_OPTION_TLS=(long)( 0);
    g_OPTION_EVAL=(long)( 0);
    g_INC_TLS = b2c_CopyString(g_INC_TLS, (char*) "");
    g_LIB_TLS = b2c_CopyString(g_LIB_TLS, (char*) "");
    g_WHICH_GUI=(long)( 0);
    g_OPTION_BREAK=(long)( 1);
    g_OPTION_DISABLE_C_ESCAPE=(long)( 0);
    g_CURFILE = b2c_CopyString(g_CURFILE, (char*) "");
    g_FUNCNAME = b2c_CopyString(g_FUNCNAME, (char*) "");
    g_SOURCEFILE = b2c_CopyString(g_SOURCEFILE, (char*) "");
    g_FUNCTYPE = b2c_CopyString(g_FUNCTYPE, (char*) "");
    g_PROTOTYPE = b2c_CopyString(g_PROTOTYPE, (char*) "");
    g_TMP_FILES = b2c_CopyString(g_TMP_FILES, (char*) "");
    g_LOCALSTRINGS = b2c_CopyString(g_LOCALSTRINGS, (char*) "");
    g_STRINGARRAYS = b2c_CopyString(g_STRINGARRAYS, (char*) "");
    g_GLOBALARRAYS = b2c_CopyString(g_GLOBALARRAYS, (char*) "");
    g_STRINGARGS = b2c_CopyString(g_STRINGARGS, (char*) "");
    g_DYNAMICARRAYS = b2c_CopyString(g_DYNAMICARRAYS, (char*) "");
    g_STATICARRAYS = b2c_CopyString(g_STATICARRAYS, (char*) "");
    g_RECORDCACHE = b2c_CopyString(g_RECORDCACHE, (char*) "");
    g_LOOPCTR=(long)( 0);
    g_ERRORTXT = b2c_CopyString(g_ERRORTXT, (char*) "");
    g_COMMENT=(long)( FALSE);
    g_TRACE_PREFIX = b2c_CopyString(g_TRACE_PREFIX, (char*) "");
    g_IGNORE_PARSE = b2c_CopyString(g_IGNORE_PARSE, (char*) "TRUE");
    g_PRIORITY = b2c_CopyString(g_PRIORITY, (char*) "\"NORMAL:-VERS-TLS1.3:%COMPAT\"");
    g_OPTION_EXPLICIT = b2c_CopyString(g_OPTION_EXPLICIT, (char*) "FALSE");
    g_OPTION_LOCAL = b2c_CopyString(g_OPTION_LOCAL, (char*) "FALSE");
    g_OPTION_INPUT = b2c_CopyString(g_OPTION_INPUT, (char*) "\"\\n\"");
    g_VARTYPE = b2c_CopyString(g_VARTYPE, (char*) "long");
    g_OBJ_FILES = b2c_CopyString(g_OBJ_FILES, (char*) "");
    g_MAKE_LINE = b2c_CopyString(g_MAKE_LINE, (char*) "");
    g_MONITOR = b2c_CopyString(g_MONITOR, (char*) "");
    g_STRING_FUNC=(long)( 1);
    g_DOTIMES=(long)( 0);
    g_LOCAL_SBUFFER = b2c_CopyString(g_LOCAL_SBUFFER, (char*) "");
    g_TWEAK = b2c_CopyString(g_TWEAK, (char*) "");
    g_DEPEND = b2c_CopyString(g_DEPEND, (char*) "");
    g_CATCHGOTO = b2c_CopyString(g_CATCHGOTO, (char*) "__B2C__PROGRAM__EXIT");
    g_CATCH_USED=(long)( 0);
    g_RECORDNAME = b2c_CopyString(g_RECORDNAME, (char*) "");
    g_RECORDVAR = b2c_CopyString(g_RECORDVAR, (char*) "");
    g_RECORDARRAY = b2c_CopyString(g_RECORDARRAY, (char*) "");
    g_WITHVAR = b2c_CopyString(g_WITHVAR, (char*) "");
    g_RECORDEND_BODY = b2c_CopyString(g_RECORDEND_BODY, (char*) "");
    g_RECORDEND_HEADER = b2c_CopyString(g_RECORDEND_HEADER, (char*) "");
    g_SOCKTYPE = b2c_CopyString(g_SOCKTYPE, (char*) "SOCK_STREAM");
    g_NETWORKTYPE = b2c_CopyString(g_NETWORKTYPE, (char*) "TCP");
    g_MULTICAST_TTL=(long)( 1);
    g_SCTP_STREAMS=(long)( 1);
    g_SELECTVAR_CTR=(long)( 0);
    g_RELATE_CTR=(long)( 0);
    g_FCTR=(long)( 0);
    g_CCTR=(long)( 0);
    g_CURSOR_X=(long)( 0);
    g_CURSOR_Y=(long)( 0);
    if( NOT(FILEEXISTS( CONCAT(GETENVIRON("HOME") , "/.bacon/") )) ){
    ERROR = b2c_makedir(CONCAT( GETENVIRON("HOME") , "/.bacon/")); if(ERROR) { RUNTIMEERROR("MAKEDIR", 8039, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    }
    if( FILEEXISTS( CONCAT(GETENVIRON("HOME") , "/.bacon/bacon.cfg" ) ) ){
        cfgfile = fopen((const char*)CONCAT( GETENVIRON("HOME") , "/.bacon/bacon.cfg" ), "r");
    if(cfgfile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8042, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
        while( NOT(ENDFILE(cfgfile)) ){
            b2c_readln(&b2c_assign, cfgfile);
            line = b2c_CopyString(line, b2c_assign);
            __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
            b2c_select_8045 = b2c_CopyString(b2c_select_8045, TOKEN(line, 1));
            if ( !b2c_strcmp(b2c_select_8045, "ccname")){
                g_CCNAME_TMP = b2c_CopyString(g_CCNAME_TMP, (char*) TOKEN(line, 2));
            } else  if ( !b2c_strcmp(b2c_select_8045, "tempdir")){
                g_TEMPDIR_TMP = b2c_CopyString(g_TEMPDIR_TMP, (char*) TOKEN(line, 2));
            } else  if ( !b2c_strcmp(b2c_select_8045, "incfiles")){
                g_INCFILES_TMP = b2c_CopyString(g_INCFILES_TMP, (char*) TOKEN(line, 2));
            } else  if ( !b2c_strcmp(b2c_select_8045, "ldflags")){
                g_LDFLAGS_TMP = b2c_CopyString(g_LDFLAGS_TMP, (char*) TOKEN(line, 2));
            } else  if ( !b2c_strcmp(b2c_select_8045, "ccflags")){
                g_CCFLAGS_TMP = b2c_CopyString(g_CCFLAGS_TMP, (char*) TOKEN(line, 2));
            } else  if ( !b2c_strcmp(b2c_select_8045, "lowercase")){
                g_LOWERCASE_TMP=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "intense")){
                Color_Intense=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "linenr")){
                Line_Number_Active=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "default_color")){
                Def_Col=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "function_color")){
                Func_Col=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "quote_color")){
                Quot_Col=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "number_color")){
                Num_Col=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "type_color")){
                Type_Col=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "variable_color")){
                Var_Col=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "statement_color")){
                Stat_Col=(long)( VAL(TOKEN(line, 2)));
            } else  if ( !b2c_strcmp(b2c_select_8045, "comment_color")){
                Comm_Col=(long)( VAL(TOKEN(line, 2)));
            }
        }
        fclose(cfgfile);
    }
    do{
        opt=(long)( CMDLINE(":c:d:i:l:o:t:e:xnjfpqrsvwyz@"));
        b2c_select_8085 = (double)opt;
        if ( (b2c_select_8085) == (99)){
            g_CCNAME = b2c_CopyString(g_CCNAME, (char*) ARGUMENT);
        } else  if ( (b2c_select_8085) == (105)){
            if( __b2c__STRCMP(LEFT(ARGUMENT) ,  "/") == 0  OR  __b2c__STRCMP(LEFT(ARGUMENT, 2) ,  "./") == 0 ){
                g_INCFILES = F_CONCAT(g_INCFILES, g_INCFILES , "#include " , CHR(34) , ARGUMENT , CHR(34)) ;
            } else if( __b2c__STRCMP(LEFT(ARGUMENT) ,  "<") == 0 ){
                g_INCFILES = F_CONCAT(g_INCFILES, g_INCFILES , "#include " , ARGUMENT) ;
            } else {
                g_INCFILES = F_CONCAT(g_INCFILES, g_INCFILES , "#include " , CHR(34) , CURDIR , "/" , ARGUMENT , CHR(34)) ;
            }
        } else  if ( (b2c_select_8085) == (108)){
            if( __b2c__STRCMP(LEFT(ARGUMENT, 1) ,  "`") == 0  OR  __b2c__STRCMP(LEFT(ARGUMENT, 1) ,  "-") == 0 ){
                g_LDFLAGS = F_CONCAT(g_LDFLAGS, ARGUMENT , " " , g_LDFLAGS) ;
            } else {
                g_LDFLAGS = F_CONCAT(g_LDFLAGS, "-l" , ARGUMENT , " " , g_LDFLAGS) ;
            }
        } else  if ( (b2c_select_8085) == (111)){
            g_CCFLAGS = F_CONCAT(g_CCFLAGS, g_CCFLAGS , " " , ARGUMENT) ;
        } else  if ( (b2c_select_8085) == (100)){
            if( NOT(FILEEXISTS(ARGUMENT)) ){
            ERROR = b2c_makedir(ARGUMENT); if(ERROR) { RUNTIMEERROR("MAKEDIR", 8114, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            }
            g_TEMPDIR = b2c_CopyString(g_TEMPDIR, (char*) ARGUMENT);
        } else  if ( (b2c_select_8085) == (116)){
            b2c_select_8119 = b2c_CopyString(b2c_select_8119, LCASE(TOKEN(ARGUMENT, 1, "=")));
            if ( !b2c_strcmp(b2c_select_8119, "pbc")){
                g_TWEAK = F_CONCAT(g_TWEAK, g_TWEAK , "#define __b2c_Pool_Block_Count " , TOKEN(ARGUMENT, 2, "=") , NL) ;
            } else  if ( !b2c_strcmp(b2c_select_8119, "pbs")){
                g_TWEAK = F_CONCAT(g_TWEAK, g_TWEAK , "#define __b2c_Pool_Block_Size " , TOKEN(ARGUMENT, 2, "=") , NL) ;
            } else  if ( !b2c_strcmp(b2c_select_8119, "hld")){
                g_TWEAK = F_CONCAT(g_TWEAK, g_TWEAK , "#define __b2c_HASH_LINEAR_DEPTH " , TOKEN(ARGUMENT, 2, "=") , NL) ;
            } else  if ( !b2c_strcmp(b2c_select_8119, "hss")){
                g_TWEAK = F_CONCAT(g_TWEAK, g_TWEAK , "#define __b2c_HASH_STR_STORE " , TOKEN(ARGUMENT, 2, "=") , NL) ;
            } else  if ( !b2c_strcmp(b2c_select_8119, "mrb")){
                g_MAX_RBUFFERS=(long)( VAL(TOKEN(ARGUMENT, 2, "=")));
            }
        } else  if ( (b2c_select_8085) == (63) || (b2c_select_8085) == ( 104)){
        fprintf(stdout, "%sUSAGE: bacon [options] program[.bac]\n", NL);
        fprintf(stdout, "%sOPTIONS:\n", NL);
        fprintf(stdout, "%s -c <compiler>%sCompiler to use (default: cc)\n", NL, TAB(1));
        fprintf(stdout, " -l <ldflags>%sPass libraries to linker\n", TAB(1));
        fprintf(stdout, " -o <options>%sPass compiler options\n", TAB(1));
        fprintf(stdout, " -i <include>%sAdd include file to C code\n", TAB(1));
        fprintf(stdout, " -d <tmpdir>%sTemporary directory (default: .)\n", TAB(1));
        fprintf(stdout, " -t <param=val>%sTweak internal parameter\n", TAB(1));
        fprintf(stdout, " -e <file.bac>%sUse embedded editor\n", TAB(1));
        fprintf(stdout, " -y %sAutomatically delete temporary files\n", TAB(2));
        fprintf(stdout, " -x %sExtract gettext strings\n", TAB(2));
        fprintf(stdout, " -z %sAllow lowercase keywords\n", TAB(2));
        fprintf(stdout, " -f %sCreate Shared Object\n", TAB(2));
        fprintf(stdout, " -n %sDo not compile, only convert\n", TAB(2));
        fprintf(stdout, " -j %sInvoke C Preprocessor\n", TAB(2));
        fprintf(stdout, " -p %sPreserve temporary files\n", TAB(2));
        fprintf(stdout, " -q %sShow summary after conversion only\n", TAB(2));
        fprintf(stdout, " -r %sCompile and execute in one step\n", TAB(2));
        fprintf(stdout, " -s %sSuppress semantic error warnings\n", TAB(2));
        fprintf(stdout, " -w %sSave options to BaCon configfile\n", TAB(2));
        fprintf(stdout, " -@ %sAdd debug information\n", TAB(2));
        fprintf(stdout, " -v %sShow version\n", TAB(2));
        fprintf(stdout, " -h %sShow help%s\n", TAB(2), NL);
            exit(EXIT_SUCCESS);
        } else  if ( (b2c_select_8085) == (118)){
        fprintf(stdout, "%sBaCon version %s on %s - (c) Peter van Eerten - MIT License.%s\n", NL, g_VERSION, OS, NL);
            exit(EXIT_SUCCESS);
        } else  if ( (b2c_select_8085) == (112)){
            g_TMP_PRESERVE=(long)( 1);
        } else  if ( (b2c_select_8085) == (113)){
            g_QUIET=(long)( 1);
        } else  if ( (b2c_select_8085) == (114)){
            g_EXEC=(long)( 1);
        } else  if ( (b2c_select_8085) == (115)){
            g_SEMANTIC=(long)( 1);
        } else  if ( (b2c_select_8085) == (120)){
            g_XGETTEXT=(long)( 1);
        } else  if ( (b2c_select_8085) == (121)){
            g_NO_QUESTION=(long)( 1);
        } else  if ( (b2c_select_8085) == (110)){
            g_NO_COMPILE=(long)( 1);
        } else  if ( (b2c_select_8085) == (101)){
            g_SOURCEFILE = b2c_CopyString(g_SOURCEFILE, (char*) IIF(__b2c__STRCMP(RIGHT(ARGUMENT, 4) ,  ".bac") != 0, CONCAT( ARGUMENT , ".bac") , ARGUMENT));
            if( FILEEXISTS(g_SOURCEFILE) ){
                Editor_Handle_Input(g_SOURCEFILE, LOAD(g_SOURCEFILE));
            } else {
                Editor_Handle_Input(g_SOURCEFILE, "");
            }
            exit(EXIT_SUCCESS);
        } else  if ( (b2c_select_8085) == (106)){
            g_CPP=(long)( 1);
        } else  if ( (b2c_select_8085) == (122)){
            g_LOWERCASE=(long)( 1);
        } else  if ( (b2c_select_8085) == (102)){
            g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " -shared -rdynamic") ;
            g_CCFLAGS = F_CONCAT(g_CCFLAGS, g_CCFLAGS , " -fPIC") ;
            g_BINEXT = b2c_CopyString(g_BINEXT, (char*) ".so");
        } else  if ( (b2c_select_8085) == (119)){
            g_SAVE_CONFIG=(long)( 1);
        } else  if ( (b2c_select_8085) == (64)){
            g_DEBUG=(long)( 1);
        }
    } while(!( opt == -1 ));
    if( g_SAVE_CONFIG == 1 ){
        cfgfile = fopen((const char*)CONCAT( GETENVIRON("HOME") , "/.bacon/bacon.cfg" ), "w");
    if(cfgfile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8229, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    fprintf(cfgfile, "ccname %s\n", g_CCNAME);
    fprintf(cfgfile, "tempdir %s\n", g_TEMPDIR);
    fprintf(cfgfile, "incfiles %s\n", REPLACE(g_INCFILES, "#include", "@"));
    fprintf(cfgfile, "ldflags %s\n", g_LDFLAGS);
    fprintf(cfgfile, "ccflags %s\n", g_CCFLAGS);
    fprintf(cfgfile, "lowercase %s\n", STR( g_LOWERCASE));
    fprintf(cfgfile, "intense %s\n", STR( Color_Intense));
    fprintf(cfgfile, "linenr %s\n", STR( Line_Number_Active));
        fclose(cfgfile);
        g_CCNAME_TMP = b2c_CopyString(g_CCNAME_TMP, (char*) g_CCNAME);
        g_TEMPDIR_TMP = b2c_CopyString(g_TEMPDIR_TMP, (char*) g_TEMPDIR);
        g_INCFILES_TMP = b2c_CopyString(g_INCFILES_TMP, (char*) REPLACE(g_INCFILES, "#include", "@"));
        g_LDFLAGS_TMP = b2c_CopyString(g_LDFLAGS_TMP, (char*) g_LDFLAGS);
        g_CCFLAGS_TMP = b2c_CopyString(g_CCFLAGS_TMP, (char*) g_CCFLAGS);
        g_LOWERCASE_TMP=(long)( g_LOWERCASE);
    }
    if( NOT(LEN(g_CCNAME)) ){
        g_CCNAME = b2c_CopyString(g_CCNAME, (char*) g_CCNAME_TMP);
        if( NOT(LEN(g_CCNAME)) ){
            g_CCNAME = b2c_CopyString(g_CCNAME, (char*) "cc");
        }
    }
    if( NOT(LEN(g_TEMPDIR)) ){
        g_TEMPDIR = b2c_CopyString(g_TEMPDIR, (char*) g_TEMPDIR_TMP);
        if( NOT(LEN(g_TEMPDIR)) ){
            g_TEMPDIR = b2c_CopyString(g_TEMPDIR, (char*) ".");
        }
    }
    if( NOT(LEN(g_INCFILES)) ){
        g_INCFILES = b2c_CopyString(g_INCFILES, (char*) REPLACE(g_INCFILES_TMP, "@", "#include"));
    }
    g_LDFLAGS = F_CONCAT(g_LDFLAGS, g_LDFLAGS , " " , g_LDFLAGS_TMP) ;
    if( NOT(LEN(g_CCFLAGS)) ){
        g_CCFLAGS = b2c_CopyString(g_CCFLAGS, (char*) g_CCFLAGS_TMP);
    }
    if( g_LOWERCASE == 0 ){
        g_LOWERCASE=(long)( g_LOWERCASE_TMP);
    }
    if( NOT(LEN(ARGUMENT)) ){
        if( g_SAVE_CONFIG == 0 ){
        fputs("System error: no filename? Run with '-h' to see usage.\n", stderr);
        }
        exit(1);
    } else {
        g_SOURCEFILE = b2c_CopyString(g_SOURCEFILE, (char*) ARGUMENT);
    }
    if( __b2c__STRCMP(LEFT(g_SOURCEFILE, 7) ,  "http://") == 0 ){
        g_SOURCEFILE = F_MID(g_SOURCEFILE,g_SOURCEFILE, 8);
        Download_File(g_SOURCEFILE);
        g_SOURCEFILE = F_MID(g_SOURCEFILE,g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/")+1);
    } else if( __b2c__STRCMP(RIGHT(g_SOURCEFILE, 4) ,  ".bac") != 0 ){
        g_SOURCEFILE = F_CONCAT(g_SOURCEFILE, CHOP(g_SOURCEFILE) , ".bac") ;
    }
    if( NOT(FILEEXISTS(g_SOURCEFILE)) ){
    fprintf(stderr, "System error: file '%s' not found!\n", g_SOURCEFILE);
        exit(1);
    }
    if( INSTR(g_SOURCEFILE, "/")  AND  __b2c__STRCMP(LEFT(g_SOURCEFILE, 1) ,  "/") == 0 ){
    if(MID(g_SOURCEFILE, 1, INSTRREV(g_SOURCEFILE, "/")-1) == NULL || chdir(MID(g_SOURCEFILE, 1, INSTRREV(g_SOURCEFILE, "/")-1)) == -1){ ERROR = 22; RUNTIMEERROR("CHANGEDIR", 8282, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    }
    g_CFILE = F_CONCAT(g_CFILE, g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".c") ;
    g_HFILE = F_CONCAT(g_HFILE, g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".h") ;
    g_GENERIC = F_CONCAT(g_GENERIC, g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".generic.h") ;
    g_FUNCTIONS = F_CONCAT(g_FUNCTIONS, g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".functions.h") ;
    STRINGARRAYFILE = F_CONCAT(STRINGARRAYFILE, g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".string.h") ;
    FLOATARRAYFILE = F_CONCAT(FLOATARRAYFILE, g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".float.h") ;
    SRCARRAYFILE = F_CONCAT(SRCARRAYFILE, g_TEMPDIR , "/" , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".src.h") ;
    g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_CFILE , " " , g_HFILE , " " , STRINGARRAYFILE , " " , FLOATARRAYFILE) ;
    total = b2c_CopyString(total, (char*) WALK(g_TEMPDIR, 1, CONCAT( BASENAME(g_SOURCEFILE, 1) , "\\..+\\..+") , FALSE));
    if( g_NO_QUESTION ){
        b2c_forin_tmpfile_string = b2c_CopyString(b2c_forin_tmpfile_string, total); b2c_forin_tmpfile_string_org = b2c_forin_tmpfile_string;
        b2c_forin_tmpfile_step = b2c_CopyString(b2c_forin_tmpfile_step, b2c_option_delim);
        b2c_forin_tmpfile_ptr = b2c_for_amount(b2c_forin_tmpfile_string, b2c_forin_tmpfile_step);
        for(; b2c_forin_tmpfile_ptr > 0; b2c_forin_tmpfile_ptr--) { b2c_for_item(&b2c_forin_tmpfile_string_org, b2c_forin_tmpfile_step, &tmpfile);
        if(unlink(tmpfile)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 8301, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
        }
    } else {
        if( AMOUNT(total) ){
        fprintf(stdout, "WARNING: %s temporary files found!%s%s\n", STR( AMOUNT(total)), NL, DELIM(SORT(total), " ", NL));
            if( __b2c__STRCMP(GETENVIRON("BACON_IN_DOCKER") ,  "true") == 0 ){
                response = b2c_CopyString(response, (char*) "y");
            } else {
            fputs("Do you want to delete them ([y]/n)? ", stdout);
                fflush(stdout);
                b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                response = b2c_CopyString(response, b2c_assign);
                __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
            }
            if( LEN(response) == 0  OR  __b2c__STRCMP(LCASE(response) ,  "y") == 0 ){
                b2c_forin_tmpfile_string = b2c_CopyString(b2c_forin_tmpfile_string, total); b2c_forin_tmpfile_string_org = b2c_forin_tmpfile_string;
                b2c_forin_tmpfile_step = b2c_CopyString(b2c_forin_tmpfile_step, b2c_option_delim);
                b2c_forin_tmpfile_ptr = b2c_for_amount(b2c_forin_tmpfile_string, b2c_forin_tmpfile_step);
                for(; b2c_forin_tmpfile_ptr > 0; b2c_forin_tmpfile_ptr--) { b2c_for_item(&b2c_forin_tmpfile_string_org, b2c_forin_tmpfile_step, &tmpfile);
                if(unlink(tmpfile)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 8313, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                }
            fputs("Temporary files were deleted.\n", stdout);
            } else {
            fputs("Exiting...\n", stdout);
                exit(1);
            }
        }
    }
    starttime=(long)( TIMER);
    g_CFILE = fopen((const char*)g_CFILE, "w");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8327, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(g_CFILE, "/* Created with BaCon %s - (c) Peter van Eerten - MIT License */\n", g_VERSION);
fprintf(g_CFILE, "#include \"%s.h\"\n", MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1));
fprintf(g_CFILE, "#include \"%s.string.h\"\n", MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1));
fprintf(g_CFILE, "#include \"%s.float.h\"\n", MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1));
    g_HFILE = fopen((const char*)g_HFILE, "w");
if(g_HFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8334, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(g_HFILE, "/* Created with BaCon %s - (c) Peter van Eerten - MIT License */\n", g_VERSION);
fprintf(g_HFILE, "%s\n", CONCAT( "#include " , CHR(34) , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".generic.h" , CHR(34) ));
fprintf(g_HFILE, "%s\n", CONCAT( "#include " , CHR(34) , MID(g_SOURCEFILE, INSTRREV(g_SOURCEFILE, "/") + 1) , ".functions.h" , CHR(34) ));
    g_GENERIC = fopen((const char*)g_GENERIC, "w");
if(g_GENERIC == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8340, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(g_GENERIC, "/* Created with BaCon %s - (c) Peter van Eerten - MIT License */\n", g_VERSION);
    STRINGARRAYFILE = fopen((const char*)STRINGARRAYFILE, "w");
if(STRINGARRAYFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8343, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fputs("char* b2c_stringarray[] = {\n", STRINGARRAYFILE);
    FLOATARRAYFILE = fopen((const char*)FLOATARRAYFILE, "w");
if(FLOATARRAYFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8346, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fputs("double b2c_floatarray[] = {\n", FLOATARRAYFILE);
    if( INSTR(g_LDFLAGS, "shared") ){
    fputs("/************************************/\n", g_CFILE);
    fputs("/* Init function for shared objects */\n", g_CFILE);
    fputs("/************************************/\n", g_CFILE);
    fputs("#ifdef __GNUC__\n", g_CFILE);
    fputs("static int BaCon_init() __attribute__((constructor));\n", g_CFILE);
    fputs("#endif\n", g_CFILE);
    fputs("int BaCon_init(void){int argc=0; char *argv[2] = { NULL };\n", g_CFILE);
    } else {
    fputs("/****************************/\n", g_CFILE);
    fputs("/* Main program starts here */\n", g_CFILE);
    fputs("/****************************/\n", g_CFILE);
    fputs("int main(int argc, char **argv){\n", g_CFILE);
    }
fputs("setvbuf(stdout, NULL, _IOLBF, 0);\n", g_CFILE);
fputs("atexit(__b2c_str_free);\n", g_CFILE);
fputs("b2c_set_stack_size();\n", g_CFILE);
fprintf(g_CFILE, "if(argc>0) { b2c_me_var%s = b2c_CopyString(b2c_me_var%s, argv[0]); }\n", g_STRINGSIGN, g_STRINGSIGN);
fprintf(g_CFILE, "if(argc==2 && !strncmp(argv[1], \"-bacon\", 6)) { fprintf(stderr, \"Converted by %s.\\n\", COMPILED_BY_WHICH_BACON%s); exit(EXIT_SUCCESS); }\n", g_STRINGSIGN);
fputs("/* Setup the reserved variable 'ARGUMENT' */\n", g_CFILE);
fprintf(g_CFILE, "b2c_argument(&ARGUMENT%s, argc, argv);\n", g_STRINGSIGN);
fputs("/* By default seed random generator */\n", g_CFILE);
fputs("srandom((unsigned int)time(NULL));\n", g_CFILE);
fputs("/* Determine current moment and keep it for timer function */\n", g_CFILE);
fputs("b2c_nanotimer(1); b2c_timer(1);\n", g_CFILE);
fputs("/* Setup error signal handling */\n", g_CFILE);
fputs("signal(SIGILL, b2c_catch_signal);\n", g_CFILE);
fputs("signal(SIGABRT, b2c_catch_signal);\n", g_CFILE);
fputs("signal(SIGFPE, b2c_catch_signal);\n", g_CFILE);
fputs("signal(SIGSEGV, b2c_catch_signal);\n", g_CFILE);
fputs("/* Rest of the program */\n", g_CFILE);
    g_IMPORTED = b2c_CopyString(g_IMPORTED, (char*) "");
    if( ISTRUE(g_LOWERCASE) ){
        b2c_forin_kwd_string = b2c_CopyString(b2c_forin_kwd_string, Stat); b2c_forin_kwd_string_org = b2c_forin_kwd_string;
        b2c_forin_kwd_step = b2c_CopyString(b2c_forin_kwd_step, "|");
        b2c_forin_kwd_ptr = b2c_for_amount(b2c_forin_kwd_string, b2c_forin_kwd_step);
        for(; b2c_forin_kwd_ptr > 0; b2c_forin_kwd_ptr--) { b2c_for_item(&b2c_forin_kwd_string_org, b2c_forin_kwd_step, &kwd);
            if( __b2c__STRCMP(kwd ,  "CONST") != 0  AND  __b2c__STRCMP(kwd ,  "STATIC") != 0 ){
                mapping = F_CONCAT(mapping, mapping , " -D" , LCASE(kwd) , "=" , kwd);
            }
        }
        b2c_forin_kwd_string = b2c_CopyString(b2c_forin_kwd_string, EXTRACT(Func, "\\")); b2c_forin_kwd_string_org = b2c_forin_kwd_string;
        b2c_forin_kwd_step = b2c_CopyString(b2c_forin_kwd_step, "|");
        b2c_forin_kwd_ptr = b2c_for_amount(b2c_forin_kwd_string, b2c_forin_kwd_step);
        for(; b2c_forin_kwd_ptr > 0; b2c_forin_kwd_ptr--) { b2c_for_item(&b2c_forin_kwd_string_org, b2c_forin_kwd_step, &kwd);
            if( __b2c__STRCMP(kwd ,  "INT") != 0 ){
                mapping = F_CONCAT(mapping, mapping , " -D" , LCASE(kwd) , "=" , kwd);
            }
        }
        b2c_forin_kwd_string = b2c_CopyString(b2c_forin_kwd_string, EXTRACT(Var, "\\")); b2c_forin_kwd_string_org = b2c_forin_kwd_string;
        b2c_forin_kwd_step = b2c_CopyString(b2c_forin_kwd_step, "|");
        b2c_forin_kwd_ptr = b2c_for_amount(b2c_forin_kwd_string, b2c_forin_kwd_step);
        for(; b2c_forin_kwd_ptr > 0; b2c_forin_kwd_ptr--) { b2c_for_item(&b2c_forin_kwd_string_org, b2c_forin_kwd_step, &kwd);
            mapping = F_CONCAT(mapping, mapping , " -D" , LCASE(kwd) , "=" , kwd) ;
        }
        g_CPP=(long)( 1);
    } else {
        mapping = b2c_CopyString(mapping, (char*) "");
    }
    if( ISTRUE(g_CPP) ){
        if( ISTRUE(LEN(EXEC("command -v cpp 2>/dev/null"))) ){
        fprintf(stdout, "Preprocessing '%s'... ", g_SOURCEFILE);
            fflush(stdout);
            src_tmp = fopen((const char*)CONCAT( g_SOURCEFILE , ".tmp" ), "w");
        if(src_tmp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8449, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            src_in = fopen((const char*)g_SOURCEFILE, "r");
        if(src_in == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8450, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            while( NOT(ENDFILE(src_in)) ){
                b2c_readln(&b2c_assign, src_in);
                line = b2c_CopyString(line, b2c_assign);
                __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
                if( __b2c__STRCMP(LEFT(line, 1) ,  "#") == 0 ){
                fprintf(src_tmp, "%s\n", line);
                } else {
                fprintf(src_tmp, "%s\n", CONCAT( "@" , line , "@" ));
                }
            }
            fclose(src_in);
            fclose( src_tmp);
        RETVAL = system(CONCAT( "cpp -w -P " , mapping , " " , g_SOURCEFILE , ".tmp " , g_SOURCEFILE , ".cpp") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
            src_cpp = fopen((const char*)CONCAT( g_SOURCEFILE , ".cpp" ), "r");
        if(src_cpp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8462, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            src_out = fopen((const char*)CONCAT( g_SOURCEFILE , ".bac2" ), "w");
        if(src_out == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8463, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            while( NOT(ENDFILE(src_cpp)) ){
                b2c_readln(&b2c_assign, src_cpp);
                line = b2c_CopyString(line, b2c_assign);
                __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
            fprintf(src_out, "%s\n", MID(line, 2, LEN(line)-2));
            }
            fclose(src_out);
            fclose( src_cpp);
            FEED = F_CONCAT(FEED, g_SOURCEFILE , ".bac2") ;
            g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_SOURCEFILE , ".cpp" , " " , g_SOURCEFILE , ".tmp" , " " , g_SOURCEFILE , ".bac2") ;
        fputs("done.\n", stdout);
        } else {
        fputs("System error: the C Preprocessor 'cpp' not found on this system! Exiting...\n", stderr);
            exit(1);
        }
    } else {
        FEED = b2c_CopyString(FEED, (char*) g_SOURCEFILE);
    }
    g_CURFILE = b2c_CopyString(g_CURFILE, (char*) g_SOURCEFILE);
    total = b2c_CopyString(total, (char*) "");
    g_COUNTER=(long)( 0);
    g_TOTAL_LINES=(long)( 0);
    Save_Main_Var( CONCAT("b2c_loop_result" , g_STRINGSIGN) , "char*");
    Save_Main_Var("b2c_loop_result", "long");
    Save_Main_Var("ERROR", "int");
    Save_Main_Var("_", "long");
    g_SOURCEFILE = fopen((const char*)FEED, "r");
if(g_SOURCEFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8496, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(stdout, "\rConverting '%s'... ", g_SOURCEFILE);
    fflush(stdout);
    do{
        b2c_readln(&b2c_assign, g_SOURCEFILE);
        line = b2c_CopyString(line, b2c_assign);
        __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
        line = F_CHOP(line,line);
        g_COUNTER = g_COUNTER + (1);
        if( (LEN(line) )> 0 ){
            if( NOT(g_QUIET) ){
            fprintf(stdout, "\rConverting '%s'... %s%s", g_SOURCEFILE, STR( g_COUNTER), EL);
                fflush(stdout);
            }
            if( __b2c__STRCMP(RIGHT(line, 2) ,  " \\") == 0  AND  __b2c__STRCMP(LEFT(line, 1) ,  CHR(39)) != 0  AND  NOT(REGEX(line, "^REM[[:space:]]+")) ){
                total = F_CONCAT(total, total , LEFT(line, LEN(line) - 1)) ;
            } else {
                total = F_CONCAT(total, total , line) ;
                if( __b2c__STRCMP(LEFT(total, 1) ,  CHR(39)) != 0 ){
                    if( g_DEBUG ){
                    fprintf(g_CFILE, "/* line %s \"%s\" */\n", STR( g_COUNTER), g_SOURCEFILE);
                    fprintf(g_HFILE, "/* line %s \"%s\" */\n", STR( g_COUNTER), g_SOURCEFILE);
                    } else {
                    fprintf(g_CFILE, "#line %s \"%s\"\n", STR( g_COUNTER), g_SOURCEFILE);
                    fprintf(g_HFILE, "#line %s \"%s\"\n", STR( g_COUNTER), g_SOURCEFILE);
                    }
                    Tokenize(total);
                    total = b2c_CopyString(total, (char*) EXTRACT(total, "\\\\"));
                    total = b2c_CopyString(total, (char*) EXTRACT(total, "\\\""));
                    g_DEPEND = F_CONCAT(g_DEPEND, g_DEPEND , EXTRACT(total, "\"[^\"]*\"", TRUE) , NL) ;
                }
                total = b2c_CopyString(total, (char*) "");
            }
        }
    } while(!( ENDFILE(g_SOURCEFILE) ));
    fclose(g_SOURCEFILE);
    if( g_DEBUG == 1 ){
    fputs("__b2c_str_realloc_debug_string();\n", g_CFILE);
    fputs("__b2c_mempool_realloc_debug();\n", g_CFILE);
    }
    if( g_CATCH_USED == 1 ){
    fputs("__B2C__PROGRAM__EXIT:\n", g_CFILE);
    }
fputs("return(0);\n", g_CFILE);
fputs("}\n", g_CFILE);
fputs(" \"\" };\n", STRINGARRAYFILE);
fputs(" 0.0};\n", FLOATARRAYFILE);
    g_TOTAL_LINES = g_TOTAL_LINES + ( g_COUNTER);
    ttime=(long)( TIMER-starttime);
    msec_time = (char*)__b2c_str_realloc(msec_time, (512+1)*sizeof(char));
    snprintf(msec_time, 512+1, "%.3ld", MOD(ttime, 1000)); __b2c__SETLEN(msec_time, strlen(msec_time));
fprintf(stdout, "\rConverting '%s'... done, %s lines were processed in %s.%s seconds.\n", g_SOURCEFILE, STR( g_TOTAL_LINES), STR( FLOOR(ttime/1000)), msec_time);
    if( g_DEBUG == 1 ){
        Debug_Vars();
    }
    if( FILEEXISTS(SRCARRAYFILE) ){
    fprintf(g_HFILE, "#include \"%s\"\n", SRCARRAYFILE);
        g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , SRCARRAYFILE) ;
    }
    if( LEN(g_LOCAL_SBUFFER) ){
    fprintf(g_HFILE, "%s\n", g_LOCAL_SBUFFER);
    }
    b2c_forin_incfiles_string = b2c_CopyString(b2c_forin_incfiles_string, g_INCLUDE_FILES); b2c_forin_incfiles_string_org = b2c_forin_incfiles_string;
    b2c_forin_incfiles_step = b2c_CopyString(b2c_forin_incfiles_step, b2c_option_delim);
    b2c_forin_incfiles_ptr = b2c_for_amount(b2c_forin_incfiles_string, b2c_forin_incfiles_step);
    for(; b2c_forin_incfiles_ptr > 0; b2c_forin_incfiles_ptr--) { b2c_for_item(&b2c_forin_incfiles_string_org, b2c_forin_incfiles_step, &incfiles);
        if( (LEN(incfiles) )> 0 ){
        fprintf(g_HFILE, "#include \"%s%s\n", incfiles, CHR(34));
        }
    }
fputs("void b2c_set_stack_size(void) { struct rlimit rl; getrlimit (RLIMIT_STACK, &rl); rl.rlim_cur = RLIM_INFINITY; setrlimit (RLIMIT_STACK, &rl); }\n", g_HFILE);
    if( LEN(g_GLOBALARRAYS) ){
    fprintf(g_HFILE, "void s_free(void) {%s}\n", g_GLOBALARRAYS);
    }
    if( REGEX(g_DEPEND, "COLLECT[[:space:]]|TREE[[:space:]]") ){
    fputs("void b2c_twalk_free(void) { if (b2c_twalk_array) { free (b2c_twalk_array); } }\n", g_HFILE);
    }
    fclose(g_HFILE);
fprintf(g_GENERIC, "%s\n", g_PRAGMA_INCLUDE);
    if( LEN(g_INCFILES) ){
    fprintf(g_GENERIC, "%s\n", REPLACE(g_INCFILES, "#include", CONCAT( NL , "#include") ));
    }
fputs("#include <stdio.h>\n", g_GENERIC);
fputs("#include <stdlib.h>\n", g_GENERIC);
fputs("#include <stdarg.h>\n", g_GENERIC);
fputs("#include <stdint.h>\n", g_GENERIC);
fputs("#include <libgen.h>\n", g_GENERIC);
fputs("#include <limits.h>\n", g_GENERIC);
fputs("#include <float.h>\n", g_GENERIC);
fputs("#include <sys/resource.h>\n", g_GENERIC);
fputs("#include <sys/time.h>\n", g_GENERIC);
fputs("#include <sys/stat.h>\n", g_GENERIC);
fputs("#include <sys/types.h>\n", g_GENERIC);
fputs("#include <sys/wait.h>\n", g_GENERIC);
fputs("#include <sys/socket.h>\n", g_GENERIC);
fputs("#include <sys/utsname.h>\n", g_GENERIC);
fputs("#include <sys/ioctl.h>\n", g_GENERIC);
fputs("#include <dirent.h>\n", g_GENERIC);
fputs("#include <setjmp.h>\n", g_GENERIC);
fputs("#include <netdb.h>\n", g_GENERIC);
    if( INSTR(OS, "BSD") ){
    fputs("#include <netinet/in.h>\n", g_GENERIC);
    fputs("#define strcat(x, y) __b2c_strlcat(x, y)\n", g_GENERIC);
    fputs("#define strcpy(x, y) __b2c_strlcpy(x, y)\n", g_GENERIC);
    fputs("#define random(void) arc4random(void)\n", g_GENERIC);
    }
fputs("#include <arpa/inet.h>\n", g_GENERIC);
fputs("#include <signal.h>\n", g_GENERIC);
    if( LEN(g_PRAGMA_REGEX) ){
        if( NOT(REGEX(g_PRAGMA_REGEX, " INCLUDE ")) ){
            kwd = b2c_CopyString(kwd, (char*) HEAD(g_PRAGMA_REGEX));
            if( INSTR(kwd, "tre") ){
            fputs("#include <tre/regex.h>\n", g_GENERIC);
            } else if( INSTR(kwd, "pcre") ){
            fputs("#include <pcreposix.h>\n", g_GENERIC);
            } else if( INSTR(kwd, "onig") ){
            fputs("#include <onigposix.h>\n", g_GENERIC);
            }
        } else {
            kwd = F_MID(kwd,g_PRAGMA_REGEX, INSTR(g_PRAGMA_REGEX, " INCLUDE ")+9);
        fprintf(g_GENERIC, "#include %s\n", HEAD(kwd));
        }
    } else {
    fputs("#include <regex.h>\n", g_GENERIC);
    }
    if( LEN(g_INC_TLS) ){
        if( REGEX(g_INC_TLS, " INCLUDE ") ){
            b2c_forin_kwd_string = b2c_CopyString(b2c_forin_kwd_string, MID(g_INC_TLS, INSTR(g_INC_TLS, " INCLUDE ")+9)); b2c_forin_kwd_string_org = b2c_forin_kwd_string;
            b2c_forin_kwd_step = b2c_CopyString(b2c_forin_kwd_step, b2c_option_delim);
            b2c_forin_kwd_ptr = b2c_for_amount(b2c_forin_kwd_string, b2c_forin_kwd_step);
            for(; b2c_forin_kwd_ptr > 0; b2c_forin_kwd_ptr--) { b2c_for_item(&b2c_forin_kwd_string_org, b2c_forin_kwd_step, &kwd);
            fprintf(g_GENERIC, "#include %s\n", kwd);
            }
        } else {
        fprintf(g_GENERIC, "%s\n", g_INC_TLS);
        }
    }
fputs("#include <fcntl.h>\n", g_GENERIC);
fputs("#include <math.h>\n", g_GENERIC);
fputs("#include <unistd.h>\n", g_GENERIC);
fputs("#include <string.h>\n", g_GENERIC);
fputs("#include <ctype.h>\n", g_GENERIC);
fputs("#include <wctype.h>\n", g_GENERIC);
fputs("#include <locale.h>\n", g_GENERIC);
fputs("#include <dlfcn.h>\n", g_GENERIC);
fputs("#include <errno.h>\n", g_GENERIC);
fputs("#include <termios.h>\n", g_GENERIC);
fputs("#include <time.h>\n", g_GENERIC);
fputs("#include <fts.h>\n", g_GENERIC);
fputs("#define ENTRY ENTRY_libc\n", g_GENERIC);
fputs("#include <search.h>\n", g_GENERIC);
fputs("#undef ENTRY\n", g_GENERIC);
fputs("/* Undefine all symbols which happen to be BaCon keywords */\n", g_GENERIC);
    b2c_forin_kwd_string = b2c_CopyString(b2c_forin_kwd_string, SORT( CONCAT(Stat , EXTRACT(Func, "\\") , EXTRACT(Var, "\\")) , "|")); b2c_forin_kwd_string_org = b2c_forin_kwd_string;
    b2c_forin_kwd_step = b2c_CopyString(b2c_forin_kwd_step, "|");
    b2c_forin_kwd_ptr = b2c_for_amount(b2c_forin_kwd_string, b2c_forin_kwd_step);
    for(; b2c_forin_kwd_ptr > 0; b2c_forin_kwd_ptr--) { b2c_for_item(&b2c_forin_kwd_string_org, b2c_forin_kwd_step, &kwd);
        if( __b2c__STRCMP(RIGHT(kwd, 1) ,  "$") != 0  AND  __b2c__STRCMP(kwd ,  "NULL") != 0 ){
        fprintf(g_GENERIC, "#undef %s\n", kwd);
        }
    }
fputs("/* Declarations for internal variables */\n", g_GENERIC);
fputs("jmp_buf b2c_jump = { 0 };\n", g_GENERIC);
fputs("int b2c_trap = 1;\n", g_GENERIC);
fputs("int b2c_catch_set_backup = 0, b2c_catch_set = 0;\n", g_GENERIC);
fputs("void (*b2c_error_callback)(char*, char*, long) = NULL;\n", g_GENERIC);
fputs("int b2c_option_compare = 0;\n", g_GENERIC);
fputs("int b2c_option_quoted = 1;\n", g_GENERIC);
fputs("int b2c_option_dq = 34;\n", g_GENERIC);
fputs("int b2c_option_esc = 92;\n", g_GENERIC);
fputs("int b2c_option_utf8 = 0;\n", g_GENERIC);
fputs("int b2c_option_proper = 0;\n", g_GENERIC);
fputs("int b2c_option_tls = 0;\n", g_GENERIC);
fputs("char *b2c_option_delim = \" \";\n", g_GENERIC);
fputs("int b2c_option_memstream = 0;\n", g_GENERIC);
fputs("int b2c_option_startpoint = 0;\n", g_GENERIC);
fputs("int b2c_option_open = O_RDWR|O_NOCTTY|O_SYNC;\n", g_GENERIC);
fputs("int b2c_collapse = 0;\n", g_GENERIC);
fputs("int b2c_break_ctr = 0;\n", g_GENERIC);
fputs("int b2c_break_flag = 0;\n", g_GENERIC);
fputs("char b2c_chop_default[] = \"\\r\\n\\t\\f\\v \";\n", g_GENERIC);
fputs("int b2c_stringarray_ptr = 0;\n", g_GENERIC);
fputs("int b2c_floatarray_ptr = 0;\n", g_GENERIC);
fputs("long b2c_ctr = 0;\n", g_GENERIC);
fprintf(g_GENERIC, "#define __b2c_STRING_FUNC (%s)\n", STR( g_STRING_FUNC));
fputs("#define __b2c_EMPTYSTRING (char*)\"\"\n", g_GENERIC);
fprintf(g_GENERIC, "jmp_buf b2c_gosub_buffer[%s];\n", STR( g_MAX_RBUFFERS));
fputs("int b2c_gosub_buffer_ptr = -1;\n", g_GENERIC);
fprintf(g_GENERIC, "char* b2c_loop_result%s = NULL;\n", g_STRINGSIGN);
fputs("long b2c_loop_result = 0;\n", g_GENERIC);
fputs("jmp_buf b2c_data_jump, b2c_loop1, b2c_loop2;\n", g_GENERIC);
fputs("char *b2c_assign = NULL;\n", g_GENERIC);
fputs("void **b2c_assign2 = NULL;\n", g_GENERIC);
fputs("int b2c_counter = 0;\n", g_GENERIC);
fputs("char **b2c_stack = NULL;\n", g_GENERIC);
fputs("void **b2c_twalk_array = NULL; int b2c_twalk_idx = 0;\n", g_GENERIC);
fputs("extern char *b2c_stringarray[];\n", g_GENERIC);
fputs("extern double b2c_floatarray[];\n", g_GENERIC);
fprintf(g_GENERIC, "char *b2c_me_var%s = NULL;\n", g_STRINGSIGN);
fputs("/* Declarations for BaCon variables */\n", g_GENERIC);
fprintf(g_GENERIC, "char *ARGUMENT%s = NULL;\n", g_STRINGSIGN);
fputs("int ERROR = 0;\n", g_GENERIC);
fputs("int RETVAL = 0;\n", g_GENERIC);
fputs("int REGLEN = 0;\n", g_GENERIC);
fputs("int SP = 0;\n", g_GENERIC);
fputs("long _ = 0;\n", g_GENERIC);
fprintf(g_GENERIC, "char VERSION%s[] = \"%s\";\n", g_STRINGSIGN, g_VERSION);
fputs("/* Prototypes for internal functions */\n", g_GENERIC);
fputs("int b2c_strcmp(const char*, const char*);\n", g_GENERIC);
fputs("char *b2c_strdup(char*);\n", g_GENERIC);
fputs("char *b2c_strndup(char*, size_t);\n", g_GENERIC);
fputs("void *__b2c_mempool_realloc_core(void*, size_t, int);\n", g_GENERIC);
fputs("void* __b2c_str_realloc_core(char*, size_t, int);\n", g_GENERIC);
fputs("long b2c_delim_engine_core(int, int, long*, char*, char*, long, int);\n", g_GENERIC);
    if( INSTR(OS, "BSD") ){
    fputs("char *__b2c_strlcat(char*, const char*);\n", g_GENERIC);
    fputs("char *__b2c_strlcpy(char*, const char*);\n", g_GENERIC);
    }
fputs("/* Prototypes for BaCon functions */\n", g_GENERIC);
fprintf(g_GENERIC, "char *ERR%s(int);\n", g_STRINGSIGN);
fputs("int __b2c_utf8_conv(int,char*);\n", g_GENERIC);
fputs("char *__b2c_Copy_String_core(char*, char*, int);\n", g_GENERIC);
fputs("char* __b2c_Swap_String(char**, char**);\n", g_GENERIC);
fputs("unsigned long b2c_len(const char*);\n", g_GENERIC);
fputs("unsigned long b2c_ulen(int,char*,char*,char*,int);\n", g_GENERIC);
fputs("unsigned long b2c_blen(int,char*,char*,char*,long,int);\n", g_GENERIC);
fputs("unsigned long b2c_ucs2_clen(int,char*,char*,char*,int);\n", g_GENERIC);
fputs("long b2c_regex_core(int, int, char*, char*, char*);\n", g_GENERIC);
fputs("char *b2c_extract_core(int, int, char*, char*, char*, int);\n", g_GENERIC);
fputs("char *b2c_replace_core(int, int, char*, char*, char*, char*, int);\n", g_GENERIC);
fputs("char *b2c_walk_core(int, int, char*, char*, int, char*, int, char*);\n", g_GENERIC);
fputs("void __b2c_str_free(void);\n", g_GENERIC);
fputs("void s_free(void);\n", g_GENERIC);
fputs("void b2c_twalk_free(void);\n", g_GENERIC);
fputs("int b2c_collect(void*, void***, int, int);\n", g_GENERIC);
fputs("/* Internal macro definitions */\n", g_GENERIC);
fputs("#define __b2c__MEMTYPE char\n", g_GENERIC);
fputs("#define __b2c__STRCMP b2c_strcmp\n", g_GENERIC);
fputs("#define __b2c__BUFOFFSET 16\n", g_GENERIC);
fputs("#define __b2c__LBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+8))\n", g_GENERIC);
fputs("#define __b2c__RBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+4))\n", g_GENERIC);
fputs("#define __b2c__STRFREE(x) if(__b2c_str_realloc_get_string(x)) { if(!__b2c_mempool_realloc_free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x))) { free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x)); } __b2c_str_realloc_del_string(x); } else { if(x) { free(x); } }\n", g_GENERIC);
fputs("#define __b2c__SETLEN(x,y) *(uint32_t*)(x-__b2c__BUFOFFSET) = y;\n", g_GENERIC);
fputs("#define __b2c__FUNCSELECT2(_1, _2, x, ...) x\n", g_GENERIC);
fputs("#define __b2c__FUNCSELECT3(_1, _2, _3, x, ...) x\n", g_GENERIC);
fputs("#define __b2c__FUNCSELECT4(_1, _2, _3, _4, x, ...) x\n", g_GENERIC);
fputs("#define __b2c__FUNCSELECT5(_1, _2, _3, _4, _5, x, ...) x\n", g_GENERIC);
fputs("#define __b2c__FUNCSELECT10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _0, x, ...) x\n", g_GENERIC);
fputs("#define __b2c_mempool_realloc_debug() __b2c_mempool_realloc_core(NULL, 0, 0)\n", g_GENERIC);
fputs("#define __b2c_mempool_realloc_free(x) __b2c_mempool_realloc_core(x, 0, 1)\n", g_GENERIC);
fputs("#define __b2c_mempool_realloc_in_block(x) __b2c_mempool_realloc_core(x, 0, 2)\n", g_GENERIC);
fputs("#define __b2c_mempool_realloc(x, y) __b2c_mempool_realloc_core(x, y, 3)\n", g_GENERIC);
fputs("#define __b2c_str_realloc(x, y) __b2c_str_realloc_core(x, y, 0)\n", g_GENERIC);
fputs("#define __b2c_str_realloc_left(x, y) __b2c_str_realloc_core(x, y, 1)\n", g_GENERIC);
fputs("#define __b2c_str_realloc_add_string(x) __b2c_str_realloc_core((char*)x, 0, 2)\n", g_GENERIC);
fputs("#define __b2c_str_realloc_del_string(x) __b2c_str_realloc_core((char*)x, 0, 3)\n", g_GENERIC);
fputs("#define __b2c_str_realloc_get_string(x) (x!=NULL && __b2c_str_realloc_core((char*)x, 0, 4))\n", g_GENERIC);
fputs("#define __b2c_str_realloc_free_string() __b2c_str_realloc_core(NULL, 0, 6)\n", g_GENERIC);
fputs("#define __b2c_str_realloc_debug_string() __b2c_str_realloc_core(NULL, 0, 5)\n", g_GENERIC);
fputs("#define b2c_CopyString(x, y) __b2c_Copy_String_core(x, y, -1)\n", g_GENERIC);
fputs("#define __b2c_Copy_N_String(x, y, z) __b2c_Copy_String_core(x, y, z)\n", g_GENERIC);
fputs("#define b2c_delim_engine(x, y, z, a, b) b2c_delim_engine_core(1, x, y, z, a, b, 0)\n", g_GENERIC);
fputs("#define b2c_delim_engine_cache(x, y, z, a, b) b2c_delim_engine_core(1, x, y, z, a, b, 1)\n", g_GENERIC);
fputs("#define b2c_delim_engine_free() b2c_delim_engine_core(0, 0, NULL, NULL, NULL, 0, 0)\n", g_GENERIC);
fputs("#define b2c_regex(x, y, z, q) b2c_regex_core(1, x, y, z, q)\n", g_GENERIC);
fputs("#define b2c_regex_free() b2c_regex_core(0, 0, NULL, NULL, NULL)\n", g_GENERIC);
fputs("#define b2c_extract(x, y, z, q, r) b2c_extract_core(1, x, y, z, q, r)\n", g_GENERIC);
fputs("#define b2c_extract_free() b2c_extract_core(0, 0, NULL, NULL, NULL, 0)\n", g_GENERIC);
fputs("#define b2c_replace(x, y, z, q, r, s) b2c_replace_core(1, x, y, z, q, r, s)\n", g_GENERIC);
fputs("#define b2c_replace_free() b2c_replace_core(0, 0, NULL, NULL, NULL, NULL, 0)\n", g_GENERIC);
fputs("#define b2c_walk(x, y, z, a, b, c, d) b2c_walk_core(1, x, y, z, a, b, c, d)\n", g_GENERIC);
fputs("#define b2c_walk_free() b2c_walk_core(0, 0, NULL, NULL, 0, NULL, 0, NULL)\n", g_GENERIC);
fputs("#if INTPTR_MAX == INT64_MAX\n", g_GENERIC);
fputs("#define HASH_FUNC (uint64_t)__b2c__HashFNV1a_64\n", g_GENERIC);
fputs("#elif INTPTR_MAX == INT32_MAX\n", g_GENERIC);
fputs("#define HASH_FUNC (uint32_t)__b2c__HashFNV1a_32\n", g_GENERIC);
fputs("#else\n", g_GENERIC);
fputs("#define HASH_FUNC (uint16_t)__b2c__HashFNV1a_16_new\n", g_GENERIC);
fputs("#endif\n", g_GENERIC);
fprintf(g_GENERIC, "#define COMPILED_BY_WHICH_BACON%s %sBaCon executable %s%s\n", g_STRINGSIGN, CHR(34), g_VERSION, CHR(34));
fprintf(g_GENERIC, "#define RUNTIMEERROR(a, x, y, z, q) do { if(!b2c_catch_set) { if(b2c_trap) { fprintf(stderr, \"Runtime error: statement '%s' at line %d in '%s': %s\\n\", a, x, y, ERR%s(z)); exit(z); } if(b2c_error_callback){ (*b2c_error_callback)(a,y,x); } } else { if(!setjmp(b2c_jump)) { goto q; } } } while(0)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define RUNTIMEFERR(a, x, y, z) do { if(b2c_trap) { fprintf(stderr, \"Runtime error: function '%s' at line %d in '%s': %s\\n\", a, z, y, ERR%s(x)); exit(x); } if(b2c_error_callback) { (*b2c_error_callback)(a,y,z); } } while(0)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define RUNTIMEDEBUG(x, y, z) (b2c_getch() == 27 ? fprintf(stderr, \"TRACE OFF - exiting trace mode.\\n\") && b2c_stop_program() : fprintf(stderr, \"File '%s' line %d: %s\\n\", #x, y, z)%s )\n", g_MONITOR);
fputs("int b2c_stop_program(void) { exit(EXIT_SUCCESS); return(1); }\n", g_GENERIC);
fputs("/* BaCon functions */\n", g_GENERIC);
fputs("#define ABS(x) fabs((double)x)\n", g_GENERIC);
fputs("#define ACOS(x) acos((double)x)\n", g_GENERIC);
fputs("#define ADDRESS(x) (uintptr_t)(&x)\n", g_GENERIC);
fputs("#define __b2c__ALIGN3(x, y, z) b2c_align(__LINE__, __FILE__, x, y, z, 0)\n", g_GENERIC);
fputs("#define __b2c__ALIGN4(x, y, z, f) b2c_align(__LINE__, __FILE__, x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define ALIGN%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__ALIGN4, __b2c__ALIGN3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__AMOUNT1(x) b2c_amount(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__AMOUNT2(x, y) b2c_amount(x, y)\n", g_GENERIC);
fputs("#define AMOUNT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__AMOUNT2, __b2c__AMOUNT1)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define AND &&\n", g_GENERIC);
fputs("#define __b2c__APPEND3(x, y, z) b2c_append(NULL, 0, x, y, z, NULL)\n", g_GENERIC);
fputs("#define __b2c__APPEND4(x, y, z, f) b2c_append(NULL, 0, x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define APPEND%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__APPEND4, __b2c__APPEND3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__FAPPEND4(s, x, y, z) b2c_append(&s, 1, x, y, z, NULL)\n", g_GENERIC);
fputs("#define __b2c__FAPPEND5(s, x, y, z, f) b2c_append(&s, 1, x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define F_APPEND%s(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__FAPPEND5, __b2c__FAPPEND4)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define ASC(x) b2c_asc(x)\n", g_GENERIC);
fputs("#define ASIN(x) asin((double)(x))\n", g_GENERIC);
fputs("#define ATN(x) atan((double)(x))\n", g_GENERIC);
fputs("#define ATN2(x,y) atan2((double)(x),(double)(y))\n", g_GENERIC);
fprintf(g_GENERIC, "#define B64DEC%s(x) b2c_b64dec(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define __b2c__B64ENC1(x) b2c_b64enc(x, 0)\n", g_GENERIC);
fputs("#define __b2c__B64ENC2(x, y) b2c_b64enc((char*)x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define B64ENC%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__B64ENC2, __b2c__B64ENC1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__BASENAME1(x) b2c_dirname(__LINE__, __FILE__, 1, x, 0)\n", g_GENERIC);
fputs("#define __b2c__BASENAME2(x, y) b2c_dirname(__LINE__, __FILE__, 1, x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define BASENAME%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__BASENAME2, __b2c__BASENAME1)(__VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define BIN%s(x) b2c_bin(sizeof(__b2c__MEMTYPE), x)\n", g_STRINGSIGN);
fputs("#define BIT(x) b2c_bit(x)\n", g_GENERIC);
fputs("#define BLOAD(x) (void*)b2c_load(1, __LINE__, __FILE__, x)\n", g_GENERIC);
fputs("#define __b2c__BYTELEN2(x, y) b2c_blen(__LINE__, __FILE__, \"BYTELEN\", x, y, 0)\n", g_GENERIC);
fputs("#define __b2c__BYTELEN3(x, y, z) b2c_blen(__LINE__, __FILE__, \"BYTELEN\", x, y, z)\n", g_GENERIC);
fputs("#define BYTELEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__BYTELEN3, __b2c__BYTELEN2)(__VA_ARGS__)\n", g_GENERIC);
fprintf(g_GENERIC, "#define CA%s(x) b2c_ca(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define CN%s(x) b2c_cn(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define CIPHER%s(x) b2c_cipher(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define VERIFY(x, y) ((SSL*)x == NULL ? -1 : (long)SSL_get_verify_result((SSL*)x) )\n", g_GENERIC);
fputs("#define ACCEPT(x) b2c_accept(__LINE__, __FILE__, b2c_caprivate, b2c_caserver, x)\n", g_GENERIC);
fputs("#define CEIL(x) (double)ceil(x)\n", g_GENERIC);
fputs("#define __b2c__CHANGE3(x, y, z) b2c_change(x, y, z, NULL)\n", g_GENERIC);
fputs("#define __b2c__CHANGE4(x, y, z, f) b2c_change(x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define CHANGE%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CHANGE4, __b2c__CHANGE3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__CHOP1(x) b2c_chop(NULL, 0, x, NULL, 0)\n", g_GENERIC);
fputs("#define __b2c__CHOP2(x, y) b2c_chop(NULL, 0, x, y, 0)\n", g_GENERIC);
fputs("#define __b2c__CHOP3(x, y, z) b2c_chop(NULL, 0, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define CHOP%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__CHOP3, __b2c__CHOP2, __b2c__CHOP1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__FCHOP2(s, x) b2c_chop(&s, 1, x, NULL, 0)\n", g_GENERIC);
fputs("#define __b2c__FCHOP3(s, x, y) b2c_chop(&s, 1, x, y, 0)\n", g_GENERIC);
fputs("#define __b2c__FCHOP4(s, x, y, z) b2c_chop(&s, 1, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define F_CHOP%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FCHOP4, __b2c__FCHOP3, __b2c__FCHOP2)(__VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define CHR%s(x) b2c_asc2char(x)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define UTF8%s(x) b2c_asc2utf8(x)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define CL%s \"\\033[2K\"\n", g_STRINGSIGN);
fputs("#define CMDLINE(x) b2c_getopt(argc, argv, x)\n", g_GENERIC);
fprintf(g_GENERIC, "#define COIL%s(...) ( !setjmp(b2c_loop1) ? b2c_loop_helper(b2c_loop2) : b2c_loop_result%s )\n", g_STRINGSIGN, g_STRINGSIGN);
fputs("#define __b2c__COLLAPSE1(x) b2c_collapse_func(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__COLLAPSE2(x, y) b2c_collapse_func(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define COLLAPSE%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__COLLAPSE2, __b2c__COLLAPSE1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define COLUMNS b2c_screen(0)\n", g_GENERIC);
fprintf(g_GENERIC, "#define CONCAT%s(...) b2c_concat(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define F_CONCAT%s(...) b2c_concat2(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define COS(x) cos((double)(x))\n", g_GENERIC);
fputs("#define COUNT(x, y) b2c_count(__LINE__, __FILE__, x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define CR%s \"\\r\"\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define CURDIR%s b2c_curdir()\n", g_STRINGSIGN);
fputs("#define __b2c__CUT3(x, y, z) b2c_cut(x, y, z, NULL)\n", g_GENERIC);
fputs("#define __b2c__CUT4(x, y, z, f) b2c_cut(x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define CUT%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CUT4, __b2c__CUT3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define DAY(x) b2c_time(x, 1)\n", g_GENERIC);
fputs("#define __b2c__DEC1(x) b2c_hex2dec(__LINE__, __FILE__, x, 0)\n", g_GENERIC);
fputs("#define __b2c__DEC2(x, y) b2c_hex2dec(__LINE__, __FILE__, x, y)\n", g_GENERIC);
fputs("#define DEC(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__DEC2, __b2c__DEC1)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define DEG(x) (x*180/PI)\n", g_GENERIC);
fputs("#define __b2c__DEL2(x, y) b2c_del(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__DEL3(x, y, z) b2c_del(x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define DEL%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__DEL3, __b2c__DEL2)(__VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define DELIM%s(x, y, z) b2c_delim(x, y, z)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define DIRNAME%s(x) b2c_dirname(__LINE__, __FILE__, 2, x, 0)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define DLE%s \"\\r\\n\"\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define EDITBOM%s(x, y) b2c_editbom(x, y)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define EL%s \"\\033[0K\"\n", g_STRINGSIGN);
fputs("#define ENDFILE(x) feof(x)\n", g_GENERIC);
fputs("#define EQ ==\n", g_GENERIC);
fputs("#define EQUAL(x, y) !__b2c__STRCMP(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define ESCAPE%s(x) b2c_escape(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define EVAL(x, y, z, q) b2c_eval(__LINE__, __FILE__, x, y, z, q)\n", g_GENERIC);
fputs("#define EVEN(x) (((long)(x) % 2 == 0) ? 1 : 0)\n", g_GENERIC);
fputs("#define __b2c__EXCHANGE3(x, y, z) b2c_exchange(x, y, z, NULL)\n", g_GENERIC);
fputs("#define __b2c__EXCHANGE4(x, y, z, f) b2c_exchange(x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define EXCHANGE%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__EXCHANGE4, __b2c__EXCHANGE3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__EXEC1(x) b2c_exec(0, __LINE__, __FILE__, x, NULL, 0)\n", g_GENERIC);
fputs("#define __b2c__EXEC2(x, y) b2c_exec(0, __LINE__, __FILE__, x, y, 0)\n", g_GENERIC);
fputs("#define __b2c__EXEC3(x, y, z) b2c_exec(0, __LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define EXEC%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXEC3, __b2c__EXEC2, __b2c__EXEC1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define EXP(x) exp((double)x)\n", g_GENERIC);
fputs("#define __b2c__EXPLODE1(x) b2c_explode(__LINE__, __FILE__, x, 1, NULL)\n", g_GENERIC);
fputs("#define __b2c__EXPLODE2(x, y) b2c_explode(__LINE__, __FILE__, x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__EXPLODE3(x, y, z) b2c_explode(__LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define EXPLODE%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXPLODE3, __b2c__EXPLODE2, __b2c__EXPLODE1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__EXTRACT2(x, y) b2c_extract(__LINE__, __FILE__, x, y, 0)\n", g_GENERIC);
fputs("#define __b2c__EXTRACT3(x, y, z) b2c_extract(__LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define EXTRACT%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXTRACT3, __b2c__EXTRACT2)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define FALSE 0\n", g_GENERIC);
fputs("#define FILEEXISTS(x) b2c_filestat(__LINE__, __FILE__, x, 1)\n", g_GENERIC);
fputs("#define FILELEN(x) b2c_filestat(__LINE__, __FILE__, x, 0)\n", g_GENERIC);
fputs("#define FILETIME(x, y) b2c_filetime(__LINE__, __FILE__, x, y)\n", g_GENERIC);
fputs("#define FILETYPE(x) b2c_filetype(__LINE__, __FILE__, x)\n", g_GENERIC);
fprintf(g_GENERIC, "#define FILL%s(x, y) b2c_fill(x, y)\n", g_STRINGSIGN);
fputs("#define FIND(x, y, z, a) b2c_find(x, y, z, a)\n", g_GENERIC);
fputs("#define __b2c__FIRST1(x) b2c_first(x, 1, NULL)\n", g_GENERIC);
fputs("#define __b2c__FIRST2(x, y) b2c_first(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__FIRST3(x, y, z) b2c_first(x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define FIRST%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__FIRST3, __b2c__FIRST2, __b2c__FIRST1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__FLATTEN1(x) b2c_flatten(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__FLATTEN2(x, y) b2c_flatten(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define FLATTEN%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__FLATTEN2, __b2c__FLATTEN1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define FLOATING double\n", g_GENERIC);
fputs("#define FLOOR(x) (long)floor(x)\n", g_GENERIC);
fputs("#define FORK fork()\n", g_GENERIC);
fputs("#define FP(x) (void*)(&x)\n", g_GENERIC);
fputs("#define GE >=\n", g_GENERIC);
fprintf(g_GENERIC, "#define GETENVIRON%s(x) b2c_getenv(x)\n", g_STRINGSIGN);
fputs("#define GETKEY b2c_getch()\n", g_GENERIC);
fprintf(g_GENERIC, "#define GETPEER%s(x) b2c_getpeer(__LINE__, __FILE__, (uintptr_t)x)\n", g_STRINGSIGN);
fputs("#define GETX b2c_getxy(0)\n", g_GENERIC);
fputs("#define GETY b2c_getxy(1)\n", g_GENERIC);
fputs("#define GUIDEFINE(x) b2c_guiDefine()\n", g_GENERIC);
fputs("#define __b2c__GUIEVENT1(x) b2c_guiExecute(x, 0)\n", g_GENERIC);
fputs("#define __b2c__GUIEVENT2(x, y) b2c_guiExecute(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define GUIEVENT%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__GUIEVENT2, __b2c__GUIEVENT1)(__VA_ARGS__)\n", g_STRINGSIGN);
    if( g_WHICH_GUI == 4 ){
    fputs("#define GUIFN(id, x) Tcl_Eval((Tcl_Interp*)id, x)\n", g_GENERIC);
    } else {
    fputs("#define __b2c__GUIFN1(id, x, func) func(GUIWIDGET(id, x))\n", g_GENERIC);
    fputs("#define __b2c__GUIFN2(id, x, func, ...) func(GUIWIDGET(id, x), __VA_ARGS__)\n", g_GENERIC);
    fputs("#define GUIFN(...) __b2c__FUNCSELECT10(__VA_ARGS__, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN1)(__VA_ARGS__)\n", g_GENERIC);
    }
    if( g_WHICH_GUI == 2 ){
    fputs("#define GUIWIDGET(id, x) __b2c_get_by_name(id, x)\n", g_GENERIC);
    fprintf(g_GENERIC, "#define GUIGET(id, x, p, q) (*(q)) = getCDK ## p( ( GUIWIDGET(id, x) == NULL ? (void*)(uintptr_t)fprintf(stderr, \"Runtime error: function 'GUIGET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR%s(42)) : GUIWIDGET(id, x) ) )\n", g_STRINGSIGN);
    fprintf(g_GENERIC, "#define GUISET(id, x, p, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUISET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR%s(42)) : setCDK ## p(GUIWIDGET(id, x), __VA_ARGS__) )\n", g_STRINGSIGN);
    fputs("#define GUICB(x, y, z, q) bindCDKObject(x, y, z, __b2c_cdk_callback, q)\n", g_GENERIC);
    } else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
    fputs("#define GUIWIDGET(id, x) __b2c_get_by_name(id, x)\n", g_GENERIC);
    fprintf(g_GENERIC, "#define GUIGET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUIGET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR%s(42)) : g_object_get(G_OBJECT(GUIWIDGET(id, x)), __VA_ARGS__, NULL) )\n", g_STRINGSIGN);
    fprintf(g_GENERIC, "#define GUISET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUISET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR%s(42)) : g_object_set(G_OBJECT(GUIWIDGET(id, x)), __VA_ARGS__, NULL) )\n", g_STRINGSIGN);
    fputs("#define GUICB(x, y, z) g_signal_connect_swapped(G_OBJECT(x), y, G_CALLBACK(__b2c_gtk_callback), z)\n", g_GENERIC);
    } else if( g_WHICH_GUI == 0 ){
    fputs("#define GUIWIDGET(id, x) XtNameToWidget((Widget)id, \"*\" x)\n", g_GENERIC);
    fprintf(g_GENERIC, "#define GUIGET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUIGET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR%s(42)) : XtVaGetValues(GUIWIDGET(id, x), __VA_ARGS__, NULL) )\n", g_STRINGSIGN);
    fprintf(g_GENERIC, "#define GUISET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUISET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR%s(42)) : XtVaSetValues(GUIWIDGET(id, x), __VA_ARGS__, NULL) )\n", g_STRINGSIGN);
    fputs("#define GUICB(x, y, z) XtAddCallback(x, y, __b2c_xt_callback, z)\n", g_GENERIC);
    } else {
    fputs("#define GUIWIDGET(id, x) x\n", g_GENERIC);
    fputs("#define GUIGET(id, x, y) y = b2c_CopyString(y, (char*)Tcl_GetVar((Tcl_Interp*)id, x, TCL_GLOBAL_ONLY))\n", g_GENERIC);
    fputs("#define GUISET(id, x, y) Tcl_SetVar((Tcl_Interp*)id, x, y, TCL_GLOBAL_ONLY)\n", g_GENERIC);
    fputs("#define GUICB(id, x, y) Tcl_CreateObjCommand((Tcl_Interp*)id, x, __b2c_tk_callback, (ClientData)y, NULL)\n", g_GENERIC);
    }
fputs("#define GT >\n", g_GENERIC);
fputs("#define HASBOM(x) b2c_hasbom(x)\n", g_GENERIC);
fputs("#define __b2c__HASDELIM1(x) b2c_hasdelim(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__HASDELIM2(x, y) b2c_hasdelim(x, y)\n", g_GENERIC);
fputs("#define HASDELIM(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASDELIM2, __b2c__HASDELIM1)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define __b2c__HASH1(x) HASH_FUNC((char*)x, 0)\n", g_GENERIC);
fputs("#define __b2c__HASH2(x, y) HASH_FUNC((char*)x, y)\n", g_GENERIC);
fputs("#define HASH(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASH2, __b2c__HASH1)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define __b2c__HEAD1(x) b2c_head(x, 1, NULL)\n", g_GENERIC);
fputs("#define __b2c__HEAD2(x, y) b2c_head(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__HEAD3(x, y, z) b2c_head(x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define HEAD%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__HEAD3, __b2c__HEAD2, __b2c__HEAD1)(__VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define HEX%s(x) b2c_dec2hex(x)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define HOST%s(x) b2c_nethost(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define HOSTNAME%s b2c_hostname(__LINE__, __FILE__)\n", g_STRINGSIGN);
fputs("#define HOUR(x) b2c_time(x, 4)\n", g_GENERIC);
fputs("#define __b2c__IIF2(x, y) (x ? y : 0)\n", g_GENERIC);
fputs("#define __b2c__IIF3(x, y, z) (x ? y : z)\n", g_GENERIC);
fputs("#define IIF(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIF3, __b2c__IIF2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define __b2c__IIFS2(x, y) (char*)(x ? y : NULL)\n", g_GENERIC);
fputs("#define __b2c__IIFS3(x, y, z) (char*)(x ? y : z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define IIF%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIFS3, __b2c__IIFS2)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__INBETWEEN3(x, y, z) b2c_inbetween(0, x, y, z, 0)\n", g_GENERIC);
fputs("#define __b2c__INBETWEEN4(x, y, z, f) b2c_inbetween(0, x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define INBETWEEN%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__INBETWEEN4, __b2c__INBETWEEN3)(__VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define __b2c__INDEX4(r, t, x, y) b2c_index(__LINE__, __FILE__, r+%s, t, (void*)x, 0, y)\n", STR( g_OPTION_BASE));
fprintf(g_GENERIC, "#define __b2c__INDEX5(r, t, x, y, z) b2c_index(__LINE__, __FILE__, r+%s, t, (void*)x, z, y)\n", STR( g_OPTION_BASE));
fputs("#define INDEX(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__INDEX5, __b2c__INDEX4)(__VA_ARGS__)\n", g_GENERIC);
fprintf(g_GENERIC, "#define INDEX%s(t, x, y) b2c_index_assoc(__LINE__, __FILE__, t, (b2c_htable*)assoc_ ## x, y)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define INSERT%s(x, y, z) b2c_insert(__LINE__, __FILE__, x, y, z)\n", g_STRINGSIGN);
fputs("#define __b2c__INSTR2(x, y) b2c_instr(__LINE__, __FILE__, x, y, -1)\n", g_GENERIC);
fputs("#define __b2c__INSTR3(x, y, z) b2c_instr(__LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fputs("#define INSTR(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTR3, __b2c__INSTR2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define __b2c__INSTRREV2(x, y) b2c_instrrev(__LINE__, __FILE__, x, y, -1)\n", g_GENERIC);
fputs("#define __b2c__INSTRREV3(x, y, z) b2c_instrrev(__LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fputs("#define INSTRREV(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTRREV3, __b2c__INSTRREV2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define INT(x) lrint((double)x)\n", g_GENERIC);
fprintf(g_GENERIC, "#define INTL%s(x) gettext(x)\n", g_STRINGSIGN);
fputs("#define INVERT(t, x) b2c_invert(__LINE__, __FILE__, t, &assoc_ ## x)\n", g_GENERIC);
fputs("#define IS ==\n", g_GENERIC);
fputs("#define ISASCII(x) b2c_isascii(x)\n", g_GENERIC);
fputs("#define ISFALSE(x) ((x) == 0)\n", g_GENERIC);
fputs("#define ISKEY(x, ...) (b2c_hash_find_key_do(assoc_ ## x, 0, __b2c__KEYCOLLECT(__VA_ARGS__)) == NULL ? 0 : 1)\n", g_GENERIC);
fputs("#define ISNOT !=\n", g_GENERIC);
fputs("#define __b2c__ISTOKEN2(x, y) b2c_istoken(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__ISTOKEN3(x, y, z) b2c_istoken(x, y, z)\n", g_GENERIC);
fputs("#define ISTOKEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ISTOKEN3, __b2c__ISTOKEN2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define ISTRUE(x) ((x) != 0)\n", g_GENERIC);
fputs("#define ISUTF8(x) b2c_isutf8(x)\n", g_GENERIC);
fprintf(g_GENERIC, "#define LCASE%s(x) b2c_lcase(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define LE <=\n", g_GENERIC);
fputs("#define __b2c__LEFT1(x) b2c_left(__LINE__, __FILE__, x, 1)\n", g_GENERIC);
fputs("#define __b2c__LEFT2(x, y) b2c_left(__LINE__, __FILE__, x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define LEFT%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__LEFT2, __b2c__LEFT1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define LEN(x) (b2c_option_utf8 ? b2c_ulen(__LINE__, __FILE__, \"LEN\", (char*)x, -1) : b2c_len(x))\n", g_GENERIC);
fputs("#define __b2c__ULEN1(x) b2c_ulen(__LINE__, __FILE__, \"ULEN\", (char*)x, -1)\n", g_GENERIC);
fputs("#define __b2c__ULEN2(x, y) b2c_ulen(__LINE__, __FILE__, \"ULEN\", (char*)x, y)\n", g_GENERIC);
fputs("#define ULEN(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__ULEN2, __b2c__ULEN1)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define __b2c__LAST1(x) b2c_last(x, 1, NULL)\n", g_GENERIC);
fputs("#define __b2c__LAST2(x, y) b2c_last(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__LAST3(x, y, z) b2c_last(x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define LAST%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__LAST3, __b2c__LAST2, __b2c__LAST1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define LINENO __LINE__\n", g_GENERIC);
fprintf(g_GENERIC, "#define LOAD%s(x) b2c_load(0, __LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define LOG(x) log((double)x)\n", g_GENERIC);
fprintf(g_GENERIC, "#define LOOP%s(...) ( !setjmp(b2c_loop1) ? b2c_loop_helper(b2c_loop2) : b2c_loop_result%s )\n", g_STRINGSIGN, g_STRINGSIGN);
fputs("#define LOOP(...) ( !setjmp(b2c_loop1) ? b2c_loop_helper2(b2c_loop2) : b2c_loop_result )\n", g_GENERIC);
fputs("#define LT <\n", g_GENERIC);
fputs("#define __b2c__MATCH2(x, y) b2c_match(x, y, -1, NULL)\n", g_GENERIC);
fputs("#define __b2c__MATCH3(x, y, z) b2c_match(x, y, z, NULL)\n", g_GENERIC);
fputs("#define __b2c__MATCH4(x, y, z, f) b2c_match(x, y, z, f)\n", g_GENERIC);
fputs("#define MATCH(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__MATCH4, __b2c__MATCH3, __b2c__MATCH2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define MAX(x, y) fmax(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define MAX%s(x, y) b2c_max_str(x, y)\n", g_STRINGSIGN);
fputs("#define MAXNUM(x) (x)POW(2, SIZEOF(x)*8)\n", g_GENERIC);
    if( INSTR(OS, "SunOS")  OR  INSTR(OS, "OSF1") ){
    fputs("#define MAXRANDOM 2147483647\n", g_GENERIC);
    } else {
    fputs("#define MAXRANDOM RAND_MAX\n", g_GENERIC);
    }
fprintf(g_GENERIC, "#define ME%s b2c_me_var%s\n", g_STRINGSIGN, g_STRINGSIGN);
fputs("#define MEMCHECK(x) b2c_memory__check((char*)x, sizeof(__b2c__MEMTYPE))\n", g_GENERIC);
fputs("#define MEMORY(x) (calloc(x+b2c_option_memstream, sizeof(__b2c__MEMTYPE)))\n", g_GENERIC);
fputs("#define MEMTELL(x) (long)x\n", g_GENERIC);
fputs("#define __b2c__MERGE1(x) b2c_merge(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__MERGE2(x, y) b2c_merge(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define MERGE%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__MERGE2, __b2c__MERGE1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__MID2(x, y) b2c_mid(__LINE__, __FILE__, NULL, 0, x, y, -1)\n", g_GENERIC);
fputs("#define __b2c__MID3(x, y, z) b2c_mid(__LINE__, __FILE__, NULL, 0, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define MID%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MID3, __b2c__MID2)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__FMID3(s, x, y) b2c_mid(__LINE__, __FILE__, &s, 1, x, y, -1)\n", g_GENERIC);
fputs("#define __b2c__FMID4(s, x, y, z) b2c_mid(__LINE__, __FILE__, &s, 1, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define F_MID%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FMID4, __b2c__FMID3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define MIN(x, y) fmin(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define MIN%s(x, y) b2c_min_str(x, y)\n", g_STRINGSIGN);
fputs("#define MINUTE(x) b2c_time(x, 5)\n", g_GENERIC);
fputs("#define __b2c__MOD2(x, y) ((long)(x) % (long)(y))\n", g_GENERIC);
fputs("#define __b2c__MOD3(x, y, z) (z == 0 ? ((long)(x) % (long)(y)) : fmod((double)x, (double)y))\n", g_GENERIC);
fputs("#define MOD(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MOD3, __b2c__MOD2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define MONTH(x) b2c_time(x, 2)\n", g_GENERIC);
fprintf(g_GENERIC, "#define MONTH%s(x) b2c_datename(x, 2)\n", g_STRINGSIGN);
fputs("#define MYPID getpid()\n", g_GENERIC);
fputs("#define NANOTIMER b2c_nanotimer(0)\n", g_GENERIC);
fputs("#define NE !=\n", g_GENERIC);
fprintf(g_GENERIC, "#define NL%s \"\\n\"\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define NNTL%s(x,y,z) ngettext(x,y,z)\n", g_STRINGSIGN);
fputs("#define NOT(x) (!(x))\n", g_GENERIC);
fputs("#define NOW (long)time(NULL)\n", g_GENERIC);
fputs("#define NRKEYS(x) b2c_hash_nrkeys(assoc_ ## x)\n", g_GENERIC);
fputs("#define NUMBER long\n", g_GENERIC);
fputs("#define __b2c__OBTAIN1(x) b2c_hash_obtain(assoc_ ## x, NULL)\n", g_GENERIC);
fputs("#define __b2c__OBTAIN2(x, y) b2c_hash_obtain(assoc_ ## x, y)\n", g_GENERIC);
fputs("#define __b2c__OBTAIN3(x, y, z) b2c_hash_obtain_by_sort(__LINE__, __FILE__, assoc_ ## x, y, z, b2c_obtain_type_ ## x)\n", g_GENERIC);
fprintf(g_GENERIC, "#define OBTAIN%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__OBTAIN3, __b2c__OBTAIN2, __b2c__OBTAIN1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define ODD(x) (((long)(x) % 2 != 0) ? 1 : 0)\n", g_GENERIC);
fputs("#define OR ||\n", g_GENERIC);
fprintf(g_GENERIC, "#define OS%s b2c_os(__LINE__, __FILE__)\n", g_STRINGSIGN);
fputs("#define __b2c__OUTBETWEEN3(x, y, z) b2c_inbetween(1, x, y, z, 0)\n", g_GENERIC);
fputs("#define __b2c__OUTBETWEEN4(x, y, z, f) b2c_inbetween(1, x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define OUTBETWEEN%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__OUTBETWEEN4, __b2c__OUTBETWEEN3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define PEEK(x) *(__b2c__MEMTYPE*)b2c_peek_check(__LINE__, __FILE__, (char*)x, sizeof(__b2c__MEMTYPE))\n", g_GENERIC);
fputs("#define PI 3.14159265358979323846\n", g_GENERIC);
fputs("#define POW(x, y) pow((double)x, (double)y)\n", g_GENERIC);
fputs("#define __b2c__PROPER1(x) b2c_proper(__LINE__, __FILE__, x, NULL)\n", g_GENERIC);
fputs("#define __b2c__PROPER2(x, y) b2c_proper(__LINE__, __FILE__, x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define PROPER%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__PROPER2, __b2c__PROPER1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define RAD(x) (x*PI/180)\n", g_GENERIC);
fputs("#define RANDOM(x) (long)((x+0.0)*random()/(MAXRANDOM+0.0))\n", g_GENERIC);
fprintf(g_GENERIC, "#define REALPATH%s(x) b2c_dirname(__LINE__, __FILE__, 0, x, 0)\n", g_STRINGSIGN);
fputs("#define REAP(x) waitpid(x, NULL, WNOHANG)\n", g_GENERIC);
fputs("#define REGEX(x, y) b2c_regex(__LINE__, __FILE__, x, y)\n", g_GENERIC);
fputs("#define __b2c__REPLACE3(x, y, z) b2c_replace(__LINE__, __FILE__, x, y, z, 0)\n", g_GENERIC);
fputs("#define __b2c__REPLACE4(x, y, z, f) b2c_replace(__LINE__, __FILE__, x, y, z, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define REPLACE%s(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__REPLACE4, __b2c__REPLACE3)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__REV1(x) b2c_rev(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__REV2(x, y) b2c_rev(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define REV%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__REV2, __b2c__REV1)(__VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define REVERSE%s(x) b2c_reverse(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define __b2c__RIGHT1(x) b2c_right(__LINE__, __FILE__, x, 1)\n", g_GENERIC);
fputs("#define __b2c__RIGHT2(x, y) b2c_right(__LINE__, __FILE__, x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define RIGHT%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__RIGHT2, __b2c__RIGHT1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__RIP2(x, y) b2c_rip(__LINE__, __FILE__, x, y, -1)\n", g_GENERIC);
fputs("#define __b2c__RIP3(x, y, z) b2c_rip(__LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define RIP%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RIP3, __b2c__RIP2)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define RND random()\n", g_GENERIC);
fputs("#define ROL(x) b2c_rol(sizeof(__b2c__MEMTYPE), x)\n", g_GENERIC);
fputs("#define ROR(x) b2c_ror(sizeof(__b2c__MEMTYPE), x)\n", g_GENERIC);
fputs("#define __b2c__ROTATE2(x, y) b2c_rotate(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__ROTATE3(x, y, z) b2c_rotate(x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define ROTATE%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ROTATE3, __b2c__ROTATE2)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define ROUND(x) lrint((double)x)\n", g_GENERIC);
fputs("#define ROWS b2c_screen(1)\n", g_GENERIC);
fputs("#define __b2c__RUN1(x) b2c_exec(1, __LINE__, __FILE__, x, NULL, 0)\n", g_GENERIC);
fputs("#define __b2c__RUN2(x, y) b2c_exec(1, __LINE__, __FILE__, x, y, 0)\n", g_GENERIC);
fputs("#define __b2c__RUN3(x, y, z) b2c_exec(1, __LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define RUN%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RUN3, __b2c__RUN2, __b2c__RUN1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__SEARCH2(x, y) b2c_search(__LINE__, __FILE__, x, y, -1)\n", g_GENERIC);
fputs("#define __b2c__SEARCH3(x, y, z) b2c_search(__LINE__, __FILE__, x, y, z)\n", g_GENERIC);
fputs("#define SEARCH(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__SEARCH3, __b2c__SEARCH2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define SECOND(x) b2c_time(x, 6)\n", g_GENERIC);
fputs("#define SETENVIRON(x, y) b2c_setenviron(x, y)\n", g_GENERIC);
fputs("#define SGN(x) b2c_sgn((double)(x))\n", g_GENERIC);
fputs("#define SIN(x) sin((double)(x))\n", g_GENERIC);
fputs("#define SIZEOF(x) sizeof(x)\n", g_GENERIC);
fputs("#define __b2c__SORT1(x) b2c_sort(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__SORT2(x, y) b2c_sort(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define SORT%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__SORT2, __b2c__SORT1)(__VA_ARGS__)\n", g_STRINGSIGN);
fprintf(g_GENERIC, "#define SPC%s(x) b2c_spc(x)\n", g_STRINGSIGN);
fputs("#define SQR(x) sqrt((double)(x))\n", g_GENERIC);
fprintf(g_GENERIC, "#define STR%s(x) b2c_str(x)\n", g_STRINGSIGN);
fputs("#define STRING char*\n", g_GENERIC);
fprintf(g_GENERIC, "#define SUM(x,...) b2c_sum(%s, x, __VA_ARGS__, LONG_MAX)\n", STR( g_OPTION_BASE));
fprintf(g_GENERIC, "#define SUMF(x,...) b2c_sumf(%s, x, __VA_ARGS__, DBL_MAX)\n", STR( g_OPTION_BASE));
fprintf(g_GENERIC, "#define TAB%s(x) b2c_tab(x)\n", g_STRINGSIGN);
fputs("#define __b2c__TAIL1(x) b2c_tail(x, 1, NULL)\n", g_GENERIC);
fputs("#define __b2c__TAIL2(x, y) b2c_tail(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__TAIL3(x, y, z) b2c_tail(x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define TAIL%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TAIL3, __b2c__TAIL2, __b2c__TAIL1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__TALLY2(x, y) b2c_tally(x, y, -1)\n", g_GENERIC);
fputs("#define __b2c__TALLY3(x, y, z) b2c_tally(x, y, z)\n", g_GENERIC);
fputs("#define TALLY(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TALLY3, __b2c__TALLY2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define TAN(x) tan((double)(x))\n", g_GENERIC);
fputs("#define TELL(x) ftell(x)\n", g_GENERIC);
fputs("#define TIMER b2c_timer(0)\n", g_GENERIC);
fputs("#define TIMEVALUE(x,y,z,a,b,c) b2c_epoch(x,y,z,a,b,c)\n", g_GENERIC);
fprintf(g_GENERIC, "#define TOASCII%s(x) b2c_toascii(x)\n", g_STRINGSIGN);
fputs("#define __b2c__TOKEN2(x, y) b2c_token(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__TOKEN3(x, y, z) b2c_token(x, y, z)\n", g_GENERIC);
fprintf(g_GENERIC, "#define TOKEN%s(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TOKEN3, __b2c__TOKEN2)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define TOTAL(x) b2c_total(x)\n", g_GENERIC);
fputs("#define TRUE 1\n", g_GENERIC);
fprintf(g_GENERIC, "#define UCASE%s(x) b2c_ucase(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define UCS(x) (unsigned int)b2c_utf8toasc(x)\n", g_GENERIC);
fprintf(g_GENERIC, "#define UNESCAPE%s(x) b2c_unescape(__LINE__, __FILE__, x)\n", g_STRINGSIGN);
fputs("#define __b2c__UNFLATTEN1(x) b2c_unflatten(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__UNFLATTEN2(x, y) b2c_unflatten(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define UNFLATTEN%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNFLATTEN2, __b2c__UNFLATTEN1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define __b2c__UNIQ1(x) b2c_uniq(x, NULL)\n", g_GENERIC);
fputs("#define __b2c__UNIQ2(x, y) b2c_uniq(x, y)\n", g_GENERIC);
fprintf(g_GENERIC, "#define UNIQ%s(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNIQ2, __b2c__UNIQ1)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define VAL(x) b2c_val(x)\n", g_GENERIC);
fputs("#define WAIT(x, y) b2c_netpeek(__LINE__, __FILE__, (uintptr_t)x, y)\n", g_GENERIC);
fputs("#define __b2c__WALK4(x, y, z, q) b2c_walk(__LINE__, __FILE__, x, y, z, q, NULL)\n", g_GENERIC);
fputs("#define __b2c__WALK5(x, y, z, q, f) b2c_walk(__LINE__, __FILE__, x, y, z, q, f)\n", g_GENERIC);
fprintf(g_GENERIC, "#define WALK%s(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__WALK5, __b2c__WALK4)(__VA_ARGS__)\n", g_STRINGSIGN);
fputs("#define WEEK(x) b2c_time(x, 7)\n", g_GENERIC);
fprintf(g_GENERIC, "#define WEEKDAY%s(x) b2c_datename(x, 1)\n", g_STRINGSIGN);
fputs("#define __b2c__WHERE2(x, y) b2c_where(x, y, NULL)\n", g_GENERIC);
fputs("#define __b2c__WHERE3(x, y, z) b2c_where(x, y, z)\n", g_GENERIC);
fputs("#define WHERE(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__WHERE3, __b2c__WHERE2)(__VA_ARGS__)\n", g_GENERIC);
fputs("#define YEAR(x) b2c_time(x, 3)\n", g_GENERIC);
fputs("#define b2c_cacerts NULL\n", g_GENERIC);
fputs("#define b2c_capeer 0\n", g_GENERIC);
fputs("#define b2c_caprivate NULL\n", g_GENERIC);
fputs("#define b2c_caserver NULL\n", g_GENERIC);
    fclose(g_GENERIC);
    fclose( g_CFILE);
    fclose( FLOATARRAYFILE);
    fclose( STRINGARRAYFILE);
    g_FUNCTIONS = fopen((const char*)g_FUNCTIONS, "w");
if(g_FUNCTIONS == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 9160, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(g_FUNCTIONS, "/* Created with BaCon %s - (c) Peter van Eerten - MIT License */\n", g_VERSION);
fprintf(g_FUNCTIONS, "%s\n", g_TWEAK);
fprintf(g_FUNCTIONS, "char *ERR%s(int nr){ static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long flen = 0, slen = 0; char *first = NULL, *second = NULL; switch (nr)\n", g_STRINGSIGN);
fputs("{ case 0: first = \"Success\"; break; case 1: first = \"Trying to access illegal memory: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 2: first = \"Error opening file: \"; second = strerror (errno); break; case 3: first = \"Could not open library.\"; break;\n", g_FUNCTIONS);
fputs("case 4: first = \"Symbol not found in library.\"; break; case 5: first = \"Wrong value: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 6: first = \"Unable to claim memory.\"; break; case 7: first = \"Unable to delete file: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 8: first = \"Could not open directory: \"; second = strerror(errno); break; case 9: first = \"Unable to rename file: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 10: first = \"NETWORK argument should contain colon with port number\"; break; case 11: first = \"Could not resolve hostname!\"; break;\n", g_FUNCTIONS);
fputs("case 12: first = \"Socket error: \"; second = strerror(errno); break; case 13: first = \"Unable to open address: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 14: first = \"Error reading from socket: \"; second = strerror(errno); break; case 15: first = \"Error sending to socket: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 16: first = \"Error checking socket: \"; second = strerror(errno); break; case 17: first = \"Unable to bind the specified socket address: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 18: first = \"Unable to listen to socket address: \"; second = strerror(errno); break; case 19: first = \"Cannot accept incoming connection: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 20: first = \"Unable to remove directory: \"; second = strerror(errno); break; case 21: first = \"Unable to create directory: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 22: first = \"Unable to change to directory: \"; second = strerror(errno); break; case 23: first = \"GETENVIRON argument does not exist as environment variable\"; break;\n", g_FUNCTIONS);
fputs("case 24: first = \"Unable to stat file: \"; second = strerror(errno); break; case 25: first = \"Search contains illegal string\"; break;\n", g_FUNCTIONS);
fputs("case 26: first = \"Cannot return name: \"; second = strerror(errno); break; case 27: first = \"Illegal regex expression\"; break;\n", g_FUNCTIONS);
fputs("case 28: first = \"Unable to create bidirectional pipes: \"; second = strerror(errno); break; case 29: first = \"Unable to fork process: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 30: first = \"Cannot read from pipe: \"; second = strerror(errno); break; case 31: first = \"Gosub nesting too deep!\"; break;\n", g_FUNCTIONS);
fputs("case 32: first = \"Could not open device: \"; second = strerror(errno); break; case 33: first = \"Error configuring serial port: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 34: first = \"Error accessing device: \"; second = strerror(errno); break; case 35: first = \"Error in INPUT: \"; second = strerror(errno); break;\n", g_FUNCTIONS);
fputs("case 36: first = \"Illegal value in SORT dimension!\"; break; case 37: first = \"Illegal option for SEARCH!\"; break;\n", g_FUNCTIONS);
fputs("case 38: first = \"Invalid UTF8 string!\"; break; case 39: first = \"Illegal EVAL expression!\"; break;\n", g_FUNCTIONS);
fputs("case 40: first = \"SSL file descriptor error!\"; break; case 41: first = \"Error loading certificate!\"; break;\n", g_FUNCTIONS);
fputs("case 42: first = \"Widget not found!\"; ERROR = 42; break; case 43: first = \"Unsupported array type!\"; break; };\n", g_FUNCTIONS);
fputs("if(first) { flen = strlen(first); } if(second) { slen = strlen(second); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], flen+slen+1);if(first)\n", g_FUNCTIONS);
fputs("{ memmove(buf[idx], first, flen); } if(second) { memmove(buf[idx]+flen, second, slen); } __b2c__SETLEN(buf[idx], flen+slen); buf[idx][flen+slen] = '\\0'; return((char*)buf[idx]); }\n", g_FUNCTIONS);
fputs("char *b2c_strdup(char *s) { if(s == NULL) { return(NULL); } return(b2c_CopyString(NULL, s)); }\n", g_FUNCTIONS);
fputs("char *b2c_strndup(char *s, size_t n) { if(s == NULL) { return(NULL); } return(__b2c_Copy_N_String(NULL, s, n)); }\n", g_FUNCTIONS);
fputs("int b2c_strcmp(const char *b2c_s1, const char *b2c_s2){ int len1 = 0, len2 = 0; len1 = b2c_len(b2c_s1); len2 = b2c_len(b2c_s2); if((b2c_s1 == NULL || len1 == 0) && (b2c_s2 == NULL || len2 == 0)) { return(0); }\n", g_FUNCTIONS);
fputs("if(b2c_s1 == NULL || len1 == 0) { return(-1); } if(b2c_s2 == NULL || len2 == 0) { return(1); } return(strcmp(b2c_s1, b2c_s2)); }\n", g_FUNCTIONS);
fputs("int b2c_strcasecmp(const char *b2c_s1, const char *b2c_s2){ int len1 = 0, len2 = 0; len1 = b2c_len(b2c_s1); len2 = b2c_len(b2c_s2); if((b2c_s1 == NULL || len1 == 0) && (b2c_s2 == NULL || len2 == 0)) { return(0); }\n", g_FUNCTIONS);
fputs("if(b2c_s1 == NULL || len1 == 0) { return(-1); } if(b2c_s2 == NULL || len2 == 0) { return(1); } return(strcasecmp(b2c_s1, b2c_s2)); }\n", g_FUNCTIONS);
fputs("#ifndef __b2c_Pool_Block_Count\n", g_FUNCTIONS);
fputs("#define __b2c_Pool_Block_Count 2048\n", g_FUNCTIONS);
fputs("#endif\n", g_FUNCTIONS);
fputs("#ifndef __b2c_Pool_Block_Size\n", g_FUNCTIONS);
fputs("#define __b2c_Pool_Block_Size 1024\n", g_FUNCTIONS);
fputs("#endif\n", g_FUNCTIONS);
fputs("void *__b2c_mempool_realloc_core (void *address, size_t size, int action) { static char bottom[__b2c_Pool_Block_Count*__b2c_Pool_Block_Size] = { 0 }; static void *top = NULL, *current = NULL; static int inited = 0, amount_used = 0; void *result = NULL;\n", g_FUNCTIONS);
fputs("if(!inited) { current = bottom; top = bottom + (__b2c_Pool_Block_Size * __b2c_Pool_Block_Count); *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } switch(action) { case 0: fprintf(stderr, \"Memory pool contains %d slots, each %d bytes, of which %d were used.\\n\", __b2c_Pool_Block_Count, __b2c_Pool_Block_Size, inited);\n", g_FUNCTIONS);
fputs("break; case 1: if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { *(uintptr_t *)address = (uintptr_t)current; current = address; amount_used--; return(address); } break; case 2:\n", g_FUNCTIONS);
fputs("if ((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { return(address); } break; default: if(amount_used < __b2c_Pool_Block_Count-1 && size < __b2c_Pool_Block_Size) { if(address == NULL) { result = current;\n", g_FUNCTIONS);
fputs("current = (void*)*(uintptr_t*)current; amount_used++; if(amount_used == inited) { *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } } else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top)\n", g_FUNCTIONS);
fputs("{ if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = address; } } else { result = realloc(address, size); } } else { if(address == NULL) { result = realloc(address, size); }\n", g_FUNCTIONS);
fputs("else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = malloc(size > __b2c_Pool_Block_Size ? size : __b2c_Pool_Block_Size);\n", g_FUNCTIONS);
fputs("memcpy(result, address, __b2c_Pool_Block_Size); *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } } else { result = realloc(address, size); } } break; } return ((void *) result); }\n", g_FUNCTIONS);
fputs("#ifndef __b2c_HASH_STR_STORE\n", g_FUNCTIONS);
fputs("#define __b2c_HASH_STR_STORE 0x100000\n", g_FUNCTIONS);
fputs("#endif\n", g_FUNCTIONS);
fputs("#define __b2c_HASH_STR_INDEX (__b2c_HASH_STR_STORE-1)\n", g_FUNCTIONS);
fputs("#ifndef __b2c_HASH_LINEAR_DEPTH\n", g_FUNCTIONS);
fputs("#define __b2c_HASH_LINEAR_DEPTH 16\n", g_FUNCTIONS);
fputs("#endif\n", g_FUNCTIONS);
fputs("#define __b2c_get_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { p=NULL; break; }}}\n", g_FUNCTIONS);
fputs("#define __b2c_del_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { break; } } if(d < l) { e[i] = NULL; } }\n", g_FUNCTIONS);
fputs("#define __b2c_add_string(p, e, i, d, l) if(p) { while(e[i] != NULL && e[i]!=p) { i++; if(++d == l) { if(++l == __b2c_HASH_LINEAR_DEPTH) { fprintf (stderr, \"\\nInternal error: cannot register string! Try to tweak the 'hld' parameter.\\n\"); __b2c_str_realloc_debug_string(); exit (EXIT_FAILURE); } } } e[i] = p; }\n", g_FUNCTIONS);
fputs("void *__b2c_str_realloc_core (char *ptr, size_t size, int action) { static char *even_addr[__b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH] = { NULL }; static int linear_depth = 1; char *next; uint32_t lbufsize = 0, rbufsize = 0, idx, len, depth = 0, total = 0; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); switch (action)\n", g_FUNCTIONS);
fputs("{ case 0: case 1: next = ptr; __b2c_get_string(next, even_addr, idx, depth, linear_depth); if(next) { lbufsize = __b2c__LBUFSIZE (ptr); rbufsize = __b2c__RBUFSIZE (ptr); if (action == 0) { if (rbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2 + 1);\n", g_FUNCTIONS);
fputs("ptr = next + lbufsize; *(uint32_t *) ((char *) ptr + 4) = size * 2 + 1 + rbufsize; } else { return (ptr); } } else { if (lbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2);\n", g_FUNCTIONS);
fputs("memmove (next + lbufsize + size * 2, next + lbufsize, __b2c__BUFOFFSET + rbufsize); ptr = next + size * 2 + lbufsize; *(uint32_t *) ((char *) ptr + 8) = size * 2 + lbufsize; } else { return (ptr); } } } else { rbufsize = b2c_len (ptr); next = (char*)__b2c_mempool_realloc(ptr, __b2c__BUFOFFSET + rbufsize + size * 2 + 1);\n", g_FUNCTIONS);
fputs("if (action == 0) { ptr = next; *(uint32_t *) ((char *) ptr) = rbufsize; *(uint32_t *) ((char *) ptr + 4) = rbufsize + size * 2 + 1; *(uint32_t *) ((char *) ptr + 8) = 0; } else { memmove (next + size * 2, next, __b2c__BUFOFFSET + rbufsize); ptr = next+size * 2; *(uint32_t *) ((char *) ptr) = rbufsize;\n", g_FUNCTIONS);
fputs("*(uint32_t *) ((char *) ptr + 4) = rbufsize + 1; *(uint32_t *) ((char *) ptr + 8) = size * 2; } } ptr += __b2c__BUFOFFSET; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); depth = 0; __b2c_add_string(ptr, even_addr, idx, depth, linear_depth); break; case 2: __b2c_add_string(ptr, even_addr, idx, depth, linear_depth);\n", g_FUNCTIONS);
fputs("break; case 3: __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); break; case 4: __b2c_get_string(ptr, even_addr, idx, depth, linear_depth); break; case 5: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if (even_addr[idx] != NULL) { total++; len = (*(uint32_t*)(even_addr[idx]-__b2c__BUFOFFSET));\n", g_FUNCTIONS);
fputs("lbufsize = __b2c__LBUFSIZE(even_addr[idx]); rbufsize = __b2c__RBUFSIZE(even_addr[idx]); if(len > 64) { even_addr[idx][64] = 0; fprintf(stderr, \"Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s[...]\\n\", idx, lbufsize, rbufsize, len, even_addr[idx]); } else { fprintf(stderr, \"Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s\\n\", idx, lbufsize, rbufsize, len, even_addr[idx]); } } }\n", g_FUNCTIONS);
fputs("fprintf(stderr, \"Total optimized strings: %d - max depth: %d\\n\", total, linear_depth); break; case 6: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if(even_addr[idx] && !__b2c_mempool_realloc_in_block(even_addr[idx])) { free(even_addr[idx] - __b2c__BUFOFFSET - __b2c__LBUFSIZE(even_addr[idx])); } } break; } return (ptr); }\n", g_FUNCTIONS);
fputs("char *__b2c_Copy_String_core(char *x, char *y, int len) { long ylen; if(y == NULL) { __b2c__STRFREE(x); return(NULL); } if(len == -1) { ylen = b2c_len(y); } else { ylen = len; } if (ylen == 0) { __b2c__STRFREE (x); return (NULL); } x = (char*)__b2c_str_realloc(x, ylen);\n", g_FUNCTIONS);
fputs("memmove(x, y, ylen); __b2c__SETLEN(x, ylen); x[ylen] = '\\0'; return(x); }\n", g_FUNCTIONS);
fputs("char *__b2c_Swap_String(char **x, char **y) { char *ptr; ptr = *x; *x = *y; *y = ptr; return(*x); }\n", g_FUNCTIONS);
fputs("unsigned long b2c_len (const char *ptr) { if (ptr == NULL) { return (0); } if(__b2c_str_realloc_get_string(ptr)) { return (*(uint32_t *) (ptr - __b2c__BUFOFFSET)); } return ((unsigned long) strlen (ptr)); }\n", g_FUNCTIONS);
fprintf(g_FUNCTIONS, "char *b2c_loop_helper(jmp_buf buf) { if(b2c_loop_result%s != NULL) { __b2c__SETLEN (b2c_loop_result%s, 0); b2c_loop_result%s = b2c_CopyString(b2c_loop_result%s, NULL); } longjmp(buf, 1); return(NULL); }\n", g_STRINGSIGN, g_STRINGSIGN, g_STRINGSIGN, g_STRINGSIGN);
fputs("long b2c_loop_helper2(jmp_buf buf) { b2c_loop_result = 0; longjmp(buf, 1); return(0); }\n", g_FUNCTIONS);
fputs("void b2c_free_str_array_members(char ***array, int base, int size) { int i; if(*array != NULL) { for(i=0; i < size; i++){ __b2c__STRFREE((*array)[i+base]); (*array)[i+base] = NULL; } } }\n", g_FUNCTIONS);
    if( INSTR(OS, "BSD") ){
    fputs("char *__b2c_strlcat(char *dest, const char *src) { strlcat(dest, src, b2c_len(dest)+b2c_len(src)+1); return(dest); }\n", g_FUNCTIONS);
    fputs("char *__b2c_strlcpy(char *dest, const char *src) { strlcpy(dest, src, b2c_len(src)+1); return(dest); }\n", g_FUNCTIONS);
    }
fputs("void __b2c_str_free(void) {\n", g_FUNCTIONS);
    if( REGEX(g_DEPEND, "REGEX\\(") ){
    fputs("b2c_regex_free();\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "EXTRACT\\$\\(") ){
    fputs("b2c_extract_free();\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "REPLACE\\$\\(") ){
    fputs("b2c_replace_free();\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "WALK\\$\\(") ){
    fputs("b2c_walk_free();\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ALIGN\\$\\(|AMOUNT\\(|APPEND\\$\\(|CHANGE\\$\\(|COIL\\$\\(|COLLAPSE\\$\\(|CUT\\$\\(|DEL\\$\\(|DELIM\\$\\(|EXCHANGE\\$\\(|EXEC\\$\\(|EXPLODE\\$\\(|FIRST\\$\\(|FOR[[:space:]]|HASDELIM\\(|HEAD\\$\\(|INBETWEEN\\$\\(|ISTOKEN\\(|LAST\\$\\(|MAKEDIR[[:space:]]|MATCH\\(|MERGE\\$\\(|NETWORK[[:space:]]|OUTBETWEEN\\$\\(|PARSE[[:space:]]|PROPER\\$\\(|REV\\$\\(|ROTATE\\$\\(|SERVER[[:space:]]|SORT\\$\\(|SPLIT[[:space:]]|TAIL\\$\\(|TOKEN\\$\\(|UNIQ\\$\\(|WHERE\\(") ){
    fputs("b2c_delim_engine_free();\n", g_FUNCTIONS);
    }
    if( LEN(g_GLOBALARRAYS) ){
    fputs("s_free();\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "COLLECT[[:space:]]|TREE[[:space:]]") ){
    fputs("b2c_twalk_free();\n", g_FUNCTIONS);
    }
fputs("__b2c_str_realloc_free_string(); }\n", g_FUNCTIONS);
fputs("void b2c_catch_signal(int sig){\n", g_FUNCTIONS);
fputs("switch (sig) {case SIGABRT: fprintf(stderr, \"ERROR: signal ABORT received - internal error. Try to compile the program with TRAP LOCAL to find the cause.\\n\"); break;\n", g_FUNCTIONS);
fputs("case SIGFPE: fprintf(stderr, \"ERROR: signal for FPE received - division by zero? Examine the calculations in the program.\\n\"); break;\n", g_FUNCTIONS);
fputs("case SIGSEGV: fprintf(stderr, \"ERROR: signal for SEGMENTATION FAULT received - memory invalid or array out of bounds? Try to compile the program with TRAP LOCAL to find the cause.\\n\"); break;\n", g_FUNCTIONS);
fputs("case SIGILL: fprintf(stderr, \"ERROR: signal for ILLEGAL INSTRUCTION received - executing the program on other hardware? Try to recompile the program from scratch.\\n\"); break;} exit(sig);}\n", g_FUNCTIONS);
fputs("void b2c_segv(int sig){ longjmp(b2c_jump, 1); }\n", g_FUNCTIONS);
fputs("int b2c_memory__check (char *x, int size) { volatile char c; unsigned int i, illegal = 1; struct sigaction osa, psa; sigaction(SIGSEGV, NULL, &osa); if (osa.sa_handler != SIG_IGN)\n", g_FUNCTIONS);
fputs("{ memset(&psa, 0, sizeof(psa)); psa.sa_flags = SA_NODEFER|SA_RESTART; psa.sa_handler = b2c_segv; sigaction(SIGSEGV, &psa, NULL); } if (!setjmp (b2c_jump))\n", g_FUNCTIONS);
fputs("{ for (i = 0; i < size; i++) { c = *(char*)(x+i); /* Use c to avoid warning */ if(c) {;} } } else { illegal = 0; } sigaction(SIGSEGV, &osa, NULL); return (illegal); }\n", g_FUNCTIONS);
fputs("int jmp_buf_is_used(jmp_buf data) { jmp_buf p = { 0 }; if(!data) {return(0);} if(memcmp(data, p, sizeof(jmp_buf))) { return(1); } return(0); }\n", g_FUNCTIONS);
fputs("char* b2c_min_str(char* x, char* y) {if(strcmp(x, y) < 0) { return(x); } return(y);}\n", g_FUNCTIONS);
fputs("char* b2c_max_str(char* x, char* y) {if(strcmp(x, y) > 0) { return(x); } return(y);}\n", g_FUNCTIONS);
fprintf(g_FUNCTIONS, "char* b2c_str(double nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc (buf[idx], %s); if(floor(nr) == nr)\n", STR( g_MAX_DIGITS));
fprintf(g_FUNCTIONS, "{ len = snprintf(buf[idx], %s, \"%ld\", (long)nr); } else { len = snprintf(buf[idx], %s, \"%g\", (double)nr); } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
fputs("unsigned long b2c_timer(int init) { struct timeval time; static time_t elapsed_secs = 0; static int elapsed_usecs = 0; if(init) { gettimeofday(&time, NULL); elapsed_usecs = time.tv_usec; elapsed_secs = time.tv_sec; return(0); }\n", g_FUNCTIONS);
fputs("else { gettimeofday(&time, NULL); if(difftime(time.tv_sec, elapsed_secs) < 1) { return((unsigned long) (time.tv_usec-elapsed_usecs)/1000); }\n", g_FUNCTIONS);
fputs("else { return((unsigned long) (difftime(time.tv_sec, elapsed_secs)-1)*1000+((1000000-elapsed_usecs)+time.tv_usec)/1000); } } }\n", g_FUNCTIONS);
fputs("uint64_t b2c_nanotimer(int init) { static struct timespec before = { 0 }; struct timespec after; if (init) { clock_gettime(CLOCK_MONOTONIC, &before); return(0); } else { clock_gettime(CLOCK_MONOTONIC, &after); return((int64_t)(after.tv_sec - before.tv_sec) * (int64_t)1000000000UL + (int64_t)(after.tv_nsec - before.tv_nsec)); } }\n", g_FUNCTIONS);
fputs("void b2c_argument(char **arg, int total, char **data) { long x, dlen, slen, pos, tot_len = 0; char quote[] = { 34, 0 }; if (total == 0) { *arg = NULL; } else { dlen = b2c_len (b2c_option_delim); for (pos = 0; pos < total; pos++)\n", g_FUNCTIONS);
fputs("{ slen = strlen(data[pos]); *arg = (char*)__b2c_str_realloc(*arg, tot_len + slen * 2 + dlen + 1); if (strstr (data[pos], \" \") || strstr (data[pos], \"\\\"\")) { (*arg)[tot_len++] = 34; for (x = 0; data[pos][x] != 0; x++) { if (data[pos][x] == quote[0])\n", g_FUNCTIONS);
fputs("{ (*arg)[tot_len++] = b2c_option_esc; } (*arg)[tot_len++] = data[pos][x]; } (*arg)[tot_len++] = 34; } else { memmove (*arg + tot_len, data[pos], slen); tot_len += slen; } if (pos < total - 1) { memmove (*arg + tot_len, b2c_option_delim, dlen);\n", g_FUNCTIONS);
fputs("tot_len += dlen; } } __b2c__SETLEN(*arg, tot_len); (*arg)[tot_len] = 0; } }\n", g_FUNCTIONS);
fputs("int __b2c_utf8_conv(int txt, char* utf8) { unsigned char b1, b2, b3; int len; if (txt > 0xFFFF) { b1 = txt & 0x0000FF; b2 = (txt & 0x00FF00) >> 8; b3 = (txt & 0xFF0000) >> 16;\n", g_FUNCTIONS);
fputs("len = snprintf (utf8, 5, \"%c%c%c%c\", 0xF0 | (b3 >> 2), 0x80 | ((b3 & 0x03) << 4) | ((b2 & 0xF0) >> 4), 0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6),\n", g_FUNCTIONS);
fputs("0x80 | (b1 & 0x3F)); } else if (txt > 0x07FF) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 4, \"%c%c%c\", 0xE0 | ((b2 & 0xF0) >> 4),\n", g_FUNCTIONS);
fputs("0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else if (txt > 0x007F) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 3, \"%c%c\",\n", g_FUNCTIONS);
fputs("0xC0 | (b2 << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else { len = snprintf (utf8, 2, \"%c\", txt & 0x7F); } return(len); }\n", g_FUNCTIONS);
fputs("unsigned long b2c_ulen (int l, char *k, char *func, char *ptr, int pos) { long len = 0; if (ptr == NULL) { return(0); } if(pos < 0) { while(*ptr){ if((*ptr&0xF0) == 0xF0) { len++; ptr += 4; } else if((*ptr&0xE0) == 0xE0) { len++; ptr += 3; }\n", g_FUNCTIONS);
fputs("else if((*ptr&0xC0) == 0xC0) { len++; ptr += 2; } else if((*ptr&0x80) == 0) { len++; ptr++; } else { ERROR = 38; RUNTIMEFERR(func, ERROR, k, l); return(0); } } } else { len = b2c_ucs2_clen(l, k, \"ULEN\", ptr, pos); } return(len); }\n", g_FUNCTIONS);
fputs("unsigned long b2c_blen (int l, char *k, char *func, char *ptr, long c, int flag) { char *org = ptr; if (ptr == NULL){ return (0); }\n", g_FUNCTIONS);
fputs("if(flag) { c = b2c_ulen (l, k, \"BYTELEN\", org, -1)-c; } while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; } else if ((*ptr & 0xE0) == 0xE0) { ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; } else if ((*ptr & 0x80) == 0)\n", g_FUNCTIONS);
fputs("{ ptr++; } else { ERROR = 38; fprintf (stderr, \"Cannot decode UTF-8 string: '%s'\\n\", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } c--; } if(flag) { return (b2c_len(org) - (ptr - org)); } else { return (ptr - org); } }\n", g_FUNCTIONS);
fputs("unsigned long b2c_ucs2_clen (int l, char* k, char *func, char *ptr, int c) { int len = 0; char *org; if (ptr == NULL) return (0); org = ptr; while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; c -= 4; } else if ((*ptr & 0xE0) == 0xE0)\n", g_FUNCTIONS);
fputs("{ ptr += 3; c -= 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; c -= 2; } else if ((*ptr & 0x80) == 0) { ptr++; c--; } else { ERROR = 38; fprintf(stderr, \"Cannot decode UTF-8 string: '%s'\\n\", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } len++; } return (len); }\n", g_FUNCTIONS);
    if( REGEX(g_DEPEND, "B64DEC\\$\\(|B64ENC\\$\\(") ){
    fputs("/* Portions of this code based on Bob Trower's C implementation at http://base64.sourceforge.net - MIT licensed */ static const char cd64[]=\"|$$$}rstuvwxyz{$$$$$$$>?@ABCDEFGHIJKLMNOPQRSTUVW$$$$$$XYZ[\\\\]^_`abcdefghijklmnopq\";\n", g_FUNCTIONS);
    fputs("static const char cb64[]=\"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/\"; static void b2c_encodeblock( unsigned char *in, unsigned char *out, int len)\n", g_FUNCTIONS);
    fputs("{ out[0] = (unsigned char) cb64[ (int)(in[0] >> 2) ]; out[1] = (unsigned char) cb64[ (int)(((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)) ];\n", g_FUNCTIONS);
    fputs("out[2] = (unsigned char) (len > 1 ? cb64[ (int)(((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)) ] : '='); out[3] = (unsigned char) (len > 2 ? cb64[ (int)(in[2] & 0x3f) ] : '='); }\n", g_FUNCTIONS);
    fputs("char * b2c_b64enc (char* src, int len) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[4]; int i, j, cur = 0, posit = 0; if (src == NULL) { return(NULL); }\n", g_FUNCTIONS);
    fputs("if (len == 0) { len = b2c_len (src); } if (len == 0) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ((len + 2) / 3) * 4 + 1);\n", g_FUNCTIONS);
    fputs("while( cur < len ){ for( i = 0; i < 3 && (cur + i < len); i++ ){ in[i] = (unsigned char) src[cur+i]; } in[i] = 0; cur += i; if( i > 0 ) { b2c_encodeblock( in, out, i );\n", g_FUNCTIONS);
    fputs("for( j = 0; j < 4; j++ ) { buf[idx][posit+j] = out[j]; } posit += 4; } } buf[idx][posit] = '\\0'; __b2c__SETLEN (buf[idx], posit); return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    fputs("static void b2c_decodeblock(unsigned char in[4], unsigned char out[3]) { out[0] = (unsigned char ) (in[0] << 2 | in[1] >> 4); out[1] = (unsigned char)(in[1] << 4 | in[2] >> 2);\n", g_FUNCTIONS);
    fputs("out[2] = (unsigned char ) (((in[2] << 6) & 0xc0) | in[3]); }\n", g_FUNCTIONS);
    fputs("char *b2c_b64dec(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[3], v; int i = 0, stlen, dec_len, len, cur = 0, posit = 0; if(src == NULL){ return (NULL); }\n", g_FUNCTIONS);
    fputs("stlen = b2c_len (src); if (stlen == 0) { return (NULL); } if(stlen % 4) { ERROR = 5; RUNTIMEFERR (\"B64DEC$\", ERROR, k, l); return(NULL); } dec_len = 3*stlen/4; while(src[stlen+i-1] == 61) { dec_len--; i--; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], dec_len + 4); while(cur < stlen){ for (len = 0, i = 0; i < 4 && (cur < stlen); i++) { v = 0; while (cur < stlen && v == 0){ v = (unsigned char) src[cur]; cur++; v = (unsigned char) ((v < 43 || v > 122) ? 0 : cd64[ v - 43 ]);\n", g_FUNCTIONS);
    fputs("if (v) {v = (unsigned char) ((v == '$') ? 0 : v - 61);} } if(cur <= stlen){ len++; if (v) { in[i] = (unsigned char)(v - 1); } else { in[i] = 0; } } } if(len){ b2c_decodeblock(in, out);\n", g_FUNCTIONS);
    fputs("for(i = 0; i < len - 1; i++) { buf[idx][posit + i] = out[i]; } buf[idx][posit + i] = '\\0'; posit += len - 1; } } __b2c__SETLEN(buf[idx], dec_len); return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "BIT\\(|BIN\\$\\(|ROL\\(|ROR\\(") ){
    fputs("unsigned long b2c_bit(long x) { return(x ? 2<<(x-1) : 1); } unsigned long b2c_rol(int type, long x)\n", g_FUNCTIONS);
    fputs("{ return((x)&lrint(pow(2, type*8-1)) ? (((x)<<1)|1)&lrint(pow(2, type*8)-1) : ((x)<<1)&lrint(pow(2, type*8)-1)); }\n", g_FUNCTIONS);
    fputs("unsigned long b2c_ror(int type, long x) { return((x)&1 ? (((x)>>1)&lrint(pow(2, type*8)-1))|lrint(pow(2, type*8-1)) : ((x)>>1)&lrint(pow(2, type*8)-1)); }\n", g_FUNCTIONS);
    fputs("char *b2c_bin(int type, long x) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], type*8+1); for(i = 0; i<type*8; i++) { if(x&1) { buf[idx][type*8-1-i] = 49; } else { buf[idx][type*8-1-i] = 48; }\n", g_FUNCTIONS);
    fputs("x = x>>1; } buf[idx][type*8] = '\\0'; __b2c__SETLEN(buf[idx], type*8); return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "CHOP\\$\\(") ){
    fputs("char *b2c_chop(char **swap, int type, char *source, char *string, int location) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long length; if (source == NULL || *source == '\\0') { if (type == 1) { *swap = b2c_CopyString(*swap, NULL); } return (NULL); } if (string == NULL) { string = (char *) b2c_chop_default; }\n", g_FUNCTIONS);
    fputs("idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } length = b2c_len(string); if (location == 0 || location == 1) { while (*source != '\\0') { if(memchr(string, *source, length)) { source++; } else { break; } } if (*source == '\\0'){ if (type == 1) { *swap = b2c_CopyString (*swap, NULL); } return(NULL); } } tmp = source + b2c_len(source) - 1;\n", g_FUNCTIONS);
    fputs("if(location == 0 || location == 2) { while (tmp >= source && *tmp != '\\0') { if(memchr(string, *tmp, length)) { tmp--; } else { break; } } } tmp++; buf[idx] = (char*)__b2c_str_realloc(buf[idx], tmp-source+1); memmove(buf[idx], source, tmp - source);\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], tmp - source); buf[idx][tmp - source] = '\\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "CHR\\$\\(|COUNT\\(|ESCAPE\\$\\(|ISASCII\\(|ISUTF8\\(|TOASCII\\$\\(|UCS\\(|UTF8\\$\\(") ){
    fputs("char *b2c_asc2char (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2); len = snprintf(buf[idx], 2, \"%c\", i); __b2c__SETLEN(buf[idx], len); return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    fputs("char *b2c_asc2utf8 (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; char buffer[5]; len = __b2c_utf8_conv(i, buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memcpy(buf[idx], buffer, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    fputs("unsigned int b2c_utf8toasc(char* ptr) { unsigned int result = 0; if((*ptr&0xF0)==0xF0) { result = (*ptr&0x07)<<2; ptr++; result = result | ((*ptr&0x30)>>4); result = result << 8; result = result | ((*ptr&0x0F)<<4);\n", g_FUNCTIONS);
    fputs("ptr++; result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xE0)==0xE0) { result = (*ptr&0x0F)<<4; ptr++;\n", g_FUNCTIONS);
    fputs("result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xC0)==0xC0) { result = (*ptr&0x1C)>>2; result = result << 8;\n", g_FUNCTIONS);
    fputs("result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0x80) == 0) { result = (*ptr&0x7F); } return (result); }\n", g_FUNCTIONS);
    fputs("unsigned char b2c_isascii(const char *ptr) { long x; for(x=0; *(ptr+x); x++) { if(*(ptr+x)&128) return(0); } return(1); }\n", g_FUNCTIONS);
    fputs("unsigned char b2c_isutf8(const char *ptr) { int result = 1; if (ptr == NULL) { return (0); } while (*ptr) { if ((*ptr & 0xF0) == 0xF0)\n", g_FUNCTIONS);
    fputs("{ if ((*(ptr + 1) & 0xC0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 || (*(ptr + 3) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 4; } else if ((*ptr & 0xE0) == 0xE0)\n", g_FUNCTIONS);
    fputs("{ if ((*(ptr + 1) & 0xc0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { if ((*(ptr + 1) & 0xc0) != 0x80 )\n", g_FUNCTIONS);
    fputs("{ result = 0; break; } ptr += 2; } else if ((*ptr & 0x80) == 0) { ptr++; } else { result = 0; break; } } return (result); }\n", g_FUNCTIONS);
    fputs("char *b2c_toascii(char *ptr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len, x; len = b2c_len (ptr); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], len); for(x = 0; x < len; x++) { *(buf[idx] + x) = *(ptr + x) & 0x7f; } __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\\0'; return((char*)buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "CMDLINE\\(") ){
    fputs("int b2c_getopt(int argc, char **argv, char* str){int opt; extern char *optarg; extern int optind, opterr; opterr = 0; opt = getopt(argc, argv, str); if(opt != -1)\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "{ ARGUMENT%s = b2c_CopyString(ARGUMENT%s, optarg); } else { ARGUMENT%s = b2c_CopyString(ARGUMENT%s, argv[optind]); } return(opt); }\n", g_STRINGSIGN, g_STRINGSIGN, g_STRINGSIGN, g_STRINGSIGN);
    }
    if( REGEX(g_DEPEND, "APPEND[[:space:]]|&|\\+|CONCAT\\$\\(|LOOP\\$\\(") ){
    fputs("char *b2c_concat(int n, ...) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } idx++;\n", g_FUNCTIONS);
    fputs("if (idx == __b2c_STRING_FUNC) { idx = 0; } va_start (ap, n); if(buf[idx]) { buflen = __b2c__RBUFSIZE(buf[idx]); } while (n) { next = va_arg (ap, char *); if (next) { cnew = b2c_len (next);\n", g_FUNCTIONS);
    fputs("if(length+cnew >= buflen) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + cnew); buflen = __b2c__RBUFSIZE(buf[idx]); } memcpy(buf[idx] + length, next, cnew); length += cnew; }\n", g_FUNCTIONS);
    fputs("n--; } va_end (ap); if (buf[idx]) { __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\\0'; } return ((char *) buf[idx]); }\n", g_FUNCTIONS);
    fputs("char *b2c_concat2(int total, ...) { char *iter, *result, *first, *next, *offset; int n_copy = 0, pos = 0, length = 0, cnew, flen = 0, stage = 0; uint32_t lbufsize = 0, rbufsize = 0; va_list ap_copy, ap; va_start (ap, total);\n", g_FUNCTIONS);
    fputs("first = result = offset = va_arg (ap, char *); total--; if (total == 0) { return (NULL); } va_copy (ap_copy, ap); if(first) { n_copy = total; } while (n_copy) { iter = va_arg (ap_copy, char *); if (iter == first) { flen = b2c_len (first); break; }\n", g_FUNCTIONS);
    fputs("pos += b2c_len (iter); n_copy--; } va_end (ap_copy); if (__b2c_str_realloc_get_string(result) ) { lbufsize = __b2c__LBUFSIZE (result); rbufsize = __b2c__RBUFSIZE (result); }\n", g_FUNCTIONS);
    fputs("else { rbufsize = b2c_len(first); } if (n_copy) { if (pos >= lbufsize) { result = (char *) __b2c_str_realloc_left(result, lbufsize + rbufsize + pos); offset = result; } __b2c_str_realloc_del_string(result);\n", g_FUNCTIONS);
    fputs("memmove (result - __b2c__BUFOFFSET - pos, result - __b2c__BUFOFFSET, __b2c__BUFOFFSET); result -= pos; __b2c_str_realloc_add_string(result); __b2c__LBUFSIZE (result) -= pos; __b2c__RBUFSIZE (result) += pos;\n", g_FUNCTIONS);
    fputs("rbufsize = __b2c__RBUFSIZE (result); } next = va_arg (ap, char *); total--; while (total >= 0) { if (next) { if (next == first) { cnew = flen; } else { cnew = b2c_len (next); } if (cnew + flen + length >= rbufsize)\n", g_FUNCTIONS);
    fputs("{ result = (char *) __b2c_str_realloc (result, cnew + flen + length); rbufsize = __b2c__RBUFSIZE (result); offset = result + pos; } if (next != first) { memmove (result + length, next, cnew); } else { if (stage == 0) { stage = 1; } else\n", g_FUNCTIONS);
    fputs("{ memmove (result + length, offset, cnew); } } length += cnew; } next = va_arg (ap, char *); total--; } va_end (ap); if(result) { __b2c__SETLEN (result, length); result[length] = '\\0'; } return ((char *) result); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "COUNT\\(") ){
    fputs("long b2c_count (int l, char *k, char *x, unsigned int y) { long i, z = 0; if(x == NULL) { return(0); } if (b2c_option_utf8) { while (*x) { if (b2c_utf8toasc (x) == y) { z++; } if ((*x & 0xF0) == 0xF0) { x += 4; }\n", g_FUNCTIONS);
    fputs("else if ((*x & 0xE0) == 0xE0) { x += 3; } else if ((*x & 0xC0) == 0xC0) { x += 2; } else if ((*x & 0x80) == 0) { x++; } else { ERROR = 38; RUNTIMEFERR (\"COUNT\", ERROR, k, l); return(0); } } } else \n", g_FUNCTIONS);
    fputs("{ for (i = 0; x[i] != '\\0'; i++) { if (x[i] == y) { z++; } } } return z; }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "CURDIR\\$") ){
    fprintf(g_FUNCTIONS, "char *b2c_curdir (void) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], %s);\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "buf[idx] = getcwd(buf[idx], %s); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][%s-1] = '\\0'; return(char*)(buf[idx]); }\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    }
    if( REGEX(g_DEPEND, "MONTH\\$\\(|WEEKDAY\\$\\(") ){
    fputs("char* b2c_datename(time_t now, int which) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; struct tm *ts; int len = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "buf[idx] = (char*)__b2c_str_realloc(buf[idx], %s); ts = localtime (&now); switch (which) { case 1: len = strftime(buf[idx], %s, \"%A\", ts); break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 2: len = strftime(buf[idx], %s, \"%B\", ts); break; } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", STR( g_MAX_DIGITS));
    }
    if( REGEX(g_DEPEND, "DEC\\(") ){
    fputs("uint64_t b2c_hex2dec (int l, char *k, char *h, int flag) { uint64_t j=0; char *status = NULL; if(h == NULL) { return(0); } if(flag == 1) { flag = 2; } else if(flag > 36) {ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); }\n", g_FUNCTIONS);
    fputs("if(flag == 0) { j = strtol(h, &status, 16); if(*status != '\\0') { ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); } } else { j = strtol(h, &status, flag);\n", g_FUNCTIONS);
    fputs("if(*status != '\\0') { ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); } } return(uint64_t)(j); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "BASENAME\\$\\(|DIRNAME\\$\\(|REALPATH\\$\\(") ){
    fputs("#ifndef PATH_MAX\n", g_FUNCTIONS);
    fputs("#define PATH_MAX 4096\n", g_FUNCTIONS);
    fputs("#endif\n", g_FUNCTIONS);
    fputs("char *b2c_dirname(int l, char *k, int x, char *y, long arg) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i; char *dup; if(y == NULL || b2c_len(y) == 0){ return(NULL); }\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], PATH_MAX*sizeof(char)); dup = b2c_strdup(y); switch(x) {case 0: if ((realpath(y, buf[idx])) == NULL) { ERROR = 26; RUNTIMEFERR(\"REALPATH$\", ERROR, k, l); strncpy(buf[idx], \"Error getting real path\",%s);\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "return(NULL); } break; case 1: if(strncpy(buf[idx], basename(dup), PATH_MAX) == NULL) { ERROR = 26; RUNTIMEFERR(\"BASENAME$\", ERROR, k, l); strncpy (buf[idx], \"Error getting basename\",%s); return(NULL); }\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "break; case 2: if(strncpy(buf[idx], dirname(dup), PATH_MAX) == NULL) { ERROR = 26; RUNTIMEFERR(\"DIRNAME$\", ERROR, k, l); strncpy(buf[idx], \"Error getting dirname\",%s); return(NULL); }\n", STR( g_BUFFER_SIZE));
    fputs("break; } __b2c__STRFREE(dup); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][PATH_MAX - 1] = '\\0'; if(arg && x==1){ for(i=b2c_len(buf[idx]); i>=0; i--) { if(buf[idx][i] == 46) break; }\n", g_FUNCTIONS);
    fputs("if(i >= 0){ if(arg == 1) {buf[idx][i] = '\\0'; __b2c__SETLEN(buf[idx], i);} if(arg == 2){ i++; memmove(buf[idx], buf[idx]+i, b2c_len(buf[idx])-i+1);\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], b2c_len(buf[idx])-i);} } else if(arg == 2) {buf[idx][0] = '\\0'; __b2c__SETLEN(buf[idx], 0);} } return(char*)(buf[idx]);}\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "TIMEVALUE\\(") ){
    fputs("unsigned long b2c_epoch(int year, int month, int day, int hour, int minute, int second){struct tm tm; time_t t; tm.tm_year = year - 1900; tm.tm_mon = month - 1; tm.tm_mday = day;\n", g_FUNCTIONS);
    fputs("tm.tm_hour = hour; tm.tm_min = minute; tm.tm_sec = second; tm.tm_isdst = -1; t = mktime(&tm); if (t == -1) return (0); return(long) t; }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "EXEC\\$\\(|RUN\\$\\(") ){
    fputs("static char **__b2c__Get_Args(char *line) { char **ptr = NULL; long start, x, collapse; long length = 0, amount = 0; collapse = b2c_collapse; b2c_collapse = 1; start = b2c_delim_engine (2, &amount, line, \" \", 0); ptr = (char**)calloc(amount, sizeof(char*));\n", g_FUNCTIONS);
    fputs("for(x = 0; x < amount; x++) { start = b2c_delim_engine_cache (1, &length, line, \" \", x + 1); ptr[x] = b2c_strndup(line+start, length); } ptr[x] = NULL; b2c_collapse = collapse; return (ptr); }\n", g_FUNCTIONS);
    fputs("char * b2c_exec(int t, int l, char *k, char *cmd, char *str, int out) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int forking, length, dnull; ssize_t result = 0; int wpipe[2], rpipe[2]; char **args; char *ans = NULL;\n", g_FUNCTIONS);
    fputs("idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char)); if (pipe (rpipe) < 0 || pipe (wpipe) < 0) { ERROR = 29; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); } if ((forking = fork ()) < 0) { ERROR = 29; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }\n", g_FUNCTIONS);
    fputs("else if (forking == 0) { fflush(stdout); close (wpipe[1]); close (rpipe[0]); dup2 (wpipe[0], STDIN_FILENO); close (wpipe[0]); dnull = open(\"/dev/null\", O_RDWR); if(out == 1) { dup2 (rpipe[1], STDOUT_FILENO); dup2(dnull, STDERR_FILENO); } else if (out == 2) { dup2(dnull, STDOUT_FILENO);\n", g_FUNCTIONS);
    fputs("dup2(rpipe[1], STDERR_FILENO); } else { dup2(rpipe[1], STDOUT_FILENO); dup2(rpipe[1], STDERR_FILENO); } close (rpipe[1]); if(t == 0) { forking = system (cmd); if (WIFEXITED (forking)) result = WEXITSTATUS (forking); }\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "else { args = __b2c__Get_Args(cmd); if(execvp(args[0], args) < 0 ) { ERROR = 29; RUNTIMEFERR (\"EXEC$\", ERROR, k, l); return(NULL); } } close(dnull); __b2c_str_free(); _exit(result); } else { close (wpipe[0]); close (rpipe[1]); ans = (char*)malloc(%s);\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "length = 0; if (str != NULL) result = write (wpipe[1], str, b2c_len(str)); close (wpipe[1]); do { result = read (rpipe[0], ans, %s); if (result == -1) { ERROR = 30; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }\n", STR( g_BUFFER_SIZE));
    fputs("if (result == 0) { break; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + result + 1); if(buf[idx] == NULL) { ERROR = 6; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }\n", g_FUNCTIONS);
    fputs("memcpy(buf[idx] + length, ans, (size_t)labs(result)); length += result; } while (result > 0); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0';\n", g_FUNCTIONS);
    fputs("close (rpipe[0]); free (ans); wait (&RETVAL); RETVAL = WEXITSTATUS (RETVAL); } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FILEEXISTS\\(|FILELEN\\(") ){
    fputs("long b2c_filestat(int l, char *k, const char *x, int check) { struct stat buf = { 0 }; int result; if(x == NULL) { if(check == 0) { return(-1); } return(0); } result = stat(x, &buf); if(result < 0 && check == 0)\n", g_FUNCTIONS);
    fputs("{ ERROR = 24; RUNTIMEFERR(\"FILELEN\", ERROR, k, l); return(-1); } if(check == 0) { return((long)buf.st_size); } if(buf.st_mode) { return(1); } return(0); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FILETIME\\(") ){
    fputs("long b2c_filetime(int l, char *k, const char *x, int y) { struct stat buf = { 0 }; int result; if (x == NULL || y < 0 || y > 2) { return(-1); } result = stat(x, &buf); if(result < 0)\n", g_FUNCTIONS);
    fputs("{ ERROR = 24; RUNTIMEFERR(\"FILETIME\", ERROR, k, l); return(-1); } if(y == 0) { return((long)buf.st_atime); } if(y == 1) { return((long)buf.st_mtime); } return((long)buf.st_ctime); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FILETYPE\\(") ){
    fputs("int b2c_filetype(int l, char *k, const char *file) { int type = 0; struct stat buf = { 0 }; if(file == NULL) { return(0); } if(lstat(file, &buf) < 0) { ERROR = 24; RUNTIMEFERR (\"FILETYPE\", ERROR, k, l); return(0); }\n", g_FUNCTIONS);
    fputs("switch (buf.st_mode & S_IFMT) { case S_IFBLK: type = 4; break; case S_IFCHR: type = 3; break; case S_IFDIR: type = 2; break; case S_IFIFO: type = 5; break; case S_IFLNK: type = 6; break;\n", g_FUNCTIONS);
    fputs("case S_IFREG: type = 1; break; case S_IFSOCK: type = 7; break; default: ERROR = 24; RUNTIMEFERR(\"FILETYPE\", ERROR, k, l); return(0); break; } return(type); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FILL\\$\\(") ){
    fputs("char * b2c_fill(long amount, int txt) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char bf[5]; int x, len; if(amount < 0 || txt > 0x10FFFF) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } if (b2c_option_utf8)\n", g_FUNCTIONS);
    fputs("{ len = __b2c_utf8_conv (txt, bf); buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount*len+1); for (x = 0; x < (amount * len); x += len) { memcpy(buf[idx] + x, bf, len); } __b2c__SETLEN(buf[idx], amount * len); buf[idx][amount * len] = '\\0'; } else\n", g_FUNCTIONS);
    fputs("{ buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1); memset(buf[idx], txt, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\\0'; } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FLATTEN\\$\\(|UNFLATTEN\\$\\(") ){
    fputs("char *b2c_flatten(char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long len, x, pos=0, escaped=0; quote[0] = b2c_option_dq; if(src == NULL) { return(src); }\n", g_FUNCTIONS);
    fputs("if (meta == NULL) { meta = quote; } len = b2c_len(src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx], src, len); buf[idx][len] = '\\0'; for(x = 0; src[x] != 0; x++) { if(src[x] == meta[0]) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); }\n", g_FUNCTIONS);
    fputs("else { pos++; escaped = 0; } } else { if(src[x] == b2c_option_esc) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); escaped = 1; } else { pos++; } }\n", g_FUNCTIONS);
    fputs("else { pos++; escaped = 0; } } } __b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    fputs("char * b2c_unflatten (char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long x, pos = 1; quote[0] = b2c_option_dq; if (src == NULL) { return (src); }\n", g_FUNCTIONS);
    fputs("if (meta == NULL) { meta = quote; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2*b2c_len(src)+1); buf[idx][0] = meta[0];\n", g_FUNCTIONS);
    fputs("for (x = 0; src[x] != 0; x++) { if (src[x] == meta[0]) { buf[idx][pos++] = b2c_option_esc; buf[idx][pos++] = src[x]; } else {buf[idx][pos++] = src[x];} } buf[idx][pos++] = meta[0];\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "GETENVIRON\\$\\(") ){
    fputs("char *b2c_getenv (char *env) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *result; long len; if(env == NULL) { return(NULL); } result = getenv (env); if(result == NULL) { return(NULL); } len = strlen(result); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], (len+1)*sizeof(char)); strncpy(buf[idx], result, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "GETKEY|TRACE[[:space:]]") ){
    fputs("long b2c_getch(void){long ch; struct termios oldt, newt; tcflush(STDIN_FILENO, TCIFLUSH); tcgetattr(STDIN_FILENO, &oldt); newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1;\n", g_FUNCTIONS);
    fputs("newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt); ch = getchar(); tcsetattr(STDIN_FILENO, TCSANOW, &oldt); return(ch);}\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "GETPEER\\$\\(") ){
        if( INSTR(OS, "OSF1") ){
            line = b2c_CopyString(line, (char*) "int");
        } else {
            line = b2c_CopyString(line, (char*) "unsigned int");
        }
    fprintf(g_FUNCTIONS, "char * b2c_getpeer(int l, char *k, uintptr_t remote) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; struct sockaddr_in *peer; %s length = sizeof (peer); char port[6]; int desc = 0; peer = (struct sockaddr_in*)calloc (1, sizeof(*peer));\n", line);
        if( g_OPTION_TLS ){
            if( TALLY(g_LIB_TLS, "gnutls") ){
            fputs("if(b2c_option_tls) { BIO_get_fd(((SSL*)remote)->gnutls_state, &desc); }\n", g_FUNCTIONS);
            } else {
            fputs("if(b2c_option_tls) { desc = SSL_get_fd((SSL*)remote); }\n", g_FUNCTIONS);
            }
        }
    fprintf(g_FUNCTIONS, "if(!b2c_option_tls) { desc = remote; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], %s*sizeof(char));\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "if (getpeername(desc, (struct sockaddr *) peer, &length) < 0) { free(peer); ERROR = 16; RUNTIMEFERR(\"GETPEER$\", ERROR, k, l); strncpy(buf[idx], \"Peer not found\", %s); return(NULL); }\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "else { strncpy(buf[idx], inet_ntoa (peer->sin_addr), %s-7); strcat(buf[idx], \":\"); snprintf (port, 6, \"%d\", ntohs (peer->sin_port)); strcat(buf[idx], port); }\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "free (peer); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][%s-1] = '\\0'; return(char*)(buf[idx]);}\n", STR( g_BUFFER_SIZE));
    }
    if( REGEX(g_DEPEND, "GETX|GETY") ){
    fprintf(g_FUNCTIONS, "long b2c_getxy(int type){char asw[%s]; struct termios old, cnew; int len, x = 0, y = 0; tcgetattr(STDIN_FILENO, &old); cnew = old; cnew.c_lflag &= ~(ICANON | ECHO); tcsetattr(STDIN_FILENO, TCSANOW, &cnew);\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "if(write(STDOUT_FILENO, \"\\033[6n\", 4)>=0){len = read(STDIN_FILENO, asw, %s); asw[len] = '\\0'; tcsetattr(STDIN_FILENO, TCSANOW, &old); sscanf(asw, \"\\033[%d;%dR\", &y, &x);} if (!type) return(long)x; return(long)y;}\n", STR( g_BUFFER_SIZE));
    }
    if( REGEX(g_DEPEND, "ASSOC[[:space:]]|HASH\\(|INDEX\\(|LOOKUP[[:space:]]|OBTAIN\\$\\(|SORT[[:space:]]|TREE[[:space:]]|UNIQ\\$\\(") ){
    fputs("int b2c_sortnrd(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(-1); else return(1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrd_wrap(const void *a, const void *b) { return(b2c_sortnrd(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrd_down(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(1); else return(-1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrd_wrap_down(const void *a, const void *b) { return(b2c_sortnrd_down(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrf(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(-1); else return(1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrf_wrap(const void *a, const void *b) { return(b2c_sortnrf(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrf_down(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(1); else return(-1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrf_wrap_down(const void *a, const void *b) { return(b2c_sortnrf_down(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrl(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(-1); else return(1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrl_wrap(const void *a, const void *b) { return(b2c_sortnrl(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrl_down(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(1); else return(-1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrl_wrap_down(const void *a, const void *b) { return(b2c_sortnrl_down(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnri(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(-1); else return(1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnri_wrap(const void *a, const void *b) { return(b2c_sortnri(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnri_down(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(1); else return(-1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnri_wrap_down(const void *a, const void *b) { return(b2c_sortnri_down(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrs(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(-1); else return(1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrs_wrap(const void *a, const void *b) { return(b2c_sortnrs(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrs_down(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(1); else return(-1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrs_wrap_down(const void *a, const void *b) { return(b2c_sortnrs_down(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrc(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(-1); else return(1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrc_wrap(const void *a, const void *b) { return(b2c_sortnrc(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    fputs("int b2c_sortnrc_down(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(1); else return(-1);}\n", g_FUNCTIONS);
    fputs("int b2c_sortnrc_wrap_down(const void *a, const void *b) { return(b2c_sortnrc_down(*(void**)a, *(void**)b)); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ASSOC[[:space:]]|HASH\\(|INDEX\\(|LOOKUP[[:space:]]|OBTAIN\\$\\(|SORT[[:space:]]|SORT\\$\\(|TREE[[:space:]]|UNIQ\\$\\(") ){
    fputs("int b2c_sortstr(const void *a, const void *b)\n", g_FUNCTIONS);
    fputs("{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)a, *(char **)b);}\n", g_FUNCTIONS);
    fputs("int b2c_sortstr2(const void *a, const void *b)\n", g_FUNCTIONS);
    fputs("{if(a == NULL) return(-1); if(b == NULL) return(1); return strcmp((char*)a, (char*)b);}\n", g_FUNCTIONS);
    fputs("int b2c_sortstr_down(const void *a, const void *b)\n", g_FUNCTIONS);
    fputs("{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)b, *(char **)a);}\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ASSOC[[:space:]]|EXTRACT\\$\\(|HASH\\(|INDEX\\$\\(|INVERT\\(|LOOKUP[[:space:]]|OBTAIN\\$\\(|REGEX\\(|REPLACE\\$\\(|SORT[[:space:]]|UNIQ\\$\\(|WALK\\$\\(") ){
    fputs("typedef struct b2c_htable { char *key[65536]; void *value[65536]; char *index[65536]; int total; struct b2c_htable *next; } b2c_htable;\n", g_FUNCTIONS);
    fputs("const char *b2c_hash_key_collect(int n, const char *first, ...) { static char *keys[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } if (n == 1) { return (first); }\n", g_FUNCTIONS);
    fputs("idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (keys[idx]) { buflen = __b2c__RBUFSIZE(keys[idx]); } cnew = b2c_len(first); if(cnew >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], cnew); buflen = __b2c__RBUFSIZE(keys[idx]); }\n", g_FUNCTIONS);
    fputs("memcpy(keys[idx], first, cnew); length += cnew; n--; va_start (ap, first); while (n) { next = va_arg (ap, char *); if (next) { cnew = b2c_len (next); if(length + cnew + 1 >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], (length + cnew + 1 + 1) * sizeof (char));\n", g_FUNCTIONS);
    fputs("buflen = __b2c__RBUFSIZE(keys[idx]); } keys[idx][length] = 32; length++; memmove (keys[idx] + length, next, cnew); length += cnew; } n--; } va_end (ap); __b2c__SETLEN(keys[idx], length); keys[idx][length] = '\\0'; return ((char *) keys[idx]); }\n", g_FUNCTIONS);
    fputs("#define __b2c__KEYCOLLECT(...) b2c_hash_key_collect(sizeof((const char*[]){__VA_ARGS__}) / sizeof(char*), __VA_ARGS__, NULL)\n", g_FUNCTIONS);
    fputs("uint64_t __b2c__HashFNV1a_64(const char *key, int len){ uint64_t hash = 14695981039346656037UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 1099511628211 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 1099511628211 * (hash ^ *key); key++; } } return(hash); }\n", g_FUNCTIONS);
    fputs("uint32_t __b2c__HashFNV1a_32(const char *key, int len){ uint32_t hash = 2166136261UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 16777619 * (hash ^ *key); key++; } } return(hash); }\n", g_FUNCTIONS);
    fputs("#define __b2c__HashFNV1a_16(x) __b2c__HashFNV1a_16_new(x, 0)\n", g_FUNCTIONS);
    fputs("uint16_t __b2c__HashFNV1a_16_new(const char *key, int len) { uint32_t hash = 2166136261UL; if (key == NULL) { return (0); } if (len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else\n", g_FUNCTIONS);
    fputs("{ while (*key) { hash = 16777619 * (hash ^ *key); key++; } } return ((hash >> 16) ^ (hash & 0xffff)); }\n", g_FUNCTIONS);
    fputs("b2c_htable *b2c_hash_new(void) { b2c_htable *name; name = (b2c_htable*)calloc(1, sizeof(b2c_htable)); name->next = NULL; name->total = 0; return(name); }\n", g_FUNCTIONS);
    fputs("b2c_htable* b2c_hash_find_key_do(b2c_htable *name, unsigned short hash, const char *key) { if(key == NULL || name == NULL) { return(NULL); } if(hash == 0) { hash = __b2c__HashFNV1a_16(key); } do\n", g_FUNCTIONS);
    fputs("{ if(name->key[hash] && !strcmp(name->key[hash], key)) { return(name); } name = name->next; } while(name); return(NULL); }\n", g_FUNCTIONS);
    fputs("#define b2c_hash_find_key(x, y, ...) b2c_hash_find_key_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("void *b2c_hash_find_value_do(b2c_htable *name, const char *key) { b2c_htable *table; unsigned short pos; if(name == NULL || key == NULL) { return(NULL); } pos = __b2c__HashFNV1a_16(key); table = b2c_hash_find_key(name, pos, key);\n", g_FUNCTIONS);
    fputs("if(table) { return(table->value[pos]); } return(NULL); }\n", g_FUNCTIONS);
    fputs("#define b2c_hash_find_value(x, ...) b2c_hash_find_value_do(x, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("void b2c_hash_add_do(b2c_htable *name, const void *value, int flag, unsigned int len, const char *key) { unsigned short hash; if(name == NULL) { return; } hash = __b2c__HashFNV1a_16(key);\n", g_FUNCTIONS);
    fputs("while(1) { if(name->key[hash] == NULL) { name->total++; break; } if(!strcmp(name->key[hash], key)) { if(flag != 2) { break; } } if(name->next) { name = name->next; } else { name->next = b2c_hash_new(); name = name->next;} }\n", g_FUNCTIONS);
    fputs("if(!name->key[hash]) { name->key[hash] = b2c_CopyString(name->key[hash], (char*)key); name->index[name->total-1] = name->key[hash]; } if(flag == 0) { if(!name->value[hash]) { name->value[hash] = calloc(1, sizeof(void*)); } memcpy(name->value[hash], value, sizeof(void*)); }\n", g_FUNCTIONS);
    fputs("else if(flag == 3) { name->value[hash] = realloc(name->value[hash], len); memcpy(name->value[hash], value, len); } else { name->value[hash] = b2c_CopyString((char*)name->value[hash], (char*)value); } }\n", g_FUNCTIONS);
    fputs("#define b2c_hash_add(x, y, ...) b2c_hash_add_do(x, y, 0, 0, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("#define b2c_hash_add_str(x, y, ...) b2c_hash_add_do(x, y, 1, 0, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("#define b2c_hash_add_redundant(x, y, ...) b2c_hash_add_do(x, y, 2, 0, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("#define b2c_hash_add_data(x, y, len, ...) b2c_hash_add_do(x, y, 3, len, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("void *b2c_hash_realloc_str_value_do(b2c_htable *name, int len, const char *key) { b2c_htable *table; unsigned short pos; if (name == NULL || key == NULL) { return (NULL); } b2c_hash_add_str(name, \"\", key); pos = __b2c__HashFNV1a_16(key);\n", g_FUNCTIONS);
    fputs("table = b2c_hash_find_key(name, pos, key); table->value[pos] = realloc(table->value[pos], len); return (table->value[pos]); }\n", g_FUNCTIONS);
    fputs("#define b2c_hash_realloc_str_value(x, y, ...) b2c_hash_realloc_str_value_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("void b2c_hash_del_do(b2c_htable *name, int rebuild, const char *key) { b2c_htable *found; unsigned short pos; int i, which; if(name == NULL) { return; } pos = __b2c__HashFNV1a_16(key); found = b2c_hash_find_key(name, pos, key);\n", g_FUNCTIONS);
    fputs("if(found) { if (rebuild) { for (i = 0; i < found->total; i++) { which = __b2c__HashFNV1a_16(found->index[i]); if (which == pos) { if(i != found->total-1) { found->index[i] = found->index[found->total-1]; } found->index[found->total-1] = NULL; break; } } }\n", g_FUNCTIONS);
    fputs("__b2c__STRFREE(found->key[pos]); found->key[pos] = NULL; if(found->value[pos]) { __b2c__STRFREE(found->value[pos]); } found->value[pos] = NULL; found->total -= 1; } }\n", g_FUNCTIONS);
    fputs("#define b2c_hash_del(x, ...) b2c_hash_del_do(x, 1, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("#define b2c_hash_del_norebuild(x, ...) b2c_hash_del_do(x, 0, __b2c__KEYCOLLECT(__VA_ARGS__))\n", g_FUNCTIONS);
    fputs("void b2c_hash_clear_do(b2c_htable *name, int regex) { b2c_htable *orig, *next; int i; orig = name; while(name) { for(i = 0; i < 65536; i++) { if(name->key[i]) { __b2c__STRFREE(name->key[i]); } name->key[i] = NULL;\n", g_FUNCTIONS);
    fputs("if(name->value[i]) { if(regex) { regfree(&(*(regex_t*)name->value[i])); } __b2c__STRFREE(name->value[i]); } name->value[i] = NULL; } next = name->next; name->next = NULL; name->total = 0; if(name != orig) { free(name); } name = next; } }\n", g_FUNCTIONS);
    fputs("#define b2c_hash_clear(x) b2c_hash_clear_do(x, 0)\n", g_FUNCTIONS);
    fputs("#define b2c_hash_clear_regfree(x) b2c_hash_clear_do(x, 1)\n", g_FUNCTIONS);
    fputs("int b2c_hash_nrkeys(b2c_htable *name) { int total = 0; while(name) { total += name->total; name = name->next; } return(total); }\n", g_FUNCTIONS);
    fputs("void b2c_hash_dup_do(b2c_htable *from, b2c_htable *to, int flag) { int i; char *value; while(from) { for(i = 0; i < 65536; i++) { if(from->key[i]) { value = (char*)b2c_hash_find_value(from, from->key[i]); if(flag==0) { b2c_hash_add(to, value, from->key[i]); } \n", g_FUNCTIONS);
    fputs("else { b2c_hash_add_str(to, value, from->key[i]); } } } from = from->next; if(to->next == NULL) { to->next = b2c_hash_new(); } to = to->next; } }\n", g_FUNCTIONS);
    fputs("#define b2c_hash_dup(x, y) b2c_hash_dup_do(x, y, 0)\n", g_FUNCTIONS);
    fputs("#define b2c_hash_dup_str(x, y) b2c_hash_dup_do(x, y, 1)\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "OBTAIN\\$\\(|UNIQ\\$\\(") ){
    fputs("char *b2c_hash_obtain(b2c_htable *name, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long ctr, dlen, len, total = 0; if(name == NULL) { return (NULL); } if(delim == NULL) { delim = b2c_option_delim; }\n", g_FUNCTIONS);
    fputs("if(name->total == 0) { return (NULL); } dlen = b2c_len(delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen); do { for(ctr=0; ctr < name->total; ctr++) { len = b2c_len(name->index[ctr]);\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+len+dlen); memmove(buf[idx] + total, name->index[ctr], len); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } name = name->next; }\n", g_FUNCTIONS);
    fputs("while(name); __b2c__SETLEN(buf[idx], total-dlen); buf[idx][total-dlen] = '\\0'; return((char*)buf[idx]); }\n", g_FUNCTIONS);
    fputs("char *b2c_hash_obtain_by_sort(int l, char *k, b2c_htable * name, char *delim, int up_down, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; void **values = { NULL }; char **keys = { NULL }; void **dups = { NULL }; b2c_htable *ptr, *inv; int i, j, pos = 0, start = 0, cur = 0; long dlen, len, total = 0;\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "unsigned short loc; char *value; char bf[%s + 1] = { 0 }; if (name == NULL || name->total == 0) { return (NULL); } if (delim == NULL) { delim = b2c_option_delim; } values = (void **) calloc (b2c_hash_nrkeys (name), sizeof (char *)); inv = b2c_hash_new (); ptr = name; do { for(i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16(ptr->index[i]); switch(type)\n", STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "{ case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (bf, %s, \"%g\", *(double *) ptr->value[loc]); value = bf; break; case 2: snprintf (bf, %s, \"%g\", *(float *) ptr->value[loc]); value = bf; break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 3: snprintf (bf, %s, \"%ld\", *(long *) ptr->value[loc]); value = bf; break; case 4: snprintf (bf, %s, \"%d\", *(int *) ptr->value[loc]); value = bf; break; case 5: snprintf (bf, %s, \"%d\", *(short *) ptr->value[loc]); value = bf; break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 6: snprintf (bf, %s, \"%d\", *(char *) ptr->value[loc]); value = bf; break; default: ERROR = 43; RUNTIMEFERR(\"OBTAIN$\", ERROR, k, l); return(NULL); } b2c_hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr);\n", STR( g_MAX_DIGITS));
    fputs("switch (type) { case 0: if (up_down) { qsort (&values[0], pos, sizeof (void *), b2c_sortstr); } else { qsort (&values[0], pos, sizeof (void *), b2c_sortstr_down); } break; case 1: if (up_down) { qsort (&values[0], pos, sizeof (void *), b2c_sortnrd_wrap); }\n", g_FUNCTIONS);
    fputs("else { qsort (&values[0], pos, sizeof (void *), b2c_sortnrd_wrap_down); } break; case 2: if (up_down) { qsort (&values[0], pos, sizeof (void *), b2c_sortnrf_wrap); } else { qsort (&values[0], pos, sizeof (void *), b2c_sortnrf_wrap_down); } break;\n", g_FUNCTIONS);
    fputs("case 3: if (up_down) { qsort (&values[0], pos, sizeof (void *), b2c_sortnrl_wrap); } else { qsort (&values[0], pos, sizeof (void *), b2c_sortnrl_wrap_down); } break; case 4: if (up_down) { qsort (&values[0], pos, sizeof (void *), b2c_sortnri_wrap); }\n", g_FUNCTIONS);
    fputs("else { qsort (&values[0], pos, sizeof (void *), b2c_sortnri_wrap_down); } break; case 5: if (up_down) { qsort (&values[0], pos, sizeof (void *), b2c_sortnrs_wrap); } else { qsort (&values[0], pos, sizeof (void *), b2c_sortnrs_wrap_down); } break;\n", g_FUNCTIONS);
    fputs("case 6: if (up_down) { qsort (&values[0], pos, sizeof (void *), b2c_sortnrc_wrap); } else { qsort (&values[0], pos, sizeof (void *), b2c_sortnrc_wrap_down); } break; } dlen = b2c_len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen);\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "keys = (char**)calloc(b2c_hash_nrkeys(name), sizeof(char*)); dups = (void**)calloc(b2c_hash_nrkeys(name), sizeof(void*)); for(i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc(%s, sizeof(char)); } switch (type)\n", STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "{ case 0: keys[i] = b2c_strdup((char*)values[i]); break; case 1: snprintf (keys[i], %s, \"%g\", *(double *) values[i]); break; case 2: snprintf(keys[i], %s, \"%g\", *(float*)values[i]); break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 3: snprintf(keys[i], %s, \"%ld\", *(long *) values[i]); break; case 4: snprintf(keys[i], %s, \"%d\", *(int *) values[i]); break; case 5: snprintf(keys[i], %s, \"%d\", *(short*)values[i]); break; case 6:\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "snprintf(keys[i], %s, \"%d\", *(char *) values[i]); break; } dups[i] = b2c_strdup((char*)b2c_hash_find_value_do (inv, keys[i])); b2c_hash_del_norebuild (inv, keys[i]); }\n", STR( g_MAX_DIGITS));
    fputs("do { if(type == 0) { while(cur < pos-1 && !strcmp(keys[cur], keys[cur+1])) { cur++; } } else { while(cur < pos-1 && !memcmp(keys[cur], keys[cur+1], sizeof(void*))) { cur++; } } qsort (&dups[start], cur-start+1, sizeof (char *), b2c_sortstr);\n", g_FUNCTIONS);
    fputs("for (j = start; j <= cur; j++) { len = b2c_len ((char *) dups[j]); buf[idx] = (char*)__b2c_str_realloc(buf[idx], total + len + dlen);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + total, dups[j], len); free(dups[j]); free(keys[j]); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } cur++; start = cur; } while(cur < pos);\n", g_FUNCTIONS);
    fputs("b2c_hash_clear (inv); free(inv); free(values); free(dups); free(keys); total -= dlen; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return((char*)buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "LOOKUP[[:space:]]|SORT[[:space:]]") ){
    fputs("int b2c_lookup_by_order(b2c_htable *name, char ***array, int size, int base) { int i, count = 0; if(name) { if(*array) { b2c_free_str_array_members (&(*array), base, size); free(*array); } *array = (char **)calloc(b2c_hash_nrkeys(name)+base, sizeof(char*));\n", g_FUNCTIONS);
    fputs("count = base; do { for(i = 0; i < name->total; i++) { (*array)[count] = b2c_CopyString((*array)[count], name->index[i]); count++; } name = name->next; } while(name); count -= base; } return(count); }\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "int b2c_lookup_by_sort (b2c_htable * name, char ***array, int size, int base, int type, int (*compare)(const void*, const void*)) { void **values = { NULL }; char **keys = { NULL }; b2c_htable *ptr, *inv; char *value; int i, j, pos = 0, count = 0, cur = 0, start = 0; unsigned short loc; char buf[%s + 1] = { 0 };\n", STR( g_MAX_DIGITS));
    fputs("if (*array) { b2c_free_str_array_members (&(*array), base, size); free (*array); } if (name) { values = (void **) calloc (b2c_hash_nrkeys (name), sizeof (char *)); inv = b2c_hash_new (); ptr = name; do\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "{ for (i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16 (ptr->index[i]); switch (type) { case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (buf, %s, \"%g\", *(double *) ptr->value[loc]); value = buf; break; case 2: snprintf (buf, %s, \"%g\", *(float *) ptr->value[loc]); value = buf;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "break; case 3: snprintf (buf, %s, \"%ld\", *(long *) ptr->value[loc]); value = buf; break; case 4: snprintf (buf, %s, \"%d\", *(int *) ptr->value[loc]); value = buf; break; case 5: snprintf (buf, %s, \"%d\", *(short *) ptr->value[loc]); value = buf; break; case 6: snprintf (buf, %s, \"%d\", *(char *) ptr->value[loc]);\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fputs("value = buf; break; } b2c_hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr); qsort (&values[0], pos, sizeof (void *), compare); *array = (char**)calloc(b2c_hash_nrkeys(name) + base, sizeof(char*)); keys = (char**)calloc(b2c_hash_nrkeys(name) + base, sizeof(char*));\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "count = base; for (i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc(%s, sizeof(char)); } switch (type) { case 0: keys[i] = b2c_strdup((char*)values[i]); break; case 1: snprintf(keys[i], %s, \"%g\", *(double *) values[i]); break; case 2: snprintf(keys[i], %s, \"%g\", *(float *) values[i]); break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 3: snprintf(keys[i], %s, \"%ld\", *(long *) values[i]); break; case 4: snprintf(keys[i], %s, \"%d\", *(int *) values[i]); break; case 5: snprintf(keys[i], %s, \"%d\", *(short *) values[i]); break; case 6: snprintf(keys[i], %s, \"%d\", *(char *) values[i]); break; }\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fputs("value = (char*)b2c_hash_find_value_do(inv, keys[i]); (*array)[count++] = b2c_strdup (value); b2c_hash_del_norebuild (inv, keys[i]); } do { if (type == 0) { while (cur < pos - 1 && !strcmp (keys[cur], keys[cur + 1])) { cur++; } } else { while (cur < pos - 1 && !memcmp (keys[cur], keys[cur + 1], sizeof(void*))) { cur++; }}\n", g_FUNCTIONS);
    fputs("qsort(&(*array)[start+base], cur - start + 1, sizeof(char*), b2c_sortstr); for (j = start; j <= cur; j++) { free (keys[j]); } cur++; start = cur; } while (cur < pos); b2c_hash_clear (inv); free (inv); free (values);\n", g_FUNCTIONS);
    fputs("free (keys); count -= base; } return (count); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "HEX\\$\\(") ){
    fprintf(g_FUNCTIONS, "char *b2c_dec2hex(int nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], %s);\n", STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "len = snprintf(buf[idx], %s, \"%X\", nr); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]);}\n", STR( g_MAX_DIGITS));
    }
    if( REGEX(g_DEPEND, "HOST\\$\\(") ){
    fputs("char *b2c_nethost(int l, char *k, char *host) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int y, flag = 0; struct hostent *he = NULL; unsigned char bf[sizeof(struct sockaddr_in*)]; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "buf[idx] = (char*)__b2c_str_realloc(buf[idx], %s); for (y = 0; host[y] != '\\0'; y++) { if (isalpha (*(host + y))) { flag = 1; break; } } if (flag){ he = gethostbyname (host); strncpy(buf[idx], inet_ntoa(*((struct in_addr*)he->h_addr)), %s); }\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "else { if (inet_pton(AF_INET, host, bf) <= 0) { ERROR = 11; RUNTIMEFERR (\"HOST$\", ERROR, k, l); strncpy(buf[idx], \"Host not found\", %s); return(NULL); }\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "else { he = gethostbyaddr(bf, sizeof(struct sockaddr_in*), AF_INET); if(he == NULL) { ERROR = 11; RUNTIMEFERR (\"HOST$\", ERROR, k, l); strncpy(buf[idx], \"Host not found\", %s); return(NULL); } else { strncpy(buf[idx], he->h_name, %s); } } }\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "__b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][%s-1] = '\\0'; return(char*)(buf[idx]); }\n", STR( g_BUFFER_SIZE));
    }
    if( REGEX(g_DEPEND, "HOSTNAME\\$") ){
    fprintf(g_FUNCTIONS, "char *b2c_hostname(int l, char *k) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], %s * sizeof (char));\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "if(gethostname(buf[idx], %s)) { ERROR = 26; RUNTIMEFERR(\"HOSTNAME$\", ERROR, k, l); strncpy(buf[idx], \"Error getting hostname\", %s); return(NULL); }\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "__b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][%s-1] = '\\0'; return(char*)(buf[idx]); }\n", STR( g_BUFFER_SIZE));
    }
    if( REGEX(g_DEPEND, "INDEX\\(") ){
    fprintf(g_FUNCTIONS, "int b2c_index (int line, char *k, size_t range, int type, void *array, int flag, ...) { int result = 0 + %s; double d; float f; long l; int i; short s; char c; char *term; void *index; va_list ap; va_start (ap, flag); if (flag == 0) { switch (type)\n", STR( g_OPTION_BASE));
    fputs("{ case 0: term = va_arg(ap, char*); if ((index = lfind (&term, array, &range, sizeof (char *), b2c_sortstr)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char *) + 1; } break; case 1: d = va_arg (ap, double); if ((index = lfind (&d, array, &range, sizeof (double), b2c_sortnrd)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (double) + 1; } break;\n", g_FUNCTIONS);
    fputs("case 2: f = va_arg (ap, double); if ((index = lfind (&f, array, &range, sizeof (float), b2c_sortnrf)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (float) + 1; } break; case 3: l = va_arg (ap, long); if ((index = lfind (&l, array, &range, sizeof (long), b2c_sortnrl)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (long) + 1; } break;\n", g_FUNCTIONS);
    fputs("case 4: i = va_arg (ap, int); if ((index = lfind (&i, array, &range, sizeof (int), b2c_sortnri)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (int) + 1; } break; case 5: s = va_arg (ap, int); if ((index = lfind (&s, array, &range, sizeof (short), b2c_sortnrs)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (short) + 1; } break;\n", g_FUNCTIONS);
    fputs("case 6: c = va_arg (ap, int); if ((index = lfind (&c, array, &range, sizeof (char), b2c_sortnrc)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char) + 1; } break; default: ERROR = 43; RUNTIMEFERR (\"INDEX\", ERROR, k, line); return(0); } } else { switch (type)\n", g_FUNCTIONS);
    fputs("{ case 0: term = va_arg(ap, char*); if ((index = bsearch (&term, array, range, sizeof (char *), b2c_sortstr)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char *) + 1; } break; case 1: d = va_arg (ap, double); if ((index = bsearch (&d, array, range, sizeof (double), b2c_sortnrd)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (double) + 1; } break;\n", g_FUNCTIONS);
    fputs("case 2: f = va_arg (ap, double); if ((index = bsearch (&f, array, range, sizeof (float), b2c_sortnrf)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (float) + 1; } break; case 3: l = va_arg (ap, long); if ((index = bsearch (&l, array, range, sizeof (long), b2c_sortnrl)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (long) + 1; } break;\n", g_FUNCTIONS);
    fputs("case 4: i = va_arg (ap, int); if ((index = bsearch (&i, array, range, sizeof (int), b2c_sortnri)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (int) + 1; } break; case 5: s = va_arg (ap, int); if ((index = bsearch (&s, array, range, sizeof (short), b2c_sortnrs)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (short) + 1; } break;\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "case 6: c = va_arg (ap, int); if ((index = bsearch (&c, array, range, sizeof (char), b2c_sortnrc)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char) + 1; } break; default: ERROR = 43; RUNTIMEFERR (\"INDEX\", ERROR, k, line); return(0); } } va_end (ap); return (result - %s); }\n", STR( g_OPTION_BASE));
    }
    if( REGEX(g_DEPEND, "INDEX\\$\\(") ){
    fprintf(g_FUNCTIONS, "char *b2c_index_assoc (int l, char *k, int type, b2c_htable * name, ...) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; b2c_htable *inv; unsigned short pos; char *value, *result; char bf[%s + 1] = { 0 }; int i, len; va_list ap; if(name == NULL || name->total == 0) { return (NULL); } inv = b2c_hash_new (); do { for(i = 0; i < name->total; i++) { pos = __b2c__HashFNV1a_16(name->index[i]); switch(type) { case 0: value = (char*)name->value[pos];\n", STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "break; case 1: snprintf (bf, %s, \"%g\", *(double *) name->value[pos]); value = bf; break; case 2: snprintf (bf, %s, \"%g\", *(float *) name->value[pos]); value = bf; break; case 3: snprintf (bf, %s, \"%ld\", *(long *) name->value[pos]); value = bf; break; case 4: snprintf (bf, %s, \"%d\", *(int *) name->value[pos]); value = bf; break; case 5: snprintf (bf, %s, \"%d\", *(short *) name->value[pos]); value = bf; break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 6: snprintf (bf, %s, \"%d\", *(char *) name->value[pos]); value = bf; break; default: ERROR = 43; RUNTIMEFERR (\"INDEX$\", ERROR, k, l); return(NULL); } b2c_hash_add_redundant (inv, name->index[i], value); } name = name->next; } while (name); va_start (ap, name); switch (type) { case 0: value = va_arg (ap, char *); break; case 1: snprintf (bf, %s, \"%g\", va_arg (ap, double)); value = bf; break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 2: snprintf (bf, %s, \"%g\", va_arg (ap, double)); value = bf; break; case 3: snprintf (bf, %s, \"%ld\", va_arg (ap, long)); value = bf; break; case 4: snprintf (bf, %s, \"%d\", va_arg (ap, int)); value = bf; break; case 5: snprintf (bf, %s, \"%d\", va_arg (ap, int)); value = bf; break; case 6: snprintf (bf, %s, \"%d\", va_arg (ap, int)); value = bf; break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fputs("default: ERROR = 43; RUNTIMEFERR (\"INDEX$\", ERROR, k, l); return(NULL); } va_end (ap); result = (char *) b2c_hash_find_value_do (inv, value); idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } len = b2c_len (result); buf[idx] = (char *) __b2c_str_realloc (buf[idx], len + 1); memmove (buf[idx], result, len); __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\\0'; b2c_hash_clear (inv); free (inv); return ((char *) buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "INVERT\\(") ){
    fprintf(g_FUNCTIONS, "int b2c_invert (int line, char *k, int type, b2c_htable ** name) { b2c_htable *inv, *ptr; char bf[%s + 1] = { 0 }; unsigned short pos; char *swap = NULL; int j, coll = 0; double d; float f; int i; long l; short s; char c; if (*name == NULL || (*name)->total == 0) { return (0); } inv = b2c_hash_new (); ptr = *name; do { for (j = 0; j < ptr->total; j++) { pos = __b2c__HashFNV1a_16(ptr->index[j]); switch (type) { case 0: swap = (char*)ptr->value[pos]; break;\n", STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 1: snprintf (bf, %s, \"%g\", *(double *) ptr->value[pos]); d = atof(ptr->index[j]); break; case 2: snprintf (bf, %s, \"%g\", *(float *) ptr->value[pos]); f = atof(ptr->index[j]); break; case 3: snprintf (bf, %s, \"%ld\", *(long *) ptr->value[pos]); l = atol(ptr->index[j]); break; case 4: snprintf (bf, %s, \"%d\", *(int *) ptr->value[pos]); i = atoi(ptr->index[j]); break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 5: snprintf (bf, %s, \"%d\", *(short *) ptr->value[pos]); s = atoi(ptr->index[j]); break; case 6: snprintf (bf, %s, \"%d\", *(char *) ptr->value[pos]); c = atoi(ptr->index[j]); break; default: ERROR = 43; RUNTIMEFERR (\"INVERT\", ERROR, k, line); return(0); } if(b2c_hash_find_value_do(inv, bf) || b2c_hash_find_value_do(inv, swap)) { coll++; } switch(type) { case 0: b2c_hash_add_str(inv, ptr->index[j], swap); break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fputs("case 1: b2c_hash_add(inv, &d, bf); break; case 2: b2c_hash_add(inv, &f, bf); break; case 3: b2c_hash_add(inv, &l, bf); break; case 4: b2c_hash_add(inv, &i, bf); break; case 5: b2c_hash_add(inv, &s, bf); break; case 6: b2c_hash_add(inv, &c, bf); break; default: ERROR = 43; RUNTIMEFERR (\"INVERT\", ERROR, k, line); return(0); } } ptr = ptr->next; } while (ptr); b2c_hash_clear (*name);\n", g_FUNCTIONS);
    fputs("free(*name); *name = inv; return(coll); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "INSERT\\$\\(") ){
    fputs("char * b2c_insert (int l, char *k, char *src, int pos, char *str) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, tot, blen; if (str == NULL) { return (src); } if (src == NULL) { return(str); } len = b2c_len (src); tot = b2c_len (str);\n", g_FUNCTIONS);
    fputs("idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+tot+1); pos--; if (pos <= 0) { memmove(buf[idx], str, tot); memmove(buf[idx] + tot, src, len); } else if (pos > len) { memmove(buf[idx], src, len);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + len, str, tot); } else { if (b2c_option_utf8) { blen = b2c_blen (l, k, \"INSERT$\", src, pos, 0); memmove(buf[idx], src, blen); memmove(buf[idx] + blen, str, tot);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + blen + tot, src + blen, len - blen); } else { memmove(buf[idx], src, pos); memmove(buf[idx] + pos, str, tot); memmove(buf[idx] + pos + tot, src + pos, len - pos); } }\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], len + tot); buf[idx][len + tot] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "INSTR\\(") ){
    fputs("long b2c_instr(int l, char *k, char *first, char *tmp, int pos) { char *result; if (first == NULL) { return (0); } if (tmp == NULL || b2c_len (tmp) == 0) { return (0); } if (pos <= 0) { pos = 1; }\n", g_FUNCTIONS);
    fputs("result = strstr (first + pos - 1, tmp); if(result == NULL) { return (0); } if (b2c_option_utf8) { return (long) b2c_ucs2_clen (l, k, \"INSTR\", first, result - first + 1); } return (long) (result - first + 1); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "INSTRREV\\(") ){
    fputs("long b2c_instrrev(int m, char *k, char *first, char *tmp, int pos) { char *result, *found; long l; if (first == NULL){ return (0);} if (tmp == NULL || b2c_len (tmp) == 0) { return (0); } if (pos < 0) { pos = 0; }\n", g_FUNCTIONS);
    fputs("l = b2c_len (first); found = first; do { result = strstr (found, tmp); if (result != NULL && result <= first + l - pos) { found = result + 1; continue; } if (result > first + l - pos) result = NULL; } while (result != NULL);\n", g_FUNCTIONS);
    fputs("if (b2c_option_startpoint) { if (l - (found - first) + 1 > l) { return(0); } if (b2c_option_utf8) { return (long) (b2c_ulen (l, k, \"INSTRREV\", first, -1) - b2c_ucs2_clen (l, k, \"INSTRREV\", first, found - first) + 1); }\n", g_FUNCTIONS);
    fputs("return (long) (l - (found - first) + 1); } if (b2c_option_utf8) { return (long) b2c_ucs2_clen (m, k, \"INSTRREV\", first, found - first); } return (long) (found - first); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "LCASE\\$\\(") ){
    fputs("char * b2c_lcase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } len = b2c_len (src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); if (b2c_option_utf8) { local = setlocale (LC_ALL, \"\"); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t));\n", g_FUNCTIONS);
    fputs("if(mbstowcs(wcs, src, mbslen + 1) == (size_t)-1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towlower (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t)-1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } free (wcs);\n", g_FUNCTIONS);
    fputs("setlocale (LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = tolower(src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "LEFT\\$\\(") ){
    fputs("char * b2c_left(int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = b2c_len (src);\n", g_FUNCTIONS);
    fputs("if (n > (b2c_option_utf8 ? b2c_ucs2_clen (l, k, \"LEFT$\", src, length) : length)) { return(src); } else { if (b2c_option_utf8)\n", g_FUNCTIONS);
    fputs("{ n = b2c_blen (l, k, \"LEFT$\", src, n, 0); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], n+1); memmove(buf[idx], src, n); __b2c__SETLEN (buf[idx], n); buf[idx][n] = '\\0'; } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "BLOAD\\(|LOAD\\$\\(") ){
    fputs("char* b2c_load(int flag, int l, char *k, char *file) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; FILE *handle; struct stat bf; void* mem; handle = fopen ((const char*)file, \"r\"); if(handle == NULL)\n", g_FUNCTIONS);
    fputs("{ ERROR = 2; RUNTIMEFERR (\"LOAD$/BLOAD\", ERROR, k, l); return(NULL); } if(stat(file, &bf) < 0) { ERROR = 24; RUNTIMEFERR (\"LOAD$/BLOAD\", ERROR, k, l); return(NULL); } if(flag) { mem = calloc(bf.st_size+b2c_option_memstream, sizeof(char));\n", g_FUNCTIONS);
    fputs("if(fread (mem, sizeof (char), bf.st_size, handle) != (size_t)bf.st_size) { ERROR = 2; RUNTIMEFERR(\"BLOAD\", ERROR, k, l); return(NULL); } fclose(handle); return(char*)(mem); } else\n", g_FUNCTIONS);
    fputs("{ idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], bf.st_size + 1); if(fread(buf[idx], sizeof (char), bf.st_size, handle) != (size_t)bf.st_size)\n", g_FUNCTIONS);
    fputs("{ ERROR = 2; RUNTIMEFERR (\"LOAD$\", ERROR, k, l); return(NULL); } __b2c__SETLEN(buf[idx], bf.st_size); buf[idx][bf.st_size] = '\\0'; fclose(handle); return(char*)(buf[idx]); } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "MID\\$\\(") ){
    fputs("char *b2c_mid(int l, char *k, char **swap, int type, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { if (type == 1) { *swap = b2c_CopyString (*swap, NULL); } return(NULL); }\n", g_FUNCTIONS);
    fputs("idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } src_len = b2c_len (src); pos -= 1; if (pos < 0) { pos = (b2c_option_utf8 ? b2c_ucs2_clen (l, k, \"MID$\", src, src_len) : src_len) + 1 + pos; } if (b2c_option_utf8) { pos = b2c_blen (l, k, \"MID$\", src, pos, 0); }\n", g_FUNCTIONS);
    fputs("if (pos > src_len) { if (type == 1) { *swap = b2c_CopyString (*swap, NULL); } return(NULL); } if (b2c_option_utf8 && length >= 0) { length = b2c_blen (l, k, \"MID$\", src + pos, length, 0); } if (length < 0 || pos + length > src_len) { length = src_len - pos; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + 1); memmove (buf[idx], src + pos, length); __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\\0'; if (type == 1) { return (__b2c_Swap_String (swap, &buf[idx])); } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "OS\\$") ){
    fputs("char *b2c_os(int l, char *k) { static char *result = NULL ; struct utsname bf; unsigned int len = 0; if(!result) { result = (char*)__b2c_str_realloc(result, 256 * sizeof (char)); if (uname(&bf) < 0)\n", g_FUNCTIONS);
    fputs("{ ERROR = 26; RUNTIMEFERR(\"OS$\", ERROR, k, l); return(NULL); } strncpy(result, bf.sysname, 64); len += strlen(bf.sysname); strncat(result, \" \", 2); len++; strncat(result, bf.machine, 128);\n", g_FUNCTIONS);
    fputs("len += strlen(bf.machine); __b2c__SETLEN(result, len); result[len] = '\\0'; } return(char*)result; }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "PEEK\\(") ){
    fputs("void *b2c_peek_check(int l, char *k, char *x, int size) { if(!b2c_memory__check((char*)x, size)) { ERROR=1; RUNTIMEFERR(\"PEEK\", ERROR, k, l); } return((void*)x); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "RECURSIVE[[:space:]]") ){
    fputs("int b2c_rmrecursive(int l, char *k, char *dir){ DIR *mydir; char *path, *item = NULL; struct stat buf = { 0 }; struct dirent *next = { NULL }; mydir = opendir(dir); if(mydir == NULL) { ERROR = 8; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); }\n", g_FUNCTIONS);
    fputs("while (1) { if (item != NULL) free(item); next = readdir(mydir); if(next != NULL) { item = (char*)calloc((strlen (next->d_name) + 1), sizeof(char));\n", g_FUNCTIONS);
    fputs("strcpy(item, next->d_name); } else { break; } if (!strcmp (item, \".\") || !strcmp(item, \"..\") ) continue; path = (char*)calloc(strlen(dir)+strlen(item)+2, sizeof(char));\n", g_FUNCTIONS);
    fputs("strcpy(path, dir); strcat(path, \"/\"); strcat(path, item); lstat(path, &buf); if(S_ISDIR (buf.st_mode)) { b2c_rmrecursive(l, k, path); } else { if(remove(path) < 0)\n", g_FUNCTIONS);
    fputs("{ ERROR = 7; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); } } if(path != NULL) free(path); } closedir(mydir); if(remove(dir) < 0)\n", g_FUNCTIONS);
    fputs("{ ERROR = 7; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); } return(0);}\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "REVERSE\\$\\(") ){
    fputs("char *b2c_reverse(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i, length, len, blen; if (src == NULL) { return (NULL); } length = b2c_len (src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], length+1); if(b2c_option_utf8) { len = length; while (len > 0) { blen = b2c_blen (l, k, \"REVERSE$\", src, 1, 0); memcpy(buf[idx] + len - blen, src, blen); src += blen; len -= blen; } } else\n", g_FUNCTIONS);
    fputs("{ for (i = 0; i < length; i++) { buf[idx][i] = src[length-i-1]; } } __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "RIGHT\\$\\(") ){
    fputs("char * b2c_right (int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = b2c_len (src);\n", g_FUNCTIONS);
    fputs("if (n > (b2c_option_utf8 ? b2c_ucs2_clen (l, k, \"RIGHT$\", src, length) : length)) { return(src); } else { if (b2c_option_utf8)\n", g_FUNCTIONS);
    fputs("{ n = b2c_blen (l, k, \"RIGHT$\", src, n, 1); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], n+1); memmove(buf[idx], src + length - n, n); __b2c__SETLEN(buf[idx], n); buf[idx][n] = '\\0'; } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "RIP\\$\\(") ){
    fputs("char *b2c_rip(int l, char *k, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { return (NULL); } src_len = b2c_len (src); pos -= 1;\n", g_FUNCTIONS);
    fputs("if (pos < 0) { pos = (b2c_option_utf8 ? b2c_ucs2_clen (l, k, \"RIP$\", src, src_len) : src_len) + 1 + pos; } if (b2c_option_utf8) { pos = b2c_blen (l, k, \"RIP$\", src, pos, 0); } if (pos > src_len)\n", g_FUNCTIONS);
    fputs("{ return (NULL); } if (b2c_option_utf8 && length >= 0) { length = b2c_blen (l, k, \"RIP$\", src + pos, length, 0); } if (length < 0 || pos + length > src_len)\n", g_FUNCTIONS);
    fputs("{ length = src_len - pos; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], src_len); memmove(buf[idx], src, pos); memmove(buf[idx]+pos, src+pos+length, src_len-pos-length);\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], src_len-length); buf[idx][src_len-length] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "COLUMNS|ROWS") ){
    fputs("long b2c_screen(int type){long x; struct winsize tmp; ioctl(STDOUT_FILENO, TIOCGWINSZ, &tmp); if(type) { x = tmp.ws_row; } else { x = tmp.ws_col; } return(x); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SEARCH\\(") ){
    fputs("long b2c_search (int l, char *k, FILE * x, char *y, int whence) { long off, pos=0, org_pos; int flag = 0; char *ptr; if (x == NULL)\n", g_FUNCTIONS);
    fputs("{ ERROR = 2; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } if (y == NULL) { ERROR = 25; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } org_pos = ftell (x); ptr = (char *) malloc (b2c_len (y) + 1);\n", g_FUNCTIONS);
    fputs("switch(whence) { case -1: case 0: off = 1; break; case 1: off = 1; break; case 2: off = -1; break; case 3: off = -1; break; default: ERROR = 37; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } do { switch(whence) { case -1: case 0: fseek (x, pos, SEEK_SET);\n", g_FUNCTIONS);
    fputs("break; case 1: fseek (x, org_pos+pos, SEEK_SET);break; case 2: flag = fseek (x, org_pos- b2c_len (y)+pos, SEEK_SET); break; case 3: fseek (x, pos-b2c_len (y), SEEK_END); break; }\n", g_FUNCTIONS);
    fputs("if (fread (ptr, sizeof (char), b2c_len (y), x) <= 0) { ERROR = 2; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } pos += off; } while (!feof (x) && !flag && memcmp (ptr, y, b2c_len (y)));\n", g_FUNCTIONS);
    fputs("if (memcmp (ptr, y, b2c_len (y))) { pos = -1; } else {pos = ftell(x)-b2c_len (y); } fseek (x, org_pos, SEEK_SET); free (ptr); return(pos); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SPC\\$\\(") ){
    fputs("char *b2c_spc(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; if(amount <= 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);\n", g_FUNCTIONS);
    fputs("memset(buf[idx], 32, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SUM\\(|SUMF\\(") ){
    fputs("long b2c_sum(int base, long *array, long nr, ...) { va_list ap; long limit = 0, total = 0; int x; va_start (ap, nr); limit = va_arg (ap, long); va_end (ap);\n", g_FUNCTIONS);
    fputs("for(x = base; x < nr+base; x++) { if(limit == LONG_MAX){ total += array[x]; } else { if(array[x]>limit) { total += array[x]; } } } return(total); }\n", g_FUNCTIONS);
    fputs("double b2c_sumf(int base, double *array, double nr, ...) { va_list ap; double limit = 0, total = 0; int x; va_start (ap, nr); limit = va_arg (ap, double); va_end (ap);\n", g_FUNCTIONS);
    fputs("for(x = base; x < nr+base; x++) { if(limit == DBL_MAX){ total += array[x]; } else { if(array[x]>limit) { total += array[x]; } } } return(total); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "TAB\\$\\(") ){
    fputs("char *b2c_tab(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; if(amount <= 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);\n", g_FUNCTIONS);
    fputs("memset(buf[idx], 9, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "TALLY\\(") ){
    fputs("long b2c_tally(char *haystack, char *needle, int pos) { char *res; long total = 0; if (haystack == NULL) { return (0); }\n", g_FUNCTIONS);
    fputs("if (needle == NULL || b2c_len(needle) == 0) { return (0); } if (pos <= 0) { pos = 1; }\n", g_FUNCTIONS);
    fputs("haystack+=pos-1; while((res = strstr(haystack, needle)) != NULL) { haystack = res+1; total++; } return((long)total); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "DAY\\(|HOUR\\(|MINUTE\\(|MONTH\\(|SECOND\\(|WEEK\\(|YEAR\\(") ){
    fprintf(g_FUNCTIONS, "long b2c_time (time_t now, int which){ long result; char *buffer; struct tm *ts; buffer = (char*)calloc(%s, sizeof (char)); ts = localtime (&now); switch (which) {\n", STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 1: strftime (buffer, %s, \"%d\", ts); break; case 2: strftime (buffer, %s, \"%m\", ts); break; case 3: strftime (buffer, %s, \"%Y\", ts); break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 4: strftime (buffer, %s, \"%H\", ts); break; case 5: strftime (buffer, %s, \"%M\", ts); break; case 6: strftime (buffer, %s, \"%S\", ts); break;\n", STR( g_MAX_DIGITS), STR( g_MAX_DIGITS), STR( g_MAX_DIGITS));
    fprintf(g_FUNCTIONS, "case 7: strftime (buffer, %s, \"%W\", ts); break; } result = atol(buffer); free(buffer); return(result); }\n", STR( g_MAX_DIGITS));
    }
    if( REGEX(g_DEPEND, "ALIGN\\$\\(|AMOUNT\\(|APPEND\\$\\(|CHANGE\\$\\(|COIL\\$\\(|COLLAPSE\\$\\(|CUT\\$\\(|DEL\\$\\(|DELIM\\$\\(|EXCHANGE\\$\\(|EXEC\\$\\(|EXPLODE\\$\\(|FIRST\\$\\(|FOR[[:space:]]|HASDELIM\\(|HEAD\\$\\(|INBETWEEN\\$\\(|ISTOKEN\\(|LAST\\$\\(|MAKEDIR[[:space:]]|MATCH\\(|MERGE\\$\\(|NETWORK[[:space:]]|OUTBETWEEN\\$\\(|PARSE[[:space:]]|PROPER\\$\\(|REV\\$\\(|ROTATE\\$\\(|SERVER[[:space:]]|SORT\\$\\(|SPLIT[[:space:]]|TAIL\\$\\(|TOKEN\\$\\(|UNIQ\\$\\(|WHERE\\(") ){
    fputs("/* API >>>> nr == 0, use_cache == 0 : rebuild cache | nr != 0, use_cache == 0 : dynamic calc member | nr != 0, use_cache == 1 : use member from cache */\n", g_FUNCTIONS);
    fputs("long b2c_delim_engine_core(int action, int type, long *returned_value, char *string, char *delim, long nr, int use_cache) { static long *cache = NULL, cache_tot = 0, cnt = 0; long x, len, pos = 0, start = 0; int in_string = 0, is_escaped = 0; if(action == 0) { if(cache) { free(cache); cache = NULL; } return(0); } *returned_value = 0; if (string == NULL || string[0] == 0) { return (0); }\n", g_FUNCTIONS);
    fputs("if (delim == NULL) { delim = b2c_option_delim; } len = b2c_len (delim); if(!use_cache) { cnt = 0; for (x = 0; string[x] != 0; x++) { if (!in_string) { if (len == 1 ? string[x] == delim[0] : !strncmp (string + x, delim, len)) { if (b2c_collapse == 0 || x > start) { cnt++; if (cnt > cache_tot)\n", g_FUNCTIONS);
    fputs("{ cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start; cache[cnt * 2 + 1] = start; } if(nr && nr == cnt) { break; } start = x + len; } } if (string[x] == b2c_option_esc) { if (!is_escaped) { is_escaped = 1; } else { is_escaped = 0; } } else if (string[x] == b2c_option_dq)\n", g_FUNCTIONS);
    fputs("{ if (!is_escaped && b2c_option_quoted) { in_string = 1 - in_string; } is_escaped = 0; } else { is_escaped = 0; } } if (b2c_collapse == 0 || x > start) { cnt++; if (cnt > cache_tot) { cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start;\n", g_FUNCTIONS);
    fputs("cache[cnt * 2 + 1] = start; } } if (nr <= cnt) { if (type == 1) { *returned_value = cache[nr*2]; pos = cache[nr*2+1]; } else { *returned_value = cnt; pos = cache[nr*2+1]; } } return(pos); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "TOKEN\\$\\(") ){
    fputs("char *b2c_token(char *string, long nr, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long length = 0; if (string == NULL || nr < 1) { return (NULL); }\n", g_FUNCTIONS);
    fputs("start = b2c_delim_engine(1, &length, string, delim, nr); if(length == 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], length+1); memmove(buf[idx], string + start, length); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "WHERE\\(") ){
    fputs("long b2c_where(char *string, long nr, char *delim) { long result = 0, length = 0; if (string == NULL || nr < 1) { return (0); } result = b2c_delim_engine (1, &length, string, delim, nr); return(result+1); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "AMOUNT\\(") ){
    fputs("long b2c_amount(char *string, char *delim) { long amount = 0; if (string == NULL) { return (0); } b2c_delim_engine(2, &amount, string, delim, 0); return(amount); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "HASDELIM\\(") ){
    fputs("int b2c_hasdelim (char *string, char *delim) { long length = 0; long start = 0; if (string == NULL) { return (0); }\n", g_FUNCTIONS);
    fputs("start = b2c_delim_engine (2, &length, string, delim, 2); if(start == 0) { return (0); } if (delim == NULL) { delim = b2c_option_delim; } return (start-b2c_len (delim)+1); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "EXCHANGE\\$\\(") ){
    fputs("char *b2c_exchange (char *string, int index1, int index2, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long tmp, tlen, len1, len2, start1 = 0, start2 = 0; long length = 0;\n", g_FUNCTIONS);
    fputs("if (string == NULL || index1 <= 0 || index2 <= 0) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start1 = b2c_delim_engine(1, &length, string, delim, index1);\n", g_FUNCTIONS);
    fputs("len1 = length; length = 0; start2 = b2c_delim_engine(1, &length, string, delim, index2); len2 = length; if (start1 == start2) { return (string); } else if (start2 < start1)\n", g_FUNCTIONS);
    fputs("{ tmp = start2; start2 = start1; start1 = tmp; tmp = len2; len2 = len1; len1 = tmp; } tlen = b2c_len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], tlen+1); memmove(buf[idx], string, start1);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + start1, string + start2, len2); memmove(buf[idx] + start1 + len2, string + start1 + len1, start2 - (start1 + len1));\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + start1 + len2 + start2 - (start1 + len1), string + start1, len1); memmove(buf[idx] + start1 + len2 + start2 - (start1 + len1) + len1, string + start2 + len2, tlen - (start2 + len2));\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], tlen); buf[idx][tlen] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "CHANGE\\$\\(") ){
    fputs("char *b2c_change(char *string, int index, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long tlen, start, len, nlen; long length = 0; if(string == NULL) { return(cnew); }\n", g_FUNCTIONS);
    fputs("if (index <= 0) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine(1, &length, string, delim, index); len = length; tlen = b2c_len(string); nlen = b2c_len(cnew);\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], tlen-len+nlen+1); memmove(buf[idx], string, start); memmove(buf[idx] + start, cnew, nlen); memmove(buf[idx] + start + nlen, string + start + len, tlen - (start + len));\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], tlen - len + nlen); buf[idx][tlen-len+nlen] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ISTOKEN\\(") ){
    fputs("long b2c_istoken(char *string, char *token, char *delim) { long len, start, x, result = 0; long length = 0, amount = 0; if(string == NULL) { return(0); } if(delim == NULL)\n", g_FUNCTIONS);
    fputs("{ delim = b2c_option_delim; } len = b2c_len(token); if(len==0) { return(0); } start = b2c_delim_engine (2, &amount, string, delim, 0); for(x = 0; x < amount; x++)\n", g_FUNCTIONS);
    fputs("{ start = b2c_delim_engine_cache(1, &length, string, delim, x+1); if(len == length && memcmp(string + start, token, len) == 0) { result = x+1; break; } } return (result); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "UNIQ\\$\\(") ){
    fputs("char *b2c_uniq(char *string, char *delim) { long x, start, amount = 0, length = 0; int t = 1; b2c_htable *table; char *item, *result; if(string == NULL) { return (string); }\n", g_FUNCTIONS);
    fputs("if(delim == NULL) { delim = b2c_option_delim; } start = b2c_delim_engine (2, &amount, string, delim, 0); if(amount <= 1) { return (string); }\n", g_FUNCTIONS);
    fputs("table = b2c_hash_new(); for (x = 0; x < amount; x++) { start = b2c_delim_engine_cache(1, &length, string, delim, x+1); item = b2c_strndup(string+start, length);\n", g_FUNCTIONS);
    fputs("if(!b2c_hash_find_key(table, 0, item)) { b2c_hash_add(table, &t, item); } __b2c__STRFREE(item); } result = b2c_hash_obtain(table, delim);\n", g_FUNCTIONS);
    fputs("b2c_hash_clear(table); free(table); return(result); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SORT\\$\\(") ){
    fputs("char *b2c_sort(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char **array; char *buffer, *backup; long start, total = 0, x, len, dlen; long amount = 0; long length = 0;\n", g_FUNCTIONS);
    fputs("if(string == NULL) { return (string); } if (delim == NULL) { delim = b2c_option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = b2c_len (delim); buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len(string)+1);\n", g_FUNCTIONS);
    fputs("buffer = b2c_strdup (string); backup = buffer; start = b2c_delim_engine (2, &amount, buffer, delim, 0); array = (char **) calloc(amount, sizeof (char *)); for (x = 0; x < amount; x++)\n", g_FUNCTIONS);
    fputs("{ start = b2c_delim_engine (1, &length, string, delim, 1); buffer[start + length] = '\\0'; if(buffer[start] == 34 && buffer[start+length-1] == 34) { buffer[start + length-1] = '\\0';\n", g_FUNCTIONS);
    fputs("array[x] = buffer + start + 1; } else { array[x] = buffer + start; } string += (start + length + dlen); buffer += (start + length + dlen); } qsort (&array[0], amount, sizeof (char *), b2c_sortstr);\n", g_FUNCTIONS);
    fputs("for (x = 0; x < amount; x++) { len = strlen (array[x]); if(strstr(array[x], delim)) { buf[idx][total] = 34; memmove(buf[idx] + total+1, array[x], len);\n", g_FUNCTIONS);
    fputs("buf[idx][total+len+1] = 34; total += len+2;} else { memmove(buf[idx] + total, array[x], len); total += len; } if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen);\n", g_FUNCTIONS);
    fputs("total += dlen; } } __b2c__STRFREE(backup); free(array); __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SORT[[:space:]]") ){
    fputs("void assoc_sort(b2c_htable **name, int type, int (*compare) (const void *, const void *)) { char **results = {  NULL }; int total; char *value; b2c_htable *ptr; int i; total =  b2c_lookup_by_sort(*name, &results, 0, 0, type, compare);\n", g_FUNCTIONS);
    fputs("ptr = b2c_hash_new(); for (i = 0; i < total; i++) { value = (char *) b2c_hash_find_value_do(*name, results[i]); if(type == 0) { b2c_hash_add_str(ptr, value, results[i]); } else { b2c_hash_add(ptr, value, results[i]); } } b2c_hash_clear (*name); free (*name); *name = ptr;\n", g_FUNCTIONS);
    fputs("if(results) { b2c_free_str_array_members(&results, 0, total); free(results); } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "REV\\$\\(") ){
    fputs("char *b2c_rev(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total, x, len, dlen; long amount = 0; long length = 0; if (string == NULL) { return (string); }\n", g_FUNCTIONS);
    fputs("len = b2c_len (string); if (delim == NULL) { delim = b2c_option_delim; } dlen = b2c_len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, delim, 0);\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); total = len; for (x = 0; x < amount; x++) { start = b2c_delim_engine_cache(1, &length, string, delim, x+1);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + total-length, string + start, length); total -= length; if (x < amount-1) { memmove(buf[idx] + total-dlen, delim, dlen); total -= dlen; } }\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "DELIM\\$\\(") ){
    fputs("char *b2c_delim(char *string, char *from, char *to) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x, tlen, dlen; long amount = 0; long length = 0; if (string == NULL) { return (string); }\n", g_FUNCTIONS);
    fputs("if(from == NULL) { from = b2c_option_delim; } if(to == NULL) { to = b2c_option_delim; } dlen = b2c_len (from); tlen = b2c_len (to); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, from, 0);\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len(string)+amount*tlen+1); for (x = 0; x < amount; x++) { start = b2c_delim_engine (1, &length, string, from, 1); memmove(buf[idx] + total, string + start, length);\n", g_FUNCTIONS);
    fputs("total += length; if (x < amount-1) { memmove(buf[idx] + total, to, tlen); total += tlen; } string += (start + length + dlen); } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "HEAD\\$\\(") ){
    fputs("char *b2c_head (char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long amount = 0; long length = 0; if (string == NULL)\n", g_FUNCTIONS);
    fputs("{ return (string); } if (delim == NULL) { delim = b2c_option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, delim, 0);\n", g_FUNCTIONS);
    fputs("if(amount < 1 || pos < 1) { return (NULL); } if (pos > amount) { pos = amount; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len(string)+1); start = b2c_delim_engine_cache(1, &length, string, delim, pos);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx], string, start + length); __b2c__SETLEN(buf[idx], start + length); buf[idx][start + length] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "TAIL\\$\\(") ){
    fputs("char *b2c_tail(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL)\n", g_FUNCTIONS);
    fputs("{ return (string); } if (delim == NULL) { delim = b2c_option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, delim, 0);\n", g_FUNCTIONS);
    fputs("if (amount < 1 || pos < 1) { return (NULL); } if (amount - pos + 1 < 1) { pos = 1; } else { pos = amount - pos + 1; } slen = b2c_len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen+1);\n", g_FUNCTIONS);
    fputs("start = b2c_delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "APPEND\\$\\(|COIL\\$\\(") ){
    fputs("char *b2c_append(char **swap, int type, char *string, long pos, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, slen, nlen, total = 0; long amount = 0; long length = 0; if (cnew == NULL || pos < 0)\n", g_FUNCTIONS);
    fputs("{ if (type == 1) { *swap = b2c_CopyString(*swap, string); } return (string); } if (delim == NULL) { delim = b2c_option_delim; } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, delim, 0);\n", g_FUNCTIONS);
    fputs("dlen = b2c_len (delim); nlen = b2c_len (cnew); slen = b2c_len (string); buf[idx] = (char *) __b2c_str_realloc (buf[idx], slen + nlen + dlen + 1); if (pos == 0 || pos > amount) { if (b2c_collapse == 0 || (b2c_collapse == 1 && slen > 0)) { memmove (buf[idx], string, slen);\n", g_FUNCTIONS);
    fputs("total += slen; } if (b2c_collapse == 0 || (b2c_collapse == 1 && nlen > 0)) { if(b2c_collapse == 0 || total) { memmove (buf[idx] + total, delim, dlen); total += dlen; } memmove (buf[idx] + total, cnew, nlen); total += nlen; } } else { start = b2c_delim_engine_cache (1, &length, string, delim, pos);\n", g_FUNCTIONS);
    fputs("memmove (buf[idx], string, start); total += start; memmove (buf[idx] + total, cnew, nlen); total += nlen; memmove (buf[idx] + total, delim, dlen); total += dlen; memmove (buf[idx] + total, string + start, slen - start); total += (slen - start); } __b2c__SETLEN (buf[idx], total);\n", g_FUNCTIONS);
    fputs("buf[idx][total] = '\\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "DEL\\$\\(") ){
    fputs("char *b2c_del(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen, dlen, total = 0; long amount = 0; long length = 0; if (string == NULL)\n", g_FUNCTIONS);
    fputs("{ return (string); } if (delim == NULL) { delim = b2c_option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, delim, 0); if (pos < 1 || pos > amount)\n", g_FUNCTIONS);
    fputs("{ return(string); } dlen = b2c_len (delim); slen = b2c_len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1); start = b2c_delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string, start);\n", g_FUNCTIONS);
    fputs("total += start; if (pos < amount) { memmove(buf[idx] + total, string + start + length + dlen, slen-(start + length + dlen)); total += slen-(start + length + dlen); }\n", g_FUNCTIONS);
    fputs("else { if(total >= dlen) { total -= dlen; } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "CUT\\$\\(") ){
    fputs("char *b2c_cut(char *string, long pos1, long pos2, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start1, start2, tmp, total = 0; long amount = 0; long length = 0; if (string == NULL)\n", g_FUNCTIONS);
    fputs("{ return (string); } if (delim == NULL) { delim = b2c_option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } if (pos1 > pos2) { tmp = pos1; pos1 = pos2; pos2 = tmp; } b2c_delim_engine (2, &amount, string, delim, 0);\n", g_FUNCTIONS);
    fputs("if(pos1 < 1) { pos1 = 1; } if(pos2 > amount) { pos2 = amount; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len(string)+1); start1 = b2c_delim_engine (1, &length, string, delim, pos1);\n", g_FUNCTIONS);
    fputs("start2 = b2c_delim_engine (1, &length, string, delim, pos2); memmove(buf[idx], string + start1, start2-start1+length); total += (start2-start1+length); __b2c__SETLEN(buf[idx], total);\n", g_FUNCTIONS);
    fputs("buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ALIGN\\$\\(") ){
    fputs("char *b2c_align (int l, char *k, char *str, unsigned long width, int mode, int indent) { static unsigned char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, x, y, left, line_start = 0, paragraph_end = 0, last_write_pos, write_pos = 0, characters, last_read_pos, read_pos = 0, wtotal = 0, ctotal = 0, found = 0, tab, pos, spaces;\n", g_FUNCTIONS);
    fputs("int quoted, collapse, utf8, preserve = 0; long amount = 0, length = 0, total, lw; char *string = NULL, *backup, *concat, *wrap, *line; if (str == NULL) { return (str); } if (width < 1) { return (NULL); } collapse = b2c_collapse; quoted = b2c_option_quoted; utf8 = b2c_option_utf8; b2c_option_quoted = 0; backup = string = b2c_strdup (str);\n", g_FUNCTIONS);
    fputs("if ((unsigned char) string[0] == 0xEF && (unsigned char) string[1] == 0xBB && (unsigned char) string[2] == 0xBF) { string += 3; b2c_option_utf8 = 1; preserve = 1; } for (x = 0; string[x]; x++) { if (string[x] == 10 && string[x + 1] == 10) x++; else if (string[x] == 10) string[x] = 32; }\n", g_FUNCTIONS);
    fputs("b2c_collapse = 1; start = b2c_delim_engine (2, &amount, string, \" \", 0); concat = (char *) calloc (x + amount + 1, sizeof (char)); for (x = 0; x < amount; x++) { start = b2c_delim_engine_cache (1, &length, string, \" \", x+1); memmove (concat + ctotal, string + start, length); ctotal += length;\n", g_FUNCTIONS);
    fputs("if (x < amount - 1) { memset (concat + ctotal, 32, 1); ctotal += 1; } } __b2c__STRFREE(backup); backup = wrap = (char *) calloc (ctotal*2 + 1, sizeof (char)); while (read_pos < ctotal) { if (*(concat + read_pos) == 32) { if (write_pos == 0) { read_pos++; continue; } else\n", g_FUNCTIONS);
    fputs("{ last_write_pos = wtotal; last_read_pos = read_pos; found = 1; } } memmove (wrap + wtotal, concat + read_pos, 1); write_pos++; wtotal++; if (*(concat + read_pos) == 10) { write_pos = 0; line_start = wtotal; } else if ((b2c_option_utf8 ? b2c_ucs2_clen (l, k, \"ALIGN$\", wrap + line_start, write_pos) : write_pos) >= width)\n", g_FUNCTIONS);
    fputs("{ if (found) { memset (wrap + last_write_pos, 10, 1); wtotal = last_write_pos + 1; read_pos = last_read_pos; if (*(concat + read_pos + 1) == 10) { read_pos++; } } else { memset (wrap + wtotal, 10, 1); wtotal += 1; } found = 0; write_pos = 0; line_start = wtotal; } read_pos++; } b2c_collapse = 0;\n", g_FUNCTIONS);
    fputs("start = b2c_delim_engine (2, &amount, wrap, \"\\n\", 0); line_start = 0; idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (unsigned char*)__b2c_str_realloc((char*)buf[idx], amount * indent + amount * width * 4 + 3 + 1); if(preserve) { buf[idx][0] = 0xEF; buf[idx][1] = 0xBB; buf[idx][2] = 0xBF;\n", g_FUNCTIONS);
    fputs("line_start += 3; } line = (char *) calloc (width * 4, sizeof (char)); for (x = 1; x <= amount; x++) { b2c_collapse = 0; paragraph_end = 0; start = b2c_delim_engine (1, &length, wrap, \"\\n\", 1); if(length && (*(wrap + start + length + 1) == 10 || x == amount )) { paragraph_end = 1; } characters = (b2c_option_utf8 ? b2c_ucs2_clen (l, k, \"ALIGN$\", wrap + start, length) : length);\n", g_FUNCTIONS);
    fputs("switch (mode) { case 0: memset (buf[idx] + line_start, 32, indent); line_start += indent; memmove (buf[idx] + line_start, wrap + start, length); line_start += length; memset (buf[idx] + line_start, 32, width - characters); line_start += (width - characters); if (x < amount) { memset (buf[idx] + line_start, '\\n', 1); line_start++; } break;\n", g_FUNCTIONS);
    fputs("case 1: memset (buf[idx] + line_start, 32, indent); line_start += indent; memset (buf[idx] + line_start, 32, width - characters); line_start += (width - characters); memmove (buf[idx] + line_start, wrap + start, length); line_start += length; if (x < amount) { memset (buf[idx] + line_start, '\\n', 1); line_start++; } break;\n", g_FUNCTIONS);
    fputs("case 2: tab = (width - characters) / 2; memset (buf[idx] + line_start, 32, indent + tab); line_start += (indent + tab); memmove (buf[idx] + line_start, wrap + start, length); line_start += length; memset (buf[idx] + line_start, 32, tab + (width - characters) % 2); line_start += (tab + (width - characters) % 2); if (x < amount)\n", g_FUNCTIONS);
    fputs("{ memset (buf[idx] + line_start, '\\n', 1); line_start++; } break; case 3: memmove (line, wrap + start, length); line[length] = '\\0'; pos = b2c_delim_engine (2, &total, line, \" \", 0); left = width - characters; spaces = total - 1; memset (buf[idx] + line_start, 32, indent); line_start += indent; for (y = 1; y <= total; y++)\n", g_FUNCTIONS);
    fputs("{ pos = b2c_delim_engine_cache (1, &lw, line, \" \", y); memmove (buf[idx] + line_start, line + pos, lw); line_start += lw; if(y<total) { memset (buf[idx] + line_start, 32, 1); line_start++; if (left && total > 1 && !paragraph_end && y > (spaces/2)-(left/2)) { tab = (left < spaces ? 1 : left / spaces); memset (buf[idx] + line_start, 32, tab); left -= tab;\n", g_FUNCTIONS);
    fputs("spaces--; line_start += tab; } } } if (x < amount) { memset (buf[idx] + line_start, '\\n', 1); line_start++; } break; } wrap += (start + length + 1); } free(backup); free (concat); free (line); b2c_option_quoted = quoted; b2c_collapse = collapse; b2c_option_utf8 = utf8; __b2c__SETLEN (buf[idx], line_start); buf[idx][line_start] = '\\0'; return (char *) (buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "EDITBOM\\$\\(|HASBOM\\(") ){
    fputs("int b2c_hasbom(char *string) { if (string == NULL || b2c_len(string) < 3) { return (0); } if ((unsigned char) string[0] == 0xEF && (unsigned char) string[1] == 0xBB && (unsigned char) string[2] == 0xBF) { return(1); } return(0); }\n", g_FUNCTIONS);
    fputs("char *b2c_editbom(char *string, int edit) { static unsigned char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int slen; if (string == NULL) { return(NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } slen = b2c_len(string);\n", g_FUNCTIONS);
    fputs("buf[idx] = (unsigned char*)__b2c_str_realloc((char*)buf[idx], 3+slen+1); if(edit) { if ((unsigned char)string[0] == 0xEF && (unsigned char)string[1] == 0xBB && (unsigned char)string[2] == 0xBF) { return (string); } buf[idx][0] = 0xEF; buf[idx][1] = 0xBB;\n", g_FUNCTIONS);
    fputs("buf[idx][2] = 0xBF; memcpy(buf[idx]+3, string, slen); __b2c__SETLEN(buf[idx], slen+3); buf[idx][slen+3] = '\\0'; } else { if ((unsigned char)string[0] != 0xEF || (unsigned char)string[1] != 0xBB || (unsigned char)string[2] != 0xBF) { return(string); }\n", g_FUNCTIONS);
    fputs("memcpy(buf[idx], string+3, slen-3); __b2c__SETLEN(buf[idx], slen-3); buf[idx][slen-3] = '\\0'; } return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "PROPER\\$\\(") ){
    fputs("char * b2c_proper(int l, char *k, char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *local; long start, total = 0, x, y, dlen, blen; long amount = 0; long length = 0; wchar_t wcs[8] = { 0 }; if (string == NULL) { return (string); }\n", g_FUNCTIONS);
    fputs("if (delim == NULL) { delim = b2c_option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = b2c_len (delim); start = b2c_delim_engine (2, &amount, string, delim, 0); buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len (string)+1); if(b2c_option_utf8)\n", g_FUNCTIONS);
    fputs("{ local = setlocale (LC_ALL, \"\"); for (x = 0; x < amount; x++) { start = b2c_delim_engine (1, &length, string, delim, 1); blen = b2c_blen (l, k, \"PROPER$\", string + start, 1, 0); if (mbtowc (wcs, string + start, blen) == (int) - 1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); }\n", g_FUNCTIONS);
    fputs("*wcs = towupper (*wcs); if (wctomb(buf[idx] + total, *wcs) == (int) -1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } for (y = blen; y < length; y += blen) { blen = b2c_blen (l, k, \"PROPER$\", string + start + y, 1, 0); if (mbtowc (wcs, string + start + y, blen) == (int) - 1)\n", g_FUNCTIONS);
    fputs("{ ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } if(b2c_option_proper == 0) { *wcs = towlower (*wcs); } if (wctomb(buf[idx] + total + y, *wcs) == (int) - 1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } } total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen);\n", g_FUNCTIONS);
    fputs("total += dlen; } string += (start + length + dlen); } setlocale (LC_ALL, local); } else { for (x = 0; x < amount; x++) { start = b2c_delim_engine (1, &length, string, delim, 1); *(buf[idx] + total) = toupper(*(string+start)); for (y = 1; y < length; y ++) { *(buf[idx]+total+y) = (b2c_option_proper == 0 ? tolower(*(string+start+y)) : *(string+start+y)); } \n", g_FUNCTIONS);
    fputs("total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen); total += dlen; } string += (start + length + dlen); } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ROTATE\\$\\(") ){
    fputs("char *b2c_rotate (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x, dlen; long amount = 0, length = 0; char *next; if (string == NULL) { return (string); } if (delim == NULL) { delim = b2c_option_delim; }\n", g_FUNCTIONS);
    fputs("idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = b2c_len (delim); start = b2c_delim_engine (2, &amount, string, delim, 0); if (amount <= 1) { return (string); } if (abs (pos) >= amount) { pos = pos % amount; } if (pos == 0) { return (string); } if (pos < 0)\n", g_FUNCTIONS);
    fputs("{ pos = amount + pos; } next = string; buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len (string) + 1); start = b2c_delim_engine (1, &length, string, delim, amount-pos+1); string += start; for (x = amount - pos; x < amount; x++) { start = b2c_delim_engine (1, &length, string, delim, 1);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + total, string + start, length); total += length; memmove(buf[idx] + total, delim, dlen); total += dlen; string += (start + length + dlen); } for (x = 0; x < amount - pos; x++) { start = b2c_delim_engine (1, &length, next, delim, 1);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx] + total, next + start, length); total += length; if (x < amount - pos - 1) { memmove(buf[idx] + total, delim, dlen); total += dlen; } next += (start + length + dlen); }\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN(buf[idx], total);buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "LAST\\$\\(") ){
    fputs("char *b2c_last (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = b2c_option_delim; }\n", g_FUNCTIONS);
    fputs("idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } slen = b2c_len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1);\n", g_FUNCTIONS);
    fputs("start = b2c_delim_engine_cache(1, &length, string, delim, pos+1); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FIRST\\$\\(") ){
    fputs("char * b2c_first (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long dlen, end; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = b2c_option_delim; }\n", g_FUNCTIONS);
    fputs("idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } end = b2c_delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len(string)+1);\n", g_FUNCTIONS);
    fputs("end = b2c_delim_engine_cache(1, &length, string, delim, amount-pos+1); dlen = b2c_len (delim); memmove(buf[idx], string, end-dlen); __b2c__SETLEN(buf[idx], end-dlen); buf[idx][end-dlen] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "MATCH\\(") ){
    fputs("int b2c_match(char *string1, char *string2, long count, char *delim) { long dlen, start1, start2, amount1, amount2, length1, length2, tmplen; int x, found = 1, wildcard = 0, after = 0; if (string1 == NULL && string2 == NULL) { return (1); }\n", g_FUNCTIONS);
    fputs("if (count == 0) { return (1); } if (delim == NULL) { delim = b2c_option_delim; } start1 = b2c_delim_engine (2, &amount1, string1, delim, 0); if (count > amount1 || amount1 == 0) { return (0); } if(count == -1) { count = amount1; } dlen = b2c_len (delim);\n", g_FUNCTIONS);
    fputs("for (x = 0; x < count; x++) { start1 = b2c_delim_engine (1, &length1, string1, delim, 1); start2 = b2c_delim_engine (1, &length2, string2, delim, 1); if (length1 == 0) { found = wildcard; break; } if (length2 == 0)\n", g_FUNCTIONS);
    fputs("{ found = wildcard; break; } if (strncmp (string2, \"?\", 1)) { if (!strncmp (string2, \"*\", 1)) { wildcard = 1; b2c_delim_engine (2, &amount2, string2+1, delim, 0); if(amount2) { after = 1; string2+=1+dlen; } else { after = 0; found = wildcard; break; } }\n", g_FUNCTIONS);
    fputs("else { if (!strncmp (string2, \"\\\\?\", 2) || !strncmp (string2, \"\\\\*\", 2)) { string2++; length2--; } } b2c_delim_engine (1, &tmplen, string2, delim, 1); if(length1 != tmplen || memcmp (string1, string2, tmplen)) { if (wildcard == 0) { found = 0; break; } else { string2 = string2-1-dlen; } }\n", g_FUNCTIONS);
    fputs("else { wildcard = 0; after = 0; } if(wildcard == 0) { string2 += (start2 + length1 + dlen); } } else { string2 += (start2 + length2 + dlen); } string1 += (start1 + length1 + dlen); } if(after) { found = 0; } return (found); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "EXPLODE\\$\\(") ){
    fputs("char *b2c_explode (int l, char *k, char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long x, dlen, len, blen, ctr=0, where = 0, escaped = 0, in_string = 0; if (string == NULL || pos <= 0 || pos >= (len = b2c_len (string)) ) { return (string); } if (delim == NULL) { delim = b2c_option_delim; }\n", g_FUNCTIONS);
    fputs("dlen = b2c_len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } blen = pos; buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + (len - 1) * dlen + 1); for (x = 0; x < len; x += blen) { if (b2c_option_utf8) { blen = b2c_blen(l, k, \"EXPLODE$\", string + x, pos, 0); } if(*(string+x) == b2c_option_esc) { escaped = 1 - escaped; } if(*(string+x) == 34)\n", g_FUNCTIONS);
    fputs("{ if(!escaped && b2c_option_quoted) { in_string = 1 - in_string; } escaped = 0; } else { escaped = 0; } memmove(buf[idx] + where, string + x, blen); where+=blen; if (x < (len - blen) && !in_string) { memmove(buf[idx] + where, delim, dlen); where+=dlen; ctr+=dlen; } } __b2c__SETLEN(buf[idx], len+ctr); buf[idx][len+ctr] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "MERGE\\$\\(") ){
    fputs("char *b2c_merge(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x; long amount = 0; long length = 0; if (string == NULL) { return (string); }\n", g_FUNCTIONS);
    fputs("if (delim == NULL) { delim = b2c_option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &amount, string, delim, 0); buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len (string) + 1); for(x = 1; x <= amount; x++)\n", g_FUNCTIONS);
    fputs("{ start = b2c_delim_engine_cache(1, &length, string, delim, x); memmove(buf[idx] + total, string + start, length); total += length; } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "INBETWEEN\\$\\(|OUTBETWEEN\\$\\(") ){
    fputs("char *b2c_inbetween(int flag, char *haystack, char *lm, char *rm, int greedy) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *l, *pos; int collapse; long len, start, end=0, in, w1, w2; long length = 0;\n", g_FUNCTIONS);
    fputs("if (haystack == NULL || lm == NULL || rm == NULL) { return (NULL); } collapse = b2c_collapse; b2c_collapse = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = b2c_delim_engine (2, &length, haystack, lm, 2);\n", g_FUNCTIONS);
    fputs("if (start == 0) { b2c_collapse = collapse; return (NULL); } if (greedy == 0) { in = b2c_delim_engine (2, &length, haystack+start+end, rm, 2); if (in == 0) { b2c_collapse = collapse; return (NULL); }\n", g_FUNCTIONS);
    fputs("l = haystack+start-b2c_len(lm); pos = haystack+start+in-b2c_len(rm); } else if (greedy == 1) { while (1) { in = b2c_delim_engine (2, &length, haystack+start+end, rm, 2); if(in) { end += in; } else { break; } }\n", g_FUNCTIONS);
    fputs("if (end == 0) { b2c_collapse = collapse; return (NULL); } l = haystack+start-b2c_len(lm); pos = haystack+start+end-b2c_len(rm); } else { w1 = start; w2 = start;\n", g_FUNCTIONS);
    fputs("while (1) { end = b2c_delim_engine (2, &length, haystack + w1, rm, 2); if (end == 0) { b2c_collapse = collapse; return (NULL); } in = b2c_delim_engine (2, &length, haystack + w2, lm, 2); if (in && ((w2 + in) < (w1 + end)))\n", g_FUNCTIONS);
    fputs("{ w1 = w1 + end; w2 = w2 + in; } else { break; } } l = haystack + start - b2c_len (lm); pos = haystack + w1 + end - b2c_len (rm); } if (flag) { pos += strlen (rm); len = strlen (pos); buf[idx] = (char*)__b2c_str_realloc(buf[idx], (l - haystack) + len + 1);\n", g_FUNCTIONS);
    fputs("memmove(buf[idx], haystack, l - haystack); memmove(buf[idx] + (l - haystack), pos, len); __b2c__SETLEN(buf[idx], (l - haystack) + len); buf[idx][(l - haystack) + len] = '\\0'; } else\n", g_FUNCTIONS);
    fputs("{ l += strlen (lm); buf[idx] = (char*)__b2c_str_realloc(buf[idx], pos - l + 1); memmove(buf[idx], l, pos - l); __b2c__SETLEN(buf[idx], pos - l); buf[idx][pos - l] = '\\0'; } b2c_collapse = collapse; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "UCASE\\$\\(") ){
    fputs("char * b2c_ucase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } len = b2c_len (src);\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); if(b2c_option_utf8) { local = setlocale (LC_ALL, \"\"); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t)); if (mbstowcs (wcs, src, mbslen + 1) == (size_t) - 1)\n", g_FUNCTIONS);
    fputs("{ ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towupper (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } free (wcs);\n", g_FUNCTIONS);
    fputs("setlocale(LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = toupper (src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "WAIT\\(") ){
    fputs("long b2c_netpeek(int l, char *k, uintptr_t fd, int usec){fd_set rfds; struct timeval tv; int desc = 0; long retval = 0; struct termios oldt = { 0 }, newt = { 0 }; if(fd == STDIN_FILENO){tcgetattr(STDIN_FILENO, &oldt);\n", g_FUNCTIONS);
    fputs("newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1; newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt);} tv.tv_usec = (usec%1000)*1000; tv.tv_sec = usec/1000; FD_ZERO(&rfds);\n", g_FUNCTIONS);
    fputs("if(fd == STDIN_FILENO) { desc = fd; } else {\n", g_FUNCTIONS);
        if( g_OPTION_TLS ){
            if( TALLY(g_LIB_TLS, "gnutls") ){
            fputs("if(b2c_option_tls) { BIO_get_fd(((SSL*)fd)->gnutls_state, &desc); }\n", g_FUNCTIONS);
            } else {
            fputs("if(b2c_option_tls) { desc = SSL_get_fd((SSL*)fd); }\n", g_FUNCTIONS);
            }
        }
    fputs("if(!b2c_option_tls) { desc = fd; } }\n", g_FUNCTIONS);
    fputs("FD_SET(desc, &rfds); retval = select(desc + 1, &rfds, NULL, NULL, &tv); if(retval == -1) { ERROR = 16; RUNTIMEFERR(\"WAIT\", ERROR, k, l); return(0); }\n", g_FUNCTIONS);
    fputs("if(fd == STDIN_FILENO){ if(retval) if(read(fd, &retval, 1)==0) { retval=0; } tcsetattr(STDIN_FILENO, TCSANOW, &oldt);} return(retval); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "EXTRACT\\$\\(") ){
    fputs("char *b2c_extract_core(int action, int l, char *k, char *src, char *needle, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int reti = 0, len, pos = 0; char *tmp; regex_t regex; char b2c_buf[100]; regmatch_t where[1];\n", g_FUNCTIONS);
    fputs("static b2c_htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { b2c_hash_clear_regfree(table_icase); free(table_icase); b2c_hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (src == NULL || needle == NULL) { return (src); } if (b2c_len (src) == 0 || b2c_len (needle) == 0) { return (src); } idx++; if (idx == __b2c_STRING_FUNC)\n", g_FUNCTIONS);
    fputs("{ idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], b2c_len (src) + 1); if (flag > 0) { if (b2c_option_compare == 0) { if (table_normal == NULL) { table_normal = b2c_hash_new(); } found = b2c_hash_find_value_do(table_normal, needle);\n", g_FUNCTIONS);
    fputs("if(!found) { reti = regcomp(&regex, needle, REG_EXTENDED); if (reti == 0) { b2c_hash_add_data(table_normal, (void *) &regex, sizeof(regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = b2c_hash_new(); }\n", g_FUNCTIONS);
    fputs("found = b2c_hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED|REG_ICASE); if (reti == 0) { b2c_hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }\n", g_FUNCTIONS);
    fputs("if(reti) { ERROR = 27; regerror (reti, &regex, b2c_buf, sizeof (b2c_buf)); fprintf (stderr, \"%s\\n\", b2c_buf); RUNTIMEFERR(\"EXTRACT$\", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, src, 1, where, 0)) == 0)\n", g_FUNCTIONS);
    fputs("{ memcpy (buf[idx] + pos, src, (size_t) where[0].rm_so); pos += where[0].rm_so; src += (long) where[0].rm_eo; } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } else { while ((tmp = strstr (src, needle)) != NULL)\n", g_FUNCTIONS);
    fputs("{ memcpy (buf[idx] + pos, src, (size_t) (tmp - src)); pos += tmp - src; src = tmp + b2c_len (needle); } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } __b2c__SETLEN (buf[idx], pos); buf[idx][pos] = '\\0'; return (char *) (buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "REGEX\\(") ){
    fputs("long b2c_regex_core (int action, int l, char *k, char *x, char *y) { regex_t reg; int reti = 0; char buf[100]; regmatch_t where[1]; static b2c_htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { b2c_hash_clear_regfree(table_icase); free(table_icase); b2c_hash_clear_regfree(table_normal); free(table_normal);\n", g_FUNCTIONS);
    fputs("return(0); } if (x == NULL || y == NULL) { return (0); } if (b2c_option_compare == 0) { if (table_normal == NULL) { table_normal = b2c_hash_new(); } found = b2c_hash_find_value_do (table_normal, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED); if (reti == 0) { b2c_hash_add_data (table_normal, (void *) &reg, sizeof (reg), y); } }\n", g_FUNCTIONS);
    fputs("else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = b2c_hash_new(); } found = b2c_hash_find_value_do (table_icase, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED | REG_ICASE); if (reti == 0) { b2c_hash_add_data (table_icase, (void *) &reg, sizeof (reg), y); } }\n", g_FUNCTIONS);
    fputs("else { reg = *(regex_t*)found; } } if(reti) { ERROR = 27; regerror (reti, &reg, buf, sizeof (buf)); fprintf(stderr, \"%s\\n\", buf); RUNTIMEFERR(\"REGEX\", ERROR, k, l); return (0); } reti = regexec (&reg, x, 1, where, 0); if (!reti) { REGLEN = where[0].rm_eo - where[0].rm_so;\n", g_FUNCTIONS);
    fputs("return (where[0].rm_so + 1); } else { REGLEN = 0; return (0); } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "REPLACE\\$\\(") ){
    fputs("char *b2c_replace_core (int action, int l, char *k, char *haystack, char *needle, char *replace, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long replen, hstlen, ndllen, length = 0; regex_t regex; int i, reti = 0; char buffer[100]; regmatch_t where[1];\n", g_FUNCTIONS);
    fputs("static b2c_htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { b2c_hash_clear_regfree(table_icase); free(table_icase); b2c_hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (haystack == NULL || needle == NULL) { return (haystack); } if (replace == NULL) { replace = __b2c_EMPTYSTRING; } ndllen = b2c_len (needle); hstlen = b2c_len (haystack); if (hstlen == 0 || ndllen == 0)\n", g_FUNCTIONS);
    fputs("{ return (haystack); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (flag == 2) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], hstlen + 1); strncpy (buf[idx], haystack, hstlen); for (i = 0; i < hstlen; i++) { if ((tmp = strchr (needle, buf[idx][i])) != NULL) { buf[idx][i] = replace[tmp - needle]; } }\n", g_FUNCTIONS);
    fputs("__b2c__SETLEN (buf[idx], i); buf[idx][i] = '\\0'; return (char *) (buf[idx]); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], sizeof (char)); buf[idx][0] = '\\0'; replen = b2c_len (replace); if (flag == 1) { if (b2c_option_compare == 0) { if (table_normal == NULL) { table_normal = b2c_hash_new (); }\n", g_FUNCTIONS);
    fputs("found = b2c_hash_find_value_do(table_normal, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED); if (reti == 0) { b2c_hash_add_data (table_normal, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL)\n", g_FUNCTIONS);
    fputs("{ table_icase = b2c_hash_new (); } found = b2c_hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED | REG_ICASE); if (reti == 0) { b2c_hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }\n", g_FUNCTIONS);
    fputs("if(reti) { ERROR = 27; regerror (reti, &regex, buffer, sizeof (buffer)); fprintf (stderr, \"%s\\n\", buffer); RUNTIMEFERR (\"REPLACE$\", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, haystack, 1, where, 0)) == 0) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + where[0].rm_so + replen + 1);\n", g_FUNCTIONS);
    fputs("memcpy (buf[idx] + length, haystack, (size_t) where[0].rm_so); length += where[0].rm_so; memcpy (buf[idx] + length, replace, replen); length += replen; haystack += (long) where[0].rm_eo; }} else { while ((tmp = strstr (haystack, needle)) != NULL) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + tmp - haystack + replen + 1);\n", g_FUNCTIONS);
    fputs("memcpy (buf[idx] + length, haystack, (size_t) (tmp - haystack)); length += tmp - haystack; memcpy (buf[idx] + length, replace, replen); length += replen; haystack = tmp + ndllen; }} hstlen = strlen (haystack); buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + hstlen + 1); memcpy (buf[idx] + length, haystack, hstlen);\n", g_FUNCTIONS);
    fputs("length += hstlen; __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\\0'; return (char *) (buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "WALK\\$\\(") ){
    fputs("#ifndef PATH_MAX\n", g_FUNCTIONS);
    fputs("#define PATH_MAX 4096\n", g_FUNCTIONS);
    fputs("#endif\n", g_FUNCTIONS);
    fputs("static int b2c_walk_filter_file(regex_t reg, char *file, int type, struct stat bf) { regmatch_t where[1]; if (regexec(&reg, file, 1, where, 0) == 0) { if (((type & 1) && S_ISREG(bf.st_mode)) || ((type & 2) && S_ISDIR(bf.st_mode)) || ((type & 4) && S_ISCHR(bf.st_mode)) || ((type & 8) && S_ISBLK(bf.st_mode)) ||\n", g_FUNCTIONS);
    fputs(" ((type & 16) && S_ISFIFO(bf.st_mode)) || ((type & 32) && S_ISLNK(bf.st_mode)) || ((type & 64) && S_ISSOCK(bf.st_mode))) { return(1); } } return(0); }\n", g_FUNCTIONS);
    fputs("static int b2c_walk_each_file_recurse(regex_t reg, char **buf, char *dir, int type, char *delim) { FTS *fts; FTSENT *ent; struct stat bf; char *item[2]; int dlen, flen, total = 0, result = 0; item[0] = dir; item[1] = NULL; fts = fts_open(item, FTS_PHYSICAL | FTS_NOCHDIR | FTS_XDEV, NULL); if(fts == NULL)\n", g_FUNCTIONS);
    fputs("{ return(-1); } dlen = b2c_len(delim); while(1) { ent = fts_read(fts); if(ent == NULL) { break; } if (lstat(ent->fts_path, &bf) < 0 && b2c_trap) { result = -1; break; } if(b2c_walk_filter_file(reg, ent->fts_path, type, bf))\n", g_FUNCTIONS);
    fputs("{ if(ent->fts_info != FTS_D) { flen = b2c_len(ent->fts_path); *buf = (char*)__b2c_str_realloc(*buf, total+flen+dlen+1); memcpy(*buf+total, ent->fts_path, flen); memcpy(*buf+total+flen, delim, dlen);\n", g_FUNCTIONS);
    fputs("total += flen + dlen; } } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total-dlen); (*buf)[total - dlen] = '\\0'; fts_close(fts); return (result); }\n", g_FUNCTIONS);
    fputs("static int b2c_walk_each_file_dir (regex_t reg, char **buf, const char *dir, int type, char *delim) { DIR *here; struct dirent *item; struct stat bf; int dlen, flen, plen, total = 0, result = 0; char path[PATH_MAX] = { 0 }; here = opendir (dir); if (here == NULL) { return (-1); } dlen = b2c_len(delim); plen = strlen(dir);\n", g_FUNCTIONS);
    fputs("if (plen >= PATH_MAX) { return (-1); } strncpy (path, dir, PATH_MAX - 1); plen++; if (plen >= PATH_MAX) { return (-1); } strncat (path, \"/\", PATH_MAX - plen - 1); while (1) { item = readdir (here); if (item == NULL) { break; } if (!strcmp (item->d_name, \".\") || !strcmp (item->d_name, \"..\")) { continue; } memset (path + plen, 0, 1);\n", g_FUNCTIONS);
    fputs("flen = strlen(item->d_name); if (plen + flen >= PATH_MAX) { return (-1); } strncat (path, item->d_name, PATH_MAX - plen - 1); flen += plen; if (lstat (path, &bf) < 0 && b2c_trap) { result = -1; break; } if (b2c_walk_filter_file (reg, path, type, bf)) { *buf = (char*)__b2c_str_realloc(*buf, total + flen + dlen + 1);\n", g_FUNCTIONS);
    fputs("memcpy(*buf+total, path, flen); memcpy(*buf+total+flen, delim, dlen); total += flen + dlen; } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total - dlen); (*buf)[total - dlen] = '\\0'; closedir (here); return (result); }\n", g_FUNCTIONS);
    fputs("char *b2c_walk_core(int action, int l, char *k, char *dir, int type, char *exp, int recurse, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; regex_t reg; char buffer[100]; int reti = 0; static b2c_htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { b2c_hash_clear_regfree(table_icase); free(table_icase); b2c_hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (dir == NULL || exp == NULL)\n", g_FUNCTIONS);
    fputs("{ return (NULL); } if (delim == NULL) { delim = b2c_option_delim; } if(type < 1 || type > 127) { ERROR = 5; RUNTIMEFERR(\"WALK$\", ERROR, k, l); return (NULL); } if (b2c_option_compare == 0) { if (table_normal == NULL) { table_normal = b2c_hash_new (); } found = b2c_hash_find_value_do (table_normal, exp);\n", g_FUNCTIONS);
    fputs("if (!found) { reti = regcomp (&reg, exp, REG_EXTENDED); if (reti == 0) { b2c_hash_add_data (table_normal, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = b2c_hash_new (); } found = b2c_hash_find_value_do (table_icase, exp); if (!found)\n", g_FUNCTIONS);
    fputs("{ reti = regcomp (&reg, exp, REG_EXTENDED | REG_ICASE); if (reti == 0) { b2c_hash_add_data (table_icase, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } if(reti) { ERROR = 27; regerror (reti, &reg, buffer, sizeof (buffer)); fprintf(stderr, \"%s\\n\", buffer); RUNTIMEFERR(\"WALK$\", ERROR, k, l);\n", g_FUNCTIONS);
    fputs("return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], PATH_MAX * sizeof (char)); if (recurse) { if (b2c_walk_each_file_recurse (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR(\"WALK$\", ERROR, k, l); return (NULL); } } else\n", g_FUNCTIONS);
    fputs("{ if (b2c_walk_each_file_dir (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR (\"WALK$\", ERROR, k, l); return (NULL); } } return (char *) (buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "EVAL\\(")  OR  g_OPTION_EVAL ){
    fputs("#include <matheval.h>\n", g_FUNCTIONS);
    fputs("double b2c_eval(int l, char *k, char **vars, double *vals, int nr, char *expr) { void *f; double result; if (expr == NULL) return (0); f = evaluator_create(expr);\n", g_FUNCTIONS);
    fputs("if(f) { result = evaluator_evaluate(f, nr, vars, vals); } else { ERROR = 39; RUNTIMEFERR(\"EVAL\", ERROR, k, l); return(0); } evaluator_destroy(f); return(result); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "GETFILE[[:space:]]") ){
    fputs("void b2c_getfile(int l, char *k, char **result, DIR * from, int *type) { struct dirent *dir; *type = -1; dir = readdir (from); if (dir != NULL) { *result = b2c_strdup (dir->d_name);\n#ifdef _DIRENT_HAVE_D_TYPE\nswitch (dir->d_type) { case DT_UNKNOWN: *type = 0; break;\n", g_FUNCTIONS);
    fputs("case DT_REG: *type = 1; break; case DT_DIR: *type = 2; break; case DT_FIFO: *type = 5; break; case DT_SOCK: *type = 7; break; case DT_CHR: *type = 3; break; case DT_BLK: *type = 4; break; case DT_LNK: *type = 6; break; default:\n", g_FUNCTIONS);
    fputs("ERROR = 24; RUNTIMEFERR(\"GETFILE\", ERROR, k, l); return; }\n#endif\n } else { *result = NULL; } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "COPY[[:space:]]") ){
    fprintf(g_FUNCTIONS, "int b2c_copy(const char *from, const char *to) { char buffer[%s]; FILE *in, *out; size_t size; in = fopen(from, \"r\"); out = fopen(to, \"w\"); if(in == NULL || out == NULL) { return(1); }\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "while((size = fread(buffer, sizeof(char), %s, in)) > 0) { if(fwrite(buffer, sizeof(char), size, out) != size) { return(1); } } fclose(in); fclose(out); return(0); }\n", STR( g_BUFFER_SIZE));
    }
    if( REGEX(g_DEPEND, "ASC\\(|INPUT[[:space:]]") ){
    fputs("unsigned char b2c_asc(char *data) { if(data == NULL) { return(0); } return((unsigned char)*data); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "INPUT[[:space:]]") ){
    fprintf(g_FUNCTIONS, "void b2c_input(int l, char *k, char **result, char *sep) { size_t size; ssize_t total; size = %s; *result = (char*)calloc(%s, sizeof(char));\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    fputs("total = getdelim(&(*result), &size, ASC(sep), stdin); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == ASC(sep)) { (*result)[total-1] = '\\0'; } else { ERROR = 2; RUNTIMEFERR(\"INPUT\", ERROR, k, l); } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "READLN[[:space:]]") ){
    fprintf(g_FUNCTIONS, "void b2c_readln(char **result, FILE *from) { size_t size; ssize_t total; size = %s; *result = (char*)calloc(%s, sizeof(char));\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    fputs("total = getline(&(*result), &size, from); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == '\\n') { (*result)[total-1] = '\\0'; } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "RETURN[[:space:]]") ){
    fprintf(g_FUNCTIONS, "char *b2c_return (char *data) { static char *rbuffer[%s] = { NULL }; static int rbuffer_ptr = 0; size_t size; if(data == NULL) { return(NULL); } size = b2c_len (data); if(size == 0) { return(NULL); }\n", STR( g_MAX_RBUFFERS));
    fprintf(g_FUNCTIONS, "rbuffer_ptr++; if(rbuffer_ptr >= %s) { rbuffer_ptr = 0; } rbuffer[rbuffer_ptr] = (char *) __b2c_str_realloc (rbuffer[rbuffer_ptr], size); memcpy (rbuffer[rbuffer_ptr], data, size);\n", STR( g_MAX_RBUFFERS));
    fputs("__b2c__SETLEN (rbuffer[rbuffer_ptr], size); rbuffer[rbuffer_ptr][size] = '\\0'; return (rbuffer[rbuffer_ptr]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "JOIN[[:space:]]") ){
    fputs("void b2c_join (char **result, char **array, int base, int size, char *by) { long dlen, i, slen, total; dlen = b2c_len (by); total = b2c_len (array[0 + base]);\n", g_FUNCTIONS);
    fputs("*result = (char*)calloc(total, sizeof(char)+1); memmove(*result, array[0 + base], total); for (i = 1; i < size; i++) { if (array[i + base] != NULL) { slen = b2c_len (array[i + base]);\n", g_FUNCTIONS);
    fputs("*result = (char *) realloc (*result, (total + dlen + slen + 1) * sizeof (char)); memmove (*result + total, by, dlen); total += dlen; memmove (*result + total, array[i + base], slen);\n", g_FUNCTIONS);
    fputs("total += slen; } } (*result)[total] = '\\0'; }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "NETWORK[[:space:]]") ){
        if( TALLY(g_LIB_TLS, "gnutls") ){
        fputs("#define SSL_set_tlsext_host_name(connection, name) gnutls_server_name_set(((SSL*)connection)->gnutls_state, GNUTLS_NAME_DNS, name, LEN(name))\n", g_FUNCTIONS);
        fputs("#undef VERIFY\n", g_FUNCTIONS);
        fputs("long VERIFY(uintptr_t ssl, char* pem) { int result = 0; gnutls_certificate_credentials_t cred = 0; if((SSL*)ssl == NULL) { return(-1); }\n", g_FUNCTIONS);
        fputs("gnutls_certificate_allocate_credentials(&cred); gnutls_certificate_set_x509_trust_file(cred, pem, GNUTLS_X509_FMT_PEM);\n", g_FUNCTIONS);
        fputs("if(gnutls_credentials_set(((SSL*)ssl)->gnutls_state, GNUTLS_CRD_CERTIFICATE, cred) != 0) { return(-1); } if(gnutls_certificate_verify_peers2(((SSL*)ssl)->gnutls_state, &result) !=0) { return(-1); }\n", g_FUNCTIONS);
        fputs("gnutls_certificate_free_credentials(cred); return(result); }\n", g_FUNCTIONS);
        fprintf(g_FUNCTIONS, "SSL_METHOD *TLS_client_method(void) { SSL_METHOD *tls; tls = calloc(1, sizeof(SSL_METHOD)); strncpy(tls->priority_string, %s, 256); tls->connend = 2; return(tls); }\n", g_PRIORITY);
        }
    fputs("int b2c_network_init(uintptr_t *handle, char *site, char *org, int sock_type, int sock_opt, char *nw_type, int multicast_ttl, int sctp_streams, int capeer, char *cacerts, char *priv, char *cert) { struct sockaddr_in *addr, *from; struct hostent *he;\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "long amount = 0; long length = 0; char data_client[%s]; char *host, *local, *port, *from_client; struct timeval tval; int sock, i, yes = 1; long start; char ttl = 1; b2c_delim_engine (2, &amount, site, \",\", 0);\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "addr = (struct sockaddr_in*)calloc(amount, sizeof(*addr)); for(i = 0; i < amount; i++) { start = b2c_delim_engine (1, &length, site, \",\", i+1); if(length >= %s) { return(5); } memset(data_client, 0, %s);\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    fputs("strncpy(data_client, site+start, length); if(strstr(data_client, \":\") == NULL) { return(10); } host = strtok(data_client, \":\"); port = strtok(NULL, \":\"); he = gethostbyname(host); if(he == NULL || he->h_addr == NULL) { return(11); }\n", g_FUNCTIONS);
    fputs("addr[i].sin_family = AF_INET; addr[i].sin_port = htons((long)atol(port)); addr[i].sin_addr = *((struct in_addr *) he->h_addr); }\n", g_FUNCTIONS);
        if( __b2c__STRCMP(g_NETWORKTYPE ,  "SCTP") == 0 ){
        fputs("sock = socket(AF_INET, sock_type, IPPROTO_SCTP);\n", g_FUNCTIONS);
        } else {
        fputs("sock = socket(AF_INET, sock_type, 0);\n", g_FUNCTIONS);
        }
    fputs("if(sock == -1) { return(12); } tval.tv_sec = sock_opt; tval.tv_usec = 0; setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tval, sizeof (struct timeval));\n", g_FUNCTIONS);
    fputs("setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)); if(org) { b2c_delim_engine (2, &amount, org, \",\", 0); from = (struct sockaddr_in*)calloc(amount, sizeof(*from));\n", g_FUNCTIONS);
    fputs("for(i = 0; i < amount; i++) { start = b2c_delim_engine (1, &length, site, \",\", i+1); from_client = b2c_strndup(org+start, length); if(strstr(from_client, \":\"))\n", g_FUNCTIONS);
    fputs("{ local = strtok(from_client, \":\"); port = strtok(NULL, \":\"); } else { local = from_client; port = NULL; } he = gethostbyname(local); if(he == NULL || he->h_addr == NULL) { return(11); }\n", g_FUNCTIONS);
    fputs("from[i].sin_family = AF_INET; if(port) { from[i].sin_port = htons((long)atol(port)); } from[i].sin_addr = *((struct in_addr *)he->h_addr); free(from_client); }\n", g_FUNCTIONS);
        if( __b2c__STRCMP(g_NETWORKTYPE ,  "SCTP") == 0 ){
        fputs("if(sctp_bindx(sock, (struct sockaddr *)from, 1, SCTP_BINDX_ADD_ADDR) < 0) { return(17); } free(from); }\n", g_FUNCTIONS);
        fputs("struct sctp_initmsg initmsg; memset (&initmsg, 0, sizeof (initmsg)); initmsg.sinit_max_attempts = 3; initmsg.sinit_num_ostreams = sctp_streams; initmsg.sinit_max_instreams = sctp_streams;\n", g_FUNCTIONS);
        fprintf(g_FUNCTIONS, "setsockopt(sock, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof (initmsg));%s#ifdef SCTP_SOCKOPT_CONNECTX_OLD%sif(sctp_connectx(sock, (struct sockaddr *) addr, 1, NULL) < 0) { return(13); }\n", NL, NL);
        fprintf(g_FUNCTIONS, "#else%sif(sctp_connectx(sock, (struct sockaddr *) addr, 1) < 0) { return(13); }%s#endif\n", NL, NL);
        } else {
        fputs("if(bind(sock, (struct sockaddr *)from, sizeof(struct sockaddr)) < 0) { return(17); } free(from); }\n", g_FUNCTIONS);
        fputs("if (!strcmp(nw_type, \"BROADCAST\")) { setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int)); } if(!strcmp(nw_type, \"MULTICAST\")) { setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &yes, sizeof(int));\n", g_FUNCTIONS);
        fputs("ttl = multicast_ttl; setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(unsigned char)); }\n", g_FUNCTIONS);
        fputs("if(connect(sock, (struct sockaddr*)addr, sizeof(struct sockaddr)) < 0) { return(13); }\n", g_FUNCTIONS);
        }
    fputs("*handle = sock;\n", g_FUNCTIONS);
        if( g_OPTION_TLS ){
        fputs("if(b2c_option_tls) { int ret; SSL_CTX *ssl_context = NULL; SSL *ssl_sock; SSL_library_init(); ssl_context = SSL_CTX_new(TLS_client_method()); SSL_CTX_set_verify(ssl_context, capeer, NULL);\n", g_FUNCTIONS);
            if( NOT(TALLY(g_LIB_TLS, "gnutls")) ){
            fputs("SSL_CTX_load_verify_locations(ssl_context, cacerts, NULL);\n", g_FUNCTIONS);
            }
            if( NOT(TALLY(g_LIB_TLS, "gnutls"))  AND  NOT(TALLY(g_LIB_TLS, "wolfssl")) ){
            fputs("SSL_CTX_set_options(ssl_context, SSL_OP_LEGACY_SERVER_CONNECT);\n", g_FUNCTIONS);
            }
        fputs("if(priv != NULL && SSL_CTX_use_PrivateKey_file(ssl_context, priv, SSL_FILETYPE_PEM) <= 0) { return(41); } if(cert != NULL && SSL_CTX_use_certificate_file(ssl_context, cert, SSL_FILETYPE_PEM) <= 0) { return(41); }\n", g_FUNCTIONS);
        fputs("SSL_CTX_set_options(ssl_context, SSL_OP_ALL); ssl_sock = SSL_new(ssl_context); SSL_set_tlsext_host_name(ssl_sock, host); if(SSL_set_fd(ssl_sock, *handle) == 0) { return(40); }\n", g_FUNCTIONS);
        fputs("if((ret = SSL_connect(ssl_sock)) <= 0) { fprintf(stderr, \"SSL CONNECT error: %s\\n\", ERR_error_string(SSL_get_error(ssl_sock, ret), NULL)); return(40); }\n", g_FUNCTIONS);
        fputs("*handle = (uintptr_t)ssl_sock; }\n", g_FUNCTIONS);
        }
    fputs("free(addr); return(0); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SERVER[[:space:]]") ){
        if( TALLY(g_LIB_TLS, "gnutls") ){
        fputs("SSL_METHOD *TLS_server_method(void) { SSL_METHOD *tls; tls = calloc(1, sizeof(SSL_METHOD)); strncpy(tls->priority_string, \"NONE:PFS:+VERS-ALL:+VERS-DTLS-ALL:+CIPHER-ALL:+CIPHER-GOST-ALL:+MAC-ALL:+MAC-GOST-ALL\", 256); tls->connend = 1; return(tls); }\n", g_FUNCTIONS);
        }
    fputs("int b2c_server_init(uintptr_t *handle, char *site, int sock_type, int sock_opt, int sctp_streams) { struct sockaddr_in *addr; struct hostent *he; long amount = 0; long length = 0; char *host, *port;\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "char data_client[%s]; struct timeval tval; int fd, i, yes = 1; long start; b2c_delim_engine (2, &amount, site, \",\", 0); addr = (struct sockaddr_in*)calloc(amount, sizeof(*addr)); for(i = 0; i < amount; i++)\n", STR( g_BUFFER_SIZE));
    fprintf(g_FUNCTIONS, "{ start = b2c_delim_engine(1, &length, site, \",\", i + 1); if (length >= %s) { return (5); } memset (data_client, 0, %s); strncpy(data_client, site + start, length);\n", STR( g_BUFFER_SIZE), STR( g_BUFFER_SIZE));
    fputs("if(strstr(data_client, \":\") == NULL) { return(10); } host = strtok(data_client, \":\"); port = strtok(NULL, \":\"); if(strstr(site, \"INADDR_ANY:\") || strstr(site, \"*:\")) { addr[i].sin_addr.s_addr = htonl(INADDR_ANY); }\n", g_FUNCTIONS);
    fputs("else { he = gethostbyname(host); if(he == NULL || he->h_addr == NULL) { return(11); } addr[i].sin_addr = *((struct in_addr*)he->h_addr); }\n", g_FUNCTIONS);
    fputs("addr[i].sin_family = AF_INET; addr[i].sin_port = htons((long)atol(port)); }\n", g_FUNCTIONS);
        if( __b2c__STRCMP(g_NETWORKTYPE ,  "SCTP") == 0 ){
        fputs("fd = socket(AF_INET, sock_type, IPPROTO_SCTP);\n", g_FUNCTIONS);
        fputs("struct sctp_initmsg initmsg; memset(&initmsg, 0, sizeof(initmsg)); initmsg.sinit_max_attempts = 3;\n", g_FUNCTIONS);
        fputs("initmsg.sinit_num_ostreams = sctp_streams; initmsg.sinit_max_instreams = sctp_streams;\n", g_FUNCTIONS);
        fputs("setsockopt(fd, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof(initmsg));\n", g_FUNCTIONS);
        } else {
        fputs("fd = socket(AF_INET, sock_type, 0);\n", g_FUNCTIONS);
        }
    fputs("if(fd == -1) { return(12); } tval.tv_sec = sock_opt; tval.tv_usec = 0; setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &tval, sizeof(struct timeval));\n", g_FUNCTIONS);
    fputs("setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));\n", g_FUNCTIONS);
        if( __b2c__STRCMP(g_NETWORKTYPE ,  "SCTP") == 0 ){
        fputs("if(sctp_bindx(fd, (struct sockaddr *)addr, 1, SCTP_BINDX_ADD_ADDR) < 0) { return(17); }\n", g_FUNCTIONS);
        } else {
        fputs("if(bind(fd, (struct sockaddr *)addr, sizeof(struct sockaddr)) < 0) { return(17); }\n", g_FUNCTIONS);
        }
        if( __b2c__STRCMP(g_NETWORKTYPE ,  "MULTICAST") == 0 ){
        fputs("struct ip_mreq imreq; imreq.imr_multiaddr.s_addr = inet_addr(host); imreq.imr_interface.s_addr = INADDR_ANY;\n", g_FUNCTIONS);
        fputs("setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &imreq, sizeof(imreq));\n", g_FUNCTIONS);
        }
        if( __b2c__STRCMP(g_NETWORKTYPE ,  "UDP") != 0  AND  __b2c__STRCMP(g_NETWORKTYPE ,  "BROADCAST") != 0  AND  __b2c__STRCMP(g_NETWORKTYPE ,  "MULTICAST") != 0 ){
        fprintf(g_FUNCTIONS, "if(listen(fd, %s) < 0) { return(18); }\n", STR( g_MAX_BACKLOG));
        }
    fputs("*handle = fd; free(addr); return(0); }\n", g_FUNCTIONS);
    fputs("uintptr_t b2c_accept(int l, char *k, char *priv, char *cert, uintptr_t fd) { uintptr_t handle; int desc; desc = accept(fd, NULL, NULL); if(desc < 0){ ERROR = 19; RUNTIMEFERR(\"ACCEPT\", ERROR, k, l); return(0); }\n", g_FUNCTIONS);
        if( g_OPTION_TLS ){
        fputs("if(b2c_option_tls) { int result = 0; SSL_CTX *ssl_context = NULL; SSL *ssl_sock = NULL; SSL_library_init(); ssl_context = SSL_CTX_new(TLS_server_method());\n", g_FUNCTIONS);
        fputs("if(SSL_CTX_use_PrivateKey_file(ssl_context, priv, SSL_FILETYPE_PEM) <= 0) { return(41); } if(SSL_CTX_use_certificate_file(ssl_context, cert, SSL_FILETYPE_PEM) <= 0) { return(41); }\n", g_FUNCTIONS);
        fputs("ssl_sock = SSL_new(ssl_context); SSL_set_fd(ssl_sock, desc); if((result = SSL_accept(ssl_sock)) <= 0){ fprintf(stderr, \"SSL ACCEPT error: %s\\n\", ERR_error_string(SSL_get_error(ssl_sock, result), NULL));\n", g_FUNCTIONS);
        fputs("return(-1); } handle = (uintptr_t)ssl_sock; } else { handle = (uintptr_t)desc; }\n", g_FUNCTIONS);
        } else {
        fputs("if(!b2c_option_tls) { handle = (uintptr_t)desc; }\n", g_FUNCTIONS);
        }
    fputs("return(handle); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "APPEND[[:space:]]|SAVE[[:space:]]")  OR  g_OPTION_EVAL ){
    fputs("int b2c_save(int mode, size_t size, char *file, ...) { FILE *outfile; va_list args; char *item; switch(mode){ case 0: case 1: outfile = fopen((const char *) file, \"w\"); break;\n", g_FUNCTIONS);
    fputs("case 2: case 3: outfile = fopen((const char *) file, \"a\"); break; } if (outfile == NULL) { return(2); } switch(mode) { case 0: case 2: va_start(args, file); while((item = va_arg(args, char*)) != NULL)\n", g_FUNCTIONS);
    fputs("{ fprintf(outfile, \"%s\", item); } va_end(args); break; case 1: case 3: va_start(args, file); if(fwrite(va_arg(args, void*), 1, size, outfile) != size){ return(2); } va_end(args); break; } fclose (outfile); return(0); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SETSERIAL[[:space:]]") ){
    fputs("int __b2c_setserial(int device, int mode, int param, int value, int donot) { struct termios tty; memset(&tty, 0, sizeof(tty)); if(tcgetattr(device, &tty) != 0) { return(33); } switch(mode)\n", g_FUNCTIONS);
    fputs("{ case 0: if(donot) { tty.c_iflag &= value; } else { tty.c_iflag |= value; } break; case 1: if(donot) { tty.c_oflag &= value; } else { tty.c_oflag |= value; } break; case 2: if(donot) { tty.c_cflag &= value; }\n", g_FUNCTIONS);
    fputs("else { tty.c_cflag |= value; } break; case 3: if(donot) { tty.c_lflag &= value; } else { tty.c_lflag |= value; } break; case 4: tty.c_cc[param] = value; break; case 5: cfsetospeed(&tty, value); cfsetispeed(&tty, value);\n", g_FUNCTIONS);
    fputs("break; } if(tcsetattr(device, TCSANOW, &tty) != 0) { return(33); } return(0); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "GETLINE[[:space:]]") ){
    fputs("char *b2c_getline(char **handle) { char *pos, *result; if(*handle == NULL || (*handle)[0] == '\\0') { return(NULL); } else { pos = strchr(*handle, '\\n'); if(pos)\n", g_FUNCTIONS);
    fputs("{ result = __b2c_Copy_N_String(NULL, *handle, (size_t)(pos - *handle)); } else { result = b2c_CopyString(NULL, *handle); } *handle += b2c_len(result); if((*handle)[0] == '\\n') { (*handle)++; } } return(result); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SPLIT[[:space:]]") ){
    fputs("void b2c_split_by(char ***array, int base, long *amount, char *string, char *by) { long length, i, start; b2c_free_str_array_members(&(*array), base, *amount);\n", g_FUNCTIONS);
    fputs("start = b2c_delim_engine(2, amount, string, by, 0); *array = (char**)realloc(*array, (*amount+base) * sizeof(char*)); for (i = 0; i < *amount; i++)\n", g_FUNCTIONS);
    fputs("{ start = b2c_delim_engine_cache(1, &length, string, by, i+1); (*array)[i + base] =__b2c_Copy_N_String(NULL, string + start, (size_t)length); } }\n", g_FUNCTIONS);
    fputs("void b2c_split_with(char ***array, int base, long *amount, char *string, int counter) { long length, i; b2c_free_str_array_members (&(*array), base, *amount);\n", g_FUNCTIONS);
    fputs("length = b2c_len(string); if (counter > length) { counter = length; } *amount = (length / counter) + (length % counter != 0 ? 1 : 0); *array = (char**)realloc(*array, (*amount+base)*sizeof(char*));\n", g_FUNCTIONS);
    fputs("if (counter > 0) { for (i = 0; i < *amount; i++) { (*array)[i + base] = __b2c_Copy_N_String(NULL, string + i*counter, (size_t)counter); } } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FOR[[:space:]]") ){
    fputs("long b2c_for_amount(char *string, char *step) { long amount = 0; b2c_delim_engine(2, &amount, string, step, 0); return(amount); }\n", g_FUNCTIONS);
    fputs("void b2c_for_item (char **string, char *step, char **result) { long length = 0; long start; start = b2c_delim_engine (1, &length, *string, step, 1); if(length == 0) { *result = NULL; } else\n", g_FUNCTIONS);
    fputs("{ *result = (char *) __b2c_str_realloc (*result, length + 1); memmove (*result, *string + start, length); __b2c__SETLEN (*result, length); (*result)[length] = '\\0'; } *string += (start + length + b2c_len (step)); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "MAKEDIR[[:space:]]") ){
    fputs("int b2c_makedir(char *newdir) { long start, amount = 0, length = 0; int item, collapse; char *dir; if (newdir != NULL && *newdir != 0) { collapse = b2c_collapse; b2c_collapse = 0; dir = (char*)calloc(b2c_len(newdir)+1, sizeof(char));\n", g_FUNCTIONS);
    fputs("start = b2c_delim_engine(2, &amount, newdir, \"/\", 0); for(item = 1; item <= amount; item++) { start = b2c_delim_engine(1, &length, newdir, \"/\", item); if(length) { strncat(dir, newdir+start, length);\n", g_FUNCTIONS);
    fputs("if(mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) < 0 && errno != EEXIST && errno != 0) { return(21); } } if(item < amount) { strcat(dir, \"/\"); } } free(dir); b2c_collapse = collapse; } return(0); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ALARM[[:space:]]") ){
    fputs("void b2c_alarm(void *func, long time) { void(*target)(int); struct itimerval alarm; struct sigaction psa; memset(&psa, 0, sizeof(psa)); psa.sa_flags = SA_RESETHAND|SA_RESTART;\n", g_FUNCTIONS);
    fputs("*((void**)&target) = func; psa.sa_handler = target; sigaction(SIGALRM, &psa, NULL); alarm.it_value.tv_sec = (long)(time)/1000; alarm.it_value.tv_usec = ((time)%1000)*1000;\n", g_FUNCTIONS);
    fputs("alarm.it_interval.tv_sec = 0; alarm.it_interval.tv_usec = 0; setitimer(ITIMER_REAL, &alarm, NULL); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SIGNAL[[:space:]]") ){
    fputs("void b2c_signal(void *func, int action) { void(*target)(int); struct sigaction psa; memset(&psa, 0, sizeof(psa)); *((void**)&target) = func; psa.sa_flags = SA_RESETHAND|SA_RESTART; psa.sa_handler = target; sigaction(action, &psa, NULL); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "CA\\$\\(|CIPHER\\$\\(|CN\\$\\(")  OR  g_OPTION_TLS ){
    fputs("char *b2c_ca(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; X509 *cert; X509_NAME *name; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); } cert = (X509*)SSL_get_peer_certificate((SSL*)desc); if(cert==NULL) { ERROR = 41; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); }\n", g_FUNCTIONS);
    fputs("name = X509_get_issuer_name(cert); X509_NAME_oneline(name, buffer, 4095); len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0';\n", g_FUNCTIONS);
        if( TALLY(g_LIB_TLS, "gnutls") ){
        fputs("free(name);\n", g_FUNCTIONS);
        }
    fputs("X509_free(cert); return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    fputs("char *b2c_cn(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; X509 *cert; X509_NAME *name; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CN$\", ERROR, k, l); return(NULL); } cert = (X509*)SSL_get_peer_certificate((SSL*)desc); if(cert==NULL) { ERROR = 41; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); }\n", g_FUNCTIONS);
    fputs("name = X509_get_subject_name(cert); X509_NAME_oneline(name, buffer, 4095); len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0';\n", g_FUNCTIONS);
        if( TALLY(g_LIB_TLS, "gnutls") ){
        fputs("free(name);\n", g_FUNCTIONS);
        }
    fputs("X509_free(cert); return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    fputs("char *b2c_cipher(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CIPHER$\", ERROR, k, l); return(NULL); } SSL_CIPHER_description(SSL_get_current_cipher((SSL*)desc), buffer, 4095);\n", g_FUNCTIONS);
    fputs("len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "ESCAPE\\$\\(") ){
    fputs("char *b2c_escape(int l, char *k, char *string) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long slen, length = 0; unsigned int current; if (string == NULL) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char));\n", g_FUNCTIONS);
    fputs("while(*string) { current = b2c_utf8toasc(string); if(current > 0xffff) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + 11); snprintf(buf[idx]+length, 11, \"\\\\U%08X\", current); length += 10; } else if(current > 0x7f)\n", g_FUNCTIONS);
    fputs("{ buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + 7); snprintf(buf[idx]+length, 7, \"\\\\u%04X\", current); length += 6; } else { buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + 2);\n", g_FUNCTIONS);
    fputs("switch(current) { case 7: snprintf(buf[idx]+length, 3, \"\\\\a\"); length+=2; break; case 8: snprintf(buf[idx]+length, 3, \"\\\\b\"); length+=2; break; case 27: snprintf(buf[idx]+length, 3, \"\\\\e\"); length+=2; break;\n", g_FUNCTIONS);
    fputs("case 12: snprintf(buf[idx]+length, 3, \"\\\\f\"); length+=2; break; case 10: snprintf(buf[idx]+length, 3, \"\\\\n\"); length+=2; break; case 13: snprintf(buf[idx]+length, 3, \"\\\\r\"); length+=2; break;\n", g_FUNCTIONS);
    fputs("case 9: snprintf(buf[idx]+length, 3, \"\\\\t\"); length+=2; break; case 11: snprintf(buf[idx]+length, 3, \"\\\\v\"); length+=2; break; case 92: snprintf(buf[idx]+length, 3, \"\\\\\\\\\"); length+=2; break;\n", g_FUNCTIONS);
    fputs("case 39: snprintf(buf[idx]+length, 3, \"\\\\'\"); length+=2; break; case 34: snprintf(buf[idx]+length, 3, \"\\\\\\\"\"); length+=2; break; case 63: snprintf(buf[idx]+length, 3, \"\\\\?\"); length+=2; break;\n", g_FUNCTIONS);
    fputs("default: snprintf(buf[idx]+length, 2, \"%c\", current); length+=1; } } slen = b2c_blen(l, k, \"ESCAPE$\", string, 1, 0); if(slen == 0) { break; } else {string += slen; } } __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "UNESCAPE\\$\\(") ){
    fputs("char *b2c_unescape(int l, char *k, char *string) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, tlen, length = 0; char *pos, *status = NULL; char hex[9], buffer[9]; uint32_t byte; if (string == NULL) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }\n", g_FUNCTIONS);
    fputs("buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char)); while((pos = strchr (string, 92)) != NULL) { switch (*(pos + 1)) { case 'u': case 'U': buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + (pos - string)); memcpy(buf[idx] + length, string, (size_t) (pos - string));\n", g_FUNCTIONS);
    fputs("length += (uintptr_t) (pos - string); string = pos + 2; if (*(pos + 1) == 'u') { tlen = 4; } else { tlen = 8; } if (b2c_len (string) < tlen) { ERROR = 5; RUNTIMEFERR(\"UNESCAPE$\", ERROR, k, l); return(NULL); } strncpy (hex, string, tlen); hex[tlen] = '\\0';\n", g_FUNCTIONS);
    fputs("byte = strtol (hex, &status, 16); len = __b2c_utf8_conv (byte, buffer); buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + len); memcpy(buf[idx] + length, buffer, len); string += tlen; length += len;\n", g_FUNCTIONS);
    fputs("break; default: buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + (pos - string) + 1); memcpy(buf[idx] + length, string, (size_t) (pos - string)); length += (uintptr_t) (pos - string);\n", g_FUNCTIONS);
    fputs("switch (*(pos + 1)) { case 'a': byte = 7; string = pos + 2; break; case 'b': byte = 8; string = pos + 2; break; case 'e': byte = 27; string = pos + 2; break; case 'f': byte = 12; string = pos + 2; break; case 'n': byte = 10; string = pos + 2; break;\n", g_FUNCTIONS);
    fputs("case 'r': byte = 13; string = pos + 2; break; case 't': byte = 9; string = pos + 2; break; case 'v': byte = 11; string = pos + 2; break; case 92: byte = 92; string = pos + 2; break; case 39: byte = 39; string = pos + 2; break;\n", g_FUNCTIONS);
    fputs("case 34: byte = 34; string = pos + 2; break; case 63: byte = 63; string = pos + 2; break; default: byte = (uint8_t)(*(pos)); string = pos + 1; } buf[idx][length] = (uint8_t) byte; length += 1; } } len = b2c_len(string);\n", g_FUNCTIONS);
    fputs("buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + len + 1); memcpy(buf[idx] + length, string, len); length += len; __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "TREE[[:space:]]") ){
    fputs("void b2c_tree_add(void *node, void **tree, int(*func)(const void*, const void*)) { void *result; if(node) { result = tsearch(node, tree, func); if(*(uintptr_t**)result != (uintptr_t*)node) { __b2c__STRFREE(node); } } }\n", g_FUNCTIONS);
    fprintf(g_FUNCTIONS, "void b2c_binary_tree_free(void *tree, int(*func)(const void*, const void*)) { int total, i; void **array = { NULL }; total = b2c_collect(tree, &array, %s, 0); for(i = %s; i<total; i++)\n", STR( g_OPTION_BASE), STR( g_OPTION_BASE));
    fputs("{ tdelete((void*)array[i], &tree, func); __b2c__STRFREE(array[i]); } if(array) { free(array); } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "FIND\\(") ){
    fputs("int b2c_find(int (*func)(const void*, const void*), void* tree, void* node, int dofree) { void **result; result = tfind(node, &tree, func); if(dofree) { free(node); } if(result == NULL) { return(0); } return(1); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SGN\\(") ){
    fputs("char b2c_sgn(double data) { if(data == 0) { return(0); } if(data > 0) { return(1); } return(-1); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "VAL\\(") ){
    fputs("double b2c_val(char *data) { if(data == NULL) { return(0); } return(atof(data)); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "SETENVIRON[[:space:]]") ){
    fputs("void b2c_setenviron(char *name, char *value) { if(name != NULL && value != NULL) { setenv(name, value, 1); } }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "COLLECT[[:space:]]|TREE[[:space:]]") ){
    fputs("static void b2c_collect_do(const void *node, VISIT which, int depth) { switch (which) { case preorder: break; case endorder: break; case postorder: case leaf: b2c_twalk_idx++; b2c_twalk_array = (void**)realloc(b2c_twalk_array, sizeof(void*)*b2c_twalk_idx);\n", g_FUNCTIONS);
    fputs("b2c_twalk_array[b2c_twalk_idx-1] = *(uintptr_t**)node; break; } }\n", g_FUNCTIONS);
    fputs("int b2c_collect(void *tree, void ***array, int base, int type) { int i, count; if(b2c_twalk_array) { free(b2c_twalk_array); b2c_twalk_array = NULL; } if(*array) { free(*array); *array = NULL; } b2c_twalk_idx = 0; twalk(tree, b2c_collect_do); count = base;\n", g_FUNCTIONS);
    fputs("*array = (void*)calloc(b2c_twalk_idx, sizeof(void*)); for (i = 0; i < b2c_twalk_idx; i++) { switch(type) { case 0: (*array)[count++] = (char*)b2c_twalk_array[i]; break; case 1: (*(double**)array)[count++] = *(double*)b2c_twalk_array[i]; break;\n", g_FUNCTIONS);
    fputs("case 2: (*(float**)array)[count++] = *(float*)b2c_twalk_array[i]; break; case 3: (*(long**)array)[count++] = *(long*)b2c_twalk_array[i]; break; case 4: (*(int**)array)[count++] = *(int*)b2c_twalk_array[i]; break;\n", g_FUNCTIONS);
    fputs("case 5: (*(short**)array)[count++] = *(short*)b2c_twalk_array[i]; break; case 6: (*(char**)array)[count++] = *(char*)b2c_twalk_array[i]; break; } } return (count-base); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "TOTAL\\(") ){
    fputs("static void b2c_total_do(const void *node, VISIT which, int depth) { switch (which) { case preorder: break; case endorder: break; case postorder: case leaf: b2c_twalk_idx++; break; } }\n", g_FUNCTIONS);
    fputs("int b2c_total(void *tree) { b2c_twalk_idx = 0; twalk(tree, b2c_total_do); return(b2c_twalk_idx); }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "PARSE[[:space:]]") ){
    fputs("void b2c_parse(char ***array, int base, long *amount1, char *string, char *with, char *delim) { long dlen, start1, start2, amount2, length1, length2, tmplen, sublen = 0; int x, i = 0, wildcard = 0, next = 0; char *pos = NULL;\n", g_FUNCTIONS);
    fputs("b2c_free_str_array_members (&(*array), base, *amount1); free (*array); *array = NULL; if (string == NULL && with == NULL) { *amount1 = 0; return; } if (delim == NULL) { delim = b2c_option_delim; }\n", g_FUNCTIONS);
    fputs("start1 = b2c_delim_engine (2, amount1, string, delim, 0); if(*amount1 == 0) { return; } *array = (char **) realloc (*array, (*amount1 + base) * sizeof (char *)); dlen = b2c_len (delim);\n", g_FUNCTIONS);
    fputs("for (x = 0; x < *amount1; x++) { start1 = b2c_delim_engine (1, &length1, string, delim, 1); start2 = b2c_delim_engine (1, &length2, with, delim, 1); if(!strncmp (with, \"?\", 1))\n", g_FUNCTIONS);
    fputs("{ (*array)[i + base] = __b2c_Copy_N_String(NULL, string, (size_t) length1); i++; string += (start1 + length1 + dlen); with += (start2 + length2 + dlen); } else { next = 0; if(!strncmp (with, \"*\", 1))\n", g_FUNCTIONS);
    fputs("{ wildcard = 1; if(!pos) { pos = string; } b2c_delim_engine (2, &amount2, with + 1, delim, 0); if(amount2) { next = 1 + dlen; } else { next = 1; } } else if(!strncmp(with, \"\\\\*\", 2) || !strncmp(with, \"\\\\?\", 2))\n", g_FUNCTIONS);
    fputs("{ with++; length2--; } b2c_delim_engine (1, &tmplen, with + next, delim, 1); if(length1 != tmplen || memcmp(string, with+next, tmplen)) { if (wildcard == 1) { if(sublen == 0) { sublen += length1; } else { sublen += length1 + dlen; } }\n", g_FUNCTIONS);
    fputs("else { b2c_free_str_array_members (&(*array), base, i); free (*array); *array = NULL; i = 0; break; } } else { if(wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t)sublen); pos = NULL; sublen = 0; i++; } wildcard = 0; }\n", g_FUNCTIONS);
    fputs("string += (start1 + length1 + dlen); if (wildcard == 0) { with += (start2 + length1 + dlen + next); } } } if (wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t) sublen); i++; } *amount1 = i; }\n", g_FUNCTIONS);
    }
    if( REGEX(g_DEPEND, "COLLAPSE\\$\\(") ){
    fputs("char *b2c_collapse_func(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, option, x, total = 0; long amount = 0, length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = b2c_option_delim; }\n", g_FUNCTIONS);
    fputs("option = b2c_collapse; b2c_collapse = 1; dlen = b2c_len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], b2c_len (string) + 1); b2c_delim_engine(2, &amount, string, delim, 0); for (x = 0; x < amount; x++)\n", g_FUNCTIONS);
    fputs("{ start = b2c_delim_engine (1, &length, string, delim, 1); memmove(buf[idx] + total, string + start, length); total += length; if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen); total += dlen; }\n", g_FUNCTIONS);
    fputs("string += (start + length); } b2c_collapse = option; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }\n", g_FUNCTIONS);
    }
    fclose(g_FUNCTIONS);
    g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_GENERIC , " " , g_FUNCTIONS) ;
    if( g_SEMANTIC == 0 ){
        semantic__b2c_array = b2c_lookup_by_order(assoc_g_SEMANTIC_MEMFREE, &semantic, semantic__b2c_array, 1);
        COUNTER = semantic__b2c_array;
        while( (COUNTER )> 0 ){
            if( LEN(g_SEMANTIC_MEMFREE(semantic[(uint64_t)COUNTER])) ){
            fprintf(stderr, "WARNING: no FREE for the memory address %s!\n", g_SEMANTIC_MEMFREE(semantic[(uint64_t)COUNTER]));
            }
            COUNTER = COUNTER - (1);
        }
    }
    if( g_SEMANTIC == 0 ){
        semantic__b2c_array = b2c_lookup_by_order(assoc_g_SEMANTIC_OPENCLOSE, &semantic, semantic__b2c_array, 1);
        COUNTER = semantic__b2c_array;
        while( (COUNTER )> 0 ){
            if( LEN(g_SEMANTIC_OPENCLOSE(semantic[(uint64_t)COUNTER])) ){
            fprintf(stderr, "WARNING: no CLOSE for the OPEN handle %s!\n", g_SEMANTIC_OPENCLOSE(semantic[(uint64_t)COUNTER]));
            }
            COUNTER = COUNTER - (1);
        }
    }
    if( LEN(g_FUNCNAME) ){
    fprintf(stderr, "Syntax error: the SUB/FUNCTION '%s' has no END in file '%s'!\n", g_FUNCNAME, g_CURFILE);
        exit(1);
    }
    if( ISTRUE(g_TMP_PRESERVE) ){
        if( ISTRUE(LEN(EXEC("command -v indent 2>/dev/null"))) ){
        fputs("Applying indentation... ", stdout);
            fflush(stdout);
            b2c_forin_tmpfile_string = b2c_CopyString(b2c_forin_tmpfile_string, g_TMP_FILES); b2c_forin_tmpfile_string_org = b2c_forin_tmpfile_string;
            b2c_forin_tmpfile_step = b2c_CopyString(b2c_forin_tmpfile_step, b2c_option_delim);
            b2c_forin_tmpfile_ptr = b2c_for_amount(b2c_forin_tmpfile_string, b2c_forin_tmpfile_step);
            for(; b2c_forin_tmpfile_ptr > 0; b2c_forin_tmpfile_ptr--) { b2c_for_item(&b2c_forin_tmpfile_string_org, b2c_forin_tmpfile_step, &tmpfile);
                if( NOT(REGEX(tmpfile, ".*\\.cpp"))  AND  NOT(REGEX(tmpfile, ".*\\.tmp"))  AND  NOT(REGEX(tmpfile, ".*\\.bac$"))  AND  NOT(REGEX(tmpfile, ".*\\.nostr$")) ){
                    if( ISTRUE(INSTR(OS, "Darwin"))  OR  ISTRUE(INSTR(OS, "BSD")) ){
                    if(rename(tmpfile, CONCAT( tmpfile , ".BAK")) < 0) { ERROR = 9; RUNTIMEERROR("RENAME", 10405, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    RETVAL = system(CONCAT( "indent " , tmpfile , ".BAK " , tmpfile) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
                    if(unlink(CONCAT( tmpfile , ".BAK") )==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 10407, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    } else {
                    RETVAL = system(CONCAT( "indent -bad -bap -bli0 -cli4 -cbi0 -nbc -nbfda -nsc -nprs -bls -blf -lp -ts4 -ppi2 -npsl -i4 -il4 -l140 -nbbo " , tmpfile) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
                    if(unlink(CONCAT( tmpfile , "~") )==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 10411, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
                    }
                }
            }
        fputs("done.\n", stdout);
        } else {
        fputs("WARNING: 'indent' not found on this system!\n", stdout);
        fputs("Generated source code cannot be beautified.\n", stdout);
        }
    }
    if( g_XGETTEXT ){
        if( ISTRUE(LEN(EXEC("command -v xgettext 2>/dev/null"))) ){
        fputs("Executing xgettext... ", stdout);
            fflush(stdout);
        RETVAL = system(CONCAT( "xgettext --keyword=INTL" , g_STRINGSIGN , " --keyword=NNTL" , g_STRINGSIGN , ":1,2 -d " , BASENAME(g_SOURCEFILE, 1) , " -s -o " , BASENAME(g_SOURCEFILE, 1) , ".pot " , g_TMP_FILES) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
            if( FILEEXISTS( CONCAT(BASENAME(g_SOURCEFILE, 1) , ".pot") ) ){
            fputs("done.\n", stdout);
            } else {
            fputs("WARNING: catalog file not created!\n", stdout);
            }
        } else {
        fputs("WARNING: 'xgettext' not found on this system!\n", stdout);
        }
    }
    makefile = fopen((const char*)CONCAT( g_TEMPDIR , "/Makefile.bacon" ), "w");
if(makefile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 10438, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
fprintf(makefile, "# Created with BaCon %s - (c) Peter van Eerten - MIT License%s\n", g_VERSION, NL);
fprintf(makefile, "%s%s: %s.o\n", BASENAME(g_SOURCEFILE, 1), g_BINEXT, BASENAME(g_SOURCEFILE));
fprintf(makefile, "%s%s -o %s%s %s.o %s %s -lm\n", TAB(1), g_CCNAME, BASENAME(g_SOURCEFILE, 1), g_BINEXT, BASENAME(g_SOURCEFILE), g_LDFLAGS, g_LIB_TLS);
fprintf(makefile, "%s.o: %s.c\n", BASENAME(g_SOURCEFILE), BASENAME(g_SOURCEFILE));
fprintf(makefile, "%s%s %s -c %s.c\n", TAB(1), g_CCNAME, g_CCFLAGS, BASENAME(g_SOURCEFILE));
fprintf(makefile, "%s.PHONY: clean\n", NL);
fputs("clean:\n", makefile);
fprintf(makefile, "%srm -f *.o *.c %s%s %s.*.* Makefile.bacon\n", TAB(1), BASENAME(g_SOURCEFILE, 1), g_BINEXT, BASENAME(g_SOURCEFILE, 1));
    fclose(makefile);
    g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_TEMPDIR , "/Makefile.bacon") ;
    if( ISFALSE(g_NO_COMPILE) ){
        if( ISFALSE(LEN(EXEC( CONCAT("command -v " , g_CCNAME , " 2>/dev/null") ))) ){
        fprintf(stderr, "ERROR: '%s' not found on this system!\n", g_CCNAME);
        fputs("Generated source code cannot be compiled.\n", stderr);
            exit(0);
        }
    fprintf(stdout, "Compiling '%s'... ", g_SOURCEFILE);
        fflush(stdout);
        SETENVIRON("LANG", "C");
        old_curdir = b2c_CopyString(old_curdir, (char*) CURDIR);
    if(g_TEMPDIR == NULL || chdir(g_TEMPDIR) == -1){ ERROR = 22; RUNTIMEERROR("CHANGEDIR", 10464, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    RETVAL = system(CONCAT( "make -f Makefile.bacon 2>" , BASENAME(g_SOURCEFILE) , ".log") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
        RETURN_CODE=(long)( RETVAL);
    if(old_curdir == NULL || chdir(old_curdir) == -1){ ERROR = 22; RUNTIMEERROR("CHANGEDIR", 10469, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
        g_TMP_FILES = F_CONCAT(g_TMP_FILES, g_TMP_FILES , " " , g_TEMPDIR , "/" , BASENAME(g_SOURCEFILE) , ".log " , g_TEMPDIR , "/" , BASENAME(g_SOURCEFILE) , ".o") ;
        if( ISFALSE(FILELEN( CONCAT(g_TEMPDIR , "/" , BASENAME(g_SOURCEFILE) , ".log") )) ){
        fprintf(stdout, "Done, program '%s%s' ready.\n", BASENAME(g_SOURCEFILE, 1), g_BINEXT);
            if( g_EXEC ){
            RETVAL = system(CONCAT( g_TEMPDIR , "/" , BASENAME(g_SOURCEFILE, 1))); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
            }
        } else {
            b2c_forin_line_string = b2c_CopyString(b2c_forin_line_string, LOAD( CONCAT(g_TEMPDIR , "/" , BASENAME(g_SOURCEFILE) , ".log") )); b2c_forin_line_string_org = b2c_forin_line_string;
            b2c_forin_line_step = b2c_CopyString(b2c_forin_line_step, NL);
            b2c_forin_line_ptr = b2c_for_amount(b2c_forin_line_string, b2c_forin_line_step);
            for(; b2c_forin_line_ptr > 0; b2c_forin_line_ptr--) { b2c_for_item(&b2c_forin_line_string_org, b2c_forin_line_step, &line);
                if( REGEX(line, "\\.generic\\.h") ){
                    continue;
                }
                if( REGEX(line, "error:|warning:|note:") ){
                    line = b2c_CopyString(line, (char*) REPLACE(line, g_STRINGSIGN, "$"));
                    line = b2c_CopyString(line, (char*) REPLACE(line, g_FLOATSIGN, "#"));
                    line = b2c_CopyString(line, (char*) REPLACE(line, g_LONGSIGN, "%"));
                fprintf(stderr, "%s\n", line);
                    break;
                }
            }
            if( NOT(g_QUIET) ){
                if( __b2c__STRCMP(GETENVIRON("BACON_IN_DOCKER") ,  "true") == 0 ){
                    response = b2c_CopyString(response, (char*) "y");
                } else {
                fprintf(stdout, "%sINFO: see full error report (y/[n])? ", NL);
                    fflush(stdout);
                    b2c_input(__LINE__, __FILE__, &b2c_assign, "\n");
                    response = b2c_CopyString(response, b2c_assign);
                    __b2c__STRFREE(b2c_assign); b2c_assign = NULL;
                }
                if( __b2c__STRCMP(LCASE(response) ,  "y") == 0 ){
                    line = b2c_CopyString(line, (char*) LOAD( CONCAT(g_TEMPDIR , "/" , BASENAME(g_SOURCEFILE) , ".log") ));
                    line = b2c_CopyString(line, (char*) REPLACE(line, g_STRINGSIGN, "$"));
                    line = b2c_CopyString(line, (char*) REPLACE(line, g_FLOATSIGN, "#"));
                    line = b2c_CopyString(line, (char*) REPLACE(line, g_LONGSIGN, "%"));
                fprintf(stderr, "%s\n", line);
                }
            }
            g_TMP_PRESERVE=(long)( 1);
        }
    }
    if( ISFALSE(g_TMP_PRESERVE) ){
        b2c_forin_tmpfile_string = b2c_CopyString(b2c_forin_tmpfile_string, g_TMP_FILES); b2c_forin_tmpfile_string_org = b2c_forin_tmpfile_string;
        b2c_forin_tmpfile_step = b2c_CopyString(b2c_forin_tmpfile_step, b2c_option_delim);
        b2c_forin_tmpfile_ptr = b2c_for_amount(b2c_forin_tmpfile_string, b2c_forin_tmpfile_step);
        for(; b2c_forin_tmpfile_ptr > 0; b2c_forin_tmpfile_ptr--) { b2c_for_item(&b2c_forin_tmpfile_string_org, b2c_forin_tmpfile_step, &tmpfile);
            if( FILEEXISTS(tmpfile)  AND  NOT(REGEX(tmpfile, ".bac$")) ){
            if(unlink(tmpfile)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 10511, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
            }
        }
    }
    b2c_hash_clear(assoc_g_ALL_MAIN_VARS);
    b2c_hash_clear(assoc_g_ALL_FUNC_VARS);
    b2c_hash_clear(assoc_g_ALL_DIM_VARS);
    b2c_hash_clear(assoc_g_SEMANTIC_MEMFREE);
    b2c_hash_clear(assoc_g_SEMANTIC_OPENCLOSE);
    b2c_hash_clear(assoc_g_MACRO_STRINGS);
    exit(RETURN_CODE);
    __B2C__PROGRAM__EXIT:
    return(0);
}
