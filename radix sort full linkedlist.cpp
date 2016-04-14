#include<iostream>
#include<math.h>
/*#include<bits/stdc++.h>*/
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct rnode
{
	struct node *lnum;
	struct rnode *next;
};
struct node *t2;
struct rnode *t1,*r;
int input(int a[10],int *e)
{

	int n=0,m=0,q,i=0,check=1;
	while(check==1)
	{
		    cout<<"please enter the element";
	cin>>a[i];
	*e=(*e)+1;
    n=0,q=0;
	do
	{
		q=a[i]/(pow(10,n));
		n++;
	}while(q!=0);
	if(m<n)m=n;
	i++;
	cout<<"enter 1 to enter more elements  else 0";
	cin>>check;  
}
     return m;
}
void pop(int a[100])
{
	int i=0,k=0;
	struct rnode *temp;
	temp=r;
	cout<<"pop";
	while(k<=9)
	{   t2=temp->lnum;
	   if(temp->lnum==NULL)
	   {k++;continue;
	   }
	   else
	     while(t2!=NULL)
	     {
	     	a[i++]=t2->data;
	     	t2=t2->next;	
		 }
		 k++;
		 temp=temp->next;
	}
		t1=r;
   k=0;
	while(k<=9)
	{
		t1->lnum=NULL;
		if(k!=9)
		t1=t1->next;k++;}
		t1=NULL;
		t2=NULL;
}
void add(int i,int d)
{   
      int k=0;
      t1=r;
      while(k<i)
{
	t1=t1->next;k++;}
	cout<<"hi";
	if(t1->lnum==NULL)
	{
		t1->lnum=new(struct node);
		t2=t1->lnum;
	    t2->data=d;
		t2->next=NULL;
	}
	else
	{ t2=t1->lnum;
	  while(t2->next!=NULL)
	    t2=t2->next;
	  t2->next=new(struct node);
	  t2=t2->next;
	  t2->data=d;
	  t2->next=NULL;
	}
}
void sort(int n,int e,int a[100])
{    int k=0,count=0,i=0,j;
	i=0;
		while(i<e)
		{  count=(pow(10,n));
		j=(a[i]%count);
		if(a[i]<(count/10))
		j=0;
		else
		{    if(j<10&&a[i]>count&&n!=1)//for 1001,101;
		j=0;
		   if(a[i]<10&&n==1)j=a[i];
		    else
		   while(j>=10)
			j=j/(10);
		}
				cout<<"hi   j ="<<j<<endl;
			add(j,a[i]);
			i++;
		}
	t2=NULL;
		pop(a);
	//	k++;	
}
int main()
{   int k=0,e=0,a[100],i=0;
//creating base linked list
	r=new(struct rnode);
	t1=r;
	while(k<=9)
	{
		t1->lnum=NULL;
		if(k!=9)
		{   
			t1->next=new(struct rnode);
			t1=t1->next;
		}
		else
		t1->next=NULL;
		k++;
	}	
	int n=input(a,&e);
	cout<<"\n\n n="<<n<<"  "<<"e="<<e;
	   i=0;
	   cout<<"\n";
    while(i<e)
	cout<<a[i++]<<" ";
	i=1;
    while(i<n)
    {cout<<i<<"     ";
	sort(i,e,a);
	 k=0;
	   cout<<"\n";
    while(k<e)
	cout<<a[k++]<<" ";
	i++;}
	 i=0;
	   cout<<"\n";
    while(i<e)
	cout<<a[i++]<<" ";
}
