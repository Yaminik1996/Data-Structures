#include<iostream>
#include<math.h>
using namespace std;
struct tnode
{
	char team;
	int score;
	tnode * lchild;
	tnode * rchild;
};
typedef tnode * tptr;
struct queue
{
	int s;
	tptr ele[50];
	int f;
	int r;
};
void enq(queue &Q, tptr d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
tptr deq(queue &Q)
{
	tptr p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void Queue(queue &Q, tptr T[1000], int num)
{
	for(int i=0; i<num; i++)
	{
		enq(Q, T[i]);
	}
}
tptr create(tptr T1, tptr T2)
{
	tptr M=new(tnode);
	if(T1->score>T2->score)
	{
		M->score=T1->score;
		M->team=T1->team;
	}
	else
	{
		M->score=T2->score;
		M->team=T2->team;
	}
	M->lchild=T1;
	M->rchild=T2;
	return M;
}
int Sort(queue &Q, char &name)
{
	while(Q.f!=Q.r)
	{
		tptr T1=deq(Q);
		tptr T2=deq(Q);
		enq(Q, create(T1, T2));
	}
	tptr P=new(tnode);
	P=deq(Q);
	name=P->team;
	return P->score;
}
void setvalue(tptr T[1000], int num)
{
	tptr P=new(tnode);
	P=T[0];
	for(int i=1; i<num ;i++)
	{
		if(P->score<T[i]->score)	P=T[i];
	}
	P->score=-1;
}
int main()
{
	int i, n, num;
	queue Q;
	Q.f=-1;
	Q.r=-1;
	Q.s=100;
	tptr T[1000];
	cout<<"Enter number of teams(as exponent of 2) ";
	cin>>n;
	num=pow(2, n);
	for(i=0; i<num; i++)
	{
		T[i]=new(tnode);
		cout<<"Enter team name : ";
		cin>>T[i]->team;
		cout<<"Enter score ";
		cin>>T[i]->score;
	}
	for(int j=0; j<num; j++)
	{
	Queue(Q, T, num);
	char name;
	int x = Sort(Q, name);
	cout<<name<<"  :  "<<x<<endl;
	setvalue(T, num);
	}
	return 0;
}
