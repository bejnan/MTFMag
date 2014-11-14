AC_INIT([mtfmag], [1.0], [Jakub Banaszewski<jakub.banaszewski@gmail.com>])
AC_PROG_CXX
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_LN_S

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AM_PROG_AR

AC_PROG_RANLIB

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([no])])

AC_CONFIG_FILES([
 src/algorithms/matrix/Makefile
 src/algorithms/move_to_front/Makefile
 src/algorithms/tree/Makefile
 src/algorithms/Makefile
 src/controller/Makefile
 src/data_managment/data_output/Makefile
 src/data_managment/data_provider/Makefile
 src/data_managment/Makefile
 src/elements/Makefile
 src/events/Makefile
 src/exceptions/Makefile
 src/headers/Makefile
 src/tools/judges/Makefile
 src/tools/Makefile
 src/results/Makefile
 src/utils/Makefile
 src/test/Makefile
 src/Makefile
 Makefile
])

AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_OUTPUT