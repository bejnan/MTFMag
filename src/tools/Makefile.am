AM_CXXFLAGS = -std=c++11 -Wall -Wextra

SUBDIRS = judges

noinst_LIBRARIES = libtools.a
noinst_HEADERS = processor_factory.h processor.h judges.h

libtools_a_LIBADD = $(top_builddir)/src/elements/libelement.a $(top_builddir)/src/algorithms/libalgorithms.a  judges/libjudge.a

libtools_a_SOURCES = processor_factory.cpp processor.cpp 