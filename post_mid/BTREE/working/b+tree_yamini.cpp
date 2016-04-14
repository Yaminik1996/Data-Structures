#include<iostream>
using namespace std;
struct bnode
{
	int keys[20];
	int count;
	struct bnode *ptr[20];
	struct bnode *pptr;
};
typedef bnode * bptr;
int d;
bptr init(bptr B)
{
	int i;
	B=new(bnode);
	B->pptr=NULL;
	B->count=0;
	for(i=0; i<2*d+1; i++){
	B->ptr[i]=NULL;
	B->keys[i]=-10000;	
	} 
	return B;
}
int insert(bptr &B, int key)//not full condition
{
	int i, j,k,temp=0,flag=0;
	bptr temp1, temp2;
	if(!B) cout<<"B is null ";
	for(i=0; i<B->count; i++)
	{
		if(key<B->keys[i])
		{
			for(j=B->count-1; j>=i; j--)
			{
				B->keys[j+1]=B->keys[j];
				B->ptr[j+2]=B->ptr[j+1];
				B->ptr[j+1]=NULL;
			}
			break;
		}
	}
	++B->count;
	B->keys[i]=key;
	for (j=0;j<B->count;j++)
	return i;
}
int find_index(bptr B, int key)//finding pointer index
{
	if(key<B->keys[0]) return 0;
	if(key>B->keys[B->count-1]) return B->count;
	for(int i=0; i<B->count-1; i++)
	{
		if(key>B->keys[i]&&key<B->keys[i+1]) return i+1;
	}
}
int find(bptr B, int key)//to check if key exists
{
	for(int i=0; i<B->count; i++)
	{
		if(B->keys[i]==key) return i;
	}
	return -1;
}
void split(bptr &B, bptr &sib, int key, int tag)
{
	bptr B1=NULL, B2=NULL;
	int i,j,m=0;
    i=insert(B,key);
	B2=init(B2);
	if(tag==0)
	{
    for(j=d+1;j<=2*d;j++)
    {
    	B2->keys[m]=B->keys[j];
    	B2->ptr[m]=B->ptr[j];
    	B2->ptr[m+1]=B->ptr[j+1];
    	B->ptr[j]=NULL;
		m++;
    }
    B->ptr[j]=NULL;
    B2->count=d;
    }
    else
    {
    for(j=d;j<=2*d;j++)
    {
    	B2->keys[m]=B->keys[j];
    	B2->ptr[m]=B->ptr[j];
    	B2->ptr[m+1]=B->ptr[j+1];
    	B->ptr[j]=NULL;
		m++;
    }
    B->ptr[j]=NULL;
    B2->count=d+1;
	}
	B1=B;
    B1->count=d;
	sib=B2;
	if(tag==1)
	{
		B1->ptr[2*d]=new(bnode);
		B1->ptr[2*d]=B2;
	}/*
	if(tag==1)
	{
		B2->ptr[0]=new(bnode);
		B2->ptr[0]=B1;
	}*/
	if(B->pptr==NULL)
    {
    	B->pptr=init(B->pptr);
    	B->pptr->keys[0]=B->keys[d];
    	B->pptr->count=1;
    	B->pptr->ptr[0]=B1;
    	B->pptr->ptr[1]=B2;
    	B2->pptr=B->pptr;
    	B1->pptr=B->pptr;
	}
    else 
    {
    	if(B->pptr->count<2*d)
    	{
    		j=insert(B->pptr,B->keys[d]);
    		B->pptr->ptr[j]=B1;
    		B->pptr->ptr[j+1]=B2;
    		B2->pptr=B->pptr;
    		B1->pptr=B->pptr;
		}
    	else
    	{
    		bptr psib=NULL;
    		int x=B->keys[d];
    		bptr pptr1=B->pptr;	
    		bptr cb1=B1;
    		bptr cb2=B2;
    		split(B->pptr, psib, x, 0);
			int z;
			z=find(pptr1, x);
			if(z!=-1)
			{
				pptr1->ptr[z]=cb1;
				pptr1->ptr[z+1]=cb2;
				cb1->pptr=pptr1;
				cb2->pptr=pptr1;
			}
			else
			{
				z=find(psib, x);
				if(z!=-1)
				{
					psib->ptr[z]=cb1;
					psib->ptr[z+1]=cb2;
					cb1->pptr=psib;
					cb2->pptr=psib;
				}
				else
				{
					pptr1->ptr[d]=cb1;
					cb1->pptr=pptr1;
					psib->ptr[0]=cb2;
					cb2->pptr=psib;
				}
			}
		}
    }
}
void add(bptr &B, int key)//basic add function
{
	int i, tag=1;
	for(i=0; i<2*d+1; i++)
	{
		if(B->ptr[i]!=NULL)
		{
			tag=0;//not a leaf 
			break;
		}
	}
	if(tag)
	{
		if(B->count<2*d)//a leaf not full
		{
			i=insert(B, key);
			B->ptr[i]=NULL;
			B->ptr[i+1]=NULL;
		}
		else//full leaf
		{
				bptr sib=NULL;
				split(B, sib, key, 1);
		}
	}
	else//finding leaf
	{
		int i=find_index(B, key);
		add(B->ptr[i], key);
	}
}
struct queue
{
	int s;
	bptr ele[50];
	int f;
	int r;
};
void enq(queue &Q, bptr d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
bptr deq(queue &Q)
{
	bptr p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void print(queue &Q, bptr B, bptr ignore)
{
	int j;
	enq(Q, B);
	enq(Q, ignore);
	while(Q.f!=-1)
	{
		if(Q.f==Q.r) break;
		bptr T=deq(Q);
		if(T->keys[0]!=-1)
		{
			for(j=0;j<T->count;j++)
			{
				cout<<T->keys[j]<<" ";
			}
			for(j=0;j<=T->count;j++)
			{
				if(T->ptr[j]!=NULL) enq(Q,T->ptr[j]);
			}
    	}
    	else
    	{
    		cout<<endl;
    		enq(Q, ignore);
		}
	}
}
void print_l(bnode * B)
{
	int i;
	while(B->ptr[0]) B=B->ptr[0];
	while(B)
	{
		for(i=0; i<B->count; i++) cout<<B->keys[i]<<"   ";
		B=B->ptr[2*d];
	}
}
int main()
{
	int key;
	bptr B;
	cout<<"Enter degree of B-tree\t";
	cin>>d;
	cout<<"Enter key(-1 to exit)\t";
	cin>>key;
	if(key!=-1)
	{
	    B=init(B);
		B->keys[0]=key;
		B->count++;
    }
    cout<<"Enter key(-1 to exit)\t";
	cin>>key;
	while(key!=-1)
	{
		add(B,key);
		while(B->pptr!=NULL) B=B->pptr;
		cout<<"Enter key(-1 to exit)\t";
	    cin>>key;
	}
	bptr ignore=new(bnode);
	ignore->keys[0]=-1;
	ignore->count=0;
	queue Q;
	Q.f=-1;
	Q.r=-1;
	Q.s=50;
	bptr T=B;
	print(Q, T, ignore);
	T=B;
	cout<<endl<<"Printing leaves "<<endl;
	print_l(T);
	return 0;
}
