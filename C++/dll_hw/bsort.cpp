#include<iostream>
using namespace std;
struct queue
{
	int s;
	int ele[50];
	int f;
	int r;
};
void enq(queue &Q, int d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
int deq(queue &Q)
{
	int p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
int main()
{
	queue Q1, Q2;
	int d, a, b, c;
	char m='y';
	Q1.f=-1;Q1.r=-1;Q1.s=50;
	Q2.f=-1;Q2.r=-1;Q2.s=50;
	do
	{
		cout<<"Enter element ";
		cin>>d;
		enq(Q1, d);
		cout<<"More?";
		cin>>m;
	}while(m=='y');
	while(Q1.f!=-1)
	{
		while(Q1.f!=Q1.r)
		{
		a=deq(Q1);
		b=deq(Q1);
		if(a>=b)
		{
			enq(Q2, a);
			enq(Q1, b);
		}
		else
		{
			enq(Q2, b);
			enq(Q1, a);
		}
		}
		cout<<deq(Q1)<<" ";
		while(Q2.f!=-1)
		{
			enq(Q1, deq(Q2));
		}
	}
	return 0;
}
