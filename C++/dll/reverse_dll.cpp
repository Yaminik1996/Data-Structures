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
	struct dnode *P1, *P2;
	P1=D;
	P2=T;
//	cout<<P1->data<<P2->data;
	while(P1->right!=P2&&P1!=P2)
	{
		int x=P1->data;
		P1->data=P2->data;
		P2->data=x;
		P1=P1->right;
		P2=P2->left;
	}
	T=D;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->right;
	}
	return 0;
}
