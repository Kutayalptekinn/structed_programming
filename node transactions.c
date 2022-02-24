#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}NODE;
void traverse(NODE *head);
void addLast(NODE **head, int data);
void addFront(NODE **head, int data);
void deleteFront(NODE **head);
void deleteLast(NODE **head);
void printNode(NODE *n);
void insertbyKey(NODE **head, int data);
void deletebyKey(NODE **head,int data);
int main(){
	NODE *head=NULL;
	addLast(&head,10);
	traverse(head);
	addFront(&head,15);
	traverse(head);
	//deleteFront(&head);
	addLast(&head,20);
	traverse(head);
	insertbyKey(&head,28);
	insertbyKey(&head,40);
	traverse(head);
	addLast(&head,30);
	traverse(head);
	//deleteLast(&head);
	traverse(head);
	//deleteFront(&head);
	traverse(head);
	addFront(&head,35);
	traverse(head);
	//deleteLast(&head);
	traverse(head);
	addLast(&head,48);
	traverse(head);
	deletebyKey(&head,28);
	traverse(head);
	deletebyKey(&head,48);
	traverse(head);
	deletebyKey(&head,35);
	traverse(head);
	return 0;
}

void traverse(NODE *head){
	NODE *tmp=head;
	while(tmp!=NULL){
		printNode(tmp);
		tmp = tmp->next;
	}
	printf("\n");
}

void printNode(NODE *n){
	printf("%d ",n->data);
}

NODE *createNode(int data){
	NODE* tmp;
	tmp = (NODE*) malloc(sizeof(NODE));	
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void addFront(NODE **head, int data){
	NODE *tmp;
	NODE *newNode=createNode(data);
	newNode->next = *head;
	*head = newNode;
}


void addLast(NODE **head, int data){
	NODE *tmp;
	NODE *newNode=createNode(data);
	if(*head==NULL){
		*head = newNode;
	}else{
		tmp = *head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}

}

void insertbyKey(NODE **head, int data){
	NODE *tmp;
	NODE *newNode=createNode(data);
	if(*head==NULL){
		newNode->next = *head;
		*head = newNode;
	}
	else{
		tmp = *head;
		while(tmp->next!= NULL && tmp->next->data < data){
			tmp= tmp->next;
		}
		if(tmp->next==NULL){
			tmp->next=newNode;
		}
		else{
			newNode->next = tmp->next;
			tmp->next=newNode;	
		}
	}
	
}

void deleteFront(NODE **head){
	NODE *tmp;
	if(*head==NULL){
		printf("Empty list\n");
		return;
	}
	else{
		tmp=(*head)->next;
		printf("%d deleted\n",(*head)->data);
		free(*head);
		*head = tmp;
	}
}

void deleteLast(NODE **head){
	NODE *tmp;
	if(*head==NULL){
		printf("Enpty\n");
	}
	else{
		if((*head)->next==NULL){
			free((*head)->next);
			head =NULL;
		}
		else{
			tmp = *head;
			while(tmp->next->next!=NULL){
				tmp = tmp->next;
			}
			free(tmp->next->next);
			tmp->next=NULL;
		}
	}
	
}

void deletebyKey(NODE **head,int data){
	NODE *tmp,*tmp2;
	if((*head)->data==data){
		tmp=(*head)->next;
		printf("%d deleted\n",(*head)->data);
		free(*head);
		printf("%d deleted\n",(*head)->data);
		(*head)->next=NULL;
		*head = tmp;		
	}
	else{
		tmp = *head;
		while(tmp->next!=NULL && tmp->next->data!=data){
			tmp = tmp->next;
		}
		if(tmp== NULL){
			printf("Not found!\n");
		}
		else{
			tmp2=tmp->next;
			tmp->next=tmp->next->next;
			printf("\n%d Deleted\n",tmp2->data);
			free(tmp2);
			tmp2=NULL;
		}
	}
}

NODE* searchNode(const NODE *head, int data){
	return NULL;
}
