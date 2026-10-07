/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:15:23 2026 */
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
#line 20 "ape-sys/stdlib.h"
extern int atoi(const char *);
#line 44
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



static a_pl_cmd_line_arg_ptr cmd_line_tail; extern  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es[94]; extern  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0 */ char 
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



static a_pl_cmd_line_arg_ptr cmd_line_tail = ((a_pl_cmd_line_arg_ptr)0);  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es[94] = "src/util.h"
#line 3774
;  /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0 */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0[1] = "";
#line 57 "util/getopt.h"
int getopt( int __27668_16_argc,  char *const *__27668_37_argv,  const char *__27668_55_optstring)
#line 73
{
auto int __27685_15_return_value;
auto char *__27686_16_optpos;
#line 83
if (_ZZ6getoptE7optchar == ((char *)0)) {
__27695_1_start_new_argument:;
if (optind >= __27668_16_argc) {

__27685_15_return_value = (-1);
goto __27773_1_end_of_routine;
} else  {
_ZZ6getoptE7optchar = (__27668_37_argv[optind]);
if (((int)(*_ZZ6getoptE7optchar)) != 45) {

__27685_15_return_value = (-1);
goto __27773_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 45) {
if (((int)(*(_ZZ6getoptE7optchar + 2))) == 0) {


optind++;
__27685_15_return_value = (-1);
} else  {

__27685_15_return_value = 63;
}
goto __27773_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


__27685_15_return_value = (-1);
goto __27773_1_end_of_routine;
} } }

_ZZ6getoptE7optchar++;
}
}


if (((int)(*_ZZ6getoptE7optchar)) == 0) {

optind++;
goto __27695_1_start_new_argument;
}

__27686_16_optpos = (strchr(((const char *)((char *)__27668_55_optstring)), ((int)(*_ZZ6getoptE7optchar))));
if (__27686_16_optpos == ((char *)0)) {

if (opterr) { fprintf(stderr, ((const char *)"%s: illegal option -- %c\n"), (__27668_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27685_15_return_value = 63;
goto __27773_1_end_of_routine;
}

__27685_15_return_value = ((int)(*_ZZ6getoptE7optchar));

if (((int)(*(__27686_16_optpos + 1))) == 58) {
if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


optind++;
if (optind >= __27668_16_argc) {


if (opterr) { fprintf(stderr, ((const char *)"%s: option requires an argument -- %c\n"), (__27668_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__27685_15_return_value = 63;
goto __27773_1_end_of_routine;
}
optarg = (__27668_37_argv[optind]);
} else  {


optarg = (_ZZ6getoptE7optchar + 1);
}

_ZZ6getoptE7optchar = ((char *)0);
optind++;
} else  {

_ZZ6getoptE7optchar++;
optarg = ((char *)0);
}
__27773_1_end_of_routine:;
return __27685_15_return_value;
}
#line 558 "util/edg_prelink.c"
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc( _ZN3edg12a_const_charE *__28264_45_error_string)




{
fprintf(stderr, ((const char *)"%s: internal error: %s\n"), message_prefix, __28264_45_error_string);



fflush(stderr);
abort(); 

}



static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_( _ZN3edg12a_const_charE *__28281_47_filename, 
int __28282_18_line_number, 
_ZN3edg12a_const_charE *__28283_19_string1, 
_ZN3edg12a_const_charE *__28284_19_string2)



{
fprintf(stderr, ((const char *)"assertion failed: %s%s (%s, line %0d)\n"), __28283_19_string1, __28284_19_string2, __28281_47_filename, __28282_18_line_number);

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"assertion failed")); 
}
#line 632
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc( char *__36428_49_file_name)



{
#line 642
return (_Bool)(((int)(__36428_49_file_name[0])) == 47);

}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv(void)



{

if ((getcwd(curr_dir_name, 2048ULL)) == ((char *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"getcwd failed"));
} 



}
#line 698
static _ZN3edg12a_const_charE *_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code( enum a_pl_error_code __36494_52_error_code)




{
auto _ZN3edg12a_const_charE *__36500_17_m = ((_ZN3edg12a_const_charE *)0);
switch ((int)__36494_52_error_code) {
case 0:
__36500_17_m = ((const char *)"%s: %s no longer needed in %s\n");
goto __T338886360;
case 1:
__36500_17_m = ((const char *)"%s: %s assigned to file %s\n");
goto __T338886360;
case 2:
__36500_17_m = ((const char *)"C++ prelinker");
goto __T338886360;
case 3:
__36500_17_m = ((const char *)"%s: executing: %s\n");
goto __T338886360;
case 4:
__36500_17_m = ((const char *)"unrecognized option: %s\n");
goto __T338886360;
case 5:
__36500_17_m = ((const char *)"%s: error: ");
goto __T338886360;
case 6:
__36500_17_m = ((const char *)"out of memory");
goto __T338886360;
case 7:
__36500_17_m = ((const char *)"invalid input format");
goto __T338886360;
case 8:
__36500_17_m = ((const char *)"bad instantiation request file -- instantiation assigned to more than one file");

goto __T338886360;
case 9:
__36500_17_m = ((const char *)"invalid nm format option");
goto __T338886360;
case 10:
__36500_17_m = ((const char *)"command line error");
goto __T338886360;
case 11:
__36500_17_m = ((const char *)"instantiation loop");
goto __T338886360;
case 12:
__36500_17_m = ((const char *)"library \"%s\" does not exist in the specified library directories\n");
goto __T338886360;
case 13:
__36500_17_m = ((const char *)"an error occurred during name decoding of \"%s\"");
goto __T338886360;
case 14:
__36500_17_m = ((const char *)"%s: warning: ");
goto __T338886360;
case 15:
__36500_17_m = ((const char *)"invalid reserved request file lines option \"%s\"");
goto __T338886360;
case 16:
__36500_17_m = ((const char *)"cannot open object file name list file \"%s\"");
goto __T338886360;
case 17:
__36500_17_m = ((const char *)"cannot create instantiation request file \"%s\"");
goto __T338886360;
case 18:
__36500_17_m = ((const char *)"cannot change to directory \"%s\"");
goto __T338886360;
case 19:
__36500_17_m = ((const char *)"no output produced by nm -- possible configuration problem");
goto __T338886360;
case 20:
__36500_17_m = ((const char *)"unable to create process for nm command");
goto __T338886360;
case 21:
__36500_17_m = ((const char *)"\"%s\" has been referenced as both an explicit specialization and a generated instantiation");

goto __T338886360;
case 22:
__36500_17_m = ((const char *)"file \"%s\" is read-only");
goto __T338886360;
case 23:
__36500_17_m = ((const char *)"nm returned a nonzero error status");
goto __T338886360;
case 24:
__36500_17_m = ((const char *)"%s assigned to %s and %s\n");
goto __T338886360;
case 25:
__36500_17_m = ((const char *)"-O and -N require a new object list file name specified with the -o option");

goto __T338886360;
case 26:
__36500_17_m = ((const char *)"invalid definition list option \"%s\"");
goto __T338886360;
case 27:
__36500_17_m = ((const char *)"cannot create temporary file \"%s\"");
goto __T338886360;
case 28:
__36500_17_m = ((const char *)"%s: %s adopted by file %s\n");
goto __T338886360;
case 29:
__36500_17_m = ((const char *)"%s: rebuilding %s because %s (used by an exported template file) has changed\n");

goto __T338886360;
case 30:
__36500_17_m = ((const char *)"corrupted template information file or instantiation request file");
goto __T338886360;
default:
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"invalid error code"));
} __T338886360:;
return __36500_17_m;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePcb( enum a_pl_error_code __36606_48_error_code, 
char *__36607_39_insertion_string, 
_ZN3edg9a_booleanE __36608_49_exit_when_done)
#line 821
{
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_error)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(__36606_48_error_code)), __36607_39_insertion_string);
fprintf(stderr, ((const char *)"\n"));
if (__36608_49_exit_when_done) { exit(2); } 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc( enum a_pl_error_code __36625_38_error_code, 
char *__36626_29_insertion_string)




{

_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePcb(__36625_38_error_code, __36626_29_insertion_string, ((_ZN3edg9a_booleanE)1)); 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc( enum a_pl_error_code __36637_40_error_code, 
char *__36638_31_insertion_string)
#line 850
{
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_warning)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(__36637_40_error_code)), __36638_31_insertion_string);
fprintf(stderr, ((const char *)"\n")); 
}

static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy( _ZN3edg8sizeof_tE __36652_49_size)




{
auto _ZN3edg10a_void_ptrE __36658_14_ptr;

if ((__36658_14_ptr = ((_ZN3edg10a_void_ptrE)(malloc(__36652_49_size)))) == ((_ZN3edg10a_void_ptrE)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_out_of_memory, ((char *)0));
}
return __36658_14_ptr;
}


static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvy( _ZN3edg10a_void_ptrE __36667_52_old_ptr, 
_ZN3edg8sizeof_tE __36668_50_new_size)
#line 878
{
auto _ZN3edg10a_void_ptrE __36675_14_ptr;



if (__36667_52_old_ptr == ((_ZN3edg10a_void_ptrE)0)) {
__36675_14_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(__36668_50_new_size));
} else  {
__36675_14_ptr = ((_ZN3edg10a_void_ptrE)(realloc(((a_realloc_arg)__36667_52_old_ptr), __36668_50_new_size)));
if (__36675_14_ptr == ((_ZN3edg10a_void_ptrE)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_out_of_memory, ((char *)0));
}
}
return __36675_14_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file( a_pl_input_file_ptr __36691_53_pifp)




{
(__36691_53_pifp->request_list) = ((a_pl_symbol_ptr)0);
(__36691_53_pifp->objects) = ((a_pl_object_file_ptr)0);
(__36691_53_pifp->is_archive) = ((_ZN3edg14a_byte_booleanE)0);
(__36691_53_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)0);
(__36691_53_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)0);
(__36691_53_pifp->is_local_file) = ((_ZN3edg14a_byte_booleanE)1);
(__36691_53_pifp->command_line) = ((char *)0);
(__36691_53_pifp->compilation_directory) = ((char *)0);
(__36691_53_pifp->compilation_file_name) = ((char *)0);
(__36691_53_pifp->secondary_files) = ((char *)0);
(__36691_53_pifp->dependencies) = ((a_pl_file_list_entry_ptr)0);
(__36691_53_pifp->instantiation_directory) = ((char *)0); 
}


static a_pl_input_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv(void)



{
auto a_pl_input_file_ptr __36717_24_pifp;

__36717_24_pifp = ((a_pl_input_file_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(120ULL)));
(__36717_24_pifp->next) = ((a_pl_input_file_ptr)0);
(__36717_24_pifp->file_name) = ((char *)0);
(__36717_24_pifp->request_file_name) = ((char *)0);
(__36717_24_pifp->template_info_file_name) = ((char *)0);
_ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(__36717_24_pifp);
return __36717_24_pifp;
}


static a_pl_object_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv(void)



{
auto a_pl_object_file_ptr __36734_25_pofp;

if (avail_pl_object_files != ((a_pl_object_file_ptr)0)) {
__36734_25_pofp = avail_pl_object_files;
avail_pl_object_files = (__36734_25_pofp->next);
} else  {
__36734_25_pofp = ((a_pl_object_file_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(40ULL)));

}
(__36734_25_pofp->next) = ((a_pl_object_file_ptr)0);
(__36734_25_pofp->file_name) = ((char *)0);
(__36734_25_pofp->symbols) = ((a_pl_symbol_ptr)0);
(__36734_25_pofp->included_in_output) = ((_ZN3edg14a_byte_booleanE)0);
(__36734_25_pofp->is_related_file) = ((_ZN3edg14a_byte_booleanE)0);
(__36734_25_pofp->modification_time) = 0LL;
return __36734_25_pofp;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file( a_pl_object_file_ptr __36753_54_pofp)



{
(__36753_54_pofp->next) = avail_pl_object_files;
avail_pl_object_files = __36753_54_pofp; 
}


static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv(void)



{
auto a_pl_assignment_ptr __36768_23_ap;

__36768_23_ap = ((a_pl_assignment_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(24ULL)));
(__36768_23_ap->next) = ((a_pl_assignment_ptr)0);
(__36768_23_ap->name) = ((char *)0);
(__36768_23_ap->times_assigned) = 0;
return __36768_23_ap;
}


static a_pl_file_list_entry_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv(void)



{
auto a_pl_file_list_entry_ptr __36783_28_flep;

__36783_28_flep = ((a_pl_file_list_entry_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(16ULL)));

(__36783_28_flep->next) = ((a_pl_file_list_entry_ptr)0);
(__36783_28_flep->name) = ((char *)0);
return __36783_28_flep;
}


static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv(void)



{
auto a_pl_symbol_ptr __36798_20_psp;

if (avail_pl_symbols != ((a_pl_symbol_ptr)0)) {
__36798_20_psp = avail_pl_symbols;
avail_pl_symbols = (__36798_20_psp->next);
} else  {
__36798_20_psp = ((a_pl_symbol_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(104ULL)));
}
(__36798_20_psp->name) = ((char *)0);
(__36798_20_psp->next) = ((a_pl_symbol_ptr)0);
(__36798_20_psp->next_in_symbol_table) = ((a_pl_symbol_ptr)0);
(__36798_20_psp->next_in_request_file) = ((a_pl_symbol_ptr)0);
(__36798_20_psp->next_in_specialization_list) = ((a_pl_symbol_ptr)0);
(__36798_20_psp->global_sym) = ((a_pl_symbol_ptr)0);
(__36798_20_psp->template_sym) = ((a_pl_symbol_ptr)0);
(__36798_20_psp->primary_entry) = ((a_pl_symbol_ptr)0);
(__36798_20_psp->instantiation_file) = ((a_pl_input_file_ptr)0);
(__36798_20_psp->possible_instantiation_sites) = ((a_pl_instantiation_site_ptr)0);
(__36798_20_psp->referenced) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->defined) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->definition_seen_in_archive) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->tentative_definition) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->multiple_definition) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->is_template) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->instantiated) = ((_ZN3edg14a_byte_booleanE)0);
(__36798_20_psp->defined_in) = ((a_pl_input_file_ptr)0);
return __36798_20_psp;
}


