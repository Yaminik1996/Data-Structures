#include<iostream>
using namespace std;
struct btnode
{
	struct btnode *lchild;
	int data;
	struct btnode *rchild;
};
typedef struct btnode *BSTPTR;
void insert(BSTPTR T, int d)
{
	if(d<T->data)
	{
		if(T->lchild!=NULL)
		{
			T=T->lchild;
			insert(T, d);
		}
		else
		{
			T->lchild=new(btnode);
			T=T->lchild;
			T->data=d;
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
	else
	{
		if(T->rchild!=NULL)
		{
			T=T->rchild;
			insert(T, d);
		}
		else
		{
			T->rchild=new(btnode);
			T=T->rchild;
			T->data=d;
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
}
struct stack
{
	char infix[50];
	int top;
	int size;
};
void inorder(BSTPTR T)
{
	if(T==NULL) cout<<"  ";
	else
	{
		inorder(T->lchild);
		cout<<T->data;
		inorder(T->rchild);
	}
}
void preorder(BSTPTR T)
{
	if(T==NULL) return;
	cout<<T->data<<"  ";
	if(T->lchild)	preorder(T->lchild);
	if(T->rchild)	preorder(T->rchild);
}
int main()
{
	int d;
	BSTPTR B, T;
	B=new(btnode);
	cout<<"Enter data element ";
	cin>>d;
	B->data=d;
	B->lchild=NULL;
	B->rchild=NULL;
	do
	{
		cout<<"Enter data element (-1 to end)";
		cin>>d;
		T=B;
		if(d!=-1)
		insert(T, d);
	}while(d!=-1);
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
	inorder(T);
	cout<<endl;
	T=B;
	preorder(T);
	return 0;
}
