#include<stdio.h>

typedef struct stack 
{
	char a[100];
	int top;
}STACK;
void push(STACK *s,char ele);
char pop(STACK *s);
void init(STACK *s);
int isEmpty(STACK *s);
int check_parantheses(char *p_exp);

int main()
{
	printf("enter the expression with parenthesis");
	char p_exp[100];
	scanf("%s",p_exp);
	int result=check_parantheses(p_exp);
	if(result==0)//if(!result)
	{
		printf("invalid \n");
	}
	else
	{
		printf("valid");
	}
	return 0;
}
void push(STACK *s,char ele)
{
	
		s->top++;
		s->a[s->top]=ele;
}
char pop(STACK *s)
{
	
		char del_ele=s->a[s->top];
		s->top--;
		return del_ele;
		
}
void init(STACK *s)
{
	s->top=-1;
	
}
int isEmpty(STACK *s)
{
	return s->top==-1;
}
int check_parantheses(char *p_exp)
{
	STACK s;
	init(&s);
	
	for(int i=0;p_exp[i]!='\0';i++)// sizeof and strlen of {} are 3 and 2 respectively since sizeof include null character
		{
			if(p_exp[i]=='{'||p_exp[i]=='('||p_exp[i]=='[')
				push(&s,p_exp[i]);
			else if(p_exp[i]=='}'||p_exp[i]==')'||p_exp[i]==']')
			{
				if(isEmpty(&s))
					return 0;
				else
				{
					switch(p_exp[i])
					{
						case '}':if(pop(&s)!='{')
								return 0;
								break;
						case ')':if(pop(&s)!='(')
								return 0;
								break;
						case ']':if(pop(&s)!='[')
								return 0;
								break;
						}
				}
			}
		}
		return isEmpty(&s);
}

		
						
				

			
				
				
			
	
	
	