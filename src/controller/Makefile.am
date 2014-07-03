AM_CXXFLAGS = -std=c++11 -Wall -Wextra

LDADD = $(top_srcdir)/src/elements/libelement.a \
		$(top_srcdir)/src/exceptions/libexception.a \
		$(top_srcdir)/src/algorithms/libalgorithms.a \
		$(top_srcdir)/src/tools/libtools.a

noinst_LIBRARIES = libcontroller.a
#noinst_HEADERS = $(top_srcdir)/headers/controller.h

libcontroller_a_SOURCES = configuration/configuration.cpp