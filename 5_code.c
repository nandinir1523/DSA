// debug this
#include<stdio.h>
#include<stdlib.h>

int main()
{
		int n;
		printf("enter n\n");
		scanf("%d", &n);
		int *p = (int*)calloc(n,sizeof(int));
		
		if(p == NULL)
			printf("space not there\n");
		else
		{
			for(int i = 0; i < n; i++)
			{
				p[i] = 60;
			}
			printf("before realloc p is %p\n", p);
			for(int i = 0; i < n; i++)
			{
				printf("%d\t", p[i]);
			}
			printf("\nenter n\n");
			scanf("%d", &n);
			int *p1 = (int*)realloc(p,n)); 
			
			printf("after realloc p is %p\n", p1);
			for(int i = 0; i < n; i++)
			{
				printf("%d\t", p1[i]);
			}
			
			
		}
		return 0;
}