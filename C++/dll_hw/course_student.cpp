#include<iostream>
using namespace std;
struct Rnode
{
	int roll;
	Rnode *snext;
	char name;
	Rnode *cnext;
	Rnode *next;
};
struct snode
{
	int roll;
	Rnode *cnext;
};
struct cnode
{
	char name;
	Rnode *snext;
};
int main()
{
	int roll;
	char name;
	snode S[50];
	cnode C[50];
	Rnode *R=new(Rnode);
	cout<<"Enter roll number : ";
	cin>>roll;
	cout<<"Enter course name : ";
	cin>>name;
	int i=0;
	S[i].roll=roll; S[i].cnext=R;
	C[i].name=name; C[i].snext=R;
	R->roll=roll;
	R->name=name;
	R->snext=NULL;
	R->cnext=NULL;
	R->next=NULL;
	Rnode *T=R, *P=NULL;
	char m='y';
	int scount=1, ccount=1, flag;
	do
	{
		flag=0;
		cout<<"Enter roll number : ";
		cin>>roll;
		cout<<"Enter course name : ";
		cin>>name;
		T->next=new(Rnode);
		T=T->next;
		T->name=name;
		T->roll=roll;
		T->cnext=NULL; T->snext=NULL;
		for(int j=0; j<scount; j++)
		{
			if(S[j].roll==roll)
			{
				P=S[j].cnext;
				flag=1;
			}
		}
		if(flag==1)
		{
		while(P->cnext!=NULL)
		{
			P=P->cnext;
		}
		P->cnext=new(Rnode);
		P->cnext=T;
		}
		else if(flag==0)
		{
			++scount;
			S[scount].roll=roll;
			S[scount].cnext=T;
		}
		flag=0;
		for(int j=0; j<ccount; j++)
		{
			if(C[j].name==name)
			{
				P=C[j].snext;
				flag=1;
			}
		}
		if(flag==1)
		{
		while(P->snext!=NULL)
		{
			P=P->snext;
		}
		P->snext=new(Rnode);
		P->snext=T;
		}
		else if(flag==0)
		{
			++ccount;
			C[ccount].name=name;
			C[ccount].snext=T;
		}
		cout<<"More students ? ";
		cin>>m;
	}while(m=='y');
	T=R;
	cout<<"Enter the roll number of student whose details you want ";
	cin>>roll;
	for(int j=0; j<scount; j++)
	{
		if(S[j].roll==roll)
		{
			T=S[j].cnext;
			while(T!=NULL)
			{
				cout<<T->name<<"  ";
				T=T->cnext;
			}
			break;
		}
		cout<<"No such roll number ";
	}
	cout<<endl;
	T=R;
	cout<<"Enter the name of the course whose details you want ";
	cin>>name;
	for(int j=0; j<ccount; j++)
	{
		if(C[j].name==name)
		{
			T=C[j].snext;
			while(T!=NULL)
			{
				cout<<T->roll<<"  ";
				T=T->snext;
			}
			break;
		}
		cout<<"No such course ";
	}
	return 0;
}
