/*	$OpenBSD: extern.h,v 1.59 2018/09/13 12:33:43 millert Exp $	*/
/*	$NetBSD: extern.h,v 1.5 1996/03/26 23:54:16 mrg Exp $	*/

/*-
 * Copyright © 2013, 2015, 2016, 2018, 2019
 *	mirabilos <m@mirbsd.org>
 * Copyright (c) 1992 Keith Muller.
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Keith Muller of the University of California, San Diego.
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
 *
 *	@(#)extern.h	8.2 (Berkeley) 4/18/94
 */

/*
 * External references from each source file
 */

#ifdef EXTERN
__IDSTRING(rcsid_extern_h, "$MirOS: src/bin/pax/extern.h,v 1.40 2020/04/07 11:56:43 tg Exp $");
#endif

#ifndef PAX_JUST_THE_WARNINGS
/*
 * ar.c
 */
int uar_stwr(int);
int uar_ismagic(char *);
int uar_id(char *, int) MKSH_A_NORETURN;
int uar_rd(ARCHD *, char *);
int uar_wr(ARCHD *);
int uar_wr_data(ARCHD *, int, off_t *);
off_t uar_endrd(void);
int uar_trail(ARCHD *, char *, int, int *) MKSH_A_NORETURN;

/*
 * ar_io.c
 */
extern const char *arcname;
extern const char *compress_program;
extern char force_one_volume;
int ar_open(const char *);
void ar_close(int _in_sig);
void ar_drain(void);
int ar_set_wr(void);
int ar_app_ok(void);
int ar_read(char *, int);
int ar_write(char *, int);
int ar_rdsync(void);
int ar_fow(off_t, off_t *);
int ar_rev(off_t );
int ar_next(void);
extern char ar_do_keepopen;
int ar_next_keepopen(void);

/*
 * ar_subs.c
 */
extern u_long flcnt;
void list(void);
void extract(void);
void append(void);
void archive(void);
void copy(void);

/*
 * buf_subs.c
 */
extern int blksz;
extern int wrblksz;
extern int maxflt;
extern int rdblksz;
extern off_t wrlimit;
extern off_t rdcnt;
extern off_t wrcnt;
int wr_start(void);
int rd_start(void);
void cp_start(void);
int appnd_start(off_t);
int rd_sync(void);
void pback(const char *, int);
int rd_skip(off_t);
void wr_fin(void);
int wr_rdbuf(const char *, int);
int rd_wrbuf(char *, int);
int wr_skip(off_t);
int wr_rdfile(ARCHD *, int, off_t *);
int rd_wrfile(ARCHD *, int, off_t *);
void cp_file(ARCHD *, int, int);
int buf_fill(void);
int buf_fill_internal(int);
int buf_flush(int);

/*
 * cache.c
 */
#if !HAVE_UG_FROM_UGID
int uidtb_start(void);
int gidtb_start(void);
const char *name_uid(uid_t, int);
const char *name_gid(gid_t, int);
#else
#define name_uid(u,frc) ((const char *)user_from_uid((u), !(frc)))
#define name_gid(g,frc) ((const char *)group_from_gid((g), !(frc)))
#endif
#if !HAVE_UGID_FROM_UG
int usrtb_start(void);
int grptb_start(void);
int uid_name(const char *, uid_t *);
int gid_name(const char *, gid_t *);
int uid_uncached(const char *, uid_t *);
int gid_uncached(const char *, gid_t *);
#else
#define uid_name uid_from_user
#define gid_name gid_from_group
#define uid_uncached uid_from_user
#define gid_uncached gid_from_group
#endif

/*
 * cpio.c
 */
int cpio_strd(void);
int cpio_trail(ARCHD *, char *, int, int *);
int cpio_endwr(void);
int cpio_id(char *, int);
int cpio_rd(ARCHD *, char *);
off_t cpio_endrd(void);
int cpio_stwr(int);
int dist_stwr(int);
int cpio_wr(ARCHD *);
int vcpio_id(char *, int);
int crc_id(char *, int);
int crc_strd(void);
int vcpio_rd(ARCHD *, char *);
off_t vcpio_endrd(void);
int crc_stwr(int);
int v4root_stwr(int);
int v4norm_stwr(int);
int vcpio_wr(ARCHD *);
int bcpio_id(char *, int);
int bcpio_rd(ARCHD *, char *);
off_t bcpio_endrd(void);
int bcpio_wr(ARCHD *);

/*
 * file_subs.c
 */
int file_creat(ARCHD *);
void file_close(ARCHD *, int);
int lnk_creat(ARCHD *, int *);
int cross_lnk(ARCHD *);
int chk_same(ARCHD *);
int node_creat(ARCHD *);
int unlnk_exist(char *, int);
int chk_path(char *, uid_t, gid_t);
void set_ftime(const char *, const struct stat *, int, int);
int set_ids(char *, uid_t, gid_t, int);
int fset_ids(char *, int, uid_t, gid_t);
void set_pmode(char *, mode_t, int);
void fset_pmode(char *, int, mode_t);
struct file_times; /* avoid pulling time.h globally */
int set_attr(const struct file_times *, int _force_times, mode_t,
    int _do_mode, int _in_sig);
