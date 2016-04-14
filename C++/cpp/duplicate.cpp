#include<iostream>
using namespace std;
struct node
{
	char data;
	struct node *next;
	struct node *rnext;
};
int main()
{
	struct node *L, *T;
	L=new(node);
	cout<<"Enter data for first ";
	char ch;
	cin>>ch;
	L->data=ch;
	L->next=NULL;
	L->rnext=NULL;
	char more='y';
	T=L;
	do
	{
		T->next=new(node);
		cout<<"Enter data ";
		cin>>ch;
		T=T->next;
		T->data=ch;
		T->next=NULL;
		T->rnext=NULL;
		cout<<"More?";
		cin>>more;
	}while(more=='Y');
	T=L;
	/*while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;	
	}*/
	T=L;
	node *P=L;
	while(T!=NULL)
	{
		for(int i=0; i<2; i++)
			P=P->next;
		T->rnext=new(node);
		T->rnext=P;
		T=T->next;
		P=L;
		for(int i=0; i<4; i++)
			P=P->next;
		T->rnext=new(node);
		T->rnext=P;
		T=T->next;
		T=T->next;
		P=L;
		for(int i=0; i<7; i++)
			P=P->next;
		T->rnext=new(node);
		T->rnext=P;
		T=T->next;
		T=T->next;
		P=L;
		for(int i=0; i<7; i++)
			P=P->next;
		T->rnext=new(node);
		T->rnext=P;
		T=T->next;
		T=T->next;
		T=T->next;
	}
	T=L;
	cout<<endl;
	/*while(T!=NULL)
	{
		if(T->rnext!=NULL)
			cout<<T->data<<" "<<cout<<T->rnext->data<<endl;
		T=T->next;
	}*/
	node *A, *B, *C;
	A=NULL;
	A=new(node);
	T=L;
	A->data=T->data;
	T=T->next;
	A->next=NULL;
	B=A;
	while(T!=NULL)
	{
		B->next=new(node);
		B=B->next;
		B->data=T->data;
		B->next=NULL;
		T=T->next;
	}
	T=A;/*
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;
	}*/
	return 0;
}
