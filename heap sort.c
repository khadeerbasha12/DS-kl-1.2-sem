#include<stdio.h>
#define size 10
void heapsort(int a[])
{
	buildheap(a);
	while(size>1)
	{
		swap(&a[0]&&a[size-1]);
		size--;
		maxheapify(a,0);
	}
}
void buildheap(int a[]){
	int i;
	for(i=(size=2)/2;i>=0;i--)
	maxheapify(a,i);
}
void maxheapify(int a[],int index){
	int large=index;
	int left=(2*index)+1;
	int right=(2*index)+2;
	if(left<size&&a[left]>a[large])
	large=left;
	if(right<size&&a[right]>a[large])
	large=right;
	if(large!=index){
		swap(&a[large],&a[index]);
		maxheapify(a,large);
	}
}
void swap(int*a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void print(int a[],int n){
	for(int i=o;i<n;i++)
	printf("%d",a[i]);
}
void main(){
	int n;
	printf("enter the size");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements into the array");
	for(int i=0;i<n;i++)
	scanf("%d",a[i]);
	heapsort(a);
	printf("sorted array is\n");
	print(a);
}
