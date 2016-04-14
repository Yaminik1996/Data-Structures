#include<iostream>
using namespace std;
void assign(int &j, int d)
{
	j=(j+d-2)/d;	
}
void add(int H[100], int n, int i, int d, int k)
{
	int j;
	if(i<=n)
	{
		H[i]=k;
		j=i;
		assign(j, d);
		while(j>0&&H[j]>k)
		{
			swap(H[j], H[i]);
			assign(i, d);
			assign(j, d);
		}
	}
}
int main()
{
	int i=0, n, d, k;
	int H[100];
	cout<<"Enter size of array ";
	cin>>n;
	cout<<"Enter value of d";
	cin>>d;
	cout<<"Enter elements ";
	for(i=1; i<=n; i++)
	{
		cin>>k;
		add(H, n, i, d, k);
	}
	for(i=1; i<=n; i++)
	{
		cout<<H[i]<<"   ";
	}
}
