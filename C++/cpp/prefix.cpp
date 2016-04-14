#include<iostream>
#include<string.h>
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
	if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else if(Q.f==-1){++Q.f; ++Q.r;}
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
int getfront(queue &Q)
{
	int p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; return p;	}
	else { p=Q.ele[Q.f]; return p;}
}
int isnum(char ch)
{
	int a=(int)(ch)-(int)('0');
	if(a>=0 && a<=9)
		return 1;
	else return 0;
}
int calc(int x1, int x2, int x3)
{
	switch(x1)
	{
		case -1 : return x2+x3;
		case -2 : return x2-x3;
		case -3 : return x2*x3;
		case -4 : return x2/x3;
		case -5 : return x2%x3;
	}
}
int main()
{
	queue Q; 
	Q.f=-1;Q.r=-1;Q.s=50;
	char prefix[50];
	cout<<"Enter prefix expression ";
	cin>>prefix;
	int i=0;
	int b;
	while(prefix[i]!='\0')
	{
		char a=prefix[i++];
		if(isnum(a)) b=(int)(a)-(int)('0');
		else if(a=='+')	b=-1;
		else if(a=='-') b=-2;
		else if(a=='*') b=-3;
		else if(a=='/') b=-4;
		else if(a=='%') b=-5;
		enq(Q, b);
	}
	char a;
	int x, y, z;
	while(Q.r!=Q.f)
	{
		a=getfront(Q);
		if(a>=0)
		{
			enq(Q, deq(Q));
		}
		else
		{
			y=Q.ele[Q.f+1];
			z=Q.ele[Q.f+2];
			if(z>0&&y>0)
			{
				int x1=deq(Q);
				int x2=deq(Q);
				int x3=deq(Q);
				int ans=calc(x1, x2, x3);
				enq(Q, ans);
			}
			else 
			{
				enq(Q, deq(Q));
			}
		}
	}
	cout<<"Answer is : "<<deq(Q);
	return 0;
}
