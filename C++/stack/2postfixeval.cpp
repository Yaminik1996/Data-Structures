#include<iostream>
using namespace std;
struct stack
{
	int size;
	int tag;
	int pe[20];
	int top;
};
void push(stack &S, int x)
{
		if(S.top==S.size-1)
		cout<<"Stack is full";
		else
		S.pe[++S.top]=x;
}
int pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
		return S.pe[S.top--];
}
int main()
{
	stack S;
	int t, a, b;
	S.top=-1;
	S.size=25;
	do
	{
		cout<<"Enter the next element (press 1 for operand, 2 for operator, 0 to end) :\n";
		cin>>t;
		if(t==1)
		{
			cout<<"Enter operand : ";
			int x;
			cin>>x;
			push(S, x);
		}
		else if(t==2)
		{
			cout<<"Enter operator : ";
			char o;
			cin>>o;
            a=pop(S);
            b=pop(S);
            switch(o)
            {
            case '+':
                push(S, (a+b));
                break;
            case '-':
                push(S, (a-b));
                break;
            case '*':
                push(S, (a*b));
                break;
            case '/':      
                push(S, (a/b));
                break;
            }
    	}
        else if(t==0)
        {
		   	cout<<"The answer is : "<<pop(S);
		}
	}while(t!=0);
	return 0;
}
