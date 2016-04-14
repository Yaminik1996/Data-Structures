#include<iostream>
using namespace std;
struct gnode;
struct anode
	{
		struct anode *next;
		struct gnode *gnext;
	};
struct gnode
{
	int d;
	char data;
	struct anode * next;
};
typedef gnode* gptr;
int main()
{
	int n,i,j;
	char p,q,ch,tag;struct anode *a;
	cout<<"enter no of vertices ";
	cin>>n;
	gptr g[n];
	for(i=0;i<n;i++)
	{
		cout<<"enter data of first vertex";
		cin>>p;
		g[i]=new(gnode);
		g[i]->next=NULL;
		g[i]->data=p;
	}
	cout<<"enter d if graph is a directed graph else enter u\n";
	cin>>ch;
	cout<<"enter edge for exit enter n";
	cin>>tag;
	while(tag!='n')
	{
		cout<<" enter the edge";
		cin>>p>>q;
		for(i=0;i<n;i++)
		{
			if(g[i]->data==p)
			{
				if(g[i]->next==NULL)
				{
					g[i]->next=new(anode);
					a=g[i]->next;
				}
				else
				{
					a=g[i]->next;
					while(a->next!=NULL)
					{
						a=a->next;
					}
					a->next=new(anode);
					a=a->next;
				}
				a->next=NULL;
				for(j=0;j<n;j++)
				{
					if(g[j]->data==q)
					{
						a->gnext=g[j];
						break;
					}
				}
				break;
			}
		}
		cout<<"enter edge for exit enter n";
    	cin>>tag;
	}
	return 0;
}
