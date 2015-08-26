#include<stdio.h>
#include<stdlib.h>
struct NODE{
	int key;
	struct NODE *left;
	struct NODE *right;
	int height;
	
	NODE(int k){
		key=k;
		left=NULL;
		right=NULL;
		height=1;
	}
};
typedef struct NODE node;
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
node *balance(node *root){
	int bf=height(root->left)-height(root->right);

	if(bf>=2)
		return rightRotate(root);
	else if(bf<=-2)
		return leftRotate(root);
	else 
		return root;
}

node *push(node* root,int key){	
	if(root==NULL)	
		return new node(key);	
	if(key<root->key)
		root->left=push(root->left,key);
	else
		root->right=push(root->right,key);	
	return balance(root);
}

node * delete(node* root,int key)
	{
	if(!root)
		return root;

	if(root->left==NULL && root->right==NULL)
		{
		if(root->key==key){
			free(root);
			return NULL;
			}
		else
			return root;
		}
	if(root->key<key)
		root->left=delete(root->left,key);

	else if(root->key>key)
		root->right=delete(root->right,key);

	else	
		{
		
		if(root->right!=NULL){
			root->key=root->right->key;
			root->right=delete(root->right,root->key);
			}
		
		else	{
			root->key=root->left->key;
			root->left=delete(root->left,root->key);
			}
		}
	return balance(root);
}

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
	preorder(tree);
	printf("\n");
	tree=delete(tree,4);
}















