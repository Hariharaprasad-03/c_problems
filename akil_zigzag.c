#include <stdio.h>

int str_len(char *s )
{
    int i =0;
    while (s[i])
    {
        i++;
    }

    return i;
}

char * zigzag(char * s, int n , int row)
{
    char *ans  =(char*) malloc(n);
    int k=0;
    char arr[row][100];
    memset(arr,' ',sizeof(arr));
    int i =0;

    int r=0 ,c =0;
    int dr =1, dc=0;

    while(i<n)
    {
      arr[r][c] = s[i];
      i++;

      if( !(r+dr >=0 && r+dr<row && c+dc >=0 ))
      {

        if (dr>0)
        {
            dr=-1;
            dc= -1;

        }
        else 
        {
            dr =1;
            dc =0;
        }
      }
      r+=dr;
      c+=dc;
    }


    for ( int i =0 ;i<=row;i++)
    {
        for (int j = 0 ; j<=r;j++)
        {
            if (arr[i][j] !=' ')
            {
                ans[k++] = arr[i][j];
            }
        }

    }

    ans[k]='\0';
    

    for ( int i= 0;i<k;i++)
    {
        printf("%c",ans[i]);
    }
    return ans;
}


int main()
{
    char input[100];
    int row;

    scanf("%s",input);
    scanf("%d",&row);

    int n =str_len(input);

    char * ans = zigzag(input , n,row );

    
    return 0;   
}
