#include<iostream>
using namespace std;
struct gnode
{
	int noc;
	char data;
	struct gnode *next[100]; 
};
typedef gnode *Gptr;
void create(Gptr G)
{
	int i;
	for(i=0; i<100; i++) G->next[i]=NULL;
	cout<<"Enter name ";
	cin>>G->data;
	cout<<"Enter number of children of"<<G->data;
	cin>>G->noc;
	if(G->noc>0) cout<<"Enter children of "<<G->data;
	cout<<endl;
	for(i=0; i<G->noc; i++)
	{
		G->next[i]=new(gnode);
		create(G->next[i]);
	}
}
bool find(gnode *G, char name, gnode *&T, gnode *A)
{
	if(G==NULL) return 0;
	else
	{
		if(G->data==name) 
		{
			cout<<"here "<<G->data;
			*T=*G;
			cout<<" here "<<T->data;
			*A=*G;
			return true;
		}
		else if(G->noc==0) return false;
		else
		{
			for(int i=0; i<G->noc; i++)
			{
				if(find(G->next[i], name, T, A)) *T=*(G->next[i]);
			}
		}
	}
}
void print(gnode *G)
{
	if(G==NULL) return;
	for(int i=0; i < G->noc; i++)
	cout<<G->next[i]->data<<"   ";
}
struct queue
{
	int s;
	Gptr ele[50];
	int f;
	int r;
};
void enq(queue &Q, Gptr d)
{
	if(Q.f==-1){++Q.f; ++Q.r;}
	else if(Q.f==(Q.r+1)%Q.s){cout<<"Queue is full"; return;}
	else { Q.r=(Q.r+1)%Q.s;}
	Q.ele[Q.r]=d;
}
Gptr deq(queue &Q)
{
	Gptr p;
	if(Q.f==-1) cout<<"Queue is empty";
	else if(Q.r==Q.f) { p=Q.ele[Q.f]; Q.r=-1; Q.f=-1; return p;	}
	else { p=Q.ele[Q.f]; Q.f=(Q.f+1)%Q.s; return p;	}
}
void level(Gptr T, Gptr A) {
	if(T== NULL) return;
	queue Q; Q.f=-1; Q.r=-1; Q.s=50;
	enq(Q, T);
	enq(Q, A);
	while(Q.f!=-1) {
		if(Q.ele[Q.f]->data=='*') 
		{
		cout<<endl;
		enq(Q, deq(Q));
		}
		gnode* current = deq(Q);
		cout<<current->data<<" ";
		if(current->noc>0)
		{
			for(int k=0; k<current->noc; k++)
		{
			enq(Q, current->next[k]);
		}
		}
	}
}
int main()
{
	Gptr G;
	G=new(gnode);
	create(G);
	cout<<"Enter the name whose children you want to see ";
	char name;
	cin>>name;
	Gptr T=new(gnode);
	Gptr A=new(gnode);
	find(G, name, A, T);
	cout<<T->data;
	cout<<" "<<T->next[0]->data;
	print(T);
	cout<<endl;
	//Gptr A=new(gnode);
	A->data='*';
	A->next[0]=NULL;
	A->noc=0;
	T=G;
	level(T, A);
	return 0;
}
