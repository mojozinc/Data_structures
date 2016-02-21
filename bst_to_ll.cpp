#include <iostream>
#include <vector>
#include <cstdio>
#define LEFT 0
#define RIGHT 1

using namespace std;

struct node {
	int key;
	node *left;
	node *right;
	node *next;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* root, int key)
{
    /* If the tree is empty, return a new node */
    if (root == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);   
 
    /* return the (unchanged) root pointer */

    return root;
}

node * init_random_tree(int size){
	printf("SIZE:%d\n",size);
	node *root=NULL;
	int key;
	for (int i = 0; i < size; ++i)
	{	
		key=7+rand()%147;
		root=insert(root,key);
		printf("%d Inserted\n",key);
	}
	return root;

}

node *minimum(node * root){
	if(!root)
		return NULL;
	while(root->left)
		root=root->left;
	return root;
}

node *maximum(node * root){
	if(!root)
		return NULL;
	while(root->right)
		root=root->right;
	return root;
}

void make_ll(node *root){
	if(!root)
		return;

	node *left = maximum(root->left);
	node *right = minimum(root->right);

	make_ll(root->left);
	make_ll(root->right);

	if(left)
		left->next=root;
	root->next=right;
}
int main(){
	
	int l,u;
	cout<<"Min Size: ";
	cin>>l;
	cout<<"Max Size: ";
	cin>>u;
	
	node *root = init_random_tree(l+rand()%(u-l));
	make_ll(root);
	node *head = minimum(root);

	while(head->next){
		cout<<head->key<<"->";
		head=head->next;
	}
	cout<<head->key;
}