# changes made to this file will be gone the next time
#   you run ./configure.

# for persistent post-configure, ad-hoc changes to the
#   build project, use usrdefs.mk instead.


CFLAGS_CONFIG           += -DHAVE_SYS_SYSCALL_H

CFLAGS_CONFIG           += -DSLBT_PREFERRED_HOST_AR=0
CFLAGS_CONFIG           += -DSLBT_PREFERRED_HOST_AS=0
CFLAGS_CONFIG           += -DSLBT_PREFERRED_HOST_NM=0
CFLAGS_CONFIG           += -DSLBT_PREFERRED_HOST_RANLIB=0

# # m4,aux
M4_DIR                   = /usr/local/share/slibtool
