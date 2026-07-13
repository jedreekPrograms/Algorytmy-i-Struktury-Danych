#!/bin/bash

echo "=== KOMPILACJA ==="

gcc ../generators/generator_asc.c -o gen_asc
gcc ../generators/generator_desc.c -o gen_desc
gcc ../generators/generator_random.c -o gen_rand

gcc ../helpfunctions/helpfunctions.c insertionsort.c main_insertionsort.c -o insertion
gcc ../helpfunctions/helpfunctions.c quicksort.c main_quicksort.c -o quick
gcc ../helpfunctions/helpfunctions.c hybridsort.c insertionsort.c quicksort.c hybrid_main.c -o hybrid

echo "=== TESTY ==="

for n in 8 32
do
    echo ""
    echo "#############################"
    echo "########## n = $n ###########"
    echo "#############################"

    echo ""
    echo "--- ROSNACY ---"
    ./gen_asc $n | ./insertion
    ./gen_asc $n | ./quick
    ./gen_asc $n | ./hybrid

    echo ""
    echo "--- MALEJACY ---"
    ./gen_desc $n | ./insertion
    ./gen_desc $n | ./quick
    ./gen_desc $n | ./hybrid

    echo ""
    echo "--- LOSOWY ---"
    ./gen_rand $n 42 | ./insertion
    ./gen_rand $n 42 | ./quick
    ./gen_rand $n 42 | ./hybrid
done

echo ""
echo "=== KONIEC ==="