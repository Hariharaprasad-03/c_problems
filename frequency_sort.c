#include <stdio.h>
#include <stdlib.h>

#define size 128



typedef struct
{
    char chr;
    int freq;
} CHR;



void insertion_sort(CHR *map, int n)
{

    for (int i = 0; i < n; i++)
    {

        CHR key = map[i];
        int j = i - 1;
        while (j >= 0 && map[j].freq < key.freq)
        {
            map[j + 1] = map[j];
            j--;
        }
        map[j + 1] = key;
    }
}

char *freq_sort(char *s, int n)
{

    CHR *map = malloc(size * sizeof(CHR));

    for (int i = 0; i < size; i++)
    {
        map[i].chr = (unsigned char)i;
        map[i].freq = 0;
    }

    char *ptr = s;
    while (*ptr)
    {
        map[(unsigned char)*ptr].freq++;
        ptr++;
    }
    insertion_sort(map, size);

    char *result = malloc(n);
    int idx = 0;

    for (int i = 0; i < size && map[i].freq > 0; i++)
    {
        for (int j = 0; j < map[i].freq; j++)
        {
            result[idx++] = map[i].chr;
        }
    }
    result[idx++] = '\0';
    return result;
}

int main()
{

    char input[20];
    scanf("%s", input);

    int len = 0;
    while (input[len])
    {
        len++;
    }

    char *sorted = freq_sort(input, len);

    printf("%s", sorted);
    return 0;
}