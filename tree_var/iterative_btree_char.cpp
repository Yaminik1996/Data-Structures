#include<iostream>
using namespace std;
struct btnode
{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
};
typedef struct btnode *BTPTR;
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
void insert(BTPTR T)
{
	char lc, rc;
	stack S;S.top=-1;S.size=50;
	do
	{
		char d;
		cout<<"Enter data ";
		cin>>d;
		T->data=d;
		T->lchild=NULL;
		T->rchild=NULL;
		cout<<"Left child ? ";
		cin>>lc;
		cout<<"Right child ? ";
		cin>>rc;
		if(lc=='Y'&&rc=='Y')
		{
			push(S, T);
			cout<<S.top<<"  ";
			T->lchild=new(btnode);
			T->rchild=new(btnode);
			T=T->lchild;
		}
		else if(lc!='Y'&&rc!='Y')
		{
			T->lchild=NULL;
			T->rchild=NULL;
			if(S.top!=-1)
			{
			T=pop(S);
			cout<<S.top<<"  ";
			T=T->rchild;
			}
			else
			{
			break;
			}
		}
		else if(lc=='Y'&&rc!='Y')
		{
			T->rchild=NULL;
			T->lchild=new(btnode);
			T=T->lchild;
		}
		else
		{
			T->lchild=NULL;
			T->rchild=new(btnode);
			T=T->rchild;
		}
}while(lc=='Y'||rc=='Y'||S.top!=-1||T!=NULL);
}
void print1(BTPTR T)
{
	if(T==NULL) cout<<"  ";
	else
	{
		print1(T->lchild);
		cout<<T->data;
		print1(T->rchild);
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
	while(T->lchild!=NULL)
	T=T->lchild;
	cout<<endl<<T->data<<"  ";
	T=B;
	while(T->rchild!=NULL)
	T=T->rchild;
	cout<<T->data;
	T=B;
	cout<<endl;
	print1(T);
	return 0;
}
