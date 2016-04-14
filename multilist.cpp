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
}*S, *ts;
struct course
{
	char name;
	struct node *down;
	struct course *right;
}*C, *tc;
struct node
{
	int tagright;
	union 
	{
		struct node *right;
		struct stud *s;
	}Uright;
	int tagdown;
	union
	{
		struct node *down;
		struct course *c;
	}Udown;
}*T;
struct m
{
	struct course *C;
	struct stud *S;
}M;
int ccount=5;
int main()
{
	int i, roll, t, ty;
	char name;
	node *P;
	cout<<"Enter name of course ";
	cin>>name;
	C=new(course);
	C->name=name;
	C->down=NULL;
	C->right=NULL;
	tc=C;
	for(i=0; i<4; i++)
	{
		cout<<"Enter name of course ";
		cin>>name;
		tc->right=new(course);
		tc=tc->right;
		tc->name=name;
		tc->down=NULL;
		tc->right=NULL;
	}
	cout<<"Enter roll number of student ";
	cin>>roll;
	S=new(stud);
	S->roll=roll;
	S->down=NULL;
	S->right=NULL;
	S->right=new(node);
	T=S->right;
	do
	{
		cout<<"Enter course name & (press 0 for last, 1 otherwise)";
		cin>>name>>t;
		T=new(node);
		T->tagdown=1;
		T->tagright=t;
		T->Udown.down=NULL;
		if(t)
		T->Uright.right=NULL;
		if(!t)
		T->Uright.s=S;
		tc=C;
		while(tc!=NULL)
		{
			if(tc->name==name)
			{
				if(tc->down==NULL)
				{
					//tc->down=new(node);
					tc->down=T;
				}
				else
				{
					P=tc->down;
					while(P->Udown.down!=NULL) P=P->Udown.down;
					//P->Udown.down=new(node);;
					P->Udown.down=T;
				}
			}
			tc=tc->right;
		}
		if(t)
		{
			T->Uright.right=new(node);
			T=T->Uright.right;
		}
	}while(t);
	ts=S;
	do
	{
		cout<<"Enter roll number of student & (press 0 for last entry, otherwise 1)";
		cin>>roll>>ty;
		ts->down=new(stud);
		ts=ts->down;
		ts->roll=roll;
		ts->down=NULL;
		ts->right=new(node);
		T=ts->right;
	do
	{
		cout<<"Enter course name & (press 0 for last, 1 otherwise)";
		cin>>name>>t;
		T=new(node);
		T->tagdown=ty;
		T->tagright=t;
		if(ty)
		T->Udown.down=NULL;
		else
		T->Udown.c=NULL;	
		if(t)
		T->Uright.right=NULL;
		else
		T->Uright.s=ts;
		tc=C;
		while(tc!=NULL)
		{
			if(tc->name==name)
			{
				if(tc->down==NULL)
				{
					tc->down=new(node);
					tc->down=T;
					if(!ty)
					T->Udown.c=tc;
				}
				else
				{
					
					P=tc->down;
					while(P->Udown.down!=NULL) P=P->Udown.down;
					P->Udown.down=new(node);;
					P->Udown.down=T;
					if(!ty)
					T->Udown.c=tc;
				}
			}
			tc=tc->right;
		}
		if(t)
		{
			T->Uright.right=new(node);
			T=T->Uright.right;
		}
	}while(t);
	}while(ty);/*
	cout<<"enter roll :";
	cin>>roll;
	ts=S;
	while(ts->roll!=roll)
	{
		ts=ts->down;
	}
	T=ts->right;
	while(T->tagright)
	{
		P=T;
		while(P->tagdown)
		P=P->Udown.down;
		cout<<P->Udown.c->name<<"  ";
		T=T->Uright.right;
	}*/
	cout<<"enter course :";
	cin>>name;
	tc=C;
	while(tc->name!=name)
	{
		tc=tc->right;
	}
	T=tc->down;
	while(T->tagdown)
	{
		P=T;
		while(P->tagright)
		P=P->Uright.right;
		cout<<P->Uright.s->roll<<"  ";
		T=T->Udown.down;
	}
	return 0;
}
