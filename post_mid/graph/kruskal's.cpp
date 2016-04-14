#include<iostream>
using namespace std;
struct edge
{
	int v1;
	int v2;
	int w;
	bool visited;
};
struct tree
{
	int v1;
	int v2;
	int w;
};
int *S;
int find(int i)
{
	if(S[i]==-1) return i;
	else return find(S[i]);
}
int Union(int i, int j)
{
	if(S[j]==-1&&S[i]==-1) {	S[j]=i; return 1;	}
	if(find(i)==find(j)) return -1;
	if(S[j]==-1) {	S[j]=i; return 1; }
	if(S[i]==-1) {	S[i]=j; return 1;}
	if(find(i)!=find(j)) {S[i]=find(j); return 0;}
}
int main()
{
	struct edge *E;
	struct tree *T;
	int v, min, j, i=1, e, low;
	cout<<"Enter number of vertices ";
	cin>>v;
	cout<<"Enter number of edges ";
	cin>>e;
	S=new int[v+1];
	E=new struct edge[e+1];
	T=new struct tree[v];
	for(i=1; i<v+1; i++) S[i]=-1;
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge (from, to, weight)";
		cin>>E[i].v1>>E[i].v2>>E[i].w;
		E[i].visited=false;
	}
	for(i=1; i<v; i++)
	{
		min=10000;
		for(j=1; j<=e; j++)
		{
			if(!E[j].visited&&E[j].w<min)
			{
				low=j;
				min=E[j].w;
			}
		}
		E[low].visited=true;
		int uni=Union(E[low].v1, E[low].v2);
		if(uni==-1) --i;
		if(uni==0||uni==1)
		{
			T[i].v1=E[low].v1;
			T[i].v2=E[low].v2;
			T[i].w=E[low].w;
		}
	}
	cout<<endl;
	for(i=1; i<v; i++) cout<<T[i].v1<<"  "<<T[i].v2<<"  "<<T[i].w<<endl;
	return 0;
}
