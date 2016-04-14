#include<iostream>
using namespace std;
struct node
{
	node *left;
	int data;
	node *right;
};
void merge(struct node *A, int low, int high, int mid)
{
	int i=low, j=mid+1, k=low, p;
	struct node *B;
	B=new(node); B=A;
	for(p=0; p<i; p++) B=B->right;	
	struct node *C;
	C=new(node); C=A;
	for(p=0; p<j; p++) C=C->right;
	struct node *D, *F;
	F=new(node);
	D=F;
	while(i<=mid&&j<=high)
	{
		if(B->data<C->data)
		{
			i++;k++;
			{
				D->right=new(node);
				D->right->left=D;
				D=D->right;
				D->data=B->data; 
				B=B->right;
				D->right=NULL;
			}
		}
		else
		{
			j++;k++;
			{
				D->right=new(node);
				D->right->left=D;
				D=D->right;
				D->data=C->data; 
				C=C->right;
				D->right=NULL;
			}
		}
	}
		while(i<=mid)
		{
			{
				D->right=new(node);
				D->right->left=D;
				D=D->right;
				D->data=B->data; 
				B=B->right;
				D->right=NULL;
			}
			i++;k++;
		}
		while(j<=high)
		{
			j++;k++;
			{
				D->right=new(node);
				D->right->left=D;
				D=D->right;
				D->data=C->data; 
				C=C->right;
				D->right=NULL;
			}
		}
		D=F->right;
		struct node *G=A;
		for(p=0; p<low; p++) G=G->right;
		for(p=low; p<k; p++)
		{
			G->data=D->data;
			G=G->right;
			D=D->right;
		}
	}
void mergesort(struct node *A, int low, int high)
{
	int mid;
	if(low<high)
	{
	mid=(low+high)/2;
	mergesort(A, low, mid);
	mergesort(A, mid+1, high);
	merge(A, low, high, mid);
	}
}
int main()
{
	struct node *D, *T;
	cout<<"Enter data element ";
	int d;
	cin>>d;
	D=new(node);
	D->data=d;
	D->left=NULL;
	D->right=NULL;
	T=D;
	int i=0;
	char m='y';
	do
	{
	cout<<" Enter next data element ";
	cin>>d;
	T->right=new(node);
	T->right->left=T;
	T=T->right;
	T->data=d;
	T->right=NULL;
	i++;
	cout<<"More? ";
	cin>>m;
	}while(m=='y');
	int size=i;
	cout<<size;
	cout<<endl;
	mergesort(D, 0, size);
	T=D;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->right;
	}
	return 0;
}
