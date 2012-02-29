# src level Makefile.am

# install to /usr/local/bin by default
bin_PROGRAMS = ctest

ctest_SOURCES = MainApp.cpp LogFrame.cpp LogInputPanel.cpp \
	ContestDefinition.cpp NewContestDialog.cpp

ctest_LDADD = @LIBS@
ctest_CXXFLAGS = @CXXFLAGS@

# Set headers include path for VPATH builds
# Set default installation path for contest definitions used in LogFrame::OnNew()
ctest_CPPFLAGS = -I\$(top_srcdir)/include -DDEFS_DIR=\"$(pkgdatadir)/defs\"
