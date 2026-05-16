#ifndef MACRO_H
#define MACRO_H

#include "map.h"
#include "vec.h"

struct MacroSet {
	struct Vec names;
	struct Map bodies;
};

void macroset_init(struct MacroSet *m);
void macroset_free(struct MacroSet *m);
void macroset_add(struct MacroSet *m, const char *name, const char *body);

int macroset_load_project(struct MacroSet *m, const char *config_path,
	const char *config_buf);

char *macroset_expand_all(struct MacroSet *m, const char *buf);

#endif
