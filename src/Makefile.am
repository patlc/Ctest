# src level Makefile.am

bin_PROGRAMS = ctest

ctest_SOURCES = MainApp.cpp LogFrame.cpp LogInputPanel.cpp \
	ContestDefinition.cpp

ctest_LDADD = @LIBS@
ctest_CXXFLAGS = @CXXFLAGS@

noinst_HEADERS = MainApp.hpp LogFrame.hpp LogInputPanel.hpp \
	ContestDefinition.hpp WindowID.hpp

AM_CPPFLAGS = -DDEFS_DIR=\"$(pkgdatadir)/defs\"
