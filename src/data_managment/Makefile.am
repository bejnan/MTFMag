AM_CXXFLAGS = -std=c++11 -Wall -Wextra

LDADD = ../elements/libelement.a \
		../algorithms/libalgorithms.a \
		../controller/libcontroller.a \
		../exceptions/libexception.a \
		../tools/libtools.a \
		../utils/libutils.a \
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