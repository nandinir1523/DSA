typedef struct Student
{
	int rnum;
	int marks;
	char name[100];
}ST;
#include<stdio.h>
#include<stdlib.h>
void read(ST *s, int n);  // function declaration
void disp(ST *s, int n);
int main()
{
		int n;
		printf("enter n\n");
		scanf("%d", &n);
		ST *p = (ST*)calloc(n,sizeof(ST));
		
		if(p == NULL)
			printf("space not there\n");
		else
		{
			read(p, n);
			disp(p,n);
			free(p);
			p = NULL;
			
			
		}
		return 0;
}
//void read(ST s[], int n)
void read(ST *s, int n)  // function defn
{
	for(int i =0; i < n ; i++, s++)
	{
		printf("enter rollnum, marks and name\n");
		//scanf("%d%d%s",&(s[i].rnum), &(s[i].marks),s[i].name ); // array notation
		scanf("%d%d%s",&((*s).rnum), &((*s).marks), (*s).name);
		// pointer notation
	}
}
void disp(ST *s, int n)
{
	for(int i =0; i < n ; i++)
	{
		
		printf("%d---%d---%s\n",s[i].rnum, s[i].marks,s[i].name);
	}
}
