/* Test parts of the API.
   Copyright (C) 2025 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Bruno Haible <bruno@clisp.org>, 2025.  */

#include <uniconv.h>
#include <uninorm.h>
#include <unistr.h>

#include <assert.h>

#define SIZEOF(array) (sizeof (array) / sizeof (array[0]))

int
main ()
{
  /* Test taken from tests/uniconv/test-u8-strconv-from-enc.c.  */
  {
    static enum iconv_ilseq_handler handlers[] =
      { iconveh_error, iconveh_question_mark, iconveh_escape_sequence };
    size_t h;

    /* Assume that iconv() supports at least the encodings ASCII, ISO-8859-1,
       ISO-8859-2, and UTF-8.  */

    /* Test conversion from ISO-8859-2 to UTF-8 with no errors.  */
    for (h = 0; h < SIZEOF (handlers); h++)
      {
        enum iconv_ilseq_handler handler = handlers[h];
        static const char input[] = "Rafa\263 Maszkowski"; /* Rafał Maszkowski */
        static const uint8_t expected[] = "Rafa\305\202 Maszkowski";
        uint8_t *result = u8_strconv_from_encoding (input, "ISO-8859-2", handler);
        assert (result != NULL);
        assert (u8_strcmp (result, expected) == 0);
        free (result);
      }
  }

  /* Test taken from tests/uninorm/test-u8-nfc.c.  */
  { /* ANGSTROM SIGN */
    static const uint8_t input[]      = { 0xE2, 0x84, 0xAB };
    static const uint8_t decomposed[] = { 0x41, 0xCC, 0x8A };
    static const uint8_t expected[]   = { 0xC3, 0x85 };
    size_t length;
    uint8_t *result;

    result = u8_normalize (UNINORM_NFC, input, SIZEOF (input), NULL, &length);
    assert (result != NULL && length == SIZEOF (expected) && u8_cmp (result, expected, SIZEOF (expected)) == 0);

    result = u8_normalize (UNINORM_NFC, decomposed, SIZEOF (decomposed), NULL, &length);
    assert (result != NULL && length == SIZEOF (expected) && u8_cmp (result, expected, SIZEOF (expected)) == 0);

    result = u8_normalize (UNINORM_NFC, expected, SIZEOF (expected), NULL, &length);
    assert (result != NULL && length == SIZEOF (expected) && u8_cmp (result, expected, SIZEOF (expected)) == 0);
  }

  return 0;
}
