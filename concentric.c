#include <stdio.h>
#include <stdlib.h>  // for abs()

int main() {
    int n = 4;
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            
            int min = i < j ? i : j;
            if (min > size - 1 - i) min = size - 1 - i;
            if (min > size - 1 - j) min = size - 1 - j;

            printf("%d ", n - min);
        }
        printf("\n");
    }
    getch();
    

    return 0;
}
