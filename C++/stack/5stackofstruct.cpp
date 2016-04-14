#include<iostream>
#include<string.h>
using namespace std;
struct stud
{
	int roll;
	char name[20];
	float cgpa;
};
struct stack
{
	struct stud student[50];
	int size;
	int top;
};
void getdata(stud &S)
{
	cout<<"Enter name :";
	cin>>S.name;
	cout<<"Enter roll number :";
	cin>>S.roll;
	cout<<"Enter cgpa";
	cin>>S.cgpa;
}
void push(stack &S, stud &student)
{
	if(S.top==S.size-1)
		cout<<"Stack is full";
	else
	{
	++S.top;
	S.student[S.top].roll=student.roll;
	strcpy(S.student[S.top].name,student.name);
	S.student[S.top].cgpa=student.cgpa;
	}
}
void display(stud S)
{
	cout<<"\nName : "<<S.name;
	cout<<"\nRoll number : "<<S.roll;
	cout<<"\nCGPA : "<<S.cgpa;
}
void pop(stack &S)
{
	if(S.top==-1)
		cout<<"Ëmpty stack !!";
	else
	{
		display(S.student[S.top]);
		S.top--;
	}	
}
void showstack(stack S)
{
	for(int i=S.top; i>=0; i--)
		display(S.student[i]);
}
int main()
{
	stack S;
	S.top=-1;
	S.size=50;
	int choice;
	do
	{
		cout<<"\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT";
		cin>>choice;
		switch(choice)
		{
			case 1:
					stud student;
					getdata(student);
					push(S, student);
					break;
			case 2: 
					pop(S);
					break;
			case 3:
					showstack(S);
					break;
		}
	}while(choice!=4);
}
