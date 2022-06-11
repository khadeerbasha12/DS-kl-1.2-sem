#include<stdio.h>
void mergesort(int a[],int n)
{
	int temp[50];
	msort(a,temp,0,n-1);
}
void msort(int a[],int temp[],int left,int right)
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		msort(a,temp,left,mid);
		msort(a,temp,mid+1,right);
		merge(a,temp,left,mid+1,right);
	}
}
void merge(int a[],int tmp[],int lpos,int rpos,int rightend)
{
	int tmppos,noe,leftend,i;
	tmppos=lpos;leftend=rpos-1;noe=rightend-lpos+1;
	while(lpos<=leftend&&rpos<=rightend)
	{
		if(a[lpos]<=a[rpos])
		tmp[tmppos++]=a[lpos++];
		else
		tmp[tmppos++]=a[rpos++];
	}
	while(lpos<=leftend)
	tmp[tmppos++]=a[lpos++];
	while(rpos<=rightend)
	tmp[tmppos++]=a[rpos++];
	for(i=0;i<noe;i++,rightend--)
	a[rightend]=tmp[rightend];
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
	mergesort(a,n);
	display(a,n);
	return 0;
}  
