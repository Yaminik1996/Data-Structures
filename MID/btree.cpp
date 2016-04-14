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
void print2(BTPTR T)
{
	if(T==NULL) cout<<"  ";
	else
	{
		print2(T->lchild);
		print2(T->rchild);
		cout<<T->data<<"   ";
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
	cout<<endl;
	print2(T);
	return 0;
}
