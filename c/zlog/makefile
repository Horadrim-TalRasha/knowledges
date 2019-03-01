# Top level makefile, the real shit is at src/makefile

TARGETS=noopt 32bit

all:
	cd src && $(MAKE) $@
	cp src/libzlog.so ../libs

install:
	cd src && $(MAKE) $@

$(TARGETS):
	cd src && $(MAKE) $@

doc:
	cd doc && $(MAKE)

test:
	cd test && $(MAKE)

TAGS:
	find . -type f -name "*.[ch]" | xargs etags -

clean:
	cd src && $(MAKE) $@

distclean: clean

dummy:

.PHONY: doc install test TAGS
