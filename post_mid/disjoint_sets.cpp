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
	if(S[i]==-1) return i;
	else return find(S[i]);
}
void Union(int i, int j)
{
	if(S[j]==-1) S[j]=i;
	else if(S[i]==-1) S[i]=j;
	else Union(find(S[i]), find(S[j]));
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
					cout<<"Root is : "<<find(a);
					break;
			case 3: for(i=1; i<=n; i++) cout<<i<<"  "<<S[i]<<endl;
					break;
		}
	}while(choice!=4);
	return 0;
}
