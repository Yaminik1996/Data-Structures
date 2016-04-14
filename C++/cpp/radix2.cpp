#include<iostream>
#include<math.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct rnode
{
	int bno;
	struct rnode *rnext;
	struct node *next;
};
int main()
{
	char y='y';
	rnode *C, *D;
	C=NULL;D=NULL;
	struct node *L, *T;
	cout<<"Enter element ";
	L=new(node);
	T=L;
	int ele;
	cin>>ele;
	T->data=ele;
	T->next=NULL;
	while(y=='y')
	{
		cout<<"Enter element ";
		cin>>ele;
		T->next=new(node);
		T=T->next;
		T->data=ele;
		T->next=NULL;
		cout<<"More?";
		cin>>y;
	}
	for(int j=0; j<3; j++)
	{
	C=new(rnode);
	D=C;
	C->bno=0;
	C->next=NULL;
	C->rnext=NULL;
	for(int k=1; k<10; k++)
	{
		D->rnext=new(rnode);
		D=D->rnext;
		D->bno=k;
		D->rnext=NULL;
		D->next=NULL;
	}
	T=L;
	for(int k=0; k<j-1; k++)
	{
		T=T->next;
	}
	node *P;
	while(T!=NULL)
	{
		int k=T->data;
		k=k/pow(10, j);
		k=k%10;
		D=C;
		for(int i=0; i<k; i++)
		{
			D=D->rnext;
		}
		if(D->next==NULL)
		{
		D->next=new(node);
		P=D->next;
		}
		else
		{
			P=D->next;
			while(P->next!=NULL)
			{
				P=P->next;
			}
			P->next=new(node);
			P=P->next;
		}
		P->data=T->data;
		P->next=NULL;
		T=T->next;
	}
	D=C;
	L->next=NULL;
	T=L;
	while(D!=NULL)
	{
		P=D->next;
		while(P!=NULL)
		{
			T->next=new(node);
			T=T->next;
			T->data=P->data;
			cout<<P->data<<" ";
			P=P->next;
			T->next=NULL;
		}
		D=D->rnext;
	}
	T=L->next;
	cout<<endl;
	while(T!=NULL)
	{	cout<<T->data<<" ";
		T=T->next;
	}
	cout<<endl;
	}
	cout<<endl;
	return 0;
}
