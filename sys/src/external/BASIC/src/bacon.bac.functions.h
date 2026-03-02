/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */

char * ERR__b2c__string_var(int nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long flen = 0, slen = 0; char *first = NULL, *second = NULL; switch (nr)
{ case 0: first = "Success"; break; case 1: first = "Trying to access illegal memory: "; second = strerror(errno); break;
case 2: first = "Error opening file: "; second = strerror (errno); break; case 3: first = "Could not open library."; break;
case 4: first = "Symbol not found in library."; break; case 5: first = "Wrong value: "; second = strerror(errno); break;
case 6: first = "Unable to claim memory."; break; case 7: first = "Unable to delete file: "; second = strerror(errno); break;
case 8: first = "Could not open directory: "; second = strerror(errno); break; case 9: first = "Unable to rename file: "; second = strerror(errno); break;
case 10: first = "NETWORK argument should contain colon with port number"; break; case 11: first = "Could not resolve hostname!"; break;
case 12: first = "Socket error: "; second = strerror(errno); break; case 13: first = "Unable to open address: "; second = strerror(errno); break;
case 14: first = "Error reading from socket: "; second = strerror(errno); break; case 15: first = "Error sending to socket: "; second = strerror(errno); break;
case 16: first = "Error checking socket: "; second = strerror(errno); break; case 17: first = "Unable to bind the specified socket address: "; second = strerror(errno); break;
case 18: first = "Unable to listen to socket address: "; second = strerror(errno); break; case 19: first = "Cannot accept incoming connection: "; second = strerror(errno); break;
case 20: first = "Unable to remove directory: "; second = strerror(errno); break; case 21: first = "Unable to create directory: "; second = strerror(errno); break;
case 22: first = "Unable to change to directory: "; second = strerror(errno); break; case 23: first = "GETENVIRON argument does not exist as environment variable"; break;
case 24: first = "Unable to stat file: "; second = strerror(errno); break; case 25: first = "Search contains illegal string"; break;
case 26: first = "Cannot return name: "; second = strerror(errno); break; case 27: first = "Illegal regex expression"; break;
case 28: first = "Unable to create bidirectional pipes: "; second = strerror(errno); break; case 29: first = "Unable to fork process: "; second = strerror(errno); break;
case 30: first = "Cannot read from pipe: "; second = strerror(errno); break; case 31: first = "Gosub nesting too deep!"; break;
case 32: first = "Could not open device: "; second = strerror(errno); break; case 33: first = "Error configuring serial port: "; second = strerror(errno); break;
case 34: first = "Error accessing device: "; second = strerror(errno); break; case 35: first = "Error in INPUT: "; second = strerror(errno); break;
case 36: first = "Illegal value in SORT dimension!"; break; case 37: first = "Illegal option for SEARCH!"; break;
case 38: first = "Invalid UTF8 string!"; break; case 39: first = "Illegal EVAL expression!"; break;
case 40: first = "SSL file descriptor error!"; break; case 41: first = "Error loading certificate!"; break;
case 42: first = "Widget not found!"; ERROR = 42; break; case 43: first = "Unsupported array type!"; break; };
if(first) { flen = strlen(first); } if(second) { slen = strlen(second); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], flen+slen+1);if(first)
{ memmove(buf[idx], first, flen); } if(second) { memmove(buf[idx]+flen, second, slen); } __b2c__SETLEN(buf[idx], flen+slen); buf[idx][flen+slen] = '\0'; return((char*)buf[idx]); }
char *__b2c__strdup(char *s) { if (s == NULL) { return(NULL); } return(__b2c_Copy_String(NULL, s)); }
char *__b2c__strndup(char *s, size_t n) { if(s == NULL) { return(NULL); } return(__b2c_Copy_N_String(NULL, s, n)); }
int __b2c__strcmp(const char *__b2c__s1, const char *__b2c__s2){ int len1 = 0, len2 = 0; len1 = __b2c__len(__b2c__s1); len2 = __b2c__len(__b2c__s2); if((__b2c__s1 == NULL || len1 == 0) && (__b2c__s2 == NULL || len2 == 0)) { return(0); }
if(__b2c__s1 == NULL || len1 == 0) { return(-1); } if(__b2c__s2 == NULL || len2 == 0) { return(1); } return(strcmp(__b2c__s1, __b2c__s2)); }
int __b2c__strcasecmp(const char *__b2c__s1, const char *__b2c__s2){ int len1 = 0, len2 = 0; len1 = __b2c__len(__b2c__s1); len2 = __b2c__len(__b2c__s2); if((__b2c__s1 == NULL || len1 == 0) && (__b2c__s2 == NULL || len2 == 0)) { return(0); }
if(__b2c__s1 == NULL || len1 == 0) { return(-1); } if(__b2c__s2 == NULL || len2 == 0) { return(1); } return(strcasecmp(__b2c__s1, __b2c__s2)); }
#ifndef __b2c_Pool_Block_Count
#define __b2c_Pool_Block_Count 2048
#endif
#ifndef __b2c_Pool_Block_Size
#define __b2c_Pool_Block_Size 1024
#endif
void *__b2c_mempool_realloc_core (void *address, size_t size, int action) { static char bottom[__b2c_Pool_Block_Count*__b2c_Pool_Block_Size] = { 0 }; static void *top = NULL, *current = NULL; static int inited = 0, amount_used = 0; void *result = NULL;
if(!inited) { current = bottom; top = bottom + (__b2c_Pool_Block_Size * __b2c_Pool_Block_Count); *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } switch(action) { case 0: fprintf(stderr, "Memory pool contains %d slots, each %d bytes, of which %d were used.\n", __b2c_Pool_Block_Count, __b2c_Pool_Block_Size, inited);
break; case 1: if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { *(uintptr_t *)address = (uintptr_t)current; current = address; amount_used--; return(address); } break; case 2:
if ((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { return(address); } break; default: if(amount_used < __b2c_Pool_Block_Count-1 && size < __b2c_Pool_Block_Size) { if(address == NULL) { result = current;
current = (void*)*(uintptr_t*)current; amount_used++; if(amount_used == inited) { *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } } else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top)
{ if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = address; } } else { result = realloc(address, size); } } else { if(address == NULL) { result = realloc(address, size); }
else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = malloc(size > __b2c_Pool_Block_Size ? size : __b2c_Pool_Block_Size);
memcpy(result, address, __b2c_Pool_Block_Size); *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } } else { result = realloc(address, size); } } break; } return ((void *) result); }
#ifndef __b2c_HASH_STR_STORE
#define __b2c_HASH_STR_STORE 0x100000
#endif
#define __b2c_HASH_STR_INDEX (__b2c_HASH_STR_STORE-1)
#ifndef __b2c_HASH_LINEAR_DEPTH
#define __b2c_HASH_LINEAR_DEPTH 16
#endif
#define __b2c_get_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { p=NULL; break; }}}
#define __b2c_del_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { break; } } if(d < l) { e[i] = NULL; } }
#define __b2c_add_string(p, e, i, d, l) if(p) { while(e[i] != NULL && e[i]!=p) { i++; if(++d == l) { if(++l == __b2c_HASH_LINEAR_DEPTH) { fprintf (stderr, "\nInternal error: cannot register string! Try to tweak the 'hld' parameter.\n"); __b2c_str_realloc_debug_string(); exit (EXIT_FAILURE); } } } e[i] = p; }
void *__b2c_str_realloc_core (char *ptr, size_t size, int action) { static char *even_addr[__b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH] = { NULL }; static int linear_depth = 1; char *next; uint32_t lbufsize = 0, rbufsize = 0, idx, len, depth = 0, total = 0; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); switch (action)
{ case 0: case 1: next = ptr; __b2c_get_string(next, even_addr, idx, depth, linear_depth); if(next) { lbufsize = __b2c__LBUFSIZE (ptr); rbufsize = __b2c__RBUFSIZE (ptr); if (action == 0) { if (rbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2 + 1);
ptr = next + lbufsize; *(uint32_t *) ((char *) ptr + 4) = size * 2 + 1 + rbufsize; } else { return (ptr); } } else { if (lbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2);
memmove (next + lbufsize + size * 2, next + lbufsize, __b2c__BUFOFFSET + rbufsize); ptr = next + size * 2 + lbufsize; *(uint32_t *) ((char *) ptr + 8) = size * 2 + lbufsize; } else { return (ptr); } } } else { rbufsize = __b2c__len (ptr); next = (char*)__b2c_mempool_realloc(ptr, __b2c__BUFOFFSET + rbufsize + size * 2 + 1);
if (action == 0) { ptr = next; *(uint32_t *) ((char *) ptr) = rbufsize; *(uint32_t *) ((char *) ptr + 4) = rbufsize + size * 2 + 1; *(uint32_t *) ((char *) ptr + 8) = 0; } else { memmove (next + size * 2, next, __b2c__BUFOFFSET + rbufsize); ptr = next+size * 2; *(uint32_t *) ((char *) ptr) = rbufsize;
*(uint32_t *) ((char *) ptr + 4) = rbufsize + 1; *(uint32_t *) ((char *) ptr + 8) = size * 2; } } ptr += __b2c__BUFOFFSET; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); depth = 0; __b2c_add_string(ptr, even_addr, idx, depth, linear_depth); break; case 2: __b2c_add_string(ptr, even_addr, idx, depth, linear_depth);
break; case 3: __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); break; case 4: __b2c_get_string(ptr, even_addr, idx, depth, linear_depth); break; case 5: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if (even_addr[idx] != NULL) { total++; len = (*(uint32_t*)(even_addr[idx]-__b2c__BUFOFFSET));
lbufsize = __b2c__LBUFSIZE(even_addr[idx]); rbufsize = __b2c__RBUFSIZE(even_addr[idx]); if(len > 64) { even_addr[idx][64] = 0; fprintf(stderr, "Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s[...]\n", idx, lbufsize, rbufsize, len, even_addr[idx]); } else { fprintf(stderr, "Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s\n", idx, lbufsize, rbufsize, len, even_addr[idx]); } } }
fprintf(stderr, "Total optimized strings: %d - max depth: %d\n", total, linear_depth); break; case 6: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if(even_addr[idx] && !__b2c_mempool_realloc_in_block(even_addr[idx])) { free(even_addr[idx] - __b2c__BUFOFFSET - __b2c__LBUFSIZE(even_addr[idx])); } } break; } return (ptr); }
char *__b2c_Copy_String_core(char *x, char *y, int len) { long ylen; if(y == NULL) { __b2c__STRFREE(x); return(NULL); } if(len == -1) { ylen = __b2c__len(y); } else { ylen = len; } if (ylen == 0) { __b2c__STRFREE (x); return (NULL); } x = (char*)__b2c_str_realloc(x, ylen);
memmove(x, y, ylen); __b2c__SETLEN(x, ylen); x[ylen] = '\0'; return(x); }
char *__b2c_Swap_String(char **x, char **y) { char *ptr; ptr = *x; *x = *y; *y = ptr; return(*x); }
unsigned long __b2c__len (const char *ptr) { if (ptr == NULL) { return (0); } if(__b2c_str_realloc_get_string(ptr)) { return (*(uint32_t *) (ptr - __b2c__BUFOFFSET)); } return ((unsigned long) strlen (ptr)); }
char *__b2c__loop_helper(jmp_buf buf) { if(__b2c__loop_result__b2c__string_var != NULL) { __b2c__SETLEN (__b2c__loop_result__b2c__string_var, 0); __b2c__loop_result__b2c__string_var = __b2c_Copy_String(__b2c__loop_result__b2c__string_var, NULL); } longjmp(buf, 1); return(NULL); }
long __b2c__loop_helper2(jmp_buf buf) { __b2c__loop_result = 0; longjmp(buf, 1); return(0); }
void __b2c__free_str_array_members(char ***array, int base, int size) { int i; if(*array != NULL) { for(i=0; i < size; i++){ __b2c__STRFREE((*array)[i+base]); (*array)[i+base] = NULL; } } }
void __b2c_str_free(void) {__b2c__regex_free();__b2c__extract_free();__b2c__replace_free();__b2c__walk_free();__b2c__delim_engine_free();__b2c__arrays_free();__b2c_str_realloc_free_string(); }
void __b2c__catch_signal(int sig){
switch (sig) {case SIGABRT: fprintf(stderr, "ERROR: signal ABORT received - internal error. Try to compile the program with TRAP LOCAL to find the cause.\n"); break;
case SIGFPE: fprintf(stderr, "ERROR: signal for FPE received - division by zero? Examine the calculations in the program.\n"); break;
case SIGSEGV: fprintf(stderr, "ERROR: signal for SEGMENTATION FAULT received - memory invalid or array out of bounds? Try to compile the program with TRAP LOCAL to find the cause.\n"); break;
case SIGILL: fprintf(stderr, "ERROR: signal for ILLEGAL INSTRUCTION received - executing the program on other hardware? Try to recompile the program from scratch.\n"); break;} exit(sig);}
void __b2c__segv(int sig){ longjmp(__b2c__jump, 1); }
int __b2c__memory__check (char *x, int size) { volatile char c; unsigned int i, illegal = 1; struct sigaction osa, psa; sigaction(SIGSEGV, NULL, &osa); if (osa.sa_handler != SIG_IGN)
{ memset(&psa, 0, sizeof(psa)); psa.sa_flags = SA_NODEFER|SA_RESTART; psa.sa_handler = __b2c__segv; sigaction(SIGSEGV, &psa, NULL); } if (!setjmp (__b2c__jump))
{ for (i = 0; i < size; i++) { c = *(char*)(x+i); /* Use c to avoid warning */ if(c) {;} } } else { illegal = 0; } sigaction(SIGSEGV, &osa, NULL); return (illegal); }
int jmp_buf_is_used(jmp_buf data) { jmp_buf p = { 0 }; if(!data) {return(0);} if(memcmp(data, p, sizeof(jmp_buf))) { return(1); } return(0); }
char* __b2c__min_str(char* x, char* y) {if(strcmp(x, y) < 0) { return(x); } return(y);}
char* __b2c__max_str(char* x, char* y) {if(strcmp(x, y) > 0) { return(x); } return(y);}
char* __b2c__str(double nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc (buf[idx], 32); if(floor(nr) == nr)
{ len = snprintf(buf[idx], 32, "%ld", (long)nr); } else { len = snprintf(buf[idx], 32, "%g", (double)nr); } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }
unsigned long __b2c__timer(int init) { struct timeval time; static time_t elapsed_secs = 0; static int elapsed_usecs = 0; if(init) { gettimeofday(&time, NULL); elapsed_usecs = time.tv_usec; elapsed_secs = time.tv_sec; return(0); }
else { gettimeofday(&time, NULL); if(difftime(time.tv_sec, elapsed_secs) < 1) { return((unsigned long) (time.tv_usec-elapsed_usecs)/1000); }
else { return((unsigned long) (difftime(time.tv_sec, elapsed_secs)-1)*1000+((1000000-elapsed_usecs)+time.tv_usec)/1000); } } }
uint64_t __b2c__nanotimer(int init) { static struct timespec before = { 0 }; struct timespec after; if (init) { clock_gettime(CLOCK_MONOTONIC, &before); return(0); } else { clock_gettime(CLOCK_MONOTONIC, &after); return((int64_t)(after.tv_sec - before.tv_sec) * (int64_t)1000000000UL + (int64_t)(after.tv_nsec - before.tv_nsec)); } }
void __b2c__argument(char **arg, int total, char **data) { long x, dlen, slen, pos, tot_len = 0; char quote[] = { 34, 0 }; if (total == 0) { *arg = NULL; } else { dlen = __b2c__len (__b2c__option_delim); for (pos = 0; pos < total; pos++)
{ slen = strlen(data[pos]); *arg = (char*)__b2c_str_realloc(*arg, tot_len + slen * 2 + dlen + 1); if (strstr (data[pos], " ") || strstr (data[pos], "\"")) { (*arg)[tot_len++] = 34; for (x = 0; data[pos][x] != 0; x++) { if (data[pos][x] == quote[0])
{ (*arg)[tot_len++] = __b2c__option_esc; } (*arg)[tot_len++] = data[pos][x]; } (*arg)[tot_len++] = 34; } else { memmove (*arg + tot_len, data[pos], slen); tot_len += slen; } if (pos < total - 1) { memmove (*arg + tot_len, __b2c__option_delim, dlen);
tot_len += dlen; } } __b2c__SETLEN(*arg, tot_len); (*arg)[tot_len] = 0; } }
int __b2c_utf8_conv(int txt, char* utf8) { unsigned char b1, b2, b3; int len; if (txt > 0xFFFF) { b1 = txt & 0x0000FF; b2 = (txt & 0x00FF00) >> 8; b3 = (txt & 0xFF0000) >> 16;
len = snprintf (utf8, 5, "%c%c%c%c", 0xF0 | (b3 >> 2), 0x80 | ((b3 & 0x03) << 4) | ((b2 & 0xF0) >> 4), 0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6),
0x80 | (b1 & 0x3F)); } else if (txt > 0x07FF) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 4, "%c%c%c", 0xE0 | ((b2 & 0xF0) >> 4),
0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else if (txt > 0x007F) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 3, "%c%c",
0xC0 | (b2 << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else { len = snprintf (utf8, 2, "%c", txt & 0x7F); } return(len); }
unsigned long __b2c__ulen (int l, char *k, char *func, char *ptr, int pos) { long len = 0; if (ptr == NULL) { return(0); } if(pos < 0) { while(*ptr){ if((*ptr&0xF0) == 0xF0) { len++; ptr += 4; } else if((*ptr&0xE0) == 0xE0) { len++; ptr += 3; }
else if((*ptr&0xC0) == 0xC0) { len++; ptr += 2; } else if((*ptr&0x80) == 0) { len++; ptr++; } else { ERROR = 38; RUNTIMEFERR(func, ERROR, k, l); return(0); } } } else { len = __b2c__ucs2_clen(l, k, "ULEN", ptr, pos); } return(len); }
unsigned long __b2c__blen (int l, char *k, char *func, char *ptr, long c, int flag) { char *org = ptr; if (ptr == NULL){ return (0); }
if(flag) { c = __b2c__ulen (l, k, "BYTELEN", org, -1)-c; } while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; } else if ((*ptr & 0xE0) == 0xE0) { ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; } else if ((*ptr & 0x80) == 0)
{ ptr++; } else { ERROR = 38; fprintf (stderr, "Cannot decode UTF-8 string: '%s'\n", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } c--; } if(flag) { return (__b2c__len(org) - (ptr - org)); } else { return (ptr - org); } }
unsigned long __b2c__ucs2_clen (int l, char* k, char *func, char *ptr, int c) { int len = 0; char *org; if (ptr == NULL) return (0); org = ptr; while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; c -= 4; } else if ((*ptr & 0xE0) == 0xE0)
{ ptr += 3; c -= 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; c -= 2; } else if ((*ptr & 0x80) == 0) { ptr++; c--; } else { ERROR = 38; fprintf(stderr, "Cannot decode UTF-8 string: '%s'\n", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } len++; } return (len); }
/* Portions of this code based on Bob Trower's C implementation at http://base64.sourceforge.net - MIT licensed */ static const char cd64[]="|$$$}rstuvwxyz{$$$$$$$>?@ABCDEFGHIJKLMNOPQRSTUVW$$$$$$XYZ[\\]^_`abcdefghijklmnopq";
static const char cb64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; static void __b2c__encodeblock( unsigned char *in, unsigned char *out, int len)
{ out[0] = (unsigned char) cb64[ (int)(in[0] >> 2) ]; out[1] = (unsigned char) cb64[ (int)(((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)) ];
out[2] = (unsigned char) (len > 1 ? cb64[ (int)(((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)) ] : '='); out[3] = (unsigned char) (len > 2 ? cb64[ (int)(in[2] & 0x3f) ] : '='); }
char * __b2c__b64enc (char* src, int len) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[4]; int i, j, cur = 0, posit = 0; if (src == NULL) { return(NULL); }
if (len == 0) { len = __b2c__len (src); } if (len == 0) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ((len + 2) / 3) * 4 + 1);
while( cur < len ){ for( i = 0; i < 3 && (cur + i < len); i++ ){ in[i] = (unsigned char) src[cur+i]; } in[i] = 0; cur += i; if( i > 0 ) { __b2c__encodeblock( in, out, i );
for( j = 0; j < 4; j++ ) { buf[idx][posit+j] = out[j]; } posit += 4; } } buf[idx][posit] = '\0'; __b2c__SETLEN (buf[idx], posit); return(char*)(buf[idx]); }
static void __b2c__decodeblock(unsigned char in[4], unsigned char out[3]) { out[0] = (unsigned char ) (in[0] << 2 | in[1] >> 4); out[1] = (unsigned char)(in[1] << 4 | in[2] >> 2);
out[2] = (unsigned char ) (((in[2] << 6) & 0xc0) | in[3]); }
char *__b2c__b64dec(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[3], v; int i = 0, stlen, dec_len, len, cur = 0, posit = 0; if(src == NULL){ return (NULL); }
stlen = __b2c__len (src); if (stlen == 0) { return (NULL); } if(stlen % 4) { ERROR = 5; RUNTIMEFERR ("B64DEC$", ERROR, k, l); return(NULL); } dec_len = 3*stlen/4; while(src[stlen+i-1] == 61) { dec_len--; i--; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], dec_len + 4); while(cur < stlen){ for (len = 0, i = 0; i < 4 && (cur < stlen); i++) { v = 0; while (cur < stlen && v == 0){ v = (unsigned char) src[cur]; cur++; v = (unsigned char) ((v < 43 || v > 122) ? 0 : cd64[ v - 43 ]);
if (v) {v = (unsigned char) ((v == '$') ? 0 : v - 61);} } if(cur <= stlen){ len++; if (v) { in[i] = (unsigned char)(v - 1); } else { in[i] = 0; } } } if(len){ __b2c__decodeblock(in, out);
for(i = 0; i < len - 1; i++) { buf[idx][posit + i] = out[i]; } buf[idx][posit + i] = '\0'; posit += len - 1; } } __b2c__SETLEN(buf[idx], dec_len); return(char*)(buf[idx]); }
char *__b2c__chop(char **swap, int type, char *source, char *string, int location) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long length; if (source == NULL || *source == '\0') { if (type == 1) { *swap = __b2c_Copy_String(*swap, NULL); } return (NULL); } if (string == NULL) { string = (char *) __b2c__chop_default; }
idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len(string); if (location == 0 || location == 1) { while (*source != '\0') { if(memchr(string, *source, length)) { source++; } else { break; } } if (*source == '\0'){ if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); } } tmp = source + __b2c__len(source) - 1;
if(location == 0 || location == 2) { while (tmp >= source && *tmp != '\0') { if(memchr(string, *tmp, length)) { tmp--; } else { break; } } } tmp++; buf[idx] = (char*)__b2c_str_realloc(buf[idx], tmp-source+1); memmove(buf[idx], source, tmp - source);
__b2c__SETLEN(buf[idx], tmp - source); buf[idx][tmp - source] = '\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }
char *__b2c__asc2char (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2); len = snprintf(buf[idx], 2, "%c", i); __b2c__SETLEN(buf[idx], len); return(char*)(buf[idx]); }
char *__b2c__asc2utf8 (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; char buffer[5]; len = __b2c_utf8_conv(i, buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memcpy(buf[idx], buffer, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }
unsigned int __b2c__utf8toasc(char* ptr) { unsigned int result = 0; if((*ptr&0xF0)==0xF0) { result = (*ptr&0x07)<<2; ptr++; result = result | ((*ptr&0x30)>>4); result = result << 8; result = result | ((*ptr&0x0F)<<4);
ptr++; result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xE0)==0xE0) { result = (*ptr&0x0F)<<4; ptr++;
result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xC0)==0xC0) { result = (*ptr&0x1C)>>2; result = result << 8;
result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0x80) == 0) { result = (*ptr&0x7F); } return (result); }
unsigned char __b2c__isascii(const char *ptr) { long x; for(x=0; *(ptr+x); x++) { if(*(ptr+x)&128) return(0); } return(1); }
unsigned char __b2c__isutf8(const char *ptr) { int result = 1; if (ptr == NULL) { return (0); } while (*ptr) { if ((*ptr & 0xF0) == 0xF0)
{ if ((*(ptr + 1) & 0xC0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 || (*(ptr + 3) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 4; } else if ((*ptr & 0xE0) == 0xE0)
{ if ((*(ptr + 1) & 0xc0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { if ((*(ptr + 1) & 0xc0) != 0x80 )
{ result = 0; break; } ptr += 2; } else if ((*ptr & 0x80) == 0) { ptr++; } else { result = 0; break; } } return (result); }
char *__b2c__toascii(char *ptr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len, x; len = __b2c__len (ptr); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], len); for(x = 0; x < len; x++) { *(buf[idx] + x) = *(ptr + x) & 0x7f; } __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\0'; return((char*)buf[idx]); }
int __b2c__getopt(int argc, char **argv, char* str){int opt; extern char *optarg; extern int optind, opterr; opterr = 0; opt = getopt(argc, argv, str); if(opt != -1)
{ ARGUMENT__b2c__string_var = __b2c_Copy_String(ARGUMENT__b2c__string_var, optarg); } else { ARGUMENT__b2c__string_var = __b2c_Copy_String(ARGUMENT__b2c__string_var, argv[optind]); } return(opt); }
char *__b2c__concat(int n, ...) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } idx++;
if (idx == __b2c_STRING_FUNC) { idx = 0; } va_start (ap, n); if(buf[idx]) { buflen = __b2c__RBUFSIZE(buf[idx]); } while (n) { next = va_arg (ap, char *); if (next) { cnew = __b2c__len (next);
if(length+cnew >= buflen) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + cnew); buflen = __b2c__RBUFSIZE(buf[idx]); } memcpy(buf[idx] + length, next, cnew); length += cnew; }
n--; } va_end (ap); if (buf[idx]) { __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\0'; } return ((char *) buf[idx]); }
char *__b2c__concat2(int total, ...) { char *iter, *result, *first, *next, *offset; int n_copy = 0, pos = 0, length = 0, cnew, flen = 0, stage = 0; uint32_t lbufsize = 0, rbufsize = 0; va_list ap_copy, ap; va_start (ap, total);
first = result = offset = va_arg (ap, char *); total--; if (total == 0) { return (NULL); } va_copy (ap_copy, ap); if(first) { n_copy = total; } while (n_copy) { iter = va_arg (ap_copy, char *); if (iter == first) { flen = __b2c__len (first); break; }
pos += __b2c__len (iter); n_copy--; } va_end (ap_copy); if (__b2c_str_realloc_get_string(result) ) { lbufsize = __b2c__LBUFSIZE (result); rbufsize = __b2c__RBUFSIZE (result); }
else { rbufsize = __b2c__len(first); } if (n_copy) { if (pos >= lbufsize) { result = (char *) __b2c_str_realloc_left(result, lbufsize + rbufsize + pos); offset = result; } __b2c_str_realloc_del_string(result);
memmove (result - __b2c__BUFOFFSET - pos, result - __b2c__BUFOFFSET, __b2c__BUFOFFSET); result -= pos; __b2c_str_realloc_add_string(result); __b2c__LBUFSIZE (result) -= pos; __b2c__RBUFSIZE (result) += pos;
rbufsize = __b2c__RBUFSIZE (result); } next = va_arg (ap, char *); total--; while (total >= 0) { if (next) { if (next == first) { cnew = flen; } else { cnew = __b2c__len (next); } if (cnew + flen + length >= rbufsize)
{ result = (char *) __b2c_str_realloc (result, cnew + flen + length); rbufsize = __b2c__RBUFSIZE (result); offset = result + pos; } if (next != first) { memmove (result + length, next, cnew); } else { if (stage == 0) { stage = 1; } else
{ memmove (result + length, offset, cnew); } } length += cnew; } next = va_arg (ap, char *); total--; } va_end (ap); if(result) { __b2c__SETLEN (result, length); result[length] = '\0'; } return ((char *) result); }
long __b2c__count (int l, char *k, char *x, unsigned int y) { long i, z = 0; if(x == NULL) { return(0); } if (__b2c__option_utf8) { while (*x) { if (__b2c__utf8toasc (x) == y) { z++; } if ((*x & 0xF0) == 0xF0) { x += 4; }
else if ((*x & 0xE0) == 0xE0) { x += 3; } else if ((*x & 0xC0) == 0xC0) { x += 2; } else if ((*x & 0x80) == 0) { x++; } else { ERROR = 38; RUNTIMEFERR ("COUNT", ERROR, k, l); return(0); } } } else 
{ for (i = 0; x[i] != '\0'; i++) { if (x[i] == y) { z++; } } } return z; }
char *__b2c__curdir (void) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], 512);
buf[idx] = getcwd(buf[idx], 512); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][512-1] = '\0'; return(char*)(buf[idx]); }
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif
char *__b2c__dirname(int l, char *k, int x, char *y, long arg) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i; char *dup; if(y == NULL || __b2c__len(y) == 0){ return(NULL); }
idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], PATH_MAX*sizeof(char)); dup = __b2c__strdup(y); switch(x) {case 0: if ((realpath(y, buf[idx])) == NULL) { ERROR = 26; RUNTIMEFERR("REALPATH$", ERROR, k, l); strncpy(buf[idx], "Error getting real path", 512);
return(NULL); } break; case 1: if(strncpy(buf[idx], basename(dup), PATH_MAX) == NULL) { ERROR = 26; RUNTIMEFERR("BASENAME$", ERROR, k, l); strncpy (buf[idx], "Error getting basename", 512); return(NULL); }
break; case 2: if (strncpy(buf[idx], dirname(dup), PATH_MAX) == NULL) { ERROR = 26; RUNTIMEFERR("DIRNAME$", ERROR, k, l); strncpy(buf[idx], "Error getting dirname", 512); return(NULL); }
break; } __b2c__STRFREE(dup); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][PATH_MAX - 1] = '\0'; if(arg && x==1){ for(i=__b2c__len(buf[idx]); i>=0; i--) { if(buf[idx][i] == 46) break; }
if(i >= 0){ if(arg == 1) { buf[idx][i] = '\0'; __b2c__SETLEN(buf[idx], i);} if(arg == 2){ i++; memmove(buf[idx], buf[idx]+i, __b2c__len(buf[idx])-i+1);
__b2c__SETLEN(buf[idx], __b2c__len(buf[idx])-i);} } else if(arg == 2) {buf[idx][0] = '\0'; __b2c__SETLEN(buf[idx], 0);} } return(char*)(buf[idx]);}
static char **__b2c__Get_Args(char *line) { char **ptr = NULL; long start, x, collapse; long length = 0, amount = 0; collapse = __b2c__collapse; __b2c__collapse = 1; start = __b2c__delim_engine (2, &amount, line, " ", 0); ptr = (char**)calloc(amount, sizeof(char*));
for(x = 0; x < amount; x++) { start = __b2c__delim_engine_cache (1, &length, line, " ", x + 1); ptr[x] = __b2c__strndup(line+start, length); } ptr[x] = NULL; __b2c__collapse = collapse; return (ptr); }
char * __b2c__exec(int t, int l, char *k, char *cmd, char *str, int out) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int forking, length, dnull; ssize_t result = 0; int wpipe[2], rpipe[2]; char **args; char *ans = NULL;
idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char)); if (pipe (rpipe) < 0 || pipe (wpipe) < 0) { ERROR = 29; RUNTIMEFERR("EXEC$", ERROR, k, l); return(NULL); } if ((forking = fork ()) < 0) { ERROR = 29; RUNTIMEFERR("EXEC$", ERROR, k, l); return(NULL); }
else if (forking == 0) { fflush(stdout); close (wpipe[1]); close (rpipe[0]); dup2 (wpipe[0], STDIN_FILENO); close (wpipe[0]);	dnull = open("/dev/null", O_RDWR); if(out == 1) { dup2 (rpipe[1], STDOUT_FILENO); dup2(dnull, STDERR_FILENO); } else if (out == 2) { dup2(dnull, STDOUT_FILENO);
dup2(rpipe[1], STDERR_FILENO); } else { dup2(rpipe[1], STDOUT_FILENO); dup2(rpipe[1], STDERR_FILENO); } close (rpipe[1]); if(t == 0) { forking = system (cmd); if (WIFEXITED (forking)) result = WEXITSTATUS (forking); }
else { args = __b2c__Get_Args(cmd); if(execvp(args[0], args) < 0 ) { ERROR = 29; RUNTIMEFERR ("EXEC$", ERROR, k, l); return(NULL); } } close(dnull); __b2c_str_free(); _exit(result); } else { close (wpipe[0]); close (rpipe[1]); ans = (char*)malloc(512);
length = 0; if (str != NULL) result = write (wpipe[1], str, __b2c__len(str)); close (wpipe[1]); do { result = read (rpipe[0], ans, 512); if (result == -1) { ERROR = 30; RUNTIMEFERR("EXEC$", ERROR, k, l); return(NULL); }
if (result == 0) { break; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + result + 1); if (buf[idx] == NULL) { ERROR = 6; RUNTIMEFERR("EXEC$", ERROR, k, l); return(NULL); }
memcpy(buf[idx] + length, ans, (size_t)labs(result)); length += result; } while (result > 0); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\0';
close (rpipe[0]); free (ans); wait (&RETVAL); RETVAL = WEXITSTATUS (RETVAL); } return(char*)(buf[idx]); }
long __b2c__filestat(int l, char *k, const char *x, int check) { struct stat buf = { 0 }; int result; if(x == NULL) { if(check == 0) { return(-1); } return(0); } result = stat(x, &buf); if(result < 0 && check == 0)
{ ERROR = 24; RUNTIMEFERR("FILELEN", ERROR, k, l); return(-1); } if(check == 0) { return((long)buf.st_size); } if(buf.st_mode) { return(1); } return(0); }
int __b2c__filetype(int l, char *k, const char *file) { int type = 0; struct stat buf = { 0 }; if(file == NULL) { return(0); } if(lstat(file, &buf) < 0) { ERROR = 24; RUNTIMEFERR ("FILETYPE", ERROR, k, l); return(0); }
switch (buf.st_mode & S_IFMT) { case S_IFBLK: type = 4; break; case S_IFCHR: type = 3; break; case S_IFDIR: type = 2; break; case S_IFIFO: type = 5; break; case S_IFLNK: type = 6; break;
case S_IFREG: type = 1; break; case S_IFSOCK: type = 7; break; default: ERROR = 24; RUNTIMEFERR("FILETYPE", ERROR, k, l); return(0); break; } return(type); }
char * __b2c__fill(long amount, int txt) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char bf[5]; int x, len; if(amount < 0 || txt > 0x10FFFF) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } if (__b2c__option_utf8)
{ len = __b2c_utf8_conv (txt, bf); buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount*len+1); for (x = 0; x < (amount * len); x += len) { memcpy(buf[idx] + x, bf, len); } __b2c__SETLEN(buf[idx], amount * len); buf[idx][amount * len] = '\0'; } else
{ buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1); memset(buf[idx], txt, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\0'; } return(char*)(buf[idx]); }
char *__b2c__flatten(char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long len, x, pos=0, escaped=0; quote[0] = __b2c__option_dq; if(src == NULL) { return(src); }
if (meta == NULL) { meta = quote; } len = __b2c__len(src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1);
memmove(buf[idx], src, len); buf[idx][len] = '\0'; for(x = 0; src[x] != 0; x++) { if(src[x] == meta[0]) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); }
else { pos++; escaped = 0; } } else { if(src[x] == __b2c__option_esc) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); escaped = 1; } else { pos++; } }
else { pos++; escaped = 0; } } } __b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\0'; return(char*)(buf[idx]); }
char * __b2c__unflatten (char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long x, pos = 1; quote[0] = __b2c__option_dq; if (src == NULL) { return (src); }
if (meta == NULL) { meta = quote; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2*__b2c__len(src)+1); buf[idx][0] = meta[0];
for (x = 0; src[x] != 0; x++) { if (src[x] == meta[0]) { buf[idx][pos++] = __b2c__option_esc; buf[idx][pos++] = src[x]; } else {buf[idx][pos++] = src[x];} } buf[idx][pos++] = meta[0];
__b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\0'; return(char*)(buf[idx]); }
char *__b2c__getenv (char *env) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *result; long len; if(env == NULL) { return(NULL); } result = getenv(env); if(result == NULL) { return(NULL); } len = strlen(result); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], (len+1)*sizeof(char)); strncpy(buf[idx], result, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }
long __b2c__getch(void){long ch; struct termios oldt, newt; tcflush(STDIN_FILENO, TCIFLUSH); tcgetattr(STDIN_FILENO, &oldt); newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1;
newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt); ch = getchar(); tcsetattr(STDIN_FILENO, TCSANOW, &oldt); return(ch);}
long __b2c__getxy(int type){char asw[512]; struct termios old, cnew; int len, x = 0, y = 0; tcgetattr(STDIN_FILENO, &old); cnew = old; cnew.c_lflag &= ~(ICANON | ECHO); tcsetattr(STDIN_FILENO, TCSANOW, &cnew);
if(write(STDOUT_FILENO, "\033[6n", 4)>=0){len = read(STDIN_FILENO, asw, 512); asw[len] = '\0'; tcsetattr(STDIN_FILENO, TCSANOW, &old); sscanf(asw, "\033[%d;%dR", &y, &x);} if (!type) return(long)x; return(long)y;}
int __b2c__sortnrd(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(-1); else return(1);}
int __b2c__sortnrd_wrap(const void *a, const void *b) { return(__b2c__sortnrd(*(void**)a, *(void**)b)); }
int __b2c__sortnrd_down(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(1); else return(-1);}
int __b2c__sortnrd_wrap_down(const void *a, const void *b) { return(__b2c__sortnrd_down(*(void**)a, *(void**)b)); }
int __b2c__sortnrf(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(-1); else return(1);}
int __b2c__sortnrf_wrap(const void *a, const void *b) { return(__b2c__sortnrf(*(void**)a, *(void**)b)); }
int __b2c__sortnrf_down(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(1); else return(-1);}
int __b2c__sortnrf_wrap_down(const void *a, const void *b) { return(__b2c__sortnrf_down(*(void**)a, *(void**)b)); }
int __b2c__sortnrl(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(-1); else return(1);}
int __b2c__sortnrl_wrap(const void *a, const void *b) { return(__b2c__sortnrl(*(void**)a, *(void**)b)); }
int __b2c__sortnrl_down(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(1); else return(-1);}
int __b2c__sortnrl_wrap_down(const void *a, const void *b) { return(__b2c__sortnrl_down(*(void**)a, *(void**)b)); }
int __b2c__sortnri(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(-1); else return(1);}
int __b2c__sortnri_wrap(const void *a, const void *b) { return(__b2c__sortnri(*(void**)a, *(void**)b)); }
int __b2c__sortnri_down(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(1); else return(-1);}
int __b2c__sortnri_wrap_down(const void *a, const void *b) { return(__b2c__sortnri_down(*(void**)a, *(void**)b)); }
int __b2c__sortnrs(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(-1); else return(1);}
int __b2c__sortnrs_wrap(const void *a, const void *b) { return(__b2c__sortnrs(*(void**)a, *(void**)b)); }
int __b2c__sortnrs_down(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(1); else return(-1);}
int __b2c__sortnrs_wrap_down(const void *a, const void *b) { return(__b2c__sortnrs_down(*(void**)a, *(void**)b)); }
int __b2c__sortnrc(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(-1); else return(1);}
int __b2c__sortnrc_wrap(const void *a, const void *b) { return(__b2c__sortnrc(*(void**)a, *(void**)b)); }
int __b2c__sortnrc_down(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(1); else return(-1);}
int __b2c__sortnrc_wrap_down(const void *a, const void *b) { return(__b2c__sortnrc_down(*(void**)a, *(void**)b)); }
int __b2c__sortstr(const void *a, const void *b)
{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)a, *(char **)b);}
int __b2c__sortstr2(const void *a, const void *b)
{if(a == NULL) return(-1); if(b == NULL) return(1); return strcmp((char*)a, (char*)b);}
int __b2c__sortstr_down(const void *a, const void *b)
{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)b, *(char **)a);}
typedef struct __b2c__htable { char *key[65536]; void *value[65536]; char *index[65536]; int total; struct __b2c__htable *next; } __b2c__htable;
const char *__b2c__hash_key_collect(int n, const char *first, ...) { static char *keys[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } if (n == 1) { return (first); }
idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (keys[idx]) { buflen = __b2c__RBUFSIZE(keys[idx]); } cnew = __b2c__len(first); if(cnew >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], cnew); buflen = __b2c__RBUFSIZE(keys[idx]); }
memcpy(keys[idx], first, cnew); length += cnew; n--; va_start (ap, first); while (n) { next = va_arg (ap, char *); if (next) { cnew = __b2c__len (next); if(length + cnew + 1 >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], (length + cnew + 1 + 1) * sizeof (char));
buflen = __b2c__RBUFSIZE(keys[idx]); } keys[idx][length] = 32; length++; memmove (keys[idx] + length, next, cnew); length += cnew; } n--; } va_end (ap); __b2c__SETLEN(keys[idx], length); keys[idx][length] = '\0'; return ((char *) keys[idx]); }
#define __b2c__KEYCOLLECT(...) __b2c__hash_key_collect(sizeof((const char*[]){__VA_ARGS__}) / sizeof(char*), __VA_ARGS__, NULL)
uint64_t __b2c__HashFNV1a_64(const char *key, int len){ uint64_t hash = 14695981039346656037UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 1099511628211 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 1099511628211 * (hash ^ *key); key++; } } return(hash); }
uint32_t __b2c__HashFNV1a_32(const char *key, int len){ uint32_t hash = 2166136261UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 16777619 * (hash ^ *key); key++; } } return(hash); }
#define __b2c__HashFNV1a_16(x) __b2c__HashFNV1a_16_new(x, 0)
uint16_t __b2c__HashFNV1a_16_new(const char *key, int len) { uint32_t hash = 2166136261UL; if (key == NULL) { return (0); } if (len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else
{ while (*key) { hash = 16777619 * (hash ^ *key); key++; } } return ((hash >> 16) ^ (hash & 0xffff)); }
__b2c__htable *__b2c__hash_new(void) { __b2c__htable *name; name = (__b2c__htable*)calloc(1, sizeof(__b2c__htable)); name->next = NULL; name->total = 0; return(name); }
__b2c__htable* __b2c__hash_find_key_do(__b2c__htable *name, unsigned short hash, const char *key) { if(key == NULL || name == NULL) { return(NULL); } if(hash == 0) { hash = __b2c__HashFNV1a_16(key); } do
{ if(name->key[hash] && !strcmp(name->key[hash], key)) { return(name); } name = name->next; } while(name); return(NULL); }
#define __b2c__hash_find_key(x, y, ...) __b2c__hash_find_key_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))
void *__b2c__hash_find_value_do(__b2c__htable *name, const char *key) { __b2c__htable *table; unsigned short pos; if(name == NULL || key == NULL) { return(NULL); } pos = __b2c__HashFNV1a_16(key); table = __b2c__hash_find_key(name, pos, key);
if(table) { return(table->value[pos]); } return(NULL); }
#define __b2c__hash_find_value(x, ...) __b2c__hash_find_value_do(x, __b2c__KEYCOLLECT(__VA_ARGS__))
void __b2c__hash_add_do(__b2c__htable *name, const void *value, int flag, unsigned int len, const char *key) { unsigned short hash; if(name == NULL) { return; } hash = __b2c__HashFNV1a_16(key);
while(1) { if(name->key[hash] == NULL) { name->total++; break; } if(!strcmp(name->key[hash], key)) { if(flag != 2) { break; } } if(name->next) { name = name->next; } else { name->next = __b2c__hash_new(); name = name->next;} }
if(!name->key[hash]) { name->key[hash] = __b2c_Copy_String(name->key[hash], (char*)key); name->index[name->total-1] = name->key[hash]; } if(flag == 0) { if(!name->value[hash]) { name->value[hash] = calloc(1, sizeof(void*)); } memcpy(name->value[hash], value, sizeof(void*)); }
else if(flag == 3) { name->value[hash] = realloc(name->value[hash], len); memcpy(name->value[hash], value, len); } else { name->value[hash] = __b2c_Copy_String((char*)name->value[hash], (char*)value); } }
#define __b2c__hash_add(x, y, ...) __b2c__hash_add_do(x, y, 0, 0, __b2c__KEYCOLLECT(__VA_ARGS__))
#define __b2c__hash_add_str(x, y, ...) __b2c__hash_add_do(x, y, 1, 0, __b2c__KEYCOLLECT(__VA_ARGS__))
#define __b2c__hash_add_redundant(x, y, ...) __b2c__hash_add_do(x, y, 2, 0, __b2c__KEYCOLLECT(__VA_ARGS__))
#define __b2c__hash_add_data(x, y, len, ...) __b2c__hash_add_do(x, y, 3, len, __b2c__KEYCOLLECT(__VA_ARGS__))
void *__b2c__hash_realloc_str_value_do(__b2c__htable *name, int len, const char *key) { __b2c__htable *table; unsigned short pos; if (name == NULL || key == NULL) { return (NULL); } __b2c__hash_add_str(name, "", key); pos = __b2c__HashFNV1a_16(key);
table = __b2c__hash_find_key(name, pos, key); table->value[pos] = realloc(table->value[pos], len); return (table->value[pos]); }
#define __b2c__hash_realloc_str_value(x, y, ...) __b2c__hash_realloc_str_value_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))
void __b2c__hash_del_do(__b2c__htable *name, int rebuild, const char *key) { __b2c__htable *found; unsigned short pos; int i, which; if(name == NULL) { return; } pos = __b2c__HashFNV1a_16(key); found = __b2c__hash_find_key(name, pos, key);
if(found) { if (rebuild) { for (i = 0; i < found->total; i++) { which = __b2c__HashFNV1a_16(found->index[i]); if (which == pos) { if(i != found->total-1) { found->index[i] = found->index[found->total-1]; } found->index[found->total-1] = NULL; break; } } }
__b2c__STRFREE(found->key[pos]); found->key[pos] = NULL; if(found->value[pos]) { __b2c__STRFREE(found->value[pos]); } found->value[pos] = NULL; found->total -= 1; } }
#define __b2c__hash_del(x, ...) __b2c__hash_del_do(x, 1, __b2c__KEYCOLLECT(__VA_ARGS__))
#define __b2c__hash_del_norebuild(x, ...) __b2c__hash_del_do(x, 0, __b2c__KEYCOLLECT(__VA_ARGS__))
void __b2c__hash_clear_do(__b2c__htable *name, int regex) { __b2c__htable *orig, *next; int i; orig = name; while(name) { for(i = 0; i < 65536; i++) { if(name->key[i]) { __b2c__STRFREE(name->key[i]); } name->key[i] = NULL;
if(name->value[i]) { if(regex) { regfree(&(*(regex_t*)name->value[i])); } __b2c__STRFREE(name->value[i]); } name->value[i] = NULL; } next = name->next; name->next = NULL; name->total = 0; if(name != orig) { free(name); } name = next; } }
#define __b2c__hash_clear(x) __b2c__hash_clear_do(x, 0)
#define __b2c__hash_clear_regfree(x) __b2c__hash_clear_do(x, 1)
int __b2c__hash_nrkeys(__b2c__htable *name) { int total = 0; while(name) { total += name->total; name = name->next; } return(total); }
void __b2c__hash_dup_do(__b2c__htable *from, __b2c__htable *to, int flag) { int i; char *value; while(from) { for(i = 0; i < 65536; i++) { if(from->key[i]) { value = (char*)__b2c__hash_find_value(from, from->key[i]); if(flag==0) { __b2c__hash_add(to, value, from->key[i]); } 
else { __b2c__hash_add_str(to, value, from->key[i]); } } } from = from->next; if(to->next == NULL) { to->next = __b2c__hash_new(); } to = to->next; } }
#define __b2c__hash_dup(x, y) __b2c__hash_dup_do(x, y, 0)
#define __b2c__hash_dup_str(x, y) __b2c__hash_dup_do(x, y, 1)
char *__b2c__hash_obtain(__b2c__htable *name, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long ctr, dlen, len, total = 0; if(name == NULL) { return (NULL); } if(delim == NULL) { delim = __b2c__option_delim; }
if(name->total == 0) { return (NULL); } dlen = __b2c__len(delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen); do { for(ctr=0; ctr < name->total; ctr++) { len = __b2c__len(name->index[ctr]);
buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+len+dlen); memmove(buf[idx] + total, name->index[ctr], len); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } name = name->next; }
while(name); __b2c__SETLEN(buf[idx], total-dlen); buf[idx][total-dlen] = '\0'; return((char*)buf[idx]); }
char *__b2c__hash_obtain_by_sort(int l, char *k, __b2c__htable * name, char *delim, int up_down, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; void **values = { NULL }; char **keys = { NULL }; void **dups = { NULL }; __b2c__htable *ptr, *inv; int i, j, pos = 0, start = 0, cur = 0; long dlen, len, total = 0;
unsigned short loc; char *value; char bf[32 + 1] = { 0 }; if (name == NULL || name->total == 0) { return (NULL); } if (delim == NULL) { delim = __b2c__option_delim; } values = (void **) calloc (__b2c__hash_nrkeys (name), sizeof (char *)); inv = __b2c__hash_new (); ptr = name; do { for(i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16(ptr->index[i]); switch(type)
{ case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (bf, 32, "%g", *(double *) ptr->value[loc]); value = bf; break; case 2: snprintf (bf, 32, "%g", *(float *) ptr->value[loc]); value = bf; break;
case 3: snprintf (bf, 32, "%ld", *(long *) ptr->value[loc]); value = bf; break; case 4: snprintf (bf, 32, "%d", *(int *) ptr->value[loc]); value = bf; break; case 5: snprintf (bf, 32, "%d", *(short *) ptr->value[loc]); value = bf; break;
case 6: snprintf (bf, 32, "%d", *(char *) ptr->value[loc]); value = bf; break; default: ERROR = 43; RUNTIMEFERR("OBTAIN$", ERROR, k, l); return(NULL); } __b2c__hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr);
switch (type) { case 0: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortstr); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortstr_down); } break; case 1: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrd_wrap); }
else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrd_wrap_down); } break; case 2: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrf_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrf_wrap_down); } break;
case 3: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrl_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrl_wrap_down); } break; case 4: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnri_wrap); }
else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnri_wrap_down); } break; case 5: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrs_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrs_wrap_down); } break;
case 6: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrc_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrc_wrap_down); } break; } dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen);
keys = (char**)calloc(__b2c__hash_nrkeys(name), sizeof(char*)); dups = (void**)calloc(__b2c__hash_nrkeys(name), sizeof(void*)); for(i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc(32, sizeof(char)); } switch (type)
{ case 0: keys[i] = __b2c__strdup((char*)values[i]); break; case 1: snprintf (keys[i], 32, "%g", *(double *) values[i]); break; case 2: snprintf(keys[i], 32, "%g", *(float*)values[i]); break;
case 3: snprintf(keys[i], 32, "%ld", *(long *) values[i]); break; case 4: snprintf(keys[i], 32, "%d", *(int *) values[i]); break; case 5: snprintf(keys[i], 32, "%d", *(short*)values[i]); break; case 6:
snprintf(keys[i], 32, "%d", *(char *) values[i]); break; } dups[i] = __b2c__strdup((char*)__b2c__hash_find_value_do (inv, keys[i])); __b2c__hash_del_norebuild (inv, keys[i]); }
do { if(type == 0) { while(cur < pos-1 && !strcmp(keys[cur], keys[cur+1])) { cur++; } } else { while(cur < pos-1 && !memcmp(keys[cur], keys[cur+1], sizeof(void*))) { cur++; } } qsort (&dups[start], cur-start+1, sizeof (char *), __b2c__sortstr);
for (j = start; j <= cur; j++) { len = __b2c__len ((char *) dups[j]); buf[idx] = (char*)__b2c_str_realloc(buf[idx], total + len + dlen);
memmove(buf[idx] + total, dups[j], len); free(dups[j]); free(keys[j]); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } cur++; start = cur; } while(cur < pos);
__b2c__hash_clear (inv); free(inv); free(values); free(dups); free(keys); total -= dlen; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return((char*)buf[idx]); }
int __b2c__lookup_by_order(__b2c__htable *name, char ***array, int size, int base) { int i, count = 0; if(name) { if(*array) { __b2c__free_str_array_members (&(*array), base, size); free(*array); } *array = (char **)calloc(__b2c__hash_nrkeys(name)+base, sizeof(char*));
count = base; do { for(i = 0; i < name->total; i++) { (*array)[count] = __b2c_Copy_String((*array)[count], name->index[i]); count++; } name = name->next; } while(name); count -= base; } return(count); }
int __b2c__lookup_by_sort (__b2c__htable * name, char ***array, int size, int base, int type, int (*compare)(const void*, const void*)) { void **values = { NULL }; char **keys = { NULL }; __b2c__htable *ptr, *inv; char *value; int i, j, pos = 0, count = 0, cur = 0, start = 0; unsigned short loc; char buf[32 + 1] = { 0 };
if (*array) { __b2c__free_str_array_members (&(*array), base, size); free (*array); } if (name) { values = (void **) calloc (__b2c__hash_nrkeys (name), sizeof (char *)); inv = __b2c__hash_new (); ptr = name; do
{ for(i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16 (ptr->index[i]); switch (type) { case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (buf, 32, "%g", *(double *) ptr->value[loc]); value = buf; break; case 2: snprintf (buf, 32, "%g", *(float *) ptr->value[loc]); value = buf;
break; case 3: snprintf (buf, 32, "%ld", *(long *) ptr->value[loc]); value = buf; break; case 4: snprintf (buf, 32, "%d", *(int *) ptr->value[loc]); value = buf; break; case 5: snprintf (buf, 32, "%d", *(short *) ptr->value[loc]); value = buf; break; case 6: snprintf (buf, 32, "%d", *(char *) ptr->value[loc]);
value = buf; break; } __b2c__hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr); qsort (&values[0], pos, sizeof (void *), compare); *array = (char**)calloc(__b2c__hash_nrkeys(name) + base, sizeof(char*)); keys = (char**)calloc(__b2c__hash_nrkeys(name) + base, sizeof(char*));
count = base; for (i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc(32, sizeof(char)); } switch (type) { case 0: keys[i] = __b2c__strdup((char*)values[i]); break; case 1: snprintf(keys[i], 32, "%g", *(double *) values[i]); break; case 2: snprintf(keys[i], 32, "%g", *(float *) values[i]); break;
case 3: snprintf(keys[i], 32, "%ld", *(long *) values[i]); break; case 4: snprintf(keys[i], 32, "%d", *(int *) values[i]); break; case 5: snprintf(keys[i], 32, "%d", *(short *) values[i]); break; case 6: snprintf(keys[i], 32, "%d", *(char *) values[i]); break; }
value = (char*)__b2c__hash_find_value_do(inv, keys[i]); (*array)[count++] = __b2c__strdup (value); __b2c__hash_del_norebuild (inv, keys[i]); } do { if (type == 0) { while (cur < pos - 1 && !strcmp (keys[cur], keys[cur + 1])) { cur++; } } else { while (cur < pos - 1 && !memcmp (keys[cur], keys[cur + 1], sizeof(void*))) { cur++; }}
qsort(&(*array)[start+base], cur - start + 1, sizeof(char*), __b2c__sortstr); for (j = start; j <= cur; j++) { free (keys[j]); } cur++; start = cur; } while (cur < pos); __b2c__hash_clear (inv); free (inv); free (values);
free (keys); count -= base; } return (count); }
char * __b2c__insert (int l, char *k, char *src, int pos, char *str) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, tot, blen; if (str == NULL) { return (src); } if (src == NULL) { return(str); } len = __b2c__len (src); tot = __b2c__len (str);
idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+tot+1); pos--; if (pos <= 0) { memmove(buf[idx], str, tot); memmove(buf[idx] + tot, src, len); } else if (pos > len) { memmove(buf[idx], src, len);
memmove(buf[idx] + len, str, tot); } else { if (__b2c__option_utf8) { blen = __b2c__blen (l, k, "INSERT$", src, pos, 0); memmove(buf[idx], src, blen); memmove(buf[idx] + blen, str, tot);
memmove(buf[idx] + blen + tot, src + blen, len - blen); } else { memmove(buf[idx], src, pos); memmove(buf[idx] + pos, str, tot); memmove(buf[idx] + pos + tot, src + pos, len - pos); } }
__b2c__SETLEN(buf[idx], len + tot); buf[idx][len + tot] = '\0'; return(char*)(buf[idx]); }
long __b2c__instr(int l, char *k, char *first, char *tmp, int pos) { char *result; if (first == NULL) { return (0); } if (tmp == NULL || __b2c__len (tmp) == 0) { return (0); } if (pos <= 0) {  pos = 1; }
result = strstr (first + pos - 1, tmp); if(result == NULL) {  return (0); } if (__b2c__option_utf8) { return (long) __b2c__ucs2_clen (l, k, "INSTR", first, result - first + 1); } return (long) (result - first + 1); }
long __b2c__instrrev(int m, char *k, char *first, char *tmp, int pos) { char *result, *found; long l; if (first == NULL){ return (0);} if (tmp == NULL || __b2c__len (tmp) == 0) { return (0); } if (pos < 0) { pos = 0; }
l = __b2c__len (first); found = first; do { result = strstr (found, tmp); if (result != NULL && result <= first + l - pos) { found = result + 1; continue; } if (result > first + l - pos) result = NULL; } while (result != NULL);
if (__b2c__option_startpoint) { if (l - (found - first) + 1 > l) { return(0); } if (__b2c__option_utf8) { return (long) (__b2c__ulen (l, k, "INSTRREV", first, -1) - __b2c__ucs2_clen (l, k, "INSTRREV", first, found - first) + 1); }
return (long) (l - (found - first) + 1); } if (__b2c__option_utf8) { return (long) __b2c__ucs2_clen (m, k, "INSTRREV", first, found - first); } return (long) (found - first); }
char * __b2c__lcase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } len = __b2c__len (src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); if (__b2c__option_utf8) { local = setlocale (LC_ALL, ""); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR ("LCASE$", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t));
if(mbstowcs(wcs, src, mbslen + 1) == (size_t)-1) { ERROR = 38; RUNTIMEFERR ("LCASE$", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towlower (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t)-1) { ERROR = 38; RUNTIMEFERR ("LCASE$", ERROR, k, l); return(NULL); } free (wcs);
setlocale (LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = tolower(src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }
char * __b2c__left(int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len (src);
if (n > (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, "LEFT$", src, length) : length)) { return(src); } else { if (__b2c__option_utf8)
{ n = __b2c__blen (l, k, "LEFT$", src, n, 0); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], n+1); memmove(buf[idx], src, n); __b2c__SETLEN (buf[idx], n); buf[idx][n] = '\0'; } return(char*)(buf[idx]); }
char* __b2c__load(int flag, int l, char *k, char *file) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; FILE *handle; struct stat bf; void* mem; handle = fopen ((const char*)file, "r"); if(handle == NULL)
{ ERROR = 2; RUNTIMEFERR ("LOAD$/BLOAD", ERROR, k, l); return(NULL); } if(stat(file, &bf) < 0) { ERROR = 24; RUNTIMEFERR ("LOAD$/BLOAD", ERROR, k, l); return(NULL); } if(flag) { mem = calloc(bf.st_size+__b2c__option_memstream, sizeof(char));
if(fread (mem, sizeof (char), bf.st_size, handle) != (size_t)bf.st_size) { ERROR = 2; RUNTIMEFERR("BLOAD", ERROR, k, l); return(NULL); } fclose(handle); return(char*)(mem); } else
{ idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], bf.st_size + 1); if(fread(buf[idx], sizeof (char), bf.st_size, handle) != (size_t)bf.st_size)
{ ERROR = 2; RUNTIMEFERR ("LOAD$", ERROR, k, l); return(NULL); } __b2c__SETLEN(buf[idx], bf.st_size); buf[idx][bf.st_size] = '\0'; fclose(handle); return(char*)(buf[idx]); } }
char *__b2c__mid(int l, char *k, char **swap, int type, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); }
idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } src_len = __b2c__len (src); pos -= 1; if (pos < 0) { pos = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, "MID$", src, src_len) : src_len) + 1 + pos; } if (__b2c__option_utf8) { pos = __b2c__blen (l, k, "MID$", src, pos, 0); }
if (pos > src_len) { if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); } if (__b2c__option_utf8 && length >= 0) { length = __b2c__blen (l, k, "MID$", src + pos, length, 0); } if (length < 0 || pos + length > src_len) { length = src_len - pos; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + 1); memmove (buf[idx], src + pos, length); __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\0'; if (type == 1) { return (__b2c_Swap_String (swap, &buf[idx])); } return(char*)(buf[idx]); }
char *__b2c__os(int l, char *k) { static char *result = NULL ; struct utsname bf; unsigned int len = 0; if(!result) { result = (char*)__b2c_str_realloc(result, 256 * sizeof (char)); if (uname(&bf) < 0)
{ ERROR = 26; RUNTIMEFERR("OS$", ERROR, k, l); return(NULL); } strncpy(result, bf.sysname, 64); len += strlen(bf.sysname); strncat(result, " ", 2); len++; strncat(result, bf.machine, 128);
len += strlen(bf.machine); __b2c__SETLEN(result, len); result[len] = '\0'; } return(char*)result; }
void *__b2c__peek_check(int l, char *k, char *x, int size) { if(!__b2c__memory__check((char*)x, size)) { ERROR=1; RUNTIMEFERR("PEEK", ERROR, k, l); } return((void*)x); }
char * __b2c__right (int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len (src);
if (n > (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, "RIGHT$", src, length) : length)) { return(src); } else { if (__b2c__option_utf8)
{ n = __b2c__blen (l, k, "RIGHT$", src, n, 1); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], n+1); memmove(buf[idx], src + length - n, n); __b2c__SETLEN(buf[idx], n); buf[idx][n] = '\0'; } return(char*)(buf[idx]); }
char *__b2c__rip(int l, char *k, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { return (NULL); } src_len = __b2c__len (src); pos -= 1;
if (pos < 0) { pos = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, "RIP$", src, src_len) : src_len) + 1 + pos; } if (__b2c__option_utf8) { pos = __b2c__blen (l, k, "RIP$", src, pos, 0); } if (pos > src_len)
{ return (NULL); } if (__b2c__option_utf8 && length >= 0) { length = __b2c__blen (l, k, "RIP$", src + pos, length, 0); } if (length < 0 || pos + length > src_len)
{ length = src_len - pos; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], src_len); memmove(buf[idx], src, pos); memmove(buf[idx]+pos, src+pos+length, src_len-pos-length);
__b2c__SETLEN(buf[idx], src_len-length); buf[idx][src_len-length] = '\0'; return(char*)(buf[idx]); }
long __b2c__screen(int type){long x; struct winsize tmp; ioctl(STDOUT_FILENO, TIOCGWINSZ, &tmp); if(type) { x = tmp.ws_row; } else { x = tmp.ws_col; } return(x); }
char *__b2c__spc(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; if(amount <= 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);
memset(buf[idx], 32, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\0'; return(char*)(buf[idx]); }
char *__b2c__tab(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; if(amount <= 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);
memset(buf[idx], 9, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\0'; return(char*)(buf[idx]); }
long __b2c__tally(char *haystack, char *needle, int pos) { char *res; long total = 0; if (haystack == NULL) { return (0); }
if (needle == NULL || __b2c__len(needle) == 0) { return (0); } if (pos <= 0) { pos = 1; }
haystack+=pos-1; while((res = strstr(haystack, needle)) != NULL) { haystack = res+1; total++; } return((long)total); }
/* API >>>> nr == 0, use_cache == 0 : rebuild cache | nr != 0, use_cache == 0 : dynamic calc member | nr != 0, use_cache == 1 : use member from cache */
long __b2c__delim_engine_core(int action, int type, long *returned_value, char *string, char *delim, long nr, int use_cache) { static long *cache = NULL, cache_tot = 0, cnt = 0; long x, len, pos = 0, start = 0; int in_string = 0, is_escaped = 0; if(action == 0) { if(cache) { free(cache); cache = NULL; } return(0); } *returned_value = 0; if (string == NULL || string[0] == 0) { return (0); }
if (delim == NULL) { delim = __b2c__option_delim; } len = __b2c__len (delim); if(!use_cache) { cnt = 0; for (x = 0; string[x] != 0; x++) { if (!in_string) { if (len == 1 ? string[x] == delim[0] : !strncmp (string + x, delim, len)) { if (__b2c__collapse == 0 || x > start) { cnt++; if (cnt > cache_tot)
{ cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start; cache[cnt * 2 + 1] = start; } if(nr && nr == cnt) { break; } start = x + len; } } if (string[x] == __b2c__option_esc) { if (!is_escaped) { is_escaped = 1; } else { is_escaped = 0; } } else if (string[x] == __b2c__option_dq)
{ if (!is_escaped && __b2c__option_quoted) { in_string = 1 - in_string; } is_escaped = 0; } else { is_escaped = 0; } } if (__b2c__collapse == 0 || x > start) { cnt++; if (cnt > cache_tot) { cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start;
cache[cnt * 2 + 1] = start; } } if (nr <= cnt) { if (type == 1) { *returned_value = cache[nr*2]; pos = cache[nr*2+1]; } else { *returned_value = cnt; pos = cache[nr*2+1]; } } return(pos); }
char *__b2c__token(char *string, long nr, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long length = 0; if (string == NULL || nr < 1) { return (NULL); }
start = __b2c__delim_engine(1, &length, string, delim, nr); if(length == 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }
buf[idx] = (char*)__b2c_str_realloc(buf[idx], length+1); memmove(buf[idx], string + start, length); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\0'; return(char*)(buf[idx]); }
long __b2c__where (char *string, long nr, char *delim) { long result = 0, length = 0; if (string == NULL || nr < 1) { return (0); } result = __b2c__delim_engine (1, &length, string, delim, nr); return(result+1); }
long __b2c__amount(char *string, char *delim) { long amount = 0; if (string == NULL) { return (0); } __b2c__delim_engine(2, &amount, string, delim, 0); return(amount); }
int __b2c__hasdelim (char *string, char *delim) { long length = 0; long start = 0; if (string == NULL) { return (0); }
start = __b2c__delim_engine (2, &length, string, delim, 2); if(start == 0) { return (0); } if (delim == NULL) { delim = __b2c__option_delim; } return (start-__b2c__len (delim)+1); }
char *__b2c__change(char *string, int index, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long tlen, start, len, nlen; long length = 0; if(string == NULL) { return(cnew); }
if (index <= 0) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine(1, &length, string, delim, index); len = length; tlen = __b2c__len(string); nlen = __b2c__len(cnew);
buf[idx] = (char*)__b2c_str_realloc(buf[idx], tlen-len+nlen+1); memmove(buf[idx], string, start); memmove(buf[idx] + start, cnew, nlen); memmove(buf[idx] + start + nlen, string + start + len, tlen - (start + len));
__b2c__SETLEN(buf[idx], tlen - len + nlen); buf[idx][tlen-len+nlen] = '\0'; return(char*)(buf[idx]); }
long __b2c__istoken(char *string, char *token, char *delim) { long len, start, x, result = 0; long length = 0, amount = 0; if(string == NULL) { return(0); } if(delim == NULL)
{ delim = __b2c__option_delim; } len = __b2c__len(token); if(len==0) { return(0); } start = __b2c__delim_engine (2, &amount, string, delim, 0); for(x = 0; x < amount; x++)
{ start = __b2c__delim_engine_cache(1, &length, string, delim, x+1); if(len == length && memcmp(string + start, token, len) == 0) { result = x+1; break; } } return (result); }
char *__b2c__uniq(char *string, char *delim) { long x, start, amount = 0, length = 0; int t = 1; __b2c__htable *table; char *item, *result; if(string == NULL) { return (string); }
if(delim == NULL) { delim = __b2c__option_delim; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if(amount <= 1) { return (string); }
table = __b2c__hash_new(); for (x = 0; x < amount; x++) { start = __b2c__delim_engine_cache(1, &length, string, delim, x+1); item = __b2c__strndup(string+start, length);
if(!__b2c__hash_find_key(table, 0, item)) { __b2c__hash_add(table, &t, item); } __b2c__STRFREE(item); } result = __b2c__hash_obtain(table, delim);
__b2c__hash_clear(table); free(table); return(result); }
char *__b2c__sort(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char **array; char *buffer, *backup; long start, total = 0, x, len, dlen; long amount = 0; long length = 0;
if(string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1);
buffer = __b2c__strdup (string); backup = buffer; start = __b2c__delim_engine (2, &amount, buffer, delim, 0); array = (char **) calloc(amount, sizeof (char *)); for (x = 0; x < amount; x++)
{ start = __b2c__delim_engine (1, &length, string, delim, 1); buffer[start + length] = '\0'; if(buffer[start] == 34 && buffer[start+length-1] == 34) { buffer[start + length-1] = '\0';
array[x] = buffer + start + 1; } else { array[x] = buffer + start; } string += (start + length + dlen); buffer += (start + length + dlen); } qsort (&array[0], amount, sizeof (char *), __b2c__sortstr);
for (x = 0; x < amount; x++) { len = strlen (array[x]); if(strstr(array[x], delim)) { buf[idx][total] = 34; memmove(buf[idx] + total+1, array[x], len);
buf[idx][total+len+1] = 34; total += len+2;} else { memmove(buf[idx] + total, array[x], len); total += len; } if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen);
total += dlen; } } __b2c__STRFREE(backup); free(array); __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }
char *__b2c__delim(char *string, char *from, char *to) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x, tlen, dlen; long amount = 0; long length = 0; if (string == NULL) { return (string); }
if(from == NULL) { from = __b2c__option_delim; } if(to == NULL) { to = __b2c__option_delim; } dlen = __b2c__len (from); tlen = __b2c__len (to); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, from, 0);
buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+amount*tlen+1); for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, from, 1); memmove(buf[idx] + total, string + start, length);
total += length; if (x < amount-1) { memmove(buf[idx] + total, to, tlen); total += tlen; } string += (start + length + dlen); } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }
char *__b2c__head (char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long amount = 0; long length = 0; if (string == NULL)
{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);
if(amount < 1 || pos < 1) { return (NULL); } if (pos > amount) { pos = amount; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1); start = __b2c__delim_engine_cache(1, &length, string, delim, pos);
memmove(buf[idx], string, start + length); __b2c__SETLEN(buf[idx], start + length); buf[idx][start + length] = '\0'; return(char*)(buf[idx]); }
char *__b2c__tail(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL)
{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);
if (amount < 1 || pos < 1) { return (NULL); } if (amount - pos + 1 < 1) { pos = 1; } else { pos = amount - pos + 1; } slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen+1);
start = __b2c__delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\0'; return(char*)(buf[idx]); }
char *__b2c__append(char **swap, int type, char *string, long pos, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, slen, nlen, total = 0; long amount = 0; long length = 0; if (cnew == NULL || pos < 0)
{ if (type == 1) { *swap = __b2c_Copy_String(*swap, string); } return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);
dlen = __b2c__len (delim); nlen = __b2c__len (cnew); slen = __b2c__len (string); buf[idx] = (char *) __b2c_str_realloc (buf[idx], slen + nlen + dlen + 1); if (pos == 0 || pos > amount) { if (__b2c__collapse == 0 || (__b2c__collapse == 1 && slen > 0)) { memmove (buf[idx], string, slen);
total += slen; } if (__b2c__collapse == 0 || (__b2c__collapse == 1 && nlen > 0)) { if(__b2c__collapse == 0 || total) { memmove (buf[idx] + total, delim, dlen); total += dlen; } memmove (buf[idx] + total, cnew, nlen); total += nlen; } } else { start = __b2c__delim_engine_cache (1, &length, string, delim, pos);
memmove (buf[idx], string, start); total += start; memmove (buf[idx] + total, cnew, nlen); total += nlen; memmove (buf[idx] + total, delim, dlen); total += dlen; memmove (buf[idx] + total, string + start, slen - start); total += (slen - start); } __b2c__SETLEN (buf[idx], total);
buf[idx][total] = '\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }
char *__b2c__del(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen, dlen, total = 0; long amount = 0; long length = 0; if (string == NULL)
{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos < 1 || pos > amount)
{ return(string); } dlen = __b2c__len (delim); slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1); start = __b2c__delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string, start);
total += start; if (pos < amount) { memmove(buf[idx] + total, string + start + length + dlen, slen-(start + length + dlen)); total += slen-(start + length + dlen); }
else { if(total >= dlen) { total -= dlen; } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }
char * __b2c__proper(int l, char *k, char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *local; long start, total = 0, x, y, dlen, blen; long amount = 0; long length = 0; wchar_t wcs[8] = { 0 }; if (string == NULL) { return (string); }
if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); start = __b2c__delim_engine (2, &amount, string, delim, 0); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string)+1); if(__b2c__option_utf8)
{ local = setlocale (LC_ALL, ""); for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1); blen = __b2c__blen (l, k, "PROPER$", string + start, 1, 0); if (mbtowc (wcs, string + start, blen) == (int) - 1) { ERROR = 38; RUNTIMEFERR ("PROPER$", ERROR, k, l); return(NULL); }
*wcs = towupper (*wcs); if (wctomb(buf[idx] + total, *wcs) == (int) -1) { ERROR = 38; RUNTIMEFERR ("PROPER$", ERROR, k, l); return(NULL); } for (y = blen; y < length; y += blen) { blen = __b2c__blen (l, k, "PROPER$", string + start + y, 1, 0); if (mbtowc (wcs, string + start + y, blen) == (int) - 1)
{ ERROR = 38; RUNTIMEFERR ("PROPER$", ERROR, k, l); return(NULL); } if(__b2c__option_proper == 0) { *wcs = towlower (*wcs); } if (wctomb(buf[idx] + total + y, *wcs) == (int) - 1) { ERROR = 38; RUNTIMEFERR ("PROPER$", ERROR, k, l); return(NULL); } } total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen);
total += dlen; } string += (start + length + dlen); } setlocale (LC_ALL, local); } else { for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1); *(buf[idx] + total) = toupper(*(string+start)); for (y = 1; y < length; y ++) { *(buf[idx]+total+y) = (__b2c__option_proper == 0 ? tolower(*(string+start+y)) : *(string+start+y)); }
total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen); total += dlen; } string += (start + length + dlen); } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }
char *__b2c__last (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }
idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1);
start = __b2c__delim_engine_cache(1, &length, string, delim, pos+1); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\0'; return(char*)(buf[idx]); }
char * __b2c__first (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long dlen, end; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }
idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } end = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string)+1);
end = __b2c__delim_engine_cache(1, &length, string, delim, amount-pos+1); dlen = __b2c__len (delim); memmove(buf[idx], string, end-dlen); __b2c__SETLEN(buf[idx], end-dlen); buf[idx][end-dlen] = '\0'; return(char*)(buf[idx]); }
int __b2c__match(char *string1, char *string2, long count, char *delim) { long dlen, start1, start2, amount1, amount2, length1, length2, tmplen; int x, found = 1, wildcard = 0, after = 0; if (string1 == NULL && string2 == NULL) { return (1); }
if (count == 0) { return (1); } if (delim == NULL) { delim = __b2c__option_delim; } start1 = __b2c__delim_engine (2, &amount1, string1, delim, 0); if (count > amount1 || amount1 == 0) { return (0); } if(count == -1) { count = amount1; } dlen = __b2c__len (delim);
for (x = 0; x < count; x++) { start1 = __b2c__delim_engine (1, &length1, string1, delim, 1); start2 = __b2c__delim_engine (1, &length2, string2, delim, 1); if (length1 == 0) { found = wildcard; break; } if (length2 == 0)
{ found = wildcard; break; } if (strncmp (string2, "?", 1)) { if (!strncmp (string2, "*", 1)) { wildcard = 1; __b2c__delim_engine (2, &amount2, string2+1, delim, 0); if(amount2) { after = 1; string2+=1+dlen; } else { after = 0; found = wildcard; break; } }
else { if (!strncmp (string2, "\\?", 2) || !strncmp (string2, "\\*", 2)) { string2++; length2--; } } __b2c__delim_engine (1, &tmplen, string2, delim, 1); if(length1 != tmplen || memcmp (string1, string2, tmplen)) { if (wildcard == 0) { found = 0; break; } else { string2 = string2-1-dlen; } }
else { wildcard = 0; after = 0; } if(wildcard == 0) { string2 += (start2 + length1 + dlen); } } else { string2 += (start2 + length2 + dlen); } string1 += (start1 + length1 + dlen); } if(after) { found = 0; } return (found); }
char *__b2c__inbetween(int flag, char *haystack, char *lm, char *rm, int greedy) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *l, *pos; int collapse; long len, start, end=0, in, w1, w2; long length = 0;
if (haystack == NULL || lm == NULL || rm == NULL) { return (NULL); } collapse = __b2c__collapse; __b2c__collapse = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &length, haystack, lm, 2);
if (start == 0) { __b2c__collapse = collapse; return (NULL); } if (greedy == 0) { in = __b2c__delim_engine (2, &length, haystack+start+end, rm, 2); if (in == 0) { __b2c__collapse = collapse; return (NULL); }
l = haystack+start-__b2c__len(lm); pos = haystack+start+in-__b2c__len(rm); } else if (greedy == 1) { while (1) { in = __b2c__delim_engine (2, &length, haystack+start+end, rm, 2); if(in) { end += in; } else { break; } }
if (end == 0) { __b2c__collapse = collapse; return (NULL); } l = haystack+start-__b2c__len(lm); pos = haystack+start+end-__b2c__len(rm); } else { w1 = start; w2 = start;
while (1) { end = __b2c__delim_engine (2, &length, haystack + w1, rm, 2); if (end == 0) { __b2c__collapse = collapse; return (NULL); } in = __b2c__delim_engine (2, &length, haystack + w2, lm, 2); if (in && ((w2 + in) < (w1 + end)))
{ w1 = w1 + end; w2 = w2 + in; } else { break; } } l = haystack + start - __b2c__len (lm); pos = haystack + w1 + end - __b2c__len (rm); } if (flag) { pos += strlen (rm); len = strlen (pos); buf[idx] = (char*)__b2c_str_realloc(buf[idx], (l - haystack) + len + 1);
memmove(buf[idx], haystack, l - haystack); memmove(buf[idx] + (l - haystack), pos, len); __b2c__SETLEN(buf[idx], (l - haystack) + len); buf[idx][(l - haystack) + len] = '\0'; } else
{ l += strlen (lm); buf[idx] = (char*)__b2c_str_realloc(buf[idx], pos - l + 1); memmove(buf[idx], l, pos - l); __b2c__SETLEN(buf[idx], pos - l); buf[idx][pos - l] = '\0'; } __b2c__collapse = collapse; return(char*)(buf[idx]); }
char * __b2c__ucase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } len = __b2c__len (src);
buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); if(__b2c__option_utf8) { local = setlocale (LC_ALL, ""); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR ("UCASE$", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t)); if (mbstowcs (wcs, src, mbslen + 1) == (size_t) - 1)
{ ERROR = 38; RUNTIMEFERR ("UCASE$", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towupper (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR ("UCASE$", ERROR, k, l); return(NULL); } free (wcs);
setlocale(LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = toupper (src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\0'; return(char*)(buf[idx]); }
long __b2c__netpeek(int l, char *k, uintptr_t fd, int usec){fd_set rfds; struct timeval tv; int desc = 0; long retval = 0; struct termios oldt = { 0 }, newt = { 0 }; if(fd == STDIN_FILENO){tcgetattr(STDIN_FILENO, &oldt);
newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1; newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt);} tv.tv_usec = (usec%1000)*1000; tv.tv_sec = usec/1000; FD_ZERO(&rfds);
if(fd == STDIN_FILENO) { desc = fd; } else {
if(!__b2c__option_tls) { desc = fd; } }
FD_SET(desc, &rfds); retval = select(desc + 1, &rfds, NULL, NULL, &tv); if(retval == -1) { ERROR = 16; RUNTIMEFERR("WAIT", ERROR, k, l); return(0); }
if(fd == STDIN_FILENO){ if(retval) if(read(fd, &retval, 1)==0) { retval=0; } tcsetattr(STDIN_FILENO, TCSANOW, &oldt);} return(retval); }
char *__b2c__extract_core(int action, int l, char *k, char *src, char *needle, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int reti = 0, len, pos = 0; char *tmp; regex_t regex; char __b2c__buf[100]; regmatch_t where[1];
static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (src == NULL || needle == NULL) { return (src); } if (__b2c__len (src) == 0 || __b2c__len (needle) == 0) { return (src); } idx++; if (idx == __b2c_STRING_FUNC)
{ idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], __b2c__len (src) + 1); if (flag > 0) { if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new(); } found = __b2c__hash_find_value_do(table_normal, needle);
if(!found) { reti = regcomp(&regex, needle, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data(table_normal, (void *) &regex, sizeof(regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new (); }
found = __b2c__hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED|REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }
if(reti) { ERROR = 27; regerror (reti, &regex, __b2c__buf, sizeof (__b2c__buf)); fprintf (stderr, "%s\n", __b2c__buf); RUNTIMEFERR("EXTRACT$", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, src, 1, where, 0)) == 0)
{ memcpy (buf[idx] + pos, src, (size_t) where[0].rm_so); pos += where[0].rm_so; src += (long) where[0].rm_eo; } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } else { while ((tmp = strstr (src, needle)) != NULL)
{ memcpy (buf[idx] + pos, src, (size_t) (tmp - src)); pos += tmp - src; src = tmp + __b2c__len (needle); } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } __b2c__SETLEN (buf[idx], pos); buf[idx][pos] = '\0'; return (char *) (buf[idx]); }
long __b2c__regex_core (int action, int l, char *k, char *x, char *y) { regex_t reg; int reti = 0; char buf[100]; regmatch_t where[1]; static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal);
return(0); } if (x == NULL || y == NULL) { return (0); } if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new(); } found = __b2c__hash_find_value_do (table_normal, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &reg, sizeof (reg), y); } }
else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new(); } found = __b2c__hash_find_value_do (table_icase, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &reg, sizeof (reg), y); } }
else { reg = *(regex_t*)found; } } if(reti) { ERROR = 27; regerror (reti, &reg, buf, sizeof (buf)); fprintf(stderr, "%s\n", buf); RUNTIMEFERR("REGEX", ERROR, k, l); return (0); } reti = regexec (&reg, x, 1, where, 0); if (!reti) { REGLEN = where[0].rm_eo - where[0].rm_so;
return (where[0].rm_so + 1); } else { REGLEN = 0; return (0); } }
char *__b2c__replace_core (int action, int l, char *k, char *haystack, char *needle, char *replace, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long replen, hstlen, ndllen, length = 0; regex_t regex; int i, reti = 0; char buffer[100]; regmatch_t where[1];
static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (haystack == NULL || needle == NULL) { return (haystack); } if (replace == NULL) { replace = __b2c_EMPTYSTRING; } ndllen = __b2c__len (needle); hstlen = __b2c__len (haystack); if (hstlen == 0 || ndllen == 0)
{ return (haystack); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (flag == 2) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], hstlen + 1); strncpy (buf[idx], haystack, hstlen); for (i = 0; i < hstlen; i++) { if ((tmp = strchr (needle, buf[idx][i])) != NULL) { buf[idx][i] = replace[tmp - needle]; } }
__b2c__SETLEN (buf[idx], i); buf[idx][i] = '\0'; return (char *) (buf[idx]); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], sizeof (char)); buf[idx][0] = '\0'; replen = __b2c__len (replace); if (flag == 1) { if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new (); }
found = __b2c__hash_find_value_do(table_normal, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL)
{ table_icase = __b2c__hash_new (); } found = __b2c__hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }
if(reti) { ERROR = 27; regerror (reti, &regex, buffer, sizeof (buffer)); fprintf (stderr, "%s\n", buffer); RUNTIMEFERR ("REPLACE$", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, haystack, 1, where, 0)) == 0) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + where[0].rm_so + replen + 1);
memcpy (buf[idx] + length, haystack, (size_t) where[0].rm_so); length += where[0].rm_so; memcpy (buf[idx] + length, replace, replen); length += replen; haystack += (long) where[0].rm_eo; }} else { while ((tmp = strstr (haystack, needle)) != NULL) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + tmp - haystack + replen + 1);
memcpy (buf[idx] + length, haystack, (size_t) (tmp - haystack)); length += tmp - haystack; memcpy (buf[idx] + length, replace, replen); length += replen; haystack = tmp + ndllen; }} hstlen = strlen (haystack); buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + hstlen + 1); memcpy (buf[idx] + length, haystack, hstlen);
length += hstlen; __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\0'; return (char *) (buf[idx]); }
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif
static int __b2c__walk_filter_file(regex_t reg, char *file, int type, struct stat bf) { regmatch_t where[1]; if (regexec(&reg, file, 1, where, 0) == 0) { if (((type & 1) && S_ISREG(bf.st_mode)) || ((type & 2) && S_ISDIR(bf.st_mode)) || ((type & 4) && S_ISCHR(bf.st_mode)) || ((type & 8) && S_ISBLK(bf.st_mode)) ||
 ((type & 16) && S_ISFIFO(bf.st_mode)) || ((type & 32) && S_ISLNK(bf.st_mode)) || ((type & 64) && S_ISSOCK(bf.st_mode))) { return(1); } } return(0); }
