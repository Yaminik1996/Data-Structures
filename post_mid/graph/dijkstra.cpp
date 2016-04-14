#include<iostream>
using namespace std;
void print_path(int c, int s, int previous[])
{
	if(s==c) return;
	int x=previous[c];
	print_path(previous[c], s, previous);
	cout<<x<<"  ";
}
int main()
{
	int i, d, V, s, c, *distance, j; 
	static int A[50][50], *visit, *previous;
	cout<<"Enter number of vertices ";
	cin>>V;
	int yes=1;
	for(i=1; i<=V; i++) for(j=1; j<=V; j++) A[i][j]=0;
	while(yes==1)
	{
		cout<<"Enter edges (from, to, weight)";
		cin>>s;
		cin>>c;
		cin>>i;
		A[s][c]=i;
		cout<<"More? ";
		cin>>yes;
	}
	distance=new int[V+1];
	visit=new int[V+1];
	previous=new int[V+1];
	yes=1;
	while(yes==1)
	{
	for(i=1; i<=V; i++) distance[i]=10000;
	cout<<"Enter source ";
	cin>>s;
	cout<<"Enter destination ";
	cin>>d;
	c=s;
	visit[c]=1;
	distance[c]=0;
	while(c!=d)
	{
		for(i=1; i<=V; i++)
		{
			if(A[c][i])
			{
				if(distance[i]>(distance[c]+A[c][i]))
				{
					previous[i]=c;
					distance[i]=distance[c]+A[c][i];
				}
			}
		}
		visit[c]=1;
		int min=10000;
		for(i=1; i<=V; i++)
		{
			if(!visit[i]&&distance[i]<min)
			{
				min=distance[i];
				c=i;
			}
		}
	}
	cout<<d<<"  ";
	print_path(c, s, previous);
	cout<"More ? ";
	cin>>yes;
	}
	return 0;
}
