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
		cout<<"Left child ? (Enter / for NO) ";
		cin>>d;
		if(d=='/') T->lchild=NULL;
		else
		{
			cout<<"Into the left subtree ";
			T->lchild=new(btnode);
			insert(T->lchild);
		}
		cout<<"Right child ? (Enter / for NO) ";
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
	btnode * B[50];
	int top;
	int size;
};
void push(stack &S, btnode *B)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
		S.B[++S.top]=B;
}
btnode * pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
		return S.B[S.top--];
}
void postorder(btnode *T)
{
	stack S1, S2;
	S1.top=-1;
	S1.size=50;
	S2.top=-1;
	S2.size=50;
	push(S1, T);
	btnode *A;
	while(S1.top!=-1)
	{
		A=pop(S1);
		push(S2, A);
		if(A->lchild) push(S1, A->lchild);
		if(A->rchild) push(S1, A->rchild);
	}
	while(S2.top!=-1)
	{
		A=pop(S2);
		cout<<A->data<<"  ";
	}
}
void postorder1(btnode * T)
{
	if(!T) return;
	if(T->lchild)	postorder1(T->lchild);
	if(T->rchild)   postorder1(T->rchild);
	cout<<T->data<<"  ";
}
int main()
{
	int d;
	BTPTR B, T;
	B=new(btnode);
	T=B;
	insert(T);
	T=B;
	postorder(T);
	cout<<endl;
	postorder1(T);
	return 0;
}
