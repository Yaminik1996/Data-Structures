#include<iostream>
using namespace std;
struct mnode
{
	int *data;
	struct mnode ** next;
	int full;
};
typedef mnode *mptr;
void init(mptr M, int m)
{
	M->data=new int[m-1];
	M->full=-1;
	for(int i=0; i<m; i++) M->next[i]=NULL;
}
void sort(int A[], int size)
{
	for(int i=0; i<=size; i++)
	{
		for(int j=i; j<=size; j++)
		{
			if(A[j]>A[i])
			{
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
}
int find_index(int A[100], int data, int m)
{
	int i;
	if(data<A[0]) return 0;
	for(i=0; i<m-1; i++)
	{
		if(data>A[i]&&data<A[i+1])
		return (i+1);
	}
}
void insert(mptr M, int m, int data)
{
	if(M->full<m-2)
	{
		M->data[++M->full]=data;
		sort(M->data, M->full);
	}
	else
	{
		int x=find_index(M->data, data, m);
		if(M->next[x]==NULL)
		{
			M->next[x]=new(mnode);
			init(M->next[x], m);
			insert(M->next[x], m, data);
		}
		else insert(M->next[x], m, data);
	}
}
struct queue
{
	int s;
	mptr ele[50];
	int f;
	int r;
};
void enq(queue &Q, mptr d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
mptr deq(queue &Q)
{
	mptr p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void level(mptr T, mptr A, int m) {
	if(T== NULL) return;
	queue Q; Q.f=-1; Q.r=-1; Q.s=50;
	enq(Q, T);
	enq(Q, A);
	while(Q.f!=-1) 
	{
		if(Q.ele[Q.f]->data[0]==-1) 
		{
		cout<<endl;
		enq(Q, deq(Q));
		}
		mptr current = deq(Q);
		cout<<current->data<<" ";
		for(int z=0; z<m; z++)
		if(current->next[z] != NULL) enq(Q, current->next[z]);
	}
}
int main()
{
	int m, size, data;
	cout<<"Enter the value of m ";
	cin>>m;
	size=m-1;
	mptr M=new(mnode);
	mptr T=new(mnode);
	init(M, m);
	cout<<"Enter a number ";
	cin>>data;
	M->data[0]=data;
	M->full=0;
	char yes='y';
	do
	{
		cout<<"Enter a number ";
		cin>>data;
		T=M;
		insert(T, m, data);
		cout<<"More?";
		cin>>yes;
	}while(yes=='y'||yes=='Y');
	T=M;
	mnode *A=new(mnode);
	A->data[0]=-1;
	level(T, A, m);
	return 0;
}
