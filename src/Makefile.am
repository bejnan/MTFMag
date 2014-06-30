ACLOCAL_AMFLAGS = -I m4
bin_PROGRAMS = mtfmag
SUBDIRS = headers elements exceptions algorithms utils controller tools data_managment
mtfmag_CPPFLAGS = -std=c++11 -Wall -Wextra
mtfmag_LDADD = $(top_srcdir)/src/algorithms/libalgorithms.a \
			 $(top_srcdir)/src/algorithms/matrix/libmatrix.a \
			 $(top_srcdir)/src/algorithms/tree/libtree.a \
			 $(top_srcdir)/src/algorithms/move_to_front/libmovetofront.a \
			 $(top_srcdir)/src/controller/libconfiguration.a \
			 $(top_srcdir)/src/data_managment/libdatamanagment.a \
			 $(top_srcdir)/src/data_managment/result/libresult.a \
			 $(top_srcdir)/src/data_managment/data_output/libdataoutput.a \
			 $(top_srcdir)/src/data_managment/data_provider/libdataprovider.a \
			 $(top_srcdir)/src/elements/libelement.a \
			 $(top_srcdir)/src/exceptions/libexception.a \
			 $(top_srcdir)/src/tools/libtools.a \
			 $(top_srcdir)/src/tools/judges/libjudge.a \
			 $(top_srcdir)/src/utils/libutils.a
			 
mtfmag_DEPENDENCIES = @LIBOBJS@
mtfmag_SOURCES = main.cpp