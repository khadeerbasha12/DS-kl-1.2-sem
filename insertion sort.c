#include<stdio.h>
int main()
{
	int i,n,j,temp;
	printf("enter n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		temp=a[j];
		j=i-1;
		while(j>=0&&temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("elements after sort");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	return 0;
}
