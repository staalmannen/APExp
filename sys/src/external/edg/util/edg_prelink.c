/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:16 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "util/edg_prelink.c"
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
#line 28 "ape-sys/ctype.h"
enum _ZN33_INTERNAL_13_edg_prelink_c_optindUt_E {
_ISupper = 0x1,
_ISlower = 0x2,
_ISdigit = 0x4,
_ISspace = 0x8,
_ISpunct = 0x10,
_IScntrl = 0x20,
_ISblank = 0x40,
_ISxdigit = 0x80};
#line 22 "ape-sys/time.h"
struct timespec;
#line 12 "ape-sys/sys/stat.h"
struct stat;
#line 84 "util/edg_prelink.c"
struct a_pl_instantiation_site;
#line 100
struct a_pl_assignment;
#line 116
struct a_pl_symbol;
#line 226
struct a_pl_object_file;
#line 258
struct a_pl_input_file;
#line 333
struct a_pl_file_list_entry;
#line 351
union _ZN17a_pl_cmd_line_argUt_E;
#line 344
struct a_pl_cmd_line_arg;
#line 464
enum an_nm_format_kind {
nmfk_default,

nmfk_solaris,

nmfk_SGI,

nmfk_SVR4,

nmfk_HPUX,

nmfk_CLIX,

nmfk_gnu,

nmfk_MacOSX,

nmfk_MacOSX64,


nmfk_lst};
#line 662
enum a_pl_error_code {
pl_ec_no_longer_needed,
pl_ec_assigned_to_file,
pl_ec_message_prefix,
pl_ec_executing,
pl_ec_unrecognized_option,
pl_ec_error,
pl_ec_out_of_memory,
pl_ec_invalid_input,
pl_ec_bad_instantiation_request_file,
pl_ec_invalid_nm_format_option,
pl_ec_command_line_error,
pl_ec_instantiation_loop,
pl_ec_lib_file_not_found,
pl_ec_error_occurred_during_name_decoding,
pl_ec_warning,
pl_ec_invalid_reserved_request_lines_option,
pl_ec_cannot_open_obj_file_list_file,
pl_ec_cannot_open_request_file,
pl_ec_cannot_chdir,
pl_ec_no_nm_info,
pl_ec_popen_failed,
pl_ec_specialized_and_instantiated,
pl_ec_cannot_open_file_for_update,
pl_ec_nm_returned_error,
pl_ec_multiple_assignments,
pl_ec_no_object_file_name_specified,
pl_ec_invalid_definition_list_option,
pl_ec_cannot_open_temporary_file,
pl_ec_adopted_by_file,
pl_ec_out_of_date,
pl_ec_corrupted_template_info_file,
pl_ec_last};
#line 3966 "src/util.h"
enum _ZN3edg6detail16a_text_alignmentE {
_ZN3edg6detail7ta_leftE,
_ZN3edg6detail8ta_rightE};
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 16 "ape-sys/sys/types.h"
typedef unsigned short ino_t;
typedef unsigned short dev_t;
typedef long long off_t;

typedef unsigned short mode_t;
typedef short uid_t;
typedef short gid_t;
typedef short nlink_t;
typedef int pid_t;
#line 30
typedef long blksize_t;
typedef long long blkcnt_t;
#line 65
typedef long long time_t;
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 22 "ape-sys/time.h"
struct timespec {
time_t tv_sec;
long tv_nsec;char __dummy[4];};
#line 12 "ape-sys/sys/stat.h"
struct stat {
dev_t st_dev;
ino_t st_ino;
mode_t st_mode;
nlink_t st_nlink;
uid_t st_uid;
gid_t st_gid;
dev_t st_rdev;
off_t st_size;
struct timespec st_atim;
struct timespec st_mtim;
struct timespec st_ctim;
blksize_t st_blksize;
blkcnt_t st_blocks;};
#line 499 "src/basics.h"
typedef void *_ZN3edg10a_void_ptrE;
#line 61 "util/edg_prelink.c"
typedef _ZN3edg10a_void_ptrE a_realloc_arg;
#line 76
typedef struct a_pl_input_file *a_pl_input_file_ptr;
typedef struct a_pl_object_file *a_pl_object_file_ptr;
typedef struct a_pl_file_list_entry *a_pl_file_list_entry_ptr;




typedef struct a_pl_instantiation_site *a_pl_instantiation_site_ptr;
struct a_pl_instantiation_site {

a_pl_instantiation_site_ptr next;


a_pl_input_file_ptr input_file;};
#line 99
typedef struct a_pl_assignment *a_pl_assignment_ptr;
struct a_pl_assignment {

a_pl_assignment_ptr next;

char *name;
int times_assigned;char __dummy[4];};
#line 115
typedef struct a_pl_symbol *a_pl_symbol_ptr;
#line 215 "src/basics.h"
typedef _Bool _ZN3edg14a_byte_booleanE;
#line 116 "util/edg_prelink.c"
struct a_pl_symbol {

a_pl_symbol_ptr next;


a_pl_symbol_ptr next_in_symbol_table;


a_pl_symbol_ptr next_in_request_file;


a_pl_symbol_ptr next_in_specialization_list;



a_pl_input_file_ptr instantiation_file;



a_pl_instantiation_site_ptr possible_instantiation_sites;



a_pl_symbol_ptr global_sym;
#line 149
a_pl_symbol_ptr template_sym;
#line 156
a_pl_symbol_ptr primary_entry;




char *name;


_ZN3edg14a_byte_booleanE referenced;
#line 170
_ZN3edg14a_byte_booleanE defined;




_ZN3edg14a_byte_booleanE definition_seen_in_archive;
#line 182
_ZN3edg14a_byte_booleanE tentative_definition;
#line 188
_ZN3edg14a_byte_booleanE multiple_definition;



_ZN3edg14a_byte_booleanE is_template;



_ZN3edg14a_byte_booleanE can_be_instantiated;



_ZN3edg14a_byte_booleanE do_not_instantiate;
#line 207
_ZN3edg14a_byte_booleanE instantiated;
#line 214
_ZN3edg14a_byte_booleanE is_specialization;



a_pl_input_file_ptr defined_in;};
#line 226
struct a_pl_object_file {

a_pl_object_file_ptr next;


char *file_name;



a_pl_symbol_ptr symbols;



_ZN3edg14a_byte_booleanE included_in_output;
#line 245
_ZN3edg14a_byte_booleanE is_related_file;




time_t modification_time;};
#line 515 "src/basics.h"
typedef const char _ZN3edg12a_const_charE;
#line 258 "util/edg_prelink.c"
struct a_pl_input_file {

a_pl_input_file_ptr next;

char *file_name;

char *orig_name;




char *request_file_name;



char *template_info_file_name;




char *command_line;

char *compilation_directory;


char *compilation_file_name;


char *secondary_files;



a_pl_file_list_entry_ptr dependencies;




char *instantiation_directory;



_ZN3edg12a_const_charE *reserved_lines[1];
#line 305
a_pl_object_file_ptr objects;




a_pl_symbol_ptr request_list;


_ZN3edg14a_byte_booleanE is_archive;


_ZN3edg14a_byte_booleanE request_file_updated;




_ZN3edg14a_byte_booleanE recompile;



_ZN3edg14a_byte_booleanE is_local_file;char __dummy[4];};
#line 333
struct a_pl_file_list_entry {

a_pl_file_list_entry_ptr next;

char *name;};
#line 343
typedef struct a_pl_cmd_line_arg *a_pl_cmd_line_arg_ptr;
#line 351
union _ZN17a_pl_cmd_line_argUt_E {

char *arg_string;



a_pl_input_file_ptr input_file_entry;};
#line 214 "src/basics.h"
typedef _Bool _ZN3edg9a_booleanE;
#line 344 "util/edg_prelink.c"
struct a_pl_cmd_line_arg {

a_pl_cmd_line_arg_ptr next;

_ZN3edg9a_booleanE is_string;
#line 360
union _ZN17a_pl_cmd_line_argUt_E variant;};
#line 540
typedef char a_pl_input_line[32767];
#line 541 "src/basics.h"
typedef size_t _ZN3edg8sizeof_tE;
#line 65 "ape-sys/stdio.h"
extern int fclose(FILE *);
extern int fflush(FILE *);
extern FILE *fopen(const char *, const char *);



extern int fprintf(FILE *, const char *, ...);




extern int snprintf(char *, size_t, const char *, ...);
#line 86
extern int fputs(const char *, FILE *);
extern int getc(FILE *);
#line 119
extern FILE *popen(char *, char *);
extern int pclose(FILE *);
#line 42 "ape-sys/stdlib.h"
extern int atoi(const char *);
#line 66
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);
extern void abort(void);

extern void exit(int);
extern char *getenv(const char *);

extern int system(const char *);
#line 14 "ape-sys/string.h"
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);

extern char *strncat(char *, const char *, size_t);

extern int strcmp(const char *, const char *);




extern int strncmp(const char *, const char *, size_t);


extern char *strchr(const char *, int);


extern char *strrchr(const char *, int);

extern char *strstr(const char *, const char *);

extern void *memset(void *, int, size_t);

extern size_t strlen(const char *);
#line 114 "ape-sys/unistd.h"
extern pid_t getpid(void);
#line 135
extern int chdir(const char *);


extern char *getcwd(char *, size_t);
extern int unlink(const char *);
#line 186 "ape-sys/sys/stat.h"
extern int stat(const char *, struct stat *);
#line 16 "util/decode.h"
extern void _Z17decode_identifierPKcPcyPbS2_Py(_ZN3edg12a_const_charE *id, char *output_buffer, _ZN3edg8sizeof_tE output_buffer_size, _ZN3edg9a_booleanE *err, _ZN3edg9a_booleanE *buffer_overflow_err, _ZN3edg8sizeof_tE *required_buffer_size);
#line 57 "util/getopt.h"
extern int getopt(int argc, char *const *argv, const char *optstring);
#line 558 "util/edg_prelink.c"
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(_ZN3edg12a_const_charE *error_string);
#line 575
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(_ZN3edg12a_const_charE *filename, int line_number, _ZN3edg12a_const_charE *string1, _ZN3edg12a_const_charE *string2);
#line 632
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc(char *file_name);
#line 647
static void _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv(void);
#line 698
static _ZN3edg12a_const_charE *_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(enum a_pl_error_code error_code);
#line 810
static void _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePcb(enum a_pl_error_code error_code, char *insertion_string, _ZN3edg9a_booleanE exit_when_done);
#line 829
static void _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(enum a_pl_error_code error_code, char *insertion_string);
#line 841
static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(enum a_pl_error_code error_code, char *insertion_string);
#line 856
static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(_ZN3edg8sizeof_tE size);
#line 871
static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvy(_ZN3edg10a_void_ptrE old_ptr, _ZN3edg8sizeof_tE new_size);
#line 895
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
#line 916
static a_pl_input_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv(void);
#line 933
static a_pl_object_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv(void);
#line 957
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file(a_pl_object_file_ptr pofp);
#line 967
static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv(void);
#line 982
static a_pl_file_list_entry_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv(void);
#line 997
static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv(void);
#line 1034
static a_pl_instantiation_site_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv(void);
#line 1054
static void _ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site(a_pl_instantiation_site_ptr pisp);
#line 1064
static void _ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(a_pl_symbol_ptr psp);
#line 1074
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(FILE *f_input);
#line 1104
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(_ZN3edg12a_const_charE *source);
#line 1117
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc(char *name);
#line 1132
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc(char *name);
#line 1164
static void _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(void);
#line 1173
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(char *encoded_name);
#line 1209
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_(char **name1, char **name2, char *type, char **symbol_name);
#line 1319
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_(char **name1, char **name2, char *type, char **symbol_name);
#line 1508
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_(char **name1, char **name2, char *type, char **symbol_name);
#line 1733
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv(void);
#line 1908
static void _ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(a_pl_symbol_ptr psp, a_pl_input_file_ptr pifp);
#line 1930
static unsigned _ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(char *name);
#line 1966
static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc(char *name);
#line 1996
static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(char *name, a_pl_symbol_ptr other_sym, _ZN3edg9a_booleanE add, _ZN3edg9a_booleanE *p_new);
#line 2090
static void _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv(void);
#line 2112
static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(a_pl_object_file_ptr pofp, a_pl_input_file_ptr input_file);
#line 2222
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file(a_pl_object_file_ptr pofp);
#line 2262
static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv(void);
#line 2311
static void _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(void);
#line 2321
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc(char *name);
#line 2334
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(_ZN3edg12a_const_charE *name, _ZN3edg12a_const_charE *suffix);
#line 2366
static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
#line 2544
static void _ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(a_pl_input_file_ptr pifp, FILE *f_request);
#line 2589
static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv(void);
#line 2638
static void _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(a_pl_input_file_ptr pifp, char **request_file_name, char **template_info_file_name);
#line 2665
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
#line 2700
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol(a_pl_input_file_ptr pifp, a_pl_symbol_ptr psp);
#line 2722
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc(char *name);
#line 2745
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file(a_pl_input_file_ptr pifp);
#line 2788
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEb(_ZN3edg9a_booleanE do_local_files);
#line 2969
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc(char *new_dir);
#line 2984
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc(char **dest, _ZN3edg12a_const_charE *source);
#line 3030
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(_ZN3edg12a_const_charE *part1, _ZN3edg12a_const_charE *part2, _ZN3edg12a_const_charE *part3, _ZN3edg12a_const_charE *part4);
#line 3065
static int _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(a_pl_input_file_ptr pifp, _ZN3edg12a_const_charE *extra_command_args, _ZN3edg12a_const_charE *extra_args_for_display);
#line 3125
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc(char *file_name);
#line 3148
static void _ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
#line 3234
static FILE *_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv(void);
#line 3266
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv(void);
#line 3305
static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file(a_pl_input_file_ptr pifp);
#line 3346
static int _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv(void);
#line 3427
static int _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv(void);
#line 3460
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv(void);
#line 3600
static void _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(void);
#line 3685
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv(void);
#line 3695
static void _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(_ZN3edg12a_const_charE *addition);
#line 3713
static void _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(_ZN3edg12a_const_charE *add1, _ZN3edg12a_const_charE *add2);
#line 3725
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc(char *lib_name);
#line 3777
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(char *str, a_pl_input_file_ptr pifp);
#line 3800
extern int main(int argc, char **argv);
#line 4193 "src/util.h"
extern  /* COMDAT group: _ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_ */ int _ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_(char *dest_buff, size_t dest_buff_size, _ZN3edg12a_const_charE *format_str, unsigned long __1_args);
#line 22 "src/host_util.h"
extern unsigned long _ZN3edg6crc_32EPKcm(_ZN3edg12a_const_charE *str, unsigned long prev_crc);
#line 55
extern _ZN3edg12a_const_charE *_ZN3edg39generate_instantiation_output_file_nameEPKc(_ZN3edg12a_const_charE *mangled_name);
#line 223
extern _ZN3edg9a_booleanE _ZN3edg26get_file_modification_timeEPKcPx(_ZN3edg12a_const_charE *file_name, time_t *p_time);
#line 53 "ape-sys/stdio.h"
extern FILE *stderr;
#line 39 "ape-sys/ctype.h"
extern unsigned char _ctype[];
#line 5 "ape-sys/errno.h"
extern int *_errnoloc;
#line 95 "util/edg_prelink.h"
static char default_nm_command[12];
static char gnu_nm_command[18];
static char solaris_nm_command[8];
static char SGI_nm_command[13];
static char CLIX_nm_command[14];
static char alternate_nm_command[13];
static char nm_command_suffix[1];

static char *pl_predefined_names[1];
#line 45 "util/getopt.h"
char *optarg = 0;


extern int optind;

extern int opterr;
#line 76
static char *_ZZ6getoptE7optchar;
#line 365 "util/edg_prelink.c"
static a_pl_object_file_ptr avail_pl_object_files;
static a_pl_symbol_ptr avail_pl_symbols;
static a_pl_instantiation_site_ptr avail_pl_instantiation_sites;


static a_pl_input_file_ptr pl_input_files;


static FILE *f_command_output;




static a_pl_symbol_ptr pl_symbol_table_head;



static a_pl_symbol_ptr specialization_list;
#line 389
static char pl_file_name_buffer[4096];



