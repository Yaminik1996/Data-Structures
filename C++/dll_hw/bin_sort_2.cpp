#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *right;
};
struct lnode
{
	int bno;
	struct lnode *right;
	struct node *up;
};
void swap(int &a, int &b)
{
	int x=a;
	a=b;
	b=x;
}
int main()
{
	lnode *D, *T, *Q;
	D=new(lnode);
	Q=new(lnode);
	node *P=new(node);
	cout<<"Enter data element ";
	int d;
	cin>>d;
	char ch='y';
	D->bno=d/10;
	D->up=new(node);
	D->up->data=d%10;
	D->up->right=NULL;
	D->right=NULL;
	T=D;
	do
	{
		cout<<"More ? ";
		cin>>ch;
		if(ch=='y'||ch=='Y')
		{
			cout<<"Enter data element ";
			cin>>d;
			T->right=new(lnode);
			P=T->up;
			T=T->right;
			T->bno=d/10;
			T->right=NULL;
			T->up=new(node);
			P->right=T->up;
			T->up->data=d%10;
			T->up->right=NULL;
		}
	}while(ch=='y'||ch=='Y');
	T=D;
	while(T!=NULL)
	{
		if(T->right==NULL) break;
		else
		{
		Q=T->right;
		while(Q!=NULL)
		{
			if(Q->bno<T->bno)
			{
				swap(Q->bno, T->bno);
				swap(Q->up->data, T->up->data);
			}
			Q=Q->right;
		}
		T=T->right;
		}
	}
	T=D;
	while(T!=NULL)
	{
		int bno=T->bno;
		if(T->right!=NULL)
		{
		Q=T->right;
		if(Q->bno!=bno) 
		{
		T=T->right;
		}
		else if(Q->bno==bno)
		{
		while(Q->bno==bno)
		{
			if((Q->up->data)<(T->up->data))
			{
				swap(Q->up->data, T->up->data);
			}
			if(Q->right!=NULL)
				Q=Q->right;
			else break;
		}
		T=T->right;
		}
		}
		else break;
	}
	cout<<"Which list do you wish to see? \n 1. LOWER DATA LIST 2. UPPER DATA LIST 3. SORTED NUMBERS";
	int choice;
	cin>>choice;
	if(choice==1)
	{
		T=D;
		while(T!=NULL)
		{
			if(T->right==NULL)
			{
				cout<<T->bno;
				break;
			}
			else if(T->right->bno==T->bno)
			{;
			}
			else cout<<T->bno<<" ";
			T=T->right;
		}
	}
	else if(choice==2)
	{
		P=D->up;
		while(P!=NULL)
		{
			cout<<P->data<<" ";
			P=P->right;
		}
	}
	else if(choice==3)
	{
		T=D;
		while(T!=NULL)
		{
		int bno=T->bno;
		if(T->right!=NULL)
		{
		Q=T->right;
		if(Q->bno==bno)
		{
		cout<<T->bno<<"  :  "<<T->up->data<<"  ";
		while(Q->bno==bno&&Q!=NULL&&T->bno==bno)
		{
			cout<<Q->up->data<<"  ";
			Q=Q->right;
			T=T->right;
		}
		T=T->right;
		}
		else if(Q==D->right)
		{
			cout<<D->bno<<"  :  "<<D->up->data; T=T->right;
		}
		else if(Q->bno!=bno)
		{
			cout<<T->bno<<"  :  "<<T->up->data<<endl;
			cout<<Q->bno<<"  :  "<<Q->up->data; T=T->right;T=T->right;
		}
		else
		{
			cout<<T->bno<<"  :  "<<T->up->data; T=T->right;
		}
		cout<<endl;
		}
		else {	cout<<T->bno<<"  :  "<<T->up->data; T=T->right;}
		}
	}
	return 0;
}
