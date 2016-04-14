#include<iostream>
using namespace std;
struct pnode
{
	int data;
	char key;
	struct pnode *left;
	struct pnode *right;
};
pnode* l_rot(pnode *k1)
{
	pnode *temp=new(pnode);
	temp=k1->right;
	k1->right=temp->left;
	temp->left=k1;
	return temp;
}
pnode* r_rot(pnode *k1)
{	
	pnode *temp=new(pnode);
	temp=k1->left;
	k1->left=temp->right;
	temp->right=k1;
	return temp;
}
pnode* insert(pnode* A, int data, char key)
{
	if(A==NULL)
	{
		A=new(pnode);
		A->data=data;
		A->key=key;
		A->left=NULL;
		A->right=NULL;
		return A;
	}
	if(key<A->key)	A->left=insert(A->left, data, key);
	else	A->right=insert(A->right, data, key);
	int k1=data;
	if(A->left!=NULL)
	{
		int k2=A->left->data;
		if(k1>k2)	return r_rot(A);
	}
	if(A->right!=NULL)
	{
		int k3=A->right->data;
		if(k1>k3)	return l_rot(A);
	}
	return A;
}
struct queue
{
	int s;
	pnode *ele[50];
	int f;
	int r;
};
void enq(queue &Q, pnode *d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
pnode* deq(queue &Q)
{
	pnode *p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void level(pnode *T, pnode *A)
{
	if(T== NULL) return;
	queue Q; Q.f=-1; Q.r=-1; Q.s=50;
	enq(Q, T);
	enq(Q, A);
	while(Q.f!=-1) {
		if(Q.ele[Q.f]->key=='*') 
		{
		cout<<endl;
		enq(Q, deq(Q));
		}
		pnode* current = deq(Q);
		cout<<current->data<<current->key<<"  ";
		if(current->left != NULL) enq(Q, current->left);
		if(current->right != NULL) enq(Q,current->right);
	}
}
int main()
{
	int d;
	char k;
	pnode *A=NULL;
	while(d!=-1)
	{
		cin>>d;
		cin>>k;
		if(d!=-1)	A=insert(A, d, k);
	}
	pnode *B=new(pnode);
	B->data=-1;
	B->key='*';
	B->left=NULL;
	B->right=NULL;
	level(A, B);
	return 0;
}
