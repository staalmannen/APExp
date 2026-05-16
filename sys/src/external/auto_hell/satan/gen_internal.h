#ifndef GEN_INTERNAL_H
#define GEN_INTERNAL_H

#include "conf.h"
#include "map.h"
#include "vec.h"

struct GenCtx {
	struct Conf *conf;
	struct Map seen_dirs;
	struct Map warn_flags;
	struct Map conds;
	struct Map defs;
	struct Map undefs;
	struct Map need_gen;
	struct Map gen_pick;
	int have_config_h;
	int probe_static_ok;
	int probe_quiet;
	size_t probe_total;
	size_t probe_done;
	struct Vec probe_log;
	struct Vec dirs;
	struct Vec installs;
	struct Vec replace_srcs;
};

int warn_once(struct GenCtx *g, const char *msg);
void split_words(struct Vec *out, const char *s);
int starts_with(const char *s, const char *pre);
int ends_with(const char *s, const char *suf);
int str_has_bad_chars(const char *s);

#endif
