#include <stdio.h>

int value(char ch)
{
   switch (ch)
   {

   case 'I':
      return 1;
   case 'V':
      return 5;
   case 'X':
      return 10;
   case 'L':
      return 50;
   case 'C':
      return 100;
   case 'D':
      return 500;
   case 'M':
      return 1000;
   default:
      return 0;
   }
}
int main()
{
   char arr[6];
   int n = 0;

   printf("Enter Roman Value :");
   scanf("%s", arr);

   while (arr[n] != '\0')
   {
      n++;
   }

   int sum = 0;
   int a, b;
    
   for (int i = 0; i < n - 1; i++)
   {
      a = value(arr[i]);
      b = value(arr[i + 1]);
      if (b > a)
      {
         sum -= a;
      }
      else
      {
         sum += a;
      }
      printf("%d \n", sum);
   }
   sum += value(arr[n - 1]);

   printf("Integer Value : %d ", sum);
}