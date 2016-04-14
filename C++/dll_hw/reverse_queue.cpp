#include<iostream>
using namespace std;
struct queue
{
	int s;
	int ele[50];
	int f;
	int r;
};
struct stack
{
	int a[100];
	int top;
	int size;
};
void push(stack &S, int x)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
		S.a[++S.top]=x;
}
int pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
		return S.a[S.top--];
}
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
void revq(queue &Q, stack &S)
{
	while(Q.f!=-1)
	{
		push(S, deq(Q));
	}
	while(S.top!=-1)
	{
		enq(Q, pop(S));
	}
}
int main()
{
	queue Q;
	Q.f=-1;
	Q.r=-1;
	Q.s=50;
	stack S;
	S.top=-1;
	S.size=50;
	int ch, d;
	do
	{
		cout<<"1. ENQUEUE 2. DEQUEUE 3. EXIT";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter data ";
			cin>>d;
			enq(Q, d);
		}
		else if(ch==2)
		{
			cout<<deq(Q);
		}
	}while(ch!=3);
	revq(Q, S);
	while(Q.f!=-1)
	{
		cout<<deq(Q)<<" ";
	}
	return 0;
}
