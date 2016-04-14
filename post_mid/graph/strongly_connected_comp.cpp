#include<iostream>
using namespace std;
static int v, e, A[20][20], *visit, *number, num=1;
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
		if(!visit[i]) return i;
	}
	return -1;
}
void reverse()
{
	int B[20][20];
	for(int i=1; i<=v; i++)
	{
		for(int j=1; j<=v; j++)
		{
			B[i][j]=A[j][i];
		}
	}
	for(int i=1; i<=v; i++)
	{
		for(int j=1; j<=v; j++)
		{
			A[i][j]=B[i][j];
		}
	}
}
void dft_1(int s, stack &S)
{
	push(S, s);
	visit[s]=1;
	int i, j=0, k, l;
	for(i=1; i<=v; i++)
	{
		if(A[s][i]&&!visit[i])
		{
			j=i;
			dft_1(j, S);
		}
	}
}
void dft_2(int x)
{
	cout<<x<<"   ";
	visit[x]=1;
	for(int j=1; j<=v; j++)
	{
		if(A[x][j]&&!visit[j])
		{
			int k=j;
			dft_2(k);
		}
	}
}
int find(int number[], int num)
{
	for(int i=1; i<=v; i++) if(number[i]==num) return i;
}
int main()
{
	int i, j, v1, v2, s;
	cout<<"Enter number of vertices ";
	cin>>v;
	cout<<"Enter number of edges ";
	cin>>e;
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge (from, to)";
		cin>>v1;
		cin>>v2;
		A[v1][v2]=1;
	}
	visit = new int[v+1];
	number = new int[v+1];
	for(i=1; i<=v; i++) visit[i]=0;
	s=1;
	stack S;
	S.top=-1;
	S.size=v;
	S.num=new int[v];
	int num=0;
	while(find()!=-1)
	{
		dft_1(find(), S);
		while(S.top!=-1) number[pop(S)]=++num;
	}
	reverse();
	for(i=1; i<=v; i++) visit[i]=0;
	int *arr;
	arr=new int[v];
	while(num!=0)
	{
		int x=find(number, num);
		if(visit[x]==0)		
		{
			dft_2(x);
			cout<<endl;
		}
		num--;
	}
	return 0;
}