static _ZN3edg9a_booleanE verbose;




static _ZN3edg9a_booleanE suppress_compilation;




static _ZN3edg9a_booleanE mangled_names_in_output;




static _ZN3edg9a_booleanE limit_recursion;
#line 414
static _ZN3edg9a_booleanE do_not_assign_to_nonlocal_objects;
#line 421
static _ZN3edg9a_booleanE check_specialization_errors;
#line 428
static _ZN3edg9a_booleanE suppress_dependency_checking;




static char **L_directories;



static int num_of_L_directories;




static _ZN3edg9a_booleanE one_instantiation_per_object;




static _ZN3edg9a_booleanE use_template_info_file;



static _ZN3edg9a_booleanE use_definition_list;



static char *temporary_file_name;



static FILE *f_informational;
#line 488
static enum an_nm_format_kind nm_format;



static _ZN3edg9a_booleanE ignore_invalid_nm_output;



static _ZN3edg12a_const_charE *message_prefix;




static _ZN3edg9a_booleanE skip_underscore_prefix;
#line 508
static _ZN3edg9a_booleanE move_nonlocal_objects_to_curr_dir;




static FILE *f_obj_file_list;
#line 520
static char curr_dir_name[2048];


static int reserved_request_file_lines;
#line 541
static a_pl_input_line pl_input_line;



static a_pl_assignment_ptr pl_assignment_table[599];



static a_pl_symbol_ptr pl_symbol_table[10007];
#line 65 "src/host_util.h"
static char _ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer[32];
#line 1139 "util/edg_prelink.c"
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
#line 1181
static char _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer[32767];
#line 1410
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer;
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer;

static _ZN3edg9a_booleanE _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL;
#line 3275
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option;
#line 3667
static char *temp_string;



static _ZN3edg8sizeof_tE temp_string_length;


static _ZN3edg8sizeof_tE pos_in_temp_string;
#line 3770
static a_pl_cmd_line_arg_ptr cmd_line_head;



static a_pl_cmd_line_arg_ptr cmd_line_tail; extern  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es[102]; extern  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0 */ char 
#line 3774
_ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0[1];
#line 95 "util/edg_prelink.h"
static char default_nm_command[12] = "/bin/nm -og";
static char gnu_nm_command[18] = "nm -og --no-cplus";
static char solaris_nm_command[8] = "nm -pxR";
static char SGI_nm_command[13] = "/bin/nm -Bop";
static char CLIX_nm_command[14] = "/bin/nm -pxre";
static char alternate_nm_command[13] = "/bin/nm -pxr";
static char nm_command_suffix[1] = "";

static char *pl_predefined_names[1] = {((char *)0)};
#line 48 "util/getopt.h"
int optind = 1;

int opterr = 1;
#line 76
static char *_ZZ6getoptE7optchar = ((char *)0);
#line 365 "util/edg_prelink.c"
static a_pl_object_file_ptr avail_pl_object_files = ((a_pl_object_file_ptr)0);
static a_pl_symbol_ptr avail_pl_symbols = ((a_pl_symbol_ptr)0);
static a_pl_instantiation_site_ptr avail_pl_instantiation_sites = ((a_pl_instantiation_site_ptr)0);


static a_pl_input_file_ptr pl_input_files = ((a_pl_input_file_ptr)0);
#line 378
static a_pl_symbol_ptr pl_symbol_table_head = ((a_pl_symbol_ptr)0);



static a_pl_symbol_ptr specialization_list = ((a_pl_symbol_ptr)0);
#line 393
static _ZN3edg9a_booleanE verbose = ((_ZN3edg9a_booleanE)1);




static _ZN3edg9a_booleanE suppress_compilation = ((_ZN3edg9a_booleanE)0);




static _ZN3edg9a_booleanE mangled_names_in_output = ((_ZN3edg9a_booleanE)0);




static _ZN3edg9a_booleanE limit_recursion = ((_ZN3edg9a_booleanE)1);
#line 414
static _ZN3edg9a_booleanE do_not_assign_to_nonlocal_objects = ((_ZN3edg9a_booleanE)0);
#line 421
static _ZN3edg9a_booleanE check_specialization_errors = ((_ZN3edg9a_booleanE)0);
#line 428
static _ZN3edg9a_booleanE suppress_dependency_checking = ((_ZN3edg9a_booleanE)0);
#line 437
static int num_of_L_directories = 0;




static _ZN3edg9a_booleanE one_instantiation_per_object = ((_ZN3edg9a_booleanE)0);




static _ZN3edg9a_booleanE use_template_info_file = ((_ZN3edg9a_booleanE)1);



static _ZN3edg9a_booleanE use_definition_list = ((_ZN3edg9a_booleanE)1);



static char *temporary_file_name = ((char *)0);
#line 488
static enum an_nm_format_kind nm_format = nmfk_default;



static _ZN3edg9a_booleanE ignore_invalid_nm_output = ((_ZN3edg9a_booleanE)0);
#line 501
static _ZN3edg9a_booleanE skip_underscore_prefix = ((_ZN3edg9a_booleanE)0);
#line 508
static _ZN3edg9a_booleanE move_nonlocal_objects_to_curr_dir = ((_ZN3edg9a_booleanE)0);




static FILE *f_obj_file_list = ((FILE *)0);
#line 523
static int reserved_request_file_lines = 0;
#line 1139
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer = ((char *)0);
#line 1410
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer = ((char *)0);
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer = ((char *)0);

static _ZN3edg9a_booleanE _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL = ((_ZN3edg9a_booleanE)0);
#line 3275
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option = ((char *)0);
#line 3770
static a_pl_cmd_line_arg_ptr cmd_line_head = ((a_pl_cmd_line_arg_ptr)0);



static a_pl_cmd_line_arg_ptr cmd_line_tail = ((a_pl_cmd_line_arg_ptr)0);  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es[102] = "src/util.h"
#line 3774
;  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0 */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0[1] = "";
#line 57 "util/getopt.h"
int getopt( int __27800_16_argc,  char *const *__27800_37_argv,  const char *__27800_55_optstring)
#line 73
{
auto int __27817_15_return_value;
auto char *__27818_16_optpos;
#line 83
if (_ZZ6getoptE7optchar == ((char *)0)) {
__27827_1_start_new_argument:;
if (optind >= __27800_16_argc) {

__27817_15_return_value = (-1);
goto __27905_1_end_of_routine;
} else  {
_ZZ6getoptE7optchar = (__27800_37_argv[optind]);
if (((int)(*_ZZ6getoptE7optchar)) != 45) {

__27817_15_return_value = (-1);
goto __27905_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 45) {
if (((int)(*(_ZZ6getoptE7optchar + 2))) == 0) {


optind++;
__27817_15_return_value = (-1);
} else  {

__27817_15_return_value = 63;
}
goto __27905_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


__27817_15_return_value = (-1);
goto __27905_1_end_of_routine;
} } }

_ZZ6getoptE7optchar++;
}
}


if (((int)(*_ZZ6getoptE7optchar)) == 0) {

optind++;
goto __27827_1_start_new_argument;
}

__27818_16_optpos = (strchr(((const char *)((char *)__27800_55_optstring)), ((int)(*_ZZ6getoptE7optchar))));
if (__27818_16_optpos == ((char *)0)) {

if (opterr) { fprintf(stderr, ((const char *)"%s: illegal option -- %c\n"), (__27800_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27817_15_return_value = 63;
goto __27905_1_end_of_routine;
}

__27817_15_return_value = ((int)(*_ZZ6getoptE7optchar));

if (((int)(*(__27818_16_optpos + 1))) == 58) {
if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


optind++;
if (optind >= __27800_16_argc) {


if (opterr) { fprintf(stderr, ((const char *)"%s: option requires an argument -- %c\n"), (__27800_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27817_15_return_value = 63;
goto __27905_1_end_of_routine;
}
optarg = (__27800_37_argv[optind]);
} else  {


optarg = (_ZZ6getoptE7optchar + 1);
}

_ZZ6getoptE7optchar = ((char *)0);
optind++;
} else  {

_ZZ6getoptE7optchar++;
optarg = ((char *)0);
}
__27905_1_end_of_routine:;
return __27817_15_return_value;
}
#line 558 "util/edg_prelink.c"
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc( _ZN3edg12a_const_charE *__28396_45_error_string)




{
fprintf(stderr, ((const char *)"%s: internal error: %s\n"), message_prefix, __28396_45_error_string);



fflush(stderr);
abort(); 

}



static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_( _ZN3edg12a_const_charE *__28413_47_filename, 
int __28414_18_line_number, 
_ZN3edg12a_const_charE *__28415_19_string1, 
_ZN3edg12a_const_charE *__28416_19_string2)



{
fprintf(stderr, ((const char *)"assertion failed: %s%s (%s, line %0d)\n"), __28415_19_string1, __28416_19_string2, __28413_47_filename, __28414_18_line_number);

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"assertion failed")); 
}
#line 632
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc( char *__36560_49_file_name)



{
#line 642
return (_Bool)(((int)(__36560_49_file_name[0])) == 47);

}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv(void)



{

if ((getcwd(curr_dir_name, 2048ULL)) == ((char *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"getcwd failed"));
} 



}
#line 698
static _ZN3edg12a_const_charE *_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code( enum a_pl_error_code __36626_52_error_code)




{
auto _ZN3edg12a_const_charE *__36632_17_m = ((_ZN3edg12a_const_charE *)0);
switch ((int)__36626_52_error_code) {
case 0:
__36632_17_m = ((const char *)"%s: %s no longer needed in %s\n");
goto __T1088009448;
case 1:
__36632_17_m = ((const char *)"%s: %s assigned to file %s\n");
goto __T1088009448;
case 2:
__36632_17_m = ((const char *)"C++ prelinker");
goto __T1088009448;
case 3:
__36632_17_m = ((const char *)"%s: executing: %s\n");
goto __T1088009448;
case 4:
__36632_17_m = ((const char *)"unrecognized option: %s\n");
goto __T1088009448;
case 5:
__36632_17_m = ((const char *)"%s: error: ");
goto __T1088009448;
case 6:
__36632_17_m = ((const char *)"out of memory");
goto __T1088009448;
case 7:
__36632_17_m = ((const char *)"invalid input format");
goto __T1088009448;
case 8:
__36632_17_m = ((const char *)"bad instantiation request file -- instantiation assigned to more than one file");

goto __T1088009448;
case 9:
__36632_17_m = ((const char *)"invalid nm format option");
goto __T1088009448;
case 10:
__36632_17_m = ((const char *)"command line error");
goto __T1088009448;
case 11:
__36632_17_m = ((const char *)"instantiation loop");
goto __T1088009448;
case 12:
__36632_17_m = ((const char *)"library \"%s\" does not exist in the specified library directories\n");
goto __T1088009448;
case 13:
__36632_17_m = ((const char *)"an error occurred during name decoding of \"%s\"");
goto __T1088009448;
case 14:
__36632_17_m = ((const char *)"%s: warning: ");
goto __T1088009448;
case 15:
__36632_17_m = ((const char *)"invalid reserved request file lines option \"%s\"");
goto __T1088009448;
case 16:
__36632_17_m = ((const char *)"cannot open object file name list file \"%s\"");
goto __T1088009448;
case 17:
__36632_17_m = ((const char *)"cannot create instantiation request file \"%s\"");
goto __T1088009448;
case 18:
__36632_17_m = ((const char *)"cannot change to directory \"%s\"");
goto __T1088009448;
case 19:
__36632_17_m = ((const char *)"no output produced by nm -- possible configuration problem");
goto __T1088009448;
case 20:
__36632_17_m = ((const char *)"unable to create process for nm command");
goto __T1088009448;
case 21:
__36632_17_m = ((const char *)"\"%s\" has been referenced as both an explicit specialization and a generated instantiation");

goto __T1088009448;
case 22:
__36632_17_m = ((const char *)"file \"%s\" is read-only");
goto __T1088009448;
case 23:
__36632_17_m = ((const char *)"nm returned a nonzero error status");
goto __T1088009448;
case 24:
__36632_17_m = ((const char *)"%s assigned to %s and %s\n");
goto __T1088009448;
case 25:
__36632_17_m = ((const char *)"-O and -N require a new object list file name specified with the -o option");

goto __T1088009448;
case 26:
__36632_17_m = ((const char *)"invalid definition list option \"%s\"");
goto __T1088009448;
case 27:
__36632_17_m = ((const char *)"cannot create temporary file \"%s\"");
goto __T1088009448;
case 28:
__36632_17_m = ((const char *)"%s: %s adopted by file %s\n");
goto __T1088009448;
case 29:
__36632_17_m = ((const char *)"%s: rebuilding %s because %s (used by an exported template file) has changed\n");

goto __T1088009448;
case 30:
__36632_17_m = ((const char *)"corrupted template information file or instantiation request file");
goto __T1088009448;
default:
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"invalid error code"));
} __T1088009448:;
return __36632_17_m;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePcb( enum a_pl_error_code __36738_48_error_code, 
char *__36739_39_insertion_string, 
_ZN3edg9a_booleanE __36740_49_exit_when_done)
#line 821
{
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_error)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(__36738_48_error_code)), __36739_39_insertion_string);
fprintf(stderr, ((const char *)"\n"));
if (__36740_49_exit_when_done) { exit(2); } 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc( enum a_pl_error_code __36757_38_error_code, 
char *__36758_29_insertion_string)




{

_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePcb(__36757_38_error_code, __36758_29_insertion_string, ((_ZN3edg9a_booleanE)1)); 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc( enum a_pl_error_code __36769_40_error_code, 
char *__36770_31_insertion_string)
#line 850
{
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_warning)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(__36769_40_error_code)), __36770_31_insertion_string);
fprintf(stderr, ((const char *)"\n")); 
}

static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy( _ZN3edg8sizeof_tE __36784_49_size)




{
auto _ZN3edg10a_void_ptrE __36790_14_ptr;

if ((__36790_14_ptr = ((_ZN3edg10a_void_ptrE)(malloc(__36784_49_size)))) == ((_ZN3edg10a_void_ptrE)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_out_of_memory, ((char *)0));
}
return __36790_14_ptr;
}


static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvy( _ZN3edg10a_void_ptrE __36799_52_old_ptr, 
_ZN3edg8sizeof_tE __36800_50_new_size)
#line 878
{
auto _ZN3edg10a_void_ptrE __36807_14_ptr;



if (__36799_52_old_ptr == ((_ZN3edg10a_void_ptrE)0)) {
__36807_14_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(__36800_50_new_size));
} else  {
__36807_14_ptr = ((_ZN3edg10a_void_ptrE)(realloc(((a_realloc_arg)__36799_52_old_ptr), __36800_50_new_size)));
if (__36807_14_ptr == ((_ZN3edg10a_void_ptrE)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_out_of_memory, ((char *)0));
}
}
return __36807_14_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file( a_pl_input_file_ptr __36823_53_pifp)




{
(__36823_53_pifp->request_list) = ((a_pl_symbol_ptr)0);
(__36823_53_pifp->objects) = ((a_pl_object_file_ptr)0);
(__36823_53_pifp->is_archive) = ((_ZN3edg14a_byte_booleanE)0);
(__36823_53_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)0);
(__36823_53_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)0);
(__36823_53_pifp->is_local_file) = ((_ZN3edg14a_byte_booleanE)1);
(__36823_53_pifp->command_line) = ((char *)0);
(__36823_53_pifp->compilation_directory) = ((char *)0);
(__36823_53_pifp->compilation_file_name) = ((char *)0);
(__36823_53_pifp->secondary_files) = ((char *)0);
(__36823_53_pifp->dependencies) = ((a_pl_file_list_entry_ptr)0);
(__36823_53_pifp->instantiation_directory) = ((char *)0); 
}


static a_pl_input_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv(void)



{
auto a_pl_input_file_ptr __36849_24_pifp;

__36849_24_pifp = ((a_pl_input_file_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(120ULL)));
(__36849_24_pifp->next) = ((a_pl_input_file_ptr)0);
(__36849_24_pifp->file_name) = ((char *)0);
(__36849_24_pifp->request_file_name) = ((char *)0);
(__36849_24_pifp->template_info_file_name) = ((char *)0);
_ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(__36849_24_pifp);
return __36849_24_pifp;
}


