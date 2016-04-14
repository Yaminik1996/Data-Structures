#include<iostream>
using namespace std;
struct knode
{
	int k;
	int *i;
	string *s;
	char *c;
	struct knode *lchild;
	struct knode *rchild;
};
void init(knode *A)
{
	A->i=new int[A->k/3];
	A->s=new string[A->k/3];
	A->c=new char[A->k/3];
}
void copy(knode *A, int i[100], string s[100], char c[100], int k)
{
	init(A);
	A->k=k;
	int count;
	for(count=0; count<k/3; count++)
	{
		A->i[count]=i[count];
		A->s[count]=s[count];
		A->c[count]=c[count];
	}
}
void add(knode *A, int i[100], string s[100], char c[100], int k)
{
	static int a=0;
	if(a>=0&&a<k/3)
	{
		if(i[a]<A->i[a])
		{
			a=(a+1)%k;
			if(A->lchild) add(A->lchild, i, s, c, k);
			else
			{
				A->lchild=new(knode);
				copy(A->lchild, i, s, c, k);
			}
		}
		else
		{
			a=(a+1)%k;
			if(A->rchild) add(A->rchild, i, s, c, k);
			else
			{
				A->rchild=new(knode);
				copy(A->rchild, i, s, c, k);
			}
		}
	}
	else if(a>=k/3&&a<2*k/3)
	{
		if(s[a-k/3]<A->s[a-k/3])
		{
			a=(a+1)%k;
			if(A->lchild) add(A->lchild, i, s, c, k);
			else
			{
				A->lchild=new(knode);
				copy(A->lchild, i, s, c, k);
			}
		}
		else
		{
			a=(a+1)%k;
			if(A->rchild) add(A->rchild, i, s, c, k);
			else
			{
				A->rchild=new(knode);
				copy(A->rchild, i, s, c, k);
			}
		}
	}
	else
	{
		if(c[a-2*k/3]<A->i[a-2*k/3])
		{
			a=(a+1)%k;
			if(A->lchild) add(A->lchild, i, s, c, k);
			else
			{
				A->lchild=new(knode);
				copy(A->lchild, i, s, c, k);
			}
		}
		else
		{
			a=(a+1)%k;
			if(A->rchild) add(A->rchild, i, s, c, k);
			else
			{
				A->rchild=new(knode);
				copy(A->rchild, i, s, c, k);
			}
		}
	}
}
int check(knode *A, int i[100], string s[100], char c[100], int k)
{
	int a, flag=0;
	for(a=0; a<k/3; a++)
	{
		if(i[a]!=A->i[a]||s[a]!=A->s[a]||c[a]!=A->c[a])
		{
			flag=1;
			break;
		}
	}
	if(flag) return 0;
	return 1;
}
int search(knode *A, int i[100], string s[100], char c[100], int k)
{
	static int a=0;
	if(a>=0&&a<k/3)
	{
		if(check(A, i, s, c, k)) return 1;
		if(i[a]<A->i[a])
		{
			a=(a+1)%k;
			if(A->lchild) return search(A->lchild, i, s, c, k);
			else return 0;
		}
		else
		{
			a=(a+1)%k;
			if(A->rchild) return search(A->rchild, i, s, c, k);
			else return 0;
		}
	}
	else if(a>=k/3&&a<2*k/3)
	{
		if(check(A, i, s, c, k)) return 1;
		if(s[a-k/3]<A->s[a-k/3])
		{
			a=(a+1)%k;
			if(A->lchild) return search(A->lchild, i, s, c, k);
			else return 0;
		}
		else
		{
			a=(a+1)%k;
			if(A->rchild) return search(A->rchild, i, s, c, k);
			else return 0;
		}
	}
	else
	{
		if(check(A, i, s, c, k)) return 1;
		if(c[a-2*k/3]<A->c[a-2*k/3])
		{
			a=(a+1)%k;
			if(A->lchild) return search(A->lchild, i, s, c, k);
			else return 0;
		}
		else
		{
			a=(a+1)%k;
			if(A->rchild) return search(A->rchild, i, s, c, k);
			else return 0;
		}
	}
}
int main()
{
	int k;
	cout<<"Enter the value of k";
	cin>>k;
	cout<<"Enter keys ";
	int i[100];
	string s[100];
	char c[100];
	for(int count=0; count<k/3; count++)
	{
		cin>>i[count];
		cin>>s[count];
		cin>>c[count];
	}
	knode *A=new(knode);
	A->k=k;
	init(A);
	for(int count=0; count<k/3; count++)
	{
		A->i[count]=i[count];
		A->s[count]=s[count];
		A->c[count]=c[count];
	}
	A->lchild=NULL;
	A->rchild=NULL;
	char yes='y';
	knode *T=A;
	while(yes=='y'||yes=='Y')
	{	
		T=A;
		cout<<"Enter keys (int, string, char)";
		for(int count=0; count<k/3; count++)
		{
			cin>>i[count];
			cin>>s[count];
			cin>>c[count];
		}
		add(T, i, s, c, k);
		cout<<"More (y/n)? ";
		cin>>yes;
	}
	yes='y';
	while(yes=='y'||yes=='Y')
	{	
		T=A;
		cout<<"Enter keys to be searched (int, string, char)";
		for(int count=0; count<k/3; count++)
		{
			cin>>i[count];
			cin>>s[count];
			cin>>c[count];
		}
		cout<<search(T, i, s, c, k)<<endl;
		cout<<"More (y/n)? ";
		cin>>yes;
	}
	return 0;
}
