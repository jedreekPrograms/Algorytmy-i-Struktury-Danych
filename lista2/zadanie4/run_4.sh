#!/bin/bash

set -e
cd "$(dirname "$0")"

echo "=== KOMPILACJA ==="

gcc generator_matrix.c -o generator.exe

gcc staircase_main.c staircasesearch.c binarysearch.c -o staircase.exe
gcc binarysearch_main.c binarysearch.c -o binary.exe
gcc hybrid_main.c hybridsearch.c staircasesearch.c binarysearch.c -o hybrid.exe

echo "=== CZYSZCZENIE ==="
rm -f *.txt

echo "=== TESTY MAŁE ==="

for i in {10..100..10}
do
  for k in {1..20}
  do
    data=$(./generator.exe $i $i $RANDOM)
    echo "$data" | ./staircase.exe >> staircase_small.txt
    echo "$data" | ./binary.exe >> binary_small.txt
    echo "$data" | ./hybrid.exe >> hybrid_small.txt

    data=$(./generator.exe 10 $i $RANDOM)
    echo "$data" | ./staircase.exe >> staircase_small.txt
    echo "$data" | ./binary.exe >> binary_small.txt
    echo "$data" | ./hybrid.exe >> hybrid_small.txt

    data=$(./generator.exe $i 10 $RANDOM)
    echo "$data" | ./staircase.exe >> staircase_small.txt
    echo "$data" | ./binary.exe >> binary_small.txt
    echo "$data" | ./hybrid.exe >> hybrid_small.txt
  done
done

echo "=== TESTY DUŻE ==="

for i in {100..2000..100}
do
  for k in {1..10}
  do
    data=$(./generator.exe $i $i $RANDOM)
    echo "$data" | ./staircase.exe >> staircase_big.txt
    echo "$data" | ./binary.exe >> binary_big.txt
    echo "$data" | ./hybrid.exe >> hybrid_big.txt

    data=$(./generator.exe 50 $i $RANDOM)
    echo "$data" | ./staircase.exe >> staircase_big.txt
    echo "$data" | ./binary.exe >> binary_big.txt
    echo "$data" | ./hybrid.exe >> hybrid_big.txt

    data=$(./generator.exe $i 50 $RANDOM)
    echo "$data" | ./staircase.exe >> staircase_big.txt
    echo "$data" | ./binary.exe >> binary_big.txt
    echo "$data" | ./hybrid.exe >> hybrid_big.txt
  done
done

echo "=== KONIEC ==="