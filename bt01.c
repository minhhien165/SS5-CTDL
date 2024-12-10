#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *listNode(int n, Node **tail) {
    Node *head = NULL;
    *tail = NULL;

    for (int i = 0; i < n; i++) {
        int temp;
        printf("Gia tri cua phan tu thu %d: ", i + 1);
        scanf("%d", &temp);

        Node *newNode = createNode(temp);

        if (head == NULL) {
            head = newNode;
            *tail = newNode;
        } else {
            (*tail)->next = newNode;
            newNode->prev = *tail;
            *tail = newNode;
        }
    }

    return head;
}

void printListNode(Node *tail) {
    Node *temp = tail;

    printf("Backward Traversal: ");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    int n;

    do {
        printf("Nhap so luong phan tu muon them n>0 : ");
        scanf("%d", &n);
    } while (n <= 0);

    Node *tail = NULL;
    Node *head = listNode(n, &tail);

    printf("\nDanh sach nut: \n");
    printListNode(tail);

    return 0;
}

