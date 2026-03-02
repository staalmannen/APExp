/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Editor_Restore_Normal( void) {
 __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 7084 "bacon.bac"
__b2c__signal((void*)(uintptr_t)SIG_DFL,  SIGINT);
#line 7085 "bacon.bac"
fprintf(stdout,"\033[%ldS", (long)1); fflush(stdout);
#line 7086 "bacon.bac"
fprintf(stdout,"\033[?47l"); fflush(stdout);
#line 7087 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( g_CURSOR_Y-1),(long)(g_CURSOR_X));fflush(stdout);
#line 7088 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7089 "bacon.bac"
fprintf(stdout,"\033[?25h"); fflush(stdout);
#line 7090 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, IXON, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7090, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7091 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7091, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7092 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  3, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7092, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7093 "bacon.bac"
fputs("\n", stdout);
#line 7094 "bacon.bac"
exit(EXIT_SUCCESS);
#line 7096 "bacon.bac"

__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
}
