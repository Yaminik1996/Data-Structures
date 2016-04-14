#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *L, *T, *T2;
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
		if(d!=-1)	T->data=d;
		T->next=NULL;
	}
	T=L;
	T2=new(node);
	T2=L;
	while(T2->next->next!=NULL)
	{
		T=T->next;
		T2=T2->next->next;
	}
	cout<<T->data;
	return 0;
}
