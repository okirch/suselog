include ../Make.defs

SUBDIRS	= library

all install clean distclean::
	set -e; for dir in $(SUBDIRS); do make -C $$dir $@; done
