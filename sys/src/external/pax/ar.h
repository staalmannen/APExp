/*-
 * Copyright (c) 2011, 2016
 *	mirabilos <m@mirbsd.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifdef EXTERN
__IDSTRING(rcsid_ar_h, "$MirOS: src/bin/pax/ar.h,v 1.4 2018/12/12 18:08:41 tg Exp $");
#endif

/****************************************************

Libraries created by the Unix Archiver and compatible
with the DEB file format consist of an initial eight-
octet magic followed by a number of sections, per ar-
chive member, comprised of a header and a data part.

The magic is "<!arch>\n" (21 3C 61 72 63 68 3E 0A).

Each archive member section (header followed by data)
is aligned to a multiple of two octets. The magic and
member header are both of even size, so a padding oc-
tet "\n" (0Ah) can be appended after the data part of
that section; an archive always has an even length. A
header is 60 octets long and structured as follows:
	+0	char ar_name[16];
	+16	char ar_mtime[12];
	+28	char ar_uid[6];
	+34	char ar_gid[6];
	+40	char ar_mode[8];
	+48	char ar_size[10];
	+58	char ar_magic[2];

All header fields are left-justified and space-padded
at the end, if necessary. The composition for ar_name
will be described later. ar_mtime, ar_uid, ar_gid and
ar_size are the unsigned decimental representation of
the mtime as time_t, numeric user and group ID values
and the size of the data part, respectively. ar_mode,
on the other hand, is the octal representation of its
Unix file mode (permissions). ar_magic = { 60h, 0Ah }

Archive memeber filenames are basenames, i.e. they do
not contain a path.

If the filename is not longer than 16 octets and does
not contain a space, it is stored as ar_name directly
(although some implementations would trim the part of
the filename before a ".o" extension). Otherwise, the
ar_name field consists of the string "#1/" (23 31 2F)
followed by the length of the filename as decimal un-
signed integer (again space-padded); the APT archival
routines only support extended filenames of less than
300 octets. The actual filename is then stored as the
first part of the data part consequently incrementing
ar_size by its length. Since some versions of APT al-
so support the SYSV property of ending ar_name with a
slash "/" (2F), on encoding filenames containing them
should be written as extended filenames; on decoding,
a trailing slash in ar_name should be ignored. (Note,
SYSV does not encode filenames that contain spaces as
extended but BSD ar and APT truncate there then.)

There are no trailers; an archive file ends after its
last member section (including the padding).

****************************************************/

typedef struct {
	char ar_name[16];
	char ar_mtime[12];
	char ar_uid[6];
	char ar_gid[6];
	char ar_mode[8];
	char ar_size[10];
	char ar_magic[2];
} HD_AR;
