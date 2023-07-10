#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* arr[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void iterativeInorder(Node* root);
void iterativePreorder(Node* root);
void iterativePostorder(Node* root);
Node* createNode(int data);

// Stack implementation

void initStack(Stack* stack) {
    stack->top = -1;
}

int isStackEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isStackFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack* stack, Node* node) {
    if (isStackFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->arr[++stack->top] = node;
}

Node* pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}

// Binary Tree traversal functions

void iterativeInorder(Node* root) {
    if (root == NULL)
        return;

    Stack stack;
    initStack(&stack);

    Node* current = root;

    while (current != NULL || !isStackEmpty(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

void iterativePreorder(Node* root) {
    if (root == NULL)
        return;

    Stack stack;
    initStack(&stack);

    push(&stack, root);

    while (!isStackEmpty(&stack)) {
        Node* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL)
            push(&stack, current->right);

        if (current->left != NULL)
            push(&stack, current->left);
    }
}

void iterativePostorder(Node* root) {
    if (root == NULL)
        return;

    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    push(&stack1, root);

    while (!isStackEmpty(&stack1)) {
        Node* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL)
            push(&stack1, current->left);

        if (current->right != NULL)
            push(&stack1, current->right);
    }

    while (!isStackEmpty(&stack2)) {
        Node* current = pop(&stack2);
        printf("%d ", current->data);
    }
}

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int choice;

    while (1) {
        printf("1. Inorder traversal\n");
        printf("2. Preorder traversal\n");
        printf("3. Postorder traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder traversal: ");
                iterativeInorder(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder traversal: ");
                iterativePreorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder traversal: ");
                iterativePostorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