static a_pl_object_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv(void)



{
auto a_pl_object_file_ptr __36866_25_pofp;

if (avail_pl_object_files != ((a_pl_object_file_ptr)0)) {
__36866_25_pofp = avail_pl_object_files;
avail_pl_object_files = (__36866_25_pofp->next);
} else  {
__36866_25_pofp = ((a_pl_object_file_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(40ULL)));

}
(__36866_25_pofp->next) = ((a_pl_object_file_ptr)0);
(__36866_25_pofp->file_name) = ((char *)0);
(__36866_25_pofp->symbols) = ((a_pl_symbol_ptr)0);
(__36866_25_pofp->included_in_output) = ((_ZN3edg14a_byte_booleanE)0);
(__36866_25_pofp->is_related_file) = ((_ZN3edg14a_byte_booleanE)0);
(__36866_25_pofp->modification_time) = 0LL;
return __36866_25_pofp;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file( a_pl_object_file_ptr __36885_54_pofp)



{
(__36885_54_pofp->next) = avail_pl_object_files;
avail_pl_object_files = __36885_54_pofp; 
}


static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv(void)



{
auto a_pl_assignment_ptr __36900_23_ap;

__36900_23_ap = ((a_pl_assignment_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(24ULL)));
(__36900_23_ap->next) = ((a_pl_assignment_ptr)0);
(__36900_23_ap->name) = ((char *)0);
(__36900_23_ap->times_assigned) = 0;
return __36900_23_ap;
}


static a_pl_file_list_entry_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv(void)



{
auto a_pl_file_list_entry_ptr __36915_28_flep;

__36915_28_flep = ((a_pl_file_list_entry_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(16ULL)));

(__36915_28_flep->next) = ((a_pl_file_list_entry_ptr)0);
(__36915_28_flep->name) = ((char *)0);
return __36915_28_flep;
}


static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv(void)



{
auto a_pl_symbol_ptr __36930_20_psp;

if (avail_pl_symbols != ((a_pl_symbol_ptr)0)) {
__36930_20_psp = avail_pl_symbols;
avail_pl_symbols = (__36930_20_psp->next);
} else  {
__36930_20_psp = ((a_pl_symbol_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(104ULL)));
}
(__36930_20_psp->name) = ((char *)0);
(__36930_20_psp->next) = ((a_pl_symbol_ptr)0);
(__36930_20_psp->next_in_symbol_table) = ((a_pl_symbol_ptr)0);
(__36930_20_psp->next_in_request_file) = ((a_pl_symbol_ptr)0);
(__36930_20_psp->next_in_specialization_list) = ((a_pl_symbol_ptr)0);
(__36930_20_psp->global_sym) = ((a_pl_symbol_ptr)0);
(__36930_20_psp->template_sym) = ((a_pl_symbol_ptr)0);
(__36930_20_psp->primary_entry) = ((a_pl_symbol_ptr)0);
(__36930_20_psp->instantiation_file) = ((a_pl_input_file_ptr)0);
(__36930_20_psp->possible_instantiation_sites) = ((a_pl_instantiation_site_ptr)0);
(__36930_20_psp->referenced) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->defined) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->definition_seen_in_archive) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->tentative_definition) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->multiple_definition) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->is_template) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->instantiated) = ((_ZN3edg14a_byte_booleanE)0);
(__36930_20_psp->defined_in) = ((a_pl_input_file_ptr)0);
return __36930_20_psp;
}


static a_pl_instantiation_site_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv(void)



{
auto a_pl_instantiation_site_ptr __36967_32_pisp;

if (avail_pl_instantiation_sites != ((a_pl_instantiation_site_ptr)0)) {
__36967_32_pisp = avail_pl_instantiation_sites;
avail_pl_instantiation_sites = (__36967_32_pisp->next);
} else  {
__36967_32_pisp = ((a_pl_instantiation_site_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(16ULL)));

}
(__36967_32_pisp->next) = ((a_pl_instantiation_site_ptr)0);
(__36967_32_pisp->input_file) = ((a_pl_input_file_ptr)0);
return __36967_32_pisp;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site( a_pl_instantiation_site_ptr __36982_68_pisp)



{
(__36982_68_pisp->next) = avail_pl_instantiation_sites;
avail_pl_instantiation_sites = __36982_68_pisp; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol( a_pl_symbol_ptr __36992_44_psp)



{
(__36992_44_psp->next) = avail_pl_symbols;
avail_pl_symbols = __36992_44_psp; 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE( FILE *__37002_43_f_input)
#line 1080
{
auto char *__37009_14_buffer_pos = pl_input_line;
auto int __37010_14_size = 0;
auto int __37011_14_ch;
auto _ZN3edg9a_booleanE __37012_14_result;

while ((__37011_14_ch = (getc(__37002_43_f_input))) , ((__37011_14_ch != (-1)) && (__37011_14_ch != 10))) {
if ((++__37010_14_size) > 32767) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"pl_read_input_line: input line too long."));
}
(*(__37009_14_buffer_pos++)) = ((char)__37011_14_ch);
}


(*(__37009_14_buffer_pos++)) = ((char)0);


__37012_14_result = ((_ZN3edg9a_booleanE)1);
if ((__37011_14_ch == (-1)) && (__37010_14_size == 0)) { __37012_14_result = ((_ZN3edg9a_booleanE)0); }

return __37012_14_result;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc( _ZN3edg12a_const_charE *__37032_43_source)




{
auto char *__37038_9_dest;
__37038_9_dest = ((char *)(malloc(((strlen(__37032_43_source)) + 1ULL))));
strcpy(__37038_9_dest, __37032_43_source);
return __37038_9_dest;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc( char *__37045_55_name)



{
auto char *__37050_10_ptr;

__37050_10_ptr = (strstr(((const char *)__37045_55_name), ((const char *)"__S")));
return (_Bool)(__37050_10_ptr != ((char *)0));
}
#line 1132
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc( char *__37060_44_name)
#line 1138
{

auto char *__37068_10_from;
auto char *__37069_10_to;

if (_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer == ((char *)0)) {


_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(32767ULL)));
}

__37068_10_from = __37060_44_name;
__37069_10_to = _ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
while (((int)(*__37068_10_from)) != 0) {
if (((((int)(*__37068_10_from)) == 95) && (((int)(__37068_10_from[1])) == 95)) && (((int)(__37068_10_from[2])) == 83)) {
__37068_10_from += 3;
goto __T1088274168;
}
(*(__37069_10_to++)) = (*(__37068_10_from++)); __T1088274168:;
}

(*__37069_10_to) = ((char)0);
return _ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(void)



{
if (!(ignore_invalid_nm_output)) { _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_input, ((char *)0)); } 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc( char *__37101_36_encoded_name)



{
auto _ZN3edg9a_booleanE __37106_13_error;
auto _ZN3edg9a_booleanE __37107_13_buffer_overflow;
auto char *__37108_10_result;

auto _ZN3edg8sizeof_tE __37110_12_required_buffer_size;

if (mangled_names_in_output) {

__37108_10_result = __37101_36_encoded_name;

} else  { if ((((int)(__37101_36_encoded_name[0])) != 95) || (((int)(__37101_36_encoded_name[1])) != 90)) {



__37108_10_result = __37101_36_encoded_name;

} else  {
_Z17decode_identifierPKcPcyPbS2_Py(((_ZN3edg12a_const_charE *)__37101_36_encoded_name), _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer, 32767ULL, (&__37106_13_error), (&__37107_13_buffer_overflow), (&__37110_12_required_buffer_size));

__37108_10_result = _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer;
if (__37106_13_error) {


_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_error_occurred_during_name_decoding, __37101_36_encoded_name);
__37108_10_result = __37101_36_encoded_name;
}
} }
return __37108_10_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_( char **__37137_49_name1, 
char **__37138_21_name2, 
char *__37139_20_type, 
char **__37140_21_symbol_name)
#line 1257
{
auto _ZN3edg9a_booleanE __37186_13_result = ((_ZN3edg9a_booleanE)1);
auto char *__37187_10_pos;
auto char *__37188_10_rest_of_line;
auto char __37189_9_ch;


(*__37137_49_name1) = ((*__37138_21_name2) = ((*__37140_21_symbol_name) = ((char *)0)));
(*__37139_20_type) = ((char)0);


__37187_10_pos = (strchr(((const char *)pl_input_line), 58));
if (__37187_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37186_13_result = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)(*(__37187_10_pos + 1))) == 0) {


__37186_13_result = ((_ZN3edg9a_booleanE)0);
} else  {


__37187_10_pos = pl_input_line;
while ((__37189_9_ch = (*__37187_10_pos)) , ((((int)__37189_9_ch) != 32) && (((int)__37189_9_ch) != 0))) { __37187_10_pos++; }

if (((int)(*(__37187_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37187_10_pos)) == 32) { __37187_10_pos++; }

(*__37139_20_type) = (*(__37187_10_pos++));
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__37139_20_type)))])) & 0x3)) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

if (((int)(*(__37187_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37187_10_pos)) == 32) { __37187_10_pos++; }


__37188_10_rest_of_line = __37187_10_pos;
__37187_10_pos = (strchr(((const char *)__37188_10_rest_of_line), 58));

(*__37187_10_pos) = ((char)0);
(*__37137_49_name1) = __37188_10_rest_of_line;
__37188_10_rest_of_line = (__37187_10_pos + 1);
__37187_10_pos = (strchr(((const char *)__37188_10_rest_of_line), 58));
if (__37187_10_pos == ((char *)0)) {

(*__37138_21_name2) = ((char *)0);
} else  {


(*__37187_10_pos) = ((char)0);
(*__37138_21_name2) = __37188_10_rest_of_line;
__37188_10_rest_of_line = (__37187_10_pos + 1);
}
(*__37140_21_symbol_name) = __37188_10_rest_of_line;
} }
return __37186_13_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_( char **__37247_51_name1, 
char **__37248_18_name2, 
char *__37249_17_type, 
char **__37250_18_symbol_name)
#line 1405
{
auto _ZN3edg9a_booleanE __37334_13_result = ((_ZN3edg9a_booleanE)1);
auto char *__37335_10_pos;
auto char *__37336_10_rest_of_line;
auto char __37337_9_ch;
#line 1417
if (_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer == ((char *)0)) {
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(32767ULL)));
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(32767ULL)));
}

(*__37247_51_name1) = ((*__37248_18_name2) = ((*__37250_18_symbol_name) = ((char *)0)));
(*__37249_17_type) = ((char)0);


__37335_10_pos = (strchr(((const char *)pl_input_line), 58));
if (__37335_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37334_13_result = ((_ZN3edg9a_booleanE)0);
} else  { if ((strchr(((const char *)pl_input_line), 32)) == ((char *)0)) {
auto char *__37361_11_bracket_pos;



__37334_13_result = ((_ZN3edg9a_booleanE)0);


__37361_11_bracket_pos = (strchr(((const char *)pl_input_line), 91));
if (__37361_11_bracket_pos != ((char *)0)) { __37335_10_pos = __37361_11_bracket_pos; }

(*__37335_10_pos) = ((char)0);
strcpy(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer, ((const char *)pl_input_line));
__37336_10_rest_of_line = (__37335_10_pos + 1);
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL = ((_Bool)(__37361_11_bracket_pos == ((char *)0)));
if (!(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL)) {

__37335_10_pos = (strchr(((const char *)__37336_10_rest_of_line), 93));
(*__37335_10_pos) = ((char)0);
strcpy(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer, ((const char *)__37336_10_rest_of_line));
}
} else  {

(*__37247_51_name1) = _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer;
(*__37248_18_name2) = ((_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL) ? ((char *)0) : _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer);


if ((((int)nm_format) == 4) || (((int)nm_format) == 5)) {
__37336_10_rest_of_line = (__37335_10_pos + 1);
} else  {
__37336_10_rest_of_line = pl_input_line;
}


__37335_10_pos = __37336_10_rest_of_line;
while (((int)(*__37335_10_pos)) == 32) { __37335_10_pos++; }


while ((__37337_9_ch = (*__37335_10_pos)) , ((((int)__37337_9_ch) != 32) && (((int)__37337_9_ch) != 0))) { __37335_10_pos++; }

if (((int)(*(__37335_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37335_10_pos)) == 32) { __37335_10_pos++; }

(*__37249_17_type) = (*(__37335_10_pos++));
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__37249_17_type)))])) & 0x3)) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
if (((int)nm_format) == 4) {

switch ((int)(*__37249_17_type)) {
case 99: (*__37249_17_type) = ((char)67); goto __T1088437600;
} __T1088437600:;
}

if (((int)nm_format) == 4) { while ((((int)(*__37335_10_pos)) != 32) && (((int)(*__37335_10_pos)) != 0)) { __37335_10_pos++; } }

if (((int)(*(__37335_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37335_10_pos)) == 32) { __37335_10_pos++; }
if (((int)nm_format) == 5) {


if ((skip_underscore_prefix) && (((int)(*__37335_10_pos)) == 95)) { __37335_10_pos++; }
}
__37336_10_rest_of_line = __37335_10_pos;


if ((((int)nm_format) != 4) && (((int)nm_format) != 5)) {
__37335_10_pos = (strchr(((const char *)__37336_10_rest_of_line), 58));
__37336_10_rest_of_line = (__37335_10_pos + 1);
}
(*__37250_18_symbol_name) = __37336_10_rest_of_line;
} }
return __37334_13_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_( char **__37436_49_name1, 
char **__37437_14_name2, 
char *__37438_13_type, 
char **__37439_14_symbol_name)
#line 1612
{
auto _ZN3edg9a_booleanE __37541_13_result = ((_ZN3edg9a_booleanE)1);
auto char *__37542_10_pos;
auto char *__37543_10_rest_of_line;
auto char __37544_9_ch;


(*__37436_49_name1) = ((*__37437_14_name2) = ((*__37439_14_symbol_name) = ((char *)0)));
(*__37438_13_type) = ((char)0);
__37542_10_pos = pl_input_line;
#line 1628
__37542_10_pos = (strchr(((const char *)__37542_10_pos), 58));
if (__37542_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37541_13_result = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)(*(__37542_10_pos + 1))) == 0) {


__37541_13_result = ((_ZN3edg9a_booleanE)0);
} else  {
if (((int)nm_format) == 6) {
auto char *__37568_13_paren_pos;


(*__37542_10_pos) = ((char)0);
__37543_10_rest_of_line = (__37542_10_pos + 1);
__37568_13_paren_pos = (strchr(((const char *)pl_input_line), 40));
if (__37568_13_paren_pos == ((char *)0)) {

(*__37436_49_name1) = pl_input_line;
(*__37437_14_name2) = ((char *)0);
} else  {
auto char *__37579_15_end_of_name2;

(*__37436_49_name1) = pl_input_line;

(*__37568_13_paren_pos) = ((char)0);

(*__37437_14_name2) = (__37568_13_paren_pos + 1);
__37579_15_end_of_name2 = (strchr(((const char *)(*__37437_14_name2)), 41));

(*__37579_15_end_of_name2) = ((char)0);
}
} else  {


(*__37542_10_pos) = ((char)0);
(*__37436_49_name1) = pl_input_line;
__37543_10_rest_of_line = (__37542_10_pos + 1);
__37542_10_pos = (strchr(((const char *)__37543_10_rest_of_line), 58));
if (__37542_10_pos == ((char *)0)) {

(*__37437_14_name2) = ((char *)0);
} else  {


(*__37542_10_pos) = ((char)0);
(*__37437_14_name2) = __37543_10_rest_of_line;
__37543_10_rest_of_line = (__37542_10_pos + 1);
}
}
__37542_10_pos = __37543_10_rest_of_line;
if (((int)nm_format) == 2) {


while (((int)(*__37542_10_pos)) == 32) { __37542_10_pos++; }
}
if (((int)nm_format) == 7) {


auto int __37617_11_i;
for (__37617_11_i = 0; __37617_11_i < 9; ++__37617_11_i) {
if (((int)(*__37542_10_pos)) == 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37542_10_pos++;
}
} else  { if (((int)nm_format) == 8) {


auto int __37625_11_i;
for (__37625_11_i = 0; __37625_11_i < 17; ++__37625_11_i) {
if (((int)(*__37542_10_pos)) == 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37542_10_pos++;
}
} else  {


while ((__37544_9_ch = (*__37542_10_pos)) , ((((int)__37544_9_ch) != 32) && (((int)__37544_9_ch) != 0))) { __37542_10_pos++; }
} }

if (((int)(*(__37542_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37542_10_pos)) == 32) { __37542_10_pos++; }

(*__37438_13_type) = (*(__37542_10_pos++));
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__37438_13_type)))])) & 0x3)) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

