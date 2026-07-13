#!/bin/bash

echo "=== KOMPILOWANIE ==="

g++ ../helpfunctions/helpfunctions.cpp RandomizedSelect.cpp RandomizedSelect_main.cpp -o randomized
g++ ../helpfunctions/helpfunctions.cpp Select.cpp Select_main.cpp -o select

g++ ../generators/generator_random.cpp -o generator

echo "=== TESTY ==="

for n in 8 32
do
  k=$((RANDOM % n + 1))   # 🔥 KLUCZOWE

  data=$(./generator $n 42 $k)

  echo "INPUT:"
  echo "$data"

  echo "$data" | ./randomized >> wynik_random.txt
  echo "$data" | ./select >> wynik_select.txt
done