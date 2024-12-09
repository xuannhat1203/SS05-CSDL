#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void inseartToStart(Node** head,int data){
	Node* newNode = createNode(data);
	newNode->next = *head;
	if(*head != NULL){
		(*head)->prev = newNode;
	}
	*head = newNode;
}
void deleteEnd(Node** head){
	Node* temp = *head;
	while (temp->next->next != NULL) {
	    temp = temp->next;
	}
	Node* lastNode = temp->next;
	temp->next = NULL;
	free(lastNode);
}
void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d <-> ", temp->data);
		temp = temp->next;
	}
	printf(" NULL ");
}
int main(){
	Node* head = NULL;
	int choice;
	int data;
	int position;
	int num;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&num);
	int n;
	for(int i = 0; i<num;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&n);
		inseartToStart(&head,n);
	}
	printf("Ham truoc khi xoa\n");
	printList(head);
	deleteEnd(&head);
	printf("\nMang sau khi xoa\n");
	printList(head);

}

