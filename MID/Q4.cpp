#include<iostream>
using namespace std;
struct node
{
	char data;
	struct node * next;
};
struct queue
{
	struct node *front;
	struct node *rear;
};
void enq(queue &Q, char c)
{
	if(!Q.front&&!Q.rear)
	{
		Q.front=new(node);
		Q.rear=new(node);
		Q.front->data=c;
		Q.rear=Q.front;
		Q.rear->next=NULL;
	}
	else
	{
		Q.rear->next=new(node);
		Q.rear=Q.rear->next;
		Q.rear->data=c;
		Q.rear->next=NULL;
	}
}
char deq(queue &Q)
{
	if(!Q.front) return '#';
	else if(Q.front==Q.rear)
	{
		node *T=Q.front;
		Q.front=NULL;
		Q.rear=NULL;
		return T->data;
	}
	else
	{
		node * T = Q.front;
		Q.front=Q.front->next;
		T->next=NULL;
		return T->data;
	}
}
struct stack
{
	char A[50];
	int top;
	int size;
};
void push(stack &S, char x)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
		S.A[++S.top]=x;
}
char pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
		return S.A[S.top--];
}
int palindrome(queue Q1, queue Q2)
{
	stack S1, S2, S3;
	S1.top=-1; S1.size=50;
	S2.top=-1; S2.size=50;
	S3.top=-1; S3.size=50;
	while(Q1.front)
	{
		char a=deq(Q1);
		push(S1, a);
		push(S2, a);
		enq(Q2, a);
	}
	while(S1.top!=-1)
	{
		push(S3, pop(S1));
	}
	int flag=0;
	while(S2.top!=-1)
	{
		if(pop(S2)!=pop(S3))
		{
			flag=1;
			break;
		}
	}
	while(Q2.front)
	{
		enq(Q1, deq(Q2));
	}
	if(flag) return 0;
	else return 1;
}
int main()
{
	queue Q;
	Q.front=NULL;
	Q.rear=NULL;
	char yes='y', c;/*
	cout<<"Enter character ";
	cin>>c;
	Q.front=new(node);
	Q.rear=new(node);
	Q.front->data=c;
	Q.rear=Q.front;
	Q.rear->next=NULL;*/
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter character ";
		cin>>c;
		enq(Q, c);
		cout<<"More(y/n) ? ";
		cin>>yes;
	}
	/*while(Q.front)
	{
		char a=deq(Q);
		cout<<a<<"  "; 
	}*/
	queue Q2;
	Q2.front=NULL;
	Q2.rear=NULL;
	cout<<"   "<<palindrome(Q, Q2);
	return 0;
}
