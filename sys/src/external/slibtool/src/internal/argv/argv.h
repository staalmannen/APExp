/****************************************************************************/
/*  argv.h: a thread-safe argument vector parser and usage screen generator */
/*  Copyright (C) 2015--2025  SysDeer Technologies, LLC                     */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL.          */
/****************************************************************************/

#ifndef ARGV_H
#define ARGV_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define ARGV_VERBOSITY_NONE		0x00
#define ARGV_VERBOSITY_ERRORS		0x01
#define ARGV_VERBOSITY_STATUS		0x02
#define ARGV_CLONE_VECTOR		0x80

#ifndef ARGV_TAB_WIDTH
#define ARGV_TAB_WIDTH			8
#endif

/*******************************************/
/*                                         */
/* support of hybrid options               */
/* -------------------------               */
/* hybrid options are very similar to      */
/* long options, yet are prefixed by       */
/* a single dash rather than two           */
/* (i.e. -std, -isystem).                  */
/* hybrid options are supported by this    */
/* driver for compatibility with legacy    */
/* tools; note, however, that the use      */
/* of hybrid options should be strongly    */
/* discouraged due to the limitations      */
/* they impose on short options (for       */
/* example, a driver implementing -std     */
/* may not provide -s as a short option    */
/* that takes an arbitrary value).         */
/*                                         */
/* SPACE: -hybrid VALUE (i.e. -MF file)    */
/* EQUAL: -hybrid=VALUE (i.e. -std=c99)    */
/* COMMA: -hybrid,VALUE (i.e. -Wl,<arg>)   */
/* ONLY:  -opt accepted, --opt rejected    */
/* JOINED: -optVALUE                       */
/*                                         */
/*******************************************/


#define ARGV_OPTION_HYBRID_NONE		0x00
#define ARGV_OPTION_HYBRID_ONLY		0x01
#define ARGV_OPTION_HYBRID_SPACE	0x02
#define ARGV_OPTION_HYBRID_EQUAL	0x04
#define ARGV_OPTION_HYBRID_COMMA	0x08
#define ARGV_OPTION_HYBRID_JOINED	0x10

#define ARGV_OPTION_KEYVAL_PAIR         0X20
#define ARGV_OPTION_KEYVAL_ARRAY        0X40
#define ARGV_OPTION_KEYVAL_MASK         (ARGV_OPTION_KEYVAL_PAIR \
					| ARGV_OPTION_KEYVAL_ARRAY)

#define ARGV_OPTION_HYBRID_CIRCUS	(ARGV_OPTION_HYBRID_SPACE \
					| ARGV_OPTION_HYBRID_JOINED)

#define ARGV_OPTION_HYBRID_DUAL		(ARGV_OPTION_HYBRID_SPACE \
					| ARGV_OPTION_HYBRID_EQUAL)

#define ARGV_OPTION_HYBRID_SWITCH	(ARGV_OPTION_HYBRID_ONLY \
					| ARGV_OPTION_HYBRID_SPACE \
					| ARGV_OPTION_HYBRID_EQUAL \
					| ARGV_OPTION_HYBRID_COMMA \
					| ARGV_OPTION_HYBRID_JOINED)

#define ARGV_KEYVAL_ASSIGN              0x01
#define ARGV_KEYVAL_OVERRIDE            0x02

enum argv_optarg {
	ARGV_OPTARG_NONE,
	ARGV_OPTARG_REQUIRED,
	ARGV_OPTARG_OPTIONAL,
};

enum argv_mode {
	ARGV_MODE_SCAN,
	ARGV_MODE_COPY,
};

enum argv_error {
	ARGV_ERROR_OK,
	ARGV_ERROR_INTERNAL,
	ARGV_ERROR_SHORT_OPTION,
	ARGV_ERROR_LONG_OPTION,
	ARGV_ERROR_VENDOR_OPTION,
	ARGV_ERROR_OPTARG_NONE,
	ARGV_ERROR_OPTARG_REQUIRED,
	ARGV_ERROR_OPTARG_PARADIGM,
	ARGV_ERROR_HYBRID_NONE,
	ARGV_ERROR_HYBRID_ONLY,
	ARGV_ERROR_HYBRID_SPACE,
	ARGV_ERROR_HYBRID_EQUAL,
	ARGV_ERROR_HYBRID_COMMA,
	ARGV_ERROR_KEYVAL_KEY,
	ARGV_ERROR_KEYVAL_VALUE,
	ARGV_ERROR_KEYVAL_ALLOC,
};

struct argv_option {
	const char *		long_name;
	const char		short_name;
	int			tag;
	enum argv_optarg	optarg;
	int			flags;
	const char *		paradigm;
	const char *		argname;
	const char *		description;
};

