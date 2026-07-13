
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Za mało argumentow");
        return 1;
    }

    int n = atoi(argv[1]);
    printf("%d\n", n);

    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}
