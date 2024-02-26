CC = gcc -std=c11
CFLAGC =  -Wall -Werror -Wextra 
STATIC = ar rcs
TESTFLAGC = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
SOURCES_ALL:=$(wildcard library/*.c)
SOURCES_FUN:=$(shell find . -not -name "library/s21_calc_test.c" -name "*.c")
UNAME:=$(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck
	OPEN_CM=open
endif

all: clean install

library/s21_smartcalc.a: library/s21_calc.o library/s21_stack.o
	$(STATIC) library/s21_smartcalc.a s21_calc.o s21_stack.o
	ranlib library/s21_smartcalc.a 

library/s21_stack.o: library/s21_stack.c library/headers/s21_stack.h
	$(CC) $(CFLAGC) -c library/s21_stack.c

library/s21_calc.o: library/s21_calc.c library/headers/s21_calc.h
	$(CC) $(CFLAGC) -c library/s21_calc.c

library/s21_calc_test: library/s21_calc_test.c
	$(CC) $(CFLAGC) -c library/s21_calc_test.c -o library/s21_calc_test.o

test: library/s21_calc_test library/s21_smartcalc.a
	$(CC) library/s21_calc_test.o library/s21_smartcalc.a $(LDFLAGS) -o s21_test
	./s21_test	

gcov_report: test
	$(CC) $(GCOVFLAGS) $(SOURCES_ALL) $(LDFLAGS) -o report.out
	./report.out
	gcov -f $(SOURCES_FUN)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	$(OPEN_CM) ./report/index-sort-f.html

dvi:
	 open dvi.md

install:
ifeq ($(UNAME),Linux)
	mkdir -p ../build
	mv Makefile cloneMake && qmake && make && make clean && rm Makefile && mv cloneMake Makefile
	cd Smart_Calc && qmake && make && make clean && rm -rf Makefile && mv Smart_Calc.app ../../build/Smart_Calc.app
	cp -R ../build/Smart_Calc.app ~/Desktop/Smart_Calc.app
endif
ifeq ($(UNAME),Darwin)
	cp Makefile copyMakefile
	$(HOME)/Qt/6.6.2/macos/bin/qmake $(PWD)/Smart_Calc/Smart_Calc.pro -spec macx-clang CONFIG+=debug CONFIG+=qml_debug
	make
	open Smart_Calc.app/Contents/MacOS/Smart_Calc
	rm -rf Makefile
	mv copyMakefile Makefile
endif

uninstall:
	rm -rf Smart_Calk.app

dist: install
	mkdir -p dist
	cp -R Smart_Calc.app dist
	cp ../README_RUS.md dist && cp ../README.md dist && cp dvi.md dist 
	cd dist && tar cvzf Smart_Calc_v1.0.tgz *
	cd dist && rm -rf Smart_Calc.app README.md README_RUS.md dvi.md 

clang-format:
	clang-format -n library/*.c library/headers/*.h 
	
clean:
	rm -rf *.o library/*.a library/*.o s21_test *.out *.gcd *.gcno *.gcov *.gcda *.info ./report build-Smart_Calc-Qt_6_6_2_for_macOS-Release Smart_Calc.app build-Smart_Calc-Desktop_arm_darwin_generic_mach_o_64bit-Debug *.cpp *.h Smart_Calc/*.o build-Smart_Calc-Qt_6_6_2_for_macOS-Debug
