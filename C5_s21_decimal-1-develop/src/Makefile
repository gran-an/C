CC = gcc -Wall -Werror -Wextra -std=c11
COVERAGE = -fprofile-arcs -ftest-coverage

UNAME:=$(shell uname -s)
SOURCES_DECIMAL_LIBRARY_C=s21_decimal.c s21_decimal_other.c
SOURCES_DECIMAL_LIBRARY_O=s21_decimal.o s21_decimal_other.o
SOURCES_DECIMAL_TESTS_C=s21_decimal_tests.c test_*.c
SOURCES_DECIMAL_TESTS_O=s21_decimal_tests.o test_*.o
OUTPUT=s21_decimal

ifeq ($(UNAME), Linux)
	CHECK_FLAGS:=$(shell pkg-config --cflags --libs check)
endif
ifeq ($(UNAME), Darwin)
	CHECK_FLAGS=-lcheck
endif

all: clean s21_decimal.a test gcov_report

gcov_report: test
	gcov s21_decimal_tests.gcda
	gcovr --html-details -o report.html
	rm -rf *.gcno *.gcov *.gcda

test: s21_decimal.a $(SOURCES_DECIMAL_TESTS_C) s21_decimal_tests.h $(SOURCES_DECIMAL_LIBRARY_C) s21_decimal.h
	$(CC) $(COVERAGE) -c *.c -g
	ar rcs s21_decimal.a $(SOURCES_DECIMAL_LIBRARY_O)
	ranlib s21_decimal.a
	$(CC) $(COVERAGE) -o $(OUTPUT) $(SOURCES_DECIMAL_TESTS_O) s21_decimal.a $(CHECK_FLAGS) -lm
	rm -rf *.o
	./$(OUTPUT); sleep 1

s21_decimal.a: $(SOURCES_DECIMAL_LIBRARY_C) s21_decimal.h
	$(CC) -c $(SOURCES_DECIMAL_LIBRARY_C)
	ar rcs s21_decimal.a $(SOURCES_DECIMAL_LIBRARY_O)
	ranlib s21_decimal.a
	rm -rf $(SOURCES_DECIMAL_LIBRARY_O)

your_hands: s21_decimal.c s21_decimal.h
	$(CC) -g -lm $(SOURCES_DECIMAL_LIBRARY_C) -o $(OUTPUT)

format:
	clang-format -i *.c *.h 

clean:
	rm -rf *.o *.a *.html *.css *.gcno *.gcov *.gcda
	rm -rf $(OUTPUT)

rebuild: clean all
