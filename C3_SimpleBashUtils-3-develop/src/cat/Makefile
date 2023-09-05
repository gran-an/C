all: s21_cat

s21_test: cat_test.sh
	sh cat_test.sh

s21_cat: cat.o cat_full.o com.o
	gcc -Wall -Werror -Wextra -std=c11 cat_full.o cat.o com.o -o s21_cat
	rm -rf *.o 

cat_full.o: cat_full.c cat.o com.o 
	gcc -Wall -Werror -Wextra -c cat_full.c

cat.o: cat.c cat.h
	gcc -Wall -Werror -Wextra -c cat.c

com.o: ../common/com.c ../common/com.h
	gcc -Wall -Werror -Wextra -c ../common/com.c

clean: 
	rm -rf *.o ../common/*.o s21_cat

format:
	clang-format -i *.c *.h ../common/*.c *.h

rebuild: clean all