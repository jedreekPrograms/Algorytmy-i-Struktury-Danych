#!/bin/bash

cd "$(dirname "$0")"

echo "=== KOMPILACJA ==="

gcc ../generators/generator_asc.c -o gen_asc.exe
gcc ../generators/generator_desc.c -o gen_desc.exe
gcc ../generators/generator_random.c -o gen_rand.exe

gcc merge_main.c mergesort.c ../helpfunctions/helpfunctions.c -o merge.exe
gcc mydivide_main.c mydivide.c mergesort.c ../helpfunctions/helpfunctions.c -o mydivide.exe

echo "=== CZYSZCZENIE ==="
rm -f *.txt

echo "=== TESTY MAŁE ==="

for i in {10..50..10}
do
  for k in {1..10}
  do
    data=$(./gen_rand.exe $i $RANDOM)
    echo "$data" | ./merge.exe >> merge_small.txt
    echo "$data" | ./mydivide.exe >> mydivide_small.txt

    data=$(./gen_asc.exe $i)
    echo "$data" | ./merge.exe >> merge_small.txt
    echo "$data" | ./mydivide.exe >> mydivide_small.txt

    data=$(./gen_desc.exe $i)
    echo "$data" | ./merge.exe >> merge_small.txt
    echo "$data" | ./mydivide.exe >> mydivide_small.txt
  done
done

echo "=== TESTY DUŻE ==="

for i in {1000..50000..1000}
do
  for k in {1..10}
  do
    data=$(./gen_rand.exe $i $RANDOM)
    echo "$data" | ./merge.exe >> merge_big.txt
    echo "$data" | ./mydivide.exe >> mydivide_big.txt
  done
done

echo "=== KONIEC ==="