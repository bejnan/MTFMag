AM_CXXFLAGS = -std=c++11 -Wall -Wextra

noinst_LIBRARIES = libtools.a
noinst_HEADERS = $(top_srcdir)/headers/tools.h

libtools_a_LIBADD = $(top_srcdir)/elements/libelement.a $(top_srcdir)/algorithms/libalgorithms.a judges/judge.a

libtools_a_SOURCES = processor_factory.h processor_factory.cpp processor.h processor.cpp 