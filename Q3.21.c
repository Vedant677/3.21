#include<stdio.h>
#include<sys/types.h>
#include unistd.h>

int main()
{
   int a;
   printf("enter a positive whole number: ");
   scanf("%d",&a);
   
   if(fork()==0)
   {
      while(a>1)
      {
         printf("%d, ",a);
         if(a%2==0)
            a=a/2;
         else
            a=(a*3)+1;
       }
      printf( "1\n");
    }
    else
    {
      wait(NULL);
    }
 }
