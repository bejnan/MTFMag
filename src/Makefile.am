bin_PROGRAMS = mtfmag
mtfmag_SUBDIRS = algorithms controller data_managment elements exceptions tools utils
mtfmag_CPPFLAGS = -std=c++11 -Wall -Wextra
mtfmag_LDADD = $(top_srcdir)/src/tools/libtools.a \
			 $(top_srcdir)/src/data_managment/libdatamanagment.a \
			 $(top_srcdir)/src/controller/libconfiguration.a
mtfmag_SOURCES = main.cpp