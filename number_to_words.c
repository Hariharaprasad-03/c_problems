#include <stdio.h>
#include <stdlib.h>

char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                "seventeen", "eighteen", "nineteen"};

char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

char *thousands[] = {"", "thousand", "million", "billion"};

char * convert_words(int n);

void handle_thousand(int n , char*res, int *index);

void handle_hundard(int n , char* res , int *index);

void handle_tens(int n , char*res ,int *index);

int strlen(char*s);


int main()
{
    int n;

    scanf("%d", &n );

    char * ans = convert_words(n);

    // printf("\n%s\n", ans);
    free(ans); // optional, but good practice


    return 0;

}

int strlen(char *s)
{
    int len=0;

    while(s[len])
    {
        len++;
    }

    return len;
}

char * convert_words(int n)
{
    char *res =(char*) malloc(256);
    int index=0;

    if (n == 0) {
        char *zero = (char *)malloc(5); // "zero" + '\0'
        zero[0] = 'z';
        zero[1] = 'e';
        zero[2] = 'r';
        zero[3] = 'o';
        zero[4] = '\0';
    return zero;
    }


    handle_thousand(n,res,&index);
    res[index]='\0';

    for (int i=0;i<index;i++){
        printf("%c",res[i]);
    }
    
    
    return res;
}

void handle_thousand(int n , char * res,int*index)
{
    int thousand = n/1000;
    char t[9]="thousand";

    if (thousand == 0) {
        handle_hundard(n % 1000, res, index);
        return;
    }

    if  ( thousand < 20 && thousand!=0)
    {
        char * s = ones[thousand];
        int len = strlen(s);

        for(int i=0 ; i<len ;i++ )
        {
            res[ (*index)++ ] = s[i];
        }
        
        res[ (*index)++ ]=' ';

        for(int i=0;i<=8;i++)
        {
            res[ (*index)++ ]=t[i];
        }
        res[ (*index)++ ]=' ';

    }
    else
    {
        char *s1 = tens[ thousand/10 ];
        char *s2 = ones[thousand%10];

        int len1 = strlen(s1);
        int len2 = strlen(s2);

        for (int i=0;i<len1;i++)
        {
            res[ (*index)++ ] = s1[i];
        } 

        res[ (*index)++ ]=' ';

        for(int i=0;i<len2;i++)
        {
            res[ (*index)++] = s2[i];
        }

        res[ (*index)++]=' ';

        for (int i=0 ; i<=8 ;i++)
        {
            res[ (*index)++]=t[i];
        }

        res[ (*index)++ ]=' ';

    }


    handle_hundard( n % 1000 , res , index);

}

void handle_hundard( int n , char * res , int * index){

    int hund = n/100;
    char h[8] ="hundred";

    if (hund == 0){
        handle_tens(n % 100,res , index);
        return ;
    }

    char* s=ones[hund];
    int len =strlen(s);

    for (int i=0;i<len;i++)
    {
        res[ (*index)++ ] = s[i];
    }

    res[(*index)++]=' ';
// 
    for (int i=0 ; i<8 ; i++)
    {
        res[(*index)++] = h[i];
    }

    res[(*index)++]=' ';

    handle_tens( n %100 , res , index);

}

void handle_tens( int n , char * res , int * index)
{
    
    if ( n<20 )
    {
        char * s = ones[n];
        int len = strlen(s);

        for ( int i=0 ; i<len ; i++ )
        {
            res[ (*index)++ ] = s[i];
        }
    }
    else{

        int ten = n/10;
        int one = n%10;

        char * s1 = tens[ten];
        char * s2 = ones[one];

        int l1 = strlen(s1);
        int len2 = strlen(s2);
        
        for ( int i=0 ;i<l1;i++)
        {
            res[ (*index)++ ] = s1[i];

        }

        res[ (*index)++ ] = ' ';

        for (int i=0 ; i<len2 ;i++)
        {
            res[ (*index)++ ] = s2[i];
        }
    }
}