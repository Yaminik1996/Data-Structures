//For tomorrow's DS lab students have to come to lab with the following program: creation of B+ Tree with two different types of nodes.
//Non leaf nodes have count,parent ptr, 2d keys , 2d+1 pointers.
//Leaf nodes have count,parent ptr, 2d keys, one pointer to its right sibling/next leaf node.
//After creation the tree should be displayed in level order and range searching (k1, k2)
//means all the keys lying in between k1 and K2 ( greater than k1 and less than k2) should be printed.
#include<iostream>
using namespace std;
struct lnode;
struct inode;
struct lnode
{
	int keys[20];
	int count;
	struct lnode *next;
	struct inode *pptr;
};
typedef lnode* lptr;
struct inode
{
	int keys[20];
	int count;
	struct inode *pptr;
	int tag;//tag=0 for parent of leaf, tag=1 for parent of non-leaf
	union
	{
		struct inode *ichild[20];
		struct lnode *lchild[20];
	}U;
}*root;
typedef inode* iptr;
int d;
lptr init(lptr B)
{
	B=new(lnode);	B->pptr=NULL;	B->count=0;	  //B->next=NULL; 
	return B;
}
iptr init(iptr B, int tag)
{
	int i;	B=new(inode);	B->pptr=NULL;	B->count=0;	  B->tag=tag;
	if(tag)	for(i=0; i<=2*d; i++)	B->U.ichild[i]=NULL;
	else  for(i=0; i<=2*d; i++)	B->U.lchild[i]=NULL;
	return B;
}
int insert(iptr &B, int key)//not full condition
{
	int i, j;
	for(i=0; i<B->count; i++)
	{
		if(key<B->keys[i])
		{
			for(j=B->count-1; j>=i; j--)
			{
				B->keys[j+1]=B->keys[j];	
				if(B->tag==0){		B->U.lchild[j+2]=B->U.lchild[j+1];	B->U.lchild[j+1]=NULL; }
				else {		B->U.ichild[j+2]=B->U.ichild[j+1];	B->U.ichild[j+1]=NULL; }
			}
			break;
		}
	}
	++B->count;	B->keys[i]=key;
	for (j=0;j<B->count;j++)
	return i;
}
int insert(lptr &B, int key)//not full condition
{
	int i, j;
	for(i=0; i<B->count; i++)
	{
		if(key<B->keys[i])
		{
			for(j=B->count-1; j>=i; j--)
			{
				B->keys[j+1]=B->keys[j];
			}
			break;
		}
	}
	++B->count;	B->keys[i]=key;
	for (j=0;j<B->count;j++)
	return i;
}
int find_index(iptr B, int key)//finding pointer index
{
	if(key<B->keys[0]) return 0;
	if(key>B->keys[B->count-1]) return B->count;
	for(int i=0; i<B->count-1; i++)
	{
		if(key>B->keys[i]&&key<B->keys[i+1]) return i+1;
	}
}
int find(iptr B, int key)//to check if key exists
{
	for(int i=0; i<B->count; i++)
	{
		if(B->keys[i]==key) return i;
	}
	return -1;
}
void split(iptr &B, iptr &sib, int key)
{
	iptr B1=NULL, B2=NULL;
	int i,j,m=0;
    i=insert(B,key);
	B2=init(B2, B->tag);
	for(j=d+1;j<=2*d;j++)
    {
    	B2->keys[m]=B->keys[j];
    	if(B->tag==0)
    	{    	B2->U.lchild[m]=B->U.lchild[j];    	B2->U.lchild[m+1]=B->U.lchild[j+1];    	B->U.lchild[j]=NULL; }
		if(B->tag==1)
    	{    	B2->U.ichild[m]=B->U.ichild[j];    	B2->U.ichild[m+1]=B->U.ichild[j+1];    	B->U.ichild[j]=NULL; }
		m++;
    }
    if(B->tag==0)    B->U.lchild[j]=NULL;
    else B->U.ichild[j]=NULL;
    B2->count=d; B2->tag=B->tag;
    B1=B; B1->tag=B->tag;
    B1->count=d;
	sib=B2;
	if(B->pptr==NULL)
    {
    	B->pptr=init(B->pptr, 1);
    	B->pptr->keys[0]=B->keys[d];
    	B->pptr->count=1;
    	B->pptr->U.ichild[0]=B1; B1->pptr=B->pptr;
    	B->pptr->U.ichild[1]=B2; B2->pptr=B->pptr;
    	if(B==root) root=B->pptr;
	}
    else
    {
    	if(B->pptr->count<2*d)
    	{
    		j=insert(B->pptr,B->keys[d]);
    		B->pptr->U.ichild[j]=B1; B1->pptr=B->pptr;
    		B->pptr->U.ichild[j+1]=B2; B2->pptr=B->pptr;
    	}
    	else
    	{
    		iptr psib=NULL;
    		int x=B->keys[d];
    		iptr pptr1=B->pptr; iptr cb1=B1; iptr cb2=B2;
    		split(B->pptr, psib, x);
			int z;
			z=find(pptr1, x);
			if(z!=-1)
			{
				pptr1->U.ichild[z]=cb1; cb1->pptr=pptr1;
				pptr1->U.ichild[z+1]=cb2; cb2->pptr=pptr1;
			}
			else
			{
				z=find(psib, x);
				if(z!=-1)
				{
					psib->U.ichild[z]=cb1; cb1->pptr=psib;
					psib->U.ichild[z+1]=cb2; cb2->pptr=psib;
				}
				else
				{
					pptr1->U.ichild[d]=cb1; cb1->pptr=pptr1;
					psib->U.ichild[0]=cb2; cb2->pptr=psib;
				}
			}
		}
    }
}
void split(lptr &B, lptr &sib, int key)
{
	lptr B1=NULL, B2=NULL;
	int i,j,m=0;
    i=insert(B,key);
	B2=init(B2);
	B2->next=B->next;
	for(j=d;j<=2*d;j++, m++)
    {
    	B2->keys[m]=B->keys[j];
    }
    B2->count=d+1;
    B1=B;
    B1->count=d;
	sib=B2;
	B1->next=new(lnode);
	B1->next=B2;
	if(B->pptr==NULL)
    {
    	B->pptr=init(B->pptr, 0);
    	B->pptr->keys[0]=B->keys[d];
    	B->pptr->count=1;
    	B->pptr->U.lchild[0]=B1; B1->pptr=B->pptr;
    	B->pptr->U.lchild[1]=B2; B2->pptr=B->pptr;
	}
    else 
    {
    	if(B->pptr->count<2*d)
    	{
    		j=insert(B->pptr,B->keys[d]);
    		B->pptr->U.lchild[j]=B1; B1->pptr=B->pptr;
    		B->pptr->U.lchild[j+1]=B2; B2->pptr=B->pptr;
    	}
    	else
    	{
    		iptr psib=NULL;
    		int x=B->keys[d];
    		iptr pptr1=B->pptr;  		
    		lptr cb1=B1;
    		lptr cb2=B2;
    		split(B->pptr, psib, x);
			int z;
			z=find(pptr1, x);
			if(z!=-1)
			{
				pptr1->U.lchild[z]=cb1; cb1->pptr=pptr1;
				pptr1->U.lchild[z+1]=cb2; cb2->pptr=pptr1;
			}
			else
			{
				z=find(psib, x);
				if(z!=-1)
				{
					psib->U.lchild[z]=cb1; cb1->pptr=psib;
					psib->U.lchild[z+1]=cb2; cb2->pptr=psib;
				}
				else
				{
					pptr1->U.lchild[d]=cb1;	cb1->pptr=pptr1;
					psib->U.lchild[0]=cb2; cb2->pptr=psib;
				}
			}
		}
    }
}
void add(lptr &B, int key)
{
	if(B->count<2*d)//a leaf not full
	{
		int i=insert(B, key);
	}
	else// full leaf
	{
			lptr sib=NULL;
			split(B, sib, key);
	}
}
void add(iptr &B, int key)//basic add function
{
	int i;
	if(B->tag==1)	{i=find_index(B, key);	add(B->U.ichild[i], key);}
	else {i=find_index(B, key); add(B->U.lchild[i], key);}
}
struct queue
{
	int s;
	iptr I[50];
	int f;
	int r;
};
void enq(queue &Q, iptr d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.I[Q.r]=d;
}
iptr deq(queue &Q)
{
	if(Q.f==-1) {cout<<"Queue is empty"; return NULL;}
	iptr I=Q.I[Q.f];
	if(Q.f==Q.r) { Q.f=-1; Q.r=-1;	}
	else Q.f=(Q.f+1)%Q.s;
	return I;
}
void print(queue &Q, iptr B, iptr ignore)
{
	int y, z;
	enq(Q, B);
	enq(Q, ignore);
	while(Q.f!=-1)
	{
		iptr T;
		if(Q.f==Q.r) break;
		T=deq(Q);
		if(T->keys[0]!=-1)
		{
			for(y=0;y<T->count;y++)
			{
				cout<<T->keys[y]<<"  ";
			}
			if(T->tag==1)
			{
			for(z=0; z<=2*d; z++)
			{
				if(T->U.ichild[z]) enq(Q, T->U.ichild[z]);
			}
			}
		}
    	else if(T->keys[0]==-1)
    	{
    		cout<<endl;
    		enq(Q, ignore);
		}
	}
}
void bet(lnode *L, int k1, int k2)
{
	while(L)
	{
		for(int i=0; i<L->count; i++) 
		{
			if(L->keys[i]>=k1&&L->keys[i]<=k2)
			cout<<L->keys[i]<<"   ";
		}
		L=L->next;
	}
}
int main()
{
	int key, count=0;
	lptr L;
	L=init(L);
	L->next=NULL;
	cout<<"Enter degree of B-tree\t";
	cin>>d;
	while(count<2*d)
	{
		cout<<"Enter key(-1 to exit)\t";
		cin>>key;
		if(key!=-1)
		{
	    	insert(L, key);
    		count++;
		}
		else break;
    }
    iptr root, T;
    root=init(root, 0);
    if(key!=-1)   cout<<"Enter key(-1 to exit)\t";  cin>>key; if(key!=-1) {  add(L, key); root=L->pptr;	root->tag=0;}
	while(key!=-1)
	{
		cout<<"Enter key(-1 to exit)\t";
	    cin>>key;
		T=root;
		if(key!=-1)	add(T,key);
		while(root->pptr!=NULL) root=root->pptr;
	}
	iptr ignore=new(inode);
		ignore->keys[0]=-1;
		ignore->count=0;
		queue Q;
		Q.f=-1;
		Q.r=-1;
		Q.s=50;
		T=root;
		print(Q, T, ignore);
	cout<<endl;
	lptr temp=L;
	while(temp)
	{
		for(int l=0; l<temp->count; l++) cout<<temp->keys[l]<<"  ";
		temp=temp->next;
	}
	temp=L;
	int k1, k2;
	cout<<endl<<"Enter the keys k1 and k2 ";
	cin>>k1>>k2;
	if(k1>k2)
	{
		int x=k1; k1=k2; k2=x;
	}
	bet(temp, k1, k2);
	return 0;
}
