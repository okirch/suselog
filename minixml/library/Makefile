include ../../Make.defs

VERSION = $(SUSETEST_VERSION)
BUILD	= $(SHLIB)
INSTALL = install-shlib install-headers

CFLAGS	= $(CCOPT) -D_GNU_SOURCE

SHLIB	= libminixml.so
LIBOBJS	= xml.o \
	  xml-reader.o \
	  xml-writer.o \
	  util.o

STATICLIB = libminixml.a
STATIC_LIBOBJS = $(addprefix static/,$(LIBOBJS))

ifeq ($(BUILD_STATIC),true)
  BUILD += $(STATICLIB)
  INSTALL += install-staticlib
endif

all: $(BUILD)

install: $(INSTALL)

install-shlib: $(SHLIB)
	install -d $(DESTDIR)/$(LIBDIR)
	install -m 555 $(SHLIB) $(DESTDIR)/$(LIBDIR)/$(SHLIB).$(VERSION)

install-headers: ;

install-staticlib: $(STATICLIB)
	install -d $(DESTDIR)/$(LIBDIR)
	install -m 644 $(STATICLIB) $(DESTDIR)/$(LIBDIR)/$(STATICLIB)

clean distclean::
	rm -f $(BUILD) *.o
	rm -rf static
	rm -f test-report.xml

$(SHLIB): $(LIBOBJS)
	$(CC) $(CFLAGS) -o $@ -shared -Wl,-soname,$@.$(VERSION) $(LIBOBJS)

$(STATICLIB): $(STATIC_LIBOBJS)
	$(AR) crv $@ $(STATIC_LIBOBJS)

%.o: %.c
	$(CC) -fPIC $(CFLAGS) -c -o $@ $<

static/%.o: %.c
	@mkdir -p static
	$(CC) $(CFLAGS) -c -o $@ $<