struct argv_keyval {
	const char *           keyword;
	const char *           value;
	int                    flags;
};

struct argv_entry {
	const char *            arg;
	struct argv_keyval *    keyv;
	int                     tag;
	bool                    fopt;
	bool                    fval;
	bool                    fnoscan;
	enum argv_error         errcode;
};

struct argv_meta {
	char **			argv;
	struct argv_entry *	entries;
};

struct argv_ctx {
	int				flags;
	int				mode;
	int				nentries;
	intptr_t			unitidx;
	intptr_t			erridx;
	enum argv_error 		errcode;
	const char *			errch;
	const struct argv_option *	erropt;
	const char *			program;
	size_t				keyvlen;
};

#ifdef ARGV_DRIVER

struct argv_meta_impl {
	char **			argv;
	char *			strbuf;
	char *                  keyvbuf;
	char *                  keyvmark;
	struct argv_meta	meta;
};

static int argv_optv_init(
	const struct argv_option[],
	const struct argv_option **);

static const char * argv_program_name(const char *);

static void argv_usage(
	int		fd,
	const char *	header,
	const struct	argv_option **,
	const char *	mode);

static void argv_usage_plain(
	int		fd,
	const char *	header,
	const struct	argv_option **,
	const char *	mode);

static struct argv_meta * argv_get(
	char **,
	const struct argv_option **,
	int flags,
	int fd);

static void argv_free(struct argv_meta *);

#ifndef argv_dprintf
#define argv_dprintf dprintf
#endif



/*------------------------------------*/
/* implementation of static functions */
/*------------------------------------*/

static int argv_optv_init(
	const struct argv_option	options[],
	const struct argv_option **	optv)
{
	const struct argv_option *	option;
	int				i;

	for (option=options,i=0; option->long_name || option->short_name; option++)
		optv[i++] = option;

	optv[i] = 0;
	return i;
}

static const struct argv_option * argv_short_option(
	const char *			ch,
	const struct argv_option **	optv,
	struct argv_entry *		entry)
{
	const struct argv_option *	option;

	for (; *optv; optv++) {
		option = *optv;

		if (option->short_name == *ch) {
			entry->tag	= option->tag;
			entry->fopt	= true;
			return option;
		}
	}

	return 0;
}

static const struct argv_option * argv_long_option(
	const char *			ch,
	const struct argv_option **	optv,
	struct argv_entry *		entry)
{
	const struct argv_option *	option;
	const char *			arg;
	size_t				len;

	for (; *optv; optv++) {
		option = *optv;
		len    = option->long_name ? strlen(option->long_name) : 0;

		if (len && !(strncmp(option->long_name,ch,len))) {
			arg = ch + len;

			if (!*arg
				|| (*arg == '=')
				|| (option->flags & ARGV_OPTION_HYBRID_JOINED)
				|| ((option->flags & ARGV_OPTION_HYBRID_COMMA)
					&& (*arg == ','))) {
				entry->tag	= option->tag;
				entry->fopt	= true;
				return option;
			}
		}
	}

	return 0;
}

static inline bool is_short_option(const char * arg)
{
	return (arg[0]=='-') && arg[1] && (arg[1]!='-');
}

static inline bool is_long_option(const char * arg)
{
	return (arg[0]=='-') && (arg[1]=='-') && arg[2];
}

static inline bool is_last_option(const char * arg)
{
	return (arg[0]=='-') && (arg[1]=='-') && !arg[2];
}

static inline bool is_hybrid_option(
	const char *			arg,
	const struct argv_option **	optv)
{
	const struct argv_option *	option;
	struct argv_entry		entry;

	if (!is_short_option(arg))
		return false;

	if (!(option = argv_long_option(++arg,optv,&entry)))
		return false;

	if (!(option->flags & ARGV_OPTION_HYBRID_SWITCH))
		if (argv_short_option(arg,optv,&entry))
			return false;

	return true;
}

static inline bool is_arg_in_paradigm(const char * arg, const char * paradigm)
{
	size_t		len;
	const char *	ch;

	for (ch=paradigm,len=strlen(arg); ch; ) {
		if (!strncmp(arg,ch,len)) {
			if (!*(ch += len))
				return true;
			else if (*ch == '|')
				return true;
		}

		if ((ch = strchr(ch,'|')))
			ch++;
	}

	return false;
}

static inline const struct argv_option * option_from_tag(
	const struct argv_option **	optv,
	int				tag)
{
	for (; *optv; optv++)
		if (optv[0]->tag == tag)
			return optv[0];
	return 0;
}

