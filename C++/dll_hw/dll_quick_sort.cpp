#include<iostream>
using namespace std;
struct dnode
{
	struct dnode * left;
	int data;
	struct dnode *right;
};
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
int partition(dnode *A, int low, int high)
{
	dnode *B=A, *C=A, *D=A;
	int i, h=high;
	for(i=0; i<low; i++){ B=B->right; D=D->right;} 
	for(i=0; i<h; i++) C=C->right;
	int p=D->data;
	int l=low;
	while(l<=h)
	{
		while(B->data<=p){ B=B->right; l++;}
		while(C->data>p){ C=C->left; h--;}
		if(l<h) swap(B->data, C->data);
	}
	swap(D->data, C->data);
	return h;
}
void quicksort(dnode *A, int low, int high)
{
	int j;
	if(low<high)
	{
	j=partition(A, low, high);
	quicksort(A, low, j-1);
	quicksort(A, j+1, high);
	}
}
int main()
{
	struct dnode *D, *T;
	cout<<"Enter data element ";
	int d, i=0;
	cin>>d;
	D=new(dnode);
	D->data=d;
	D->left=NULL;
	D->right=NULL;
	T=D;
	char m='y';
	do
	{
	cout<<" Enter next data element ";
	cin>>d;
	T->right=new(dnode);
	T->right->left=T;
	T=T->right;
	T->data=d;
	T->right=NULL;
	i++;
	cout<<"More? ";
	cin>>m;
	}while(m=='y');
	cout<<endl;
	int n=0;
	quicksort(D, n, i);
	dnode *A=D;
	while(A!=NULL)
	{
		cout<<A->data<<" ";
		A=A->right;
	}
	return 0;
}
