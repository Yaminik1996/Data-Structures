#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
{
	public:
			char name[20];
			char roll[2];
			char branch[3];
			friend istream &operator >>(istream &fin,student &s);
};
istream &operator >>(istream &fin,student &s)
{
	cout<<"enter name:";
	fin>>s.name;
	cout<<"enter rollno:";
	fin>>s.roll;
	cout<<"enter branch:";
	fin>>s.branch;
	return fin;
}
void pack(ofstream &fout,student &s)
{
	char buffer[25];
	strcpy(buffer,s.name);
	strcat(buffer,"|");
	strcat(buffer,s.roll);
	strcat(buffer,"|");
	strcat(buffer,s.branch);
	strcat(buffer,"#");
	fout<<buffer;
}
int main()
{
	student s[3];
	ofstream fout;
	fout.open("students",ios::out);
	for(int i=0;i<3;i++)
	{
		cin>>s[i];
		pack(fout,s[i]);
	}
	fout.close();
	return 0;
}
