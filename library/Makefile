include ../Make.defs

VERSION = $(SUSETEST_VERSION)
BUILD = $(SHLIB) test-logging test-junit
INSTALL = install-shlib install-headers

CFLAGS	= $(CCOPT) -D_GNU_SOURCE -I../minixml/library

SHLIB	= libsuselog.so
LIBOBJS	= suselog.o

STATICLIB = libsuselog.a
STATIC_LIBOBJS = $(addprefix static/,$(LIBOBJS))

LINK	= -L../library -lsuselog -L../minixml/library -lminixml -lncurses

ifeq ($(BUILD_STATIC),true)
  BUILD += $(STATICLIB)
  INSTALL += install-staticlib
endif

all: $(BUILD)

install: $(INSTALL)

install-shlib: $(SHLIB)
	install -d $(DESTDIR)/$(LIBDIR)
	install -m 555 $(SHLIB) $(DESTDIR)/$(LIBDIR)/$(SHLIB).$(VERSION)
	ln -sf $(SHLIB).$(VERSION) $(DESTDIR)/$(LIBDIR)/$(SHLIB)

install-headers:
	install -d $(DESTDIR)/usr/include
	install -m 444 suselog.h $(DESTDIR)/usr/include

install-staticlib: $(STATICLIB)
	install -d $(DESTDIR)/$(LIBDIR)
	install -m 644 $(STATICLIB) $(DESTDIR)/$(LIBDIR)/$(STATICLIB)

clean distclean::
	rm -f $(BUILD) *.o
	rm -f test-report.xml

$(SHLIB): $(LIBOBJS)
	$(CC) $(CFLAGS) -o $@ -shared -Wl,-soname,$@.$(VERSION) $(LIBOBJS) -lncurses -L../minixml/library -lminixml

$(STATICLIB): $(STATIC_LIBOBJS)
	$(AR) crv $@ $(STATIC_LIBOBJS)

suselog.o: suselog.c suselog.h suselog_p.h
	$(CC) -fPIC $(CFLAGS) -c -o $@ suselog.c

static/%.o: %.c
	@mkdir -p static
	$(CC) $(CFLAGS) -c -o $@ $<

test-logging: test-logging.o $(SHLIB)
	$(CC) -o $@ test-logging.o $(LINK)

testit.o: testit.c suselog.h
	$(CC) $(CFLAGS) -c -o $@ testit.c 

test-junit: test-junit.o $(SHLIB)
	$(CC) -o $@ test-junit.o $(LINK)

test-junit-static: test-junit.o $(STATICLIB)
	$(CC) -static -o $@ test-junit.o $(LINK)

test-junit.o: test-junit.c suselog.h
	$(CC) $(CFLAGS) -c -o $@ test-junit.c 