static a_pl_instantiation_site_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv(void)



{
auto a_pl_instantiation_site_ptr __36835_32_pisp;

if (avail_pl_instantiation_sites != ((a_pl_instantiation_site_ptr)0)) {
__36835_32_pisp = avail_pl_instantiation_sites;
avail_pl_instantiation_sites = (__36835_32_pisp->next);
} else  {
__36835_32_pisp = ((a_pl_instantiation_site_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(16ULL)));

}
(__36835_32_pisp->next) = ((a_pl_instantiation_site_ptr)0);
(__36835_32_pisp->input_file) = ((a_pl_input_file_ptr)0);
return __36835_32_pisp;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site( a_pl_instantiation_site_ptr __36850_68_pisp)



{
(__36850_68_pisp->next) = avail_pl_instantiation_sites;
avail_pl_instantiation_sites = __36850_68_pisp; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol( a_pl_symbol_ptr __36860_44_psp)



{
(__36860_44_psp->next) = avail_pl_symbols;
avail_pl_symbols = __36860_44_psp; 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE( FILE *__36870_43_f_input)
#line 1080
{
auto char *__36877_14_buffer_pos = pl_input_line;
auto int __36878_14_size = 0;
auto int __36879_14_ch;
auto _ZN3edg9a_booleanE __36880_14_result;

while ((__36879_14_ch = (getc(__36870_43_f_input))) , ((__36879_14_ch != (-1)) && (__36879_14_ch != 10))) {
if ((++__36878_14_size) > 32767) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"pl_read_input_line: input line too long."));
}
(*(__36877_14_buffer_pos++)) = ((char)__36879_14_ch);
}


(*(__36877_14_buffer_pos++)) = ((char)0);


__36880_14_result = ((_ZN3edg9a_booleanE)1);
if ((__36879_14_ch == (-1)) && (__36878_14_size == 0)) { __36880_14_result = ((_ZN3edg9a_booleanE)0); }

return __36880_14_result;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc( _ZN3edg12a_const_charE *__36900_43_source)




{
auto char *__36906_9_dest;
__36906_9_dest = ((char *)(malloc(((strlen(__36900_43_source)) + 1ULL))));
strcpy(__36906_9_dest, __36900_43_source);
return __36906_9_dest;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc( char *__36913_55_name)



{
auto char *__36918_10_ptr;

__36918_10_ptr = (strstr(((const char *)__36913_55_name), ((const char *)"__S")));
return (_Bool)(__36918_10_ptr != ((char *)0));
}
#line 1132
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc( char *__36928_44_name)
#line 1138
{

auto char *__36936_10_from;
auto char *__36937_10_to;

if (_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer == ((char *)0)) {


_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(32767ULL)));
}

__36936_10_from = __36928_44_name;
__36937_10_to = _ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
while (((int)(*__36936_10_from)) != 0) {
if (((((int)(*__36936_10_from)) == 95) && (((int)(__36936_10_from[1])) == 95)) && (((int)(__36936_10_from[2])) == 83)) {
__36936_10_from += 3;
goto __T339159944;
}
(*(__36937_10_to++)) = (*(__36936_10_from++)); __T339159944:;
}

(*__36937_10_to) = ((char)0);
return _ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(void)



{
if (!(ignore_invalid_nm_output)) { _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_input, ((char *)0)); } 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc( char *__36969_36_encoded_name)



{
auto _ZN3edg9a_booleanE __36974_13_error;
auto _ZN3edg9a_booleanE __36975_13_buffer_overflow;
auto char *__36976_10_result;

auto _ZN3edg8sizeof_tE __36978_12_required_buffer_size;

if (mangled_names_in_output) {

__36976_10_result = __36969_36_encoded_name;

} else  { if ((((int)(__36969_36_encoded_name[0])) != 95) || (((int)(__36969_36_encoded_name[1])) != 90)) {



__36976_10_result = __36969_36_encoded_name;

} else  {
_Z17decode_identifierPKcPcyPbS2_Py(((_ZN3edg12a_const_charE *)__36969_36_encoded_name), _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer, 32767ULL, (&__36974_13_error), (&__36975_13_buffer_overflow), (&__36978_12_required_buffer_size));

__36976_10_result = _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer;
if (__36974_13_error) {


_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_error_occurred_during_name_decoding, __36969_36_encoded_name);
__36976_10_result = __36969_36_encoded_name;
}
} }
return __36976_10_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_( char **__37005_49_name1, 
char **__37006_21_name2, 
char *__37007_20_type, 
char **__37008_21_symbol_name)
#line 1257
{
auto _ZN3edg9a_booleanE __37054_13_result = ((_ZN3edg9a_booleanE)1);
auto char *__37055_10_pos;
auto char *__37056_10_rest_of_line;
auto char __37057_9_ch;


(*__37005_49_name1) = ((*__37006_21_name2) = ((*__37008_21_symbol_name) = ((char *)0)));
(*__37007_20_type) = ((char)0);


__37055_10_pos = (strchr(((const char *)pl_input_line), 58));
if (__37055_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37054_13_result = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)(*(__37055_10_pos + 1))) == 0) {


__37054_13_result = ((_ZN3edg9a_booleanE)0);
} else  {


__37055_10_pos = pl_input_line;
while ((__37057_9_ch = (*__37055_10_pos)) , ((((int)__37057_9_ch) != 32) && (((int)__37057_9_ch) != 0))) { __37055_10_pos++; }

if (((int)(*(__37055_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37055_10_pos)) == 32) { __37055_10_pos++; }

(*__37007_20_type) = (*(__37055_10_pos++));
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__37007_20_type)))])) & 0x3)) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

if (((int)(*(__37055_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37055_10_pos)) == 32) { __37055_10_pos++; }


__37056_10_rest_of_line = __37055_10_pos;
__37055_10_pos = (strchr(((const char *)__37056_10_rest_of_line), 58));

(*__37055_10_pos) = ((char)0);
(*__37005_49_name1) = __37056_10_rest_of_line;
__37056_10_rest_of_line = (__37055_10_pos + 1);
__37055_10_pos = (strchr(((const char *)__37056_10_rest_of_line), 58));
if (__37055_10_pos == ((char *)0)) {

(*__37006_21_name2) = ((char *)0);
} else  {


(*__37055_10_pos) = ((char)0);
(*__37006_21_name2) = __37056_10_rest_of_line;
__37056_10_rest_of_line = (__37055_10_pos + 1);
}
(*__37008_21_symbol_name) = __37056_10_rest_of_line;
} }
return __37054_13_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_( char **__37115_51_name1, 
char **__37116_18_name2, 
char *__37117_17_type, 
char **__37118_18_symbol_name)
#line 1405
{
auto _ZN3edg9a_booleanE __37202_13_result = ((_ZN3edg9a_booleanE)1);
auto char *__37203_10_pos;
auto char *__37204_10_rest_of_line;
auto char __37205_9_ch;
#line 1417
if (_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer == ((char *)0)) {
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(32767ULL)));
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(32767ULL)));
}

(*__37115_51_name1) = ((*__37116_18_name2) = ((*__37118_18_symbol_name) = ((char *)0)));
(*__37117_17_type) = ((char)0);


__37203_10_pos = (strchr(((const char *)pl_input_line), 58));
if (__37203_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37202_13_result = ((_ZN3edg9a_booleanE)0);
} else  { if ((strchr(((const char *)pl_input_line), 32)) == ((char *)0)) {
auto char *__37229_11_bracket_pos;



__37202_13_result = ((_ZN3edg9a_booleanE)0);


__37229_11_bracket_pos = (strchr(((const char *)pl_input_line), 91));
if (__37229_11_bracket_pos != ((char *)0)) { __37203_10_pos = __37229_11_bracket_pos; }

(*__37203_10_pos) = ((char)0);
strcpy(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer, ((const char *)pl_input_line));
__37204_10_rest_of_line = (__37203_10_pos + 1);
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL = ((_Bool)(__37229_11_bracket_pos == ((char *)0)));
if (!(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL)) {

__37203_10_pos = (strchr(((const char *)__37204_10_rest_of_line), 93));
(*__37203_10_pos) = ((char)0);
strcpy(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer, ((const char *)__37204_10_rest_of_line));
}
} else  {

(*__37115_51_name1) = _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer;
(*__37116_18_name2) = ((_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL) ? ((char *)0) : _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer);


if ((((int)nm_format) == 4) || (((int)nm_format) == 5)) {
__37204_10_rest_of_line = (__37203_10_pos + 1);
} else  {
__37204_10_rest_of_line = pl_input_line;
}


__37203_10_pos = __37204_10_rest_of_line;
while (((int)(*__37203_10_pos)) == 32) { __37203_10_pos++; }


while ((__37205_9_ch = (*__37203_10_pos)) , ((((int)__37205_9_ch) != 32) && (((int)__37205_9_ch) != 0))) { __37203_10_pos++; }

if (((int)(*(__37203_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37203_10_pos)) == 32) { __37203_10_pos++; }

(*__37117_17_type) = (*(__37203_10_pos++));
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__37117_17_type)))])) & 0x3)) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
if (((int)nm_format) == 4) {

switch ((int)(*__37117_17_type)) {
case 99: (*__37117_17_type) = ((char)67); goto __T339334896;
} __T339334896:;
}

if (((int)nm_format) == 4) { while ((((int)(*__37203_10_pos)) != 32) && (((int)(*__37203_10_pos)) != 0)) { __37203_10_pos++; } }

