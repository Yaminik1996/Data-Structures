#include<bits/stdc++.h>
using namespace std;
class stack1{
	int size;
	int a[100];

	public:
			int top;
		stack1(){size=100;top=-1;	}
		void push(int x){a[++top]=x;}
		int pop(){return a[top--];	}
		int peek(){return a[top];}
		bool empty(){return top==-1;}
};
class node{
	public:
		int data;
		int noofbranches;
		node** p;
		node(){p=new node*[1];}
		node(int n){if(n==0)n++;p=new node*[n];}
};
void create(node* &l)
{
	int data,noofbranches,i;
	cout<<"Enter data:";
	cin>>data;
	cout<<"Enter noofbranches:";
	cin>>noofbranches;
	l=new node(noofbranches);
	l->data=data;
	l->noofbranches=noofbranches;
	for(i=0;i<noofbranches;i++)
	{
		create(l->p[i]);
	}
	if(noofbranches==0)l->p[0]=NULL;
}
void popuntil(stack1& s,int k)
{
	while(s.peek()!=k)s.pop();
}
bool find(node* l,int target,stack1& s)
{
	if(l->data==target){s.push(l->data);return true;}
	else if(l->noofbranches==0)return false;
	else{s.push(l->data);int z=l->data;
		for(int i=0;i<l->noofbranches;i++)
		 {if(find(l->p[i],target,s))return true;
		 else popuntil(s,z);}
	}
	return false;
}
int main()
{	
stack1 s,s1;
	node* l;
	int target;
	create(l);
	cout<<"Enter a target:";
	cin>>target;
	find(l,target,s);
	while(!s.empty())cout<<s.pop()<<" ";
	
	
return 0;	
}
