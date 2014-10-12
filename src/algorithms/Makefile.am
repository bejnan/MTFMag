AM_CXXFLAGS = -std=c++11 -Wall -Wextra

SUBDIRS = tree move_to_front matrix

LDADD = $(top_builddir)/src/elements/libelement.a matrix/libmatrix.a move_to_front/libmovetofront.a tree/libtree.a

noinst_HEADERS = algorithm.h algorithm_container.h matrix_algorithms.h move_to_front_algorithms.h tree_algorithms.h
noinst_LIBRARIES = libalgorithms.a


libalgorithms_a_SOURCES = algorithm_container.cpp