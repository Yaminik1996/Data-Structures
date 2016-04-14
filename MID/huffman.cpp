#include<iostream>
using namespace std;
struct hnode
{
	int tag;
	union
	{
		char data;
		struct
		{
			hnode * lchild;
			hnode * rchild;
		}S;
	}U;
};
hnode * insert(hnode *H, char d, char code[10], int i)
{
	if(code[i]=='\0')
	{
		cout<<"NULL char found ";
		H->tag=0;
		H->U.data=d;
		return H;
	}
	else if(code[i]=='0')
	{
		cout<<"Code not NULL, going to left ";
		if(H->U.S.lchild) insert(H->U.S.lchild, d, code, i+1);
		else
		{
			H->U.S.lchild=new(hnode);
			H->U.S.lchild->U.S.lchild=NULL;
			H->U.S.lchild->U.S.rchild=NULL;
			H->tag=1;
			insert(H->U.S.lchild, d, code, i+1);
		}
	}
	else if(code[i]=='1')
	{
		cout<<"Code not NULL, going to right ";
		if(H->U.S.rchild) insert(H->U.S.lchild, d, code, i+1);
		else
		{
			H->U.S.rchild=new(hnode);
			H->U.S.rchild->U.S.lchild=NULL;
			H->U.S.rchild->U.S.rchild=NULL;
			H->tag=1;
			insert(H->U.S.rchild, d, code, i+1);
		}
	}
}
void print(hnode *H)
{
	if(H->tag==0) cout<<H->U.data<<"  ";
	else
	{
		if(H->U.S.lchild) print(H->U.S.lchild);
		if(H->U.S.rchild) print(H->U.S.rchild);
	}
}
int main()
{
	char code[10];
	char d;
	hnode *H=new(hnode), *T, *P;
	H->tag=1;
	H->U.S.lchild=NULL;
	H->U.S.rchild=NULL;
	char yes='y';
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter code ";
		cin>>code;
		cout<<"Enter character ";
		cin>>d;
		T=H;
		P=insert(T, d, code, 0);
		cout<<P->U.data;
		cout<<"More ?";
		cin>>yes;
	}
	T=H;
	print(T);
	return 0;
}
