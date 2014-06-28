ACLOCAL_AMFLAGS = -I m4
bin_PROGRAMS = mtfmag
mtfmag_SUBDIRS = algorithms controller data_managment elements exceptions tools utils
mtfmag_CPPFLAGS = -std=c++11 -Wall -Wextra
mtfmag_LDADD = $(top_srcdir)/tools/libtools.a \
			 $(top_srcdir)/data_managment/libdatamanagment.a \
			 $(top_srcdir)/controller/libconfiguration.a
mtfmag_DEPENDENCIES = @LIBOBJS@
mtfmag_SOURCES = main.cpp