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
    if (position < 0) {
        return;
    }
    if (*head == NULL) {
        if (position == 0) {
            *head = newNode;
        } else {
            free(newNode);
        }
        return;
    }
    if (position == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    int currentPosition = 0;
    while (temp->next != NULL && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }
    if (currentPosition == position - 1) {
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        free(newNode);
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
int lengthList(Node* head){
	Node* temp = head;
	int count = 0;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	return count;
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
	printf("%d", lengthList(head));
}

