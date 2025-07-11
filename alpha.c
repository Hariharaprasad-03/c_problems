#include <stdio.h>

int main (){
    int n;
    scanf("%1d",&n);
    int i,j;
    for (int i =1; i<=n;i++){
        for (j=1 ;j<=(n-i);j++){
            printf(" ");
        }
        char ch = 'A';
        for (j=1;j<=(2*i)-1;j++){
            printf("%c",ch);
            if (j < (i)){
               ch++;
            }
            else{
                 ch--;
                 }
            
        }
        
        
        printf("\n");
    }   
    getch();
    return 0;
}
