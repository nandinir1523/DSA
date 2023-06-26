typedef struct Student
{
	int rnum;
	int marks;
	char name[100];
}ST;

#include<stdio.h>
void read(ST *s, int n);  // function declaration
void disp(ST *s, int n);
int main()
{
	printf("%d\n", sizeof(ST));
	//struct Student s[100];
	ST s[100];
	int n;
	printf("enter the number of students details u want to store\n");
	scanf("%d", &n);
	printf("please enter details of %d students\n",n);
	read(s,n);   // function call
	printf("you entered\n");
	disp(s, n);
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