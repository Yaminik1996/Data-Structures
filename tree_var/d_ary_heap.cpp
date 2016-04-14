#include<iostream>
using namespace std;
struct hnode
{
	struct hnode *pptr;
	int data;
	struct hnode *next[100];
};
struct queue
{
	int s;
	hnode* ele[1000];
	int f;
	int r;
};
void enq(queue &Q, hnode* d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
hnode* deq(queue &Q)
{
	hnode* p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
void insert(hnode *H, queue &Q, int data, int d)
{
	hnode *T=new(hnode);
	T=deq(Q);
	T->data=data;
	for(int z=0; z<d; z++)
	{
		T->next[z]=new(hnode);
		T->next[z]->pptr=T;
		T->next[z]->data=0;
		enq(Q, T->next[z]);
	}
	if(T->pptr!=NULL)
	{
	while(T!=H)
	{
		if(T->data<T->pptr->data)
			swap(T->data, T->pptr->data);
		T=T->pptr;
	}
	}
}
void level(hnode* T, hnode* A, int d) 
{
	if(T== NULL) return;
	queue P; P.f=-1; P.r=-1; P.s=50;
	enq(P, T);
	enq(P, A);
	while(P.f!=-1) 
	{
		if(P.ele[P.f]->data==-1) 
		{
		cout<<endl;
		enq(P, deq(P));
		}
		hnode* current = deq(P);
		if(current->data==0) return;
		cout<<current->data<<" ";
		for(int z=0; z<d; z++)
		{
			if(current->next[z] != NULL) enq(P, current->next[z]);
		}
	}
}
int main()
{
	int z, data, d;
	queue Q;
	Q.f=-1; Q.r=-1; Q.s=100;
	cout<<"Enter value of d ";
	cin>>d;
	cout<<"Enter data for root node ";
	cin>>data;
	hnode *H=new(hnode);
	H->data=data;
	for(z=0; z<d; z++)
	{
		H->next[z]=new(hnode);
		H->next[z]->data=0;
		H->next[z]->pptr=H;
		enq(Q, H->next[z]);
	}
	H->pptr=NULL;
	while(data!=-1)
	{
		cout<<"Enter data ";
		cin>>data;
		if(data!=-1)
		{
			insert(H, Q, data, d);
		}
	}
	hnode *T=new(hnode);
	T=H;
	hnode *A=new(hnode);
	A->data=-1;
	for(z=0; z<d; z++)
	{
		A->next[z]=NULL;
	}
	A->pptr=NULL;
	level(T, A, d);
	return 0;
}
