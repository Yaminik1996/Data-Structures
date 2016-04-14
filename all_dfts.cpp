#include<iostream>
using namespace std;
static int A[10][10];
bool visited[10];
void dft(int A[][10], int i, int n)
{
	int c;
	for(c=0; c<n; c++) if(visited[c]!=true) break;
	if(c==n) return;
	int j, k;
	for(j=0; j<n; j++)
	{
		if(A[i][j]==1&&visited[j]==false) {	cout<<j<<"\t"; visited[j]=true; dft(A, j, n);}
	}
}
int main()
{
	int n, i, j, source;
	char yes='y';
	cout<<"How many vertices ? ";
	cin>>n;
	for(i=0; i<n; i++) visited[i]=false;
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter edges ";
		cin>>i;
		cin>>j;
		A[i][j]=1;
		A[j][i]=1;
		cout<<"More ? ";
		cin>>yes;
	}
	for(i=0; i<n; i++)
	{
		source=i;
	cout<<source<<"\t";
	visited[source]=true;
	dft(A, source, n);
	cout<<endl;
	for(j=0; j<n; j++) visited[j]=false;
	}
	return 0;
}
