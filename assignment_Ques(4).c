#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void *func1(void *x);
void *func2(void *x);
int *array2;
void *func1(void *x)
{ pthread_t th2; 
  int *b=(int *)x;
  int n=*b;
  int first=-1,second=1,sum=0;
  int array[n];
  for(int i=0;i<n;i++)
   {  sum=first+second;
      first=second;
      second=sum;
      array[i]=sum;
   }
   array2=array;
   pthread_create(&th2,NULL,func2,&n);
   pthread_join(th2,NULL);
}
void *func2(void *x)
{  int *b=(int *)x;
   int n=*b;
   printf("fibonacci series upto %d no. :\t ",n);
   for(int i=0;i<n;i++)	
     printf(" %d ",*(array2+i));
}
void main()
{
int n;
pthread_t th1;
printf("Enter value of n : ");
scanf("%d",&n);
pthread_create(&th1,NULL,func1,&n);
pthread_join(th1,NULL);
}
