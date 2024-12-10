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

Node *listNode(int n) {
    Node *head = NULL;
    Node*tail = NULL;

    for (int i = 0; i < n; i++) {
        int temp;
        printf("Gia tri cua phan tu thu %d: ", i + 1);
        scanf("%d", &temp);

        Node *newNode = createNode(temp);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

void insertPosition(Node**head, int value, int index){
	Node*newNode = createNode(value);
	
	if(index == 0){
		newNode->next = *head;
		newNode->data = value;
		newNode->prev = NULL;
	}
	
	int currentIndex = 0;
	Node*temp = *head;
	
	while(temp != NULL && currentIndex < index - 1){
		temp = temp->next;
		currentIndex++;
	}
	
	if(temp == NULL){
		printf("Vi tri nam ngoai List");
		free(newNode);
	}
	
	newNode->prev = temp;
	newNode->next = temp->next;
	temp->next = newNode;
	
}

void printListNode(Node *head) {
    Node *temp = head;

    printf("Danh sach: ");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main(){
	int n;
	int value;
	int index;
	
	do{
		printf("Vui long nhap so luong phan tu n>0: ");
		scanf("%d", &n);
	}while(n<0);
	
	Node*head = listNode(n);
	
	printf("\n Mang ban dau: ");
	printListNode(head);
	
	printf("\n Nhap gia tri muon them: ");
	scanf("%d", &value);
	
	printf("\n Nhap vi tri muon them: ");
	scanf("%d", &index);
	
	insertPosition(&head, value, index);
	
	printf("Mang sau khi them: ");
	printListNode(head);
}
