#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 4) return 1;

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int seed = atoi(argv[3]);

    srand(seed);

    printf("%d %d\n", m, n);

    int tab[m][n];

    int base = rand() % 10;

    for (int i = 0; i < m; i++) {
        int current = base + i * 10; // większy odstęp → stabilniejsze kolumny

        for (int j = 0; j < n; j++) {
            current += rand() % 5 + 1;
            tab[i][j] = current;
            printf("%d ", current);
        }
        printf("\n");
    }

    int x;
    int mode = rand() % 3;

    if (mode == 0) {
        // BEST CASE
        x = tab[0][0];
    }
    else if (mode == 1) {
        // WORST CASE
        x = tab[m - 1][n - 1];
    }
    else {
        // LOSOWY (często nie istnieje)
        x = base + rand() % (m * n * 2);
    }

    printf("%d\n", x);

    return 0;
}