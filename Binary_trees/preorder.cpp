#include<iostream>
using namespace std;
struct btnode
{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
};
typedef struct btnode *BTPTR;
void insert(BTPTR T)
{
	if(T!=NULL)
	{
		char d;
		cout<<"Enter data ";
		cin>>d;
		T->data=d;
		cout<<"Left child for "<<T->data<<"? (Enter / for NO) ";
		cin>>d;
		if(d=='/') T->lchild=NULL;
		else
		{
			cout<<"Into the left subtree ";
			T->lchild=new(btnode);
			insert(T->lchild);
		}
		cout<<"Right child "<<T->data<<"? (Enter / for NO) ";
		cin>>d;
		if(d=='/') T->rchild=NULL;
		else
		{
			cout<<"Into the right subtree ";
			T->rchild=new(btnode);
			insert(T->rchild);
		}
	}
}
struct stack
{
	btnode *A[50];
	int top;
	int size;
};
void push(stack &S, btnode *x)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
		S.A[++S.top]=x;
}
btnode * pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
		return S.A[S.top--];
}
void preorder(BTPTR T)
{
	stack S; S.top=-1; S.size=50;
	if(T==NULL) return;
	push(S, T);
	while(S.top!=-1)
	{
		btnode *P=pop(S);
		cout<<P->data<<"  ";
		if(P->rchild)	push(S, P->rchild);
		if(P->lchild)	push(S, P->lchild);
	}
}
void preorder2(BTPTR T)
{
	if(T==NULL) return;
	else
	{
		cout<<T->data<<"  ";
		preorder2(T->lchild);
		preorder2(T->rchild);
	}
}
int main()
{
	int d;
	BTPTR B, T;
	B=new(btnode);
	T=B;
	insert(T);
	T=B;
	preorder(T);
	cout<<endl;
	T=B;
	preorder2(T);
	return 0;
}
