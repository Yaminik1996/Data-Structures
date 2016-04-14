#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *L, *T, *P;
struct stack
{
	int ele[10];
	int top;
	int size;
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
	stack S1;
	S1.size=10;
	S1.top=-1;
	L=new(node);
	int d=0;
	cout<<"Enter element";
	cin>>d;
	L->data=d;
	L->next=NULL;
	T=L;
	char ch='y';
	while(ch=='y')
	{
		cout<<"Enter element";
		cin>>d;
		T->next=new(node);
		T=T->next;
		T->data=d;
		T->next=NULL;
		cout<<"More?";
		cin>>ch;
	}
	cout<<endl;
	T=L;
	P=L;
	int flag=0;
	while(T->next!=NULL)
	{
		T=T->next;
		P=P->next;
		T=T->next;
		push(S1, P->data);
	}
	pop(S1);
	P=P->next;
	while(P->next!=NULL)
	{
		if(gettop(S1)==P->data)
		{
			pop(S1);
			P=P->next;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag) cout<<"NO";
	else cout<<"YES";
	return 0;
}
