#include<iostream>
using namespace std;
struct edge
{
	int v1;
	int v2;
	int w;
}*E;
int main()
{
	int i, V, s, c, j, next, min; 
	static int A[50][50], *visit;
	cout<<"Enter number of vertices ";
	cin>>V;
	int yes=1;
	E=new struct edge[V];
	for(i=1; i<=V; i++) for(j=1; j<=V; j++) A[i][j]=0;
	while(yes==1)
	{
		cout<<"Enter edge (from, to, weight)";
		cin>>s;
		cin>>c;
		cin>>i;
		A[s][c]=i;
		A[c][s]=i;
		cout<<"More? ";
		cin>>yes;
	}
	visit=new int[V+1];
	for(i=1; i<=V; i++) 
	{
		visit[i]=0;
		for(j=1; j<=V; j++) 
		{
			cout<<A[i][j]<<"  ";
		}
		cout<<endl;
	}
	c=1;
	visit[1]=1;
	while(c!=V)
	{
		min=10000;
		for(i=1; i<=V; i++)
		{
			if(visit[i]==1)
			{
			for(j=1; j<=V; j++)
			{if(visit[j]==0&&A[i][j]<min&&A[i][j])
			{
				s=i;
				next=j;
				min=A[i][j];
			}
			}
			}
		}
		visit[next]=1;
		E[c].v1=s;
		E[c].v2=next;
		E[c].w=min;
		++c;
	}
	cout<<endl;
	for(i=1; i<V; i++) cout<<E[i].v1<<"  "<<E[i].v2<<"  "<<E[i].w<<endl;
	return 0;
}
