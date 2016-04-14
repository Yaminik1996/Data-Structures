#include<iostream>
using namespace std;
static int v, e, A[20][20], *visit, *index1, *index2, num=1;
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
int neighbour(int s)
{
	int i;
	for(i=1; i<=v; i++)
	{
		if(A[s][i]==1&&!visit[i])
		return i;
	}
	if(i==v+1) return 0;
	return -1;
}
void dft(int s, stack &S)
{
	visit[s]=1;
	cout<<"\nSource = "<<s;
	int i, j, n;
	n=neighbour(s);
	cout<<"\nInitial neighbour of "<<s<<" = "<<n<<endl;
	if(n==0) push(S, s);
	else
	{
	for(i=1; i<=v; i++)
	{
		if(A[s][i]&&!visit[i])
		{
			j=i;
			A[s][j]=-1;
			A[j][s]=-1;
			dft(j, S);
			n=neighbour(s);
			cout<<"\nFinal Neighbour of "<<s<<" = "<<n<<endl;
			if(n==0) push(S, s);
		}
	}
	}
}
int find()
{
	for(int i=1; i<=v; i++)
	{
		if(!visit[i]) return i;
	}
	return -1;
}
void print(int com[], int i, stack &S)
{
	int x=com[i], j;
	if(S.top==-1)
	{
		for(j=0; j<=i; j++) cout<<com[j]<<"\t";
		return;
	}
	int y=peek(S);
	if(A[x][y]==-1)
	{
		y=pop(S);
		com[i+1]=y;
		print(com, i+1, S);
	}
	else
	{
		for(j=0; j<=i; j++) cout<<com[j]<<"\t";
		cout<<endl;
		i=0;
		com[i]=pop(S);
		print(com, i, S);
	}
}
int main()
{
	int x, i, j, v1, v2, s;
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
	for(i=1; i<=v; i++) visit[i]=0;
	s=1;
	stack S, S2;
	S.top=-1;
	S.size=v;
	S.num=new int[v];
	S2.top=-1;
	S2.size=v;
	S2.num=new int[v];
	num=0;
	while(find()!=-1)
	{
		x=find();
		dft(x, S);
	}
	while(S.top!=-1) cout<<pop(S)<<"\t";
	return 0;
}
