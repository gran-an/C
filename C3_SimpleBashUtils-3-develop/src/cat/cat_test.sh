#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_FILE1="text.txt"
TEST_FILE2="cat.txt"
echo "" > log.txt
echo "TEST 1: $TEST_FILE1"
for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
do

          TEST1="$var $TEST_FILE1"
          ./s21_cat $TEST1 > s21_cat.txt
          cat $TEST1 > cat_test.txt
          DIFF_RES="$(diff -s s21_cat.txt cat_test.txt)"
          if [ $? == 0 ]
            then
              (( COUNTER_SUCCESS++ ))
              echo "$TEST1: SUCCESS"
            else
              echo "$TEST1" >> log.txt
              echo "$TEST1: FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_cat.txt cat_test.txt
done

echo "TEST 2: $TEST_FILE2" 
for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
do
          TEST2="$var $TEST_FILE2"
          ./s21_cat $TEST2 > s21_cat.txt
          cat $TEST2 > cat_test.txt
          DIFF_RES="$(diff -s s21_cat.txt cat_test.txt)"
          if [ $? == 0 ]
            then
            echo "$TEST2: SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST2: FAIL"
              echo "$TEST2" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_cat.txt cat_test.txt
done

echo "TEST 3: $TEST_FILE1 $TEST_FILE2" 
for var in $TEST_FILE1 $TEST_FILE2
do
          TEST3="$var"
          ./s21_cat $TEST3 > s21_cat.txt
          cat $TEST3 > cat_test.txt
          DIFF_RES="$(diff -s s21_cat.txt cat_test.txt)"
          if [ $? == 0 ]
            then
            echo "$TEST3: SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST3: FAIL"
              echo "$TEST3" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_cat.txt cat_test.txt
done

echo "TEST 4: $TEST_FILE1 ../grep/grep.c $TEST_FILE2" 
for var in $TEST_FILE1 ../grep/grep.c $TEST_FILE2
do
          TEST4="$var"
          ./s21_cat $TEST4 > s21_cat.txt
          cat $TEST4 > cat_test.txt
          DIFF_RES="$(diff -s s21_cat.txt cat_test.txt)"
          if [ $? == 0 ]
            then
            echo "$TEST4: SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST4: FAIL"
              echo "$TEST4" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_cat.txt cat_test.txt
done


echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
