#include<bits/stdc++.h>
using namespace std;

struct btnode{
	char data;
	btnode* lchild;
	btnode* rchild;
};
class stk{
	int size;
	int top;
	btnode* a[100];
	public:
		stk(){size=100;top=-1;}
		void push(btnode* x){a[++top]=x;}
		btnode* pop(){return a[top--];}
		bool empty(){return top==-1;}
};
class que{
	int size;
	int f;
	int r;
	btnode* e[100];
	public:
		que(){size=100;r=f=-1;}
		void enque(btnode* x)
		{
			if((r+1)%size==f){cout<<"Queue full";exit(0);}
			else{
				if(r==-1)++f;
				r=(r+1)%size;
				e[r]=x;
			}
		}
		btnode* deque()
		{
			btnode* p;
			if(f==-1){cout<<"Queue is empty";exit(0);}
			else if(r==f){p=e[f];r=f=-1;	}
			else
			{
				p=e[f];f=(f+1)%size;
			}
			return p;
		}
		bool empty(){return f==-1;}
};
void create(btnode*& l)
{
	int n,flag=0,k,i;
	stk s;
	char ch;
	//cin>>n;
	cin>>ch;
 l=new btnode;btnode*t;
	t=l;
	t->data=ch;
	t->lchild=NULL;
	t->rchild=NULL;
	s.push(t);
	for(;1;)
	{
		cin>>ch;
		if(ch!='-')
		{
			if(!flag)
			{
				t->lchild=new btnode;
				t=t->lchild;
				t->data=ch;
				t->lchild=NULL;
				t->rchild=NULL;
				s.push(t);
			}
			else{
				t->rchild=new btnode;
				t=t->rchild;
				t->data=ch;
				t->rchild=NULL;
				t->lchild=NULL;
				s.push(t);
			}
			flag=0;
		}
		else if(ch=='-')
		{
			if(s.empty())break;
			t=s.pop();
			flag=1;
		}
	}
}
void print(btnode* l)
{
	if(l!=NULL)
	{	
	cout<<l->data<<" ";
		print(l->lchild);
		
		print(l->rchild);
	}
}
void levelorder(btnode* l)
{
	que s;
	cout<<l->data<<" ";
	btnode* star=new btnode;
	star->data='*';s.enque(star);
	while(1)
	{
		if(l->lchild!=NULL)s.enque(l->lchild);
		if(l->rchild!=NULL)s.enque(l->rchild);
		if(s.empty())break;
		l=s.deque();
		if(l->data=='*'){cout<<"\n";if(s.empty())break;
		l=s.deque();s.enque(star);} 
		cout<<l->data<<" ";
		
	}
}
int main()
{
	btnode* l;
	create(l);
	print(l);
	cout<<"\n";
	levelorder(l);
	return 0;
}