if (((int)(*(__37203_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37203_10_pos)) == 32) { __37203_10_pos++; }
if (((int)nm_format) == 5) {


if ((skip_underscore_prefix) && (((int)(*__37203_10_pos)) == 95)) { __37203_10_pos++; }
}
__37204_10_rest_of_line = __37203_10_pos;


if ((((int)nm_format) != 4) && (((int)nm_format) != 5)) {
__37203_10_pos = (strchr(((const char *)__37204_10_rest_of_line), 58));
__37204_10_rest_of_line = (__37203_10_pos + 1);
}
(*__37118_18_symbol_name) = __37204_10_rest_of_line;
} }
return __37202_13_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_( char **__37304_49_name1, 
char **__37305_14_name2, 
char *__37306_13_type, 
char **__37307_14_symbol_name)
#line 1612
{
auto _ZN3edg9a_booleanE __37409_13_result = ((_ZN3edg9a_booleanE)1);
auto char *__37410_10_pos;
auto char *__37411_10_rest_of_line;
auto char __37412_9_ch;


(*__37304_49_name1) = ((*__37305_14_name2) = ((*__37307_14_symbol_name) = ((char *)0)));
(*__37306_13_type) = ((char)0);
__37410_10_pos = pl_input_line;
#line 1628
__37410_10_pos = (strchr(((const char *)__37410_10_pos), 58));
if (__37410_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37409_13_result = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)(*(__37410_10_pos + 1))) == 0) {


__37409_13_result = ((_ZN3edg9a_booleanE)0);
} else  {
if (((int)nm_format) == 6) {
auto char *__37436_13_paren_pos;


(*__37410_10_pos) = ((char)0);
__37411_10_rest_of_line = (__37410_10_pos + 1);
__37436_13_paren_pos = (strchr(((const char *)pl_input_line), 40));
if (__37436_13_paren_pos == ((char *)0)) {

(*__37304_49_name1) = pl_input_line;
(*__37305_14_name2) = ((char *)0);
} else  {
auto char *__37447_15_end_of_name2;

(*__37304_49_name1) = pl_input_line;

(*__37436_13_paren_pos) = ((char)0);

(*__37305_14_name2) = (__37436_13_paren_pos + 1);
__37447_15_end_of_name2 = (strchr(((const char *)(*__37305_14_name2)), 41));

(*__37447_15_end_of_name2) = ((char)0);
}
} else  {


(*__37410_10_pos) = ((char)0);
(*__37304_49_name1) = pl_input_line;
__37411_10_rest_of_line = (__37410_10_pos + 1);
__37410_10_pos = (strchr(((const char *)__37411_10_rest_of_line), 58));
if (__37410_10_pos == ((char *)0)) {

(*__37305_14_name2) = ((char *)0);
} else  {


(*__37410_10_pos) = ((char)0);
(*__37305_14_name2) = __37411_10_rest_of_line;
__37411_10_rest_of_line = (__37410_10_pos + 1);
}
}
__37410_10_pos = __37411_10_rest_of_line;
if (((int)nm_format) == 2) {


while (((int)(*__37410_10_pos)) == 32) { __37410_10_pos++; }
}
if (((int)nm_format) == 7) {


auto int __37485_11_i;
for (__37485_11_i = 0; __37485_11_i < 9; ++__37485_11_i) {
if (((int)(*__37410_10_pos)) == 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37410_10_pos++;
}
} else  { if (((int)nm_format) == 8) {


auto int __37493_11_i;
for (__37493_11_i = 0; __37493_11_i < 17; ++__37493_11_i) {
if (((int)(*__37410_10_pos)) == 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__37410_10_pos++;
}
} else  {


while ((__37412_9_ch = (*__37410_10_pos)) , ((((int)__37412_9_ch) != 32) && (((int)__37412_9_ch) != 0))) { __37410_10_pos++; }
} }

if (((int)(*(__37410_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__37410_10_pos)) == 32) { __37410_10_pos++; }

(*__37306_13_type) = (*(__37410_10_pos++));
if (!(((int)((_ctype)[((unsigned char)((unsigned char)(*__37306_13_type)))])) & 0x3)) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

if (((int)(*(__37410_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }


if ((skip_underscore_prefix) && (((int)(*__37410_10_pos)) == 95)) { __37410_10_pos++; }
(*__37307_14_symbol_name) = __37410_10_pos;
if (((int)nm_format) == 2) {




while ((__37412_9_ch = (*__37410_10_pos)) , ((((int)__37412_9_ch) != 32) && (((int)__37412_9_ch) != 0))) { __37410_10_pos++; }
if (((int)__37412_9_ch) == 32) { (*__37410_10_pos) = ((char)0); }
}
} }
return __37409_13_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv(void)
#line 1744
{
auto char *__37541_11_input_file_name = ((char *)0);
auto char *__37542_11_obj_file_name = ((char *)0);
auto _ZN3edg9a_booleanE __37543_14_is_archive = ((_ZN3edg9a_booleanE)0);
auto a_pl_object_file_ptr __37544_24_objects_tail = ((a_pl_object_file_ptr)0);
auto a_pl_object_file_ptr __37545_24_pofp = ((a_pl_object_file_ptr)0);
auto a_pl_input_file_ptr __37546_23_pifp = ((a_pl_input_file_ptr)0);
auto _ZN3edg9a_booleanE __37547_14_any_lines_read = ((_ZN3edg9a_booleanE)0);

while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(f_command_output)) { {
auto char *__37550_12_name1;
auto char *__37551_12_name2;
auto char __37552_11_type;
auto char *__37553_12_symbol_name;
auto a_pl_symbol_ptr __37554_21_psp;
auto _ZN3edg9a_booleanE __37555_16_process_line;
#line 1765
__37547_14_any_lines_read = ((_ZN3edg9a_booleanE)1);

if (((int)nm_format) == 1) {
__37555_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_((&__37550_12_name1), (&__37551_12_name2), (&__37552_11_type), (&__37553_12_symbol_name)));

} else  { if (((((int)nm_format) == 3) || (((int)nm_format) == 4)) || (((int)nm_format) == 5))

{
__37555_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_((&__37550_12_name1), (&__37551_12_name2), (&__37552_11_type), (&__37553_12_symbol_name)));

} else  {

__37555_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_((&__37550_12_name1), (&__37551_12_name2), (&__37552_11_type), (&__37553_12_symbol_name)));

} }
#line 1791
if (!(__37555_16_process_line)) { goto __T339444080; }

if ((__37541_11_input_file_name == ((char *)0)) || ((strcmp(((const char *)__37541_11_input_file_name), ((const char *)__37550_12_name1))) != 0))
{



__37543_14_is_archive = ((_Bool)(__37551_12_name2 != ((char *)0)));
for (__37546_23_pifp = pl_input_files; __37546_23_pifp != ((a_pl_input_file_ptr)0); __37546_23_pifp = (__37546_23_pifp->next)) {
#line 1806
if ((__37543_14_is_archive) && ((strcmp(((const char *)(__37546_23_pifp->file_name)), ((const char *)__37550_12_name1))) != 0)) { goto __T339451024; }


if (__37546_23_pifp->is_archive) { goto __T339451024; }


for (__37545_24_pofp = (__37546_23_pifp->objects); __37545_24_pofp != ((a_pl_object_file_ptr)0); __37545_24_pofp = (__37545_24_pofp->next)) {
if ((strcmp(((const char *)(__37545_24_pofp->file_name)), ((const char *)__37550_12_name1))) == 0) { goto __T339455304; }
} __T339455304:;
if (__37545_24_pofp != ((a_pl_object_file_ptr)0)) { goto __T339456712; }



if ((strcmp(((const char *)(__37546_23_pifp->file_name)), ((const char *)__37550_12_name1))) == 0) { goto __T339456712; } __T339451024:;
} __T339456712:;
if (__37546_23_pifp == ((a_pl_input_file_ptr)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Input file not in list"));
}
__37541_11_input_file_name = (__37546_23_pifp->file_name);
(__37546_23_pifp->is_archive) = __37543_14_is_archive;
__37544_24_objects_tail = ((a_pl_object_file_ptr)0);
if (__37543_14_is_archive) {
__37542_11_obj_file_name = ((char *)0);
} else  {
if (__37545_24_pofp == ((a_pl_object_file_ptr)0)) {



__37545_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__37545_24_pofp->next) = (__37546_23_pifp->objects);
(__37546_23_pifp->objects) = __37545_24_pofp;
(__37545_24_pofp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37541_11_input_file_name)));
}
}
}

if (__37543_14_is_archive) {
if ((__37542_11_obj_file_name == ((char *)0)) || ((strcmp(((const char *)__37542_11_obj_file_name), ((const char *)__37551_12_name2))) != 0))
{

__37542_11_obj_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37551_12_name2)));
__37545_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__37545_24_pofp->file_name) = __37542_11_obj_file_name;


if ((__37546_23_pifp->objects) == ((a_pl_object_file_ptr)0)) { (__37546_23_pifp->objects) = __37545_24_pofp; }
if (__37544_24_objects_tail != ((a_pl_object_file_ptr)0)) { (__37544_24_objects_tail->next) = __37545_24_pofp; }
__37544_24_objects_tail = __37545_24_pofp;
}
}


if ((((((((((((int)__37552_11_type) != 66) && (((int)__37552_11_type) != 68)) && (((int)__37552_11_type) != 76)) && (((int)__37552_11_type) != 82)) && (((int)__37552_11_type) != 83)) && (((int)__37552_11_type) != 84)) && (((int)__37552_11_type) != 85)) && (((int)__37552_11_type) != 86)) && (((int)
#line 1858
__37552_11_type) != 87)) && (((int)__37552_11_type) != 67))
#line 1867
{


} else  {
__37554_21_psp = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());
(__37554_21_psp->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37553_12_symbol_name)));

switch ((int)__37552_11_type) {
case 66:
case 68:
case 76:
case 82:
case 83:
case 84:
case 86:
case 87:
(__37554_21_psp->defined) = ((_ZN3edg14a_byte_booleanE)1);
goto __T339495280;
case 85:
(__37554_21_psp->referenced) = ((_ZN3edg14a_byte_booleanE)1);
goto __T339495280;
case 67:
(__37554_21_psp->tentative_definition) = ((_ZN3edg14a_byte_booleanE)1);
goto __T339495280;
default:
goto __T339495280;
} __T339495280:;

(__37554_21_psp->next) = (__37545_24_pofp->symbols);
(__37545_24_pofp->symbols) = __37554_21_psp;
}
} __T339444080:; }
if (!(__37547_14_any_lines_read)) {


_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_no_nm_info, ((char *)0));
}
return;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file( a_pl_symbol_ptr __37704_61_psp, 
a_pl_input_file_ptr __37705_30_pifp)



{
auto a_pl_instantiation_site_ptr __37710_31_pisp;
#line 1920
if (((__37704_61_psp->possible_instantiation_sites) == ((a_pl_instantiation_site_ptr)0)) || (((__37704_61_psp->possible_instantiation_sites)->input_file) != __37705_30_pifp))
{
__37710_31_pisp = (_ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv());
(__37710_31_pisp->input_file) = __37705_30_pifp;
(__37710_31_pisp->next) = (__37704_61_psp->possible_instantiation_sites);
(__37704_61_psp->possible_instantiation_sites) = __37710_31_pisp;
} 
}


static unsigned _ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc( char *__37726_47_name)



{
auto unsigned __37731_16_hash_value = 0U;
auto char *__37732_10_ptr;
auto int __37733_8_length;




__37733_8_length = ((int)((unsigned)(strlen(((const char *)__37726_47_name)))));
__37732_10_ptr = __37726_47_name;
if (__37733_8_length > 9) {
__37731_16_hash_value = ((unsigned)(*(__37732_10_ptr++)));
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*(__37732_10_ptr++))));
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*__37732_10_ptr)));
__37732_10_ptr = ((__37726_47_name + (__37733_8_length >> 1)) - 1);
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*(__37732_10_ptr++))));
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*(__37732_10_ptr++))));
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*__37732_10_ptr)));
__37732_10_ptr = ((__37726_47_name + __37733_8_length) - 3);
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*(__37732_10_ptr++))));
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*(__37732_10_ptr++))));
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*__37732_10_ptr)));
} else  {
auto int __37753_9_a;
for (__37753_9_a = 0; __37753_9_a < __37733_8_length; __37753_9_a++) {
__37731_16_hash_value = ((__37731_16_hash_value * 73U) + ((unsigned)(*(__37732_10_ptr++))));
}
}
return __37731_16_hash_value;
}


static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc( char *__37762_53_name)




{
auto unsigned __37768_17_hash_value;
auto a_pl_assignment_ptr __37769_23_ap;
auto int __37770_9_bucket_number;

__37768_17_hash_value = (_ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(__37762_53_name));
__37770_9_bucket_number = ((int)(__37768_17_hash_value % 599U));

for (__37769_23_ap = ((pl_assignment_table)[__37770_9_bucket_number]); __37769_23_ap != ((a_pl_assignment_ptr)0); __37769_23_ap = (__37769_23_ap->next)) {
if ((strcmp(((const char *)(__37769_23_ap->name)), ((const char *)__37762_53_name))) == 0) {
goto __T339541984;
}
} __T339541984:;
if (__37769_23_ap == ((a_pl_assignment_ptr)0)) {

__37769_23_ap = (_ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv());
(__37769_23_ap->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37762_53_name)));

(__37769_23_ap->next) = ((pl_assignment_table)[__37770_9_bucket_number]);
((pl_assignment_table)[__37770_9_bucket_number]) = __37769_23_ap;
}
return __37769_23_ap;
}


static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb( char *__37792_46_name, 
a_pl_symbol_ptr __37793_55_other_sym, 
_ZN3edg9a_booleanE __37794_22_add, 
_ZN3edg9a_booleanE *__37795_23_p_new)
#line 2006
{
auto unsigned __37803_24_hash_value;
auto a_pl_symbol_ptr __37804_26_prev_sym_ptr;
auto a_pl_symbol_ptr __37805_32_sym_ptr = ((a_pl_symbol_ptr)0);
auto int __37806_32_bucket_number;
auto _ZN3edg9a_booleanE __37807_21_is_new = ((_ZN3edg9a_booleanE)0);




if ((__37793_55_other_sym != ((a_pl_symbol_ptr)0)) && ((__37793_55_other_sym->global_sym) != ((a_pl_symbol_ptr)0))) {
__37805_32_sym_ptr = (__37793_55_other_sym->global_sym);
goto __37866_1_symbol_found;
}
__37803_24_hash_value = (_ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(__37792_46_name));


__37806_32_bucket_number = ((int)(__37803_24_hash_value % 10007U));
if ((__37805_32_sym_ptr = ((pl_symbol_table)[__37806_32_bucket_number])) != ((a_pl_symbol_ptr)0)) {
__37804_26_prev_sym_ptr = ((a_pl_symbol_ptr)0);
do {
if ((strcmp(((const char *)__37792_46_name), ((const char *)(__37805_32_sym_ptr->name)))) == 0) {



if (__37804_26_prev_sym_ptr != ((a_pl_symbol_ptr)0)) {
(__37804_26_prev_sym_ptr->next) = (__37805_32_sym_ptr->next);
(__37805_32_sym_ptr->next) = ((pl_symbol_table)[__37806_32_bucket_number]);
((pl_symbol_table)[__37806_32_bucket_number]) = __37805_32_sym_ptr;
}
goto __37866_1_symbol_found;
}
__37804_26_prev_sym_ptr = __37805_32_sym_ptr;
} while ((__37805_32_sym_ptr = (__37805_32_sym_ptr->next)) != ((a_pl_symbol_ptr)0));
}



if (__37794_22_add) {
__37805_32_sym_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());

(__37805_32_sym_ptr->next_in_symbol_table) = pl_symbol_table_head;
pl_symbol_table_head = __37805_32_sym_ptr;



(__37805_32_sym_ptr->next) = ((pl_symbol_table)[__37806_32_bucket_number]);
((pl_symbol_table)[__37806_32_bucket_number]) = __37805_32_sym_ptr;
(__37805_32_sym_ptr->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__37792_46_name)));
if (_ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc((__37805_32_sym_ptr->name))) {


(__37805_32_sym_ptr->is_specialization) = ((_ZN3edg14a_byte_booleanE)1);
(__37805_32_sym_ptr->next_in_specialization_list) = specialization_list;
specialization_list = __37805_32_sym_ptr;
}
#line 2067
__37807_21_is_new = ((_ZN3edg9a_booleanE)1);
}

__37866_1_symbol_found:;


