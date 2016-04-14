#include<iostream>
using namespace std;
struct edge
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
void swap(struct edge &E1, struct edge &E2)
{
	int temp=E1.v1;E1.v1=E2.v1;E2.v1=temp;
	temp=E1.v2;E1.v2=E2.v2;E2.v2=temp;
	temp=E1.w;E1.w=E2.w;E2.w=temp;
}
void addheap(struct edge H[], int heapcount, struct edge E1)
{
	int i=heapcount;
	H[i].v1=E1.v1;
	H[i].v2=E1.v2;
	H[i].w=E1.w;
	if(H[i/2].w>=H[i].w)
	{
	while(H[i/2].w>=H[i].w&&(i/2)>0)
	{
		if(H[i/2].w>H[i].w)
		{
		swap(H[i/2], H[i]);
		i=i/2;
		}
		else
		{
		struct edge temp;
		temp.v1=H[i].v1;
		temp.v2=H[i].v2;
		temp.w=H[i].w;
		for(int j=i-1; j>=i/2+1; j--)
		{
			H[j+1].v1=H[j].v1;
			H[j+1].v2=H[j].v2;
			H[j+1].w=H[j].w;
		}
		H[i/2+1].v1=temp.v1;
		H[i/2+1].v2=temp.v2;
		H[i/2+1].w=temp.w;
		i=i/2+1;
		}
	}
	}
}
void deleteheap(struct edge H[], int &heapcount, struct edge T[], int &treecount)
{
	int uni=Union(H[1].v1, H[1].v2);
	if(uni==0||uni==1)
	{
		T[treecount].v1=H[1].v1;
		T[treecount].v2=H[1].v2;
		T[treecount].w=H[1].w;
		++treecount;
	}
	H[1].v1=H[heapcount].v1;
	H[1].v2=H[heapcount].v2;
	H[1].w=H[heapcount].w;
	int i=1;
	while(i<heapcount)
	{
		if(H[2*i].w<H[2*i+1].w&&2*i<heapcount) swap(H[2*i], H[i]);
		else if(H[2*i].w>H[2*i+1].w&&2*i+1<heapcount) swap(H[2*i+1], H[i]);
		i=i*2;
	}
	--heapcount;
}
int main()
{
	struct edge *H, E1;
	struct edge *T;
	int v, min, j, i=1, e, low;
	cout<<"Enter number of vertices ";
	cin>>v;
	cout<<"Enter number of edges ";
	cin>>e;
	S=new int[v+1];
	H=new struct edge[e+1];
	T=new struct edge[v];
	for(i=1; i<v+1; i++) S[i]=-1;
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge (from, to, weight)";
		cin>>E1.v1>>E1.v2>>E1.w;
		addheap(H, i, E1);
	}
	for(i=1; i<=e; i++) cout<<endl<<H[i].v1<<"  "<<H[i].v2<<"  "<<H[i].w;
	i=1;
	while(e!=0) 
	{
		deleteheap(H, e, T, i);
	}/*
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
	}*/
	cout<<endl;
	for(i=1; i<v; i++) cout<<T[i].v1<<"  "<<T[i].v2<<"  "<<T[i].w<<endl;
	return 0;
}
