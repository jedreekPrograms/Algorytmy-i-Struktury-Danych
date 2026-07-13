
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {

    if (argc != 3) {
        printf("Za mało argumentow");
        return 1;
    }

    int n = atoi(argv[1]);
    int seed = atoi(argv[2]);

    srand(seed);

    printf("%d\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", rand() % (2 * n));
    }

    printf("\n");

    return 0;
}
