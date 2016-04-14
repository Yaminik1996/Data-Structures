#include<iostream>
using namespace std;
int S[50];
void init(int n)
{
	int i;
	for(i=1; i<=n; i++)
	S[i]=-1;
}
int find(int i)
{
	if(S[i]<0) return i;
	else return find(S[i]);
}
int find_pc(int i)//path_compression
{
	int root=find(i);
	if(i!=root)
	{
		int x=S[i];
		while(x!=root)
		{
			S[i]=root;
			i=x;
			x=S[x];
		}
	}
}
void Union_by_height(int i, int j)
{
	int si=-S[i], sj=-S[j];
	if(si>sj)
	{
		S[j]=i;
		S[i]+=S[j];
	}
	else
	{
		S[i]=j;
		S[j]+=S[i];
	}
}
void Union(int i, int j)
{
	if(S[j]==-1) S[j]=i;
	else if(S[i]==-1) S[i]=j;
	else Union_by_height(find(S[i]), find(S[j]));
}
int main()
{
	int i, a, b, n, choice;
	cout<<"How many elements ? ";
	cin>>n;
	init(n);
	do
	{
		cout<<"1. Union\n2. Find\n3. Display\n4. Exit";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter numbers ";
					cin>>a>>b;
					Union(a, b);
					break;
			case 2: cout<<"Enter number ";
					cin>>a;
					cout<<"Root is : "<<find_pc(a);
					break;
			case 3: for(i=1; i<=n; i++) cout<<i<<"  "<<S[i]<<endl;
					break;
		}
	}while(choice!=4);
	return 0;
}
