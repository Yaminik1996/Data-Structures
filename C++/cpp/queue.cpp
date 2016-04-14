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
	queue Q;
	Q.f=-1;
	Q.r=-1;
	Q.s=50;
	int ch, d;
	do
	{
		cout<<"1. ENQUEUE 2. DEQUEUE 3. EXIT";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter data ";
			cin>>d;
			enq(Q, d);
		}
		else if(ch==2)
		{
			cout<<deq(Q);
		}
	}while(ch!=3);
	char ch='9';
	cout<<(int)(ch)-(int)('0');
	return 0;
}
