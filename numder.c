#include <stdio.h>

int main (){
    int n;
    scanf("%1d",&n);
    int i,j;
    for (int i =1; i<=n;i++){
        for (j=1 ;j<=(n-i);j++){
            printf(" ");
        }
        for (j=i;j<2*i;j++){
            printf("%d",j);
        }
        for (j=(i-1)*2;j>=i;j--){
            printf("%d",j);
        }
        
        printf("\n");
    }   
    getch();
    return 0;
}
