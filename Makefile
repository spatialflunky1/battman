#
# Global Settings
#

INSTALL = install
DESTDIR ?= /
PREFIX ?= $(DESTDIR)/usr

PATH_BATTMAN = $(PREFIX)/bin/battman

#
# Targets
#

all:
	g++ main.cpp -o battman

install:
	$(INSTALL) -m0755 -D battman $(PATH_BATTMAN)

uninstall:
	rm -rf $(PATH_BATTMAN)

clean:
	rm -rf battman
