#include<stdio.h>
#include<stdlib.h>

int main()
{
	
		//int *p = (int*)malloc(3*sizeof(int));
		int *p = (int*)calloc(3,sizeof(int));
		
		if(p == NULL)
			printf("space not there\n");
		else
		{
			*p = 10;
			*(p+1) = 20;
			*(p+2) = 30;
			printf("%d %d %d\n", *p,*(p+1), *(p+2) );
			free(p);
			p = NULL;
			printf("%d %d %d\n", *p,*(p+1), *(p+2) ); //undefined behavior if p is dangling
			// definite crash if p is a NULL pointer
			printf("ended\n");
			
			
		}
		return 0;
}