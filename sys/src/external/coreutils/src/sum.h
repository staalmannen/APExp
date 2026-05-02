extern int
bsd_sum_stream (FILE *stream, void *resstream, intmax_t *length);

extern int
sysv_sum_stream (FILE *stream, void *resstream, intmax_t *length);

typedef int (*sumfn)(FILE *, void *, intmax_t *);


extern void
output_bsd (char const *file, int binary_file, void const *digest,
            bool raw, bool tagged, unsigned char delim, bool args,
            intmax_t length);

extern void
output_sysv (char const *file, int binary_file, void const *digest,
             bool raw, bool tagged, unsigned char delim, bool args,
             intmax_t length);
