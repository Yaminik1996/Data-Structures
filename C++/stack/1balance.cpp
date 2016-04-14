#include<ctype.h>
#include<string.h>
#include<iostream>
using namespace std;
struct stack
{
	char infix[50];
	int top;
	int size;
};
int isclose(char a)
{
	if(a=='}')
		return 1;
	else if(a==']')
		return 2;
	else if(a==')')
		return 3;
	else return 0;
}
int isopen(char a)
{
	if(a=='{')
		return 1;
	else if(a=='[')
		return 2;
	else if(a=='(')
		return 3;
	else return 0;
}
void push(stack &S, char x)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
		S.infix[++S.top]=x;
}
char pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
		return S.infix[S.top--];
}
int main()
{
	stack S;
	S.top=-1;
	S.size=50;
	int t;
	cout<<"Enter the expression : ";
	char x[20];
	cin>>x;
	int i, flag=0;
	for(i=0; i<strlen(x); i++)
	{
		if(isopen(x[i])!=0)
			push(S, x[i]);
		else if(isclose(x[i]!=0))
		{
			char c=pop(S);
			if(isopen(c)==isclose(x[i]))
			{	
				;
			}
			else
			{
				flag=1;
				break;
			}
		}
		else 
		{
			;
		}
	}
	if(flag==1||S.top!=-1)
		cout<<"UNBALANCED!";
	else cout<<"BALANCED!";
	return 0;
}
