/* Self tests for base64.
   Copyright (C) 2004, 2008-2026 Free Software Foundation, Inc.
   Written by Simon Josefsson.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include <config.h>

#include "base64.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "macros.h"

int
main (void)
{
  const char *in = "abcdefghijklmnop";
  const char *b64in = "YWJjZGVmZw==";
  char out[255];
  idx_t len;
  bool ok;
  char *p;

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 0, out, 0);
  ASSERT (out[0] == '\x42');

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 1, out, 1);
  ASSERT (memeq (out, "YQ==", 1));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 1, out, 2);
  ASSERT (memeq (out, "YQ==", 2));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 1, out, 3);
  ASSERT (memeq (out, "YQ==", 3));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 1, out, 4);
  ASSERT (memeq (out, "YQ==", 4));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 1, out, 8);
  ASSERT (memeq (out, "YQ==", 4));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 2, out, 4);
  ASSERT (memeq (out, "YWI=", 4));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 3, out, 4);
  ASSERT (memeq (out, "YWJj", 4));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 4, out, 5);
  ASSERT (memeq (out, "YWJjZA==", 5));

  memset (out, 0x42, sizeof (out));
  base64_encode (in, 4, out, 100);
  ASSERT (memeq (out, "YWJjZA==", 6));

  /* Decode. */

  memset (out, 0x42, sizeof (out));
  len = 0;
  ok = base64_decode (b64in, 4, out, &len);
  ASSERT (ok);
  ASSERT (len == 0);

  memset (out, 0x42, sizeof (out));
  len = 1;
  ok = base64_decode (b64in, 4, out, &len);
  ASSERT (ok);
  ASSERT (len == 1);
  ASSERT (memeq (out, "abcdefg", 1));

  memset (out, 0x42, sizeof (out));
  len = 2;
  ok = base64_decode (b64in, 4, out, &len);
  ASSERT (ok);
  ASSERT (len == 2);
  ASSERT (memeq (out, "abcdefg", 2));

  memset (out, 0x42, sizeof (out));
  len = 3;
  ok = base64_decode (b64in, 4, out, &len);
  ASSERT (ok);
  ASSERT (len == 3);
  ASSERT (memeq (out, "abcdefg", 3));

  memset (out, 0x42, sizeof (out));
  len = 4;
  ok = base64_decode (b64in, 4, out, &len);
  ASSERT (ok);
  ASSERT (len == 3);
  ASSERT (memeq (out, "abcdefg", 3));

  memset (out, 0x42, sizeof (out));
  len = 100;
  ok = base64_decode (b64in, strlen (b64in), out, &len);
  ASSERT (ok);
  ASSERT (len == 7);
  ASSERT (memeq (out, "abcdefg", 7));

  /* Allocating encode */

  len = base64_encode_alloc (in, strlen (in), &p);
  ASSERT (len == 24);
  ASSERT (streq (p, "YWJjZGVmZ2hpamtsbW5vcA=="));
  free (p);

  len = base64_encode_alloc (in, IDX_MAX - 5, &p);
  ASSERT (len == 0);

  /* Decode context function */
  {
    struct base64_decode_context ctx;

    base64_decode_ctx_init (&ctx);

    len = sizeof (out);
    ok = base64_decode_ctx (&ctx, b64in, strlen (b64in), out, &len);
    ASSERT (ok);
    ASSERT (len == 7);
    ASSERT (memeq (out, "abcdefg", len));
  }

  /* Allocating decode context function */

  ok = base64_decode_alloc_ctx (NULL, b64in, strlen (b64in), &p, &len);
  ASSERT (ok);
  ASSERT (len == 7);
  ASSERT (memeq (out, "abcdefg", len));
  free (p);

  {
    struct base64_decode_context ctx;
    const char *newlineb64 = "YWJjZG\nVmZ2hp\namtsbW5vcA==";

    base64_decode_ctx_init (&ctx);

    ok = base64_decode_alloc_ctx (&ctx, newlineb64, strlen (newlineb64), &p, &len);
    ASSERT (ok);
    ASSERT (len == strlen (in));
    ASSERT (memeq (p, in, len));
    free (p);
  }

  {
    struct base64_decode_context ctx;
    base64_decode_ctx_init (&ctx);

    ok = base64_decode_alloc_ctx (&ctx, "YW\nJjZGVmZ2hp", 13, &p, &len);
    ASSERT (ok);
    ASSERT (len == 9);
    ASSERT (memeq (p, "abcdefghi", len));
    free (p);

    base64_decode_ctx_init (&ctx);

    ok = base64_decode_alloc_ctx (&ctx, "YW\n", 3, &p, &len);
    ASSERT (ok);
    ASSERT (len == 0);
    free (p);

    ok = base64_decode_alloc_ctx (&ctx, "JjZGVmZ2", 8, &p, &len);
    ASSERT (ok);
    ASSERT (len == 6);
    ASSERT (memeq (p, "abcdef", len));
    free (p);

    ok = base64_decode_alloc_ctx (&ctx, "hp", 2, &p, &len);
    ASSERT (ok);
    ASSERT (len == 3);
    ASSERT (memeq (p, "ghi", len));
    free (p);

    ok = base64_decode_alloc_ctx (&ctx, "", 0, &p, &len);
    ASSERT (ok);
    free (p);
  }

  {
    struct base64_decode_context ctx;
    const char *newlineb64 = "\n\n\n\n\n";

    base64_decode_ctx_init (&ctx);

    ok = base64_decode_alloc_ctx (&ctx, newlineb64, strlen (newlineb64), &p, &len);
    ASSERT (ok);
    ASSERT (len == 0);
    free (p);
  }

  ok = base64_decode_alloc_ctx (NULL, " ! ", 3, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "abc\ndef", 7, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "aa", 2, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "aa=", 3, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "aax", 3, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "aa=X", 4, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "aa=X", 4, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "aax=X", 5, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "SGVsbG9=", 8, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "TR==", 4, &p, &len);
  ASSERT (!ok);

  ok = base64_decode_alloc_ctx (NULL, "TWF=TWE=", 8, &p, &len);
  ASSERT (!ok);

  return test_exit_status;
}
