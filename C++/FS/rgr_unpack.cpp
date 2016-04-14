#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct child
{
	char name[20];
	int age;
};
struct emp
{
	int empno;
	char name[20];
	struct child c[20];
	int noc;
	int sal;
};
void unpack(char a[500],emp &e)
{
	int i=0;
	char b[25];
	int j=0;
	while(a[i]!='|')
	{
		b[j++]=a[i++];
	}
	e.empno=atoi(b);
	j=0;i++;
	while(a[i]!='|')
	{
		b[j++]=a[i++];
	}
	b[j]='\0';
	strcpy(e.name,b);
	j=0;i++;
	while(a[i]!='|')
	{
		b[j++]=a[i++];	
	}
	e.sal=atoi(b);
	j=0;i++;
	while(a[i]!='|')
	{
		b[j++]=a[i++];
	}
	e.noc=atoi(b);
	for(int k=0;k<e.noc;k++)
	{
		j=0;i++;
		while(a[i]!='|')
	{
		b[j++]=a[i++];
	}
	b[j]='\0';
	strcpy(e.c[k].name,b);
		j=0;i++;
		while(a[i]!='|')
	{
		b[j++]=a[i++];
	}
	e.c[k].age=atoi(b);
	}
}
void putdata(emp e)
{
		cout<<"name:";	
		cout<<e.name;
		cout<<"empno:";
		cout<<e.empno;
		cout<<"noc:";
		cout<<e.noc;
		cout<<"sal:";
		cout<<e.sal;
		for(int j=0;j<e.noc;j++)
		{
			cout<<"age of ch:";
			cout<<e.c[j].age;
			cout<<"name:";
			cout<<e.c[j].name;
		}
}
int main()
{
	emp e;
	char ch;
	char a[500];
	ifstream fin("empl", ios::in);
	for(int i=0;i<3;i++)
	{
		fin.getline(a,500,'#');
		fin>>ch;
		unpack(a,e);
		putdata(e);
	}
	fin.close();
	return 0;
}