if ((__37805_32_sym_ptr != ((a_pl_symbol_ptr)0)) && ((__37805_32_sym_ptr->primary_entry) != ((a_pl_symbol_ptr)0))) {
__37805_32_sym_ptr = (__37805_32_sym_ptr->primary_entry);
}
if (__37805_32_sym_ptr != ((a_pl_symbol_ptr)0)) {
if ((__37793_55_other_sym != ((a_pl_symbol_ptr)0)) && ((__37793_55_other_sym->global_sym) == ((a_pl_symbol_ptr)0))) {


(__37793_55_other_sym->global_sym) = __37805_32_sym_ptr;
}
}


if (__37795_23_p_new != ((_ZN3edg9a_booleanE *)0)) { (*__37795_23_p_new) = __37807_21_is_new; }
return __37805_32_sym_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv(void)
#line 2097
{
auto char *__37894_11_name;
auto int __37895_9_pos = 0;
auto a_pl_symbol_ptr __37896_19_sym;

for (; ; ) {
__37894_11_name = ((pl_predefined_names)[(__37895_9_pos++)]);
if (__37894_11_name == ((char *)0)) { goto __T339587688; }
__37896_19_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__37894_11_name, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__37896_19_sym->defined) = ((_ZN3edg14a_byte_booleanE)1);
} __T339587688:; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file( a_pl_object_file_ptr __37908_61_pofp, 
a_pl_input_file_ptr __37909_33_input_file)
#line 2123
{
auto a_pl_symbol_ptr __37920_19_psp;

__37920_19_psp = (__37908_61_pofp->symbols);
while (__37920_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __37924_21_sym;
auto _ZN3edg9a_booleanE __37925_16_is_special_symbol = ((_ZN3edg9a_booleanE)0);
if ((((int)((__37920_19_psp->name)[0])) == 95) && (((int)((__37920_19_psp->name)[1])) == 95)) {
if ((strncmp(((const char *)(__37920_19_psp->name)), ((const char *)"__TIR__"), 7ULL)) == 0)
{
#line 2141
__37925_16_is_special_symbol = ((_ZN3edg9a_booleanE)1);
__37924_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(((__37920_19_psp->name) + 7), __37920_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__37924_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
(__37924_21_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1);
} else  { if ((strncmp(((const char *)(__37920_19_psp->name)), ((const char *)"__DNI__"), 7ULL)) == 0)
{
#line 2155
__37925_16_is_special_symbol = ((_ZN3edg9a_booleanE)1);
__37924_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(((__37920_19_psp->name) + 7), __37920_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__37924_21_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1);
} else  { if ((!(__37909_33_input_file->is_archive)) && ((strncmp(((const char *)(__37920_19_psp->name)), ((const char *)"__CBI__"), 7ULL)) == 0))

{




__37925_16_is_special_symbol = ((_ZN3edg9a_booleanE)1);
__37924_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(((__37920_19_psp->name) + 7), __37920_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__37924_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
if (!(__37909_33_input_file->is_archive)) {
(__37924_21_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1);


_ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(__37924_21_sym, __37909_33_input_file);
}
} } }
}
if (!(__37925_16_is_special_symbol)) {


__37924_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb((__37920_19_psp->name), __37920_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));
if (__37920_19_psp->referenced) {
(__37924_21_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1);
}




if (__37920_19_psp->defined) {
if ((__37924_21_sym->defined) && ((__37924_21_sym->defined_in) != __37909_33_input_file)) {
(__37924_21_sym->multiple_definition) = ((_ZN3edg14a_byte_booleanE)1);
} else  {
(__37924_21_sym->defined_in) = __37909_33_input_file;
(__37924_21_sym->defined) = ((_ZN3edg14a_byte_booleanE)1);
}
}


if ((__37920_19_psp->template_sym) != ((a_pl_symbol_ptr)0)) { (__37924_21_sym->template_sym) = (__37920_19_psp->template_sym); }


if (__37920_19_psp->do_not_instantiate) { (__37924_21_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1); }
if (__37920_19_psp->is_template) { (__37924_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1); }
if ((__37920_19_psp->can_be_instantiated) || (((__37924_21_sym->template_sym) != ((a_pl_symbol_ptr)0)) && ((__37924_21_sym->template_sym)->defined)))
{
(__37924_21_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1);
#line 2212
_ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(__37924_21_sym, __37909_33_input_file);
}
(__37924_21_sym->tentative_definition) = ((_ZN3edg14a_byte_booleanE)((((int)(__37924_21_sym->tentative_definition)) | ((int)(__37920_19_psp->tentative_definition))) != 0));
}
__37920_19_psp = (__37920_19_psp->next);
}
(__37908_61_pofp->included_in_output) = ((_ZN3edg14a_byte_booleanE)1); 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file( a_pl_object_file_ptr __38018_65_pofp)




{
auto a_pl_symbol_ptr __38024_19_psp;
auto _ZN3edg9a_booleanE __38025_14_result = ((_ZN3edg9a_booleanE)0);

__38024_19_psp = (__38018_65_pofp->symbols);
while (__38024_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __38029_21_sym;
if ((__38024_19_psp->defined) || (__38024_19_psp->tentative_definition)) {

__38029_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb((__38024_19_psp->name), __38024_19_psp, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));
if (!(__38029_21_sym->defined)) {



if ((__38029_21_sym->referenced) || ((__38029_21_sym->tentative_definition) && (__38024_19_psp->defined)))
{
__38025_14_result = ((_ZN3edg9a_booleanE)1);
goto __T339666016;
}
#line 2253
(__38029_21_sym->definition_seen_in_archive) = ((_ZN3edg14a_byte_booleanE)1);
}
}
__38024_19_psp = (__38024_19_psp->next);
} __T339666016:;
return __38025_14_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv(void)




{
auto a_pl_input_file_ptr __38064_23_pifp;

__38064_23_pifp = pl_input_files;
while (__38064_23_pifp != ((a_pl_input_file_ptr)0)) {
auto a_pl_object_file_ptr __38068_26_pofp;
auto _ZN3edg9a_booleanE __38069_17_file_used_from_archive = ((_ZN3edg9a_booleanE)0);
__38068_26_pofp = (__38064_23_pifp->objects);
if (!(__38064_23_pifp->is_archive)) {
if (__38068_26_pofp != ((a_pl_object_file_ptr)0)) {




for (; __38068_26_pofp != ((a_pl_object_file_ptr)0); __38068_26_pofp = (__38068_26_pofp->next)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(__38068_26_pofp, __38064_23_pifp);
}
}
} else  {
while (__38068_26_pofp != ((a_pl_object_file_ptr)0)) {
if (!(__38068_26_pofp->included_in_output)) {



if (_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file(__38068_26_pofp)) {



_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(__38068_26_pofp, __38064_23_pifp);
__38069_17_file_used_from_archive = ((_ZN3edg9a_booleanE)1);
}
}
__38068_26_pofp = (__38068_26_pofp->next);
}
}




if (!(__38069_17_file_used_from_archive)) { __38064_23_pifp = (__38064_23_pifp->next); }
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(void)




{
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_corrupted_template_info_file, ((char *)0)); 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc( char *__38117_35_name)




{
auto char *__38123_9_last_dot;

__38123_9_last_dot = (strrchr(((const char *)__38117_35_name), 46));
return __38123_9_last_dot;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_( _ZN3edg12a_const_charE *__38130_44_name, 
_ZN3edg12a_const_charE *__38131_23_suffix)
#line 2343
{
auto char *__38140_11_last_dot;
#line 2351
((pl_file_name_buffer)[0]) = ((char)0);
strncat(pl_file_name_buffer, __38130_44_name, 4085ULL);

__38140_11_last_dot = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc(pl_file_name_buffer));
if (__38140_11_last_dot == ((char *)0)) {

__38140_11_last_dot = ((pl_file_name_buffer) + (strlen(((const char *)pl_file_name_buffer))));
}

(*__38140_11_last_dot) = ((char)0);
strncat(__38140_11_last_dot, __38131_23_suffix, 10ULL);
return pl_file_name_buffer;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file( a_pl_input_file_ptr __38162_60_pifp)
#line 2373
{
auto _ZN3edg8sizeof_tE __38170_13_instantiation_dir_length = 0ULL;
auto _ZN3edg8sizeof_tE __38171_13_compilation_dir_length = 0ULL;
auto _ZN3edg8sizeof_tE __38172_13_instantiation_suffix_length;
auto _ZN3edg8sizeof_tE __38173_13_extra_space;
auto FILE *__38174_11_f_template_info = ((FILE *)0);
auto _ZN3edg9a_booleanE __38175_14_instantiation_dir_set = ((_ZN3edg9a_booleanE)0);
auto a_pl_object_file_ptr __38176_24_pofp;
auto a_pl_symbol_ptr __38177_19_last_primary_entry = ((a_pl_symbol_ptr)0);

if ((__38162_60_pifp->template_info_file_name) != ((char *)0)) {
__38174_11_f_template_info = (fopen(((const char *)(__38162_60_pifp->template_info_file_name)), ((const char *)"r")));
}
if (__38174_11_f_template_info != ((FILE *)0)) {


__38176_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__38176_24_pofp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__38162_60_pifp->file_name))));
__38172_13_instantiation_suffix_length = 6ULL;
while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__38174_11_f_template_info)) {
auto char *__38189_14_line_type = pl_input_line;
auto char *__38190_14_info;
auto a_pl_symbol_ptr __38191_23_sym;
#line 2394
__38190_14_info = (__38189_14_line_type + 4);


if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"flg:"), 4ULL)) == 0) {
#line 2403
auto char *__38199_15_flag_pos;
__38199_15_flag_pos = (strchr(((const char *)__38190_14_info), 58));
if (__38199_15_flag_pos == ((char *)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }

(*(__38199_15_flag_pos++)) = ((char)0);
__38191_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());
(__38191_23_sym->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38190_14_info)));
for (; (((int)(*__38199_15_flag_pos)) != 0) && (((int)(*__38199_15_flag_pos)) != 58); __38199_15_flag_pos++) {
switch ((int)(*__38199_15_flag_pos)) {
case 67:
(__38191_23_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1);
(__38191_23_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
goto __T339733640;
case 68:
(__38191_23_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1);
goto __T339733640;
case 84:
(__38191_23_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1);
(__38191_23_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1);
goto __T339733640;
default:
_ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv();
} __T339733640:; ;
}

if (((int)(*__38199_15_flag_pos)) == 58) {
auto char *__38225_17_name_pos; __38225_17_name_pos = (__38199_15_flag_pos + 1);
(__38191_23_sym->template_sym) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__38225_17_name_pos, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

}
(__38191_23_sym->next) = (__38176_24_pofp->symbols);
(__38176_24_pofp->symbols) = __38191_23_sym;


__38177_19_last_primary_entry = __38191_23_sym;
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"ent:"), 4ULL)) == 0) {


auto char *__38237_15_name_pos;
auto a_pl_symbol_ptr __38238_25_global_for_last_primary;
#line 2441
__38237_15_name_pos = (__38189_14_line_type + 4);

if (__38177_19_last_primary_entry == ((a_pl_symbol_ptr)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__38191_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__38237_15_name_pos, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

__38238_25_global_for_last_primary = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb((__38177_19_last_primary_entry->name), __38177_19_last_primary_entry, ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));



(__38191_23_sym->primary_entry) = __38238_25_global_for_last_primary;
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"tnm:"), 4ULL)) == 0) {

auto char *__38249_15_name_pos; __38249_15_name_pos = (__38189_14_line_type + 4);
__38191_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__38249_15_name_pos, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

(__38191_23_sym->defined) = ((_ZN3edg14a_byte_booleanE)1);
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"ifn:"), 4ULL)) == 0) {
#line 2463
auto a_pl_object_file_ptr __38259_30_i_pofp;
auto _ZN3edg9a_booleanE __38260_20_add_compilation_dir = ((_ZN3edg9a_booleanE)0);
#line 2481
auto size_t __38277_16_file_name_size;
#line 2465
__38173_13_extra_space = 3ULL;
if (!(__38175_14_instantiation_dir_set)) {


(__38162_60_pifp->instantiation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((const char *)"Template.dir")));
__38170_13_instantiation_dir_length = (strlen(((const char *)(__38162_60_pifp->instantiation_directory))));
__38175_14_instantiation_dir_set = ((_ZN3edg9a_booleanE)1);
}
if ((!(__38162_60_pifp->is_local_file)) && (!(_ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc((__38162_60_pifp->instantiation_directory)))))
{



__38260_20_add_compilation_dir = ((_ZN3edg9a_booleanE)1);
}
__38259_30_i_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
__38277_16_file_name_size = (((((strlen(((const char *)__38190_14_info))) + __38170_13_instantiation_dir_length) + __38172_13_instantiation_suffix_length) + ((__38260_20_add_compilation_dir) ? __38171_13_compilation_dir_length : 0ULL)) + __38173_13_extra_space);
#line 2487
(__38259_30_i_pofp->file_name) = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(__38277_16_file_name_size)));

snprintf((__38259_30_i_pofp->file_name), __38277_16_file_name_size, ((const char *)"%s%s%s/%s%s"), ((__38260_20_add_compilation_dir) ? ((const char *)(__38162_60_pifp->compilation_directory)) : ((const char *)"")), ((__38260_20_add_compilation_dir) ? ((const char *)("/")) : ((const char *)(""))), (
#line 2489
__38162_60_pifp->instantiation_directory), __38190_14_info, ((const char *)(".int.o")));




