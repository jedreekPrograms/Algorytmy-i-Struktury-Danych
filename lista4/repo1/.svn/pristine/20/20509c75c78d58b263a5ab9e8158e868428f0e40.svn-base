#!/bin/bash

echo "=== KOMPILOWANIE ==="

g++ ../helpfunctions/helpfunctions.cpp ../zadanie1/RandomizedSelect.cpp ../zadanie1/RandomizedSelect_main.cpp -o randomized
g++ ../helpfunctions/helpfunctions.cpp ../zadanie1/Select.cpp ../zadanie1/Select_main.cpp -o select
g++ ../generators/generator_random.cpp -o generator

echo "=== CZYSZCZENIE ==="

rm -f random_k1.txt random_kmid.txt random_kn.txt
rm -f select_k1.txt select_kmid.txt select_kn.txt

echo "=== TESTY ==="

m=50

for n in $(seq 100 100 50000)
do
  echo "n=$n"

  for ((i=0;i<m;i++))
  do
    k1=1
    kmid=$((n/2))
    kn=$n

    # k = 1
    data=$(./generator $n $i $k1)
    echo "$data" | ./randomized >> random_k1.txt
    echo "$data" | ./select >> select_k1.txt

    # k = n/2
    data=$(./generator $n $i $kmid)
    echo "$data" | ./randomized >> random_kmid.txt
    echo "$data" | ./select >> select_kmid.txt

    # k = n
    data=$(./generator $n $i $kn)
    echo "$data" | ./randomized >> random_kn.txt
    echo "$data" | ./select >> select_kn.txt
  done
done

echo "=== DONE ==="
