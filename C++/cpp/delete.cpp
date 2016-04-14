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
	cout<<"Enter the element which you want to delete";
	int e1;
	cin>>e1;
	T=L;
	while(T->next->data!=e1)
	{
		T=T->next;
	}
	T->next=T->next->next;
	T=L;
	cout<<endl;
	while(T->next!=NULL)
	{
		cout<<T->data<<"  ";
		T=T->next;
	}
	return 0;
}