(__38259_30_i_pofp->next) = (__38162_60_pifp->objects);
(__38259_30_i_pofp->is_related_file) = ((_ZN3edg14a_byte_booleanE)1);
(__38162_60_pifp->objects) = __38259_30_i_pofp;
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"dep:"), 4ULL)) == 0) {


auto a_pl_file_list_entry_ptr __38296_34_flep;
__38296_34_flep = (_ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv());
(__38296_34_flep->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38190_14_info)));
(__38296_34_flep->next) = (__38162_60_pifp->dependencies);
(__38162_60_pifp->dependencies) = __38296_34_flep;
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"cmd:"), 4ULL)) == 0) {

(__38162_60_pifp->command_line) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38190_14_info)));
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"dir:"), 4ULL)) == 0) {

(__38162_60_pifp->compilation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38190_14_info)));

(__38162_60_pifp->is_local_file) = ((_Bool)((strcmp(((const char *)(__38162_60_pifp->compilation_directory)), ((const char *)curr_dir_name))) == 0));

__38171_13_compilation_dir_length = (strlen(((const char *)(__38162_60_pifp->compilation_directory))));
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"fnm:"), 4ULL)) == 0) {

(__38162_60_pifp->compilation_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38190_14_info)));
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"stu:"), 4ULL)) == 0) {


(__38162_60_pifp->secondary_files) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38190_14_info)));
} else  { if ((strncmp(((const char *)__38189_14_line_type), ((const char *)"idn:"), 4ULL)) == 0) {


if (__38175_14_instantiation_dir_set) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"instantiation_dir already set"));
}
(__38162_60_pifp->instantiation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__38190_14_info)));
__38170_13_instantiation_dir_length = (strlen(((const char *)(__38162_60_pifp->instantiation_directory))));
__38175_14_instantiation_dir_set = ((_ZN3edg9a_booleanE)1);
} else  {
_ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv();
} } } } } } } } } }
}
fclose(__38174_11_f_template_info);


(__38176_24_pofp->next) = (__38162_60_pifp->objects);
(__38162_60_pifp->objects) = __38176_24_pofp;
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(
a_pl_input_file_ptr __38341_26_pifp, 
FILE *__38342_14_f_request)



{
auto int __38347_7_i;

for (__38347_7_i = 0; __38347_7_i < reserved_request_file_lines; ++__38347_7_i) {
_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__38342_14_f_request);
(((__38341_26_pifp->reserved_lines))[__38347_7_i]) = ((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_input_line))));
}



if (reserved_request_file_lines >= 1) {
(__38341_26_pifp->command_line) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc((((__38341_26_pifp->reserved_lines))[0])));
}
if (!(use_template_info_file)) {
#line 2579
}



for (; __38347_7_i < 0; ++__38347_7_i) {
(((__38341_26_pifp->reserved_lines))[__38347_7_i]) = ((const char *)"");
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv(void)




{
auto a_pl_input_file_ptr __38391_23_pifp;
auto FILE *__38392_11_f_request;

__38391_23_pifp = pl_input_files;
while (__38391_23_pifp != ((a_pl_input_file_ptr)0)) {
if ((!(__38391_23_pifp->is_archive)) && ((__38391_23_pifp->request_file_name) != ((char *)0))) {
__38392_11_f_request = (fopen(((const char *)(__38391_23_pifp->request_file_name)), ((const char *)"r")));
#line 2608
if (__38392_11_f_request != ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(__38391_23_pifp, __38392_11_f_request);

while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__38392_11_f_request)) {
auto a_pl_symbol_ptr __38408_27_sym;
__38408_27_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(pl_input_line, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), ((_ZN3edg9a_booleanE *)0)));

if ((__38408_27_sym->instantiation_file) != ((a_pl_input_file_ptr)0)) {


fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_error)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_multiple_assignments)), (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__38408_27_sym->name))), (__38391_23_pifp->file_name), ((__38408_27_sym->instantiation_file)->file_name));


_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_bad_instantiation_request_file, ((char *)0));
}
(__38408_27_sym->instantiation_file) = __38391_23_pifp;


(__38408_27_sym->next_in_request_file) = (__38391_23_pifp->request_list);
(__38391_23_pifp->request_list) = __38408_27_sym;
}
fclose(__38392_11_f_request);
}
}
__38391_23_pifp = (__38391_23_pifp->next);
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(
a_pl_input_file_ptr __38435_24_pifp, 
char **__38436_13_request_file_name, 
char **__38437_13_template_info_file_name)




{
auto char *__38443_11_suffix;

(*__38436_13_request_file_name) = ((char *)0);
(*__38437_13_template_info_file_name) = ((char *)0);
__38443_11_suffix = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc((__38435_24_pifp->file_name)));
if ((__38443_11_suffix != ((char *)0)) && ((strcmp(((const char *)__38443_11_suffix), ((const char *)".o"))) == 0)) {


(*__38436_13_request_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(((_ZN3edg12a_const_charE *)(__38435_24_pifp->file_name)), ((const char *)".ii"))))));

if ((use_template_info_file) && ((*__38436_13_request_file_name) != ((char *)0))) {
(*__38437_13_template_info_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(((_ZN3edg12a_const_charE *)(__38435_24_pifp->file_name)), ((const char *)".ti"))))));

}
} 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file( a_pl_input_file_ptr __38461_65_pifp)




{
auto FILE *__38467_11_f_test = ((FILE *)0);
auto char *__38468_11_request_file_name;
auto char *__38469_11_template_info_file_name;
auto char *__38470_11_file_to_test;


_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(__38461_65_pifp, (&__38468_11_request_file_name), (&__38469_11_template_info_file_name));



if (__38468_11_request_file_name != ((char *)0)) {


__38470_11_file_to_test = ((use_template_info_file) ? __38469_11_template_info_file_name : __38468_11_request_file_name);

__38467_11_f_test = (fopen(((const char *)__38470_11_file_to_test), ((const char *)"r")));
if (__38467_11_f_test != ((FILE *)0)) {
fclose(__38467_11_f_test);
(__38461_65_pifp->request_file_name) = __38468_11_request_file_name;
(__38461_65_pifp->template_info_file_name) = __38469_11_template_info_file_name;
} else  {
free(((void *)__38468_11_request_file_name));
if (use_template_info_file) { free(((void *)__38469_11_template_info_file_name)); }
}
}
return (_Bool)(__38467_11_f_test != ((FILE *)0));
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol( a_pl_input_file_ptr __38496_57_pifp, 
a_pl_symbol_ptr __38497_22_psp)




{
auto a_pl_instantiation_site_ptr __38503_31_pisp;
auto _ZN3edg9a_booleanE __38504_15_result = ((_ZN3edg9a_booleanE)0);

__38503_31_pisp = (__38497_22_psp->possible_instantiation_sites);
while (__38503_31_pisp != ((a_pl_instantiation_site_ptr)0)) {
if ((__38503_31_pisp->input_file) == __38496_57_pifp) {
__38504_15_result = ((_ZN3edg9a_booleanE)1);
goto __T339882176;
}
__38503_31_pisp = (__38503_31_pisp->next);
} __T339882176:;
return __38504_15_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc( char *__38518_37_name)
#line 2730
{
auto a_pl_assignment_ptr __38527_23_ap;

__38527_23_ap = (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc(__38518_37_name));




if ((__38527_23_ap->times_assigned) > 3) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"instantiation loop"));
}
(__38527_23_ap->times_assigned)++; 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file( a_pl_input_file_ptr __38541_60_pifp)
#line 2751
{
auto _ZN3edg9a_booleanE __38548_15_result = ((_ZN3edg9a_booleanE)0);
auto a_pl_object_file_ptr __38549_25_pofp;
auto a_pl_file_list_entry_ptr __38550_28_flep;
#line 2753
__38549_25_pofp = (__38541_60_pifp->objects);



if (__38549_25_pofp == ((a_pl_object_file_ptr)0)) {
goto __38579_1_done;
} else  { if ((__38549_25_pofp->modification_time) == 0LL) {


if (!(_ZN3edg26get_file_modification_timeEPKcPx(((_ZN3edg12a_const_charE *)(__38549_25_pofp->file_name)), (&(__38549_25_pofp->modification_time)))))
{


goto __38579_1_done;
}
} }
for (__38550_28_flep = (__38541_60_pifp->dependencies); __38550_28_flep != ((a_pl_file_list_entry_ptr)0); __38550_28_flep = (__38550_28_flep->next)) {
auto time_t __38566_12_dep_time;
if (_ZN3edg26get_file_modification_timeEPKcPx(((_ZN3edg12a_const_charE *)(__38550_28_flep->name)), (&__38566_12_dep_time))) {
if (__38566_12_dep_time > (__38549_25_pofp->modification_time)) {

__38548_15_result = ((_ZN3edg9a_booleanE)1);
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_out_of_date)), message_prefix, (__38541_60_pifp->file_name), (__38550_28_flep->name));

}
goto __T339902888;
}
}
} __T339902888:;
__38579_1_done:;
return __38548_15_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEb( _ZN3edg9a_booleanE __38584_49_do_local_files)
#line 2799
{
auto a_pl_input_file_ptr __38596_23_pifp;
auto _ZN3edg9a_booleanE __38597_14_done = ((_ZN3edg9a_booleanE)1);

for (__38596_23_pifp = pl_input_files; __38596_23_pifp != ((a_pl_input_file_ptr)0); __38596_23_pifp = (__38596_23_pifp->next)) { {

if (((int)(__38596_23_pifp->is_local_file)) != ((int)__38584_49_do_local_files)) { goto __T339909480; }

if ((__38596_23_pifp->objects) == ((a_pl_object_file_ptr)0)) { goto __T339909480; }
if (!(__38596_23_pifp->is_archive)) {
auto a_pl_symbol_ptr __38605_23_psp;
auto a_pl_symbol_ptr __38606_23_prev_psp;


if ((((__38596_23_pifp->dependencies) != ((a_pl_file_list_entry_ptr)0)) && (!(suppress_dependency_checking))) && (_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file(__38596_23_pifp)))

{


(__38596_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1);
(__38596_23_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)1);
__38597_14_done = ((_ZN3edg9a_booleanE)0);
}


__38605_23_psp = (__38596_23_pifp->request_list);
__38606_23_prev_psp = ((a_pl_symbol_ptr)0);
while (__38605_23_psp != ((a_pl_symbol_ptr)0)) {
auto _ZN3edg9a_booleanE __38623_20_remove_from_request_file = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __38624_20_recompile_file = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __38625_20_remove_one_inst_per_obj_file = ((_ZN3edg9a_booleanE)0);
if ((__38605_23_psp->multiple_definition) || (__38605_23_psp->do_not_instantiate)) {
#line 2837
__38623_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);
__38624_20_recompile_file = ((_ZN3edg9a_booleanE)1);
} else  { if (((__38605_23_psp->defined_in) == ((a_pl_input_file_ptr)0)) || ((__38605_23_psp->defined_in) != __38596_23_pifp))
{
#line 2849
__38623_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);


__38625_20_remove_one_inst_per_obj_file = ((_Bool)((__38605_23_psp->defined_in) == ((a_pl_input_file_ptr)0)));
__38624_20_recompile_file = ((_ZN3edg9a_booleanE)1);
} else  { if (!(__38605_23_psp->is_template)) {


__38623_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);
__38624_20_recompile_file = ((_ZN3edg9a_booleanE)1);
} else  { if (!(__38605_23_psp->referenced)) {
#line 2866
__38623_20_remove_from_request_file = ((_ZN3edg9a_booleanE)1);
__38624_20_recompile_file = ((_ZN3edg9a_booleanE)1);
__38625_20_remove_one_inst_per_obj_file = ((_ZN3edg9a_booleanE)1);
} else  {

(__38605_23_psp->instantiated) = ((_ZN3edg14a_byte_booleanE)1);
} } } }
if (__38623_20_remove_from_request_file) {
#line 2880
if (__38606_23_prev_psp != ((a_pl_symbol_ptr)0)) {
(__38606_23_prev_psp->next_in_request_file) = (__38605_23_psp->next_in_request_file);
} else  {
(__38596_23_pifp->request_list) = (__38605_23_psp->next_in_request_file);
}
(__38605_23_psp->instantiation_file) = ((a_pl_input_file_ptr)0);
(__38596_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1);
(__38596_23_pifp->recompile) = __38624_20_recompile_file;
__38597_14_done = ((_ZN3edg9a_booleanE)0);




if ((one_instantiation_per_object) && (__38625_20_remove_one_inst_per_obj_file))
{



snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"%s/%s%s"), (__38596_23_pifp->instantiation_directory), (_ZN3edg39generate_instantiation_output_file_nameEPKc(((_ZN3edg12a_const_charE *)(__38605_23_psp->name)))), ((const char *)(".int.o")));




unlink(((const char *)pl_file_name_buffer));
}

if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_no_longer_needed)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__38605_23_psp->name))), (__38596_23_pifp->file_name));


}
}


if (!(__38623_20_remove_from_request_file)) { __38606_23_prev_psp = __38605_23_psp; }
__38605_23_psp = (__38605_23_psp->next_in_request_file);
}



