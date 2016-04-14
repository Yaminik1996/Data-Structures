#include<iostream>
using namespace std;
struct Mstack
{
	int *arr;
	int *top;
	int *next;
	int n;
	int m;
	int free;
};
void init(Mstack &M, int n1, int m1)
{
	M.m=m1;
	M.n=n1;
	M.arr=new int[M.n];
	M.top=new int[M.m];
	M.next=new int[M.n];
	for(int i=0; i<M.m; i++)
	{
		M.top[i]=-1;
	}
	M.free=0;
	for(int i=0; i<(M.n)-1; i++)
	{
		M.next[i]=i+1;
	}
	M.next[(M.n)-1]=-1;
}
int Full(Mstack M)
{
	if(M.free==-1)
		return 1;
	else return 0;
}
int Empty(Mstack M, int sno)
{
	if(M.top[sno]==-1)
		return 1;
	else return 0;
}
void push(Mstack &M, int sno, int ele)
{
	if(!Full(M))
	{
		int i=M.free;
		M.arr[i]=ele;
		M.free=M.next[i];
		M.next[i]=M.top[sno];
		M.top[sno]=i;
	}
	else cout<<"Stack is full";
}
int pop(Mstack &M, int sno)
{
	if(!Empty(M, sno))
	{
		int i=M.top[sno];
		M.top[sno]=M.next[i];
		M.next[i]=M.free;
		M.free=i;
		return M.arr[i];
	}
	else cout<<"Stack is empty";
}
void display(Mstack M)
{
	cout<<endl;
	for(int j=0; j<M.free; j++)
	{
		cout<<M.arr[j]<<" ";
	}
}
int main()
{
	Mstack M;
	cout<<"Enter size of array";
	int n1;
	cin>>n1;
	cout<<"Enter number of stacks";
	int m1;
	cin>>m1;
	init(M, n1, m1);
	char choice='y';
	int t;
	do
	{
		cout<<"\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT";
		cin>>t;
		if(t==1) 
		{
			cout<<"Enter stack number";
			int sno;
			cin>>sno;
			cout<<"Enter element";
			int ele;
			cin>>ele;
			push(M, sno, ele);
		}
		else if(t==2)
		{	
			cout<<"Enter stack number";
			int sno;
			cin>>sno;
			cout<<pop(M, sno);
		}
		else if(t==3)
		{
			display(M);
		}
		cout<<"Continue?";
		cin>>choice;
	}while(choice=='y');
	return 0;
}
