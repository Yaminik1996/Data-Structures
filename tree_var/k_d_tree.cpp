#include<iostream>
using namespace std;
struct knode
{
	knode *lchild;
	int data[100];
	knode *rchild;
};
typedef knode *kptr;
void insert(kptr T, int k[], int size)
{
	int j;
	static int i=0;
	if(k[i]<T->data[i])
	{
		i=(i+1)%size;
		if(T->lchild!=NULL)
		{
			T=T->lchild;
			insert(T, k, size);
		}
		else
		{
			T->lchild=new(knode);
			T=T->lchild;
			for(j=0; j<size; j++) T->data[i]=k[i];
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
	else
	{
		i=(i+1)%size;
		if(T->rchild!=NULL)
		{
			T=T->rchild;
			insert(T, k, size);
		}
		else
		{
			T->rchild=new(knode);
			T=T->rchild;
			for(j=0; j<size; j++) T->data[i]=k[i];
			T->lchild=NULL;
			T->rchild=NULL;
			return;
		}
	}
}
int main()
{
	int i, array[100], n;
	char ch;
	cout<<"Enter array size ";
	cin>>n;
	kptr K=new(knode);
	kptr T=new(knode);
	K->lchild=NULL;
	K->rchild=NULL;
	for(i=0; i<n; i++)	cin>>K->data[i];
	do
	{
		cout<<"Enter data elements";
		for(i=0; i<n; i++)	cin>>array[i];
		T=K;
		insert(T, array, n);
		cout<<"More ?";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
