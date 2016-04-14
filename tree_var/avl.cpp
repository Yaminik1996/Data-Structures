#include<iostream>
using namespace std;
struct anode
{
	int data;
	struct anode *left;
	struct anode *right;
};
int max(int a, int b)
{
	(a>b):return a ?	return b;
}
int height(anode *A)
{
	int h=-1;
	if(A!=NULL)
	{
		h=1+max(height(A->left), height(A->right));
	}
	return h;
}
int dif(anode *A)
{
	return height(A->left)-height(A->right);
}
anode* l_rot(anode *k1)
{
	anode *temp=new(anode);
	temp=k1->right;
	k1->right=temp->left;
	temp->left=k1;
	return temp;
}
anode* r_rot(anode *k1)
{	
	anode *temp=new(anode);
	temp=k1->left;
	k1->left=temp->right;
	temp->right=k1;
	return temp;
}
anode* l_r_rot(anode *k3)
{
	anode *k1=new(anode);
	k1=k3->left;
	anode *k2=new(anode);
	k2=k1->right;
	anode *temp=new(anode);
	temp=k1->right;
	k1->right=k2->left;
	k3->left=k2->right;
	k2->left=k1;
	k2->right=k3;
	return k2;
}
anode* r_l_rot(anode *k3)
{
	anode *k1=new(anode);
	k1=k3->right;
	anode *k2=new(anode);
	k2=k1->left;
	anode *temp=new(anode);
	temp=k1->left;
	k1->left=k2->right;
	k3->right=k2->left;
	k2->left=k3;
	k2->right=k1;
	return k2;
}
anode* insert(anode* A, int data)
{
	if(A==NULL)
	{
		A=new(anode);
		A->data=data;
		A->left=NULL;
		A->right=NULL;
		return A;
	}
	if(data<A->data)	A->left=insert(A->left, data);
	else	A->right=insert(A->right, data);
	int d=dif(A);
	if(d>1&&data<A->left->data)	return r_rot(A);
	if(d<-1&&data>A->right->data)	return l_rot(A);
	if(d>1&&data>A->left->data)	return l_r_rot(A);
	if(d<-1&&data<A->right->data)	return r_l_rot(A);
	return A;
}
struct queue
{
	int s;
	anode *ele[50];
	int f;
	int r;
};
void enq(queue &Q, anode *d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
anode* deq(queue &Q)
{
	anode *p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void level(anode *T, anode *A) {
	if(T== NULL) return;
	queue Q; Q.f=-1; Q.r=-1; Q.s=50;
	enq(Q, T);
	enq(Q, A);
	while(Q.f!=-1) {
		if(Q.ele[Q.f]->data==-1) 
		{
		cout<<endl;
		enq(Q, deq(Q));
		}
		anode* current = deq(Q);
		cout<<current->data<<"     ";
		if(current->left != NULL) enq(Q, current->left);
		if(current->right != NULL) enq(Q,current->right);
	}
}
int main()
{
	int d;
	anode *A=NULL;
	while(d!=-1)
	{
		cin>>d;
		if(d!=-1)
		A=insert(A, d);
	}
	anode *B=new(anode);
	B->data=-1;
	B->left=NULL;
	B->right=NULL;
	level(A, B);
	return 0;
}
