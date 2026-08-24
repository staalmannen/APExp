/* Diagnostics for GNU diffutils

   Copyright 2023-2025 Free Software Foundation, Inc.

   This file is part of GNU DIFF.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>

#include "diagnose.h"

#include "gettext.h"
#include "progname.h"
#include "quotearg.h"

#include <error.h>

/* In slot N return NAME, quoted for the shell if NAME has unusual characters.
   This is for messages that historically did not quote names,
   where we want to keep the message unchanged for compatibility reasons
   unless the unusual characters might cause confusion.
   Also, POSIX requires that names be unquoted in some cases,
   and we want to respect that for POSIX portable filenames.  */
char *
squote (int n, char const *name)
{
  return quotearg_n_style (n, shell_escape_quoting_style, name);
}

/* Issue help for the program.  If REASON_MSGID, first issue a
   diagnostic with that reason and with optional operand OPERAND.
   Suggest --help regardless.  */
void
try_help (char const *reason_msgid, char const *operand)
{
  if (reason_msgid)
    error (0, 0, gettext (reason_msgid), operand);
  error (EXIT_TROUBLE, 0,
	 gettext ("Try '%s --help' for more information."), program_name);
}
