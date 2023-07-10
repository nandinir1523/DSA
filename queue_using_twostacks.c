#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = (int*)malloc(capacity * sizeof(int));
    queue->stack2 = (int*)malloc(capacity * sizeof(int));
    queue->top1 = -1;
    queue->top2 = -1;
    queue->capacity = capacity;
    return queue;
}

int isFull(Queue* queue) {
    return (queue->top1 == queue->capacity - 1);
}

int isEmpty(Queue* queue) {
    return (queue->top1 == -1 && queue->top2 == -1);
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }
    queue->stack1[++queue->top1] = data;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        exit(1);
    }
    if (queue->top2 == -1) {
        while (queue->top1 != -1) {
            queue->stack2[++queue->top2] = queue->stack1[queue->top1--];
        }
    }
    int data = queue->stack2[queue->top2--];
    return data;
}

int main() {
    Queue* queue = createQueue(5);

    int choice;
    int element;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                if (!isEmpty(queue)) {
                    int dequeuedElement = dequeue(queue);
                    printf("Dequeued element: %d\n", dequeuedElement);
                } else {
                    printf("Queue is empty. Dequeue operation failed.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
