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


void deleteEnd(Node**tail){
	Node*temp = *tail;
	
	if (*tail == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
	
	*tail = (*tail)->prev;
	if (*tail != NULL) {
        (*tail)->next = NULL;
    }
	free(temp);
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
	
	do{
		printf("Vui long nhap so luong phan tu n>0: ");
		scanf("%d", &n);
	}while(n<0);
	
	Node *head = NULL;
    Node *tail = NULL;

    listNode(n, &head, &tail);
	
	printf("Mang ban dau: ");
	printListNode(head);
	
	printf("Mang sau khi xoa phan tu cuoi: ");
	deleteEnd(&tail);
	printListNode(head);
	
	return 0;
	
}
