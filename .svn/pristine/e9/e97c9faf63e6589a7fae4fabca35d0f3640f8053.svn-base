#!/bin/bash

echo "=== KOMPILACJA ==="

gcc ../helpfunctions/helpfunctions.c ../zadanie1a/insertionsort.c ../zadanie1a/main_insertionsort.c -o insertion.exe
gcc ../helpfunctions/helpfunctions.c ../zadanie1a/quicksort.c ../zadanie1a/main_quicksort.c -o quick.exe
gcc ../helpfunctions/helpfunctions.c ../zadanie1a/hybridsort.c ../zadanie1a/insertionsort.c ../zadanie1a/quicksort.c ../zadanie1a/hybrid_main.c -o hybrid.exe

echo "=== KOMPILACJA GENERATORA ==="
gcc ../generators/generator_random.c -o gen_rand.exe

echo "=== CZYSZCZENIE ==="
rm -f *.txt

echo "=== TESTY MAŁE ==="

for i in {10..50..10}
do
  for k in {1..10}
  do
    ./gen_rand.exe $i $RANDOM | ./hybrid.exe >> hybrid_small.txt
    ./gen_rand.exe $i $RANDOM | ./insertion.exe >> insertion_small.txt
    ./gen_rand.exe $i $RANDOM | ./quick.exe >> quick_small.txt
  done
done

echo "=== TESTY DUŻE ==="

for i in {1000..50000..1000}
do
  for k in {1..10}
  do
    ./gen_rand.exe $i $RANDOM | ./hybrid.exe >> hybrid_big.txt
    ./gen_rand.exe $i $RANDOM | ./quick.exe >> quick_big.txt
  done
done

echo "=== KONIEC ==="