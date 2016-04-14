#include<iostream>
#include<stdlib.h>
using namespace std;
struct queue
{
	int front;
	int rear;
	int size;
	int ele[50];
};
int c=0;
int checkempty(queue &Q)
{
	return(Q.front==-1);
}
int checkfull(queue &Q)
{
	return((Q.rear+1)%Q.size==Q.front);
}
int checksize(queue &Q)
{
	return((Q.size-Q.front+Q.rear+1)%Q.size-c);
}
int operatr(char data)
{
	if(data=='+'||data=='-'||data=='*'||data=='/'||data=='^')
	return 1;
	else return 0;
}
int operand(char data)
{
	if(data>='0'&& data<='9')
	return 1;
	else return 0;
}
void enqueue(queue &Q,char data)
{
	if(checkfull(Q))
		cout<<"\n overflow";
	else
	{
		if(Q.front==-1)
		{Q.front=0;}
		Q.rear=(Q.rear+1)%Q.size;
		if(operand(data))
		Q.ele[Q.rear]=(int)(data)-48;	
		else
			Q.ele[Q.rear]=data;
	}
}
char dequeue(queue &Q)
{
	int temp,x;
	if(checkempty(Q))
	{
		cout<<"\n underflow";
		return '0';
	}
	else
	{
		temp=Q.ele[Q.front];
			 x=temp;
			temp=0;
		if(Q.rear==Q.front)
		{
		Q.rear=-1;
		Q.front=-1;
		}
		else
		Q.front=(Q.front+1)%Q.size;
		return x;
		//c++;
	}

}
void show(queue &Q)
{
	int temp;
	if(checkempty(Q))
	cout<<"\n underflow";
	else
	{
		temp=Q.front;
		Q.rear=(Q.rear+1)%Q.size;	
		while(temp!=Q.rear)
		{
			if(Q.ele[temp]!=0)
			cout<<Q.ele[temp]<<endl;
			temp++;
		}
	}
}
void prefixevalution(queue &Q)
{
	char temp,temp1;
	temp=Q.front;
	Q.rear=(Q.rear+1)%Q.size;
	cout<<"***8";
	while(Q.front!=Q.rear)
	{
	temp1=dequeue(Q);
	if(operatr(temp1))
	{
		cout<<"####";
		if(operand(temp)&&operand(temp+1))
		{
			char c,d,e,g;
			c=dequeue(Q);
			d=dequeue(Q);
			switch(temp1)
			{
				cout<<"PPPPPP";
				case '+': g=d+c;enqueue(Q,g);break;
				case '-': g=d-c;enqueue(Q,g);break;
				case '*': g=d*c;enqueue(Q,g);break;
				case '/': g=d/c;enqueue(Q,g);break;
				case '^': g=d^c;enqueue(Q,g);break;
			}
		}
		else
		{
			enqueue(Q,temp1);
		}
		cout<<"AAAAA";
	}
	else if(operand(temp1))
		enqueue(Q,temp1);
		cout<<"DDDDDDDD";
	}
	cout<<"\n answer is:"<<Q.front;
}
int main()
{
	queue Q;
	Q.size=50;
	Q.front=-1;
	Q.rear=-1;
	cout<<"\n entr the lenght of expression";int n;
	cin>>n;
	char exp[50];
	cout<<"\n enter the operand and operators!";
	for(int i=0;i<n;i++)
	{
	cin>>exp[i];
	enqueue(Q,exp[i]);
	}
	prefixevalution(Q);
	return 0;
}
