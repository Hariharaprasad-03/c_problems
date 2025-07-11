#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int rows = 5;
    int columns = 20;
    
    char **dynamic_arr = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
    {
        dynamic_arr[i] = malloc(sizeof(char) * 20);
    }
    printf("give inputs\n");
    for (int i = 0; i < 5; i++)
    {

        scanf("%s", dynamic_arr[i]);
    }
    char s[10] = "mani";
    strcpy(dynamic_arr[4], s);

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", dynamic_arr[i]);
    }
    return 0;
}