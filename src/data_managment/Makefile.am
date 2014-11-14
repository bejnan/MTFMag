AM_CXXFLAGS = -std=c++11 -Wall -Wextra

SUBDIRS = data_output data_provider
noinst_LIBRARIES = libdatamanagment.a
noinst_HEADERS = \
	results_collectors/data_collector.h \
	results_collectors/judge_collector.h \
	results_collectors/result_collector.h \
	data_outputs.h \
	data_providers.h \
	results_collectors.h \
	database.h
	

libdatamanagment_a_LIBADD = \
		$(top_builddir)/src/algorithms/libalgorithms.a \
		$(top_builddir)/src/controller/libcontroller.a \
		$(top_builddir)/src/elements/libelement.a \
		$(top_builddir)/src/exceptions/libexception.a \
		$(top_builddir)/src/tools/libtools.a \
		$(top_builddir)/src/utils/libutils.a \
		$(top_builddir)/src/results/libresult.a \
		 data_output/libdataoutput.a \
		 data_provider/libdataprovider.a
		

libdatamanagment_a_SOURCES = database.cpp \
							 results_collectors/data_collector.cpp \
							 results_collectors/judge_collector.cpp \
							 results_collectors/result_collector.cpp
