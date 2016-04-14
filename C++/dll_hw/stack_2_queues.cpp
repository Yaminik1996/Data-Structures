#include<iostream>
using namespace std;
struct queue
{
	int s;
	int ele[50];
	int f;
	int r;
};
void enq(queue &Q, int d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
int deq(queue &Q)
{
	int p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
struct stack
{
	queue Q1;
	queue Q2;
};
void push(stack &S, int x)
{
	enq(S.Q1, x);
}
int pop(stack &S)
{
	int a;
	while(S.Q1.f!=S.Q1.r)
	{
		a=deq(S.Q1);
		enq(S.Q2, a);
	}
	int p=deq(S.Q1);
	while(S.Q2.f!=-1)
	{	a=deq(S.Q2);
		enq(S.Q1, a);
	}
	return p;
}
void display(stack S)
{
	for(int i=S.Q1.f; i<=S.Q1.r; )
	{	cout<<S.Q1.ele[i]<<" ";
		i=(i+1)%S.Q1.s;
	}
}
int main()
{
	stack S;
	S.Q1.f=-1; S.Q1.r=-1;
	S.Q2.f=-1; S.Q2.r=-1;
	int x, ch;
	do
	{
		cout<<"1. PUSH \n2. POP \n3. DISPLAY \n4. EXIT ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter data element ";
				int x;
				cin>>x;
				push(S, x);
				break;
			case 2: cout<<pop(S);
				break;
			case 3: cout<<endl;
				display(S);
				break;
		}
	}while(ch!=4);
	return 0;
}
