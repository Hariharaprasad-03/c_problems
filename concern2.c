#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 4;
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int val = n - abs(n - 1 - i) < n - abs(n - 1 - j) ?
                      n - abs(n - 1 - i) : n - abs(n - 1 - j);
            printf("%d ", val);
        }
        printf("\n");
    }

    return 0;
}
