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
void print_leaf(BTPTR T)
{
	if(!T) return;
	print_leaf(T->lchild);
	if(!T->lchild&&!T->rchild) cout<<T->data<<"\t";
	print_leaf(T->rchild);
}
void right(BTPTR T)
{
	if(!T) return;
	if(!T->rchild) return;
	right(T->rchild);
	cout<<T->data<<"\t";
}
void boundary(BTPTR T)
{
	BTPTR T1=T;
	while(T1->lchild!=NULL){ cout<<T1->data<<"\t"; T1=T1->lchild;}
	T1=T;
	print_leaf(T1);
	T1=T;
	right(T1->rchild);
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
bool path(BTPTR B, int data, stack &S)
{
	if(!B) return 0;
	if(B->data==data)
	{
		return 1;
	}
	else if(path(B->lchild, data, S)) 
	{
		cout<<"Pushing 2 "<<B->lchild->data;
		push(S, B->lchild);
	}
	else if(path(B->rchild, data, S)) 
	{
		cout<<"Pushing 3 "<<B->rchild->data;
		push(S, B->rchild);
	}
}
int main()
{
	int d;
	BTPTR B, T, P;
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
	int found;
	char data;
	char yes='y';
	T=B;
	cout<<"Boundary traversal is = ";
	boundary(T);
	while(yes=='y'||yes=='Y')
	{
	cout<<"Enter element for finding path ";
	cin>>data;
	stack S1;
	S1.top=0;
	S1.size=50;
	T=B;
	//cout<<path(T, data, S1)<<endl;
	if(path(T, data, S1))
	{
		S1.A[++S1.top]->data=B->data;
		while(S1.top!=-1)
		{
			P=pop(S1);
			cout<<P->data<<"  ";
		}
	}
	cout<<"More?";
	cin>>yes;
	}
	return 0;
}