static inline int argv_scan_keyval_array(struct argv_meta_impl * meta, struct argv_entry * entry)
{
	const char *            ch;
	char *                  dst;
	int                     ncomma;
	int                     cint;
	struct argv_keyval *    keyv;

	/* count key[val] elements, assume no comma after last element */
	for (ch=entry->arg,ncomma=1; *ch; ch++) {
		if ((ch[0]=='\\') && (ch[1]==',')) {
			ch++;

		} else if ((ch[0]==',')) {
			ncomma++;
		}
	}

	/* keyval string buffer */
	dst = meta->keyvmark;

	/* allocate keyval array */
	if (!(entry->keyv = calloc(ncomma+1,sizeof(*entry->keyv))))
		return ARGV_ERROR_KEYVAL_ALLOC;

	/* create keyval array */
	entry->keyv->keyword = dst;

	for (ch=entry->arg,keyv=entry->keyv; *ch; ch++) {
		if ((ch[0]=='\\') && (ch[1]==',')) {
			*dst++ = ',';
			ch++;

		} else if ((ch[0]==':') && (ch[1]=='=')) {
			if (!keyv->keyword[0])
				return ARGV_ERROR_KEYVAL_KEY;

			keyv->flags = ARGV_KEYVAL_OVERRIDE;
			keyv->value = ++dst;
			ch++;

		} else if ((ch[0]=='=')) {
			if (!keyv->keyword[0])
				return ARGV_ERROR_KEYVAL_KEY;

			keyv->flags = ARGV_KEYVAL_ASSIGN;
			keyv->value = ++dst;

		} else if ((ch[0]==',')) {
			for (; isblank(cint = ch[1]); )
				ch++;

			if (ch[1]) {
				keyv++;
				keyv->keyword = ++dst;
			}
		} else {
			*dst++ = *ch;
		}
	}

	/* keyval string buffer */
	meta->keyvmark = ++dst;

	return ARGV_ERROR_OK;
}

static inline int argv_scan_keyval_pair(struct argv_meta_impl * meta, struct argv_entry * entry)
{
	const char *            ch;
	char *                  dst;
	struct argv_keyval *    keyv;

	/* keyval string buffer */
	dst = meta->keyvmark;

	/* allocate keyval array */
	if (!(entry->keyv = calloc(2,sizeof(*entry->keyv))))
		return ARGV_ERROR_KEYVAL_ALLOC;

	/* create keyval array */
	entry->keyv->keyword = dst;

	for (ch=entry->arg,keyv=entry->keyv; *ch && !keyv->flags; ch++) {
		if ((ch[0]=='\\') && (ch[1]==',')) {
			*dst++ = ',';
			ch++;

		} else if ((ch[0]==':') && (ch[1]=='=')) {
			if (!keyv->keyword[0])
				return ARGV_ERROR_KEYVAL_KEY;

			keyv->flags = ARGV_KEYVAL_OVERRIDE;
			keyv->value = ++dst;
			ch++;

		} else if ((ch[0]=='=')) {
			if (!keyv->keyword[0])
				return ARGV_ERROR_KEYVAL_KEY;

			keyv->flags = ARGV_KEYVAL_ASSIGN;
			keyv->value = ++dst;

		} else {
			*dst++ = *ch;
		}
	}

	for (; *ch; )
		*dst++ = *ch++;

	/* keyval string buffer */
	meta->keyvmark = ++dst;

	return ARGV_ERROR_OK;
}

static void argv_scan(
	char **				argv,
	const struct argv_option **	optv,
	struct argv_ctx *		ctx,
	struct argv_meta *		meta)
{
	struct argv_meta_impl *         imeta;
	uintptr_t                       addr;
	char **				parg;
	const char *			ch;
	const char *			val;
	const struct argv_option *	option;
	struct argv_entry		entry;
	struct argv_entry *		mentry;
	enum argv_error			ferr;
	bool				fval;
	bool				fnext;
	bool				fshort;
	bool				fhybrid;
	bool				fnoscan;

	addr  = (uintptr_t)meta - offsetof(struct argv_meta_impl,meta);
	imeta = (struct argv_meta_impl *)addr;

	parg	= &argv[1];
	ch	= *parg;
	ferr	= ARGV_ERROR_OK;
	fshort	= false;
	fnoscan	= false;
	fval	= false;
	mentry	= meta ? meta->entries : 0;

	ctx->unitidx = 0;
	ctx->erridx  = 0;

