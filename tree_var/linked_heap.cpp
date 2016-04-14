#include<iostream>
using namespace std;
struct hnode
{
	struct hnode *pptr;
	struct hnode *lchild;
	int data;
	struct hnode *rchild;
};
struct queue
{
	int s;
	hnode* ele[50];
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
void insert(hnode *H, queue &Q, int data)
{
	hnode *T=new(hnode);
	T=deq(Q);
	T->lchild=new(hnode);
	T->rchild=new(hnode);
	T->lchild->pptr=T;
	T->rchild->pptr=T;
	enq(Q, T->lchild);
	enq(Q, T->rchild);
	T->data=data;
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
void level(hnode* T, hnode* A) 
{
	if(T== NULL) return;
	queue P; P.f=-1; P.r=-1; P.s=50;
	enq(P, T);
	enq(P, A);
	while(P.f!=-1) {
		if(P.ele[P.f]->data==-1) 
		{
		cout<<endl;
		enq(P, deq(P));
		}
		hnode* current = deq(P);
		if(current->data==0) return;
		cout<<current->data<<" ";
		if(current->lchild != NULL) enq(P, current->lchild);
		if(current->rchild != NULL) enq(P,current->rchild);
	}
}
int main()
{
	int data,d;
	queue Q;
	Q.f=-1; Q.r=-1; Q.s=100;
	cout<<"Enter data for root node ";
	cin>>data;
	hnode *H=new(hnode);
	H->data=data;
	H->lchild=new(hnode);
	H->lchild->pptr=H;
	H->rchild=new(hnode);
	H->rchild->pptr=H;
	enq(Q, H->lchild);
	enq(Q, H->rchild);
	H->pptr=NULL;
	while(d!=-1)
	{
		cout<<"Enter data ";
		cin>>d;
		if(d!=-1)
		{
			insert(H, Q, d);
		}
	}
	hnode *T=new(hnode);
	T=H;
	hnode *A=new(hnode);
	A->data=-1;
	A->lchild=NULL;
	A->rchild=NULL;
	A->pptr=NULL;
	level(T, A);
	return 0;
}
