#include<iostream>
using namespace std;
struct dnode
{
	struct dnode * left;
	int data;
	struct dnode *right;
};
int main()
{
	struct dnode *D, *T;
	cout<<"Enter data element ";
	int d;
	cin>>d;
	D=new(dnode);
	D->data=d;
	D->left=NULL;
	D->right=NULL;
	T=D;
	char m='y';
	do
	{
	cout<<" Enter next data element ";
	cin>>d;
	T->right=new(dnode);
	T->right->left=T;
	T=T->right;
	T->data=d;
	T->right=NULL;
	cout<<"More? ";
	cin>>m;
	}while(m=='y');
	cout<<"Enter the node element before which you want to add element ";
	cin>>d;
	T=D;
	while(T->right->data!=d)
		T=T->right;
	dnode *P;
	cout<<"Enter data element ";
	cin>>d;
	P=new(dnode);
	P->data=d;
	P->right=T->right;
	P->right->left=P;
	P->left=T;
	T->right=P;
	T=D;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->right;
	}
	return 0;
}
