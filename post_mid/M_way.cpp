#include<iostream>
using namespace std;
struct mnode
{
	int full;
	int *ele;
	struct mnode **child;
};
void init(mnode *M, int m)
{
	M->full=0;
	M->ele=new int[m-1];
	M->child=new mnode* [m];
	for(int i=0; i<m; i++) M->child[i]=NULL;
}
int isFull(mnode *M, int m)
{
	if(M->full==m-1) return 1;
	return 0;
}
int find(mnode *M, int m, int data)
{
	if(data<M->ele[0]) return 0;
	for(int i=0; i<M->full; i++)
	{
		if(data>M->ele[i]&&data<M->ele[i+1])
			return i+1;
	}
}
void insert(mnode *M, int m, int data)
{
	if(!isFull(M, m))
	{
		if(M->full==0) 
		{
			M->ele[M->full++]=data;
			return;
		}
		else if(data>M->ele[M->full])
		{
			M->ele[M->full++]=data;
			return;
		}
	}
	int pos=find(M, m, data);
	if(M->child[pos]) insert(M->child[pos], m, data);
	else
	{
		M->child[pos]=new(mnode);
		init(M->child[pos], m);
		insert(M->child[pos], m, data);
	}
}
int search(mnode *M, int m, int data)
{
	for(int i=0; i<M->full; i++)
	{
		if(M->ele[i]==data) return 1;
	}
	int pos=find(M, m, data);
	if(M->child[pos]) return search(M->child[pos], m, data);
	else return 0; 
}
void print(mnode *M, int m)
{
	int i;
	if(!M) return;
	for(i=0; i<M->full; i++) cout<<M->ele[i]<<"  ";
	cout<<endl;
	for(i=0; i<m; i++)
	{
		if(M->child[i]) print(M->child[i], m);
	}
}
int main()
{
	mnode *M, *T;
	int m, data;
	cout<<"Enter the value of m ";
	cin>>m;
	M=new(mnode);
	init(M, m);
	char yes='Y';
	cout<<"Enter data elements \n";
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter : ";
		cin>>data;
		T=M;
		insert(T, m, data);
		cout<<"More ? (y/n)";
		cin>>yes;
	}
	cout<<M->ele[0];
	yes='Y';
	T=M;
	print(T, m);
	cout<<"Enter data elements to be searched ";
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter : ";
		cin>>data;
		T=M;
		cout<<search(T, m, data)<<endl;
		cout<<"More ? (y/n)";
		cin>>yes;
	}
	return 0;
}
