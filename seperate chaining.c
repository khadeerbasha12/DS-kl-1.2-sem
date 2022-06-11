#include<stdio.h>
#include<stdlib.h>
#define tsize 10
struct node
{
int data;
struct node*next;
};
struct node*ht[tsize]={NULL};
struct node*temp;
void insert(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % tsize;
    if(ht[key] == NULL)
        ht[key] = newNode;
    else
    {
        struct node *temp = ht[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
void search()
{
int x,index;
printf("Enter Key");
scanf("%d",&x);
index=x%tsize;
struct node*temp;
if(ht[index]==NULL)
printf("Not Found");
else
{
temp=ht[index];
while(temp)
{
if (temp->data==x)
{
printf("Found");
break;
}
temp=temp->next;
}
if(temp==NULL)
printf("Not Found");
}
}
void display()
{
int index;
for(index=0;index<tsize;index++)
{
temp=ht[index];
while(temp)
{
printf("%d  ",temp->data);
temp=temp->next;
}
}
}
int main()
{
int x,a;
char c;
while(1){
printf("\nEnter \n 1.Insert \n 2.Search \n 3.Display \n 4.Exit");
scanf("%d",&x);
switch(x){
case 1:
	printf("enter the element you want to insert");
	scanf("%d",&a);
insert(a);
break;
case 2:
search();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
default:
printf("Invalid Choice");
break;
}
}
}
