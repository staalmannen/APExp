#ifndef _TERMCAP_H
#define _TERMCAP_H 1

#ifdef __cplusplus
extern "C" {
#endif

/* Find the termcap entry for TERMTYPE and store it in BUFFER.
   If BUFFER is null, space is dynamically allocated (caller must free).
   Returns 1 on success, 0 if terminal type not found, -1 on I/O error. */
extern int tgetent(char *buffer, const char *termtype);

/* Look up numeric capability NAME in the loaded entry. Returns -1 if absent. */
extern int tgetnum(const char *name);

/* Look up boolean capability NAME. Returns 1 if present, 0 if absent. */
extern int tgetflag(const char *name);

/* Look up string capability NAME. If AREA is non-null, the string is stored
   there and *AREA is advanced past it; otherwise malloc is used. */
extern char *tgetstr(const char *name, char **area);

/* Output STRING with baud-rate padding, calling OUTFUN for each character.
   NLINES is the number of lines being affected (for * padding).  */
extern int tputs(const char *string, int nlines, int (*outfun)(int));

/* Expand cursor-motion string CM for position (HPOS, VPOS). */
extern char *tgoto(const char *cm, int hpos, int vpos);

/* Merge up to 4 numeric parameters into termcap string STRING.
   OUTSTRING is the buffer (length LEN); may be reallocated.  */
extern char *tparam(const char *string, char *outstring, int len,
                    int arg0, int arg1, int arg2, int arg3);

/* Pad character (default NUL). Set by the application if needed. */
extern char PC;

/* Terminal output speed (B9600, etc.). Set by the application. */
extern short ospeed;

/* Cursor-up and backspace strings (used by tgoto). */
extern char *UP;
extern char *BC;

#ifdef __cplusplus
}
#endif

#endif /* _TERMCAP_H */