	while (ch && (ferr == ARGV_ERROR_OK)) {
		option  = 0;
		fhybrid = false;

		if (fnoscan)
			fval = true;

		else if (is_last_option(ch))
			fnoscan = true;

		else if (!fshort && is_hybrid_option(ch,optv))
			fhybrid = true;

		if (!fnoscan && !fhybrid && (fshort || is_short_option(ch))) {
			if (!fshort)
				ch++;

			if ((option = argv_short_option(ch,optv,&entry))) {
				if (ch[1]) {
					ch++;
					fnext	= false;
					fshort	= (option->optarg == ARGV_OPTARG_NONE);
				} else {
					parg++;
					ch	= *parg;
					fnext	= true;
					fshort	= false;
				}

				if (option->optarg == ARGV_OPTARG_NONE) {
					if (!fnext && ch && (*ch == '-')) {
						ferr = ARGV_ERROR_OPTARG_NONE;
					} else {
						fval = false;
					}

				} else if (!fnext) {
					fval = true;

				} else if (option->optarg == ARGV_OPTARG_REQUIRED) {
					if (ch && is_short_option(ch))
						ferr = ARGV_ERROR_OPTARG_REQUIRED;
					else if (ch && is_long_option(ch))
						ferr = ARGV_ERROR_OPTARG_REQUIRED;
					else if (ch && is_last_option(ch))
						ferr = ARGV_ERROR_OPTARG_REQUIRED;
					else if (ch)
						fval = true;
					else
						ferr = ARGV_ERROR_OPTARG_REQUIRED;
				} else {
					/* ARGV_OPTARG_OPTIONAL */
					if (ch && is_short_option(ch))
						fval = false;
					else if (ch && is_long_option(ch))
						fval = false;
					else if (ch && is_last_option(ch))
						fval = false;
					else if (fnext)
						fval = false;
					else
						fval = ch;
				}
			} else {
				if ((ch == &parg[0][1]) && (ch[0] == 'W') && ch[1]) {
					ferr = ARGV_ERROR_VENDOR_OPTION;
				} else {
					ferr = ARGV_ERROR_SHORT_OPTION;
				}
			}

		} else if (!fnoscan && (fhybrid || is_long_option(ch))) {
			ch += (fhybrid ? 1 : 2);

			if ((option = argv_long_option(ch,optv,&entry))) {
				val = ch + strlen(option->long_name);

				/* val[0] is either '=' (or ',') or '\0' */
				if (!val[0]) {
					parg++;
					ch = *parg;
				}

				/* now verify the proper setting of option values */
				if (fhybrid && !(option->flags & ARGV_OPTION_HYBRID_SWITCH)) {
					ferr = ARGV_ERROR_HYBRID_NONE;

				} else if (!fhybrid && (option->flags & ARGV_OPTION_HYBRID_ONLY)) {
					ferr = ARGV_ERROR_HYBRID_ONLY;

				} else if (option->optarg == ARGV_OPTARG_NONE) {
					if (val[0]) {
						ferr = ARGV_ERROR_OPTARG_NONE;
						ctx->errch = val + 1;
					} else {
						fval = false;
					}

				} else if (val[0] && (option->flags & ARGV_OPTION_HYBRID_JOINED)) {
					fval = true;
					ch   = val;

				} else if (fhybrid && !val[0] && !(option->flags & ARGV_OPTION_HYBRID_SPACE)) {
					if (option->optarg == ARGV_OPTARG_OPTIONAL) {
						fval = false;

					} else {
						ferr = ARGV_ERROR_HYBRID_SPACE;
					}

				} else if (fhybrid && (val[0]=='=') && !(option->flags & ARGV_OPTION_HYBRID_EQUAL)) {
					ferr = ARGV_ERROR_HYBRID_EQUAL;

				} else if (fhybrid && (val[0]==',') && !(option->flags & ARGV_OPTION_HYBRID_COMMA)) {
					ferr = ARGV_ERROR_HYBRID_COMMA;

				} else if (!fhybrid && (val[0]==',')) {
					ferr = ARGV_ERROR_HYBRID_COMMA;

				} else if (val[0] && !val[1]) {
					ferr = ARGV_ERROR_OPTARG_REQUIRED;

				} else if (val[0] && val[1]) {
					fval = true;
					ch   = ++val;

				} else if (option->optarg == ARGV_OPTARG_REQUIRED) {
					if (!val[0] && !*parg) {
						ferr = ARGV_ERROR_OPTARG_REQUIRED;

					} else if (*parg && is_short_option(*parg)) {
						ferr = ARGV_ERROR_OPTARG_REQUIRED;

					} else if (*parg && is_long_option(*parg)) {
						ferr = ARGV_ERROR_OPTARG_REQUIRED;

					} else if (*parg && is_last_option(*parg)) {
						ferr = ARGV_ERROR_OPTARG_REQUIRED;

					} else {
						fval = true;
					}
				} else {
					/* ARGV_OPTARG_OPTIONAL */
					fval = val[0];
				}
			} else {
				ferr = ARGV_ERROR_LONG_OPTION;
			}
		}

		if (ferr == ARGV_ERROR_OK)
			if (option && fval && option->paradigm)
				if (!is_arg_in_paradigm(ch,option->paradigm))
					ferr = ARGV_ERROR_OPTARG_PARADIGM;

		if (ferr == ARGV_ERROR_OK)
			if (!option && !ctx->unitidx)
				ctx->unitidx = parg - argv;

		if (ferr == ARGV_ERROR_OK)
			if (option && (option->flags & ARGV_OPTION_KEYVAL_MASK))
				if (ctx->mode == ARGV_MODE_SCAN)
					ctx->keyvlen += strlen(ch) + 1;

		if (ferr != ARGV_ERROR_OK) {
			ctx->errcode = ferr;
			ctx->errch   = ctx->errch ? ctx->errch : ch;
			ctx->erropt  = option;
			ctx->erridx  = parg - argv;
			return;
		}

		if (ctx->mode == ARGV_MODE_SCAN) {
			if (!fnoscan)
				ctx->nentries++;
			else if (fval)
				ctx->nentries++;

			if (fval || !option) {
				parg++;
				ch = *parg;
			}

		} else if (ctx->mode == ARGV_MODE_COPY) {
			if (fnoscan) {
				if (fval) {
					mentry->arg	= ch;
					mentry->fnoscan = true;
				}

				parg++;
				ch = *parg;
			} else if (option) {
				mentry->arg	= fval ? ch : 0;
				mentry->tag	= option->tag;
				mentry->fopt	= true;
				mentry->fval	= fval;

				if (fval) {
					parg++;
					ch = *parg;
				}
			} else {
				mentry->arg = ch;
				parg++;
				ch = *parg;
			}
		}

		if (option && (option->flags & ARGV_OPTION_KEYVAL_PAIR))
			if (ctx->mode == ARGV_MODE_COPY)
				ferr = argv_scan_keyval_pair(imeta,mentry);

		if (option && (option->flags & ARGV_OPTION_KEYVAL_ARRAY))
			if (ctx->mode == ARGV_MODE_COPY)
				ferr = argv_scan_keyval_array(imeta,mentry);

		if (ferr != ARGV_ERROR_OK) {
			ctx->errcode = ferr;
			ctx->errch   = ctx->errch ? ctx->errch : ch;
			ctx->erropt  = option;
			ctx->erridx  = parg - argv;
			return;
		}

		mentry++;
	}
}

