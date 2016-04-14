#include<iostream>
using namespace std;
struct bnode
{
	int keys[20];
	int count;
	struct bnode *ptr[20];
	struct bnode *pptr;
}*B;
typedef bnode * bptr;
int d;
void del(bnode *found, int key, int index);
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
	//cout<<"finding "<<key;
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
    		split(B->pptr, psib, x);
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
bnode * search(bnode * B, int key, int &index)
{
	int i, j;
	for(i=0; i<B->count; i++) 
	{
		index=i;
		if(B->keys[i]==key) return B;
	}
	int x=find_index(B, key);
	if(B->ptr[x])
	return search(B->ptr[x], key, index);
	else return NULL;
}
int child_index(bnode *B)
{
	if(!B->pptr) return -1;
	bptr T=B->pptr;
	for(int i=0; i<=2*d; i++)
	{
		if(T->ptr[i]==B) return i;
	}
}
void remove(bnode *B, int key, int index)
{
	for(int i=index; i<B->count-1; i++)
	{
		B->keys[i]=B->keys[i+1];
		B->ptr[i+1]=B->ptr[i+2];
	}
	B->count--;
}
int l_key(bnode *B, int key, int index)
{
	int x=child_index(B);
	if(x==-1||x==0) return -1;
	int y=x-1;
	bptr lsib=B->pptr->ptr[y];
	if(lsib->count<=d) return -1;
	remove(B, key, index);
	cout<<B->pptr->keys[y];
	int a1=insert(B, B->pptr->keys[y]);
	B->pptr->keys[y]=lsib->keys[lsib->count-1];
	lsib->count--;
	return 1;
}
int r_key(bnode *B, int key, int index)
{
	int x=child_index(B);
	if(x==-1||x==2*d) return -1;
	int y=x+1;
	bptr rsib=B->pptr->ptr[y];
	if(rsib->count<=d) return -1;
	remove(B, key, index);
	int a1=insert(B, B->pptr->keys[x]);
	B->pptr->keys[x]=rsib->keys[0];
	for(a1=rsib->count-2; a1>=0; a1--)
		rsib->keys[a1]=rsib->keys[a1+1];
	rsib->count--;
	return 1;
}
void mergeleaf(bnode * B, int key)
{
	int i, j, y;
	bnode *B1=new(bnode); B1=init(B1);
	int x=child_index(B);
	if(x>0)
	{
		y=x-1;
		bnode *lsib=B->pptr->ptr[y];
		j=0;
		for(i=0; i<lsib->count; i++)
		{
			B1->keys[j++]=lsib->keys[i];
		}
		B1->keys[j++]=B->pptr->keys[y];
		for(i=0; i<B->count; i++)
		{
			if(B->keys[i]!=key) {B1->keys[j++]=B->keys[i];}
		}
		B1->count=j;
		B->pptr->ptr[y]=B1;
		remove(B->pptr, key, y);
	}
	else
	{
		y=x+1;
		bnode *lsib=B->pptr->ptr[y];
		j=0;
		for(i=0; i<B->count; i++)
		{
			if(B->keys[i]!=key) B1->keys[j++]=B->keys[i];
		}
		B1->keys[j++]=B->pptr->keys[x];
		for(i=0; i<lsib->count; i++)
		{
			B1->keys[j++]=lsib->keys[i];
		}
		B->pptr->ptr[x]=B1;
		B1->count=j;
		remove(B->pptr, key, x);
	}
}
int l_key_2(bnode * found, int key, int index)
{
	if(found->ptr[index]->count<=d) return -1;
	bnode * lchild=found->ptr[index];
	found->keys[index]=lchild->keys[lchild->count-1];
	lchild->count--;
	return 1;
}
int r_key_2(bnode * found, int key, int index)
{
	bnode * rchild=found->ptr[index+1];
	if(rchild->count<=d) return -1;
	found->keys[index]=rchild->keys[0];
	remove(rchild, key, 0);
	return 1;
}
void del(bnode *found, int key, int index)
{
	int i, tag=1;
	for(i=0; i<2*d+1; i++)
	{
		if(found->ptr[i]!=NULL)
		{
			tag=0;//not a leaf 
			break;
		}
	}
	if(tag)
	{
		if(found->count>d) remove(found, key, index);
		else
		{
			int x=l_key(found, key, index);
			if(x==-1)	x=r_key(found, key, index);
			if(x==-1) mergeleaf(found, key);
		}
	}
	else if(!tag)
	{
		int x=l_key_2(found, key, index);
		if(x==-1) x=r_key_2(found, key, index);
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
	int key, del1;
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
	cout<<"Enter element to be deleted ";
	cin>>del1;
	T=B;
	int index;
	bnode * found=search(T, del1, index);
	if(!found)
	{
		cout<<"Key isn't present";
	}
	else	{
	del(found, del1, index);
	}
	Q.f=-1;
	Q.r=-1;
	Q.s=50;
	T=B;
	print(Q, T, ignore);
	return 0;
}
