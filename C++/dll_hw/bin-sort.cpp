#include<iostream>
using namespace std;
struct dnode
{
	struct dnode *left;
	int bno;
	int data;
	struct dnode *right;
};
void swap(int &a, int &b)
{
	int x=a;
	a=b;
	b=x;
}
int main()
{
	dnode *D, *T, *P;
	D=new(dnode);
	cout<<"Enter data element ";
	int d;
	cin>>d;
	char ch='y';
	D->bno=d/10;
	D->data=d%10;
	D->left=NULL;
	D->right=NULL;
	T=D;
	do
	{
		cout<<"More ? ";
		cin>>ch;
		if(ch=='y')
		{
			cout<<"Enter data element ";
			cin>>d;
			T->right=new(dnode);
			T->right->left=T;
			T=T->right;
			T->data=d%10;
			T->bno=d/10;
			T->right=NULL;
		}
	}while(ch=='y');
	T=D;
	while(T!=NULL)
	{
		P=T->right;
		while(P!=NULL)
		{
			if(P->bno<T->bno)
			{
				swap(P->data, T->data);
				swap(P->bno, T->bno);
			}
			P=P->right;
		}
		T=T->right;
	}
	T=D;
	while(T!=NULL)
	{
		int bno=T->bno;
		P=T->right;
		if(P==NULL) break;
		else if(P->bno!=bno) T=T->right;
		else if(P->bno==bno)
		{
		while(P->bno==bno&&P!=NULL&&T!=NULL)
		{
			if(P->data<T->data)
			{
				swap(P->data, T->data);
			}
			P=P->right;
		}
		T=T->right;
		}
	}
	T=D;
	while(T!=NULL)
	{
		cout<<T->bno<<T->data<<" ";
		T=T->right;
	}
	return 0;
}
