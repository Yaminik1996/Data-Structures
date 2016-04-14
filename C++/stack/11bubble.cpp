#include<iostream>
using namespace std;
struct stack
{
	int top;
	int size;
	int ele[50];
};
void push(stack &S, int x)
{
	++S.top;
	S.ele[S.top]=x;
}
int pop(stack &S)
{
	if(S.top==-1)
		return -1;
	else return S.ele[S.top--];
}
int gettop(stack &S)
{
	if(S.top==-1)
		return -1;
	else return S.ele[S.top];
}
int main()
{
	int a, b, x;
	stack S1;
	stack S2;
	S1.top=-1;
	S2.top=-1;
	S1.size=25;
	S2.size=25;
	char choice='y';
	while(choice=='y')
	{
		cout<<"Enter element : ";
		cin>>x;
		push(S1, x);
		cout<<"More ?";
		cin>>choice;
	}
	do
	{
		b=pop(S1);
		do
		{
			a=pop(S1);
			if(a<b)
				push(S2, a);
			else if(a>=b)
			{
				int t=a;
				a=b;
				b=t;
				push(S2, a);
			}
		}while(gettop(S1)!=-1);//b is largest
		do
		{
			a=pop(S2);
			push(S1, a);
		}while((gettop(S2)!=-1)&&(gettop(S2)<b));
		push(S2, b);
	}while(gettop(S1)!=-1);
	cout<<"Sorted stack is : ";
	for(int i=0; i<=S2.top; i++)
	{
		cout<<S2.ele[i]<<" ";
	}
	return 0;
}
