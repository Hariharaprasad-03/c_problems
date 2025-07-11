#include <stdio.h>
#include <stdlib.h>  

int main() {
    int n = 5; 
    int totalRows = 2 * n - 1;

    for (int i = 0; i < totalRows; i++)
     {
        int row = i < n ? i : 2 * n - 2 - i; 

        int spaces = n - row - 1;
        
        int stars = 2 * row + 1;

        for (int j = 0; j < spaces + stars; j++) {
            if (j < spaces)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }

    return 0;
}