static const char * argv_program_name(const char * program_path)
{
	const char * ch;

	if (program_path) {
		if ((ch = strrchr(program_path,'/')))
			return *(++ch) ? ch : 0;

		if ((ch = strrchr(program_path,'\\')))
			return *(++ch) ? ch : 0;
	}

	return program_path;
}

static void argv_show_error(int fd, struct argv_ctx * ctx)
{
	const char * src;
	char *       dst;
	char *       cap;
	char         opt_vendor_buf[256];
	char         opt_short_name[2] = {0,0};

	if (ctx->erropt && ctx->erropt->short_name)
		opt_short_name[0] = ctx->erropt->short_name;

	argv_dprintf(fd,"%s: error: ",ctx->program);

	switch (ctx->errcode) {
		case ARGV_ERROR_SHORT_OPTION:
			argv_dprintf(fd,"'-%c' is not a valid short option\n",*ctx->errch);
			break;

		case ARGV_ERROR_LONG_OPTION:
			argv_dprintf(fd,"'--%s' is not a valid long option\n",ctx->errch);
			break;

		case ARGV_ERROR_VENDOR_OPTION:
			src = ctx->errch;
			dst = opt_vendor_buf;
			cap = &opt_vendor_buf[sizeof(opt_vendor_buf)];

			for (; src && *src && dst<cap; ) {
				if ((*src == '=') || (*src == ',') || (*src == ':')) {
					src  = 0;
				} else {
					*dst++ = *src++;
				}
			}

			if (dst == cap)
				dst--;

			*dst = '\0';

			argv_dprintf(fd,"'-%s' is not a valid vendor option\n",opt_vendor_buf);
			break;

		case ARGV_ERROR_OPTARG_NONE:
			argv_dprintf(fd,"'%s' is not a valid option value for [%s%s%s%s%s] "
					"(option values may not be specified)\n",
				ctx->errch,
				opt_short_name[0] ? "-" : "",
				opt_short_name,
				opt_short_name[0] ? "," : "",
				ctx->erropt->long_name ? "--" : "",
				ctx->erropt->long_name);
			break;

		case ARGV_ERROR_OPTARG_REQUIRED:
			argv_dprintf(fd,"option [%s%s%s%s%s] requires %s %s%s%s\n",
				opt_short_name[0] ? "-" : "",
				opt_short_name,
				opt_short_name[0] ? "," : "",
				ctx->erropt->long_name
					? (ctx->erropt->flags & ARGV_OPTION_HYBRID_ONLY) ? "-" : "--"
					: "",
				ctx->erropt->long_name,
				ctx->erropt->paradigm ? "one of the following values:" : "a value",
				ctx->erropt->paradigm ? "{" : "",
				ctx->erropt->paradigm ? ctx->erropt->paradigm : "",
				ctx->erropt->paradigm ? "}" : "");
			break;

		case ARGV_ERROR_OPTARG_PARADIGM:
			argv_dprintf(fd,"'%s' is not a valid option value for [%s%s%s%s%s]={%s}\n",
				ctx->errch,
				opt_short_name[0] ? "-" : "",
				opt_short_name,
				opt_short_name[0] ? "," : "",
				ctx->erropt->long_name ? "--" : "",
				ctx->erropt->long_name,
				ctx->erropt->paradigm);
			break;

		case ARGV_ERROR_HYBRID_NONE:
			argv_dprintf(fd,"-%s is not a synonym for --%s\n",
				ctx->erropt->long_name,
				ctx->erropt->long_name);
			break;

		case ARGV_ERROR_HYBRID_ONLY:
			argv_dprintf(fd,"--%s is not a synonym for -%s\n",
				ctx->erropt->long_name,
				ctx->erropt->long_name);
			break;

		case ARGV_ERROR_HYBRID_SPACE:
		case ARGV_ERROR_HYBRID_EQUAL:
		case ARGV_ERROR_HYBRID_COMMA:
			argv_dprintf(fd,"-%s: illegal value assignment; valid syntax is "
					"-%s%sVAL\n",
				ctx->erropt->long_name,
				ctx->erropt->long_name,
				(ctx->erropt->flags & ARGV_OPTION_HYBRID_SPACE)
					? " " : (ctx->erropt->flags & ARGV_OPTION_HYBRID_EQUAL)
					? "=" : (ctx->erropt->flags & ARGV_OPTION_HYBRID_COMMA)
					? "," : "");

			break;

		case ARGV_ERROR_KEYVAL_KEY:
			argv_dprintf(fd,"illegal key detected in keyval argument\n");
			break;

		case ARGV_ERROR_KEYVAL_VALUE:
			argv_dprintf(fd,"illegal value detected in keyval argument\n");
			break;

		case ARGV_ERROR_INTERNAL:
			argv_dprintf(fd,"internal error");
			break;

		default:
			break;
	}
}

