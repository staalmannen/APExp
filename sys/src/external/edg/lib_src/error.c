/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/error.c"
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
#line 17 "lib_src/error.h"
enum an_error_code {
ec_none,
ec_abort_header,
ec_terminate_called,
ec_terminate_returned,
ec_already_marked_for_destruction,
ec_main_called_more_than_once,
ec_pure_virtual_called,
ec_bad_cast,
ec_bad_typeid,
ec_array_not_from_vec_new,
ec_terminate_called_more_than_once,
ec_negative_vla_size,
ec_vla_allocation_failed,
ec_deleted_virtual_called,
ec_thread_registration_failed,
ec_last};
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 69 "ape-sys/stdlib.h"
extern void abort(void);
#line 66 "ape-sys/stdio.h"
extern int fflush(FILE *);




extern int fprintf(FILE *, const char *, ...);
#line 20 "lib_src/error.c"
static const char *_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code(enum an_error_code err_code);
#line 77
static void _ZN28_INTERNAL_7_error_c_96006b1021display_abort_messageE13an_error_code(enum an_error_code err_code);
#line 91
extern void __abort_execution(enum an_error_code err_code);
#line 52 "ape-sys/stdio.h"
extern FILE *stdout;
extern FILE *stderr;
#line 20 "lib_src/error.c"
static const char *_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code( enum an_error_code __3018_45_err_code)



{
auto const char *__3023_15_s = ((const char *)0);

switch ((int)__3018_45_err_code) {
case 1:
__3023_15_s = ((const char *)"C++ runtime abort");
goto __T789090984;
case 2:
__3023_15_s = ((const char *)"terminate() called by the exception handling mechanism");
goto __T789090984;
case 3:
__3023_15_s = ((const char *)"returned from a user-defined terminate() routine");
goto __T789090984;
case 4:
__3023_15_s = ((const char *)"internal error: static object marked for destruction more than once");

goto __T789090984;
case 6:
__3023_15_s = ((const char *)"a pure virtual function was called");
goto __T789090984;
case 7:
__3023_15_s = ((const char *)"invalid dynamic cast");
goto __T789090984;
case 8:
__3023_15_s = ((const char *)"invalid typeid operation");
goto __T789090984;
case 9:
__3023_15_s = ((const char *)"freeing array not allocated by an array new operation");
goto __T789090984;
case 10:
__3023_15_s = ((const char *)"terminate() called itself recursively");
goto __T789090984;
case 11:
__3023_15_s = ((const char *)"negative size for variable-length array");
goto __T789090984;
case 12:
__3023_15_s = ((const char *)"VLA allocation failed");
goto __T789090984;
case 13:
__3023_15_s = ((const char *)"a deleted virtual function was called");
goto __T789090984;
case 14:
__3023_15_s = ((const char *)"registration for thread termination notification failed");
goto __T789090984;
case 5:
default:
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/error.c")), 70); abort(); } ;
goto __T789090984;
} __T789090984:;
return __3023_15_s;
}


static void _ZN28_INTERNAL_7_error_c_96006b1021display_abort_messageE13an_error_code( enum an_error_code __3075_49_err_code)



{ auto FILE *__T789113528; auto const char *__T789114176; auto const char *__T789114912;
(((__T789113528 = stderr) , (__T789114176 = (_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code(ec_abort_header)))) , (__T789114912 = (_ZN28_INTERNAL_7_error_c_96006b1010error_textE13an_error_code(__3075_49_err_code)))) , (fprintf(__T789113528, ((const char *)"%s: %s\n"), __T789114176, 
#line 82
__T789114912)); 

}
#line 91
void __abort_execution( enum an_error_code __3089_56_err_code)


{


_ZN28_INTERNAL_7_error_c_96006b1021display_abort_messageE13an_error_code(__3089_56_err_code);


fflush(stdout);
fflush(stderr);

abort(); 



}
