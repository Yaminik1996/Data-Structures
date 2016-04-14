#include<iostream>
using namespace std;
static int *Euler, A[20][20], *auxi, ecount, acount, *auxi2, v, e;
void splice()
{
	cout<<endl<<"In splice "<<endl;
	int i, j;
	if(ecount==0)	for(i=1; i<=acount; i++)	Euler[i]=auxi[i];
	else
	{
		cout<<endl<<"Current Euler \n";
		for(i=1; i<=ecount; i++) cout<<Euler[i]<<"\t";
		cout<<"\nCurrent auxi \n";
		for(i=1; i<=acount; i++) cout<<auxi[i]<<"\t";
		for(i=1; i<=ecount; i++) if(Euler[i]==auxi[acount]) break;
		cout<<endl<<"Match found at "<<i<<"\t"<<Euler[i]<<endl;
		int a2count=0;
		cout<<"\nShifting\n";
		for(j=i+1; j<=ecount; j++) 
		{
			auxi2[++a2count]=Euler[j];
			cout<<auxi2[a2count]<<"\t";
		}
		cout<<endl<<"Resulting auxi2 "<<endl;
		for(j=1; j<=a2count; j++) cout<<auxi2[j]<<"   ";
		cout<<"Resulting auxi "<<endl;
		for(j=1; j<=acount; j++) cout<<auxi[j]<<"   ";
		for(j=1; j<=acount; j++) Euler[++i]=auxi[j];
		for(j=1; j<=a2count; j++) Euler[++i]=auxi2[j];
		ecount=i;
		cout<<endl<<"Resulting Euler path "<<endl;
		for(j=1; j<=ecount; j++) cout<<Euler[j]<<"   ";
		a2count=0;
		acount=0;
	}
}
int checkzero(int a)
{
	int i;
	for(i=1; i<=v; i++) if(A[a][i]!=0) break;
	if(i==v+1) return 1;
	return 0;
}
void path(int s)
{
	int i, j, k, m;
	int check=checkzero(s);
	if(check==1)
	{
		int flag=0;
		splice();
		for(j=1; j<=ecount; j++)
		{
			for(k=1; k<=v; k++)
			{
				if(A[Euler[j]][k])
				{
					flag=1;
					break;
				}
			}
			if(flag) 
			{
				path(Euler[j]);
				break;
			}
		}
	}
	for(i=1; i<=v; i++) 
	{
	if(A[s][i])
	{
		auxi[++acount]=i;
		A[s][i]=0;
		A[i][s]=0;
		j=i;
		cout<<"\ni = "<<i<<endl;
		path(j);
		break;
	}
	}
}
int main()
{
	cout<<"Enter number of vertices ";
	cin>>v;
	cout<<"Enter number of edges ";
	cin>>e;
	Euler = new int[e+1];
	auxi = new int [e+1];
	auxi2= new int[e+1];
	int i, v1, v2, s;
	for(i=1; i<=e; i++)
	{
		cout<<"Enter edge ";
		cin>>v1>>v2;
		A[v1][v2]=1;
		A[v2][v1]=1;
	}
	cout<<"Enter source ";
	cin>>s;
	Euler[++ecount]=s;
	path(s);
//	for(i=1; i<=ecount; i++) cout<<Euler[i]<<"  ";
	return 0;
}