if (((int)(*(__37542_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }


if ((skip_underscore_prefix) && (((int)(*__37542_10_pos)) == 95)) { __37542_10_pos++; }
(*__37439_14_symbol_name) = __37542_10_pos;
if (((int)nm_format) == 2) {




while ((__37544_9_ch = (*__37542_10_pos)) , ((((int)__37544_9_ch) != 32) && (((int)__37544_9_ch) != 0))) { __37542_10_pos++; }
if (((int)__37544_9_ch) == 32) { (*__37542_10_pos) = ((char)0); }
}
} }
return __37541_13_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv(void)
#line 1744
{
auto char *__37673_11_input_file_name = ((char *)0);
auto char *__37674_11_obj_file_name = ((char *)0);
auto _ZN3edg9a_booleanE __37675_14_is_archive = ((_ZN3edg9a_booleanE)0);
auto a_pl_object_file_ptr __37676_24_objects_tail = ((a_pl_object_file_ptr)0);
auto a_pl_object_file_ptr __37677_24_pofp = ((a_pl_object_file_ptr)0);
auto a_pl_input_file_ptr __37678_23_pifp = ((a_pl_input_file_ptr)0);
auto _ZN3edg9a_booleanE __37679_14_any_lines_read = ((_ZN3edg9a_booleanE)0);

while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(f_command_output)) { {
auto char *__37682_12_name1;
auto char *__37683_12_name2;
auto char __37684_11_type;
auto char *__37685_12_symbol_name;
auto a_pl_symbol_ptr __37686_21_psp;
auto _ZN3edg9a_booleanE __37687_16_process_line;
#line 1765
__37679_14_any_lines_read = ((_ZN3edg9a_booleanE)1);

if (((int)nm_format) == 1) {
__37687_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_((&__37682_12_name1), (&__37683_12_name2), (&__37684_11_type), (&__37685_12_symbol_name)));

} else  { if (((((int)nm_format) == 3) || (((int)nm_format) == 4)) || (((int)nm_format) == 5))

{
__37687_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_((&__37682_12_name1), (&__37683_12_name2), (&__37684_11_type), (&__37685_12_symbol_name)));

} else  {

__37687_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_((&__37682_12_name1), (&__37683_12_name2), (&__37684_11_type), (&__37685_12_symbol_name)));

} }
#line 1791
if (!(__37687_16_process_line)) { goto __T1088546720; }

if ((__37673_11_input_file_name == ((char *)0)) || ((strcmp(((const char *)__37673_11_input_file_name), ((const char *)__37682_12_name1))) != 0))
{



__37675_14_is_archive = ((_Bool)(__37683_12_name2 != ((char *)0)));
for (__37678_23_pifp = pl_input_files; __37678_23_pifp != ((a_pl_input_file_ptr)0); __37678_23_pifp = (__37678_23_pifp->next)) {
#line 1806
if ((__37675_14_is_archive) && ((strcmp(((const char *)(__37678_23_pifp->file_name)), ((const char *)__37682_12_name1))) != 0)) { goto __T1088553664; }


if (__37678_23_pifp->is_archive) { goto __T1088553664; }


for (__37677_24_pofp = (__37678_23_pifp->objects); __37677_24_pofp != ((a_pl_object_file_ptr)0); __37677_24_pofp = (__37677_24_pofp->next)) {
if ((strcmp(((const char *)(__37677_24_pofp->file_name)), ((const char *)__37682_12_name1))) == 0) { goto __T1088557944; }
} __T1088557944:;
if (__37677_24_pofp != ((a_pl_object_file_ptr)0)) { goto __T1088559352; }



if ((strcmp(((const char *)(__37678_23_pifp->file_name)), ((const char *)__37682_12_name1))) == 0) { goto __T1088559352; } __T1088553664:;
} __T1088559352:;
if (__37678_23_pifp == ((a_pl_input_file_ptr)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Input file not in list"));
}
__37673_11_input_file_name = (__37678_23_pifp->file_name);
(__37678_23_pifp->is_archive) = __37675_14_is_archive;
__37676_24_objects_tail = ((a_pl_object_file_ptr)0);
if (__37675_14_is_archive) {
__37674_11_obj_file_name = ((char *)0);
} else  {
if (__37677_24_pofp == ((a_pl_object_file_ptr)0)) {



__37677_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__37677_24_pofp->next) = (__37678_23_pifp->objects);
(__37678_23_pifp->objects) = __37677_24_pofp;
(__37677_24_pofp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37673_11_input_file_name)));
}
}
}

if (__37675_14_is_archive) {
if ((__37674_11_obj_file_name == ((char *)0)) || ((strcmp(((const char *)__37674_11_obj_file_name), ((const char *)__37683_12_name2))) != 0))
{

__37674_11_obj_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37683_12_name2)));
__37677_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__37677_24_pofp->file_name) = __37674_11_obj_file_name;


if ((__37678_23_pifp->objects) == ((a_pl_object_file_ptr)0)) { (__37678_23_pifp->objects) = __37677_24_pofp; }
if (__37676_24_objects_tail != ((a_pl_object_file_ptr)0)) { (__37676_24_objects_tail->next) = __37677_24_pofp; }
__37676_24_objects_tail = __37677_24_pofp;
}
}


if ((((((((((((int)__37684_11_type) != 66) && (((int)__37684_11_type) != 68)) && (((int)__37684_11_type) != 76)) && (((int)__37684_11_type) != 82)) && (((int)__37684_11_type) != 83)) && (((int)__37684_11_type) != 84)) && (((int)__37684_11_type) != 85)) && (((int)__37684_11_type) != 86)) && (((int)
#line 1858
__37684_11_type) != 87)) && (((int)__37684_11_type) != 67))
#line 1867
{


} else  {
__37686_21_psp = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());
(__37686_21_psp->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37685_12_symbol_name)));

switch ((int)__37684_11_type) {
case 66:
case 68:
case 76:
case 82:
case 83:
case 84:
case 86:
case 87:
(__37686_21_psp->defined) = ((_ZN3edg14a_byte_booleanE)1);
goto __T1088597736;
case 85:
(__37686_21_psp->referenced) = ((_ZN3edg14a_byte_booleanE)1);
goto __T1088597736;
case 67:
(__37686_21_psp->tentative_definition) = ((_ZN3edg14a_byte_booleanE)1);
goto __T1088597736;
default:
goto __T1088597736;
} __T1088597736:;

(__37686_21_psp->next) = (__37677_24_pofp->symbols);
(__37677_24_pofp->symbols) = __37686_21_psp;
}
} __T1088546720:; }
if (!(__37679_14_any_lines_read)) {


_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_no_nm_info, ((char *)0));
}
return;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file( a_pl_symbol_ptr __37836_61_psp, 
a_pl_input_file_ptr __37837_30_pifp)



{
auto a_pl_instantiation_site_ptr __37842_31_pisp;
#line 1920
if (((__37836_61_psp->possible_instantiation_sites) == ((a_pl_instantiation_site_ptr)0)) || (((__37836_61_psp->possible_instantiation_sites)->input_file) != __37837_30_pifp))
{
__37842_31_pisp = (_ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv());
(__37842_31_pisp->input_file) = __37837_30_pifp;
(__37842_31_pisp->next) = (__37836_61_psp->possible_instantiation_sites);
(__37836_61_psp->possible_instantiation_sites) = __37842_31_pisp;
} 
}


static unsigned _ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc( char *__37858_47_name)



{
auto unsigned __37863_16_hash_value = 0U;
auto char *__37864_10_ptr;
auto int __37865_8_length;




__37865_8_length = ((int)((unsigned)(strlen(((const char *)__37858_47_name)))));
__37864_10_ptr = __37858_47_name;
if (__37865_8_length > 9) {
__37863_16_hash_value = ((unsigned)(*(__37864_10_ptr++)));
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*(__37864_10_ptr++))));
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*__37864_10_ptr)));
__37864_10_ptr = ((__37858_47_name + (__37865_8_length >> 1)) - 1);
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*(__37864_10_ptr++))));
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*(__37864_10_ptr++))));
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*__37864_10_ptr)));
__37864_10_ptr = ((__37858_47_name + __37865_8_length) - 3);
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*(__37864_10_ptr++))));
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*(__37864_10_ptr++))));
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*__37864_10_ptr)));
} else  {
auto int __37885_9_a;
for (__37885_9_a = 0; __37885_9_a < __37865_8_length; __37885_9_a++) {
__37863_16_hash_value = ((__37863_16_hash_value * 73U) + ((unsigned)(*(__37864_10_ptr++))));
}
}
return __37863_16_hash_value;
}


static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc( char *__37894_53_name)




{
auto unsigned __37900_17_hash_value;
auto a_pl_assignment_ptr __37901_23_ap;
auto int __37902_9_bucket_number;

__37900_17_hash_value = (_ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(__37894_53_name));
__37902_9_bucket_number = ((int)(__37900_17_hash_value % 599U));

for (__37901_23_ap = ((pl_assignment_table)[__37902_9_bucket_number]); __37901_23_ap != ((a_pl_assignment_ptr)0); __37901_23_ap = (__37901_23_ap->next)) {
if ((strcmp(((const char *)(__37901_23_ap->name)), ((const char *)__37894_53_name))) == 0) {
goto __T1088679488;
}
} __T1088679488:;
if (__37901_23_ap == ((a_pl_assignment_ptr)0)) {

__37901_23_ap = (_ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv());
(__37901_23_ap->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37894_53_name)));

(__37901_23_ap->next) = ((pl_assignment_table)[__37902_9_bucket_number]);
((pl_assignment_table)[__37902_9_bucket_number]) = __37901_23_ap;
}
return __37901_23_ap;
}


static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb( char *__37924_46_name, 
a_pl_symbol_ptr __37925_55_other_sym, 
_ZN3edg9a_booleanE __37926_22_add, 
_ZN3edg9a_booleanE *__37927_23_p_new)
#line 2006
{
auto unsigned __37935_24_hash_value;
auto a_pl_symbol_ptr __37936_26_prev_sym_ptr;
auto a_pl_symbol_ptr __37937_32_sym_ptr = ((a_pl_symbol_ptr)0);
auto int __37938_32_bucket_number;
auto _ZN3edg9a_booleanE __37939_21_is_new = ((_ZN3edg9a_booleanE)0);




if ((__37925_55_other_sym != ((a_pl_symbol_ptr)0)) && ((__37925_55_other_sym->global_sym) != ((a_pl_symbol_ptr)0))) {
__37937_32_sym_ptr = (__37925_55_other_sym->global_sym);
goto __37998_1_symbol_found;
}
__37935_24_hash_value = (_ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(__37924_46_name));


__37938_32_bucket_number = ((int)(__37935_24_hash_value % 10007U));
if ((__37937_32_sym_ptr = ((pl_symbol_table)[__37938_32_bucket_number])) != ((a_pl_symbol_ptr)0)) {
__37936_26_prev_sym_ptr = ((a_pl_symbol_ptr)0);
do {
if ((strcmp(((const char *)__37924_46_name), ((const char *)(__37937_32_sym_ptr->name)))) == 0) {



if (__37936_26_prev_sym_ptr != ((a_pl_symbol_ptr)0)) {
(__37936_26_prev_sym_ptr->next) = (__37937_32_sym_ptr->next);
(__37937_32_sym_ptr->next) = ((pl_symbol_table)[__37938_32_bucket_number]);
((pl_symbol_table)[__37938_32_bucket_number]) = __37937_32_sym_ptr;
}
goto __37998_1_symbol_found;
}
__37936_26_prev_sym_ptr = __37937_32_sym_ptr;
} while ((__37937_32_sym_ptr = (__37937_32_sym_ptr->next)) != ((a_pl_symbol_ptr)0));
}



if (__37926_22_add) {
__37937_32_sym_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());

(__37937_32_sym_ptr->next_in_symbol_table) = pl_symbol_table_head;
pl_symbol_table_head = __37937_32_sym_ptr;



(__37937_32_sym_ptr->next) = ((pl_symbol_table)[__37938_32_bucket_number]);
((pl_symbol_table)[__37938_32_bucket_number]) = __37937_32_sym_ptr;
(__37937_32_sym_ptr->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37924_46_name)));
if (_ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc((__37937_32_sym_ptr->name))) {


(__37937_32_sym_ptr->is_specialization) = ((_ZN3edg14a_byte_booleanE)1);
(__37937_32_sym_ptr->next_in_specialization_list) = specialization_list;
specialization_list = __37937_32_sym_ptr;
}
#line 2067
__37939_21_is_new = ((_ZN3edg9a_booleanE)1);
}

__37998_1_symbol_found:;


if ((__37937_32_sym_ptr != ((a_pl_symbol_ptr)0)) && ((__37937_32_sym_ptr->primary_entry) != ((a_pl_symbol_ptr)0))) {
__37937_32_sym_ptr = (__37937_32_sym_ptr->primary_entry);
}
if (__37937_32_sym_ptr != ((a_pl_symbol_ptr)0)) {
if ((__37925_55_other_sym != ((a_pl_symbol_ptr)0)) && ((__37925_55_other_sym->global_sym) == ((a_pl_symbol_ptr)0))) {


(__37925_55_other_sym->global_sym) = __37937_32_sym_ptr;
}
}


