#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
struct node
{
	int t;
	void *data;
	node *next;
};
struct snode
{
	char name[50];
	snode *snext;
	node *next;
} *S2, *S;
void push(snode *S, char name[50])
{
	node *D;
	snode *S2;
	S2=S;
	if(S==NULL)
	{
		S=new(snode);
		strcpy(S->name, name);
		S->next=new(node);
		D=S->next;
		S->snext=NULL;
	}
	else
	{
		S->snext=new(snode);
		S2=S->snext;
		S2->next=new(node);
		D=S2->next;
		S2->snext=NULL;
	}
	int t;
	char ch='y';
	do{
	cout<<"What do you want to store? 1. INTEGER 2. CHARACTER 3. FLOAT";
	cin>>t;
	if(t==1)
	{
		cout<<"Enter integer ";
		int a;
		cin>>a;
		D->t=1;
		D->data=malloc(sizeof(int));
		*((int*)D->data)=a;
	}
	else if(t==2)
	{
		cout<<"Enter character ";
		char a;
		cin>>a;
		D->t=2;
		D->data=malloc(sizeof(char));
		*((char*)D->data)=a;
	}
	else if (t==3)
	{
		cout<<"Enter floating point number ";
		float a;
		cin>>a;
		D->t=3;
		D->data=malloc(sizeof(float));
		*((float*)D->data)=a;
	}
	cout<<"Any more info?";
	cin>>ch;
	if(ch=='y')
	{	D->next=new(node);
		D=D->next;
	}
	else D->next=NULL;
}while(ch=='y');
	/*else if(t==4)
	{
		cout<<"Enter string ";
		string a;
		cin>>a;
		D->data=malloc(sizeof(string));
		*((string*)D->data)=a;
		cout<<*((string*)D->data);
	}*/
}
int main()
{
	node *D, *D2;
	char name[30];
	S=NULL;S2=NULL;D=NULL;D2=NULL;
	char m='y';
	int i=0;
	cout<<"Enter student's name ";
	cin>>name;
	S=new(snode);
	strcpy(S->name, name);
	S->next=new(node);
	D=S->next;
	S->snext=NULL;
	int t;
	char ch='y';
	do{
	cout<<"What do you want to store? 1. INTEGER 2. CHARACTER 3. FLOAT";
	cin>>t;
	if(t==1)
	{
		cout<<"Enter integer ";
		int a;
		cin>>a;
		D->t=1;
		D->data=malloc(sizeof(int));
		*((int*)D->data)=a;
	}
	else if(t==2)
	{
		cout<<"Enter character ";
		char a;
		cin>>a;
		D->t=2;
		D->data=malloc(sizeof(char));
		*((char*)D->data)=a;
	}
	else if (t==3)
	{
		cout<<"Enter floating point number ";
		float a;
		cin>>a;
		D->t=3;
		D->data=malloc(sizeof(float));
		*((float*)D->data)=a;
	}
	cout<<"Any more info?";
	cin>>ch;
	if(ch=='y')
	{	D->next=new(node);
		D=D->next;
	}
	else D->next=NULL;
}while(ch=='y');
	S2=new(snode);
	S2=S;
	do
	{
		cout<<"Enter student's name ";
		cin>>name;
		push(S2, name);
		cout<<"More ?";
		cin>>m;
	}while(m=='y');
	cout<<"Enter the name of student whom you want to search ";
	cin>>name;
	S2=S;
	if(S==NULL) cout<<"NULL";
	cout<<S2->name;
	cout<<S2->snext->name;
	while(S2!=NULL)
	{
		if(strcmp(S2->name,name)==0)
		{
		D2=S2->next;
		while(D2->next!=NULL)
		{
		if(D2->t==1) cout<<*((int*)D->data)<<endl;
		else if(D2->t==2) cout<<*((char*)D->data)<<endl;
		else if(D2->t==3) cout<<*((float*)D->data)<<endl;
		D2=D2->next;
		}
		}
		else S2=S2->snext;
	}
	return 0;
}
