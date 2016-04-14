#include<iostream>
using namespace std;
struct dnode
{
	dnode *left;
	int data;
	dnode *right;
	dnode *random;
};
int find(dnode *L, dnode *T)
{
	dnode *P=L;
	int i=0;
	while(P!=T)
	{
		++i;
		P=P->right;
	}
	return i;
}
int main()
{
	struct dnode *L, *T, *P;
	L=new(dnode);
	cout<<"Enter data for first ";
	int num;
	cin>>num;
	L->data=num;
	L->left=NULL;
	L->right=NULL;
	L->random=NULL;
	char more='y';
	T=L;
	do
	{
		T->right=new(dnode);
		cout<<"Enter data ";
		T->right->left=T;
		cin>>num;
		T=T->right;
		T->data=num;
		T->right=NULL;
		T->random=NULL;
		cout<<"More?";
		cin>>more;
	}while(more=='Y'||more=='y');
	T=L;
	char yes;
	cout<<"Enter nodes for links ";
	while(T!=NULL)
	{
		cout<<"Enter link for "<<T->data;
		cin>>yes;
		if(yes=='y'||yes=='Y')
		{
			cin>>num;
			P=L;
			for(int i=0; i<num-1; i++)
				P=P->right;
			T->random=new(dnode);
			T->random=P;
		}
		T=T->right;
	}
	T=L;
	while(T!=NULL)
	{
		if(T->random==NULL)
		{
		;
		}
		else
		{
			dnode *X=T->random;
			cout<<"Cycle is : ";
			int x=find(L, X);
			int t=find(L, T);
			if(x<t)
			{
				P=X;
				while(P!=T)
				{
					cout<<P->data<<"->"; P=P->right;
				}
				cout<<T->data<<"->"<<X->data;
			}
			else if(x>t)
			{
				P=X;
				while(P!=T)
				{
					cout<<P->data<<"->"; P=P->left;
				}
				cout<<T->data<<"->"<<X->data;
			}
		}
		T=T->right;
	}
	return 0;
}
