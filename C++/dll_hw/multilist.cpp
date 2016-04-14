#include<iostream>
using namespace std;
struct stud;
struct course;
struct node;
struct stud
{
	int roll;
	struct node *right;
	struct stud *down;
}*S[10];
struct course
{
	char name;
	struct node *down;
	struct course *right;
}*C[10];
struct node
{
	int tagright;
	union 
	{
		struct node *right;
		struct stud *cnext;
	}Uright;
	int tagdown;
	union
	{
		struct node *down;
		struct course *snext;
	}Udown;
};
struct m
{
	struct course *C;
	struct stud *S;
}M;
int ccount=0;
int main()
{
	char name, yes='y', yes2='y';
	node *P, *Q;
	cout<<"Enter the number of courses ";
	cin>>ccount;
	cout<<"Enter name of course ";
	cin>>name;
	C[0]=new(course);
	C[0]->name=name;
	C[0]->down=NULL;
	C[0]->right=NULL;
	for(int j=1; j<ccount; j++)
	{
		cout<<"Enter name of course ";
		cin>>name;
		C[j]=new(course);
		C[j]->name=name;
		C[j]->right=NULL;
		C[j]->down=NULL;
		C[j-1]->right=new(course);
		C[j-1]->right=C[j];
	}
	int j, i=0, roll;
	do
	{
	cout<<"Enter roll number of student ";
	cin>>roll;
	S[i]=new(stud);
	S[i]->roll=roll;
	S[i]->down=NULL;
	S[i]->right=NULL;
	if(i!=0)
	{
		S[i-1]->down=new(stud);
		S[i-1]->down=S[i];
	}
	cout<<"Enter course registered by the student ";
	cin>>name;
	for(j=0; j<ccount; j++)
	{
		if(C[j]->name==name)
		{
			S[i]->right=new(node);
			P=S[i]->right;
			if(C[j]->down==NULL)
			{
				C[j]->down=new(node);
				C[j]->down=P;
			}
			else
			{
				Q=C[j]->down;
				while(Q!=NULL) Q=Q->Udown.down;
				Q=new(node);
				Q=P;
			}
		}
	}
	cout<<"More courses ? ";
	cin>>yes;
	while(yes=='y'||yes=='Y')
	{
	cout<<"Enter course registered by the student ";
	cin>>name;
	for(j=0; j<ccount; j++)
	{
		if(C[j]->name==name)
		{
			P->Uright.right=new(node);
			P=P->Uright.right;
			P->Uright.right=NULL;
			P->Udown.down=NULL;
			if(C[j]->down==NULL)
			{
				C[j]->down=new(node);
				C[j]->down=P;
			}
			else
			{
				Q=C[j]->down;
				while(Q!=NULL) Q=Q->Udown.down;
				Q=new(node);
				Q=P;
			}
		}
	}
	cout<<"More courses ? ";
	cin>>yes;
	}
	++i;
	cout<<"More students ? ";
	cin>>yes2;
	}while(yes2=='y'||yes2=='Y');
	return 0;
}
