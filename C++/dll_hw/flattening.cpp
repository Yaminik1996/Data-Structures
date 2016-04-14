#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
}*t=NULL,*q=NULL,*p=NULL;
struct dnode
{
	int data;
	dnode *dnext;
	node *cnext;
}*ld=NULL,*td=NULL;
int c=0;
void create_node()
{
	int d;
	cout<<"enter data for node(-1 to stop):";
	cin>>d;
	while(d!=-1)
	{
		c++;
		if(td->cnext==NULL)
		{
			td->cnext=new(struct node);
			t=td->cnext;
			t->data=d;
			t->next=NULL;
		}
		else
		{
			t->next=new(struct node);
			t=t->next;
			t->data=d;
			t->next=NULL;
		}
		cout<<"enter:";
		cin>>d;
	}
}
void create_dnode(int d)
{
	if(ld==NULL)
	{
		ld=new(struct dnode);
		ld->data=d;
		ld->dnext=NULL;
		ld->cnext=NULL;
		td=ld;
	}
	else
	{
		td->dnext=new(struct dnode);
		td=td->dnext;
		td->data=d;
		td->dnext=NULL;
		td->cnext=NULL;
	}
	create_node();
}
void print()
{
	td=ld;
	while(td!=NULL)
	{
		cout<<td->data<<"  ";
		t=td->cnext;
		while(t!=NULL)
		{
			cout<<t->data<<"  ";
			t=t->next;
		}
		td=td->dnext;
		cout<<"\n";
	}
}
node *list(dnode *d,node *s)
{
	node *t=NULL;
	s=new(node);
	s->data=d->data;
	s->next=NULL;
	q=s;
	t=d->cnext;
	while(t!=NULL)
	{	q->next=new(node);
		q=q->next;
		q->data=t->data;
		q->next=NULL;
		t=t->next;
	}
	return s;
}
node *merge(node *t1,node *t2)
{
	node *s3=NULL;
	while((t1!=NULL)&&(t2!=NULL))
	{
		if(t1->data<=t2->data)
		{
			if(s3==NULL)
			{
				s3=new(struct node);
				s3->data=t1->data;
				s3->next=NULL;
				q=s3;
			}
			else
			{
				q->next=new(struct node);
				q=q->next;
				q->data=t1->data;
				q->next=NULL;
			}
			t1=t1->next;
		}
		else
		{
			if(s3==NULL)
			{
				s3=new(struct node);
				s3->data=t2->data;
				s3->next=NULL;
				q=s3;
			}
			else
			{
				q->next=new(struct node);
				q=q->next;
				q->data=t2->data;
				q->next=NULL;
			}
			t2=t2->next;
		}
	}
	while(t1!=NULL)
	{
		q->next=new(node);
		q=q->next;
		q->data=t1->data;
		q->next=NULL;
		t1=t1->next;
	}
	while(t2!=NULL)
	{
		q->next=new(node);
		q=q->next;
		q->data=t2->data;
		q->next=NULL;
		t2=t2->next;
	}
	return (s3);
}
int main()
{
	int d;	
	node *s1=NULL,*s2=NULL,*s3=NULL;
	cout<<"enter data for dnode(-1 to stop):";
	cin>>d;
	while(d!=-1)
	{
		c++;
		create_dnode(d);
		cout<<"enter dnode:";
		cin>>d;
	}
	print();
	td=ld;
	s1=list(td,s1);
	td=td->dnext;
	s2=list(td,s2);
	s2=merge(s1,s2);
	td=td->dnext;
	while(td!=NULL)
	{
		s1=list(td,s1);
		s2=merge(s1,s2);
		td=td->dnext;
	}q=s2;
	cout<<"\nflattened:";
	while(q!=NULL)
	{
		cout<<q->data<<"  ";
		q=q->next;
	}
	return 0;
}
