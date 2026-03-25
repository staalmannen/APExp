/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Editor_Restore_Normal( void) {
    b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    b2c_signal((void*)(uintptr_t)SIG_DFL,  SIGINT);
    fprintf(stdout,"\033[%ldS", (long)1); fflush(stdout);
    fprintf(stdout,"\033[?47l"); fflush(stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( g_CURSOR_Y-1),(long)(g_CURSOR_X));fflush(stdout);
    fputs("\033[0m", stdout); fflush(stdout);
    fprintf(stdout,"\033[?25h"); fflush(stdout);
    ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, IXON, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7090, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7091, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  3, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7092, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
    fputs("\n", stdout);
    exit(EXIT_SUCCESS);

    __B2C__PROGRAM__EXIT: ;
    b2c_catch_set = b2c_catch_set_backup;
}
