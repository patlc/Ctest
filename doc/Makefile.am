# Documentation Makefile.am

internals = CTestInternals

internals_src = $(internals).txt

EXTRA_DIST = $(internals_src) $(internals).html $(internals).pdf

.PHONY: doc clean-local

doc: $(internals).html $(internals).pdf

clean-local:
	rm -f $(builddir)/$(internals).html $(builddir)/$(internals).pdf

$(internals).html: $(internals_src)
	asciidoc -b html -o $(builddir)/$(internals).html $(srcdir)/$(internals_src)

$(internals).pdf: $(internals_src)
	a2x -f pdf -D $(builddir) $(srcdir)/$(internals_src)
