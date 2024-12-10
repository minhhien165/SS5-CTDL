#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	
	struct Node*next;
	struct Node*prev;
}Node;

Node*creatNode(int value){
	Node*newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

Node*listNode(int n, Node**head, Node**tail){
	*head = NULL;
	*tail = NULL;
	
	for(int i=0; i<n ; i++){
		int temp;
		printf("Gia tri phan tu thu %d: ", i+1);
		scanf("%d", &temp);
		
		Node*newNode = creatNode(temp);
		
		if(*head == NULL){
			*head = newNode;
			*tail = newNode;
		}else{
			(*tail)->next = newNode;
			newNode->prev = *tail;
			*tail = newNode;
		}
	}
	
	return *head;
}

void reverseList(Node **head, Node **tail) {
    Node *current = *head;
    Node *temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        temp = temp->prev;
        *tail = *head;
        *head = temp;
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
	
	do{
		printf("Nhap so luong phan tu muon them n>0: ");
		scanf("%d", &n);
	}while(n<0);
	
	Node*head = NULL;
	Node*tail = NULL;
	
	listNode(n, &head, &tail);
	
	printf("\n Ham chua dao nguoc: ");
	printListNode(head);
	
	reverseList(&head, &tail);

    printf("\nDanh sach sau khi dao nguoc: ");
    printListNode(head);
	
	return 0;
}
