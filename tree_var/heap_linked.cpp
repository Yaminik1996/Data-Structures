#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void add(node *H, int n, int i, int d)
{
	int j, k, l;
	if(i<=n)
	{
		node *h=new(node), *h2=new(node);
		h=H;
		h2=H;
		for(k=1; k<i-1; k++)	h=h->next;
		h->next=new(node);
		h=h->next;
		h->data=d;
		h->next=NULL;
		j=i/2;
		for(l=1; l<j; l++)	h2=h2->next;
		while(j>0&&h2->data>d)
		{
			swap(h2->data, h->data);
			i=i/2;
			h=H;
			for(k=1; k<i; k++) h=h->next;
			j=j/2;
			h2=H;
			for(l=1; l<j; l++) h2=h2->next;
		}
	}
}
void assign(node *t, int i)
{
	for(int j=1; j<i; j++)	t=t->next;
}
int del(node *H, int &n)
{
	int x=H->data, j;
	node *h1=new(node);
	h1=H;
	for(int c=1; c<n; c++)	h1=h1->next;
	H->data=h1->data;
	n=n-1;
	int i=1;
	while(i<=n)
	{
		if((2*i+1)<=n)
		{
			node *t1=new(node), *t2=new(node), *t3=new(node);
			t1=H;t2=H;t3=H;
			for(j=1; j<i; j++)	t1=t1->next;
			for(j=1; j<2*i; j++)	t2=t2->next;
			for(j=1; j<(2*i+1); j++)	t3=t3->next;
		if(((t1->data<t2->data)&&(t1->data<t3->data))) break;
		if(t2->data<t3->data)
		{	
		swap(t1->data, t2->data);
		}
		else
		{
			swap(t1->data, t3->data);
		}
		i=i*2;
		}
		else if((2*i)==n)
		{
			node *t1=new(node), *t2=new(node);
			t1=H;t2=H;
			for(j=1; j<i; j++)	t1=t1->next;
			for(j=1; j<2*i; j++)	t2=t2->next;
			if(t1->data>t2->data) swap(t1->data, t2->data);
			i=2*i;
		}
		else
		{
			i=2*i;
		}
	}
	return x;
}
int main()
{
	int n, d;
	struct node *H;
	H=new(node);
	cout<<"Enter size ";
	cin>>n;
	cout<<"Enter first data element ";
	cin>>d;
	H->data=d;
	H->next=NULL;
	int i=1;
	for(i=2; i<=n; i++)
	{
		cin>>d;
		add(H, n, i, d);
	}
	node *h=H;
	while(h!=NULL) 
	{
	cout<<h->data<<"\t";
	h=h->next;
	}
	cout<<endl;
	int m=n;
	for(i=1; i<=m; i++)
	{
		cout<<del(H, n)<<"   ";
	}
	return 0;
}
