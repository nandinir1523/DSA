// double ended queue implementation using linked list

typedef struct node 
{
	int info;
	struct node *prev;
	struct node* next;
}NODE;
typedef struct List
{
	NODE* front;
	NODE* rear;
}DEQUE;
#include<stdio.h>
#include<stdlib.h>
void initQ(DEQUE *pq);
void insertLast(DEQUE *pq, int ele);
void insertFront(DEQUE *pq, int ele);
int deleteFront(DEQUE *pq);
int deleteLast(DEQUE *pq);
void display(DEQUE *pq);
int isEmpty(DEQUE *pq);
int main()
{
	DEQUE q;
	initQ(&q);
	int choice, ele;
	int del_ele;
	
	do{
		printf("1. insertLast 2. deleteLast 3. insertFront 4. deleteFront 5.isEmpty 6.display  7. exit\n enter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	printf("enter the element\n");
					scanf("%d", &ele);
					insertLast(&q,ele);
					break;
			case 2: if(isEmpty(&q))
						printf("q is empty, cannot delete elements\n");
					else
					{
						del_ele = deleteLast(&q);
						printf("deleted element is %d\n", del_ele);
					}
					break;
			case 3:printf("enter the element\n");
					scanf("%d", &ele);
					insertFront(&q,ele);
					break;
			case 4: if(isEmpty(&q))
						printf("q is empty, cannot delete elements\n");
					else
					{
						del_ele = deleteFront(&q);
						printf("deleted element is %d\n", del_ele);
					}
					break;
			case 5: if(isEmpty(&q))
						printf("empty\n");
					else
						printf("not empty\n");
					break;
			
			case 6: display(&q);
					break;

			     // check for empty
			default: printf("exit\n");
		}
	}while(choice<7);
	return 0;
}
void initQ(DEQUE *pq)
{
	pq->front = pq->rear = NULL;
}
int isEmpty(DEQUE *pq)
{
	return pq->rear == NULL;
}
void insertLast(DEQUE *pq, int ele){
	NODE *temp = malloc(sizeof(NODE));
	temp->info = ele;
	temp->next = temp->prev = NULL;
	if(isEmpty(pq))
		pq->front= pq->rear = temp;
	else
	{
		temp->prev = pq->rear;
		pq->rear->next = temp;
		pq->rear = temp;
	}
}
void insertFront(DEQUE *pq, int ele)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->info = ele;
	temp->next = temp->prev = NULL;
	if(isEmpty(pq))
		pq->front= pq->rear = temp;
	else
	{
		temp->next = pq->front;
		pq->front->prev = temp;
		pq->front = temp;
	}
}
int deleteFront(DEQUE *pq)
{
	int d = pq->front->info;
	if(pq->front == pq->rear)
	{	free(pq->rear);
		initQ(pq);
	}
	else{
		NODE *p = pq->front; 
		pq->front = p->next;
		free(p);
		pq->front->prev = NULL;
	
	}
	
	return d;
}
int deleteLast(DEQUE *pq)
{	
	int d = pq->rear->info;
	if(pq->front == pq->rear)
	{	free(pq->rear);
		initQ(pq);
	}
	else{
		pq->rear = pq->rear->prev;
		free(pq->rear->next);
		pq->rear->next = NULL;
	
	}
	return d;		
}
void display(DEQUE *pq)
{
	NODE *p;
	if(isEmpty(pq))
		printf("no elements to display\n");
	else
	{
		p = pq->front;
		while(p != NULL)
		{
			printf("%d\t", p->info);
			p= p->next;
		}
	}
}
Copilot
Upgrade to Pro
 
for unlimited access.
Send a message to LINER Copilot
