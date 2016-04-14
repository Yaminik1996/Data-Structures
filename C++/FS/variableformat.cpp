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
void pack(char a[200], struct emp E)
{
	if(E.tag[0]=='1')
	{
	char eno[10];
	itoa(E.empno, eno, 10);
	strcpy(a, eno);
	strcat(a, "|");
	strcat(a, E.name);
	strcat(a, "|");
	strcat(a, E.tag);
	strcat(a, "|");
		char msal[10];
		itoa(E.F.H1.msalary, msal, 10);
		strcat(a, msal);
		strcat(a, "#");
	}
	else if(E.tag[0]=='2')
	{
		
	char eno[10];
	itoa(E.empno, eno, 10);
	strcpy(a, eno);
	strcat(a, "|");
	strcat(a, E.name);
	strcat(a, "|");
	strcat(a, E.tag);
	strcat(a, "|");
		char h[10];
		itoa(E.F.H2.hours, h, 10);
		strcat(a, h);
		strcat(a, "|");
		char hsal[10];
		itoa(E.F.H2.hsalary, hsal, 10);
		strcat(a, hsal);
		strcat(a, "#");
	}
}
int main()
{
	ofstream fout("C:\\Users\\YAMINI KASHYAP\\Desktop\\Employee.txt");
	struct emp E;
	char E1[200];
	char E2[200];
	E.empno=56;
	strcpy(E.name,"MILI");
	strcpy(E.tag,"1");
	E.F.H1.msalary=9000;
	pack(E1, E);
	cout<<E1;
	fout<<E1;
	E.empno=18;
	strcpy(E.name,"TANG");
	strcpy(E.tag,"2");
	E.F.H2.hours=10;
	E.F.H2.hsalary=90;
	pack(E2, E);
	cout<<E2;
	fout<<E2;
	fout.close();
}