if (__37927_23_p_new != ((_ZN3edg9a_booleanE *)0)) { (*__37927_23_p_new) = __37939_21_is_new; }
return __37937_32_sym_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv(void)
#line 2097
{
auto char *__38026_11_name;
auto int __38027_9_pos = 0;
auto a_pl_symbol_ptr __38028_19_sym;

for (; ; ) {
__38026_11_name = ((pl_predefined_names)[(__38027_9_pos++)]);
if (__38026_11_name == ((char *)0)) { goto __T1088725192; }
__38028_19_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__38026_11_name, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__38028_19_sym->defined) = ((_ZN3edg14a_byte_booleanE)1);
} __T1088725192:; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file( a_pl_object_file_ptr __38040_61_pofp, 
a_pl_input_file_ptr __38041_33_input_file)
#line 2123
{
auto a_pl_symbol_ptr __38052_19_psp;

__38052_19_psp = (__38040_61_pofp->symbols);
while (__38052_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __38056_21_sym;
auto _ZN3edg9a_booleanE __38057_16_is_special_symbol = ((_ZN3edg9a_booleanE)0);
if ((((int)((__38052_19_psp->name)[0])) == 95) && (((int)((__38052_19_psp->name)[1])) == 95)) {
if ((strncmp(((const char *)(__38052_19_psp->name)), ((const char *)"__TIR__"), 7ULL)) == 0)
{
#line 2141
__38057_16_is_special_symbol = ((_ZN3edg9a_booleanE)1);
__38056_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(((__38052_19_psp->name) + 7), __38052_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__38056_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
(__38056_21_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1);
} else  { if ((strncmp(((const char *)(__38052_19_psp->name)), ((const char *)"__DNI__"), 7ULL)) == 0)
{
#line 2155
__38057_16_is_special_symbol = ((_ZN3edg9a_booleanE)1);
__38056_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(((__38052_19_psp->name) + 7), __38052_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__38056_21_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1);
} else  { if ((!(__38041_33_input_file->is_archive)) && ((strncmp(((const char *)(__38052_19_psp->name)), ((const char *)"__CBI__"), 7ULL)) == 0))

{




__38057_16_is_special_symbol = ((_ZN3edg9a_booleanE)1);
__38056_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(((__38052_19_psp->name) + 7), __38052_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__38056_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
if (!(__38041_33_input_file->is_archive)) {
(__38056_21_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1);


_ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(__38056_21_sym, __38041_33_input_file);
}
} } }
}
if (!(__38057_16_is_special_symbol)) {


__38056_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb((__38052_19_psp->name), __38052_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));
if (__38052_19_psp->referenced) {
(__38056_21_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1);
}




if (__38052_19_psp->defined) {
if ((__38056_21_sym->defined) && ((__38056_21_sym->defined_in) != __38041_33_input_file)) {
(__38056_21_sym->multiple_definition) = ((_ZN3edg14a_byte_booleanE)1);
} else  {
(__38056_21_sym->defined_in) = __38041_33_input_file;
(__38056_21_sym->defined) = ((_ZN3edg14a_byte_booleanE)1);
}
}


if ((__38052_19_psp->template_sym) != ((a_pl_symbol_ptr)0)) { (__38056_21_sym->template_sym) = (__38052_19_psp->template_sym); }


if (__38052_19_psp->do_not_instantiate) { (__38056_21_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1); }
if (__38052_19_psp->is_template) { (__38056_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1); }
if ((__38052_19_psp->can_be_instantiated) || (((__38056_21_sym->template_sym) != ((a_pl_symbol_ptr)0)) && ((__38056_21_sym->template_sym)->defined)))
{
(__38056_21_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1);
#line 2212
_ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(__38056_21_sym, __38041_33_input_file);
}
(__38056_21_sym->tentative_definition) = ((_ZN3edg14a_byte_booleanE)((((int)(__38056_21_sym->tentative_definition)) | ((int)(__38052_19_psp->tentative_definition))) != 0));
}
__38052_19_psp = (__38052_19_psp->next);
}
(__38040_61_pofp->included_in_output) = ((_ZN3edg14a_byte_booleanE)1); 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file( a_pl_object_file_ptr __38150_65_pofp)




{
auto a_pl_symbol_ptr __38156_19_psp;
auto _ZN3edg9a_booleanE __38157_14_result = ((_ZN3edg9a_booleanE)0);

__38156_19_psp = (__38150_65_pofp->symbols);
while (__38156_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __38161_21_sym;
if ((__38156_19_psp->defined) || (__38156_19_psp->tentative_definition)) {

__38161_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb((__38156_19_psp->name), __38156_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));
if (!(__38161_21_sym->defined)) {



if ((__38161_21_sym->referenced) || ((__38161_21_sym->tentative_definition) && (__38156_19_psp->defined)))
{
__38157_14_result = ((_ZN3edg9a_booleanE)1);
goto __T1088803640;
}
#line 2253
(__38161_21_sym->definition_seen_in_archive) = ((_ZN3edg14a_byte_booleanE)1);
}
}
__38156_19_psp = (__38156_19_psp->next);
} __T1088803640:;
return __38157_14_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv(void)




{
auto a_pl_input_file_ptr __38196_23_pifp;

__38196_23_pifp = pl_input_files;
while (__38196_23_pifp != ((a_pl_input_file_ptr)0)) {
auto a_pl_object_file_ptr __38200_26_pofp;
auto _ZN3edg9a_booleanE __38201_17_file_used_from_archive = ((_ZN3edg9a_booleanE)0);
__38200_26_pofp = (__38196_23_pifp->objects);
if (!(__38196_23_pifp->is_archive)) {
if (__38200_26_pofp != ((a_pl_object_file_ptr)0)) {




for (; __38200_26_pofp != ((a_pl_object_file_ptr)0); __38200_26_pofp = (__38200_26_pofp->next)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(__38200_26_pofp, __38196_23_pifp);
}
}
} else  {
while (__38200_26_pofp != ((a_pl_object_file_ptr)0)) {
if (!(__38200_26_pofp->included_in_output)) {



if (_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file(__38200_26_pofp)) {



_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(__38200_26_pofp, __38196_23_pifp);
__38201_17_file_used_from_archive = ((_ZN3edg9a_booleanE)1);
}
}
__38200_26_pofp = (__38200_26_pofp->next);
}
}




if (!(__38201_17_file_used_from_archive)) { __38196_23_pifp = (__38196_23_pifp->next); }
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(void)




{
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_corrupted_template_info_file, ((char *)0)); 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc( char *__38249_35_name)




{
auto char *__38255_9_last_dot;

__38255_9_last_dot = (strrchr(((const char *)__38249_35_name), 46));
return __38255_9_last_dot;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_( _ZN3edg12a_const_charE *__38262_44_name, 
_ZN3edg12a_const_charE *__38263_23_suffix)
#line 2343
{
auto char *__38272_11_last_dot;
#line 2351
((pl_file_name_buffer)[0]) = ((char)0);
strncat(pl_file_name_buffer, __38262_44_name, 4085ULL);

__38272_11_last_dot = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc(pl_file_name_buffer));
if (__38272_11_last_dot == ((char *)0)) {

__38272_11_last_dot = ((pl_file_name_buffer) + (strlen(((const char *)pl_file_name_buffer))));
}

(*__38272_11_last_dot) = ((char)0);
strncat(__38272_11_last_dot, __38263_23_suffix, 10ULL);
return pl_file_name_buffer;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file( a_pl_input_file_ptr __38294_60_pifp)
#line 2373
{
auto _ZN3edg8sizeof_tE __38302_13_instantiation_dir_length = 0ULL;
auto _ZN3edg8sizeof_tE __38303_13_compilation_dir_length = 0ULL;
auto _ZN3edg8sizeof_tE __38304_13_instantiation_suffix_length;
auto _ZN3edg8sizeof_tE __38305_13_extra_space;
auto FILE *__38306_11_f_template_info = ((FILE *)0);
auto _ZN3edg9a_booleanE __38307_14_instantiation_dir_set = ((_ZN3edg9a_booleanE)0);
auto a_pl_object_file_ptr __38308_24_pofp;
auto a_pl_symbol_ptr __38309_19_last_primary_entry = ((a_pl_symbol_ptr)0);

if ((__38294_60_pifp->template_info_file_name) != ((char *)0)) {
__38306_11_f_template_info = (fopen(((const char *)(__38294_60_pifp->template_info_file_name)), ((const char *)"r")));
}
if (__38306_11_f_template_info != ((FILE *)0)) {


__38308_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__38308_24_pofp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__38294_60_pifp->file_name))));
__38304_13_instantiation_suffix_length = 6ULL;
while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__38306_11_f_template_info)) {
auto char *__38321_14_line_type = pl_input_line;
auto char *__38322_14_info;
auto a_pl_symbol_ptr __38323_23_sym;
#line 2394
__38322_14_info = (__38321_14_line_type + 4);


if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"flg:"), 4ULL)) == 0) {
#line 2403
auto char *__38331_15_flag_pos;
__38331_15_flag_pos = (strchr(((const char *)__38322_14_info), 58));
if (__38331_15_flag_pos == ((char *)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }

(*(__38331_15_flag_pos++)) = ((char)0);
__38323_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());
(__38323_23_sym->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38322_14_info)));
for (; (((int)(*__38331_15_flag_pos)) != 0) && (((int)(*__38331_15_flag_pos)) != 58); __38331_15_flag_pos++) {
switch ((int)(*__38331_15_flag_pos)) {
case 67:
(__38323_23_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1);
(__38323_23_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
goto __T1088870936;
case 68:
(__38323_23_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1);
goto __T1088870936;
case 84:
(__38323_23_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
(__38323_23_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1);
goto __T1088870936;
default:
_ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv();
} __T1088870936:; ;
}

if (((int)(*__38331_15_flag_pos)) == 58) {
auto char *__38357_17_name_pos; __38357_17_name_pos = (__38331_15_flag_pos + 1);
(__38323_23_sym->template_sym) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__38357_17_name_pos, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

}
(__38323_23_sym->next) = (__38308_24_pofp->symbols);
(__38308_24_pofp->symbols) = __38323_23_sym;


__38309_19_last_primary_entry = __38323_23_sym;
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"ent:"), 4ULL)) == 0) {


auto char *__38369_15_name_pos;
auto a_pl_symbol_ptr __38370_25_global_for_last_primary;
#line 2441
__38369_15_name_pos = (__38321_14_line_type + 4);

if (__38309_19_last_primary_entry == ((a_pl_symbol_ptr)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__38323_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__38369_15_name_pos, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

__38370_25_global_for_last_primary = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb((__38309_19_last_primary_entry->name), __38309_19_last_primary_entry, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));



(__38323_23_sym->primary_entry) = __38370_25_global_for_last_primary;
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"tnm:"), 4ULL)) == 0) {

auto char *__38381_15_name_pos; __38381_15_name_pos = (__38321_14_line_type + 4);
__38323_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__38381_15_name_pos, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__38323_23_sym->defined) = ((_ZN3edg14a_byte_booleanE)1);
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"ifn:"), 4ULL)) == 0) {
#line 2463
auto a_pl_object_file_ptr __38391_30_i_pofp;
auto _ZN3edg9a_booleanE __38392_20_add_compilation_dir = ((_ZN3edg9a_booleanE)0);
#line 2481
auto size_t __38409_16_file_name_size;
#line 2465
__38305_13_extra_space = 3ULL;
if (!(__38307_14_instantiation_dir_set)) {


(__38294_60_pifp->instantiation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((const char *)"Template.dir")));
__38302_13_instantiation_dir_length = (strlen(((const char *)(__38294_60_pifp->instantiation_directory))));
__38307_14_instantiation_dir_set = ((_ZN3edg9a_booleanE)1);
}
if ((!(__38294_60_pifp->is_local_file)) && (!(_ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc((__38294_60_pifp->instantiation_directory)))))
{



__38392_20_add_compilation_dir = ((_ZN3edg9a_booleanE)1);
}
__38391_30_i_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
__38409_16_file_name_size = (((((strlen(((const char *)__38322_14_info))) + __38302_13_instantiation_dir_length) + __38304_13_instantiation_suffix_length) + ((__38392_20_add_compilation_dir) ? __38303_13_compilation_dir_length : 0ULL)) + __38305_13_extra_space);
#line 2487
(__38391_30_i_pofp->file_name) = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(__38409_16_file_name_size)));

snprintf((__38391_30_i_pofp->file_name), __38409_16_file_name_size, ((const char *)"%s%s%s/%s%s"), ((__38392_20_add_compilation_dir) ? ((const char *)(__38294_60_pifp->compilation_directory)) : ((const char *)"")), ((__38392_20_add_compilation_dir) ? ((const char *)("/")) : ((const char *)(""))), (
#line 2489
__38294_60_pifp->instantiation_directory), __38322_14_info, ((const char *)(".int.o")));




(__38391_30_i_pofp->next) = (__38294_60_pifp->objects);
(__38391_30_i_pofp->is_related_file) = ((_ZN3edg14a_byte_booleanE)1);
(__38294_60_pifp->objects) = __38391_30_i_pofp;
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"dep:"), 4ULL)) == 0) {


auto a_pl_file_list_entry_ptr __38428_34_flep;
__38428_34_flep = (_ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv());
(__38428_34_flep->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38322_14_info)));
(__38428_34_flep->next) = (__38294_60_pifp->dependencies);
(__38294_60_pifp->dependencies) = __38428_34_flep;
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"cmd:"), 4ULL)) == 0) {

(__38294_60_pifp->command_line) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38322_14_info)));
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"dir:"), 4ULL)) == 0) {

(__38294_60_pifp->compilation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38322_14_info)));

(__38294_60_pifp->is_local_file) = ((_Bool)((strcmp(((const char *)(__38294_60_pifp->compilation_directory)), ((const char *)curr_dir_name))) == 0));

__38303_13_compilation_dir_length = (strlen(((const char *)(__38294_60_pifp->compilation_directory))));
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"fnm:"), 4ULL)) == 0) {

(__38294_60_pifp->compilation_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38322_14_info)));
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"stu:"), 4ULL)) == 0) {


(__38294_60_pifp->secondary_files) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38322_14_info)));
} else  { if ((strncmp(((const char *)__38321_14_line_type), ((const char *)"idn:"), 4ULL)) == 0) {


if (__38307_14_instantiation_dir_set) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"instantiation_dir already set"));
}
(__38294_60_pifp->instantiation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38322_14_info)));
__38302_13_instantiation_dir_length = (strlen(((const char *)(__38294_60_pifp->instantiation_directory))));
__38307_14_instantiation_dir_set = ((_ZN3edg9a_booleanE)1);
} else  {
_ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv();
} } } } } } } } } }
}
fclose(__38306_11_f_template_info);


(__38308_24_pofp->next) = (__38294_60_pifp->objects);
(__38294_60_pifp->objects) = __38308_24_pofp;
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(
a_pl_input_file_ptr __38473_26_pifp, 
FILE *__38474_14_f_request)



{
auto int __38479_7_i;

for (__38479_7_i = 0; __38479_7_i < reserved_request_file_lines; ++__38479_7_i) {
_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__38474_14_f_request);
(((__38473_26_pifp->reserved_lines))[__38479_7_i]) = ((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_input_line))));
}



if (reserved_request_file_lines >= 1) {
(__38473_26_pifp->command_line) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc((((__38473_26_pifp->reserved_lines))[0])));
}
if (!(use_template_info_file)) {
#line 2579
}



for (; __38479_7_i < 0; ++__38479_7_i) {
(((__38473_26_pifp->reserved_lines))[__38479_7_i]) = ((const char *)"");
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv(void)




{
auto a_pl_input_file_ptr __38523_23_pifp;
auto FILE *__38524_11_f_request;

__38523_23_pifp = pl_input_files;
while (__38523_23_pifp != ((a_pl_input_file_ptr)0)) {
if ((!(__38523_23_pifp->is_archive)) && ((__38523_23_pifp->request_file_name) != ((char *)0))) {
__38524_11_f_request = (fopen(((const char *)(__38523_23_pifp->request_file_name)), ((const char *)"r")));
#line 2608
if (__38524_11_f_request != ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(__38523_23_pifp, __38524_11_f_request);

while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__38524_11_f_request)) {
auto a_pl_symbol_ptr __38540_27_sym;
__38540_27_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(pl_input_line, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

if ((__38540_27_sym->instantiation_file) != ((a_pl_input_file_ptr)0)) {


fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_error)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_multiple_assignments)), (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__38540_27_sym->name))), (__38523_23_pifp->file_name), ((__38540_27_sym->instantiation_file)->file_name));


_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_bad_instantiation_request_file, ((char *)0));
}
(__38540_27_sym->instantiation_file) = __38523_23_pifp;


(__38540_27_sym->next_in_request_file) = (__38523_23_pifp->request_list);
(__38523_23_pifp->request_list) = __38540_27_sym;
}
fclose(__38524_11_f_request);
}
}
__38523_23_pifp = (__38523_23_pifp->next);
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(
a_pl_input_file_ptr __38567_24_pifp, 
char **__38568_13_request_file_name, 
char **__38569_13_template_info_file_name)




{
auto char *__38575_11_suffix;

(*__38568_13_request_file_name) = ((char *)0);
(*__38569_13_template_info_file_name) = ((char *)0);
__38575_11_suffix = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc((__38567_24_pifp->file_name)));
if ((__38575_11_suffix != ((char *)0)) && ((strcmp(((const char *)__38575_11_suffix), ((const char *)".o"))) == 0)) {


(*__38568_13_request_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(((_ZN3edg12a_const_charE *)(__38567_24_pifp->file_name)), ((const char *)".ii"))))));

if ((use_template_info_file) && ((*__38568_13_request_file_name) != ((char *)0))) {
(*__38569_13_template_info_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(((_ZN3edg12a_const_charE *)(__38567_24_pifp->file_name)), ((const char *)".ti"))))));

}
} 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file( a_pl_input_file_ptr __38593_65_pifp)




