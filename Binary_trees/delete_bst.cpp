#include<iostream>
#include<stdlib.h>
using namespace std;
struct btnode
{
	struct btnode *lchild;
	int data;
	struct btnode *rchild;
};
typedef struct btnode *BSTPTR;
void insert(BSTPTR T, int d)
{
	if(T==NULL)
	{
		T=new(btnode);
		T->data=d;
		T->lchild=NULL;
		T->rchild=NULL;
		return;
	}
	else if(d<T->data)
	{
		if(T->lchild!=NULL)
		{
			T=T->lchild;
			insert(T, d);
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
		if(T->rchild!=NULL)
		{
			T=T->rchild;
			insert(T, d);
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
void inorder(BSTPTR T)
{
	if(T==NULL) cout<<"  ";
	else
	{
		inorder(T->lchild);
		cout<<T->data;
		inorder(T->rchild);
	}
}
struct btnode* Delete(struct btnode *T, int data) {
	if(T == NULL) return T; 
	else if(data < T->data) T->lchild = Delete(T->lchild,data);
	else if (data > T->data) T->rchild = Delete(T->rchild,data);
	else {
		if(T->lchild == NULL && T->rchild == NULL) { 
			delete T;
			T = NULL;
		}
		else if(T->lchild == NULL) {
			struct btnode *temp = T;
			T = T->rchild;
			delete temp;
		}
		else if(T->rchild == NULL) {
			struct btnode *temp = T;
			T = T->lchild;
			delete temp;
		}
		else { 
			struct btnode *temp=T->rchild;
			while(temp->lchild!=NULL) temp=temp->lchild;
			T->data = temp->data;
			T->rchild = Delete(T->rchild,temp->data);
		}
	}
	return T;
}
int main()
{
	int d;
	BSTPTR B, T;
	B=new(btnode);
	cout<<"Enter data element ";
	cin>>d;
	B->data=d;
	B->lchild=NULL;
	B->rchild=NULL;
	do
	{
		cout<<"Enter data element (-1 to end)";
		cin>>d;
		T=B;
		if(d!=-1)
		insert(T, d);
	}while(d!=-1);
	T=B;
	cout<<endl;
	inorder(T);
	cout<<"Enter node which has to be deleted  ";
	int k;
	cin>>k;
	T=B;
	B=Delete(T, k);
	inorder(T);
	return 0;
}
