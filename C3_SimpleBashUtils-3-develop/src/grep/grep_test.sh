#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
FINAL_SUCCESS=0
FINAL_FAIL=0
DIFF_RES=""
TEST_FILE1="text.txt"
TEST_FILE2="grep.txt"
TEST_FILE3="test.txt"
TEST_FILE4="grep_text.txt"
TEST_FILE5="eng.txt"
echo "" > log.txt
echo "TEST 1: -e -i -v -c -n -s -o (all alphabet) $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5"
for var in -e -i -v -c -n -s -o 
do
for letters in A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z
do
for file in $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5
do 
          TEST1="$var $letters $file"
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep_test.txt
          DIFF_RES="$(diff -s s21_grep.txt grep_test.txt)"
          if [ $? == 0 ]
            then
              (( COUNTER_SUCCESS++ ))
              (( FINAL_SUCCESS++ ))
            else
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
              (( FINAL_FAIL++ ))
          fi
          rm s21_grep.txt grep_test.txt
done
done
done
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
COUNTER_SUCCESS=0
COUNTER_FAIL=0

echo "TEST 2: -l -h (all alphabet) $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5" 
for var in -l -h
do
for letters in A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z
do
for file in $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5
do 
          TEST2="$var $letters $file"
          ./s21_grep $TEST2 > s21_grep.txt
          grep $TEST2 > grep_test.txt
          DIFF_RES="$(diff -s s21_grep.txt grep_test.txt)"
          if [ $? == 0 ]
            then
              (( COUNTER_SUCCESS++ ))
              (( FINAL_SUCCESS++ ))
            else
              echo "$TEST2" >> log.txt
              (( COUNTER_FAIL++ ))
              (( FINAL_FAIL++ ))
          fi
          rm s21_grep.txt grep_test.txt
done
done
done
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
COUNTER_SUCCESS=0
COUNTER_FAIL=0

echo "TEST 3: -f $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5" 
for var in $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5
do
for var2 in $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5
do
          TEST16="-f $var $var2"
          ./s21_grep $TEST16 > s21_grep.txt
          grep $TEST16 > grep_test.txt
          DIFF_RES="$(diff -s s21_grep.txt grep_test.txt)"
          if [ $? == 0 ]
            then
              (( COUNTER_SUCCESS++ ))
              (( FINAL_SUCCESS++ ))
            else
              echo "$TEST16" >> log.txt
              (( COUNTER_FAIL++ ))
              (( FINAL_FAIL++ ))
          fi
          rm s21_grep.txt grep_test.txt
done
done
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
COUNTER_SUCCESS=0
COUNTER_FAIL=0



echo "TEST 4: (no flag) (all alphabet) $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5"
for var in $TEST_FILE1 $TEST_FILE2 $TEST_FILE3 $TEST_FILE4 $TEST_FILE5
do
for letters in A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z
do
          TEST6="$letters $var"
          ./s21_grep $TEST6 > s21_grep.txt
          grep $TEST6 > grep_test.txt
          DIFF_RES="$(diff -s s21_grep.txt grep_test.txt)"
          if [ $? == 0 ]
            then
              (( COUNTER_SUCCESS++ ))
              (( FINAL_SUCCESS++ ))
            else
              echo "$TEST6" >> log.txt
              (( COUNTER_FAIL++ ))
              (( FINAL_FAIL++ ))
          fi
          rm s21_grep.txt grep_test.txt
done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"

echo "FINAL SUCCESS: $FINAL_SUCCESS"
echo "FINAL FAIL: $FINAL_FAIL"