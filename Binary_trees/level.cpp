#include<iostream>
using namespace std;
struct btnode
{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
};
typedef struct btnode *BTPTR;
struct queue
{
	int s;
	BTPTR ele[50];
	int f;
	int r;
};
void enq(queue &Q, BTPTR d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
BTPTR deq(queue &Q)
{
	BTPTR p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void level(BTPTR T, BTPTR A) {
	if(T== NULL) return;
	queue Q; Q.f=-1; Q.r=-1; Q.s=50;
	enq(Q, T);
	enq(Q, A);
	while(Q.f!=-1) 
	{
		if(Q.ele[Q.f]->data=='*') 
		{
		cout<<endl;
		enq(Q, deq(Q));
		}
		btnode* current = deq(Q);
		cout<<current->data<<" ";
		if(current->lchild != NULL) enq(Q, current->lchild);
		if(current->rchild != NULL) enq(Q, current->rchild);
	}
}
void insert(BTPTR T)
{
	if(T!=NULL)
	{
		char d;
		cout<<"Enter data ";
		cin>>d;
		T->data=d;
		cout<<"Left child ? (Enter / for NO) ";
		cin>>d;
		if(d=='/') T->lchild=NULL;
		else
		{
			cout<<"Into the left subtree ";
			T->lchild=new(btnode);
			insert(T->lchild);
		}
		cout<<"Right child ? (Enter / for NO) ";
		cin>>d;
		if(d=='/') T->rchild=NULL;
		else
		{
			cout<<"Into the right subtree ";
			T->rchild=new(btnode);
			insert(T->rchild);
		}
	}
}
int main()
{
	int d;
	BTPTR B, T;
	BTPTR A;
	A=new(btnode);
	A->lchild=NULL;
	A->rchild=NULL;
	char ch='*';
	A->data=ch;
	B=new(btnode);
	T=B;
	insert(T);
	T=B;
	level(T, A);
	cout<<endl;
	return 0;
}
