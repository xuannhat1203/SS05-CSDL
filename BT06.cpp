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
void inseartToEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {  
        *head = newNode; 
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void updateList(Node** head, int data, int newData) {
    if (*head == NULL) return; 

    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == data) { 
            temp->data = newData; 
            return;               
        }
        temp = temp->next;
    }
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
	int newData;
	int data;
	int original;
	int num;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&num);
	int n;
	for(int i = 0; i<num;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&n);
		inseartToEnd(&head,n);
	}
	printf("Nhap gia tri muon thay doi: ");
	scanf("%d",&original);
	printf("Nhap gia tri mo: ");
	scanf("%d",&newData);
	updateList(&head, original, newData);
	printList(head);
}

