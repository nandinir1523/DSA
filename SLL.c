#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;
    struct node* link;
} NODE;

typedef struct list {
    NODE* head;
} LIST;

void init_list(LIST* li);
void insertatfront(LIST* li, int ele);
void display(LIST* li);
void insertLast(LIST* li, int ele);
void insertatpos(LIST* li, int ele, int pos);
void delfront(LIST* li, int* p_del_ele);
void deletefromlast(LIST* li, int* p_del_ele);
void deletefrompos(LIST* li, int pos, int* p_del_ele);
void deletefromaltposition(LIST* li);
void search(LIST* li, int key);
void displayReverse(LIST* li);

int main()
{
    LIST li;
    init_list(&li);
    printf("1. insertat front  2. insertatlast 3. insertat position 4. display 5. delfront 6. deletefromlast 7. deletefrompos 8. deletefromaltposition 9. search 10. display reverse 11: exit\n ");
    int choice;
    int ele, pos, del_ele;
    do {
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("enter the element\n");
            scanf("%d", &ele);
            insertatfront(&li, ele);
            break;
        case 2:
            printf("enter the element\n");
            scanf("%d", &ele);
            insertLast(&li, ele);
            break;
        case 3:
            printf("enter the element and position\n");
            scanf("%d%d", &ele, &pos);
            insertatpos(&li, ele, pos);
            break;
        case 4:
            display(&li);
            break;
        case 5:
            delfront(&li, &del_ele);
            if (del_ele != -1)
                printf("deleted element is %d\n", del_ele);
            break;
        case 6:
            deletefromlast(&li, &del_ele);
            if (del_ele != -1)
                printf("deleted element is %d\n", del_ele);
            break;
        case 7:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            deletefrompos(&li, pos, &del_ele);
            if (del_ele != -1)
                printf("Deleted element: %d\n", del_ele);
            break;
        case 8:
            deletefromaltposition(&li);
            break;
        case 9:
            printf("Enter the key to search: ");
            scanf("%d", &ele);
            search(&li, ele);
            break;
        case 10:
            displayReverse(&li);
            break;
        default:
            printf("exiting from here\n");
            break;
        }
    } while (choice <= 10);

    init_list(&li);  // li->head = NULL;
    return 0;
}

void init_list(LIST* li)
{
    li->head = NULL;
}

void insertatfront(LIST* li, int ele)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = ele;
    temp->link = li->head;
    li->head = temp;
}

void insertLast(LIST* li, int ele)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = ele;
    temp->link = NULL;
    NODE* p = li->head;
    if (p == NULL)
        li->head = temp;
    else
    {
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void insertatpos(LIST* li, int ele, int pos)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->info = ele;
    temp->link = NULL;
    NODE* p = li->head;
    NODE* q;
    if (pos == 0)
    {
        temp->link = p;
        li->head = temp;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            q = p;
            p = p->link;
        }
        q->link = temp;
        temp->link = p;
    }
}

void display(LIST* li)
{
    NODE* p = li->head;
    if (p == NULL)
        printf("no nodes to display\n");
    else
    {
        while (p != NULL)
        {
            printf("%d\t", p->info);
            p = p->link;
        }
        printf("\n");
    }
}

void delfront(LIST* li, int* p_del_ele)
{
    NODE* p = li->head;
    if (p == NULL)
    {
        printf("no nodes to delete\n");
        *p_del_ele = -1;
        return;
    }
    li->head = p->link;
    *p_del_ele = p->info;
    free(p);
}

void deletefromlast(LIST* li, int* p_del_ele)
{
    NODE* p = li->head;
    NODE* temp = NULL;

    if (p == NULL) {
        printf("no nodes to delete\n");
        *p_del_ele = -1;
        return;
    }

    if (p->link == NULL) {
        *p_del_ele = p->info;
        free(p);
        li->head = NULL;
        return;
    }

    while (p->link != NULL) {
        temp = p;
        p = p->link;
    }

    temp->link = NULL;
    *p_del_ele = p->info;
    free(p);
}

void deletefrompos(LIST* li, int pos, int* p_del_ele)
{
    NODE* p = li->head;
    NODE* temp = NULL;
    if (p == NULL || pos < 0)
    {
        printf("no nodes to delete or invalid position\n");
        *p_del_ele = -1;
        return;
    }
    if (pos == 0)
    {
        *p_del_ele = p->info;
        li->head = p->link;
        free(p);
        return;
    }
    int n = 0;
    while (p != NULL && n < pos)
    {
        temp = p;
        p = p->link;
        n++;
    }
    if (p == NULL)
    {
        printf("invalid position %d\n", pos);
        *p_del_ele = -1;
        return;
    }
    *p_del_ele = p->info;
    temp->link = p->link;
    free(p);
}

void deletefromaltposition(LIST* li)
{
    NODE* p = li->head;
   NODE* temp = NULL;

    while (p != NULL && p->link != NULL) {
        temp = p->link;
        p->link = temp->link;
        free(temp);
        p = p->link;
    }
}

void search(LIST* li, int key)
{
    NODE* p = li->head;
    int position = 0;
    while (p != NULL) {
        if (p->info == key) {
            printf("Key found at position %d\n", position);
            return;
        }
        p = p->link;
        position++;
    }
    printf("Key not found\n");
}

void displayReverse(LIST* li)
{
    NODE* p = li->head;
    if (p == NULL)
        return;
    
    displayReverse(p->link);
    printf("%d\t", p->info);
}
