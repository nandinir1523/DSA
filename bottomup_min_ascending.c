#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void bottomUpHeapConstruction(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printHeap(int arr[], int n) {
    printf("Min Heap: ");
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
