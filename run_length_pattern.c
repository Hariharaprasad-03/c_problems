#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n ;
    scanf("%d",&n);

    int * prev = (int*)malloc(100 * sizeof(int));
    prev[0]=1;
    int prev_size =1;

    for ( int i=0 ; i<n ;i++)
    {
        

        for ( int i=0 ;i < prev_size;i++)
        {
            printf("%d",prev[i]);
        }
        printf("\n");

        int j=0 ;
        int * cur =(int *)malloc(sizeof(int)*100);
        int cur_len =0;

        while( j < prev_size)
        {
            int cnt =1;
            
            while( j+1 < prev_size && prev[j]==prev[j+1] )
            {
                cnt++;
                j++;
            }
            
            cur[cur_len++]=cnt;
            cur[cur_len++]=prev[j];
            j++;
        }

        free(prev);
        prev = cur;
        prev_size=cur_len;        
    }
}