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
	cout<<"Enter the element to be entered in front ";
	cin>>d;
	T=new(dnode);
	T->data=d;
	T->right=D;
	D->left=T;
	T->left=NULL;
	D=T;
	T=D;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->right;
	}
	return 0;
}
