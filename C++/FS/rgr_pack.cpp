#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
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
	child c[20];
	int noc;
	int sal;
};
void pack(char a[500],emp e)
{
	char empno[10];
	itoa(e.empno,empno,10);
	strcpy(a,empno);
	strcat(a,"|");
	strcat(a,e.name);
	strcat(a,"|");
	char sal[10];
	itoa(e.sal,sal,10);
	strcat(a,sal);
	strcat(a,"|");
	char noc[2];
	itoa(e.noc,noc,10);
	strcat(a,noc);
	strcat(a,"|");
	for(int i=0;i<e.noc;i++)
	{
		strcat(a,e.c[i].name);
		strcat(a,"|");
		char age[2];
		itoa(e.c[i].age,age,10);
		strcat(a,age);
		strcat(a,"|");
	}
	strcat(a,"#");
}
int main()
{
	emp e;
	char a[500];
	ofstream fout("empl",ios::out);
	for(int i=0;i<3;i++)
	{
		cout<<"name:";
		cin>>e.name;
		cout<<"empno:";
		cin>>e.empno;
		cout<<"noc:";
		cin>>e.noc;
		cout<<"sal:";
		cin>>e.sal;
		for(int j=0;j<e.noc;j++)
		{
			cout<<"age of ch:";
			cin>>e.c[j].age;
			cout<<"name:";
			cin>>e.c[j].name;
		}
		pack(a,e);
		fout<<a;
	}
	return 0;
}
