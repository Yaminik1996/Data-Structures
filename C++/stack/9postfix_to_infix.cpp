#include<iostream>
#include<string.h>
using namespace std;
struct stack
{
	int top;
	string e[25];
	int max;
};
void push(stack &s,string a)
{
	if(s.top==s.max-1)
	{
		cout<<"full";
	}
	else
	{
		s.e[++s.top]=a;
	}
}
string pop(stack &s)
{
	if(s.top==-1)
	{
		return "#";
	}
	else
	{
		return s.e[s.top--];
	}
}
int main()
{
	stack s;
	s.top=-1;
	s.max=25;
	string op,o;
	string c,r;
	char ch;
	int tag;
	cout<<"tag->1:operands   2->operators\n";
	do
	{
		cout<<"tag:";
		cin>>tag;
		if(tag==1)
		{
			cout<<"operand:";
			cin>>op;
			push(s,op);
		}
		else if(tag==2)
		{
			cout<<"enter operator:";
			cin>>c;
			op=pop(s);
			o=pop(s);
		/*	strcat('(',o);
			strcat(o,c);
			strcat(o,op);
			strcat(o,')');
		*/	r=o+c+op;
			push(s,r);
		}
		cout<<"continue?:";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	while(s.top!=-1)
	{
		o=pop(s);
		cout<<o;
	}
	cout<<endl;	
	return 0;
}
