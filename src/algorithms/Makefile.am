AM_CXXFLAGS = -std=c++11 -Wall -Wextra

SUBDIRS = tree move_to_front matrix

LDADD = ../elements/libelement.a matrix/libmatrix.a move_to_front/libmovetofront.a tree/libtree.a

noinst_LIBRARIES = libalgorithms.a
#noinst_HEADERS = $(top_srcdir)/headers/algorithms.h

libalgorithms_a_SOURCES = algorithm.h algorithm_tools.h