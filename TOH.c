#include <stdio.h>

void TOH(int n, char src, char temp, char dst) {
    if (n == 1||n==0) {
        printf("Move disk 1 from %c to %c\n", src, dst);
        
    }
	else{
		 TOH(n - 1, src, dst, temp);
		printf("Move disk %d from %c to %c\n", n, src, dst);
		TOH(n - 1, temp, src, dst);
	}
}

		

   

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    TOH(n, 'A', 'B', 'C');

    return 0;
}

