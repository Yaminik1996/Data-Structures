#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student
{

			char name[20];
			char roll[2];
			char branch[3];
};
void unpack(char a[50],student &s)
{
	int i=0;
	int j=0;
	while(a[i]!='|')
	{
		s.name[j]=a[i];
		j++;i++;
	}
	s.name[j]='\0';
	while(a[i]=='|')
		i++;
	j=0;
	while(a[i]!='|')
	{
		s.roll[j]=a[i];
		j++;i++;
	}
		s.roll[j]='\0';
	while(a[i]=='|')
		i++;
	j=0;
	while(a[i]!='|')
	{
		s.branch[j]=a[i];
		j++;i++;
	}
	s.branch[j]='\0';
	while(a[i]=='|')	i++;
}
int main()
{
	student s[3];
	ifstream fin;
	fin.open("students1");
	char a[200];
	int i=0;
	for(i=0; i<3;)
	{
		fin.getline(a,50,'#');
		strcat(a,"#");
		unpack(a,s[i]);
		i++;
	}
	for(i=0; i<3; i++)
	{
		cout<<endl;
		cout<<s[i].branch<<" "<<s[i].name<<" "<<s[i].roll<<" ";
	}
	fin.close();
	return 0;
}
