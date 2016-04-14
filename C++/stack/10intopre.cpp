#include<iostream>
using namespace std;
union pe
{
	int a;
	char b;
};
struct post
{
	union pe ele;
	int tag;
};
struct stack
{
	char ch[50];
	int top;
};
int priority(char a)
{
	int p;
	switch(a)
	{
		case '+' : p=1;break;
		case '-' : p=1; break;
		case '*': p=2; break;
		case '/': p=2; break;
		case '%': p=2; break;
		case '#': p=0; break;
	}
	return p;
}
void push(stack &S, char x)
{
	S.ch[++S.top]=x;
}
char pop(stack &S)
{
	if(S.top==-1)
		return '#';
	else
	return S.ch[S.top--];
}
char gettop(stack S)
{
	if(S.top==-1)
		return '#';
	else
	return S.ch[S.top];
}
int main()
{
	post postfix[50];
	stack S;
	S.top=-1;
	int i=0, t=0;
	char choice='y';
	do
	{
		cout<<"Enter tag : (1->operand) (0->operator)";
		cin>>t;
		if(t)
		{
			cout<<"Enter operand";
			int num;
			cin>>num;
			postfix[i].tag=t;
			postfix[i].ele.a=num;
			++i;
		}
		else if(!t)
		{
			cout<<"Enter operator";
			char ch;
			cin>>ch;
			if(S.top==-1)
				push(S, ch);
			else if(S.top!=-1)
			{
				if(ch=='(')
					push(S, ch);
				else if(ch==')')
				{
					while(gettop(S)!='(')
					{
						postfix[i].tag=t;
						postfix[i].ele.b=pop(S);
						++i;
					}
					pop(S);
				}
				else 
				{
					int l=priority(ch);
					char m=gettop(S);
					int n=priority(m);
					if(l<=n)
					{
						do
						{
						postfix[i].tag=t;
						postfix[i].ele.b=pop(S);
						++i;
						m=gettop(S);
						n=priority(m);
						}while(l<=n&&n!=0);
						push(S, ch);
					}
					if(l>n)
					{
						push(S, ch);
					}
				}
			}
		}
		cout<<"Continue(y/n)?";
		cin>>choice;
	}while(choice=='y');
	for(int k=S.top; k>=0; k--)
		postfix[i++].ele.b=pop(S);
	for(int j=i-1; j>=0; j--)
	{
		if(postfix[j].tag==1)
			cout<<postfix[j].ele.a;
		else if(postfix[j].tag==0) 
			cout<<postfix[j].ele.b;
	}
	return 0;
}
