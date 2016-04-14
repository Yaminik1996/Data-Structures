#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *L, *T, *P;
int main()
{
	L=new(node);
	int d=0;
	cout<<"Enter element";
	cin>>d;
	L->data=d;
	L->next=NULL;
	T=L;
	while(d!=-1)
	{
		cout<<"Enter element";
		cin>>d;
		T->next=new(node);
		T=T->next;
		T->data=d;
		T->next=NULL;
	}
	cout<<endl;
	T=L;
	P=L;
	while(T->next!=NULL)
	{
		T=T->next;
		P=P->next;
		T=T->next;
	}
	cout<<"Middle element is :"<<P->data;
	return 0;
}
