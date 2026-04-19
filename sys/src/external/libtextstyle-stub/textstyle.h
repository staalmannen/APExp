/* Stub replacement for libtextstyle API.
   Based on the dummy replacement in GNU bison, cleaned up for APExp.
   Provides a no-op styling API that outputs plain text via stdio. */

#ifndef _TEXTSTYLE_H
#define _TEXTSTYLE_H

#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Describes the scope of a flush operation.  */
typedef enum
{
  FLUSH_THIS_STREAM = 0,
  FLUSH_THIS_PROCESS = 1,
  FLUSH_ALL = 2
} ostream_flush_scope_t;

/* An output stream is an object to which one can feed a sequence of bytes.  */
typedef FILE * ostream_t;

static inline void
ostream_write_mem (ostream_t stream, const void *data, size_t len)
{
  if (len > 0)
    fwrite (data, 1, len, stream);
}

static inline void
ostream_flush (ostream_t stream, ostream_flush_scope_t scope)
{
  fflush (stream);
  if (scope == FLUSH_ALL)
    {
      int fd = fileno (stream);
      if (fd >= 0)
        fsync (fd);
    }
}

static inline void
ostream_free (ostream_t stream)
{
  if (stream == stdin || stream == stderr)
    fflush (stream);
  else
    fclose (stream);
}

static inline void
ostream_write_str (ostream_t stream, const char *string)
{
  ostream_write_mem (stream, string, strlen (string));
}

static inline ptrdiff_t
ostream_printf (ostream_t stream, const char *format, ...)
{
  va_list args;
  char *temp_string;
  int ret;

  va_start (args, format);
  ret = vasprintf (&temp_string, format, args);
  va_end (args);
  if (ret >= 0)
    {
      if (ret > 0)
        ostream_write_str (stream, temp_string);
      free (temp_string);
    }
  return (ptrdiff_t)ret;
}

static inline ptrdiff_t
ostream_vprintf (ostream_t stream, const char *format, va_list args)
{
  char *temp_string;
  int ret = vasprintf (&temp_string, format, args);
  if (ret >= 0)
    {
      if (ret > 0)
        ostream_write_str (stream, temp_string);
      free (temp_string);
    }
  return (ptrdiff_t)ret;
}

/* Styled output stream.  */
typedef ostream_t styled_ostream_t;

#define styled_ostream_write_mem ostream_write_mem
#define styled_ostream_flush ostream_flush
#define styled_ostream_free ostream_free

static inline void
styled_ostream_begin_use_class (styled_ostream_t stream, const char *classname)
{
  (void)stream;
  (void)classname;
}

static inline void
styled_ostream_end_use_class (styled_ostream_t stream, const char *classname)
{
  (void)stream;
  (void)classname;
}

static inline const char *
styled_ostream_get_hyperlink_ref (styled_ostream_t stream)
{
  (void)stream;
  return NULL;
}

static inline const char *
styled_ostream_get_hyperlink_id (styled_ostream_t stream)
{
  (void)stream;
  return NULL;
}

static inline void
styled_ostream_set_hyperlink (styled_ostream_t stream, const char *ref, const char *id)
{
  (void)stream;
  (void)ref;
  (void)id;
}

static inline void
styled_ostream_flush_to_current_style (styled_ostream_t stream)
{
  (void)stream;
}

/* File output stream.  */
typedef ostream_t file_ostream_t;

#define file_ostream_write_mem ostream_write_mem
#define file_ostream_flush ostream_flush
#define file_ostream_free ostream_free

static inline file_ostream_t
file_ostream_create (FILE *fp)
{
  return fp;
}

/* File descriptor output stream.  */
typedef ostream_t fd_ostream_t;

#define fd_ostream_write_mem ostream_write_mem
#define fd_ostream_flush ostream_flush
#define fd_ostream_free ostream_free

static inline fd_ostream_t
fd_ostream_create (int fd, const char *filename, bool buffered)
{
  (void)filename;
  (void)buffered;
  if (fd == 1)
    return stdout;
  else if (fd == 2)
    return stderr;
  else
    return fdopen (fd, "w");
}

/* Terminal output stream.  */
typedef int term_color_t;
enum { COLOR_DEFAULT = -1 };

typedef enum { WEIGHT_NORMAL = 0, WEIGHT_BOLD, WEIGHT_DEFAULT = WEIGHT_NORMAL } term_weight_t;
typedef enum { POSTURE_NORMAL = 0, POSTURE_ITALIC, POSTURE_DEFAULT = POSTURE_NORMAL } term_posture_t;
typedef enum { UNDERLINE_OFF = 0, UNDERLINE_ON, UNDERLINE_DEFAULT = UNDERLINE_OFF } term_underline_t;

