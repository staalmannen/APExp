
include ../config.mk

APP  = unace$(EXE)

# find . -name '*.c' | sed 's%\.c%.o%'
OBJS = acefuncs.o \
	base/all.o \
	base/unused.o \
	base/arcblk.o \
	base/archives/ace.o \
	base/archives/read.o \
	base/archives/test.o \
	base/bitwidth.o \
	base/bufread.o \
	base/comments.o \
	base/convert.o \
	base/cprdcpr/cprdcpr.o \
	base/crc.o \
	base/crypt.o \
	base/dcpr/comments.o \
	base/dcpr/dcpr.o \
	base/dcpr/huff.o \
	base/dcpr/lz77.o \
	base/dcpr/pic.o \
	base/dcpr/sound.o \
	base/dosfuncs.o \
	base/error.o \
	base/errorout.o \
	base/extract.o \
	base/filelist.o \
	base/funcs.o \
	base/lfn.o \
	base/memory.o \
	base/msgout.o \
	base/options.o \
	base/pathfunc.o \
	base/qsort.o \
	base/state.o \
	base/uninorm/unincore.o \
	base/uninorm/uninorm.o \
	base/volume.o \
	commline.o \
	convert.o \
	input.o \
	main.o \
	messages/messages.o \
	output.o \
	state.o

# -D__EMULATE_UNALIGNED__
CFLAGS += -I. -I.. -I../lib

all: $(APP)

$(APP): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(APP) $(LDFLAGS) $(LIBS)

strip: $(APP)
	$(STRIP) $(APP)

distclean: clean

clean:
	rm -f *.o *~ $(APP)
	find . -name '*.o' -delete

install: all
	mkdir -p $(DESTDIR)$(bindir)
	install $(APP) $(DESTDIR)$(bindir)

install-strip: strip install

uninstall:
	rm -f $(DESTDIR)$(bindir)/$(APP)
