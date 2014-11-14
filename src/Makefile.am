ACLOCAL_AMFLAGS = -I m4
bin_PROGRAMS = mtfmag mtfmagtest
SUBDIRS = headers elements utils results events exceptions algorithms controller tools data_managment
mtfmag_CPPFLAGS = -std=c++11 -Wall -Wextra
mtfmag_LDADD = \
$(top_builddir)/src/data_managment/libdatamanagment.a \
$(top_builddir)/src/data_managment/data_output/libdataoutput.a \
$(top_builddir)/src/data_managment/data_provider/libdataprovider.a \
$(top_builddir)/src/tools/judges/libjudge.a \
$(top_builddir)/src/tools/libtools.a \
$(top_builddir)/src/controller/libcontroller.a \
$(top_builddir)/src/algorithms/libalgorithms.a \
$(top_builddir)/src/algorithms/move_to_front/libmovetofront.a \
$(top_builddir)/src/algorithms/tree/libtree.a \
$(top_builddir)/src/algorithms/matrix/libmatrix.a \
$(top_builddir)/src/exceptions/libexception.a \
$(top_builddir)/src/events/libevents.a \
$(top_builddir)/src/results/libresult.a \
$(top_builddir)/src/utils/libutils.a \
$(top_builddir)/src/elements/libelement.a 

mtfmagtest_CPPFLAGS = -std=c++11 -Wall -Wextra -DBOOST_TEST_DYN_LINK -lboost_unit_test_framework
mtfmagtest_LDADD = \
$(top_builddir)/src/data_managment/libdatamanagment.a \
$(top_builddir)/src/data_managment/data_output/libdataoutput.a \
$(top_builddir)/src/data_managment/data_provider/libdataprovider.a \
$(top_builddir)/src/tools/judges/libjudge.a \
$(top_builddir)/src/tools/libtools.a \
$(top_builddir)/src/controller/libcontroller.a \
$(top_builddir)/src/algorithms/libalgorithms.a \
$(top_builddir)/src/algorithms/move_to_front/libmovetofront.a \
$(top_builddir)/src/algorithms/tree/libtree.a \
$(top_builddir)/src/algorithms/matrix/libmatrix.a \
$(top_builddir)/src/exceptions/libexception.a \
$(top_builddir)/src/events/libevents.a \
$(top_builddir)/src/results/libresult.a \
$(top_builddir)/src/utils/libutils.a \
$(top_builddir)/src/elements/libelement.a

mtfmagtest_LDFLAGS = -lboost_unit_test_framework
			 
			 
#mtfmag_DEPENDENCIES = @LIBOBJS@
mtfmag_SOURCES = main.cpp
mtfmagtest_SOURCES = main_test.cpp \
 test/data_collector_test.cpp \
 test/database_test.cpp \
 test/element_test.cpp \
 test/file_data_provider_test.cpp \
 test/judge_collector_test.cpp \
 test/move_to_front_test.cpp \
 test/mtf_matrix_test.cpp \
 test/proccessor_test.cpp \
 test/tester_test.cpp \
 test/tree_root_test.cpp \
 test/utils_test.cpp \
 test/event_notifier_test.cpp