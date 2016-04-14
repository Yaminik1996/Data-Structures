#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
int main()
{
	int flag=0;
	node *L1, *L2, *T;
	L1=new(node);
	cout<<"Enter data for first node of first linked list ";
	int data;
	cin>>data;
	L1->data=data;
	L1->next=NULL;
	T=L1;
	char choice='y';
	while(choice=='y')
	{
		cout<<"Next data ";
		cin>>data;
		T->next=new(node);
		T=T->next;
		T->data=data;
		T->next=NULL;
		cout<<"More?";
		cin>>choice;
	}
	cout<<"Enter data for first node of second linked list ";
	cin>>data;
	L2=new(node);
	L2->data=data;
	L2->next=NULL;
	T=L2;
	choice='y';
	while(choice=='y')
	{
		cout<<"Next data ";
		cin>>data;
		T->next=new(node);
		T=T->next;
		T->data=data;
		T->next=NULL;
		cout<<"More?";
		cin>>choice;
	}
	cout<<"Which node of first linked list do you want to connect?";
	int n, i;
	cin>>n;
	T=L1;
	for(i=0; i<n-1 ; i++)
	{
		T=T->next;
	}
	node *T2;
	T2=L2;
	while(T2->next!=NULL)
	{
		T2=T2->next;
	}
	T2->next=new(node);
	T2->next=T;
	T=L1;
	T2=L2;
	while(T!=NULL)
	{
		T2=L2;
		while(T2!=NULL)
		{
			if(T==T2)
			{	cout<<"Common node content is : "<<T->data;
				flag=1;
				break;
			}
			else T2=T2->next;
		}
		if(flag) break;
		else T=T->next;
	}
	return 0;
}
