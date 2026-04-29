/*
 * ns_strip.c — Namespace-stripping preprocessor for cfront-C4
 *
 * Reads C++ source from stdin, writes flattened C++ to stdout.
 *
 * Transformations:
 *   namespace foo { ... }     → content only (namespace wrapper stripped)
 *   namespace { ... }         → content only (anonymous namespace stripped)
 *   using namespace foo;      → stripped (replaced by empty line)
 *   using foo::bar;           → stripped (replaced by empty line)
 *   foo::name (qualified name → bare name, only for flattened namespaces)
 *
 * Class scope qualifiers (ClassName::member) are NOT stripped because
 * cfront already handles those correctly.
 *
 * Build:
 *   gcc -o ns_strip ns_strip.c
 *
 * Usage:
 *   gcc -E input.cpp | ns_strip | cfront +a1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ------------------------------------------------------------------ */
/* Namespace name registry                                              */
/* ------------------------------------------------------------------ */

#define MAX_NS      128
#define MAX_NS_LEN  256

static char ns_registry[MAX_NS][MAX_NS_LEN];
static int  ns_count = 0;

static void ns_register(const char *name) {
    int i;
    if (!name || !name[0]) return;          /* anonymous namespace */
    for (i = 0; i < ns_count; i++)
        if (strcmp(ns_registry[i], name) == 0) return;
    if (ns_count < MAX_NS) {
        strncpy(ns_registry[ns_count], name, MAX_NS_LEN - 1);
        ns_registry[ns_count][MAX_NS_LEN - 1] = '\0';
        ns_count++;
    }
}

static int ns_known(const char *name) {
    int i;
    for (i = 0; i < ns_count; i++)
        if (strcmp(ns_registry[i], name) == 0) return 1;
    return 0;
}

/* ------------------------------------------------------------------ */
/* Input buffer                                                         */
/* ------------------------------------------------------------------ */

#define BUF_SZ  (8 * 1024 * 1024)   /* 8 MB input buffer */

static char *ibuf  = NULL;
static int   ilen  = 0;
static int   ipos  = 0;

static int peek(void) {
    return (ipos < ilen) ? (unsigned char)ibuf[ipos] : -1;
}

static int peek2(void) {
    return (ipos + 1 < ilen) ? (unsigned char)ibuf[ipos + 1] : -1;
}

static int getch(void) {
    return (ipos < ilen) ? (unsigned char)ibuf[ipos++] : -1;
}

static void ungetch(void) {
    if (ipos > 0) ipos--;
}

/* ------------------------------------------------------------------ */
/* Output                                                               */
/* ------------------------------------------------------------------ */

static void outch(int c) {
    putchar(c);
}

static void outstr(const char *s) {
    fputs(s, stdout);
}

/* ------------------------------------------------------------------ */
/* Brace-depth namespace tracking                                       */
/* ------------------------------------------------------------------ */

#define MAX_DEPTH 1024

/*
 * ns_at_depth[d] > 0 when brace depth d opened a namespace block.
 * The value is the count of nested namespace blocks at that depth.
 */
static int ns_at_depth[MAX_DEPTH];
static int brace_depth = 0;         /* current brace nesting depth */

static int inside_namespace(void) {
    int d;
    for (d = 0; d <= brace_depth; d++)
        if (ns_at_depth[d]) return 1;
    return 0;
}

/* ------------------------------------------------------------------ */
/* Identifier scanning                                                  */
/* ------------------------------------------------------------------ */

static int is_ident_start(int c) {
    return isalpha(c) || c == '_';
}
static int is_ident_cont(int c) {
    return isalnum(c) || c == '_';
}

/* Read an identifier into buf (max len-1 chars), null-terminated.
   Returns length. Assumes first char already consumed (passed as first). */
static int read_ident_rest(char *buf, int len, int first) {
    int n = 0;
    if (first > 0 && n < len - 1) buf[n++] = (char)first;
    while (n < len - 1) {
        int c = peek();
        if (!is_ident_cont(c)) break;
        buf[n++] = (char)getch();
    }
    buf[n] = '\0';
    return n;
}

/* ------------------------------------------------------------------ */
/* Skip whitespace (not newlines) in input                              */
/* ------------------------------------------------------------------ */
static void skip_spaces(void) {
    while (peek() == ' ' || peek() == '\t') getch();
}

