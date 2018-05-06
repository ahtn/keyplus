
#######################################
# The list of libraries we are building separated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = lib@PACKAGE_NAME@-@PACKAGE_VERSION@.la

#######################################
# Build information for each library


library_include_aes_mindir=$(includedir)/@PACKAGE_NAME@-@PACKAGE_VERSION@
library_include_aes_min_HEADERS = aes.h
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_SOURCES = aes-encrypt.c aes-key-schedule.c aes-shift-rows.c aes-mix-columns.c
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_SOURCES += aes-otfks-encrypt.c aes-key-schedule-round.c
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_SOURCES += aes-decrypt.c aes-shift-rows-inv.c aes-mix-columns-inv.c
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_SOURCES += aes-otfks-decrypt.c
if ENABLE_SBOX_SMALL
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_SOURCES += aes-sbox-small.c aes-sbox-inv-small.c aes-mul.c aes-inv.c
else
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_SOURCES += aes-sbox.c aes-sbox-inv.c
endif
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_SOURCES += aes-sbox.h aes-shift-rows.h aes-mix-columns.h aes-mul.h aes-mul2.h aes-inv.h aes-rotate.h aes-add-round-key.h aes-key-schedule-round.h
lib@PACKAGE_NAME@_@PACKAGE_VERSION@_la_LDFLAGS = -version-info @LIB_SO_VERSION@

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = @PACKAGE_NAME@.pc


#######################################
# Tests

TESTS = aes-sbox-test aes-inv-test aes-key-schedule-test aes-encrypt-test aes-vectors-test

check_PROGRAMS = aes-sbox-test aes-inv-test aes-key-schedule-test aes-encrypt-test aes-vectors-test

aes_sbox_test_SOURCES = tests/aes-sbox-test.c  aes-print-block.h
aes_sbox_test_LDADD = lib@PACKAGE_NAME@-@PACKAGE_VERSION@.la

aes_inv_test_SOURCES = tests/aes-inv-test.c  aes-mul.c aes-inv.c aes-print-block.h
aes_inv_test_LDADD = lib@PACKAGE_NAME@-@PACKAGE_VERSION@.la
aes_inv_test_CFLAGS = $(AM_CFLAGS)

aes_key_schedule_test_SOURCES = tests/aes-key-schedule-test.c  aes-print-block.h
aes_key_schedule_test_LDADD = lib@PACKAGE_NAME@-@PACKAGE_VERSION@.la

aes_encrypt_test_SOURCES = tests/aes-encrypt-test.c aes-print-block.h
aes_encrypt_test_LDADD = lib@PACKAGE_NAME@-@PACKAGE_VERSION@.la

aes_vectors_test_SOURCES = tests/aes-vectors-test.c tests/aes-test-vectors.h aes-print-block.h
aes_vectors_test_LDADD = lib@PACKAGE_NAME@-@PACKAGE_VERSION@.la
