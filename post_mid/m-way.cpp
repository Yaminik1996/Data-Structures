#include<iostream>
using namespace std;
struct mnode
{
	int *data;
	struct mnode ** next;
	int full;
};
typedef mnode *mptr;
int m;
void init(mptr M, int m)
{
	M->data=new int[m-1];
	M->full=-1;
	M->next=new mnode * [m];
	for(int i=0; i<m; i++) 
	{
		//M->next[i]=new *mnode[m];
		M->next[i]=NULL;
	}
}
void sort(int A[], int size)
{
	for(int i=0; i<=size; i++)
	{
		for(int j=i; j<=size; j++)
		{
			if(A[j]<A[i])
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
		cout<<"case 1";
		M->data[++M->full]=data;
		sort(M->data, M->full);
	}
	else
	{
		cout<<"case 2";
		cout<<M->full;
		int x=find_index(M->data, data, m);
		cout<<"index = "<<x;
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
		if(Q.f==Q.r) return;
		if(Q.ele[Q.f]->data[0]==-1) 
		{
		cout<<endl;
		enq(Q, deq(Q));
		}
		mptr current = deq(Q);
		for(int z=0; z<=current->full; z++) cout<<current->data[z]<<"  ";
		for(int z=0; z<m; z++)
		if(current->next[z] != NULL) enq(Q, current->next[z]);
	}
}
int search(mnode *M, int data, int m)
{
	if(!M) return 0;
	for(int i=0; i<=M->full; i++)
	if(M->data[i]==data) return 1;
	int x=find_index(M->data, data, m);
	if(!M->next[x]) return 0;
	return search(M->next[x], data, m);
}
mnode* del(mnode *M, int data, int &index)
{
	if(!M) return NULL;
	for(int i=0; i<=M->full; i++)
	if(M->data[i]==data) {
		index=i;
		return M;
	}
	int x=find_index(M->data, data, index);
	if(!M->next[x]) return NULL;
	return del(M->next[x], data, index);
}
void remove(mnode *M, int index)
{
	if(M->full<m-2)
	{
		for(int j=index; j<M->full; j++)
		M->data[j]=M->data[j+1];
		--M->full;
		if(M->full==-1) 
		{
			M=NULL;
		}
		return;
	}
	if(!M->next[index])
	{
		for(int j=index; j<M->full; j++)
		{
			M->data[j]=M->data[j+1];
			M->next[j]=M->next[j+1];
		}
		M->next[M->full]=M->next[M->full+1];
		--M->full;
		return;
	}
	mnode *P=M;
	if(M->next[index]) M=M->next[index];
	if(M->next[0])
	while(M->next[0]) M=M->next[0];
	P->data[index]=M->data[M->full];
	--M->full;
	if(M->full==-1)
	{
		delete(M);
		M=NULL;
	}
}
int main()
{
	int size, data;
	cout<<"Enter the value of m ";
	cin>>m;
	size=m-1;
	mptr M=NULL;
	M=new(mnode);
	mptr T=NULL;
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
	yes='y';
	/*while(yes=='y'||yes=='Y')
	{
		cout<<"Enter a number to search ";
		cin>>data;
		T=M;
		cout<<search(T, data, m)<<endl;
		cout<<"More ?";
		cin>>yes;
	}*/
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter a number to delete ";
		cin>>data;
		T=M;
		int index=0;
		mnode *P=del(T, data, index);
		remove(P, index);
		T=M;
		level(T, A, m);
		cout<<"More ?";
		cin>>yes;
	}
	return 0;
}
