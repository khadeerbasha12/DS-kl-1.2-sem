#include<stdio.h>
void quicksort(int a[],int n)
{
	qsort(a,0,n-1);
}
void qsort(int a[],int left,int right)
{
	int i,j,temp,pivot;
	if(left<right)
	{
		i=left;j=right;
		pivot=a[left];
		while(i<j)
		{
			while(a[i]<=pivot)
			i++;
			while(a[j]>pivot)
			j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[j];
		a[j]=a[left];
		a[left]=temp;
		qsort(a,left,j-1);
		qsort(a,j+1,right);
	}
}
void display(int a[],int n)
{
	int i;
		printf("the sorted array is\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
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
	quicksort(a,n);
	display(a,n);
	return 0;
}  
