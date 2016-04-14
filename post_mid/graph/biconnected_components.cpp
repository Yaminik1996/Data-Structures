#include<iostream>
using namespace std;
static int A[20][20], e, V, *visit, *num, *low, number=0;
int children(int i)
{
	int j, count=0;
	for(j=1; j<=V; j++)
	{
		if(A[i][j]==1) count++;
	}
	return count;
}
struct edge
{
	int a, b;
}e1, temp;
struct stack
{
	int top;
	struct edge *E;
	int size;
};
void push(stack &S, struct edge E)
{
	if(S.size==S.top+1)
	{
		cout<<"Stack is full ";
		return;
	}
	S.E[++S.top].a=E.a;
	S.E[S.top].b=E.b;
}
void pop(stack &S)
{
	if(S.top==-1) return;
	S.E[S.top--];
}
void peek(stack S)
{
	if(S.top==-1) return;
	S.E[S.top];
}
int find()
{
	for(int i=1; i<=V; i++)
	{
		if(!visit[i]) return i;
	}
	return -1;
}
void bi_con(int v, stack &S)
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
				temp.a=v;
				temp.b=w;
				push(S, temp);
				A[v][w]=-1;
				bi_con(w, S);
				if(low[v]>low[w]) low[v]=low[w];
				if(low[w]>=num[v]) 
				{
					if(v==1)
					{
						if(children(1)>1)
						{
							cout<<endl<<endl<<"Printing "<<endl;
					while(S.E[S.top].a!=v||S.E[S.top].b!=w)
					{
						cout<<endl<<S.E[S.top].a<<"\t"<<S.E[S.top].b<<endl;
						pop(S);
					}
						cout<<endl<<S.E[S.top].a<<"\t"<<S.E[S.top].b<<endl;
						pop(S);
					}
					}
					else
					{
						cout<<endl<<endl<<"Printing "<<endl;
							while(S.E[S.top].a!=v||S.E[S.top].b!=w)
					{
							cout<<endl<<S.E[S.top].a<<"\t"<<S.E[S.top].b<<endl;
						pop(S);
					}
						cout<<endl<<S.E[S.top].a<<"\t"<<S.E[S.top].b<<endl;
						pop(S);
					}
				}
			}
			else if(A[w][v]!=-1)
			{
				if(low[v]>num[w]) 
				{
					low[v]=num[w];
					temp.a=v;
					temp.b=w;
					push(S, temp);
				}
			}
		}
	}
}
int main()
{
	int i, j, v1, v2, s;
	cout<<"Enter the number of vertices ";
	cin>>V;
	cout<<"Enter the number of edges ";
	cin>>e;
	visit=new int[V+1];
	num=new int[V+1];
	low=new int[V+1];
	for(i=0; i<=V; i++)
	{
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
	stack S;
	S.top=-1;
	S.size=50;
	S.E=new edge[e+1];
	while(find()!=-1)
	{
		s=find();
		if(s!=-1)	bi_con(s, S);
	}
	cout<<endl<<endl<<"Printing"<<endl;
	while(S.top!=-1)
	{
		cout<<endl<<S.E[S.top].a<<"\t"<<S.E[S.top].b<<endl;
						pop(S);
	}
	return 0;
}
