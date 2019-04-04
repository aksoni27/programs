#include<stdio.h>
#include<conio.h>
void sorting(int b[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
	 for(j=0;j<n-i-1;j++)
	{ 
		if(b[j]>b[j+1])
	    {
	        int temp;
	    	temp=b[j];
	   		b[j]=b[j+1];
	   		b[j+1]=temp;	
	 	}
	
	}
 	}
}
void sorting2(int b[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
	 for(j=0;j<n-i-1;j++)
	{ 
		if(b[j]<b[j+1])
	    {
	        int temp;
	    	temp=b[j];
	   		b[j]=b[j+1];
	   		b[j+1]=temp;	
	 	}
	
	}
 	}
}
int main()
{ 	int n,no;
 	int head;
	int prev_request;   
 	printf("\n\n\t**********************************************************************************\n");
	printf("\t\t\tEnter the no. of cylinder in the disk : ");
	scanf("%d",&n);
 	printf("\t\t\tEnter no. of pending request : ");
	scanf("%d",&no);
	int a[n], b[no];
	
	for(int i=0;i<n;i++)
	{
		a[i]=i;
	}
	printf("\t\t\tEnter queue of pending request (%d) : ",no);
	for(int i=0;i<no;i++)
	{
		scanf("%d",&b[i]);	
	}
	printf("\n\t\t\tDrive is currently serving a request at cylinder : ");
	scanf("%d",&head);
	printf("\t\t\tPrevious request was at cylinder : ");
	scanf("%d",&prev_request);
	if(prev_request<head)
      {
	    int n2=sizeof(b)/sizeof(b[0]);
		sorting(b,n2);
		/*printf("sorted  queue:");
		for(int i=0;i<9;i++)
		{
			printf("\t%d",b[i]);	
		}*/
		int temp=head;
		int sum=0;
		for(int i=0;i<no;i++)
		{
			if(b[i]>head)
			{
				sum=sum+(b[i]-temp);
				temp=b[i];
			}
		}
		int sum1=sum+(a[n-1]-temp);
		int sum2=a[n-1]-b[0];
		int sum3=sum1+sum2;
		printf("\t\t\tThe total distance (in cylinders)that the disk " 
		              "arm moves to satisfy all the pending requests is : %d",sum3);
      }
  	else
	{
  		int n2=sizeof(b)/sizeof(b[0]);
	        sorting2(b,n2);
	/*	printf("sorted  queue2:");
		for(int i=0;i<no;i++)
		{
			printf("\t%d",b[i]);	
		}*/
		int temp2=head;
		int s=0;
		for(int i=0;i<no;i++)
		{
			if(b[i]<head)
			{
				s=s+(temp2-b[i]);
				temp2=b[i];
			}
		}
		int s1=s+temp2+b[0];
		printf("\t\t\t\the total distance (in cylinders)that the disk arm "
		              "moves to satisfy all the pending requests is : %d",s1);
	}
	printf("\n\n\t***********************************************************************************\n");
}
