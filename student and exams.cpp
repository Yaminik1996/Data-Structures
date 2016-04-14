#include<iostream>
#include<string.h>
using namespace std;
struct enode
{
	char ename[10];
	int marks;
	struct enode *next;
}*te;
struct snode
{
	char name[10];
	int rollno;
	struct snode *next;
	struct enode *eref;
};
struct snode *ls,*ts;
void push()
{
	if(ls==NULL)
	{ls=new (struct snode);
	  ts=ls;
	}
	else
	{ts->next=new (struct snode);
	 ts=ts->next;
	 ts->next=NULL;
	 ts->eref=NULL;
	}
	cout<<"\n\n\n name:-";cin>>ts->name;
	cout<<"\n rollno:-";cin>>ts->rollno;
	cout<<"\n\n enter the details of the subjects taken by the student";
	te=ts->eref;
	int i=0,check=1;
	while(1>0&&check==1)
	{
		if(te==NULL)
	   {	ts->eref=new(struct enode);
	      te=ts->eref;
	   }
		else
		{te->next=new(struct enode);
		te=te->next;
    	}
    	cout<<"\nenter the name of the subject:-";cin>>te->ename;
    	cout<<"\nenter marks obtained in the subject:-";cin>>te->marks;i++;
    	if(i>=2)
    	{cout<<"\nif student wants to take more subjects press 1";
    	cin>>check;}
    	if(check!=1)te->next=NULL;
    }
}
void print()
{
	cout<<"\n\n                       DETAILS OF STUDENTS\n\n\n\n";
	struct snode *stemp;
	struct enode *etemp;
	stemp=ls;
	while(stemp!=NULL)
	{
		cout<<"                      DETAILS OF STUDENT\n\n";
		cout<<"  name of the student:-"<<stemp->name;
		cout<<"\n  rollnumber of the student:-"<<stemp->rollno;
		etemp=stemp->eref;
		while(etemp!=NULL)
		{
		cout<<"\n\n  name of the exam:-"<<etemp->ename;
		cout<<"\n  marks obtained in the subject"<<etemp->marks;
		etemp=etemp->next;
       	}
       stemp=stemp->next;	
	}
}
void find(char sub[10])
{  
    int avg=0,n=0;	
	struct snode *stemp=NULL;
	struct enode *etemp=NULL;
	stemp=ls;
	while(stemp!=NULL)
	{
		etemp=stemp->eref;
		while(etemp!=NULL)
		{	
		if(strcmpi(sub,etemp->ename)){avg=avg+etemp->marks;n++;}
		etemp=etemp->next;
       	}
       stemp=stemp->next;	
	}
	cout<<"\n\n average of the subject "<<sub<<" is "<<float(avg/n);
}	
	int main()
	{ls=NULL;te=NULL;ts=NULL;   
	char sub[100];
	cout<<"\n     PLEASE ENTER THE DETAILS OF THE STUDENTS";
		int check=1;
		while(check==1)
		{push();
		cout<<"\nif u want to add more records press 1";cin>>check;}
		print();
		
		cout<<"\n\nenter the name of the suject whose avg is to be taken";
		cin>>sub;
		find(sub);
	}