/* ------------------------------------------------------------------ */
/* Skip over a block comment (assumes opening / * already consumed)    */
/* ------------------------------------------------------------------ */
static void skip_block_comment_content(void) {
    int c;
    while ((c = getch()) != -1) {
        if (c == '*' && peek() == '/') { getch(); return; }
    }
}


/* ------------------------------------------------------------------ */
/* Skip matching braces — used when we want to discard namespace body  */
/* (We don't actually discard; we re-enter with ns flag set.)          */
/* ------------------------------------------------------------------ */


/* ------------------------------------------------------------------ */
/* Look-ahead to check for '::' after an identifier to detect          */
/* qualified name reference                                             */
/* ------------------------------------------------------------------ */

/* After reading identifier, check if next non-whitespace chars are "::"
   Returns 1 if yes, 0 if no.  Does NOT consume the '::'. */
static int peek_coloncolon(void) {
    int saved = ipos;
    /* skip optional whitespace */
    while (peek() == ' ' || peek() == '\t') getch();
    int a = getch();
    int b = getch();
    int result = (a == ':' && b == ':') ? 1 : 0;
    ipos = saved;   /* restore position */
    return result;
}

/* ------------------------------------------------------------------ */
/* Forward declaration                                                  */
/* ------------------------------------------------------------------ */
static void process(void);

/* ------------------------------------------------------------------ */
/* Emit a string literal (pass through), consuming from input          */
/* ------------------------------------------------------------------ */
static void emit_string(int delim) {
    outch(delim);
    int c;
    while ((c = getch()) != -1) {
        outch(c);
        if (c == '\\') {
            int esc = getch();
            if (esc != -1) outch(esc);
        } else if (c == delim) {
            break;
        }
    }
}

/* ------------------------------------------------------------------ */
/* Handle preprocessor # lines — pass through unchanged                */
/* ------------------------------------------------------------------ */
static void emit_hash_line(void) {
    outch('#');
    int c;
    while ((c = getch()) != -1) {
        outch(c);
        if (c == '\n') break;
        if (c == '\\') {    /* line continuation */
            int nc = getch();
            if (nc != -1) { outch(nc); if (nc != '\n') continue; }
            /* nc == '\n': continue reading next line */
        }
    }
}

/* ------------------------------------------------------------------ */
/* Main processing                                                      */
/* ------------------------------------------------------------------ */