__38605_23_psp = ((__38596_23_pifp->objects)->symbols);
while (__38605_23_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __38718_25_sym; __38718_25_sym = (__38605_23_psp->global_sym);
#line 2932
if (((((((((__38718_25_sym != ((a_pl_symbol_ptr)0)) && (__38718_25_sym->is_template)) && (!(__38718_25_sym->instantiated))) && (!(__38718_25_sym->do_not_instantiate))) && (__38718_25_sym->can_be_instantiated)) && ((__38718_25_sym->referenced) || (__38718_25_sym->tentative_definition))) && (!(
#line 2932
__38718_25_sym->defined))) && (!(__38718_25_sym->definition_seen_in_archive))) && (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol(__38596_23_pifp, __38718_25_sym)))




{




(__38718_25_sym->next_in_request_file) = (__38596_23_pifp->request_list);
(__38596_23_pifp->request_list) = __38718_25_sym;
(__38718_25_sym->instantiated) = ((_ZN3edg14a_byte_booleanE)1);
(__38596_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1);
(__38596_23_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)1);
__38597_14_done = ((_ZN3edg9a_booleanE)0);


_ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc((__38718_25_sym->name));
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_assigned_to_file)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__38718_25_sym->name))), (__38596_23_pifp->file_name));


}
}
__38605_23_psp = (__38605_23_psp->next);
}
}



if ((__38596_23_pifp->recompile) && (use_definition_list)) { goto __T339978024; }
} __T339909480:; } __T339978024:;
return __38597_14_done;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc( char *__38765_39_new_dir)


{
#line 2978
if ((chdir(((const char *)__38765_39_new_dir))) != 0) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_chdir, __38765_39_new_dir);
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc( char **__38780_48_dest, 
_ZN3edg12a_const_charE *__38781_19_source)
#line 2992
{
auto _ZN3edg12a_const_charE *__38789_17_from;
auto char *__38790_10_to;
auto _ZN3edg9a_booleanE __38791_13_in_quote = ((_ZN3edg9a_booleanE)0);
auto char __38792_9_quote_char = ((char)0);
auto _ZN3edg9a_booleanE __38793_13_is_escaped = ((_ZN3edg9a_booleanE)0);
auto char __38794_9_outer_quote = ((char)0);
#line 2994
__38790_10_to = (*__38780_48_dest);
#line 3000
for (__38789_17_from = __38781_19_source; ((int)(*__38789_17_from)) != 0; ++__38789_17_from) {
auto char __38797_10_ch;
auto _ZN3edg9a_booleanE __38798_15_is_close_quote = ((_ZN3edg9a_booleanE)0);
#line 3001
__38797_10_ch = (*__38789_17_from);

if (__38793_13_is_escaped) {
__38793_13_is_escaped = ((_ZN3edg9a_booleanE)0);
} else  { if (((int)__38797_10_ch) == 92) {
__38793_13_is_escaped = ((_ZN3edg9a_booleanE)1);
} else  { if ((!(__38791_13_in_quote)) && ((((int)__38797_10_ch) == 34) || (((int)__38797_10_ch) == 39))) {
__38791_13_in_quote = ((_ZN3edg9a_booleanE)1);
__38792_9_quote_char = __38797_10_ch;
__38794_9_outer_quote = ((((int)__38797_10_ch) == 34) ? ((char)39) : ((char)34));
(*(__38790_10_to++)) = __38794_9_outer_quote;
} else  { if ((__38791_13_in_quote) && (((int)__38797_10_ch) == ((int)__38792_9_quote_char))) {
__38798_15_is_close_quote = ((_ZN3edg9a_booleanE)1);
} else  { if (((__38791_13_in_quote) && (((int)__38797_10_ch) == ((int)__38792_9_quote_char))) || ((!(__38791_13_in_quote)) && ((((int)__38797_10_ch) == 40) || (((int)__38797_10_ch) == 41))))
{
(*(__38790_10_to++)) = ((char)92);
} } } } }
(*(__38790_10_to++)) = __38797_10_ch;
if (__38798_15_is_close_quote) {
__38791_13_in_quote = ((_ZN3edg9a_booleanE)0);
(*(__38790_10_to++)) = __38794_9_outer_quote;
}
}

if (((int)(*(__38790_10_to - 1))) != 32) { (*(__38790_10_to++)) = ((char)32); }
(*__38780_48_dest) = __38790_10_to; 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_( _ZN3edg12a_const_charE *__38826_47_part1, 
_ZN3edg12a_const_charE *__38827_47_part2, 
_ZN3edg12a_const_charE *__38828_47_part3, 
_ZN3edg12a_const_charE *__38829_19_part4)
#line 3040
{
auto char *__38837_10_to;
auto _ZN3edg8sizeof_tE __38838_12_length;
auto char *__38839_10_command;



if (__38827_47_part2 == ((_ZN3edg12a_const_charE *)0)) { __38827_47_part2 = ((const char *)""); }
if (__38828_47_part3 == ((_ZN3edg12a_const_charE *)0)) { __38828_47_part3 = ((const char *)""); }
if (__38829_19_part4 == ((_ZN3edg12a_const_charE *)0)) { __38829_19_part4 = ((const char *)""); }
if (__38826_47_part1 == ((_ZN3edg12a_const_charE *)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__38838_12_length = (((((strlen(__38826_47_part1)) + (strlen(__38827_47_part2))) + (strlen(__38828_47_part3))) + (strlen(__38829_19_part4))) * 2ULL);
if (__38838_12_length <= 3ULL) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__38839_10_command = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(__38838_12_length)));
__38837_10_to = __38839_10_command;
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38837_10_to), __38826_47_part1);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38837_10_to), __38827_47_part2);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38837_10_to), __38828_47_part3);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__38837_10_to), __38829_19_part4);

(*(__38837_10_to - 1)) = ((char)0);
return __38839_10_command;
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_( a_pl_input_file_ptr __38861_50_pifp, 
_ZN3edg12a_const_charE *__38862_45_extra_command_args, 
_ZN3edg12a_const_charE *__38863_24_extra_args_for_display)
#line 3074
{
auto char *__38871_10_command;
auto char *__38872_10_display_command;
auto int __38873_8_result;
auto _ZN3edg9a_booleanE __38874_13_chdir_needed;




__38874_13_chdir_needed = ((_Bool)(((__38861_50_pifp->compilation_directory) != ((char *)0)) && ((strcmp(((const char *)(__38861_50_pifp->compilation_directory)), ((const char *)curr_dir_name))) != 0)));

if (__38874_13_chdir_needed) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc((__38861_50_pifp->compilation_directory));
}
__38871_10_command = (_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(((_ZN3edg12a_const_charE *)(__38861_50_pifp->command_line)), __38862_45_extra_command_args, ((_ZN3edg12a_const_charE *)(__38861_50_pifp->compilation_file_name)), ((_ZN3edg12a_const_charE *)(
#line 3089
__38861_50_pifp->secondary_files))));


if (__38863_24_extra_args_for_display != ((_ZN3edg12a_const_charE *)0)) {



__38872_10_display_command = (_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(((_ZN3edg12a_const_charE *)(__38861_50_pifp->command_line)), __38863_24_extra_args_for_display, ((_ZN3edg12a_const_charE *)(__38861_50_pifp->compilation_file_name)), ((_ZN3edg12a_const_charE *)(
#line 3096
__38861_50_pifp->secondary_files))));



} else  {
__38872_10_display_command = __38871_10_command;
}
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_executing)), message_prefix, __38872_10_display_command);

fflush(f_informational);
__38873_8_result = (system(((const char *)__38871_10_command)));



if (__38873_8_result == (-1)) {
__38873_8_result = (*_errnoloc);
} else  {
__38873_8_result = (__38873_8_result >> 8);
}
if (__38872_10_display_command != __38871_10_command) { free(((void *)__38872_10_display_command)); }
free(((void *)__38871_10_command));
if (__38874_13_chdir_needed) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc(curr_dir_name);
}
return __38873_8_result;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc( char *__38921_39_file_name)




{
auto char *__38927_9_ptr;

__38927_9_ptr = (strrchr(((const char *)__38921_39_file_name), 47));
#line 3144
return __38927_9_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file( a_pl_input_file_ptr __38944_63_pifp)
#line 3158
{
auto char *__38955_10_orig_file_name;
auto char *__38956_10_orig_request_file_name;
auto char *__38957_10_orig_template_info_file_name;
auto char *__38958_10_ptr;


__38955_10_orig_file_name = (__38944_63_pifp->file_name);
__38958_10_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc((__38944_63_pifp->file_name)));
if (__38958_10_ptr == ((char *)0)) {
fprintf(stderr, ((const char *)"Expected %s to include a directory name\n"), (__38944_63_pifp->file_name));

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Directory name missing"));
}
if ((__38944_63_pifp->secondary_files) != ((char *)0)) {


_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"copy if nonlocal cannot be used with secondary trans units"));

}
(__38944_63_pifp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__38958_10_ptr + 1))));
__38956_10_orig_request_file_name = (__38944_63_pifp->request_file_name);
__38957_10_orig_template_info_file_name = (__38944_63_pifp->template_info_file_name);




_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(__38944_63_pifp, (&(__38944_63_pifp->request_file_name)), (&(__38944_63_pifp->template_info_file_name)));




if (_ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc((__38944_63_pifp->compilation_file_name))) {

} else  {


snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"%s/%s"), (__38944_63_pifp->compilation_directory), (__38944_63_pifp->compilation_file_name));

free(((void *)(__38944_63_pifp->compilation_file_name)));
(__38944_63_pifp->compilation_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}

free(((void *)(__38944_63_pifp->compilation_directory)));
(__38944_63_pifp->compilation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)curr_dir_name)));
#line 3215
free(((void *)__38955_10_orig_file_name));
free(((void *)__38956_10_orig_request_file_name));
if (__38957_10_orig_template_info_file_name != ((char *)0)) { free(((void *)__38957_10_orig_template_info_file_name)); }
if (!(use_template_info_file)) {


(((__38944_63_pifp->reserved_lines))[0]) = ((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__38944_63_pifp->command_line)))));
#line 3228
}

(__38944_63_pifp->is_local_file) = ((_ZN3edg14a_byte_booleanE)1); 
}


static FILE *_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv(void)
#line 3240
{
auto FILE *__39037_10_f_temp;
auto _ZN3edg12a_const_charE *__39038_17_tmpdir;

if (temporary_file_name == ((char *)0)) {

__39038_17_tmpdir = ((_ZN3edg12a_const_charE *)(getenv(((const char *)"TMPDIR"))));
if (__39038_17_tmpdir == ((_ZN3edg12a_const_charE *)0)) {



__39038_17_tmpdir = ((const char *)"/tmp");

}
snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"%s/%0dpltf"), __39038_17_tmpdir, (getpid()));

temporary_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}
__39037_10_f_temp = (fopen(((const char *)temporary_file_name), ((const char *)"w")));
if (__39037_10_f_temp == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_temporary_file, temporary_file_name);
}
return __39037_10_f_temp;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv(void)
#line 3274
{

auto FILE *__39072_11_f_temp;
auto a_pl_input_file_ptr __39073_23_pifp;
auto a_pl_object_file_ptr __39074_24_pofp;
auto a_pl_symbol_ptr __39075_19_psp;

__39072_11_f_temp = (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv());
for (__39073_23_pifp = pl_input_files; __39073_23_pifp != ((a_pl_input_file_ptr)0); __39073_23_pifp = (__39073_23_pifp->next)) {
for (__39074_24_pofp = (__39073_23_pifp->objects); __39074_24_pofp != ((a_pl_object_file_ptr)0); __39074_24_pofp = (__39074_24_pofp->next)) {
for (__39075_19_psp = (__39074_24_pofp->symbols); __39075_19_psp != ((a_pl_symbol_ptr)0); __39075_19_psp = (__39075_19_psp->next)) {
if (__39075_19_psp->defined) {
fputs(((const char *)(__39075_19_psp->name)), __39072_11_f_temp);
fputs(((const char *)"\n"), __39072_11_f_temp);
}
}
}
}
fclose(__39072_11_f_temp);
if (_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option == ((char *)0)) {



snprintf(pl_file_name_buffer, 4096ULL, ((const char *)"--definition_list_file=%s"), temporary_file_name);

_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}
return _ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file( a_pl_input_file_ptr __39101_69_pifp)
#line 3311
{
auto FILE *__39108_9_f_request;
auto FILE *__39109_9_f_temp;

__39109_9_f_temp = (fopen(((const char *)temporary_file_name), ((const char *)"r")));
if (__39109_9_f_temp != ((FILE *)0)) {




if ((_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__39109_9_f_temp)) && ((strcmp(((const char *)pl_input_line), ((const char *)":add:"))) == 0)) {

__39108_9_f_request = (fopen(((const char *)(__39101_69_pifp->request_file_name)), ((const char *)"a")));
if (__39108_9_f_request == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_file_for_update, (__39101_69_pifp->request_file_name));
}
while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__39109_9_f_temp)) {
fputs(((const char *)pl_input_line), __39108_9_f_request);
fputs(((const char *)"\n"), __39108_9_f_request);


_ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc(pl_input_line);
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_adopted_by_file)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(pl_input_line)), (__39101_69_pifp->file_name));


}
}
fclose(__39108_9_f_request);
}
fclose(__39109_9_f_temp);
} 
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv(void)