{
auto FILE *__38599_11_f_test = ((FILE *)0);
auto char *__38600_11_request_file_name;
auto char *__38601_11_template_info_file_name;
auto char *__38602_11_file_to_test;


_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(__38593_65_pifp, (&__38600_11_request_file_name), (&__38601_11_template_info_file_name));



if (__38600_11_request_file_name != ((char *)0)) {


__38602_11_file_to_test = ((use_template_info_file) ? __38601_11_template_info_file_name : __38600_11_request_file_name);

__38599_11_f_test = (fopen(((const char *)__38602_11_file_to_test), ((const char *)"r")));
if (__38599_11_f_test != ((FILE *)0)) {
fclose(__38599_11_f_test);
(__38593_65_pifp->request_file_name) = __38600_11_request_file_name;
(__38593_65_pifp->template_info_file_name) = __38601_11_template_info_file_name;
} else  {
free(((void *)__38600_11_request_file_name));
if (use_template_info_file) { free(((void *)__38601_11_template_info_file_name)); }
}
}
return (_Bool)(__38599_11_f_test != ((FILE *)0));
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol( a_pl_input_file_ptr __38628_57_pifp, 
a_pl_symbol_ptr __38629_22_psp)




{
auto a_pl_instantiation_site_ptr __38635_31_pisp;
auto _ZN3edg9a_booleanE __38636_15_result = ((_ZN3edg9a_booleanE)0);

__38635_31_pisp = (__38629_22_psp->possible_instantiation_sites);
while (__38635_31_pisp != ((a_pl_instantiation_site_ptr)0)) {
if ((__38635_31_pisp->input_file) == __38628_57_pifp) {
__38636_15_result = ((_ZN3edg9a_booleanE)1);
goto __T1089019232;
}
__38635_31_pisp = (__38635_31_pisp->next);
} __T1089019232:;
return __38636_15_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc( char *__38650_37_name)
#line 2730
{
auto a_pl_assignment_ptr __38659_23_ap;

__38659_23_ap = (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc(__38650_37_name));




if ((__38659_23_ap->times_assigned) > 3) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"instantiation loop"));
}
(__38659_23_ap->times_assigned)++; 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file( a_pl_input_file_ptr __38673_60_pifp)
#line 2751
{
auto _ZN3edg9a_booleanE __38680_15_result = ((_ZN3edg9a_booleanE)0);
auto a_pl_object_file_ptr __38681_25_pofp;
auto a_pl_file_list_entry_ptr __38682_28_flep;
#line 2753
__38681_25_pofp = (__38673_60_pifp->objects);



if (__38681_25_pofp == ((a_pl_object_file_ptr)0)) {
goto __38711_1_done;
} else  { if ((__38681_25_pofp->modification_time) == 0LL) {


if (!(_ZN3edg26get_file_modification_timeEPKcPx(((_ZN3edg12a_const_charE *)(__38681_25_pofp->file_name)), (&(__38681_25_pofp->modification_time)))))
{


goto __38711_1_done;
}
} }
for (__38682_28_flep = (__38673_60_pifp->dependencies); __38682_28_flep != ((a_pl_file_list_entry_ptr)0); __38682_28_flep = (__38682_28_flep->next)) {
auto time_t __38698_12_dep_time;
if (_ZN3edg26get_file_modification_timeEPKcPx(((_ZN3edg12a_const_charE *)(__38682_28_flep->name)), (&__38698_12_dep_time))) {
if (__38698_12_dep_time > (__38681_25_pofp->modification_time)) {

__38680_15_result = ((_ZN3edg9a_booleanE)1);
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_out_of_date)), message_prefix, (__38673_60_pifp->file_name), (__38682_28_flep->name));

}
goto __T1089039944;
}
}
} __T1089039944:;
__38711_1_done:;
return __38680_15_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEb( _ZN3edg9a_booleanE __38716_49_do_local_files)
#line 2799
{
auto a_pl_input_file_ptr __38728_23_pifp;
auto _ZN3edg9a_booleanE __38729_14_done = ((_ZN3edg9a_booleanE)1);

for (__38728_23_pifp = pl_input_files; __38728_23_pifp != ((a_pl_input_file_ptr)0); __38728_23_pifp = (__38728_23_pifp->next)) { {

if (((int)(__38728_23_pifp->is_local_file)) != ((int)__38716_49_do_local_files)) { goto __T1089046536; }

if ((__38728_23_pifp->objects) == ((a_pl_object_file_ptr)0)) { goto __T1089046536; }
if (!(__38728_23_pifp->is_archive)) {
auto a_pl_symbol_ptr __38737_23_psp;
auto a_pl_symbol_ptr __38738_23_prev_psp;


if ((((__38728_23_pifp->dependencies) != ((a_pl_file_list_entry_ptr)0)) && (!(suppress_dependency_checking))) && (_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file(__38728_23_pifp)))

{


(__38728_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1);
(__38728_23_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)1);
__38729_14_done = ((_ZN3edg9a_booleanE)0);
}


__38737_23_psp = (__38728_23_pifp->request_list);
__38738_23_prev_psp = ((a_pl_symbol_ptr)0);
while (__38737_23_psp != ((a_pl_symbol_ptr)0)) {
auto _ZN3edg9a_booleanE __38755_20_remove_from_request_file = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __38756_20_recompile_file = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __38757_20_remove_one_inst_per_obj_file = ((_ZN3edg9a_booleanE)0);
if ((__38737_23_psp->multiple_definition) || (__38737_23_psp->do_not_instantiate)) {
#line 2837
__38755_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);
__38756_20_recompile_file = ((_ZN3edg9a_booleanE)1);
} else  { if (((__38737_23_psp->defined_in) == ((a_pl_input_file_ptr)0)) || ((__38737_23_psp->defined_in) != __38728_23_pifp))
{
#line 2849
__38755_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);


__38757_20_remove_one_inst_per_obj_file = ((_Bool)((__38737_23_psp->defined_in) == ((a_pl_input_file_ptr)0)));
__38756_20_recompile_file = ((_ZN3edg9a_booleanE)1);
} else  { if (!(__38737_23_psp->is_template)) {


__38755_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);
__38756_20_recompile_file = ((_ZN3edg9a_booleanE)1);
} else  { if (!(__38737_23_psp->referenced)) {
#line 2866
__38755_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);
__38756_20_recompile_file = ((_ZN3edg9a_booleanE)1);
__38757_20_remove_one_inst_per_obj_file = ((_ZN3edg9a_booleanE)1);
} else  {

(__38737_23_psp->instantiated) = ((_ZN3edg14a_byte_booleanE)1);
} } } }
if (__38755_20_remove_from_request_file) {
#line 2880
if (__38738_23_prev_psp != ((a_pl_symbol_ptr)0)) {
(__38738_23_prev_psp->next_in_request_file) = (__38737_23_psp->next_in_request_file);
} else  {
(__38728_23_pifp->request_list) = (__38737_23_psp->next_in_request_file);
}
(__38737_23_psp->instantiation_file) = ((a_pl_input_file_ptr)0);
(__38728_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1);
(__38728_23_pifp->recompile) = __38756_20_recompile_file;
__38729_14_done = ((_ZN3edg9a_booleanE)0);




if ((one_instantiation_per_object) && (__38757_20_remove_one_inst_per_obj_file))
{



snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"%s/%s%s"), (__38728_23_pifp->instantiation_directory), (_ZN3edg39generate_instantiation_output_file_nameEPKc(((_ZN3edg12a_const_charE *)(__38737_23_psp->name)))), ((const char *)(".int.o")));




unlink(((const char *)pl_file_name_buffer));
}

if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_no_longer_needed)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__38737_23_psp->name))), (__38728_23_pifp->file_name));


}
}


if (!(__38755_20_remove_from_request_file)) { __38738_23_prev_psp = __38737_23_psp; }
__38737_23_psp = (__38737_23_psp->next_in_request_file);
}



__38737_23_psp = ((__38728_23_pifp->objects)->symbols);
while (__38737_23_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __38850_25_sym; __38850_25_sym = (__38737_23_psp->global_sym);
#line 2932
if (((((((((__38850_25_sym != ((a_pl_symbol_ptr)0)) && (__38850_25_sym->is_template)) && (!(__38850_25_sym->instantiated))) && (!(__38850_25_sym->do_not_instantiate))) && (__38850_25_sym->can_be_instantiated)) && ((__38850_25_sym->referenced) || (__38850_25_sym->tentative_definition))) && (!(
#line 2932
__38850_25_sym->defined))) && (!(__38850_25_sym->definition_seen_in_archive))) && (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol(__38728_23_pifp, __38850_25_sym)))




{




(__38850_25_sym->next_in_request_file) = (__38728_23_pifp->request_list);
(__38728_23_pifp->request_list) = __38850_25_sym;
(__38850_25_sym->instantiated) = ((_ZN3edg14a_byte_booleanE)1);
(__38728_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1);
(__38728_23_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)1);
__38729_14_done = ((_ZN3edg9a_booleanE)0);


_ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc((__38850_25_sym->name));
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_assigned_to_file)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__38850_25_sym->name))), (__38728_23_pifp->file_name));


}
}
__38737_23_psp = (__38737_23_psp->next);
}
}



if ((__38728_23_pifp->recompile) && (use_definition_list)) { goto __T1089114992; }
} __T1089046536:; } __T1089114992:;
return __38729_14_done;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc( char *__38897_39_new_dir)


{
#line 2978
if ((chdir(((const char *)__38897_39_new_dir))) != 0) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_chdir, __38897_39_new_dir);
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc( char **__38912_48_dest, 
_ZN3edg12a_const_charE *__38913_19_source)
#line 2992
{
auto _ZN3edg12a_const_charE *__38921_17_from;
auto char *__38922_10_to;
auto _ZN3edg9a_booleanE __38923_13_in_quote = ((_ZN3edg9a_booleanE)0);
auto char __38924_9_quote_char = ((char)0);
auto _ZN3edg9a_booleanE __38925_13_is_escaped = ((_ZN3edg9a_booleanE)0);
auto char __38926_9_outer_quote = ((char)0);
#line 2994
__38922_10_to = (*__38912_48_dest);
#line 3000
for (__38921_17_from = __38913_19_source; ((int)(*__38921_17_from)) != 0; ++__38921_17_from) {
auto char __38929_10_ch;
auto _ZN3edg9a_booleanE __38930_15_is_close_quote = ((_ZN3edg9a_booleanE)0);
#line 3001
__38929_10_ch = (*__38921_17_from);

if (__38925_13_is_escaped) {
__38925_13_is_escaped = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)__38929_10_ch) == 92) {
__38925_13_is_escaped = ((_ZN3edg9a_booleanE)1);
} else  { if ((!(__38923_13_in_quote)) && ((((int)__38929_10_ch) == 34) || (((int)__38929_10_ch) == 39))) {
__38923_13_in_quote = ((_ZN3edg9a_booleanE)1);
__38924_9_quote_char = __38929_10_ch;
__38926_9_outer_quote = ((((int)__38929_10_ch) == 34) ? ((char)39) : ((char)34));
(*(__38922_10_to++)) = __38926_9_outer_quote;
} else  { if ((__38923_13_in_quote) && (((int)__38929_10_ch) == ((int)__38924_9_quote_char))) {
__38930_15_is_close_quote = ((_ZN3edg9a_booleanE)1);
} else  { if (((__38923_13_in_quote) && (((int)__38929_10_ch) == ((int)__38924_9_quote_char))) || ((!(__38923_13_in_quote)) && ((((int)__38929_10_ch) == 40) || (((int)__38929_10_ch) == 41))))
{
(*(__38922_10_to++)) = ((char)92);
} } } } }
(*(__38922_10_to++)) = __38929_10_ch;
if (__38930_15_is_close_quote) {
__38923_13_in_quote = ((_ZN3edg9a_booleanE)0);
(*(__38922_10_to++)) = __38926_9_outer_quote;
}
}

if (((int)(*(__38922_10_to - 1))) != 32) { (*(__38922_10_to++)) = ((char)32); }
(*__38912_48_dest) = __38922_10_to; 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_( _ZN3edg12a_const_charE *__38958_47_part1, 
_ZN3edg12a_const_charE *__38959_47_part2, 
_ZN3edg12a_const_charE *__38960_47_part3, 
_ZN3edg12a_const_charE *__38961_19_part4)
#line 3040
{
auto char *__38969_10_to;
auto _ZN3edg8sizeof_tE __38970_12_length;
auto char *__38971_10_command;



if (__38959_47_part2 == ((_ZN3edg12a_const_charE *)0)) { __38959_47_part2 = ((const char *)""); }
if (__38960_47_part3 == ((_ZN3edg12a_const_charE *)0)) { __38960_47_part3 = ((const char *)""); }
if (__38961_19_part4 == ((_ZN3edg12a_const_charE *)0)) { __38961_19_part4 = ((const char *)""); }
if (__38958_47_part1 == ((_ZN3edg12a_const_charE *)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__38970_12_length = (((((strlen(__38958_47_part1)) + (strlen(__38959_47_part2))) + (strlen(__38960_47_part3))) + (strlen(__38961_19_part4))) * 2ULL);
if (__38970_12_length <= 3ULL) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__38971_10_command = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(__38970_12_length)));
__38969_10_to = __38971_10_command;
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38969_10_to), __38958_47_part1);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38969_10_to), __38959_47_part2);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38969_10_to), __38960_47_part3);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38969_10_to), __38961_19_part4);

(*(__38969_10_to - 1)) = ((char)0);
return __38971_10_command;
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_( a_pl_input_file_ptr __38993_50_pifp, 
_ZN3edg12a_const_charE *__38994_45_extra_command_args, 
_ZN3edg12a_const_charE *__38995_24_extra_args_for_display)
#line 3074
{
auto char *__39003_10_command;
auto char *__39004_10_display_command;
auto int __39005_8_result;
auto _ZN3edg9a_booleanE __39006_13_chdir_needed;




__39006_13_chdir_needed = ((_Bool)(((__38993_50_pifp->compilation_directory) != ((char *)0)) && ((strcmp(((const char *)(__38993_50_pifp->compilation_directory)), ((const char *)curr_dir_name))) != 0)));

if (__39006_13_chdir_needed) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc((__38993_50_pifp->compilation_directory));
}
__39003_10_command = (_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(((_ZN3edg12a_const_charE *)(__38993_50_pifp->command_line)), __38994_45_extra_command_args, ((_ZN3edg12a_const_charE *)(__38993_50_pifp->compilation_file_name)), ((_ZN3edg12a_const_charE *)(
#line 3089
__38993_50_pifp->secondary_files))));


if (__38995_24_extra_args_for_display != ((_ZN3edg12a_const_charE *)0)) {



__39004_10_display_command = (_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(((_ZN3edg12a_const_charE *)(__38993_50_pifp->command_line)), __38995_24_extra_args_for_display, ((_ZN3edg12a_const_charE *)(__38993_50_pifp->compilation_file_name)), ((_ZN3edg12a_const_charE *)(
#line 3096
__38993_50_pifp->secondary_files))));



} else  {
__39004_10_display_command = __39003_10_command;
}
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_executing)), message_prefix, __39004_10_display_command);

fflush(f_informational);
__39005_8_result = (system(((const char *)__39003_10_command)));



if (__39005_8_result == (-1)) {
__39005_8_result = (*_errnoloc);
} else  {
__39005_8_result = (__39005_8_result >> 8);
}
if (__39004_10_display_command != __39003_10_command) { free(((void *)__39004_10_display_command)); }
free(((void *)__39003_10_command));
if (__39006_13_chdir_needed) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc(curr_dir_name);
}
return __39005_8_result;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc( char *__39053_39_file_name)




{
auto char *__39059_9_ptr;

__39059_9_ptr = (strrchr(((const char *)__39053_39_file_name), 47));
#line 3144
return __39059_9_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file( a_pl_input_file_ptr __39076_63_pifp)
#line 3158
{
auto char *__39087_10_orig_file_name;
auto char *__39088_10_orig_request_file_name;
auto char *__39089_10_orig_template_info_file_name;
auto char *__39090_10_ptr;


__39087_10_orig_file_name = (__39076_63_pifp->file_name);
__39090_10_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc((__39076_63_pifp->file_name)));
if (__39090_10_ptr == ((char *)0)) {
fprintf(stderr, ((const char *)"Expected %s to include a directory name\n"), (__39076_63_pifp->file_name));

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Directory name missing"));
}
if ((__39076_63_pifp->secondary_files) != ((char *)0)) {


_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"copy if nonlocal cannot be used with secondary trans units"));

}
(__39076_63_pifp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__39090_10_ptr + 1))));
__39088_10_orig_request_file_name = (__39076_63_pifp->request_file_name);
__39089_10_orig_template_info_file_name = (__39076_63_pifp->template_info_file_name);




