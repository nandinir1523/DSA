#include <stdio.h>

int f(int n) {
    if (n == 1 || n == 0)
        return n;
    else {
        return f(n - 1) + f(n - 2);
    }
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to be displayed: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d ", f(i));
    }

    return 0;
}
