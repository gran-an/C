all: s21_grep

s21_test: grep_test.sh
	sh grep_test.sh

s21_grep: grep.o grep_full.o com.o
	gcc -Wall -Werror -Wextra -std=c11 grep_full.o grep.o com.o -o s21_grep
	rm -rf *.o ../common/*.o

grep_full.o: grep_full.c grep.o com.o
	gcc -Wall -Werror -Wextra -c grep_full.c

grep.o: grep.c grep.h com.o
	gcc -Wall -Werror -Wextra -c grep.c

com.o: ../common/com.c ../common/com.h
	gcc -Wall -Werror -Wextra -c ../common/com.c

clean: 
	rm -rf *.o ../common/*.o s21_grep

format:
	clang-format -i *.c *.h ../common/*.c *.h

rebuild: clean all