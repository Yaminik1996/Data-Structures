#include<iostream>
using namespace std;
struct stack
{
	int top;
	int size;
	int ele[10];
};
struct stackofstack
{
	int n[10];
	int top;
	int size;
	stack S[10];
};
void pushint(stack &S, int x)
{
	if(S.top==S.size-1)
		cout<<"Stack is full!";
	else
		S.ele[++S.top]=x;
}
void pushstack(stackofstack &S2, stack &S1, int n)
{
	if(S2.top==S2.size-1)
		cout<<"Stack of stack is full!";
	else
	{
		S2.top++;
		for(int i=0; i<n; i++)
		{
			if(S2.S[S2.top].top==(S2.S[S2.top]).size-1)
			{
				cout<<"Stack is full";
			}
			else
			{
				S2.S[S2.top].top++;
				S2.S[S2.top].ele[S2.S[S2.top].top]=S1.ele[i];
			}
		}
		S2.n[S2.top]=n;
	}
}
void popstack(stackofstack &S2)
{
	if(S2.top==-1)
		cout<<"Stack of stack is empty";
	else
	{
		for(int i=S2.n[S2.top]-1; i>=0; i--)
		{
			cout<<S2.S[S2.top].ele[i]<<" ";
		}
		S2.top--;
	}
}
void display(stack S)
{
	for(int i=S.top; i>=0; i--)
		cout<<S.ele[i]<<" ";
}
void displaysos(stackofstack S2)
{
	cout<<endl;
	for(int i=S2.top; i>=0; i--)
	{
		display(S2.S[i]);
	}
}
int main()
{
	int x;
	int n;
	stackofstack sos;
	sos.top=-1;
	sos.size=10;
	for(int j=0; j<10; j++)
	{
		sos.S[j].top=-1;
		sos.S[j].size=10;
	}
	int choice;
	do
	{
		cout<<"\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Number of elements? ";
					cin>>n;
					stack S;
					S.top=-1;
					S.size=10;
					for(int i=0; i<n; i++)
					{
						cout<<"Element? ";
						cin>>x;
						pushint(S, x);
					}
					pushstack(sos, S, n);
					break;
			case 2: popstack(sos);
					break;
			case 3: displaysos(sos);
					break;
		}
	}while(choice!=4);
	return 0;
}
