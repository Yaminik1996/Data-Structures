#include<iostream>
using namespace std;
struct hnode
{
	struct hnode *pptr;
	struct hnode *lchild;
	int data[50];
	int level;
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
void swap(int a[100], int b[100], int size)
{
	int t, i;
	for(i=0; i<size; i++)
	{
		t=a[i];
		a[i]=b[i];
		b[i]=t;
	}
}
void insert(hnode *H, queue &Q, int data[50], int size)
{
	hnode *T=new(hnode);
	T=deq(Q);
	T->lchild=new(hnode);
	T->rchild=new(hnode);
	T->lchild->pptr=T;
	T->rchild->pptr=T;
	T->lchild->level=((T->level)+1)%size;
	T->rchild->level=((T->level)+1)%size;
	enq(Q, T->lchild);
	enq(Q, T->rchild);
	for(int i=0; i<size; i++) T->data[i]=data[i];
	if(T->pptr!=NULL)
	{
	while(T!=H)
	{
		if(T->data[(T->level)-1]<T->pptr->data[(T->level)-1])
			{
				swap(T->data, T->pptr->data, size);
			}
		T=T->pptr;
	}
	}
	return;
}
void level(hnode* T, hnode* A, int size) 
{
	if(T== NULL) return;
	queue P; P.f=-1; P.r=-1; P.s=50;
	enq(P, T);
	enq(P, A);
	while(P.f!=-1) {
		if(P.ele[P.f]->data[0]==-1) 
		{
		cout<<endl;
		enq(P, deq(P));
		}
		hnode* current = deq(P);
		if(current->data[0]==0) return;
		for(int l=0; l<size; l++) cout<<current->data[l]<<"\t";
		if(current->lchild != NULL) enq(P, current->lchild);
		if(current->rchild != NULL) enq(P, current->rchild);
	}
}
int main()
{
	int data, size, array[50], i;
	queue Q;
	char yes='y';
	Q.f=-1; Q.r=-1; Q.s=100;
	cout<<"Enter size of array (atleast 2)";
	cin>>size;
	hnode *H=new(hnode);
	cout<<"Enter data for root node ";
	for(i=0; i<size; i++) cin>>H->data[i];
	H->level=0;
	H->lchild=new(hnode);
	H->lchild->pptr=H;
	H->lchild->level=1;
	H->rchild=new(hnode);
	H->rchild->pptr=H;
	H->rchild->level=1;
	enq(Q, H->lchild);
	enq(Q, H->rchild);
	H->pptr=NULL;
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter data ";
		for(i=0; i<size; i++) cin>>array[i];
		insert(H, Q, array, size);
		cout<<"More ? ";
		cin>>yes;
	}
	hnode *T=new(hnode);
	T=H;
	hnode *A=new(hnode);
	A->data[0]=-1;
	A->lchild=NULL;
	A->rchild=NULL;
	A->pptr=NULL;
	level(T, A, size);
	return 0;
}
