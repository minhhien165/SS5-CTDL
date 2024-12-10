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

void createList(int n, Node **head, Node **tail) {
    *head = NULL;
    *tail = NULL;

    for (int i = 0; i < n; i++) {
        int temp;
        printf("Nhap gia tri pha tu thu %d: ", i + 1);
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

void printList(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void replaceValue(Node *head, int oldValue, int newValue) {
    Node *current = head;
    int found = 0;

    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found) {
        printf("Da thay the gia tri %d bang %d.\n", oldValue, newValue);
    } else {
        printf("Khong tim thay gia tri cân thay the %d \n", oldValue);
    }
}

int main() {
    int n;

    do {
        printf("Nhap so luong phan tu n > 0: ");
        scanf("%d", &n);
    } while (n <= 0);

    Node *head = NULL;
    Node *tail = NULL;

    createList(n, &head, &tail);

    printf("\nDanh sach ban dau: ");
    printList(head);

    int oldValue, newValue;
    printf("\nNhap gia tri can thay the: ");
    scanf("%d", &oldValue);
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    replaceValue(head, oldValue, newValue);

    printf("\nDanh sach sau khi thay the: ");
    printList(head);

    return 0;
}