int file_write(int, char *, int, int *, int *, int, char *);
void file_flush(int, char *, int);
void rdfile_close(ARCHD *, int *);
int set_crc(ARCHD *, int);

/*
 * ftree.c
 */
int ftree_start(void);
int ftree_add(char *, int);
void ftree_sel(ARCHD *);
void ftree_skipped_newer(void);
void ftree_chk(void);
int next_file(ARCHD *);

/*
 * gen_subs.c
 */
void ls_list(ARCHD *, FILE *);
void ls_tty(ARCHD *);
void safe_print(const char *, FILE *);
u_long asc_ul(char *, int, int);
int ul_asc(u_long, char *, int, int);
unsigned long long asc_ull(char *, int, int);
int ull_asc(unsigned long long, char *, int, int);
size_t fieldcpy(char *, size_t, const char *, size_t);

/*
 * getoldopt.c
 */
int getoldopt(int, char **, const char *);

/*
 * options.c
 */
extern const FSUB fsub[];
extern const unsigned char ford[];
extern int anonarch;
extern char to_stdout;
void options(int, char **);
OPLIST * opt_next(void);
int opt_add(const char *);
int bad_opt(void);
void guess_compress_program(int);
void anonarch_init(void);
void mircpio_deprecated(const char *, const char *);
extern char *chdname;

/*
 * pat_rep.c
 */
int rep_add(char *);
int pat_add(char *, char *);
void pat_chk(void);
int pat_sel(ARCHD *);
int pat_match(ARCHD *);
int mod_name(ARCHD *);
int set_dest(ARCHD *, char *, int);
int has_dotdot(const char *);

/*
 * pax.c
 */
extern signed char act;
extern const FSUB *frmt;
extern signed char cflag;
extern signed char cwdfd;
extern signed char dflag;
extern signed char iflag;
extern signed char kflag;
extern signed char lflag;
extern signed char nflag;
extern signed char tflag;
extern signed char uflag;
extern signed char Vflag;
extern signed char vflag;
extern signed char Dflag;
extern signed char Hflag;
extern signed char Lflag;
extern signed char Xflag;
extern signed char Yflag;
extern signed char Zflag;
extern signed char zeroflag;
extern signed char vfpart;
extern signed char patime;
extern signed char pmtime;
extern signed char nodirs;
extern signed char pmode;
extern signed char pids;
extern signed char rmleadslash;
extern signed char exit_val;
extern signed char docrc;
extern char *dirptr;
extern const char *argv0;
extern enum op_mode { OP_PAX, OP_TAR, OP_CPIO } op_mode;
extern FILE *listf;
extern int listfd;
extern char *tempfile;
extern char *tempbase;
extern char havechd;
extern time_t now;

void sig_cleanup(int) MKSH_A_NORETURN;

/*
 * sel_subs.c
 */
int sel_chk(ARCHD *);
int grp_add(char *);
int usr_add(char *);
int trng_add(char *);

/*
 * tables.c
 */
int lnk_start(void);
int chk_lnk(ARCHD *);
void purg_lnk(ARCHD *);
void lnk_end(void);
int ftime_start(void);
int chk_ftime(ARCHD *);
int sltab_start(void);
int sltab_add_sym(const char *_path, const char *_value, mode_t _mode);
int sltab_add_link(const char *, const struct stat *);
void sltab_process(int _in_sig);
int name_start(void);
int add_name(char *, int, char *);
void sub_name(char *, int *, int);
int dev_start(void);
int add_dev(ARCHD *);
int map_dev(ARCHD *, u_long, u_long);
int atdir_start(void);
void atdir_end(void);
void add_atdir(const char *, const struct stat *);
int do_atdir(const char *, dev_t, ino_t);
int dir_start(void);
void add_dir(char *, struct stat *, int);
void delete_dir(dev_t, ino_t);
void proc_dir(int _in_sig);
unsigned int st_hash(const char *, int, int);
int flnk_start(void);
int chk_flnk(ARCHD *);

/*
 * tar.c
 */
#ifndef SMALL
extern char tar_nodir;
#endif
extern char *gnu_name_string, *gnu_link_string;
int tar_endwr(void);
off_t tar_endrd(void);
int tar_trail(ARCHD *, char *, int, int *);
int tar_id(char *, int);
#ifndef SMALL
int tar_opt(void);
#else
#define tar_opt bad_opt
#endif
int tar_rd(ARCHD *, char *);
int tar_wr(ARCHD *);
int ustar_strd(void);
int ustar_stwr(int);
int ustar_id(char *, int);
int ustar_rd(ARCHD *, char *);
int ustar_wr(ARCHD *);

/*
 * tty_subs.c
 */
extern char fdgetline_err;
char *fdgetline(int);
int tty_init(void);
void tty_prnt(const char *, ...)
    MKSH_A_NONNULL(1)
    MKSH_A_FORMAT(__printf__, 1, 2);
char *tty_rd(void);
#endif
void paxwarn(int, const char *, ...)
    MKSH_A_NONNULL(2)
    MKSH_A_FORMAT(__printf__, 2, 3);
void syswarn(int, int, const char *, ...)
    MKSH_A_NONNULL(3)
    MKSH_A_FORMAT(__printf__, 3, 4);
