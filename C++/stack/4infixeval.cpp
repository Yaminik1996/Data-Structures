#include<iostream>
using namespace std;
struct stack1
{
	int top;
	int size;
	int operand[50];
};
struct stack2
{
	int top;
	int size;
	char opt[50];
};
void push(stack1 &S, int x)
{
	if(S.top==S.size-1)
	{
		cout<<"Stack of operands is full !";
	}
	else
		S.operand[++S.top]=x;
}
void push(stack2 &S, char x)
{
	if(S.top==S.size-1)
	{
		cout<<"Stack of operators is full !";
	}
	else
		S.opt[++S.top]=x;
}
int pop(stack1 &S)
{
	if(S.top==-1)
		cout<<"Stack of operands is empty";
	else
		return S.operand[S.top--];
}
char pop(stack2 &S)
{
	if(S.top==-1)
		return '#';
	else
		return S.opt[S.top--];
}
int priority(char ch)
{
	int p;
	switch(ch)
	{
		case '*': p=2;break;
		case '/': p=2;break;
		case '%': p=2;break;
		case '+': p=1;break;
		case '-': p=1; break;
		case '#': p=0; break;
	}
	return p;
}
int eval(int a, int b, char ch)
{
	int c;
	switch(ch)
	{
		case '*': c=a*b;break;
		case '/': c=a/b;break;
		case '%': c=a%b;break;
		case '+': c=a+b;break;
		case '-': c=a-b;break;
	}
	return c;
}
char gettop(stack2 S)
{
	if(S.top==-1)
		return '#';
	else return S.opt[S.top--]; 
}
int main()
{
	char choice='y';
	stack1 num;
	num.top=-1;
	num.size=50;
	stack2 arith;
	arith.size=50;
	arith.top=-1;
	int t;
	do
	{
		cout<<"Tag?";
		cin>>t;
		if(t)
		{
			cout<<"Enter number";
			int x;
			cin>>x;
			push(num, x);
		}
		else if(!t)
		{
			cout<<"Enter operator or brace";
			char ch;
			cin>>ch;
			if(arith.top==-1)
				push(arith, ch);
			else
			{
				if(ch=='(')
					push(arith, ch);
				else if(ch==')')
				{
					while(gettop(arith)!='(')
					{
						char a=pop(arith);
						int a2=pop(num);
						int a1=pop(num);
						int a3=eval(a1, a2, a);
						push(num, a3);
					}
					pop(arith);
				}
				else
				{
					int l=priority(ch);
					char m=gettop(arith);
					int n=priority(m);
					if(l<n)
					{
						do
						{
							char a=pop(arith);
							int a2=pop(num);
							int a1=pop(num);
							int a3=eval(a1, a2, a);
							push(num, a3);
							m=gettop(arith);
							n=priority(m);
						}while(l<=n&&n!=0);
						push(arith, ch);
					}
					else if(l>=n)
					{
						push(arith, ch);
					}
				}
			}
		}
		cout<<"Continue?";
		cin>>choice;
	}while(choice=='y');
	for(int i=arith.top; i>=0; i--)
	{
		char a=pop(arith);
		int a2=pop(num);
		int a1=pop(num);
		int a3=eval(a1, a2, a);
		push(num, a3);
	}
	cout<<"\nAnswer is :"<<pop(num);
	return 0;
}