static int __b2c__walk_each_file_recurse(regex_t reg, char **buf, char *dir, int type, char *delim) { FTS *fts; FTSENT *ent; struct stat bf; char *item[2]; int dlen, flen, total = 0, result = 0; item[0] = dir; item[1] = NULL; fts = fts_open(item, FTS_PHYSICAL | FTS_NOCHDIR | FTS_XDEV, NULL); if(fts == NULL)
{ return(-1); } dlen = __b2c__len(delim); while(1) { ent = fts_read(fts); if(ent == NULL) { break; } if (lstat(ent->fts_path, &bf) < 0 && __b2c__trap) { result = -1; break; } if(__b2c__walk_filter_file(reg, ent->fts_path, type, bf))
{ if(ent->fts_info != FTS_D) { flen = __b2c__len(ent->fts_path); *buf = (char*)__b2c_str_realloc(*buf, total+flen+dlen+1); memcpy(*buf+total, ent->fts_path, flen); memcpy(*buf+total+flen, delim, dlen);
total += flen + dlen; } } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total-dlen); (*buf)[total - dlen] = '\0'; fts_close(fts); return (result); }
static int __b2c__walk_each_file_dir (regex_t reg, char **buf, const char *dir, int type, char *delim) { DIR *here; struct dirent *item; struct stat bf; int dlen, flen, plen, total = 0, result = 0; char path[PATH_MAX] = { 0 }; here = opendir (dir); if (here == NULL) { return (-1); } dlen = __b2c__len(delim); plen = strlen(dir);
if (plen >= PATH_MAX) { return (-1); } strncpy (path, dir, PATH_MAX - 1); plen++; if (plen >= PATH_MAX) { return (-1); } strncat (path, "/", PATH_MAX - plen - 1); while (1) { item = readdir (here); if (item == NULL) { break; } if (!strcmp (item->d_name, ".") || !strcmp (item->d_name, "..")) { continue; } memset (path + plen, 0, 1);
flen = strlen(item->d_name); if (plen + flen >= PATH_MAX) { return (-1); } strncat (path, item->d_name, PATH_MAX - plen - 1); flen += plen; if (lstat (path, &bf) < 0 && __b2c__trap) { result = -1; break; } if (__b2c__walk_filter_file (reg, path, type, bf)) { *buf = (char*)__b2c_str_realloc(*buf, total + flen + dlen + 1);
memcpy(*buf+total, path, flen); memcpy(*buf+total+flen, delim, dlen); total += flen + dlen; } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total - dlen); (*buf)[total - dlen] = '\0'; closedir (here); return (result); }
char *__b2c__walk_core(int action, int l, char *k, char *dir, int type, char *exp, int recurse, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; regex_t reg; char buffer[100]; int reti = 0; static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (dir == NULL || exp == NULL)
{ return (NULL); } if (delim == NULL) { delim = __b2c__option_delim; } if(type < 1 || type > 127) { ERROR = 5; RUNTIMEFERR("WALK$", ERROR, k, l); return (NULL); } if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new (); } found = __b2c__hash_find_value_do (table_normal, exp);
if (!found) { reti = regcomp (&reg, exp, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new (); } found = __b2c__hash_find_value_do (table_icase, exp); if (!found)
{ reti = regcomp (&reg, exp, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } if(reti) { ERROR = 27; regerror (reti, &reg, buffer, sizeof (buffer)); fprintf(stderr, "%s\n", buffer); RUNTIMEFERR("WALK$", ERROR, k, l);
return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], PATH_MAX * sizeof (char)); if (recurse) { if (__b2c__walk_each_file_recurse (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR("WALK$", ERROR, k, l); return (NULL); } } else
{ if (__b2c__walk_each_file_dir (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR ("WALK$", ERROR, k, l); return (NULL); } } return (char *) (buf[idx]); }
unsigned char __b2c__asc(char *data) { if(data == NULL) { return(0); } return((unsigned char)*data); }
void __b2c__input(int l, char *k, char **result, char *sep) { size_t size; ssize_t total; size = 512; *result = (char*)calloc(512, sizeof(char));
total = getdelim(&(*result), &size, ASC(sep), stdin); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == ASC(sep)) { (*result)[total-1] = '\0'; } else { ERROR = 2; RUNTIMEFERR("INPUT", ERROR, k, l); } }
void __b2c__readln(char **result, FILE *from) { size_t size; ssize_t total; size = 512; *result = (char*)calloc(512, sizeof(char));
total = getline(&(*result), &size, from); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == '\n') { (*result)[total-1] = '\0'; } }
char *__b2c__return (char *data) { static char *rbuffer[64] = { NULL }; static int rbuffer_ptr = 0; size_t size; if(data == NULL) { return(NULL); } size = __b2c__len (data); if(size == 0) { return(NULL); }
rbuffer_ptr++; if(rbuffer_ptr >= 64) { rbuffer_ptr = 0; } rbuffer[rbuffer_ptr] = (char *) __b2c_str_realloc (rbuffer[rbuffer_ptr], size); memcpy (rbuffer[rbuffer_ptr], data, size);
__b2c__SETLEN (rbuffer[rbuffer_ptr], size); rbuffer[rbuffer_ptr][size] = '\0'; return (rbuffer[rbuffer_ptr]); }
int __b2c__network_init(uintptr_t *handle, char *site, char *org, int sock_type, int sock_opt, char *nw_type, int multicast_ttl, int sctp_streams, int capeer, char *cacerts, char *priv, char *cert) { struct sockaddr_in *addr, *from; struct hostent *he;
long amount = 0; long length = 0; char data_client[512]; char *host, *local, *port, *from_client; struct timeval tval; int sock, i, yes = 1; long start; char ttl = 1; __b2c__delim_engine (2, &amount, site, ",", 0);
addr = (struct sockaddr_in*)calloc(amount, sizeof(*addr)); for(i = 0; i < amount; i++) { start = __b2c__delim_engine (1, &length, site, ",", i+1); if(length >= 512) { return(5); } memset(data_client, 0, 512);
strncpy(data_client, site+start, length); if(strstr(data_client, ":") == NULL) { return(10); } host = strtok(data_client, ":"); port = strtok(NULL, ":"); he = gethostbyname(host); if(he == NULL || he->h_addr == NULL) { return(11); }
addr[i].sin_family = AF_INET; addr[i].sin_port = htons((long)atol(port)); addr[i].sin_addr = *((struct in_addr *) he->h_addr); }
sock = socket(AF_INET, sock_type, 0);
if(sock == -1) { return(12); } tval.tv_sec = sock_opt; tval.tv_usec = 0; setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tval, sizeof (struct timeval));
setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)); if(org) { __b2c__delim_engine (2, &amount, org, ",", 0); from = (struct sockaddr_in*)calloc(amount, sizeof(*from));
for(i = 0; i < amount; i++) { start = __b2c__delim_engine (1, &length, site, ",", i+1); from_client = __b2c__strndup(org+start, length); if(strstr(from_client, ":"))
{ local = strtok(from_client, ":"); port = strtok(NULL, ":"); } else { local = from_client; port = NULL; } he = gethostbyname(local); if(he == NULL || he->h_addr == NULL) { return(11); }
from[i].sin_family = AF_INET; if(port) { from[i].sin_port = htons((long)atol(port)); } from[i].sin_addr = *((struct in_addr *)he->h_addr); free(from_client); }
if(bind(sock, (struct sockaddr *)from, sizeof(struct sockaddr)) < 0) { return(17); } free(from); }
if (!strcmp(nw_type, "BROADCAST")) { setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int)); } if(!strcmp(nw_type, "MULTICAST")) { setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &yes, sizeof(int));
ttl = multicast_ttl; setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(unsigned char)); }
if(connect(sock, (struct sockaddr*)addr, sizeof(struct sockaddr)) < 0) { return(13); }
*handle = sock;
free(addr); return(0); }
int __b2c__save(int mode, size_t size, char *file, ...) { FILE *outfile; va_list args; char *item; switch(mode){ case 0: case 1: outfile = fopen((const char *) file, "w"); break;
case 2: case 3: outfile = fopen((const char *) file, "a"); break; } if (outfile == NULL) { return(2); } switch(mode) { case 0: case 2: va_start(args, file); while((item = va_arg(args, char*)) != NULL)
{ fprintf(outfile, "%s", item); } va_end(args); break; case 1: case 3: va_start(args, file); if(fwrite(va_arg(args, void*), 1, size, outfile) != size){ return(2); } va_end(args); break; } fclose (outfile); return(0); }
int __b2c_setserial(int device, int mode, int param, int value, int donot) { struct termios tty; memset(&tty, 0, sizeof(tty)); if(tcgetattr(device, &tty) != 0) { return(33); } switch(mode)
{ case 0: if(donot) { tty.c_iflag &= value; } else { tty.c_iflag |= value; } break; case 1: if(donot) { tty.c_oflag &= value; } else { tty.c_oflag |= value; } break; case 2: if(donot) { tty.c_cflag &= value; }
else { tty.c_cflag |= value; } break; case 3: if(donot) { tty.c_lflag &= value; } else { tty.c_lflag |= value; } break; case 4: tty.c_cc[param] = value; break; case 5: cfsetospeed(&tty, value); cfsetispeed(&tty, value);
break; } if(tcsetattr(device, TCSANOW, &tty) != 0) { return(33); } return(0); }
void __b2c__split_by(char ***array, int base, long *amount, char *string, char *by) { long length, i, start; __b2c__free_str_array_members(&(*array), base, *amount);
start = __b2c__delim_engine(2, amount, string, by, 0); *array = (char**)realloc(*array, (*amount+base) * sizeof(char*)); for (i = 0; i < *amount; i++)
{ start = __b2c__delim_engine_cache(1, &length, string, by, i+1); (*array)[i + base] =__b2c_Copy_N_String(NULL, string + start, (size_t)length); } }
void __b2c__split_with(char ***array, int base, long *amount, char *string, int counter) { long length, i; __b2c__free_str_array_members (&(*array), base, *amount);
length = __b2c__len(string); if (counter > length) { counter = length; } *amount = (length / counter) + (length % counter != 0 ? 1 : 0); *array = (char**)realloc(*array, (*amount+base)*sizeof(char*));
if (counter > 0) { for (i = 0; i < *amount; i++) { (*array)[i + base] = __b2c_Copy_N_String(NULL, string + i*counter, (size_t)counter); } } }
long __b2c__for_amount(char *string, char *step) { long amount = 0; __b2c__delim_engine(2, &amount, string, step, 0); return(amount); }
void __b2c__for_item (char **string, char *step, char **result) { long length = 0; long start; start = __b2c__delim_engine (1, &length, *string, step, 1); if(length == 0) { *result = NULL; } else
{ *result = (char *) __b2c_str_realloc (*result, length + 1); memmove (*result, *string + start, length); __b2c__SETLEN (*result, length); (*result)[length] = '\0'; } *string += (start + length + __b2c__len (step)); }
int __b2c__makedir(char *newdir) { long start, amount = 0, length = 0; int item, collapse; char *dir; if (newdir != NULL && *newdir != 0) { collapse = __b2c__collapse; __b2c__collapse = 0; dir = (char*)calloc(__b2c__len(newdir)+1, sizeof(char));
start = __b2c__delim_engine(2, &amount, newdir, "/", 0); for(item = 1; item <= amount; item++) { start = __b2c__delim_engine(1, &length, newdir, "/", item); if(length) { strncat(dir, newdir+start, length);
if(mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) < 0 && errno != EEXIST && errno != 0) { return(21); } } if(item < amount) { strcat(dir, "/"); } } free(dir); __b2c__collapse = collapse; } return(0); }
void __b2c__signal(void *func, int action) { void(*target)(int); struct sigaction psa; memset(&psa, 0, sizeof(psa)); *((void**)&target) = func; psa.sa_flags = SA_RESETHAND|SA_RESTART; psa.sa_handler = target; sigaction(action, &psa, NULL); }
double __b2c__val(char *data) { if(data == NULL) { return(0); } return(atof(data)); }
void __b2c__setenviron(char *name, char *value) { if(name != NULL && value != NULL) { setenv(name, value, 1); } }
void __b2c__parse(char ***array, int base, long *amount1, char *string, char *with, char *delim) { long dlen, start1, start2, amount2, length1, length2, tmplen, sublen = 0; int x, i = 0, wildcard = 0, next = 0; char *pos = NULL;
__b2c__free_str_array_members (&(*array), base, *amount1); free (*array); *array = NULL; if (string == NULL && with == NULL) { *amount1 = 0; return; } if (delim == NULL) { delim = __b2c__option_delim; }
start1 = __b2c__delim_engine (2, amount1, string, delim, 0); if(*amount1 == 0) { return; } *array = (char **) realloc (*array, (*amount1 + base) * sizeof (char *)); dlen = __b2c__len (delim);
for (x = 0; x < *amount1; x++) { start1 = __b2c__delim_engine (1, &length1, string, delim, 1); start2 = __b2c__delim_engine (1, &length2, with, delim, 1); if(!strncmp (with, "?", 1))
{ (*array)[i + base] = __b2c_Copy_N_String(NULL, string, (size_t) length1); i++; string += (start1 + length1 + dlen); with += (start2 + length2 + dlen); } else { next = 0; if(!strncmp (with, "*", 1))
{ wildcard = 1; if(!pos) { pos = string; } __b2c__delim_engine (2, &amount2, with + 1, delim, 0); if(amount2) { next = 1 + dlen; } else { next = 1; } } else if(!strncmp(with, "\\*", 2) || !strncmp(with, "\\?", 2))
{ with++; length2--; } __b2c__delim_engine (1, &tmplen, with + next, delim, 1); if(length1 != tmplen || memcmp(string, with+next, tmplen)) { if (wildcard == 1) { if(sublen == 0) { sublen += length1; } else { sublen += length1 + dlen; } }
else { __b2c__free_str_array_members (&(*array), base, i); free (*array); *array = NULL; i = 0; break; } } else { if(wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t)sublen); pos = NULL; sublen = 0; i++; } wildcard = 0; }
string += (start1 + length1 + dlen); if (wildcard == 0) { with += (start2 + length1 + dlen + next); } } } if (wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t) sublen); i++; } *amount1 = i; }
char *__b2c__collapse_func(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, option, x, total = 0; long amount = 0, length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }
option = __b2c__collapse; __b2c__collapse = 1; dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string) + 1); __b2c__delim_engine(2, &amount, string, delim, 0); for (x = 0; x < amount; x++)
{ start = __b2c__delim_engine (1, &length, string, delim, 1); memmove(buf[idx] + total, string + start, length); total += length; if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen); total += dlen; }
string += (start + length); } __b2c__collapse = option; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\0'; return(char*)(buf[idx]); }
