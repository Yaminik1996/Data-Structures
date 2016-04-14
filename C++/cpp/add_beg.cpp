#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *L, *T;
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
	while(T->next!=NULL)
	{
		cout<<T->data<<"  ";
		T=T->next;
	}
	cout<<"Enter element to be added in beginning";
	int beg;
	cin>>beg;
	T=new(node);
	T->data=beg;
	T->next=L;
	L=T;
	cout<<endl;
	T=L;
	while(T->next!=NULL)
	{
		cout<<T->data<<"  ";
		T=T->next;
	}
	return 0;
}
