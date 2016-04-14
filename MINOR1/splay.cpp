#include<iostream>
using namespace std;
struct snode
{
    int data;
    struct snode *lchild;
	struct snode *rchild;
};
typedef snode  *SPTR;
void insert(struct snode *T, int d)
{
	if(d<T->data)
	{
		if(T->lchild!=NULL)
		{
			T=T->lchild;
			insert(T, d);
		}
		else
		{
			T->lchild=new(snode);
			T=T->lchild;
			T->data=d;
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
	else
	{
		if(T->rchild!=NULL)
		{
			T=T->rchild;
			insert(T, d);
		}
		else
		{
			T->rchild=new(snode);
			T=T->rchild;
			T->data=d;
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
}
struct snode* r_rot(struct snode *k1)
{
    struct snode *k2=k1->lchild;
    k1->lchild=k2->rchild;
    k2->rchild=k1;
    return k2;
}
struct snode* l_rot(struct snode *k1)
{
    struct snode *k2=k1->rchild;
    k1->rchild=k2->lchild;
    k2->lchild=k1;
    return k2;
}
struct snode* shift(struct snode *S, int data)
{
    if(!S) return S;
	if(S->data==data) return S;
    if(data<S->data)
    {
        if(!S->lchild) return S;
 		if(data<S->lchild->data)
        {
        	if(S->lchild->lchild)
        	{
           	S->lchild->lchild=shift(S->lchild->lchild, data);
 			S=r_rot(S);
     		}
	    }
        else if(data>S->lchild->data)
		{
			if(S->lchild->rchild)  
			{
				S->lchild->rchild=shift(S->lchild->rchild,data);
			//if(S->lchild->rchild)    
				S->lchild=l_rot(S->lchild);
        	}
		}
        return r_rot(S);
	}
    else if(data>S->data)
	{
        if (!S->rchild) return S;
 	    if (data>S->rchild->data)
        {
        	if(S->rchild->rchild)
    		{
			S->rchild->rchild = shift(S->rchild->rchild, data);
            S= l_rot(S);
        	}
		}
		else if (data<S->rchild->data)
        {
        	if(S->rchild->lchild)    
			{
				S->rchild->lchild = shift(S->rchild->lchild, data);
 	        //if (S->rchild->lchild) 	 
				S->rchild = r_rot(S->rchild);
        	}
		} 
        return l_rot(S);
    }
}
void preorder(struct snode *S)
{
    if(S)
    {
        cout<<S->data<<"  ";
        preorder(S->lchild);
        preorder(S->rchild);
    }
}
int main()
{
	int d;
	struct snode *S, *T;
	S=new(snode);
	cout<<"Enter data element ";
	cin>>d;
	S->data=d;
	S->lchild=NULL;
	S->rchild=NULL;
	do
	{
		cout<<"Enter data element (-1 to end)";
		cin>>d;
		T=S;
		if(d!=-1)
		insert(T, d);
	}while(d!=-1);
	T=S;
	preorder(T);
	char yes='y';
	while(yes=='y'||yes=='Y')
	{
	cout<<"Enter key to be searched ";
	cin>>d;
	T=S;
	S=shift(S, d);
	T=S;
	//cout<<T->data;
	preorder(T);
	cout<<"Search more?";
	cin>>yes;
	}
	return 0;
}
