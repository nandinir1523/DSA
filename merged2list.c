#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

void initDLL(DoublyLinkedList* dll);
Node* createNode(int data);
void insertNode(DoublyLinkedList* dll, int data);
void displayDLL(DoublyLinkedList* dll);
void mergeDLL(DoublyLinkedList* dll1, DoublyLinkedList* dll2, DoublyLinkedList* mergedDLL);

int main() {
    DoublyLinkedList dll1, dll2, mergedDLL;
    initDLL(&dll1);
    initDLL(&dll2);
    initDLL(&mergedDLL);

    int choice;
    int value;

    while (1) {
        printf("1. Insert an element in DLL1\n");
        printf("2. Insert an element in DLL2\n");
        printf("3. Merge DLL1 and DLL2\n");
        printf("4. Display the merged DLL\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert in DLL1: ");
                scanf("%d", &value);
                insertNode(&dll1, value);
                break;
            case 2:
                printf("Enter the element to insert in DLL2: ");
                scanf("%d", &value);
                insertNode(&dll2, value);
                break;
            case 3:
                mergeDLL(&dll1, &dll2, &mergedDLL);
                printf("DLL1 and DLL2 merged successfully.\n");
                break;
            case 4:
                printf("Merged Doubly Linked List: ");
                displayDLL(&mergedDLL);
                break;
            case 5:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}

void initDLL(DoublyLinkedList* dll) {
    dll->head = NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(DoublyLinkedList* dll, int data) {
    Node* newNode = createNode(data);
    if (dll->head == NULL) {
        dll->head = newNode;
    } else if (data < dll->head->data) {
        newNode->next = dll->head;
        dll->head->prev = newNode;
        dll->head = newNode;
    } else {
        Node* current = dll->head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void displayDLL(DoublyLinkedList* dll) {
    Node* current = dll->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void mergeDLL(DoublyLinkedList* dll1, DoublyLinkedList* dll2, DoublyLinkedList* mergedDLL) {
    Node* current1 = dll1->head;
    Node* current2 = dll2->head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data <= current2->data) {
            insertNode(mergedDLL, current1->data);
            current1 = current1->next;
        } else {
            insertNode(mergedDLL, current2->data);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        insertNode(mergedDLL, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertNode(mergedDLL, current2->data);
        current2 = current2->next;
    }
}