{

auto a_pl_input_file_ptr __39149_24_pifp;
auto int __39150_10_return_status = 0;
auto int __39151_10_i;

__39149_24_pifp = pl_input_files;
while (__39149_24_pifp != ((a_pl_input_file_ptr)0)) {
if (__39149_24_pifp->request_file_updated) {
auto a_pl_symbol_ptr __39156_23_psp;
auto FILE *__39157_14_f_request;

if ((__39149_24_pifp->request_file_name) == ((char *)0)) {
fprintf(stderr, ((const char *)"Input file %s has instantiations but no instantiation request file.\n"), (__39149_24_pifp->file_name));


_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Instantiation request file is missing"));
}
if ((move_nonlocal_objects_to_curr_dir) && (!(__39149_24_pifp->is_local_file))) {



_ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file(__39149_24_pifp);
}

__39157_14_f_request = (fopen(((const char *)(__39149_24_pifp->request_file_name)), ((const char *)"w")));
if (__39157_14_f_request == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_file_for_update, (__39149_24_pifp->request_file_name));
}

for (__39151_10_i = 0; __39151_10_i < reserved_request_file_lines; ++__39151_10_i) {
fprintf(__39157_14_f_request, ((const char *)"%s\n"), (((__39149_24_pifp->reserved_lines))[__39151_10_i]));
}

__39156_23_psp = (__39149_24_pifp->request_list);
while (__39156_23_psp != ((a_pl_symbol_ptr)0)) {
fprintf(__39157_14_f_request, ((const char *)"%s\n"), (__39156_23_psp->name));
__39156_23_psp = (__39156_23_psp->next_in_request_file);
}
fclose(__39157_14_f_request);
if ((!(suppress_compilation)) && (__39149_24_pifp->recompile)) {
auto char *__39188_23_definition_list_option = ((char *)0);
auto _ZN3edg12a_const_charE *__39189_23_def_list_display_option = ((_ZN3edg12a_const_charE *)0);

unlink(((const char *)(__39149_24_pifp->file_name)));

if (use_definition_list) {
__39188_23_definition_list_option = (_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv());
__39189_23_def_list_display_option = ((const char *)"");
#line 3405
}
__39150_10_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(__39149_24_pifp, ((_ZN3edg12a_const_charE *)__39188_23_definition_list_option), __39189_23_def_list_display_option));

if (use_definition_list) {
if (__39150_10_return_status == 0) {


_ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file(__39149_24_pifp);
}

unlink(((const char *)temporary_file_name));
}

if (__39150_10_return_status != 0) { goto __T340171784; }
}
}
__39149_24_pifp = (__39149_24_pifp->next);
} __T340171784:;
return __39150_10_return_status;
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv(void)




{

auto a_pl_input_file_ptr __39230_24_pifp;
auto int __39231_10_return_status = 0;
auto int __39232_10_max_return_status = 0;

__39230_24_pifp = pl_input_files;
while (__39230_24_pifp != ((a_pl_input_file_ptr)0)) {


if (((!(__39230_24_pifp->is_archive)) && ((__39230_24_pifp->request_file_name) != ((char *)0))) && (__39230_24_pifp->is_local_file))
{



unlink(((const char *)(__39230_24_pifp->file_name)));

__39231_10_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(__39230_24_pifp, ((const char *)"--suppress_instantiation_flags"), ((_ZN3edg12a_const_charE *)0)));


if (__39231_10_return_status > __39232_10_max_return_status) { __39232_10_max_return_status = __39231_10_return_status; }
}
__39230_24_pifp = (__39230_24_pifp->next);
}
return __39232_10_max_return_status;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv(void)
#line 3466
{
auto a_pl_symbol_ptr __39263_19_psp;
auto _ZN3edg9a_booleanE __39264_14_any_errors = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __39265_14_is_new;

for (__39263_19_psp = specialization_list; __39263_19_psp != ((a_pl_symbol_ptr)0); __39263_19_psp = (__39263_19_psp->next_in_specialization_list))
{
auto a_pl_symbol_ptr __39269_21_nonspec_psp;
auto char *__39270_12_nonspec_name;


__39270_12_nonspec_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc((__39263_19_psp->name)));

__39269_21_nonspec_psp = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symbolbPb(__39270_12_nonspec_name, ((a_pl_symbol_ptr)0), ((_ZN3edg9a_booleanE)1), (&__39265_14_is_new)));
#line 3487
if ((__39269_21_nonspec_psp != ((a_pl_symbol_ptr)0)) && ((__39269_21_nonspec_psp->referenced) || (__39269_21_nonspec_psp->defined)))
{
_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePcb(pl_ec_specialized_and_instantiated, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(__39270_12_nonspec_name)), ((_ZN3edg9a_booleanE)0));


__39264_14_any_errors = ((_ZN3edg9a_booleanE)1);
} else  {




(__39269_21_nonspec_psp->referenced) = ((_ZN3edg14a_byte_booleanE)((((int)(__39269_21_nonspec_psp->referenced)) | ((int)(__39263_19_psp->referenced))) != 0));
(__39269_21_nonspec_psp->defined) = ((_ZN3edg14a_byte_booleanE)((((int)(__39269_21_nonspec_psp->defined)) | ((int)(__39263_19_psp->defined))) != 0));
}
}
return __39264_14_any_errors;
}
#line 3600
static void _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(void)



{
auto a_pl_input_file_ptr __39401_23_pifp;
auto a_pl_symbol_ptr __39402_19_psp;

__39401_23_pifp = pl_input_files;
while (__39401_23_pifp != ((a_pl_input_file_ptr)0)) {
auto a_pl_object_file_ptr __39406_26_pofp;
auto a_pl_object_file_ptr __39407_26_last_pofp;
__39406_26_pofp = (__39401_23_pifp->objects);
while (__39406_26_pofp != ((a_pl_object_file_ptr)0)) {
auto a_pl_symbol_ptr __39410_23_last_psp;
__39402_19_psp = (__39406_26_pofp->symbols);
while (__39402_19_psp != ((a_pl_symbol_ptr)0)) {
__39410_23_last_psp = __39402_19_psp;
__39402_19_psp = (__39402_19_psp->next);
free(((void *)(__39410_23_last_psp->name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(__39410_23_last_psp);
}
__39407_26_last_pofp = __39406_26_pofp;
__39406_26_pofp = (__39406_26_pofp->next);
free(((void *)(__39407_26_last_pofp->file_name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file(__39407_26_last_pofp);
}

{ auto a_pl_file_list_entry_ptr __39424_32_flep;
auto a_pl_file_list_entry_ptr __39425_32_next_flep;
for (__39424_32_flep = (__39401_23_pifp->dependencies); __39424_32_flep != ((a_pl_file_list_entry_ptr)0); __39424_32_flep = __39425_32_next_flep) {
__39425_32_next_flep = (__39424_32_flep->next);
free(((void *)__39424_32_flep));
}
}



if ((__39401_23_pifp->command_line) != ((char *)0)) { free(((void *)(__39401_23_pifp->command_line))); }
if ((__39401_23_pifp->compilation_directory) != ((char *)0)) { free(((void *)(__39401_23_pifp->compilation_directory))); }
if ((__39401_23_pifp->compilation_file_name) != ((char *)0)) { free(((void *)(__39401_23_pifp->compilation_file_name))); }
if ((__39401_23_pifp->secondary_files) != ((char *)0)) { free(((void *)(__39401_23_pifp->secondary_files))); }
if ((__39401_23_pifp->instantiation_directory) != ((char *)0)) {
free(((void *)(__39401_23_pifp->instantiation_directory)));
}
__39401_23_pifp = (__39401_23_pifp->next);
}

__39402_19_psp = pl_symbol_table_head;
while (__39402_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __39446_29_last_psp;
auto a_pl_instantiation_site_ptr __39447_33_pisp;
__39447_33_pisp = (__39402_19_psp->possible_instantiation_sites);
while (__39447_33_pisp != ((a_pl_instantiation_site_ptr)0)) {
auto a_pl_instantiation_site_ptr __39450_35_last_pisp;
__39450_35_last_pisp = __39447_33_pisp;
__39447_33_pisp = (__39447_33_pisp->next);
_ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site(__39450_35_last_pisp);
}
__39446_29_last_psp = __39402_19_psp;
__39402_19_psp = (__39402_19_psp->next_in_symbol_table);
free(((void *)(__39446_29_last_psp->name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(__39446_29_last_psp);
} 
}
#line 3685
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv(void)




{
pos_in_temp_string = 0ULL; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc( _ZN3edg12a_const_charE *__39491_49_addition)



{
auto int __39496_7_addition_length;

__39496_7_addition_length = ((int)(strlen(__39491_49_addition)));
if ((pos_in_temp_string + ((unsigned long long)__39496_7_addition_length)) >= temp_string_length) {
temp_string_length += 4000ULL;
temp_string = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvy(((_ZN3edg10a_void_ptrE)temp_string), temp_string_length)));

}
strcpy((temp_string + pos_in_temp_string), __39491_49_addition);
pos_in_temp_string += ((unsigned long long)__39496_7_addition_length); 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_( _ZN3edg12a_const_charE *__39509_53_add1, 
_ZN3edg12a_const_charE *__39510_25_add2)




{
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(__39509_53_add1);
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(__39510_25_add2); 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc( char *__39521_41_lib_name)
#line 3734
{


auto char *__39533_17_string_buffer = pl_input_line;
auto _ZN3edg9a_booleanE __39534_13_found = ((_ZN3edg9a_booleanE)0);
auto char *__39535_18_result = ((char *)0);
auto int __39536_8_j;

for (__39536_8_j = 0; __39536_8_j < num_of_L_directories; ++__39536_8_j) {
auto FILE *__39539_11_f_lib;
snprintf(__39533_17_string_buffer, 32767ULL, ((const char *)"%s/lib%s.a"), (L_directories[__39536_8_j]), __39521_41_lib_name);
#line 3751
if ((__39539_11_f_lib = (fopen(((const char *)__39533_17_string_buffer), ((const char *)"r")))) != ((FILE *)0)) {


__39535_18_result = __39533_17_string_buffer;
__39534_13_found = ((_ZN3edg9a_booleanE)1);
fclose(__39539_11_f_lib);
goto __T340259024;
}
} __T340259024:;

if (!(__39534_13_found)) {
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_lib_file_not_found)), __39521_41_lib_name);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
}
return __39535_18_result;
}
#line 3777
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file( char *__39573_41_str, 
a_pl_input_file_ptr __39574_53_pifp)




{
auto a_pl_cmd_line_arg_ptr __39580_25_pclap;
__39580_25_pclap = ((a_pl_cmd_line_arg_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy(24ULL)));

(__39580_25_pclap->is_string) = ((_Bool)(__39573_41_str != ((char *)0)));
(__39580_25_pclap->next) = ((a_pl_cmd_line_arg_ptr)0);
if (__39580_25_pclap->is_string) {
((__39580_25_pclap->variant).arg_string) = __39573_41_str;
} else  {
((__39580_25_pclap->variant).input_file_entry) = __39574_53_pifp;
}
if (cmd_line_head == ((a_pl_cmd_line_arg_ptr)0)) { cmd_line_head = __39580_25_pclap; }
if (cmd_line_tail != ((a_pl_cmd_line_arg_ptr)0)) { (cmd_line_tail->next) = __39580_25_pclap; }
cmd_line_tail = __39580_25_pclap; 
}


int main( int __39596_14_argc,  char **__39596_26_argv)
{
auto int __39598_17_arg;
auto int __39599_17_return_status = 0;
auto _ZN3edg9a_booleanE __39600_22_done = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __39601_22_any_template_files = ((_ZN3edg9a_booleanE)0);


auto int __39604_17_optchar;
auto long __39605_18_number_of_iterations = 0L;
auto char *__39606_19_nm_command = ((char *)0);
auto a_pl_cmd_line_arg_ptr __39607_26_last_arg_to_reemit = ((a_pl_cmd_line_arg_ptr)0);
auto _ZN3edg9a_booleanE __39608_15_suppress_instantiation_flags = ((_ZN3edg9a_booleanE)0);
auto _ZN3edg9a_booleanE __39609_15_list_object_files = ((_ZN3edg9a_booleanE)0);


f_informational = stderr;

message_prefix = (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_message_prefix));


memset(((void *)((char *)pl_assignment_table)), 0, 4792ULL);




L_directories = ((char **)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEy((((unsigned long long)__39596_14_argc) * 8ULL))));

_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv();



opterr = 0;

while ((__39604_17_optchar = (getopt(__39596_14_argc, ((char *const *)__39596_26_argv), ((const char *)"a:bc:d:ef:il:mno:qrs:vuB:DL:NOR:SW:")))) != (-1)) {
switch (__39604_17_optchar) {
case 97:

if (((strcmp(((const char *)optarg), ((const char *)"0"))) != 0) && ((strcmp(((const char *)optarg), ((const char *)"1"))) != 0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_definition_list_option, optarg);
}
use_definition_list = ((_Bool)((atoi(((const char *)optarg))) != 0));
goto __T340350496;
case 98:




__39609_15_list_object_files = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 99:


__39606_19_nm_command = optarg;
goto __T340350496;
case 68:

do_not_assign_to_nonlocal_objects = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 101:


suppress_dependency_checking = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
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
goto __T340350496;
case 105:

ignore_invalid_nm_output = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 66:



case 108:
#line 3902
optind--;
goto __39801_1_end_of_options;
case 76:

(L_directories[(num_of_L_directories++)]) = optarg;
goto __T340350496;
case 111:



{
auto char *__39709_17_obj_file_list_file_name;
__39709_17_obj_file_list_file_name = optarg;
f_obj_file_list = (fopen(((const char *)__39709_17_obj_file_list_file_name), ((const char *)"w")));
if (f_obj_file_list == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_obj_file_list_file, __39709_17_obj_file_list_file_name);

}
}
goto __T340350496;

case 79:

one_instantiation_per_object = ((_ZN3edg9a_booleanE)1);
goto __T340350496;

case 87:


if ((strncmp(((const char *)optarg), ((const char *)"l,-L"), 4ULL)) != 0) {
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_unrecognized_option)), optarg);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
}
(L_directories[(num_of_L_directories++)]) = (optarg + 4);
goto __T340350496;
case 109:

mangled_names_in_output = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 110:


suppress_compilation = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 78:




move_nonlocal_objects_to_curr_dir = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 114:

limit_recursion = ((_ZN3edg9a_booleanE)0);
goto __T340350496;
case 82:


reserved_request_file_lines = (atoi(((const char *)optarg)));
if ((reserved_request_file_lines < 0) || (reserved_request_file_lines > 0))

{
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_reserved_request_lines_option, optarg);
}
goto __T340350496;
case 115:


check_specialization_errors = ((_Bool)((atoi(((const char *)optarg))) != 0));
goto __T340350496;
case 83:



__39608_15_suppress_instantiation_flags = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 117:


skip_underscore_prefix = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 113:

verbose = ((_ZN3edg9a_booleanE)0);
goto __T340350496;
case 118:

verbose = ((_ZN3edg9a_booleanE)1);
goto __T340350496;
case 100:
#line 3997
default:
if (optind >= __39596_14_argc) { optind = (__39596_14_argc - 1); }
optarg = (__39596_26_argv[optind]);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_unrecognized_option)), optarg);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
goto __T340350496;
} __T340350496:;
}
__39801_1_end_of_options:;
if (((one_instantiation_per_object) || (move_nonlocal_objects_to_curr_dir)) && (f_obj_file_list == ((FILE *)0)))
{


_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_no_object_file_name_specified, ((char *)0));
}

