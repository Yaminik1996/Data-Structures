#include<iostream>
#include<string.h>
using namespace std;
struct cnode
{
	int marks;
	char cname[30];
	struct cnode *cnext;
}*P;
struct snode
{
	char name[30];
	struct snode *snext;
	struct cnode *cnext;
}*S1, *T1, *T2;
void add()
{
	if(S1==NULL)
	{S1=new (struct snode);
	  T1=S1;
	}
	else
	{T1->snext=new (struct snode);
	 T1=T1->snext;
	 T1->snext=NULL;
	 T1->cnext=NULL;
	}
	cout<<"Enter name ";
	cin>>T1->name;
	cout<<"Enter the details of subjects ";
	P=T1->cnext;
	int i=0,check=1;
	while(check==1)
	{
		if(P==NULL)
	   {	T1->cnext=new(struct cnode);
	        P=T1->cnext;
	   }
		else
		{T1->cnext=new(struct cnode);
		P=T1->cnext;
    	}
    	cout<<"Enter the name of the course";cin>>P->cname;
    	cout<<"Enter marks obtained in the course";cin>>P->marks;i++;
    	if(i>=2)
    	{cout<<"Press 1 for more subjects";
    	cin>>check;}
    	if(check!=1)P->cnext=NULL;
    }
}
void show()
{
	struct snode *stemp;
	struct cnode *ctemp;
	stemp=S1;
	while(stemp!=NULL)
	{
		cout<<"\t\tDETAILS OF STUDENT\n\n";
		cout<<"Name "<<stemp->name;
		ctemp=stemp->cnext;
		while(ctemp!=NULL)
		{
		cout<<"Name of course"<<ctemp->cname;
		cout<<"Marks obtained in the course"<<ctemp->marks;
		ctemp=ctemp->cnext;
       	}
       stemp=stemp->snext;	
	}
}
int main()
{
	T1=NULL;
	S1=NULL;
	P=NULL;
	cout<<"\n     PLEASE ENTER THE DETAILS OF THE STUDENTS";
	int check=1;
	while(check==1)
	{
	add();
	cout<<"Press 1 for more records ";cin>>check;
	}
	show();
	return 0;
}
