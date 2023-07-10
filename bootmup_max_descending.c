#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void bottomUpHeapConstruction(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int arr[], int n) {
    printf("Max Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Before Heap Construction:\n");
    printHeap(arr, n);

    bottomUpHeapConstruction(arr, n);

    printf("After Heap Construction:\n");
    printHeap(arr, n);

    return 0;
}
