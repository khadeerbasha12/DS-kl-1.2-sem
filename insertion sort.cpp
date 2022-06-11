#include<stdio.h>
void insert(int a[],int n)
{
	int p,j,temp;
	for(p=1;p<n;p++)
	{
		temp=a[p];
		for(j=p;a[j-1]>temp&&j>0;j--)
		a[j]=a[j-1];
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
	insert(a,n);
	return 0;
}
