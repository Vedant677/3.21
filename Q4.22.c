#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>


int arr[50];
int i;
int n;
float avg;
int min;
int max;
float sd = 0;

void *th()
{
        float b=0;
        for(i=0;i<n;i++)
                b=b+arr[i];
        avg=b/n;       
}

void *th1()
{
        min=arr[0];
        for(i=0;i<n;i++)
                if(min>arr[i])
                        min=arr[i];     
}

void *th2()
{
        max=arr[0];
        for(i=0;i<n;i++)
                if(max<arr[i])
                        max=arr[i];                       
}

void *th3()
{
    float sum = 0;
    float mean;
    float s;
    
    int i;
    for (i=0;i<n;i++) 
    {
        sum=sum+arr[i];
    }
    mean=sum/n;
    for (i=0; i<n;i++) 
    {
        s=s+pow(arr[i]-mean,2);
    }
    sd=sqrt(s/n);
}


int main()
{
 
    printf("enter the number of elements you want to enter: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("enter the number: ");
        scanf("%d",&arr[i]);
    }
   
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    
        pthread_create(&t1,NULL,&th,NULL);
        pthread_join(t1,NULL);
    
        pthread_create(&t2,NULL,&th1,NULL);
        pthread_join(t2,NULL);

        pthread_create(&t3,NULL,&th2,NULL);
        pthread_join(t3,NULL);
        
        pthread_create(&t4,NULL,&th3,NULL);
        pthread_join(t4,NULL);
 
    printf("\n Average value is %f \n",avg);
    printf("Minimum  value is %d \n",min);
    printf("Maximum  value is %d \n",max);
    printf("Standard Deviation is %f \n",sd);

}
