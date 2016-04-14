#include<iostream>
using namespace std;
struct node
{
	int co;
	int exp;
	int flag;
	struct node *next;
};
int main()
{
	int co, i=0;
	int exp;
	struct node *L1, *L2, *T;
	cout<<"Enter first polynomial ";
	cin>>co;
	cin>>exp;
	L1=new(node);
	L1->co=co;
	L1->exp=exp;
	L1->next=NULL;
	T=L1;
	char choice='y';
	do
	{
		cout<<"Enter next term ";
		cin>>co;
		cin>>exp;
		T->next=new(node);
		T=T->next;
		T->co=co;
		T->exp=exp;
		T->next=NULL;
		cout<<"More ?";
		cin>>choice;
	}while(choice=='y');
	cout<<"Enter second polynomial ";
	cin>>co;
	cin>>exp;
	L2=new(node);
	L2->co=co;
	L2->exp=exp;
	L2->next=NULL;
	T=L2;
	choice='y';
	do
	{
		cout<<"Enter next term ";
		cin>>co;
		cin>>exp;
		T->next=new(node);
		T=T->next;
		T->co=co;
		T->exp=exp;
		T->next=NULL;
		cout<<"More ?";
		cin>>choice;
	}while(choice=='y');
	cout<<endl;
	struct node *T1=L1;
	struct node *T2=L2;
	while(T1!=NULL)
	{
		T2=L2;
		co=T1->co;
		exp=T1->exp;
		while(T2!=NULL)
		{
			if(exp==T2->exp)
			{	++i;
				if(i==1)
				{
					cout<<(co+(T2->co))<<"X^"<<exp;
				}
				else
				cout<<" + "<<(co+(T2->co))<<"X^"<<exp;
				T1->flag=1;
				T2->flag=1;
			}
			T2=T2->next;
		}
		T1=T1->next;
	}
	T1=L1;
	T2=L2;
	while(T1!=NULL)
	{
		if(T1->flag!=1)
			cout<<" + "<<T1->co<<"X^"<<T1->exp;
		T1=T1->next;
	}
	while(T2!=NULL)
	{
		if(T2->flag!=1)
			cout<<" + "<<T2->co<<"X^"<<T2->exp;
		T2=T2->next;
	}
	return 0;
}
