#include<iostream>
using namespace std;
struct btnode
{
	struct btnode *lchild;
	int data;
	struct btnode *rchild;
};
struct node
{
	char data;
	struct node *next;
	struct btnode *bstptr;
};
struct node *L, *T;
node * create()
{
	L=new(node);
	char d;
	cout<<"Enter element";
	cin>>d;
	L->data=d;
	L->bstptr=NULL;
	L->next=NULL;
	T=L;
	while(d!='/')
	{
		cout<<"Enter element(/ to end)";
		cin>>d;
		if(d!='/')
		{
		T->next=new(node);
		T=T->next;
		T->data=d;
		T->bstptr=NULL;
		T->next=NULL;
		}
	}
	T=L;
	return T;
}
void insert_tree(btnode * T, int d)
{
	cout<<"In insert_tree";
	if(d<T->data)
	{
		cout<<"case 1 of Insert";
		if(T->lchild!=NULL)
		{
			T=T->lchild;
			insert_tree(T, d);
		}
		else
		{
			T->lchild=new(btnode);
			T=T->lchild;
			T->data=d;
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
	else
	{
		cout<<"case 2 of Insert";
		if(T->rchild!=NULL)
		{
			T=T->rchild;
			insert_tree(T, d);
		}
		else
		{
			T->rchild=new(btnode);
			T=T->rchild;
			T->data=d;
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
}
void insert(node* T, char data, int key)
{
	node* P=T;
	while(P->data!=data&&P!=NULL)	P=P->next;
	if(P==NULL)
	{
		cout<<"case 1";
		P->next=new(node);
		P->data=data;
		P->bstptr=new(btnode);
		P->bstptr->data=key;
		P->bstptr->lchild=NULL;
		P->bstptr->rchild=NULL;
		return;
	}
	else
	{
		cout<<"case 2";
		if(P->bstptr)
		{
		insert_tree(P->bstptr, key);
		return;
		}
		else
		{
			P->bstptr=new(btnode);
			P->bstptr->data=key;
			P->bstptr->lchild=NULL;
			P->bstptr->rchild=NULL;
			return;
		}
	}
}
int search(node *T, btnode * B, char data, int key, int &flag)
{
	if(!T)
	{
		cout<<"Node is NULL";
		return 0;
	}
	if(!flag)
	{
	cout<<"flag is 0";
	if(T->data==data)
	{
		flag=1;
		return search(T, B, data, key, flag);
	}
	else return search(T->next, T->next->bstptr, data, key, flag);
	}
	else if(flag)
	{
		cout<<"flag is 1";
		if(!B)
		{
			cout<<"Btnode is NULL";
			return 0;
		}
		if(B->data==key) return 1;
		else if(key<B->data) return search(T, B->lchild, data, key, flag);
		else if(key>B->data) return search(T, B->rchild, data, key, flag);
	}
}
struct stack
{
	btnode *A[50];
	int top;
	int size;
};
void push(stack &S, btnode *x)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
		S.A[++S.top]=x;
}
btnode * pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
		return S.A[S.top--];
}
void print(node *T)
{
	if(!T) return;
	cout<<T->data<<"  :  ";
	stack S; S.top=-1; S.size=50;
	btnode *cur=T->bstptr;
	int done=0;
	while(!done)
	{
	if(cur!=NULL) 
	{
		push(S, cur);
		cur=cur->lchild;
	}
	else
	{
	if(S.top!=-1)
	{
		cur=pop(S);
		cout<<cur->data<<"  ";
		cur=cur->rchild;		
	}
	else done=1;
	}
	}
	cout<<endl;
	print(T->next);
}
int main()
{
	char data;
	int key;
	L=create();
	char yes='y';
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter data ";
		cin>>data;
		cout<<"Enter key ";
		cin>>key;
		T=L;
		insert(T, data, key);
		cout<<"More(y/n)?";
		cin>>yes;
	}
	yes='y';
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter data";
		cin>>data;
		cout<<"Enter key";
		cin>>key;
		T=L;
		int flag=0;
		cout<<search(T, T->bstptr, data, key, flag);
		cout<<endl<<"More ?";
		cin>>yes;
	}
	cout<<endl;
	T=L;
	print(T);
	return 0;
}
