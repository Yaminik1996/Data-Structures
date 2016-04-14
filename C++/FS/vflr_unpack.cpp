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
/*void print (student &s)
{
	cout<<"name:"<<s.name<<"\nrollno:"<<s.roll<<"\nbranch:"<<s.branch;
}*/
void unpack(char a[30],student &s)
{
	int i=0;
	int j=0;
	while(a[i]!='|')
	{
		s.name[j]=a[i];
		j++;
		i++;
	}
	cout<<"name:"<<s.name<<"\n";
	j=0;i++;
	while(a[i]!='|')
	{
		s.roll[j]=a[i];
		j++;
		i++;
	}
	cout<<"roll no:"<<s.roll<<"\n";
	j=0;i++;
	while(a[i]!='#')
	{
		s.branch[j]=a[i];
		j++;
		i++;
	}
	cout<<"branch:"<<s.branch<<"\n";
}
int main()
{
	student s[3];
	ifstream fin;
	fin.open("C:\\Users\\DELL\\Desktop\\students.txt");
	char a[200];
	int j=0;
	
	for(int i=0;i<3;i++)
	{
		fin.getline(a,20,'#');
		strcat(a,"#");
		unpack(a,s[i]);
	}
	fin.close();
	return 0;
}
