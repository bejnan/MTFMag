AM_CXXFLAGS = -std=c++11 -Wall -Wextra

SUBDIRS = data_output data_provider result
noinst_LIBRARIES = libdatamanagment.a
#noinst_HEADERS = $(top_srcdir)/headers/data_managment.h

libdatamanagment_a_LIBADD = \
		$(top_srcdir)/src/algorithms/libalgorithms.a \
		$(top_srcdir)/src/controller/libcontroller.a \
		$(top_srcdir)/src/elements/libelement.a \
		$(top_srcdir)/src/exceptions/libexception.a \
		$(top_srcdir)/src/tools/libtools.a \
		$(top_srcdir)/src/utils/libutils.a \
		 data_output/libdataoutput.a \
		 data_provider/libdataprovider.a \
		 result/libresult.a
		

libdatamanagment_a_SOURCES = database.h database.cpp \
							 results_collectors/data_collector.h \
							 results_collectors/data_collector.cpp \
							 results_collectors/judge_collector.h \
							 results_collectors/judge_collector.cpp \
							 results_collectors/result_collector.h \
							 results_collectors/result_collector.cpp \
							 results_collectors/result_collector_builder.h \
							 results_collectors/result_collector_builder.cpp