typedef ostream_t term_ostream_t;

#define term_ostream_write_mem ostream_write_mem
#define term_ostream_flush ostream_flush
#define term_ostream_free ostream_free

static inline term_color_t term_ostream_get_color (term_ostream_t s) { (void)s; return COLOR_DEFAULT; }
static inline void term_ostream_set_color (term_ostream_t s, term_color_t c) { (void)s; (void)c; }
static inline term_color_t term_ostream_get_bgcolor (term_ostream_t s) { (void)s; return COLOR_DEFAULT; }
static inline void term_ostream_set_bgcolor (term_ostream_t s, term_color_t c) { (void)s; (void)c; }
static inline term_weight_t term_ostream_get_weight (term_ostream_t s) { (void)s; return WEIGHT_DEFAULT; }
static inline void term_ostream_set_weight (term_ostream_t s, term_weight_t w) { (void)s; (void)w; }
static inline term_posture_t term_ostream_get_posture (term_ostream_t s) { (void)s; return POSTURE_DEFAULT; }
static inline void term_ostream_set_posture (term_ostream_t s, term_posture_t p) { (void)s; (void)p; }
static inline term_underline_t term_ostream_get_underline (term_ostream_t s) { (void)s; return UNDERLINE_DEFAULT; }
static inline void term_ostream_set_underline (term_ostream_t s, term_underline_t u) { (void)s; (void)u; }
static inline const char * term_ostream_get_hyperlink_ref (term_ostream_t s) { (void)s; return NULL; }
static inline const char * term_ostream_get_hyperlink_id (term_ostream_t s) { (void)s; return NULL; }
static inline void term_ostream_set_hyperlink (term_ostream_t s, const char *r, const char *i) { (void)s; (void)r; (void)i; }
static inline void term_ostream_flush_to_current_style (term_ostream_t s) { fflush (s); }

typedef enum
{
  TTYCTL_AUTO = 0,
  TTYCTL_NONE,
  TTYCTL_PARTIAL,
  TTYCTL_FULL
} ttyctl_t;

static inline term_ostream_t
term_ostream_create (int fd, const char *filename, ttyctl_t tty_control)
{
  (void)tty_control;
  return fd_ostream_create (fd, filename, true);
}

/* Styled terminal output stream.  */
typedef styled_ostream_t term_styled_ostream_t;

#define term_styled_ostream_write_mem ostream_write_mem
#define term_styled_ostream_flush ostream_flush
#define term_styled_ostream_free ostream_free
#define term_styled_ostream_begin_use_class styled_ostream_begin_use_class
#define term_styled_ostream_end_use_class styled_ostream_end_use_class
#define term_styled_ostream_get_hyperlink_ref styled_ostream_get_hyperlink_ref
#define term_styled_ostream_get_hyperlink_id styled_ostream_get_hyperlink_id
#define term_styled_ostream_set_hyperlink styled_ostream_set_hyperlink
#define term_styled_ostream_flush_to_current_style styled_ostream_flush_to_current_style

static inline term_styled_ostream_t
term_styled_ostream_create (int fd, const char *filename,
                            ttyctl_t tty_control,
                            const char *css_filename)
{
  (void)tty_control;
  (void)css_filename;
  return fd_ostream_create (fd, filename, true);
}

/* Styled HTML output stream.  */
typedef styled_ostream_t html_styled_ostream_t;

static inline html_styled_ostream_t
html_styled_ostream_create (ostream_t destination, const char *css_filename)
{
  (void)destination;
  (void)css_filename;
  abort ();
  return NULL;
}

/* Color and style handling.  */
#define color_test_mode false
enum color_option { color_no, color_tty, color_yes, color_html };
#define color_mode color_no
#define style_file_name NULL

static inline bool handle_color_option (const char *option) { (void)option; return false; }
static inline void handle_style_option (const char *option) { (void)option; }
static inline void print_color_test (void) { abort (); }
static inline void style_file_prepare (const char *a, const char *b, const char *c, const char *d) { (void)a; (void)b; (void)c; (void)d; }

/* Miscellaneous.  */
static inline styled_ostream_t
styled_ostream_create (int fd, const char *filename,
                       ttyctl_t tty_control,
                       const char *css_filename)
{
  (void)tty_control;
  (void)css_filename;
  return fd_ostream_create (fd, filename, true);
}

static inline void
libtextstyle_set_failure_exit_code (int exit_code)
{
  (void)exit_code;
}

#endif /* _TEXTSTYLE_H */
