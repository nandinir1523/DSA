typedef struct node 
{
	int a;
	struct node *link; // self referential structure
}ST;
#include<stdio.h>
#include<stdlib.h>
void disp(ST* p1);
int main()
{
	
		ST *p1 = (ST*)malloc(sizeof(ST));
		p1->a = 100;
		p1->link = (ST*)malloc(sizeof(ST));
		p1->link->a = 400;
		p1->link->link = (ST*)malloc(sizeof(ST));
		p1->link->link->a = 13;
		p1->link->link->link = (ST*)malloc(sizeof(ST));
		p1->link->link->link->a = 500;
		p1->link->link->link->link = NULL;
		disp(p1);
		
		
}
void disp(ST* p1)
{
	while(p1 != NULL)
	{
		printf("%d\t", p1->a);
		p1 = p1->link;
	}
}