static void argv_show_status(
	int				fd,
	const struct argv_option **	optv,
	struct argv_ctx *		ctx,
	struct argv_meta *		meta)
{
	int				i;
	int				argc;
	char **				argv;
	struct argv_keyval *            keyv;
	struct argv_entry *		entry;
	const struct argv_option *	option;
	char				short_name[2] = {0};
	const char *			space = "";

	(void)ctx;

	argv_dprintf(fd,"\n\nconcatenated command line:\n");
	for (argv=meta->argv; *argv; argv++) {
		argv_dprintf(fd,"%s%s",space,*argv);
		space = " ";
	}

	argv_dprintf(fd,"\n\nargument vector:\n");
	for (argc=0,argv=meta->argv; *argv; argc++,argv++)
		argv_dprintf(fd,"argv[%d]: %s\n",argc,*argv);

	argv_dprintf(fd,"\n\nparsed entries:\n");
	for (entry=meta->entries; entry->arg || entry->fopt; entry++) {
		if (entry->fopt) {
			option = option_from_tag(optv,entry->tag);
			short_name[0] = option->short_name;

			if (entry->fval)
				argv_dprintf(fd,"[-%s,--%s] := %s\n",
					short_name,option->long_name,entry->arg);
			else
				argv_dprintf(fd,"[-%s,--%s]\n",
					short_name,option->long_name);

			if (entry->keyv) {
				for (i=0,keyv=entry->keyv; keyv->keyword; i++,keyv++) {
					switch (keyv->flags) {
						case ARGV_KEYVAL_ASSIGN:
							argv_dprintf(fd,"\tkeyval[%d]: <%s>=%s\n",
								i,keyv->keyword,keyv->value);
							break;

						case ARGV_KEYVAL_OVERRIDE:
							argv_dprintf(fd,"\tkeyval[%d]: <%s>:=%s\n",
								i,keyv->keyword,keyv->value);
							break;

						default:
							argv_dprintf(fd,"\tkeyval[%d]: <%s>\n",
								i,keyv->keyword);
						break;
					}
				}
			}
		} else {
			argv_dprintf(fd,"<program arg> := %s\n",entry->arg);
		}
	}

