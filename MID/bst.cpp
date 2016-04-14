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
int main()
{
	int d;
	BSTPTR B, T;
	B=new(btnode);
	int A[100], i=0;
	do
	{
		cout<<"Enter data element (-1 to end)";
		cin>>A[i];
		i++;
	}
	while(A[i-1]!=-1);
	int size=i;
	B->data=A[0];
	B->lchild=NULL;
	B->rchild=NULL;
	i=1;
	while(i<size-1)
	{
		T=B;
		insert(T, A[i]);
		i++;
	}
	T=B;
	inorder(T);
	return 0;
}
