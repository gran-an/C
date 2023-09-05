CC = gcc
CFLAGC =  -Wall -Werror -Wextra -std=c11
STATIC = ar rcs
TESTFLAGC = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
SOURCES_ALL:=$(wildcard *.c test/*.c)
SOURCES_FUN:=$(shell find . -not -name "s21_matrix_test.c" -name "*.c")
UNAME:=$(shell uname -s)

SOURCES_MATRIX_TESTS_C=test/s21_matrix_test.c test/test_*.c
SOURCES_MATRIX_TESTS_O=s21_matrix_test.o test_*.o

ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck
	OPEN_CM=open
endif

all: clean test s21_matrix.a gcov_report 

test.o: test.c s21_matrix.h
	$(CC) $(CFLAGC) -c test.c

s21_matrix.o: s21_matrix.c s21_matrix.h
	$(CC) $(CFLAGC) -c s21_matrix.c

s21_matrix_test: test/s21_matrix_test.c
	$(CC) $(CFLAGC) -c test/s21_matrix_test.c -o s21_matrix_test.o

test: s21_matrix.a $(SOURCES_MATRIX_TESTS_C) test/s21_matrix_test.h $(SOURCES_MATRIX_LIBRARY_C) s21_matrix.h
	$(CC) $(COVERAGE) -c *.c test/*.c -g
	$(STATIC) s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a	
	$(CC) $(COVERAGE) -o s21_matrix $(SOURCES_MATRIX_TESTS_O) s21_matrix.a $(LDFLAGS) -lm
	rm -rf *.o
	./s21_matrix; sleep 1

s21_matrix.a: s21_matrix.o
	$(STATIC) s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a	

gcov_report: test
	$(CC) $(GCOVFLAGS) $(SOURCES_ALL) $(LDFLAGS) -o report.out
	./report.out
	gcov -f $(SOURCES_FUN)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	$(OPEN_CM) ./report/index-sort-f.html

clang-format:
	clang-format -i *.c *.h 
	
clean:
	rm -rf *.o s21_matrix *.a s21_test *.out *.gcd *.gcno *.gcov *.gcda *.info ./report

for_me: s21_matrix.c s21_matrix.h
	$(CC) -g s21_matrix.c -o s21_matrix
