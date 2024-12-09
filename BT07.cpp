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
void deleteEven(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* nextNode = temp->next; 
        if (temp->data % 2 == 0) {
            if (temp->prev != NULL) { 
                temp->prev->next = temp->next;
            } else { 
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp); 
        }
        temp = nextNode; 
    }
}
void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Node* current = *head;
    Node* index = NULL;
    int temp;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
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
	deleteEven(&head);
	sortList(&head);
	printf("\nMang sau khi xoa\n");
	printList(head);

}

