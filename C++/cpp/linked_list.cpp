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
	T=L;
	while(T->next!=NULL)
	{
		cout<<T->data<<"  ";
		T=T->next;
	}
	cout<<T->data;
	cout<<"Enter the element to be found";
	int ele;
	cin>>ele;
	T=L;
	int i=0;
	while(T!=NULL)
	{
		if(T->data==ele)
		{
			cout<<"Found at "<<i+1;
			i=-1;
			break;
		}
		else
		{	i++;
			T=T->next;
		}
	}
	if(i!=-1)	cout<<"Not found";
	return 0;
}
