#include<stdio.h>
#include<stdlib.h>
#define tsize 10
int ht[tsize]={NULL};
void insert()
{
int x,index,hashx,i;
printf("Enter Data");
scanf("%d",&x);
hashx=x%tsize;
for(i=0;i<tsize;i++){
	index=(hashx+i)%tsize;
	if(ht[index]==NULL){
	ht[index]=x;
	break;
	}
	else if(i==tsize)
	printf("unable to insert");
	}
}
void search(){
	int x,i,index,hashx;
	printf("enter key");
	scanf("%d",&x);
	hashx=x%tsize;
	for(i=0;i<tsize;i++)
	{
		index=(hashx+i*i)%tsize;
		if(ht[index]==x)
		{
			printf("found");
			break;
		}
	}
	if(i==tsize)
		printf("not found");
}
void display(){
	int i;
	for(i=0;i<tsize;i++){
		printf("%d ",ht[i]);
	}
}
int main(){
	int x;
	while(1){
	printf("\nenter \n1.insert\n2.display\n3.search\n4.exit");
	scanf("%d",&x);
	switch(x){
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("invalid choice");
	}
	}
}
