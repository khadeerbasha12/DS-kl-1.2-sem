#include<stdio.h>
#include<stdlib.h>
struct node{
	int data,height;
	struct node *left,*right;
};
typedef struct node* tree;
void inorder(tree t){
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}
void preorder(tree t){
	if(t!=NULL){
		printf("%d ",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void postorder(tree t){
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		printf("%d ",t->data);
	}
}
int height(tree t){
	if(t==NULL)
	return -1;
	else
	return t->height;
}
int max(int l,int r){
	if(l>r)
	return l;
	else
	return r;
}
tree ll(tree k1){
	tree k2=k1->left;
	k1->left=k2->right;
	k2->right=k1;
	return k2;
}
tree rr(tree k1){
	tree k2=k1->right;
	k1->right=k2->left;
	k2->left=k1;
	k1->height=max(height(k1->left),height(k1->right))+1;
	k2->height=max(height(k2->left),k1->height);
	return k2;
}
tree lr(tree k1){
	k1->left=rr(k1->left);
	return ll(k1);
}
tree rl(tree k1){
	k1->right=ll(k1->right);
	return rr(k1);
}
tree insert(tree t,int x){
	if(t==NULL){
		t=(tree)malloc(sizeof(struct node));
		t->data=x;
		t->height=0;
		t->left=t->right=NULL;
	}
	else if(x<t->data){
		t->left=insert(t->left,x);
		if(height(t->left)-height(t->right)==2)
		if(x<t->left->data)
		t=ll(t);
		else
		t=lr(t);
	}
	else if(x>t->data){
		t->right=insert(t->right,x);
		if(height(t->right)-height(t->left)==2)
		if(x>t->right->data)
		t=rr(t);
		else
		t=rl(t);
	}
	t->height=max(height(t->left),height(t->right))+1;
	return t;
}
void delete(){
	
}
int main(){
	int x,h,d;
	tree t={NULL};
	while(1){
	printf("\nenter \n1.insert\n2.delete\n3.inorder\n4.preorder\n5.postorder\n6.height\n7.exit");
	scanf("%d",&x);
	switch(x){
		case 1:
			printf("enter data to insert");
			scanf("%d",&h);
			t=insert(t,h);
			break;
		case 2:
			delete();
			break;
		case 3:
			inorder(t);
			break;
		case 4:
			preorder(t);
			break;
		case 5:
			postorder(t);
			break;
		case 6:
			d=height(t);
			printf("height=%d",d);
			break;
		case 7:
			exit(0);
			break;
		default:
			printf("invalid choice");
			break;
	}
	}
}
