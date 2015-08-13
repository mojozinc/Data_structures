#include<stdio.h>
#include<stdlib.h>
struct bst{
	int key;
	int data;
	struct bst *left;
	struct bst *right;
};
typedef struct bst bst;

bst *put(bst *r,int k,int val){
	if(r==NULL)
		{
		r=(bst *)malloc(sizeof(bst));
		r->key=k;
		r->data=val;
		r->left=NULL;
		r->right=NULL;
		return r;
		}
	if(k>r->key)
		r->right=put(r->right,k,val);
	else if(k<r->key)
		r->left=put(r->left,k,val);
	else
		r->data=val;
	
	return r;
}

int getMin(bst *r){
	if(r->left==NULL)
		return r->data;
	return getMin(r->left);
	}

int getMax(bst *r){
	if(r==NULL){
		printf("ERROR: Tree is Empty\n");
		exit(0);
		return 0;
		}
	if(r->right==NULL)
		return r->data;
	return getMin(r->right);

}

bst *deleteMin(bst *r){
	if(r->left==NULL){
		bst *t=r->right;
		free(r);
		return t;		
	}
	else if(r->left->left==NULL){
		bst *t=r->left->right;
		free(r->left);
		r->left=t;
		return r;
		}
	else
		r->left=deleteMin(r->left);
	return r;
}

bst *deleteMax(bst *r){
        if(r->right==NULL){
                bst *t=r->left;
                free(r);
                return t;
        }
        else if(r->right->right==NULL){
                bst *t=r->right->left;
                free(r->right);
                r->right=t;
                return r;
                }
        else
                r->right=deleteMin(r->right);
        return r;
}

int floor(bst* r,int k){
	if(r->key==k)
		return r->data;
	if(r->key<k&&r->right!=NULL)
		if(r->right->key>k)
			return r->data;
		else
			return floor(r->right,k);
	
	return floor(r->left,k);

}

int ceil(bst *r,int k){
	if(r->key==k)
		return r->data;
	if(r->key<k&&r->right!=NULL)
		return ceil(r->right,k);
	if(r->key>k&&r->left!=NULL)
		if(r->left->key>k)
			return ceil(r->left,k);
	if(r->left==NULL&&r->right==NULL)
		return r->data;	
}

void inorder(bst *r){
	if(r==NULL)
		return;
	inorder(r->left);
	printf("%d:%d ",r->key,r->data);
	inorder(r->right);
}
void preorder(bst *r){
	if(r==NULL)
		return;
	printf("%d:%d ",r->key,r->data);
	preorder(r->left);
	preorder(r->right);

}
int main(){
	bst *a=NULL;
	int i,key,data;
	for(i=0;i<10;i++){
		scanf("%d",&key);
		data=rand()%100;
		a=put(a,key,data);
		inorder(a);
		printf("\n");
		}
	inorder(a);
	printf("\n");
	preorder(a);
	printf("\n");

	printf("%d\n",ceil(a,4));
	printf("%d\n",floor(a,4));

}
