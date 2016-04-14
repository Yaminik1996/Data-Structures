#include<iostream>
using namespace std;
static int A[20][20], e, V, *print, *visit, *num, *low, number=0;
int find()
{
	for(int i=1; i<=V; i++)
	{
		if(!visit[i]) return i;
	}
	return -1;
}
int children(int i)
{
	int j, count=0;
	for(j=1; j<=V; j++)
	{
		if(A[i][j]==1) count++;
	}
	return count;
}
void articulation_points(int v)
{
	int i, w, k;
	visit[v]=1;
	num[v]=number;
	low[v]=number;
	number+=1;
	for(i=1; i<=V; i++)
	{
		if(A[v][i]==1)
		{
			w=i;
			if(visit[w]==0)
			{
				A[v][w]=-1;
				articulation_points(w);
				if(low[v]>low[w]) 
				{
					low[v]=low[w];
				}
				if(low[w]>=num[v]&&!print[v]) 
				{
					if(v==1)
					{
						if(children(1)>1)
						{
					cout<<"\n\nArticulation point : ";
					cout<<v<<"\t";
					print[v]=1;
					}
					}
					else
					{
						cout<<"\n\nArticulation point : ";
						cout<<v<<"\t";
						print[v]=1;
					}
				}
			}
			else if(A[w][v]!=-1)
			{
				if(low[v]>num[w]) 
				{
					low[v]=num[w];
				}
			}
		}
	}
}
int main()
{
	int i, j, v1, v2, s;
	visit=new int[V+1];
	num=new int[V+1];
	low=new int[V+1];
	print=new int[V+1];
	cout<<"Enter the number of vertices ";
	cin>>V;
	cout<<"Enter the number of edges ";
	cin>>e;
	for(i=0; i<=V; i++)
	{
		print[i]=0;
		visit[i]=0;
		num[i]=0;
		low[i]=0;
		for(j=1; j<=V; j++) A[i][j]=0;
	}
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge(v1, v2) \n";
		cin>>v1>>v2;
		A[v1][v2]=1;
		A[v2][v1]=1;
	}
	while(find()!=-1)
	{
		s=find();
		if(s!=-1)	articulation_points(s);
	}
	return 0;
}
