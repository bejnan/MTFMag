AM_CXXFLAGS = -std=c++11 -Wall -Wextra

LDADD = $(top_builddir)/src/elements/libelement.a \
		$(top_builddir)/src/exceptions/libexception.a \
		$(top_builddir)/src/algorithms/libalgorithms.a \
		$(top_builddir)/src/tools/libtools.a

noinst_LIBRARIES = libcontroller.a
noinst_HEADERS = configuration/configuration.h configurations.h

libcontroller_a_SOURCES = configuration/configuration.cpp