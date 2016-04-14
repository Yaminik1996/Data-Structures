#include<iostream>
#include<string.h>
using namespace std;
union generic
{
	int roll;
	char name[20];
	float cgpa;
};
struct stack
{
	int tag[50];
	union generic G[50];
	int size;
	int top;
};
void push(stack &S, generic G, int tag)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
	{
		S.tag[++S.top]=tag;
		switch(tag)
		{
			case 1: S.G[S.top].roll=G.roll;
					break;
			case 2: strcpy(S.G[S.top].name, G.name);
					break;
			case 3: S.G[S.top].cgpa=G.cgpa;
					break;
		}
	}
}
void pop(stack &S)
{
	if(S.top==-1)
		cout<<"Stack is empty";
	else
	{
		switch(S.tag[S.top])
		{
			case 1: cout<<"\n"<<S.G[S.top].roll;
					break;
			case 2: cout<<"\n"<<S.G[S.top].name;
					break;
			case 3: cout<<"\n"<<S.G[S.top].cgpa;
					break;
		}
		--S.top;
	}
}
void display(stack &S)
{
	for(int i=0; i<=S.top; i++)
	{
		switch(S.tag[i])
		{
			case 1: cout<<S.G[i].roll<<" ";
					break;
			case 2: cout<<S.G[i].name<<" ";
					break;
			case 3: cout<<S.G[i].cgpa<<" ";
					break;
		}
	}
}
int main()
{
	stack S;
	S.top=-1;
	S.size=50;
	int choice, t;
	do
	{
		cout<<"\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT";
		cin>>choice;
		switch (choice)
		{
		case 1:{
		cout<<"Tag?";
		cin>>t;
		generic G;
		switch(t)
		{
			case 1: cout<<"Enter roll number : ";
					cin>>G.roll;
					push(S, G, t);
					break;
			case 2: cout<<"Enter name : ";
					cin>>G.name;
					push(S, G, t);
					break;
			case 3: cout<<"Enter cgpa : ";
					cin>>G.cgpa;
					push(S, G, t);
					break;
		}
		break;}
		case 2:
				pop(S);
				break;
		case 3:
				display(S);
				break;
		}
	}while(choice!=4);
	return 0;
}
