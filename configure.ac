#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([CTest], [0.00~git], [n0nb@n0nb.us], [ctest], [http://www.n0nb.us/blog])

# Local preprocessor variable substitutions
AC_DEFINE([PACKAGE_COPYRIGHT_YEARS], ["2012"], [Copyright years])

AM_INIT_AUTOMAKE

dnl # AM_SILENT_RULES available on Automake 1.11 and later
AM_SILENT_RULES([yes])

AC_CONFIG_SRCDIR([src/MainApp.cpp])
AC_CONFIG_HEADERS([include/config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AM_OPTIONS_WXCONFIG
reqwx=2.8.12
AM_PATH_WXCONFIG($reqwx, wxWin=1)
if test "$wxWin" != 1; then
	AC_MSG_ERROR([
		wxWidgets must be installed on your system.

		Please check that wx-config is in path, the directory
		where wxWidgets libraries are installed (returned by
		'wx-config --libs' or 'wx-config --static --libs' command)
		is in LD_LIBRARY_PATH or equivalent variable and
		wxWidgets version is $reqwx or above.
		])
fi

CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
CFLAGS="$CFLAGS $WX_CFLAGS_ONLY"
LIBS="$LIBS $WX_LIBS"

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.

# Define then generate output files
AC_CONFIG_FILES([
Makefile
src/Makefile
defs/Makefile
include/Makefile
])

AC_OUTPUT