static void process(void) {
    int c;

    while ((c = getch()) != -1) {

        /* Preprocessor lines: pass through unchanged */
        if (c == '#') {
            emit_hash_line();
            continue;
        }

        /* String literal */
        if (c == '"') { emit_string('"'); continue; }

        /* Char literal */
        if (c == '\'') { emit_string('\''); continue; }

        /* Line comment: // — pass through unchanged */
        if (c == '/' && peek() == '/') {
            getch(); /* consume second / */
            outstr("//");
            int cc;
            while ((cc = getch()) != -1) {
                outch(cc);
                if (cc == '\n') break;
            }
            continue;
        }

        /* Block comment */
        if (c == '/' && peek() == '*') {
            getch(); /* consume * */
            outstr("/*");
            /* pass through block comment content */
            int prev = 0;
            int cc;
            while ((cc = getch()) != -1) {
                outch(cc);
                if (prev == '*' && cc == '/') break;
                prev = cc;
            }
            continue;
        }

        /* Opening brace */
        if (c == '{') {
            brace_depth++;
            if (brace_depth < MAX_DEPTH)
                ns_at_depth[brace_depth] = 0;
            outch('{');
            continue;
        }

        /* Closing brace */
        if (c == '}') {
            if (brace_depth > 0 && brace_depth < MAX_DEPTH
                    && ns_at_depth[brace_depth]) {
                /* This closes a namespace block — don't emit the '}' */
                /* Instead emit a comment to preserve line numbering */
                outstr("/* end namespace */\n");
                ns_at_depth[brace_depth] = 0;
                brace_depth--;
            } else {
                if (brace_depth > 0) brace_depth--;
                outch('}');
            }
            continue;
        }

        /* Identifier — check for keywords we care about */
        if (is_ident_start(c)) {
            char ident[MAX_NS_LEN];
            read_ident_rest(ident, sizeof(ident), c);

            /* --- namespace keyword --- */
            if (strcmp(ident, "namespace") == 0) {
                /* Skip whitespace to find namespace name or '{' */
                skip_spaces();
                int nc = peek();

                if (nc == '{') {
                    /* Anonymous namespace: namespace { ... }
                       Emit nothing for the namespace header;
                       just let the content flow through. */
                    getch(); /* consume '{' */
                    brace_depth++;
                    if (brace_depth < MAX_DEPTH)
                        ns_at_depth[brace_depth] = 1;
                    outstr("/* anonymous namespace */\n");
                } else if (is_ident_start(nc)) {
                    char nsname[MAX_NS_LEN];
                    read_ident_rest(nsname, sizeof(nsname), getch());
                    ns_register(nsname);

                    /* Skip spaces/comments after name, look for '{' or '=' */
                    skip_spaces();

                    /* Handle namespace alias: namespace alias = existing; */
                    if (peek() == '=') {
                        /* namespace alias: skip to semicolon, emit comment */
                        getch(); /* consume '=' */
                        int sc;
                        while ((sc = getch()) != -1 && sc != ';') ;
                        fprintf(stdout, "/* namespace alias %s */\n", nsname);
                        continue;
                    }

                    /* Inline namespace (namespace inline X { ... }):
                       just treat as namespace */
                    if (peek() == '{') {
                        getch(); /* consume '{' */
                        brace_depth++;
                        if (brace_depth < MAX_DEPTH)
                            ns_at_depth[brace_depth] = 1;
                        fprintf(stdout, "/* namespace %s */\n", nsname);
                    } else {
                        /* Something unexpected — just pass through */
                        fprintf(stdout, "namespace %s", nsname);
                    }
                } else {
                    /* Unexpected — pass through */
                    outstr("namespace");
                }
                continue;
            }

            /* --- using keyword --- */
            if (strcmp(ident, "using") == 0) {
                skip_spaces();

                /* Check for 'using namespace ...' */
                if (peek() != -1 && is_ident_start(peek())) {
                    char kw[MAX_NS_LEN];
                    int kpos = ipos;
                    read_ident_rest(kw, sizeof(kw), getch());

                    if (strcmp(kw, "namespace") == 0) {
                        /* using namespace foo; — strip it */
                        int sc;
                        while ((sc = getch()) != -1 && sc != ';') ;
                        outstr("/* using namespace (stripped) */\n");
                        continue;
                    } else {
                        /* using foo::bar; or using Type = ...; */
                        /* Check if next non-space is '::' */
                        skip_spaces();
                        if (peek() == ':' && peek2() == ':') {
                            /* using ns::name; form — strip it */
                            int sc;
                            while ((sc = getch()) != -1 && sc != ';') ;
                            fprintf(stdout, "/* using %s::... (stripped) */\n", kw);
                            continue;
                        } else if (peek() == '=') {
                            /* using Alias = Type; — this is a type alias,
                               pass through (cfront handles typedefs) */
                            ipos = kpos;    /* restore to before kw */
                            outstr("using ");
                            /* fall through to emit rest */
                        } else {
                            /* Unknown using form, restore and pass through */
                            ipos = kpos;
                            outstr("using ");
                        }
                    }
                } else {
                    outstr("using ");
                }
                continue;
            }

            /* --- Other identifier: check for ns::name pattern --- */
            if (peek_coloncolon() && ns_known(ident)) {
                /* This is ns::name where ns is a known namespace.
                   Consume the '::' and skip the namespace qualifier. */
                skip_spaces();  /* consume any space before :: */
                getch(); getch(); /* consume '::' */
                /* Output nothing for the namespace prefix — the name
                   that follows will be output on the next iteration. */
                continue;
            }

            /* Regular identifier: output as-is */
            outstr(ident);
            continue;
        }

        /* All other characters: pass through */
        outch(c);
    }
}

/* ------------------------------------------------------------------ */
/* main                                                                 */
/* ------------------------------------------------------------------ */

int main(void) {
    /* Read all of stdin into memory */
    ibuf = (char *)malloc(BUF_SZ);
    if (!ibuf) {
        fprintf(stderr, "ns_strip: out of memory\n");
        return 1;
    }

    ilen = 0;
    int c;
    while (ilen < BUF_SZ - 1 && (c = getchar()) != EOF)
        ibuf[ilen++] = (char)c;
    ibuf[ilen] = '\0';

    /* Initialise brace tracking */
    memset(ns_at_depth, 0, sizeof(ns_at_depth));

    /* Process */
    process();

    free(ibuf);
    return 0;
}
