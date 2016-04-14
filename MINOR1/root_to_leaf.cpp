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
void print(btnode *T, char a[50], int i)
{
	if(T==NULL) 
	{
		cout<<"It is NULL ";
		return;
	}
	if(T!=NULL) 
	{
		a[i++]=T->data;
	}
	if(T->lchild==NULL&&T->rchild==NULL) cout<<a<<endl;
	else 
	{
		if(T->lchild)	print(T->lchild, a, i);
		if(T->rchild)	print(T->rchild, a, i);
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
	char a[50]=" ";
	cout<<endl;
	int i=0;
	print(T, a, i);
	cout<<endl;
	return 0;
}