_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(__39076_63_pifp, (&(__39076_63_pifp->request_file_name)), (&(__39076_63_pifp->template_info_file_name)));




if (_ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc((__39076_63_pifp->compilation_file_name))) {

} else  {


snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"%s/%s"), (__39076_63_pifp->compilation_directory), (__39076_63_pifp->compilation_file_name));

free(((void *)(__39076_63_pifp->compilation_file_name)));
(__39076_63_pifp->compilation_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}

free(((void *)(__39076_63_pifp->compilation_directory)));
(__39076_63_pifp->compilation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)curr_dir_name)));
#line 3215
free(((void *)__39087_10_orig_file_name));
free(((void *)__39088_10_orig_request_file_name));
if (__39089_10_orig_template_info_file_name != ((char *)0)) { free(((void *)__39089_10_orig_template_info_file_name)); }
if (!(use_template_info_file)) {


(((__39076_63_pifp->reserved_lines))[0]) = ((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__39076_63_pifp->command_line)))));
#line 3228
}

(__39076_63_pifp->is_local_file) = ((_ZN3edg14a_byte_booleanE)1); 
}


static FILE *_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv(void)
#line 3240
{
auto FILE *__39169_10_f_temp;
auto _ZN3edg12a_const_charE *__39170_17_tmpdir;

if (temporary_file_name == ((char *)0)) {

__39170_17_tmpdir = ((_ZN3edg12a_const_charE *)(getenv(((const char *)"TMPDIR"))));
if (__39170_17_tmpdir == ((_ZN3edg12a_const_charE *)0)) {



__39170_17_tmpdir = ((const char *)"/tmp");

}
snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"%s/%0dpltf"), __39170_17_tmpdir, (getpid()));

temporary_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}
__39169_10_f_temp = (fopen(((const char *)temporary_file_name), ((const char *)"w")));
if (__39169_10_f_temp == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_temporary_file, temporary_file_name);
}
return __39169_10_f_temp;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv(void)
#line 3274
{

auto FILE *__39204_11_f_temp;
auto a_pl_input_file_ptr __39205_23_pifp;
auto a_pl_object_file_ptr __39206_24_pofp;
auto a_pl_symbol_ptr __39207_19_psp;

__39204_11_f_temp = (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv());
for (__39205_23_pifp = pl_input_files; __39205_23_pifp != ((a_pl_input_file_ptr)0); __39205_23_pifp = (__39205_23_pifp->next)) {
for (__39206_24_pofp = (__39205_23_pifp->objects); __39206_24_pofp != ((a_pl_object_file_ptr)0); __39206_24_pofp = (__39206_24_pofp->next)) {
for (__39207_19_psp = (__39206_24_pofp->symbols); __39207_19_psp != ((a_pl_symbol_ptr)0); __39207_19_psp = (__39207_19_psp->next)) {
if (__39207_19_psp->defined) {
fputs(((const char *)(__39207_19_psp->name)), __39204_11_f_temp);
fputs(((const char *)"\n"), __39204_11_f_temp);
}
}
}
}
fclose(__39204_11_f_temp);
if (_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option == ((char *)0)) {



snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"--definition_list_file=%s"), temporary_file_name);

_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}
return _ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file( a_pl_input_file_ptr __39233_69_pifp)
#line 3311
{
auto FILE *__39240_9_f_request;
auto FILE *__39241_9_f_temp;

__39241_9_f_temp = (fopen(((const char *)temporary_file_name), ((const char *)"r")));
if (__39241_9_f_temp != ((FILE *)0)) {




if ((_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__39241_9_f_temp)) && ((strcmp(((const char *)pl_input_line), ((const char *)":add:"))) == 0)) {

__39240_9_f_request = (fopen(((const char *)(__39233_69_pifp->request_file_name)), ((const char *)"a")));
if (__39240_9_f_request == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_file_for_update, (__39233_69_pifp->request_file_name));
}
while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__39241_9_f_temp)) {
fputs(((const char *)pl_input_line), __39240_9_f_request);
fputs(((const char *)"\n"), __39240_9_f_request);


_ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc(pl_input_line);
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_adopted_by_file)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(pl_input_line)), (__39233_69_pifp->file_name));


}
}
fclose(__39240_9_f_request);
}
fclose(__39241_9_f_temp);
} 
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv(void)




{

auto a_pl_input_file_ptr __39281_24_pifp;
auto int __39282_10_return_status = 0;
auto int __39283_10_i;

__39281_24_pifp = pl_input_files;
while (__39281_24_pifp != ((a_pl_input_file_ptr)0)) {
if (__39281_24_pifp->request_file_updated) {
auto a_pl_symbol_ptr __39288_23_psp;
auto FILE *__39289_14_f_request;

if ((__39281_24_pifp->request_file_name) == ((char *)0)) {
fprintf(stderr, ((const char *)"Input file %s has instantiations but no instantiation request file.\n"), (__39281_24_pifp->file_name));


_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Instantiation request file is missing"));
}
if ((move_nonlocal_objects_to_curr_dir) && (!(__39281_24_pifp->is_local_file))) {



_ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file(__39281_24_pifp);
}

__39289_14_f_request = (fopen(((const char *)(__39281_24_pifp->request_file_name)), ((const char *)"w")));
if (__39289_14_f_request == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_file_for_update, (__39281_24_pifp->request_file_name));
}

for (__39283_10_i = 0; __39283_10_i < reserved_request_file_lines; ++__39283_10_i) {
fprintf(__39289_14_f_request, ((const char *)"%s\n"), (((__39281_24_pifp->reserved_lines))[__39283_10_i]));
}

__39288_23_psp = (__39281_24_pifp->request_list);
while (__39288_23_psp != ((a_pl_symbol_ptr)0)) {
fprintf(__39289_14_f_request, ((const char *)"%s\n"), (__39288_23_psp->name));
__39288_23_psp = (__39288_23_psp->next_in_request_file);
}
fclose(__39289_14_f_request);
if ((!(suppress_compilation)) && (__39281_24_pifp->recompile)) {
auto char *__39320_23_definition_list_option = ((char *)0);
auto _ZN3edg12a_const_charE *__39321_23_def_list_display_option = ((_ZN3edg12a_const_charE *)0);

unlink(((const char *)(__39281_24_pifp->file_name)));

if (use_definition_list) {
__39320_23_definition_list_option = (_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv());
__39321_23_def_list_display_option = ((const char *)"");
#line 3405
}
__39282_10_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(__39281_24_pifp, ((_ZN3edg12a_const_charE *)__39320_23_definition_list_option), __39321_23_def_list_display_option));

if (use_definition_list) {
if (__39282_10_return_status == 0) {


_ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file(__39281_24_pifp);
}

unlink(((const char *)temporary_file_name));
}

if (__39282_10_return_status != 0) { goto __T1089371224; }
}
}
__39281_24_pifp = (__39281_24_pifp->next);
} __T1089371224:;
return __39282_10_return_status;
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv(void)




{

auto a_pl_input_file_ptr __39362_24_pifp;
auto int __39363_10_return_status = 0;
auto int __39364_10_max_return_status = 0;

__39362_24_pifp = pl_input_files;
while (__39362_24_pifp != ((a_pl_input_file_ptr)0)) {


if (((!(__39362_24_pifp->is_archive)) && ((__39362_24_pifp->request_file_name) != ((char *)0))) && (__39362_24_pifp->is_local_file))
{



unlink(((const char *)(__39362_24_pifp->file_name)));

__39363_10_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(__39362_24_pifp, ((const char *)"--suppress_instantiation_flags"), ((_ZN3edg12a_const_charE *)0)));


if (__39363_10_return_status > __39364_10_max_return_status) { __39364_10_max_return_status = __39363_10_return_status; }
}
__39362_24_pifp = (__39362_24_pifp->next);
}
return __39364_10_max_return_status;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv(void)
#line 3466
{
auto a_pl_symbol_ptr __39395_19_psp;
auto _ZN3edg9a_booleanE __39396_14_any_errors = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __39397_14_is_new;

for (__39395_19_psp = specialization_list; __39395_19_psp != ((a_pl_symbol_ptr)0); __39395_19_psp = (__39395_19_psp->next_in_specialization_list))
{
auto a_pl_symbol_ptr __39401_21_nonspec_psp;
auto char *__39402_12_nonspec_name;


__39402_12_nonspec_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc((__39395_19_psp->name)));

__39401_21_nonspec_psp = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__39402_12_nonspec_name, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), (&__39397_14_is_new)));
#line 3487
if ((__39401_21_nonspec_psp != ((a_pl_symbol_ptr)0)) && ((__39401_21_nonspec_psp->referenced) || (__39401_21_nonspec_psp->defined)))
{
_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePcb(pl_ec_specialized_and_instantiated, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(__39402_12_nonspec_name)), ((_ZN3edg9a_booleanE)0));


__39396_14_any_errors = ((_ZN3edg9a_booleanE)1);
} else  {




(__39401_21_nonspec_psp->referenced) = ((_ZN3edg14a_byte_booleanE)((((int)(__39401_21_nonspec_psp->referenced)) | ((int)(__39395_19_psp->referenced))) != 0));
(__39401_21_nonspec_psp->defined) = ((_ZN3edg14a_byte_booleanE)((((int)(__39401_21_nonspec_psp->defined)) | ((int)(__39395_19_psp->defined))) != 0));
}
}
return __39396_14_any_errors;
}
#line 3600
static void _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(void)



{
auto a_pl_input_file_ptr __39533_23_pifp;
auto a_pl_symbol_ptr __39534_19_psp;

__39533_23_pifp = pl_input_files;
while (__39533_23_pifp != ((a_pl_input_file_ptr)0)) {
auto a_pl_object_file_ptr __39538_26_pofp;
auto a_pl_object_file_ptr __39539_26_last_pofp;
__39538_26_pofp = (__39533_23_pifp->objects);
while (__39538_26_pofp != ((a_pl_object_file_ptr)0)) {
auto a_pl_symbol_ptr __39542_23_last_psp;
__39534_19_psp = (__39538_26_pofp->symbols);
while (__39534_19_psp != ((a_pl_symbol_ptr)0)) {
__39542_23_last_psp = __39534_19_psp;
__39534_19_psp = (__39534_19_psp->next);
free(((void *)(__39542_23_last_psp->name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(__39542_23_last_psp);
}
__39539_26_last_pofp = __39538_26_pofp;
__39538_26_pofp = (__39538_26_pofp->next);
free(((void *)(__39539_26_last_pofp->file_name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file(__39539_26_last_pofp);
}

{ auto a_pl_file_list_entry_ptr __39556_32_flep;
auto a_pl_file_list_entry_ptr __39557_32_next_flep;
for (__39556_32_flep = (__39533_23_pifp->dependencies); __39556_32_flep != ((a_pl_file_list_entry_ptr)0); __39556_32_flep = __39557_32_next_flep) {
__39557_32_next_flep = (__39556_32_flep->next);
free(((void *)__39556_32_flep));
}
}



if ((__39533_23_pifp->command_line) != ((char *)0)) { free(((void *)(__39533_23_pifp->command_line))); }
if ((__39533_23_pifp->compilation_directory) != ((char *)0)) { free(((void *)(__39533_23_pifp->compilation_directory))); }
if ((__39533_23_pifp->compilation_file_name) != ((char *)0)) { free(((void *)(__39533_23_pifp->compilation_file_name))); }
if ((__39533_23_pifp->secondary_files) != ((char *)0)) { free(((void *)(__39533_23_pifp->secondary_files))); }
if ((__39533_23_pifp->instantiation_directory) != ((char *)0)) {
free(((void *)(__39533_23_pifp->instantiation_directory)));
}
__39533_23_pifp = (__39533_23_pifp->next);
}

__39534_19_psp = pl_symbol_table_head;
while (__39534_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __39578_29_last_psp;
auto a_pl_instantiation_site_ptr __39579_33_pisp;
__39579_33_pisp = (__39534_19_psp->possible_instantiation_sites);
while (__39579_33_pisp != ((a_pl_instantiation_site_ptr)0)) {
auto a_pl_instantiation_site_ptr __39582_35_last_pisp;
__39582_35_last_pisp = __39579_33_pisp;
__39579_33_pisp = (__39579_33_pisp->next);
_ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site(__39582_35_last_pisp);
}
__39578_29_last_psp = __39534_19_psp;
__39534_19_psp = (__39534_19_psp->next_in_symbol_table);
free(((void *)(__39578_29_last_psp->name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(__39578_29_last_psp);
} 
}
#line 3685
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv(void)




{
pos_in_temp_string = 0ULL; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc( _ZN3edg12a_const_charE *__39623_49_addition)



{
auto int __39628_7_addition_length;

__39628_7_addition_length = ((int)(strlen(__39623_49_addition)));
if ((pos_in_temp_string + ((unsigned long long)__39628_7_addition_length)) >= temp_string_length) {
temp_string_length += 4000ULL;
temp_string = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvy(((_ZN3edg10a_void_ptrE)temp_string), temp_string_length)));

}
strcpy((temp_string + pos_in_temp_string), __39623_49_addition);
pos_in_temp_string += ((unsigned long long)__39628_7_addition_length); 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_( _ZN3edg12a_const_charE *__39641_53_add1, 
_ZN3edg12a_const_charE *__39642_25_add2)




{
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(__39641_53_add1);
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(__39642_25_add2); 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc( char *__39653_41_lib_name)
#line 3734
{


auto char *__39665_17_string_buffer = pl_input_line;
auto _ZN3edg9a_booleanE __39666_13_found = ((_ZN3edg9a_booleanE)0);
auto char *__39667_18_result = ((char *)0);
auto int __39668_8_j;

for (__39668_8_j = 0; __39668_8_j < num_of_L_directories; ++__39668_8_j) {
auto FILE *__39671_11_f_lib;
snprintf(__39665_17_string_buffer, 32767ULL, ((const char *)"%s/lib%s.a"), (L_directories[__39668_8_j]), __39653_41_lib_name);
#line 3751
if ((__39671_11_f_lib = (fopen(((const char *)__39665_17_string_buffer), ((const char *)"r")))) != ((FILE *)0)) {


__39667_18_result = __39665_17_string_buffer;
__39666_13_found = ((_ZN3edg9a_booleanE)1);
fclose(__39671_11_f_lib);
goto __T1089479752;
}
} __T1089479752:;

if (!(__39666_13_found)) {
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_lib_file_not_found)), __39653_41_lib_name);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
}
return __39667_18_result;
}
#line 3777
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file( char *__39705_41_str, 
a_pl_input_file_ptr __39706_53_pifp)




{
auto a_pl_cmd_line_arg_ptr __39712_25_pclap;
__39712_25_pclap = ((a_pl_cmd_line_arg_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(24ULL)));

(__39712_25_pclap->is_string) = ((_Bool)(__39705_41_str != ((char *)0)));
(__39712_25_pclap->next) = ((a_pl_cmd_line_arg_ptr)0);
if (__39712_25_pclap->is_string) {
((__39712_25_pclap->variant).arg_string) = __39705_41_str;
} else  {
((__39712_25_pclap->variant).input_file_entry) = __39706_53_pifp;
}
if (cmd_line_head == ((a_pl_cmd_line_arg_ptr)0)) { cmd_line_head = __39712_25_pclap; }
if (cmd_line_tail != ((a_pl_cmd_line_arg_ptr)0)) { (cmd_line_tail->next) = __39712_25_pclap; }
cmd_line_tail = __39712_25_pclap; 
}


int main( int __39728_14_argc,  char **__39728_26_argv)
{
auto int __39730_17_arg;
auto int __39731_17_return_status = 0;
auto _ZN3edg9a_booleanE __39732_22_done = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __39733_22_any_template_files = ((_ZN3edg9a_booleanE)0);


auto int __39736_17_optchar;
auto long __39737_18_number_of_iterations = 0L;
auto char *__39738_19_nm_command = ((char *)0);
auto a_pl_cmd_line_arg_ptr __39739_26_last_arg_to_reemit = ((a_pl_cmd_line_arg_ptr)0);
auto _ZN3edg9a_booleanE __39740_15_suppress_instantiation_flags = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __39741_15_list_object_files = ((_ZN3edg9a_booleanE)0);


f_informational = stderr;

message_prefix = (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_message_prefix));


memset(((void *)((char *)pl_assignment_table)), 0, 4792ULL);




L_directories = ((char **)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy((((unsigned long long)__39728_14_argc) * 8ULL))));

_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv();



opterr = 0;

while ((__39736_17_optchar = (getopt(__39728_14_argc, ((char *const *)__39728_26_argv), ((const char *)"a:bc:d:ef:il:mno:qrs:vuB:DL:NOR:SW:")))) != (-1)) {
switch (__39736_17_optchar) {
case 97:

if (((strcmp(((const char *)optarg), ((const char *)"0"))) != 0) && ((strcmp(((const char *)optarg), ((const char *)"1"))) != 0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_definition_list_option, optarg);
}
use_definition_list = ((_Bool)((atoi(((const char *)optarg))) != 0));
goto __T1089519280;
case 98:




__39741_15_list_object_files = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 99:


__39738_19_nm_command = optarg;
goto __T1089519280;
case 68:

do_not_assign_to_nonlocal_objects = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 101:


suppress_dependency_checking = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 102:

if ((strcmp(((const char *)optarg), ((const char *)"solaris"))) == 0) {
nm_format = nmfk_solaris;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"SGI"))) == 0) {
nm_format = nmfk_SGI;
ignore_invalid_nm_output = ((_ZN3edg9a_booleanE)1);
skip_underscore_prefix = ((_ZN3edg9a_booleanE)0);
} else  { if ((strcmp(((const char *)optarg), ((const char *)"SVR4"))) == 0) {
nm_format = nmfk_SVR4;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"HPUX"))) == 0) {
nm_format = nmfk_HPUX;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"CLIX"))) == 0) {
nm_format = nmfk_CLIX;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"gnu"))) == 0) {
nm_format = nmfk_gnu;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"MacOSX"))) == 0) {
nm_format = nmfk_MacOSX;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"MacOSX64"))) == 0) {
nm_format = nmfk_MacOSX64;
} else  {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_nm_format_option, ((char *)0));
} } } } } } } }
goto __T1089519280;
case 105:

