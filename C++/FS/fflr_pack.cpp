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
	
};
void getdata(student &s)
{
	cout<<"enter name:";
	cin>>s.name;
	cout<<"enter branch:";
	cin>>s.branch;
	cout<<"enter rollno:";
	cin>>s.roll;	
}
void pack(ofstream &fout,student &s)
{
	int i;
	char buffer[50];
	strcpy(buffer,s.name);
	for(i=strlen(s.name);i<20;i++)
	{
		strcat(buffer,"|");
	}
	strcat(buffer,s.roll);
	for(i=strlen(s.roll);i<2;i++)
	{
		strcat(buffer,"|");
	}
	strcat(buffer,s.branch);
	for(i=strlen(s.branch);i<3;i++)
	{
		strcat(buffer,"|");
	}
	strcat(buffer,"#");
	fout<<buffer;
}
int main()
{
	student s[3];
	ofstream fout;
	fout.open("students1",ios::out);
	for(int i=0;i<3;i++)
	{
		getdata(s[i]);
		pack(fout,s[i]);
		cout<<s[i].branch<<"\t"<<s[i].name<<"\t"<<s[i].roll<<"\n";
	}

	fout.close();
	return 0;
}
