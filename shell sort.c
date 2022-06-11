#include<stdio.h>
void shell(int a[],int n)
{
	int p,j,inc,temp;
	for(inc=n/2;inc>0;inc=inc/2)
	for(p=inc;p<n;p++)
	{
		temp=a[p];
		for(j=p;a[j-inc]>temp&&j>0;j=j-inc)
		a[j]=a[j-inc];
		a[j]=temp;
	}
	printf("the sorted array is\n");
	for(j=0;j<n;j++)
	printf("%d ",a[j]);
}
int main()
{
	int n;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the array");
	int i;
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	shell(a,n);
	return 0;
}  
