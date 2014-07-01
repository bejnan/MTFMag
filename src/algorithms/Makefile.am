AM_CXXFLAGS = -std=c++11 -Wall -Wextra

SUBDIRS = tree move_to_front matrix

LDADD = $(top_srcdir)/src/elements/libelement.a matrix/libmatrix.a move_to_front/libmovetofront.a tree/libtree.a

#noinst_HEADERS = $(top_srcdir)/headers/algorithms.h algorithm.h
noinst_LIBRARIES = libalgorithms.a


libalgorithms_a_SOURCES = algorithm_tools.cpp