include macros.mk

export CC
export inc bin
export stripping
export CFLAGS WFLAGS IFLAGS

.PHONY	: docs

all	: $(bin)
	$(MAKE) $(MFLAGS) $(panagram) -f panagram.mk
	$(MAKE) $(MFLAGS) $(calculator) -f calculator.mk
	@echo -e "\n### Successfully generated all binaries"

clean	:
	rm -rf $(bin) $(docs)
	$(MAKE) $(MFLAGS) $(panagram) -f panagram.mk clean
	$(MAKE) $(MFLAGS) $(calculator) -f calculator.mk clean

$(bin)	:
	@if [ -d "$(bin)" ] ; then true ; else mkdir $(bin) ; fi

docs	:
	@doxygen && xdg-open $(docs)/html/index.html
