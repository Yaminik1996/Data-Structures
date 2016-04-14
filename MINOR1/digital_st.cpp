#include<iostream>
#include<string.h>
using namespace std;
struct dnode
{
	struct dnode *lchild;
	char a[100];
	struct dnode *rchild;
};
void insert(dnode * D, char a[100], int i)
{
	if(!strcmp(D->a, a)) return;
	if(a[i]=='0')
	{
		if(D->lchild) insert(D->lchild, a, ++i);
		else
		{
			D->lchild=new(dnode);
			D=D->lchild;
			D->lchild=NULL;
			D->rchild=NULL;
			strcpy(D->a, a);
		}
	}
	else
	{
		if(D->rchild) insert(D->rchild, a, ++i);
		else
		{
			D->rchild=new(dnode);
			D=D->rchild;
			D->lchild=NULL;
			D->rchild=NULL;
			strcpy(D->a, a);
		}
	}
}
void inorder(dnode *D)
{
	if(D)
	{
		inorder(D->lchild);
		cout<<D->a<<endl;
		inorder(D->rchild);
	}
}
int main()
{
	char a[100];
	char yes='y';
	dnode *D=new(dnode), *T=new(dnode);
	cin>>a;
	strcpy(D->a, a);
	D->lchild=NULL;
	D->rchild=NULL;
	cout<<"More ? ";
	cin>>yes;
	while(yes=='y'||yes=='Y')
	{
		T=D;
		cin>>a;
		insert(T, a, 0);
		cout<<"More ? ";
		cin>>yes;
	}
	T=D;
	inorder(T);
	return 0;
}
