AM_CXXFLAGS = -std=c++11 -Wall -Wextra

SUBDIRS = judges

noinst_LIBRARIES = libtools.a
#noinst_HEADERS = $(top_srcdir)/src/headers/tools.h

libtools_a_LIBADD = $(top_srcdir)/src/elements/libelement.a $(top_srcdir)/src/algorithms/libalgorithms.a  judges/libjudge.a

libtools_a_SOURCES = processor_factory.h processor_factory.cpp processor.h processor.cpp 