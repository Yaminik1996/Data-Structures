#include<iostream>
#include<string.h>
using namespace std;
struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};
typedef btnode *BTPTR;
int get_index(char in[100], char a, int beg, int end)
{
	int i;
	for(i=beg; i<end+1; i++)
	{
		if(in[i]==a) return i;
	}
	return -1;
}
BTPTR construct(char pre[100], char in[100], int beg, int end)
{
	static int p_index=0;
	if(beg>end) return NULL;
	BTPTR TREE=new(btnode);
	TREE->data=pre[p_index];
	TREE->lchild=NULL;
	TREE->rchild=NULL;
	++p_index;
	if(beg==end) return TREE;
	int i_index=get_index(in, TREE->data, beg, end);
	TREE->lchild=construct(pre, in, beg, i_index-1);
	TREE->rchild=construct(pre, in, i_index+1, end);
	return TREE;
}
void inorder(BTPTR T)
{
	if(T==NULL) cout<<"  ";
	else
	{
		inorder(T->lchild);
		cout<<T->data;
		inorder(T->rchild);
	}
}
void preorder(BTPTR T)
{
	if(T==NULL) cout<<"  ";
	else
	{
		cout<<T->data<<"  ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
int main()
{
	char pre[100], in[100];
	cout<<"Enter preorder sequence ";
	cin>>pre;
	cout<<"Enter inorder sequence ";
	cin>>in;
	BTPTR L=new(btnode);
	int beg=0, end=strlen(pre)-1;
	//cout<<beg<<"  "<<end;
	BTPTR T=new(btnode);
	T=L;
	//T->lchild=NULL;
	//T->rchild=NULL;
	L=construct(pre, in, beg, end);
	T=L;
	inorder(T);
	cout<<"1."<<endl;
	T=L;
	preorder(T);
	cout<<"2.";
	return 0;
}
