#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
	int data;
	struct treenode *left;
	struct treenode *right;
}NODE;

NODE *insert(NODE *, int);
NODE *insertR(NODE *, int);
void preOrder(NODE*);
void postOrder(NODE*);
void inOrder(NODE*);
NODE* createNode(int N);
int main(){
	NODE *root=NULL;
	int N;
	while(N != 0){
		printf("Enter element, 0 to exit");
		scanf("%d",&N);
		if(N!=0)
			root=insertR(root,N);	
	}	
	inOrder(root); printf("\n");
	preOrder(root); printf("\n");
	postOrder(root); printf("\n");
}
NODE* createNode(int N){
	NODE *ptr= (NODE*)malloc(sizeof(NODE));
	ptr->data = N;
	ptr->left=ptr->right=NULL;
	return ptr;
}

NODE* insert(NODE *root, int N){
	NODE *newNode=createNode(N);
	if(root==NULL){
		root = newNode;
		return root;
	}
	NODE *tmp=root;
	NODE *tmp2=NULL;
	
	while(tmp!=NULL){
		tmp2 = tmp;
		if(N < tmp->data){
			tmp = tmp->left;
		} 
		else{
			tmp = tmp->right;
		}
	}
	
	if(tmp2==NULL){
		tmp2=newNode;
	}
	else if(tmp2->data<N){
		tmp2->right=newNode;
	}
	else{
		tmp2->left=newNode;
	}
	
	return root;
}

NODE *insertR(NODE *root, int data){
	if(root == NULL){
		root = createNode(data);
		return root;
	}
	else if( data > root->data){
		root->right = insertR(root->right,data);
		return root;
	}
	else{
		root->left = insertR(root->left, data);
		return root;
	}
}

void inOrder(NODE* root){//a + b
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);	
	}
}

void preOrder(NODE* root){//+ a b
	if(root!=NULL){
		printf("%d ",root->data);
		preOrder(root->left);	
		preOrder(root->right);	
	}
}

void postOrder(NODE* root){//a b +
	if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->data);		
	}
}

