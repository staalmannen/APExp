#ifndef GEN_H
#define GEN_H

#include "conf.h"

int gen_project(const char *root, struct Conf *conf);
int gen_config_only(const char *root, struct Conf *conf);

#endif
