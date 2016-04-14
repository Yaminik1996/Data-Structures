#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
void insert_end(struct node *T, int a)
{
	struct node *L=T;
	while(L->next!=NULL)
	{
		L=L->next;
	}
	struct node *P=new (node);
	P->data=a;
	P->next=NULL;
	L->next=P;
}
void del(struct node *P)
{
	P->next=P->next->next;	
}
int main()
{
	struct node *T[10], *L, *X;
	struct node *R[10];
	int A[50], i=0, a, b, c, k, j;
	cout<<"Enter elements : ";
	char ch='y';
	for(k=0; k<10; k++)
	{
	R[k]=new(node);
	R[k]->data=k;
	R[k]->next=NULL;
	}
	while(ch=='y')
	{
		cin>>A[i++];
		cout<<"More?";
		cin>>ch;
	}
	int size=i;
	for(i=0; i<size; i++)
	{
		k=A[i];
		k=k%10;
		insert_end(R[k], A[i]);		
	}
	b=0;
	cout<<endl;
	for(a=0; a<10; a++)
	{
		L=R[a];
		X=R[a];
		while(L->next!=NULL)
		{
			L=L->next;
			A[b++]=L->data;	
			del(X);
		}
	}
	for(c=0; c<b; c++)
		cout<<A[c]<<" ";
	for(i=0; i<size; i++)
	{
		k=A[i];
		k=k/10;
		k=k%10;
		insert_end(R[k], A[i]);		
	}
	b=0;
	cout<<endl;
	for(a=0; a<10; a++)
	{
		L=R[a];
		X=R[a];
		while(L->next!=NULL)
		{
			L=L->next;
			A[b++]=L->data;	
			del(X);
		}
	}
	for(c=0; c<b; c++)
		cout<<A[c]<<" ";
	for(i=0; i<size; i++)
	{
		k=A[i];
		k=k/100;
		k=k%10;
		L=R[k];
		insert_end(R[k], A[i]);		
	}
	b=0;
	cout<<endl;
	for(a=0; a<10; a++)
	{
		L=R[a];
		X=R[a];
		while(L->next!=NULL)
		{
			L=L->next;
			A[b++]=L->data;	
			del(X);
		}
	}
	for(c=0; c<b; c++)
		cout<<A[c]<<" ";
	return 0;
}
