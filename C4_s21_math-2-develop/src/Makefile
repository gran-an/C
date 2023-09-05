CC = gcc
CFLAGC =  -Wall -Werror -Wextra -std=c11
STATIC = ar rcs
TESTFLAGC = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
SOURCES_ALL:=$(wildcard *.c)
SOURCES_FUN:=$(shell find . -not -name "s21_math_test.c" -name "*.c")
UNAME:=$(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck
	OPEN_CM=open
endif

all: clean test s21_math.a gcov_report 

s21_math.o: s21_math.c s21_math.h
	$(CC) $(CFLAGC) -c s21_math.c

s21_math_test: s21_math_test.c
	$(CC) $(CFLAGC) -c s21_math_test.c -o s21_math_test.o

test: s21_math_test s21_math.a
	$(CC) s21_math_test.o s21_math.a $(LDFLAGS) -o s21_test
	./s21_test

s21_math.a: s21_math.o
	$(STATIC) s21_math.a s21_math.o
	ranlib s21_math.a	

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
	rm -rf *.o s21_math *.a s21_test *.out *.gcd *.gcno *.gcov *.gcda *.info ./report

