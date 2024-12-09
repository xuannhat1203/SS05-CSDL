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
void insertToRandom(Node** head, int data, int position) {
    Node* newNode = createNode(data);
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	
	Node* temp = *head;
	
	for(int i=0; temp != NULL && i<position - 1; i++){
		temp = temp->next;
	}
	
	newNode->next = temp->next;
	temp->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;
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
	printf("Nhap gia tri muon them: ");
	scanf("%d",&data);
	inseartToStart(&head,data);
	printf("Mang sau khi them\n");
	printList(head);
	printf("Nhap gia tri muon them: ");
	scanf("%d",&data);
	printf("Nhap vi tri muon them: ");
	scanf("%d",&position);
	insertToRandom(&head,data,position);
	printf("Mang se khi them\n");
	printList(head);

}