	argv_dprintf(fd,"\n\n");
}

static struct argv_meta * argv_free_impl(struct argv_meta_impl * imeta)
{
	struct argv_entry * entry;
	void *              addr;

	if (imeta->keyvbuf)
		for (entry=imeta->meta.entries; entry->fopt || entry->arg; entry++)
			if (entry->keyv)
				free((addr = entry->keyv));

	if (imeta->keyvbuf)
		free(imeta->keyvbuf);

	if (imeta->argv)
		free(imeta->argv);

	if (imeta->strbuf)
		free(imeta->strbuf);

	if (imeta->meta.entries)
		free(imeta->meta.entries);

	free(imeta);
	return 0;
}

static struct argv_meta * argv_alloc(char ** argv, struct argv_ctx * ctx)
{
	struct argv_meta_impl * imeta;
	char **			vector;
	char *			dst;
	size_t			size;
	int			argc;
	int			i;

	if (!(imeta = calloc(1,sizeof(*imeta))))
		return 0;

	if (ctx->flags & ARGV_CLONE_VECTOR) {
		for (vector=argv,argc=0,size=0; *vector; vector++) {
			size += strlen(*vector) + 1;
			argc++;
		}

		if (!(imeta->argv = calloc(argc+1,sizeof(char *))))
			return argv_free_impl(imeta);

		if (!(imeta->strbuf = calloc(1,size+1)))
			return argv_free_impl(imeta);

		for (i=0,dst=imeta->strbuf; i<argc; i++) {
			strcpy(dst,argv[i]);
			imeta->argv[i] = dst;
			dst += strlen(dst)+1;
		}

		imeta->meta.argv = imeta->argv;
	} else {
		imeta->meta.argv = argv;
	}

	imeta->meta.entries = calloc(
		ctx->nentries+1,
		sizeof(struct argv_entry));

	if (!imeta->meta.entries)
		return argv_free_impl(imeta);

	if (ctx->keyvlen) {
		imeta->keyvbuf = calloc(
			ctx->keyvlen,
			sizeof(char));

		if (!(imeta->keyvmark = imeta->keyvbuf))
			return argv_free_impl(imeta);
	}

	return &imeta->meta;
}

static struct argv_meta * argv_get(
	char **				argv,
	const struct argv_option **	optv,
	int				flags,
	int				fd)
{
	struct argv_meta *	meta;
	struct argv_ctx		ctx = {flags,ARGV_MODE_SCAN,0,0,0,0,0,0,0,0};

	argv_scan(argv,optv,&ctx,0);

	if (ctx.errcode != ARGV_ERROR_OK) {
		ctx.program = argv_program_name(argv[0]);

		if (ctx.flags & ARGV_VERBOSITY_ERRORS)
			argv_show_error(fd,&ctx);

		return 0;
	}

	if (!(meta = argv_alloc(argv,&ctx)))
		return 0;

	ctx.mode = ARGV_MODE_COPY;
	argv_scan(meta->argv,optv,&ctx,meta);

	if (ctx.errcode != ARGV_ERROR_OK) {
		ctx.program = argv[0];
		ctx.errcode = ARGV_ERROR_INTERNAL;
		argv_show_error(fd,&ctx);
		argv_free(meta);

		return 0;
	}

	if (ctx.flags & ARGV_VERBOSITY_STATUS)
		argv_show_status(fd,optv,&ctx,meta);

	return meta;
}

static void argv_free(struct argv_meta * xmeta)
{
	struct argv_meta_impl * imeta;
	uintptr_t		addr;

	if (xmeta) {
		addr  = (uintptr_t)xmeta - offsetof(struct argv_meta_impl,meta);
		imeta = (struct argv_meta_impl *)addr;
		argv_free_impl(imeta);
	}
}

