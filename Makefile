include Make.defs

SUBDIRS	= minixml library shell python

all install clean distclean::
	set -e; for dir in $(SUBDIRS); do make -C $$dir $@; done