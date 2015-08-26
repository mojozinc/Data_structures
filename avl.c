#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *left;
	struct node *right;
	int height;
	
	node(int k){
		key=k;
		left=NULL;
		right=NULL;
		height=1;
	}
};
typedef struct node node;
int max(int a,int b){
	return a>b?a:b;
	}

int height(node *root){
	if(!root)
		return 0;
	return 1+max(height(root->left),height(root->right));
}

node *leftRotate(node *root){
	node *x;
	x=root->right;
	root->right=x->left;
	x->left=root;

	return x;
}
node *rightRotate(node *root){
	node *x;
	x=root->left;
	root->left=x->right;
	x->right=root;
	return x;
}

node *push(node* root,int key){
	node *x;
	int bf;
	int left_h,right_h;

	if(root==NULL)
		{
		x=new node(key);
		return x;
		}		
	if(key<root->key)
		root->left=push(root->left,key);
	else
		root->right=push(root->right,key);	
	x=root;
	
	x->height=height(x);

	left_h=height(x->left);
	right_h=height(x->right);	

	bf=left_h-right_h;
	if(bf>=2)
		return rightRotate(x);
	else if(bf<=-2)
		return leftRotate(x);	
	return x;
	
}
node *delete(node *root,int key){}
void preorder(node *root){
	if(!root)
		return;
	printf("%d ",root->key);
	preorder(root->left);
	preorder(root->right);

}


void inorder(node *root){
	if(!root)
		return;
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
	
}

int main(){
	int i=1;
	node *tree=NULL;
	for(i=1;i<=7;i++)
	{	
	tree=push(tree,i);
	}
}