ignore_invalid_nm_output = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 66:



case 108:
#line 3902
optind--;
goto __39933_1_end_of_options;
case 76:

(L_directories[(num_of_L_directories++)]) = optarg;
goto __T1089519280;
case 111:



{
auto char *__39841_17_obj_file_list_file_name;
__39841_17_obj_file_list_file_name = optarg;
f_obj_file_list = (fopen(((const char *)__39841_17_obj_file_list_file_name), ((const char *)"w")));
if (f_obj_file_list == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_obj_file_list_file, __39841_17_obj_file_list_file_name);

}
}
goto __T1089519280;

case 79:

one_instantiation_per_object = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;

case 87:


if ((strncmp(((const char *)optarg), ((const char *)"l,-L"), 4ULL)) != 0) {
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_unrecognized_option)), optarg);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
}
(L_directories[(num_of_L_directories++)]) = (optarg + 4);
goto __T1089519280;
case 109:

mangled_names_in_output = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 110:


suppress_compilation = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 78:




move_nonlocal_objects_to_curr_dir = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 114:

limit_recursion = ((_ZN3edg9a_booleanE)0);
goto __T1089519280;
case 82:


reserved_request_file_lines = (atoi(((const char *)optarg)));
if ((reserved_request_file_lines < 0) || (reserved_request_file_lines > 0))

{
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_reserved_request_lines_option, optarg);
}
goto __T1089519280;
case 115:


check_specialization_errors = ((_Bool)((atoi(((const char *)optarg))) != 0));
goto __T1089519280;
case 83:



__39740_15_suppress_instantiation_flags = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 117:


skip_underscore_prefix = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 113:

verbose = ((_ZN3edg9a_booleanE)0);
goto __T1089519280;
case 118:

verbose = ((_ZN3edg9a_booleanE)1);
goto __T1089519280;
case 100:
#line 3997
default:
if (optind >= __39728_14_argc) { optind = (__39728_14_argc - 1); }
optarg = (__39728_26_argv[optind]);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_unrecognized_option)), optarg);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
goto __T1089519280;
} __T1089519280:;
}
__39933_1_end_of_options:;
if (((one_instantiation_per_object) || (move_nonlocal_objects_to_curr_dir)) && (f_obj_file_list == ((FILE *)0)))
{


_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_no_object_file_name_specified, ((char *)0));
}

if (__39738_19_nm_command != ((char *)0)) {

} else  { if (((int)nm_format) == 1) {
__39738_19_nm_command = solaris_nm_command;
} else  { if (((int)nm_format) == 2) {
__39738_19_nm_command = SGI_nm_command;
} else  { if (((int)nm_format) == 5) {
__39738_19_nm_command = CLIX_nm_command;
} else  { if ((((int)nm_format) == 3) || (((int)nm_format) == 4))
{
__39738_19_nm_command = alternate_nm_command;
} else  { if (((int)nm_format) == 6) {
__39738_19_nm_command = gnu_nm_command;
} else  {

__39738_19_nm_command = default_nm_command;
} } } } } }

{
#line 4037
auto a_pl_input_file_ptr __39965_25_list_tail = ((a_pl_input_file_ptr)0);
for (__39730_17_arg = optind; __39730_17_arg < __39728_14_argc; ++__39730_17_arg) { {
auto a_pl_input_file_ptr __39967_27_pifp;
auto char *__39968_34_orig_name;
auto char *__39969_34_file_name;
__39968_34_orig_name = (__39728_26_argv[__39730_17_arg]);
if ((strcmp(((const char *)__39968_34_orig_name), ((const char *)"--"))) == 0) {



__39739_26_last_arg_to_reemit = cmd_line_tail;
goto __T1089614712;
}
if ((strncmp(((const char *)__39968_34_orig_name), ((const char *)"-B"), 2ULL)) == 0) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(__39968_34_orig_name, ((a_pl_input_file_ptr)0));
goto __T1089614712;
} else  { if ((strncmp(((const char *)__39968_34_orig_name), ((const char *)"-l"), 2ULL)) == 0) {

auto char *__39984_16_lib_name; __39984_16_lib_name = (__39968_34_orig_name + 2);
__39969_34_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc(__39984_16_lib_name));
} else  {
__39969_34_file_name = __39968_34_orig_name;
} }
__39967_27_pifp = (_ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv());
(__39967_27_pifp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__39969_34_file_name)));

if (pl_input_files == ((a_pl_input_file_ptr)0)) { pl_input_files = __39967_27_pifp; }
_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(((char *)0), __39967_27_pifp);
if (__39965_25_list_tail != ((a_pl_input_file_ptr)0)) { (__39965_25_list_tail->next) = __39967_27_pifp; }
__39965_25_list_tail = __39967_27_pifp;
__39733_22_any_template_files = ((_ZN3edg9a_booleanE)((((int)__39733_22_any_template_files) | ((int)(_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file(__39967_27_pifp)))) != 0));
} __T1089614712:; }
}

if (__39733_22_any_template_files) {
do {
auto a_pl_input_file_ptr __40002_27_pifp;
auto _ZN3edg9a_booleanE __40003_19_no_local_changes;
auto _ZN3edg9a_booleanE __40004_19_no_nonlocal_changes;
auto int __40005_13_nm_status;



for (__40002_27_pifp = pl_input_files; __40002_27_pifp != ((a_pl_input_file_ptr)0); __40002_27_pifp = (__40002_27_pifp->next)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(__40002_27_pifp);
}

pl_symbol_table_head = ((a_pl_symbol_ptr)0);
specialization_list = ((a_pl_symbol_ptr)0);
memset(((void *)((char *)pl_symbol_table)), 0, 80056ULL);


_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv();
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(((_ZN3edg12a_const_charE *)__39738_19_nm_command));

for (__40002_27_pifp = pl_input_files; __40002_27_pifp != ((a_pl_input_file_ptr)0); __40002_27_pifp = (__40002_27_pifp->next)) {
auto a_pl_object_file_ptr __40022_30_pofp;
_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(((const char *)" "), ((_ZN3edg12a_const_charE *)(__40002_27_pifp->file_name)));
if (use_template_info_file) {
_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file(__40002_27_pifp);
}
if (one_instantiation_per_object) {

for (__40022_30_pofp = (__40002_27_pifp->objects); __40022_30_pofp != ((a_pl_object_file_ptr)0); __40022_30_pofp = (__40022_30_pofp->next)) {
if (__40022_30_pofp->is_related_file) {


_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(((const char *)" "), ((_ZN3edg12a_const_charE *)(__40022_30_pofp->file_name)));
}
}
}
}
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(((_ZN3edg12a_const_charE *)nm_command_suffix));




if (!(__39741_15_list_object_files)) {

f_command_output = (popen(temp_string, "r"));
if (f_command_output == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_popen_failed, ((char *)0));
}

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv();
__40005_13_nm_status = (pclose(f_command_output));
if (__40005_13_nm_status != 0) {

_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_nm_returned_error, ((char *)0));
}


_ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv();
#line 4139
_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv();

_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv();
#line 4152
__40003_19_no_local_changes = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEb(((_ZN3edg9a_booleanE)1)));




if ((do_not_assign_to_nonlocal_objects) || ((use_definition_list) && (!(__40003_19_no_local_changes))))
{

__40004_19_no_nonlocal_changes = ((_ZN3edg9a_booleanE)1);
} else  {
__40004_19_no_nonlocal_changes = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEb(((_ZN3edg9a_booleanE)0)));
}
__39732_22_done = ((_Bool)((__40003_19_no_local_changes) && (__40004_19_no_nonlocal_changes)));


__39731_17_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv());
if ((limit_recursion) && ((++__39737_18_number_of_iterations) == 300L)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_instantiation_loop, ((char *)0));
}


if (check_specialization_errors) {
if (_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv()) {


if (__39731_17_return_status == 0) { __39731_17_return_status = 1; }
}
}
if ((__39731_17_return_status != 0) || (suppress_compilation)) { __39732_22_done = ((_ZN3edg9a_booleanE)1); }
} else  {

__39732_22_done = ((_ZN3edg9a_booleanE)1);
}
if (!(__39732_22_done)) { _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(); }
} while (!(__39732_22_done));
}
if (__39740_15_suppress_instantiation_flags) {


_ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv();
}
if (f_obj_file_list != ((FILE *)0)) {
#line 4199
auto a_pl_cmd_line_arg_ptr __40127_27_pclap;
for (__40127_27_pclap = cmd_line_head; __40127_27_pclap != ((a_pl_cmd_line_arg_ptr)0); __40127_27_pclap = (__40127_27_pclap->next)) {
if (__40127_27_pclap->is_string) {
fprintf(f_obj_file_list, ((const char *)" %s"), ((__40127_27_pclap->variant).arg_string));
} else  {
auto a_pl_object_file_ptr __40132_30_pofp;
fprintf(f_obj_file_list, ((const char *)" %s"), (((__40127_27_pclap->variant).input_file_entry)->file_name));



for (__40132_30_pofp = (((__40127_27_pclap->variant).input_file_entry)->objects); __40132_30_pofp != ((a_pl_object_file_ptr)0); __40132_30_pofp = (__40132_30_pofp->next))
{
if (!(__40132_30_pofp->is_related_file)) { goto __T1089682048; }
fprintf(f_obj_file_list, ((const char *)" %s"), (__40132_30_pofp->file_name)); __T1089682048:;
}
}
if (__40127_27_pclap == __39739_26_last_arg_to_reemit) { goto __T1089683944; }
} __T1089683944:;
fprintf(f_obj_file_list, ((const char *)"\n"));
fclose(f_obj_file_list);
}
#line 4228
return __39731_17_return_status;
}
#line 4193 "src/util.h"
 /* COMDAT group: _ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_ */ int _ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_( char *__33525_40_dest_buff, 
size_t __33526_39_dest_buff_size, 
_ZN3edg12a_const_charE *__33527_40_format_str, 
unsigned long __1_33528_42_args)
#line 4205
{




auto int __33542_7_result;
#line 4206
((__33525_40_dest_buff != ((char *)0)) && (__33526_39_dest_buff_size > 0ULL)) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)_ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es), 4206, ((const char *)
#line 4206
_ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0), ((const char *)_ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0)));



__33542_7_result = (snprintf(__33525_40_dest_buff, __33526_39_dest_buff_size, __33527_40_format_str, __1_33528_42_args));

if ((__33542_7_result >= 0) && (((size_t)__33542_7_result) >= __33526_39_dest_buff_size)) {



__33542_7_result = (-1);
}
return __33542_7_result;

}
#line 22 "src/host_util.h"
unsigned long _ZN3edg6crc_32EPKcm( _ZN3edg12a_const_charE *__36274_36_str, 
unsigned long __36275_22_prev_crc)
#line 33
{
auto unsigned long __36286_17_crc;



__36286_17_crc = (__36275_22_prev_crc ^ 4294967295UL);
while (((int)(*__36274_36_str)) != 0) {
auto unsigned long __36292_19_ch;
auto int __36293_9_nbit;
#line 40
__36292_19_ch = ((unsigned long)((unsigned char)(*(__36274_36_str++))));


for (__36293_9_nbit = 0; __36293_9_nbit < 8; (__36293_9_nbit++) , (__36292_19_ch >>= 1)) {
auto int __36296_11_low_bit; __36296_11_low_bit = ((int)((__36292_19_ch ^ __36286_17_crc) & 1UL));
__36286_17_crc >>= 1;
if (__36296_11_low_bit) { __36286_17_crc ^= 0xedb88320UL; }
}
}
__36286_17_crc ^= 4294967295UL;
return __36286_17_crc;
}



_ZN3edg12a_const_charE *_ZN3edg39generate_instantiation_output_file_nameEPKc(
_ZN3edg12a_const_charE *__36308_67_mangled_name)
#line 63
{


auto long long __36318_22_max_len_without_suffix;
#line 83
auto unsigned long __36335_17_crc_value;
auto size_t __36336_17_used_buffer_len;
auto size_t __36337_17_remaining_buffer_len;


auto int __36340_17_chars_written;
#line 73
__36318_22_max_len_without_suffix = 23LL;

__36318_22_max_len_without_suffix -= 7LL;



(__36318_22_max_len_without_suffix > 0LL) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)"src/host_util.h"), 79, ((const char *)""), ((const char *)"")));
strncpy(_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer, __36308_67_mangled_name, ((size_t)__36318_22_max_len_without_suffix));
((_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer)[__36318_22_max_len_without_suffix]) = ((char)0);

__36335_17_crc_value = (_ZN3edg6crc_32EPKcm(__36308_67_mangled_name, 0UL));
__36336_17_used_buffer_len = (strlen(((const char *)_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer)));
__36337_17_remaining_buffer_len = (32ULL - __36336_17_used_buffer_len);


__36340_17_chars_written = (_ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_((_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer + __36336_17_used_buffer_len), __36337_17_remaining_buffer_len, ((const char *)"_%08lx"), __36335_17_crc_value));



(__36340_17_chars_written > 0) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)"src/host_util.h"), 92, ((const char *)""), ((const char *)"")));

return (_ZN3edg12a_const_charE *)(_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer);
}
#line 223
_ZN3edg9a_booleanE _ZN3edg26get_file_modification_timeEPKcPx( _ZN3edg12a_const_charE *__36475_52_file_name, 
time_t *__36476_52_p_time)




{
auto _ZN3edg9a_booleanE __36482_13_is_regular = ((_ZN3edg9a_booleanE)0);
#line 254
{


auto struct stat __36509_17_buf;
#line 266
if ((stat(__36475_52_file_name, (&__36509_17_buf))) == 0) {



__36482_13_is_regular = ((_Bool)((((int)(__36509_17_buf.st_mode)) & 0xf000) == 0x8000));



if ((__36482_13_is_regular) && (__36476_52_p_time != ((time_t *)0))) { (*__36476_52_p_time) = ((__36509_17_buf.st_mtim).tv_sec); }
} else  {

if (__36476_52_p_time != ((time_t *)0)) { (*__36476_52_p_time) = 0LL; }
}
}
return __36482_13_is_regular;
}
