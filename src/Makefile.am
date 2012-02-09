# src level Makefile.am

bin_PROGRAMS = ctest

ctest_SOURCES = MainApp.cpp LogFrame.cpp LogInputPanel.cpp \
	ContestDefinition.cpp

ctest_LDADD = @LIBS@
ctest_CXXFLAGS = @CXXFLAGS@

AM_CPPFLAGS = -DDEFS_DIR=\"$(pkgdatadir)/defs\"
