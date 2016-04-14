#include<iostream>
using namespace std;
struct gnode 
{
	char data;
	struct gnode *fchild;
	struct gnode *nsib;
};
typedef gnode * GPTR;
void create(gnode *G)
{
	char fc, sib;
	int yes;
	cout<<"Enter first child (/ for NO): ";
	cin>>fc;
	if(fc!='/')
	{
		G->fchild=new(gnode);
		G->fchild->data=fc;
		G->fchild->nsib=NULL;
		create(G->fchild);
	}
	else
	{
		G->fchild=NULL;
	}
	cout<<"Siblings of "<<G->data<<" ? (0 for no, 1 for yes)";
	cin>>yes;
	if(yes)
	{
		cout<<"Enter name of sibling of "<<G->data;
		cin>>sib;
		G->nsib=new(gnode);
		G->nsib->data=sib;
		G->nsib->fchild=NULL;
		G->nsib->nsib=NULL;
		create(G->nsib);
	}
	if(!yes) G->nsib=NULL;
}
bool search(gnode *G, char name, gnode *T)
{
	if(G==NULL) return false;
	else
	{
		if(G->data==name) 
		{
			*T=*G;
			return true;
		}
		else if(G->fchild==NULL&&G->nsib==NULL) return false;
		else
		{
			if(search(G->nsib, name, T)) *T=*(G->nsib);
			if(search(G->fchild, name, T)) *T=*(G->fchild);
		}		
	}
}
void pc(gnode *T)
{
	if(T->fchild==NULL) cout<<"No children ";
	else
	{
		cout<<T->fchild<<"   ";
		T=T->fchild;
		if(T->nsib)
		{
		while(T->nsib!=NULL)
		{
			cout<<T->nsib->data<<"   ";
			T=T->nsib;
		}
		cout<<T->nsib->data;
		}
	}
}
void print(gnode *T, int hor)
{
	int i;
	if(!T) return;
	for(i=0; i<hor; i++) cout<<" ";
	cout<<T->data<<endl;
	hor+=1;
	if(T->fchild)
	{
		print(T->fchild, hor);
	}
	hor-=1;
	if(T->nsib) print(T->nsib, hor);
}
int main()
{
	char name;
	cout<<"Enter data for root node ";
	cin>>name;
	GPTR G;
	G=new(gnode);
	G->data=name;
	G->nsib=NULL;
	G->fchild=NULL;
	gnode *G2=new(gnode);
	G2=G;
	create(G2);
	gnode *T=new(gnode);
	cout<<"Enter name whose children have to be listed ";
	cin>>name;
	search(G, name, T);
	pc(T);/*
	T=G;
	int hor=0;
	print(T, hor);
	*/return 0;
}
