#include<iostream>
using namespace std;
struct node 
{
	int tag;
	union
	{
		char data;
		node *down;
	}u;
	node *next;
};
struct stack
{
	node *e[20];
	int top;
};
void push(stack &s1,node *n)
{
	if(s1.top==19)
	{
		cout<<"empty";
	}
	else
	{
		s1.e[++s1.top]=n;
	}
}
node *pop(stack &s1)
{
	if(s1.top!=-1)
	{
		return s1.e[s1.top--];
	}
}
struct set
{
	char name;
	node *ptr;
}s[25];
int c=0;
void create(node* &t,stack &s1)
{
	char tag,a;
	int f=0;
	cout<<"enter tag(c->character,( for set,e->pre-existing set,)/n to terminate ";
	cin>>tag;
	switch(tag)
	{
		case 'c':	cout<<"enter element:";
					cin>>a;
					t->tag=0;
					t->u.data=a;
					t->next=NULL;
					t->next=new(struct node);
					t=t->next;
					create(t,s1);
					break;
		case '(':	t->tag=1;
					t->u.down=NULL;
					t->next=NULL;
					push(s1,t);
					t->u.down=new(struct node);
					t=t->u.down;
					create(t,s1);
					break;
		case 'e':	t->tag=1;
					t->u.down=NULL;
					t->next=NULL;
					cout<<"enter set name:";
					cin>>a;
					for(int i=0;i<c;i++)
					{
						if(s[i].name==a)
						{
							t->u.down=s[i].ptr;
							f=1;		
						}		
					}
					if(f)
					{
						t->next=new(struct node);
						t=t->next;
						create(t,s1);								
					}		
					break;
		case ')':	node *m;
					m=pop(s1);
					t->next=NULL;
					t=m;
					t->next=new(struct node);
					t=t->next;
					create(t,s1);
					break;
		case 'n':	t->tag=-1;
					t->next=NULL;
					break;
					
	};
}
void print(node *t)
{
	cout<<"( ";
	while(t->next!=NULL){
	if(t->tag==0)
	{
		cout<<t->u.data<<" , ";
	}
	else if(t->tag==1)
	{
		cout<<"( ";
		node *q=t->u.down;
		while(q->next!=NULL)
		{
			cout<<q->u.data<<",";
			q=q->next;
		}
		cout<<" )";
	}t=t->next;
	}
	cout<<")";
}
int main()
{
	stack s1;
	s1.top=-1;
	char n;
	cout<<"enter set name:";
	cin>>n;
	s[c].name=n;
	s[c].ptr=new(struct node);
	s[c].ptr->tag=-1;
	s[c].ptr->u.data='#';
	s[c].ptr->next=NULL;
	node *ptr;
	ptr=s[c].ptr;
	ptr->next=new(struct node);
	c++;
	create(ptr,s1);
	cout<<"list:";
	ptr=s[c-1].ptr;
//	
ptr=ptr->next;
	print(ptr);
	return 0;
}
