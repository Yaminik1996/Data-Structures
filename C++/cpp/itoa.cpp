#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int x=9000;
	char p[20];
	itoa(x, p, 10);
	cout<<"\n"<<p;
	return 0;
}