if (__39606_19_nm_command != ((char *)0)) {

} else  { if (((int)nm_format) == 1) {
__39606_19_nm_command = solaris_nm_command;
} else  { if (((int)nm_format) == 2) {
__39606_19_nm_command = SGI_nm_command;
} else  { if (((int)nm_format) == 5) {
__39606_19_nm_command = CLIX_nm_command;
} else  { if ((((int)nm_format) == 3) || (((int)nm_format) == 4))
{
__39606_19_nm_command = alternate_nm_command;
} else  { if (((int)nm_format) == 6) {
__39606_19_nm_command = gnu_nm_command;
} else  {

__39606_19_nm_command = default_nm_command;
} } } } } }

{
#line 4037
auto a_pl_input_file_ptr __39833_25_list_tail = ((a_pl_input_file_ptr)0);
for (__39598_17_arg = optind; __39598_17_arg < __39596_14_argc; ++__39598_17_arg) { {
auto a_pl_input_file_ptr __39835_27_pifp;
auto char *__39836_34_orig_name;
auto char *__39837_34_file_name;
__39836_34_orig_name = (__39596_26_argv[__39598_17_arg]);
if ((strcmp(((const char *)__39836_34_orig_name), ((const char *)"--"))) == 0) {



__39607_26_last_arg_to_reemit = cmd_line_tail;
goto __T340511352;
}
if ((strncmp(((const char *)__39836_34_orig_name), ((const char *)"-B"), 2ULL)) == 0) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(__39836_34_orig_name, ((a_pl_input_file_ptr)0));
goto __T340511352;
} else  { if ((strncmp(((const char *)__39836_34_orig_name), ((const char *)"-l"), 2ULL)) == 0) {

auto char *__39852_16_lib_name; __39852_16_lib_name = (__39836_34_orig_name + 2);
__39837_34_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc(__39852_16_lib_name));
} else  {
__39837_34_file_name = __39836_34_orig_name;
} }
__39835_27_pifp = (_ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv());
(__39835_27_pifp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__39837_34_file_name)));

if (pl_input_files == ((a_pl_input_file_ptr)0)) { pl_input_files = __39835_27_pifp; }
_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(((char *)0), __39835_27_pifp);
if (__39833_25_list_tail != ((a_pl_input_file_ptr)0)) { (__39833_25_list_tail->next) = __39835_27_pifp; }
__39833_25_list_tail = __39835_27_pifp;
__39601_22_any_template_files = ((_ZN3edg9a_booleanE)((((int)__39601_22_any_template_files) | ((int)(_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file(__39835_27_pifp)))) != 0));
} __T340511352:; }
}

if (__39601_22_any_template_files) {
do {
auto a_pl_input_file_ptr __39870_27_pifp;
auto _ZN3edg9a_booleanE __39871_19_no_local_changes;
auto _ZN3edg9a_booleanE __39872_19_no_nonlocal_changes;
auto int __39873_13_nm_status;



for (__39870_27_pifp = pl_input_files; __39870_27_pifp != ((a_pl_input_file_ptr)0); __39870_27_pifp = (__39870_27_pifp->next)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(__39870_27_pifp);
}

pl_symbol_table_head = ((a_pl_symbol_ptr)0);
specialization_list = ((a_pl_symbol_ptr)0);
memset(((void *)((char *)pl_symbol_table)), 0, 80056ULL);


_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv();
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(((_ZN3edg12a_const_charE *)__39606_19_nm_command));

for (__39870_27_pifp = pl_input_files; __39870_27_pifp != ((a_pl_input_file_ptr)0); __39870_27_pifp = (__39870_27_pifp->next)) {
auto a_pl_object_file_ptr __39890_30_pofp;
_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(((const char *)" "), ((_ZN3edg12a_const_charE *)(__39870_27_pifp->file_name)));
if (use_template_info_file) {
_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file(__39870_27_pifp);
}
if (one_instantiation_per_object) {

for (__39890_30_pofp = (__39870_27_pifp->objects); __39890_30_pofp != ((a_pl_object_file_ptr)0); __39890_30_pofp = (__39890_30_pofp->next)) {
if (__39890_30_pofp->is_related_file) {


_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(((const char *)" "), ((_ZN3edg12a_const_charE *)(__39890_30_pofp->file_name)));
}
}
}
}
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(((_ZN3edg12a_const_charE *)nm_command_suffix));




if (!(__39609_15_list_object_files)) {

f_command_output = (popen(temp_string, "r"));
if (f_command_output == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_popen_failed, ((char *)0));
}

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv();
__39873_13_nm_status = (pclose(f_command_output));
if (__39873_13_nm_status != 0) {

_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_nm_returned_error, ((char *)0));
}


_ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv();
#line 4139
_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv();

_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv();
#line 4152
__39871_19_no_local_changes = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEb(((_ZN3edg9a_booleanE)1)));




if ((do_not_assign_to_nonlocal_objects) || ((use_definition_list) && (!(__39871_19_no_local_changes))))
{

__39872_19_no_nonlocal_changes = ((_ZN3edg9a_booleanE)1);
} else  {
__39872_19_no_nonlocal_changes = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEb(((_ZN3edg9a_booleanE)0)));
}
__39600_22_done = ((_Bool)((__39871_19_no_local_changes) && (__39872_19_no_nonlocal_changes)));


__39599_17_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv());
if ((limit_recursion) && ((++__39605_18_number_of_iterations) == 300L)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_instantiation_loop, ((char *)0));
}


if (check_specialization_errors) {
if (_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv()) {


if (__39599_17_return_status == 0) { __39599_17_return_status = 1; }
}
}
if ((__39599_17_return_status != 0) || (suppress_compilation)) { __39600_22_done = ((_ZN3edg9a_booleanE)1); }
} else  {

__39600_22_done = ((_ZN3edg9a_booleanE)1);
}
if (!(__39600_22_done)) { _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(); }
} while (!(__39600_22_done));
}
if (__39608_15_suppress_instantiation_flags) {


_ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv();
}
if (f_obj_file_list != ((FILE *)0)) {
#line 4199
auto a_pl_cmd_line_arg_ptr __39995_27_pclap;
for (__39995_27_pclap = cmd_line_head; __39995_27_pclap != ((a_pl_cmd_line_arg_ptr)0); __39995_27_pclap = (__39995_27_pclap->next)) {
if (__39995_27_pclap->is_string) {
fprintf(f_obj_file_list, ((const char *)" %s"), ((__39995_27_pclap->variant).arg_string));
} else  {
auto a_pl_object_file_ptr __40000_30_pofp;
fprintf(f_obj_file_list, ((const char *)" %s"), (((__39995_27_pclap->variant).input_file_entry)->file_name));



for (__40000_30_pofp = (((__39995_27_pclap->variant).input_file_entry)->objects); __40000_30_pofp != ((a_pl_object_file_ptr)0); __40000_30_pofp = (__40000_30_pofp->next))
{
if (!(__40000_30_pofp->is_related_file)) { goto __T340578688; }
fprintf(f_obj_file_list, ((const char *)" %s"), (__40000_30_pofp->file_name)); __T340578688:;
}
}
if (__39995_27_pclap == __39607_26_last_arg_to_reemit) { goto __T340580584; }
} __T340580584:;
fprintf(f_obj_file_list, ((const char *)"\n"));
fclose(f_obj_file_list);
}
#line 4228
return __39599_17_return_status;
}
#line 4193 "src/util.h"
 /* COMDAT group: _ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_ */ int _ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_( char *__33393_40_dest_buff, 
size_t __33394_39_dest_buff_size, 
_ZN3edg12a_const_charE *__33395_40_format_str, 
unsigned long __1_33396_42_args)
#line 4205
{




auto int __33410_7_result;
#line 4206
((__33393_40_dest_buff != ((char *)0)) && (__33394_39_dest_buff_size > 0ULL)) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)_ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es), 4206, ((const char *)
#line 4206
_ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0), ((const char *)_ZZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_Es_0)));



__33410_7_result = (snprintf(__33393_40_dest_buff, __33394_39_dest_buff_size, __33395_40_format_str, __1_33396_42_args));

if ((__33410_7_result >= 0) && (((size_t)__33410_7_result) >= __33394_39_dest_buff_size)) {



__33410_7_result = (-1);
}
return __33410_7_result;

}
#line 22 "src/host_util.h"
unsigned long _ZN3edg6crc_32EPKcm( _ZN3edg12a_const_charE *__36142_36_str, 
unsigned long __36143_22_prev_crc)
#line 33
{
auto unsigned long __36154_17_crc;



__36154_17_crc = (__36143_22_prev_crc ^ 4294967295UL);
while (((int)(*__36142_36_str)) != 0) {
auto unsigned long __36160_19_ch;
auto int __36161_9_nbit;
#line 40
__36160_19_ch = ((unsigned long)((unsigned char)(*(__36142_36_str++))));


for (__36161_9_nbit = 0; __36161_9_nbit < 8; (__36161_9_nbit++) , (__36160_19_ch >>= 1)) {
auto int __36164_11_low_bit; __36164_11_low_bit = ((int)((__36160_19_ch ^ __36154_17_crc) & 1UL));
__36154_17_crc >>= 1;
if (__36164_11_low_bit) { __36154_17_crc ^= 0xedb88320UL; }
}
}
__36154_17_crc ^= 4294967295UL;
return __36154_17_crc;
}



_ZN3edg12a_const_charE *_ZN3edg39generate_instantiation_output_file_nameEPKc(
_ZN3edg12a_const_charE *__36176_67_mangled_name)
#line 63
{


auto long long __36186_22_max_len_without_suffix;
#line 83
auto unsigned long __36203_17_crc_value;
auto size_t __36204_17_used_buffer_len;
auto size_t __36205_17_remaining_buffer_len;


auto int __36208_17_chars_written;
#line 73
__36186_22_max_len_without_suffix = 23LL;

__36186_22_max_len_without_suffix -= 7LL;



(__36186_22_max_len_without_suffix > 0LL) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)"src/host_util.h"), 79, ((const char *)""), ((const char *)"")));
strncpy(_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer, __36176_67_mangled_name, ((size_t)__36186_22_max_len_without_suffix));
((_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer)[__36186_22_max_len_without_suffix]) = ((char)0);

__36203_17_crc_value = (_ZN3edg6crc_32EPKcm(__36176_67_mangled_name, 0UL));
__36204_17_used_buffer_len = (strlen(((const char *)_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer)));
__36205_17_remaining_buffer_len = (32ULL - __36204_17_used_buffer_len);


__36208_17_chars_written = (_ZN3edg6detail13snprintf_implIJmEEEiPcyPKcDpT_((_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer + __36204_17_used_buffer_len), __36205_17_remaining_buffer_len, ((const char *)"_%08lx"), __36203_17_crc_value));



(__36208_17_chars_written > 0) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)"src/host_util.h"), 92, ((const char *)""), ((const char *)"")));

return (_ZN3edg12a_const_charE *)(_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer);
}
#line 223
_ZN3edg9a_booleanE _ZN3edg26get_file_modification_timeEPKcPx( _ZN3edg12a_const_charE *__36343_52_file_name, 
time_t *__36344_52_p_time)




{
auto _ZN3edg9a_booleanE __36350_13_is_regular = ((_ZN3edg9a_booleanE)0);
#line 254
{


auto struct stat __36377_17_buf;
#line 266
if ((stat(__36343_52_file_name, (&__36377_17_buf))) == 0) {



__36350_13_is_regular = ((_Bool)((((int)(__36377_17_buf.st_mode)) & 0xf000) == 0x8000));



if ((__36350_13_is_regular) && (__36344_52_p_time != ((time_t *)0))) { (*__36344_52_p_time) = ((__36377_17_buf.st_mtim).tv_sec); }
} else  {

if (__36344_52_p_time != ((time_t *)0)) { (*__36344_52_p_time) = 0LL; }
}
}
return __36350_13_is_regular;
}