static void argv_usage_impl(
	int				fd,
	const char *    		header,
	const struct argv_option **	options,
	const char *			mode,
	int				fcolor)
{
	const struct argv_option **	optv;
	const struct argv_option *	option;
	int                             nlong;
	bool				fshort,flong,fboth;
	size_t				len,optlen,desclen;
	char				cache;
	char *				prefix;
	char *				desc;
	char *				mark;
	char *				cap;
	char				description[4096];
	char				optstr     [72];
	const size_t			optcap    = 64;
	const size_t			width     = 80;
	const char			indent[]  = "  ";
	const char			creset[]  = "\x1b[0m";
	const char			cbold []  = "\x1b[1m";
	const char			cgreen[]  = "\x1b[32m";
	const char			cblue []  = "\x1b[34m";
	const char			ccyan []  = "\x1b[36m";
	const char *			color     = ccyan;

	(void)argv_usage;
	(void)argv_usage_plain;

	fshort = mode ? !strcmp(mode,"short") : 0;
	flong  = fshort ? 0 : mode && !strcmp(mode,"long");
	fboth  = !fshort && !flong;

	if (fcolor)
		argv_dprintf(fd,"%s%s",cbold,cgreen);

	if (header)
		argv_dprintf(fd,"%s",header);

	for (optlen=0,nlong=0,optv=options; *optv; optv++) {
		option = *optv;

		/* indent + comma */
		len = fboth ? sizeof(indent) + 1 : sizeof(indent);

		/* -o */
		if (fshort || fboth)
			len += option->short_name
				? 2 : 0;

		/* --option */
		if (flong || fboth)
			len += option->long_name
				? 2 + strlen(option->long_name) : 0;

		/* optlen */
		if (len > optlen)
			optlen = len;

		/* long (vs. hybrid-only) option? */
		if (option->long_name)
			if (!(option->flags & ARGV_OPTION_HYBRID_ONLY))
				nlong++;
	}

	if (optlen >= optcap) {
		argv_dprintf(fd,
			"Option strings exceed %zu characters, "
			"please generate the usage screen manually.\n",
			optcap);
		return;
	}

	optlen += ARGV_TAB_WIDTH;
	optlen &= (~(ARGV_TAB_WIDTH-1));
	desclen = (optlen < width / 2) ? width - optlen : optlen;

	for (optv=options; *optv; optv++) {
		option = *optv;

		/* color */
		if (fcolor) {
			color = (color == ccyan) ? cblue : ccyan;
			argv_dprintf(fd,color,0);
		}

		/* description, using either paradigm or argname if applicable */
		snprintf(description,sizeof(description),option->description,
			option->paradigm
				? option->paradigm
				: option->argname ? option->argname : "");
		description[sizeof(description)-1] = 0;

		/* long/hybrid option prefix (-/--) */
		prefix = option->flags & ARGV_OPTION_HYBRID_ONLY
				? "  -" : " --";

		/* avoid extra <stace> when all long opts are hybrid-only */
		if (nlong == 0)
			prefix++;

		/* option string */
		if (fboth && option->short_name && option->long_name)
			sprintf(optstr,"%s-%c,%s%s",
				indent,option->short_name,prefix,option->long_name);

		else if ((fshort || fboth) && option->short_name)
			sprintf(optstr,"%s-%c",indent,option->short_name);

		else if (flong && option->long_name)
			sprintf(optstr,"%s%s%s",
				indent,prefix,option->long_name);

		else if (fboth && option->long_name)
			sprintf(optstr,"%s   %s%s",
				indent,prefix,option->long_name);

		else
			optstr[0] = 0;

		/* right-indented option buffer */
		if (description[0]) {
			len = strlen(optstr);
			sprintf(&optstr[len],"%-*c",(int)(optlen-len),' ');
		}

		/* single line? */
		if (optlen + strlen(description) < width) {
			argv_dprintf(fd,"%s%s\n",optstr,description);

		} else {
			desc = description;
			cap  = desc + strlen(description);

			while (desc < cap) {
				mark = (desc + desclen >= cap)
					? cap : desc + desclen;

				while (*mark && (mark > desc)
						&& (*mark != ' ')
						&& (*mark != '|')
						&& (*mark != '\t')
						&& (*mark != '\n'))
					mark--;

				if (mark == desc) {
					mark = (desc + desclen >= cap)
						? cap : desc + desclen;
					cache = *mark;
					*mark = 0;
				} else if (*mark == '|') {
					cache = *mark;
					*mark = 0;
				} else {
					cache = 0;
					*mark = 0;
				}

				/* first line? */
				if (desc == description)
					argv_dprintf(fd,"%s%s\n",optstr,desc);
				else
					argv_dprintf(fd,"%-*c %s\n",
						(*desc == '|')
							? (int)(optlen+1)
							: (int)optlen,
						' ',desc);

				if (cache)
					*mark = cache;
				else
					mark++;

				desc = mark;
			}
		}
	}

	if (fcolor)
		argv_dprintf(fd,creset);
}

static void argv_usage(
	int				fd,
	const char *    		header,
	const struct argv_option **	options,
	const char *			mode)
{
	argv_usage_impl(fd,header,options,mode,isatty(fd));
}

static void argv_usage_plain(
	int				fd,
	const char *    		header,
	const struct argv_option **	options,
	const char *			mode)
{
	argv_usage_impl(fd,header,options,mode,0);
}

#endif

#endif
