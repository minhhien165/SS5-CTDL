#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node*next;
	struct Node*prev;
}Node;

Node*createNode(int value){
	Node*newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

void listNode(int n, Node **head, Node **tail) {
    *head = NULL;
    *tail = NULL;

    for (int i = 0; i < n; i++) {
        int temp;
        printf("Gia tri cua phan tu thu %d: ", i + 1);
        scanf("%d", &temp);

        Node *newNode = createNode(temp);

        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
        } else {
            (*tail)->next = newNode;
            newNode->prev = *tail;
            *tail = newNode;
        }
    }
}


void currentIndex(Node*head){
	Node*temp = head;
	int current = 0;
	while(temp != NULL){
		current++;
		temp = temp->next;
	}
	
	if(current == 0){
		printf("Danh sach rong");
	}else{
		printf("%d", current);
	}
	
}

void printListNode(Node*head){
	
	Node*temp = head;
	while(temp != NULL){
		printf("%d<->", temp->data);
		temp = temp->next;
	}
	
	printf("NULL\n");
}

int main(){
	int n;
	
	printf("Vui long nhap so luong phan tu n>0: ");
	scanf("%d", &n);
	
	Node *head = NULL;
    Node *tail = NULL;

    listNode(n, &head, &tail);
	
	printf("Mang ban dau: ");
	printListNode(head);
	
	printf("So luong phan tu: ");
	currentIndex(head);
	
	return 0;
	
}
