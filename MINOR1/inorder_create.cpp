#include<iostream>
using namespace std;
struct node
{
	int data;
	node *lchild;
	node *rchild;
};
node* create(int A[], int beg, int end)
{
	int i_index=(beg+end)/2;
	if(beg>end) return NULL;
	node *tree=new(node);
	tree->data=A[i_index];
	//cout<<tree->data<<"\t";
	if(beg==end) 
	{
		tree->lchild=NULL;
		tree->rchild=NULL;
		return tree;
	}
	tree->lchild=create(A, beg, i_index-1);
	tree->rchild=create(A, i_index+1, end);
	return tree;
}
void inorder(node *t)
{
	if(t==NULL) return;
	inorder(t->lchild);
	cout<<t->data<<"\t";
	inorder(t->rchild);
}
int main()
{
	node *L, *T;
	int A[1000], i=0;
	char yes='y';
	while(yes=='y'||yes=='Y')
	{
		cin>>A[i++];
		cin>>yes;
	}
	int end=--i;
	//cout<<end;
	int beg=0;
	L=new(node);
	T=new(node);
	T=L;
	T=create(A, beg, end);
	inorder(T);
	return 0;
}
