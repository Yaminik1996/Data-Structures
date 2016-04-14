//topological sort
#include<iostream>
using namespace std;
static int A[20][20];
static bool visited[20];
int num(int A[20][20], int c, int n)
{
	int r;
	for(r=0; r<n; r++) if(A[r][c]) break;
	if(r==n) return 0;
	return -1;
}
void zero(int A[20][20], int row, int n)
{
	for(int c=0; c<n; c++) A[row][c]=0;
}
void top_sort(int A[20][20], int n)
{
	int c, j, choice;
	for(c=0; c<n; c++) if(visited[c]==false) break;
	if(c==n) return;
	cout<<"Available options = ";
	for(j=0; j<n; j++) if(num(A, j, n)==0&&visited[j]==false) { cout<<j<<"\t"; }
	cout<<"Enter choice : ";
	cin>>choice;
	zero(A, choice, n);
	visited[choice]=true;
	top_sort(A, n);
}
int main()
{
	int n, i, j;
	char yes='y';
	cout<<"How many vertices ? ";
	cin>>n;
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter edges (from, to)";
		cin>>i;
		cin>>j;
		A[i][j]=1;
		cout<<"More ? ";
		cin>>yes;
	}
	top_sort(A, n);
}
