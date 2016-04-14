#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
void add(int H[100], int n, int i, int d)
{
	int j;
	if(i<=n)
	{
		H[i]=d;
		j=i/2;
		while(j>0&&H[j]>d)
		{
			swap(H[j], H[i]);
			i=i/2;
			j=j/2;
		}
	}
}
int del(int H[100], int &n)
{
	int x=H[1];
	H[1]=H[n--];
	int i=1;
	while(i<=n)
	{
		if((2*i+1)<=n)
		{
		if((H[i]<H[2*i]&&H[i]<H[2*i+1])) break;
		if(H[2*i]<H[2*i+1])
		{	
		swap(H[i], H[2*i]);
		}
		else
		{
			swap(H[i], H[2*i+1]);
		}
		}
		else if((2*i)==n)
		{
			if(H[i]>H[2*i]) swap(H[i], H[2*i]);
		}
		i*=2;
	}
	return x;
}
void print(int H[100], int n)
{
	for(int i=1; i<=n; i++) cout<<H[i]<<"\t";
}
int main()
{
	int i=0, n, d;
	int H[100];
	cout<<"Enter size of array ";
	cin>>n;
	cout<<"Enter elements ";
	for(i=1; i<=n; i++)
	{
		cin>>d;
		add(H, n, i, d);
	}
	for(i=1; i<=n; i++)
	{
		cout<<H[i]<<"   ";
	}
	int m=n;
cout<<endl;
	//cout<<n<<endl;
	for(i=1; i<=m; i++)
	{
		//cout<<m<<endl;
		//cout<<n<<"   ";
		//print(H, n);
		//cout<<"\t";
		cout<<del(H, n)<<"   ";
		//cout<<endl;
	}
	return 0;
}
