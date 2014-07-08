ACLOCAL_AMFLAGS = -I m4
bin_PROGRAMS = mtfmag
SUBDIRS = headers elements exceptions algorithms utils controller tools data_managment
mtfmag_CPPFLAGS = -std=c++11 -Wall -Wextra
mtfmag_LDADD = \
$(top_builddir)/src/data_managment/libdatamanagment.a \
$(top_builddir)/src/data_managment/result/libresult.a \
$(top_builddir)/src/data_managment/data_output/libdataoutput.a \
$(top_builddir)/src/data_managment/data_provider/libdataprovider.a \
$(top_builddir)/src/tools/judges/libjudge.a \
$(top_builddir)/src/tools/libtools.a \
$(top_builddir)/src/controller/libcontroller.a \
$(top_builddir)/src/utils/libutils.a \
$(top_builddir)/src/algorithms/libalgorithms.a \
$(top_builddir)/src/algorithms/move_to_front/libmovetofront.a \
$(top_builddir)/src/algorithms/tree/libtree.a \
$(top_builddir)/src/algorithms/matrix/libmatrix.a \
$(top_builddir)/src/exceptions/libexception.a \
$(top_builddir)/src/elements/libelement.a 
			 
			 
#mtfmag_DEPENDENCIES = @LIBOBJS@
mtfmag_SOURCES = main.cpp