#include<iostream>
using namespace std;
struct node
{
	char data;
	struct node *next;
};
void del(node *L, node *T, int A[26])
{
	static int k=0;
	if(T==NULL) cout<<endl;
	else
	{
		char a=T->data;
		int value=(int)(a)-(int)('A');
		if(A[value]==0)
		{
		++A[value];
		++k;
		T=T->next;
		del(L, T, A);
		}
		else 
		{
			node *P=L;
			for(int j=0; j<k; j++)
				P=P->next;
			P->next=P->next->next;
			cout<<P->data;
			T=T->next;
			del(L, T, A);
		}
	}
}
int main()
{
	int A[26];
	for(int i=0; i<26; i++)
	{
		A[i]=0;
	}
	node *L;
	L=new(node);
	cout<<"Enter data ";
	char ch;
	cin>>ch;
	L->data=ch;
	L->next=NULL;
	node *T=L;
	char more='Y';
	while(more=='Y')
	{
		cout<<"Enter data ";
		cin>>ch;
		T->next=new(node);
		T=T->next;
		T->data=ch;
		T->next=NULL;
		cout<<"More ?";
		cin>>more;
	}
	T=L;
	del(L, T, A);
	T=L;
	cout<<endl;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;
	}
	return 0;
}
