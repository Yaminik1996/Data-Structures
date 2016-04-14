#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct h1
{
	int msalary;
};
struct h2
{
	int hours;
	int hsalary;
};
union field
{
	h1 H1;
	h2 H2;
};
struct emp
{
	int empno;
	char name[30];
	char tag[1];
	union field F;
};
void unpack(char a[200], emp &E)
{
	int i=0;
	char b[30];
	while(a[i]!='|')
	{	b[i]=a[i];
		i++;
	}
	E.empno=atoi(b);
	int j=0;
	i++;
	while(a[i]!='|')
	{
		E.name[j++]=a[i++];
	}
	E.name[j]='\0';
	j=0;i++;
	E.tag[0]=a[i];
	i++;
	if(E.tag[0]=='1')
	{
		i++;
		while(a[i]!='#')
		{
			b[j++]=a[i++];
		}
		E.F.H1.msalary=atoi(b);
	}
	else if(E.tag[0]=='2')
	{
		while(a[i]!='|')
		{
			b[j++]=a[i++];
		}
		j=0;i++;
		E.F.H2.hours=atoi(b);
		while(a[i]!='#')
		{
			b[j++]=a[i++];
		}
		E.F.H2.hsalary=atoi(b);
	}
}
int main()
{
	ifstream fin("C:\\Users\\YAMINI KASHYAP\\Desktop\\Employee.txt");
	char a[200];
	emp E;
	fin>>a;
	unpack(a, E);
	cout<<E.empno<<E.name<<E.tag<<E.F.H1.msalary;
	return 0;
}
