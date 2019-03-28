#include<pthread.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/types.h>
void *func1(void *n)
{ int *d=(int*)n;
int e=*d;
int a=0;
 int b=1;
 int c;
 for(int i=0;i<e;i++)
  {    printf("%d\t",c);
        c=a+b;
        a=b;
        b=c;
    
}
}
int main()
{ int n=10;
pthread_t th1;
pthread_create(&th1,NULL,func1,&n);
pthread_join(th1,NULL);
}
