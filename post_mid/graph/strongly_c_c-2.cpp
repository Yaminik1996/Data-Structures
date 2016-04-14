#include<iostream>
using namespace std;
static int A[20][20], e, v, *print, *visit, *number, *history, num=0;
struct stack
{
	int top;
	int *num;
	int size;
};
void push(stack &S, int a)
{
	if(S.size==S.top+1)
	{
		cout<<"Stack is full ";
		return;
	}
	S.num[++S.top]=a;
}
int pop(stack &S)
{
	if(S.top==-1) return -1;
	return S.num[S.top--];
}
int peek(stack S)
{
	if(S.top==-1) return -1;
	return S.num[S.top];
}
int find()
{
	for(int i=1; i<=v; i++)
	{
		if(!visit[i]&&!print[i]) return i;
	}
	return -1;
}
void strong(int s, stack &S)
{
	int i, j, k;
	visit[s]=1;
	number[s]=num;
	history[s]=num;
	cout<<"Source = "<<s;
	cout<<"Assign = "<<num;
	num+=1;
	push(S, s);
	for(i=1; i<=v; i++)
	{
		if(A[s][i]==1)
		{
			j=i;
			if(visit[j]==0&&print[j]==0)
			{
				cout<<"Next neighbour unvisited = "<<j<<"recursion ";
				strong(j, S);
				cout<<"Assign to history of "<<s<<"  "<<history[s]<<"   "<<history[j];
				if(history[s]>history[j]) history[s]=history[j];
			}
			else if(visit[j]==1)
			{
				cout<<"visited neighbour = "<<j<<"no recursion ";
				cout<<"Assign to history of "<<s<<"  "<<history[s]<<"   "<<history[j];
				if(history[s]>number[j]) history[s]=number[j];
			}
		}
	}
	cout<<" Finally "<<history[s]<<"   "<<number[s]<<"for "<<s<<endl;
	if(history[s]==number[s])
	{
		cout<<"Printing ";
		while(1&&S.top!=-1)
		{
			k=pop(S);
			cout<<k<<"\t";
			print[k]=1;
			visit[k]=0;
			if(k==s) break;
		}
	}
}
int main()
{
	int i, j, v1, v2, s;
	v=10;
	visit=new int[v+1];
	number=new int[v+1];
	history=new int[v+1];
	print=new int[v+1];
	for(i=0; i<=v; i++)
	{
		visit[i]=0;
		number[i]=0;
		history[i]=0;
		print[i]=0;
		for(j=1; j<=v; j++) A[i][j]=0;
	}
	A[1][2]=1;
	A[1][4]=1;
	A[2][3]=1;
	A[2][6]=1;
	A[3][1]=1;
	A[3][4]=1;
	A[3][5]=1;
	A[4][5]=1;
	A[6][3]=1;
	A[7][6]=1;
	A[7][8]=1;
	A[8][6]=1;
	A[8][9]=1;
	A[9][10]=1;
	A[10][8]=1;/*
	cout<<"Enter the number of vertices ";
	cin>>v;
	cout<<"Enter the number of edges ";
	cin>>e;
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge(v1, v2) \n";
		cin>>v1>>v2;
		A[v1][v2]=1;
	}*/
	stack S;
	S.top=-1;
	S.size=50;
	S.num=new int[v+1];
	while(find()!=-1)
	{
		s=find();
		if(s!=-1)	strong(s, S);
	}
	return 0;
}
