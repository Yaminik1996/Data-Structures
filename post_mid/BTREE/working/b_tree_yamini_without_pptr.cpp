#include<iostream>
using namespace std;
struct bnode
{
	int keys[20];
	int count;
	struct bnode *ptr[20];
}*root;
typedef bnode * bptr;
int d;
bptr init(bptr B)
{
	int i;
	B=new(bnode);
	B->count=0;
	for(i=0; i<2*d+1; i++){
	B->ptr[i]=NULL;	
	} 
	return B;
}
bnode * get_parent(bnode * B, bnode * root)
{
	if(!B||!root||B==root) return NULL;
	int i;
	for(i=0; i<2*d+1; i++) if(root->ptr[i]) if(root->ptr[i]==B) return root;
	for(i=0; i<2*d+1; i++) if(root->ptr[i]) return (B, root->ptr[i]);
}
int insert(bptr &B, int key)//not full condition
{
	int i,j,k,temp=0,flag=0;
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
void split(bptr &B, bptr &sib, int key)
{
	bptr B1=NULL, B2=NULL;
	int i,j,m=0;
    i=insert(B,key);
	B2=init(B2);
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
    B1=B;
    B1->count=d;
	sib=B2;
	if(B==root)
    {
    	bptr pptr;
    	pptr=init(pptr);
    	pptr->keys[0]=B->keys[d];
    	pptr->count=1;
    	pptr->ptr[0]=B1;
    	pptr->ptr[1]=B2;
		root=pptr;
	}
    else 
    {
   		bptr pptr=get_parent(B, root);
    	if(pptr->count<2*d)
    	{
    		j=insert(pptr,B->keys[d]);
    		pptr->ptr[j]=B1;
    		pptr->ptr[j+1]=B2;
    	}
    	else
    	{
    		bptr psib=NULL;
    		int x=B->keys[d];
    		bptr pptr1=pptr;    		
    		bptr cb1=B1;
    		bptr cb2=B2;
    		split(pptr, psib, x);
			int z;
			z=find(pptr1, x);
			if(z!=-1)
			{
				pptr1->ptr[z]=cb1;
				pptr1->ptr[z+1]=cb2;
			}
			else
			{
				z=find(psib, x);
				if(z!=-1)
				{
					psib->ptr[z]=cb1;
					psib->ptr[z+1]=cb2;
				}
				else
				{
					pptr1->ptr[d]=cb1;
					psib->ptr[0]=cb2;
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
		else// full leaf
		{
				bptr sib=NULL;
				split(B, sib, key);
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
int main()
{
	int key;
	bptr B, T;
	cout<<"Enter degree of B-tree\t";
	cin>>d;
	cout<<"Enter key(-1 to exit)\t";
	cin>>key;
	if(key!=-1)
	{
	    root=init(root);
		root->keys[0]=key;
		root->count++;
    }
    cout<<"Enter key(-1 to exit)\t";
	cin>>key;
	while(key!=-1)
	{
		T=root;
		add(T,key);
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
	print(Q, root, ignore);
	return 0;
}
