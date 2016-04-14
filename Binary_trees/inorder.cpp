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
void inorder(BTPTR T)
{
	stack S; S.top=-1; S.size=50;
	btnode *cur=T;
	int done=0;
	while(!done)
	{
	if(cur!=NULL) 
	{
		push(S, cur);
		cur=cur->lchild;
	}
	else
	{
	if(S.top!=-1)
	{
		cur=pop(S);
		cout<<cur->data<<"  ";
		cur=cur->rchild;		
	}
	else done=1;
	}
	}
}
void inorder2(BTPTR T)
{
	if(T==NULL) return;
	else
	{
		inorder2(T->lchild);
		cout<<T->data<<"  ";
		inorder2(T->rchild);
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
	/*while(T->lchild!=NULL)
	T=T->lchild;
	cout<<endl<<T->data<<"  ";
	T=B;
	while(T->rchild!=NULL)
	T=T->rchild;
	cout<<T->data;*/
	inorder(T);
	cout<<endl;
	T=B;
	inorder2(T);
	return 0;
}
