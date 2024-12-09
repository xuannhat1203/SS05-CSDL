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
void printListReverse(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("Danh sách rong.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main(){
	Node* head = NULL;
	int num;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&num);
	int n;
	for(int i = 0; i<num;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&n);
		inseartToStart(&head,n);
	}
	printf("Mang in nguoc\n");
	printListReverse(head);
}

