#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct gnode
{
	char data;
	bool visited;
	int degree;
	struct gnode *neighbour[20];
};
void connect(gnode *A, gnode *B)
{
	++A->degree;
	++B->degree;
	A->neighbour[A->degree]=new(gnode);
	B->neighbour[B->degree]=new(gnode);
	A->neighbour[A->degree]=B;
	B->neighbour[B->degree]=A;
}
gnode * init(gnode *A, char label)
{
	A->degree=-1;
	A->data=label;
	A->visited=false;
	return A;
}
void print(gnode * vertex[], int n)
{
	int i, j;
	for(i=0; i<n; i++) 
	{
		cout<<vertex[i]->data<<"\t"<<vertex[i]->degree<<"\t";
		for(j=0; j<vertex[i]->degree; j++) cout<<vertex[i]->neighbour[j]->data<<"\t";
		cout<<endl;
	}
}
int main()
{
	struct gnode * vertex[20];
	gnode *A, *B;
	int i=0;
	char yes='y', l1, l2;
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter the vertex label : ";
		cin>>l1;
		vertex[i]=new(gnode);
		vertex[i]=init(vertex[i], l1);
		++i;
		cout<<"More ? ";
		cin>>yes;
	}
	int count=i;
	cout<<"Enter edges : ";
	yes='y';
	while(yes=='y'||yes=='Y')
	{
		cin>>l1>>l2;
		for(i=0; i<count; i++) if(vertex[i]->data==l1) { A=vertex[i]; break; }
		for(i=0; i<count; i++) if(vertex[i]->data==l2) { B=vertex[i]; break; }
		connect(A, B);
		cout<<"More ? ";
		cin>>yes;
	}
	cout<<endl;
	print(vertex, count);
	return 0;
}
