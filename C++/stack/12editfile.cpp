#include<iostream>
#include<fstream>
using namespace std;
struct stack
{
	int top;
	int size;
	char brace[20];
};
void push(stack S, char x)
{
	++S.top;
	S.brace[S.top]=x;
}
char pop(stack S)
{
	if(S.top==-1)
		return '#';
	else
	return S.brace[S.top--];
}
char gettop(stack S)
{
	if(S.top==-1)
		return '#';
	else
	return S.brace[S.top];
}
int main()
{
	stack S1;
	stack S2;
	S1.top==-1;
	S2.top==-1;
	S1.size=25;
	S2.size=25;
	char ch;
	ifstream fin("C:\\Users\\YAMINI KASHYAP\\Desktop\\File.txt");
	ofstream fout("C:\\Users\\YAMINI KASHYAP\\Desktop\\File2.txt");
	while(!fin.eof())
	{
		fin.get(ch);
		if(ch==';')
		{
			fout<<ch<<'\n';
		}
		else if(ch=='>')
		{
			fout<<ch<<'\n';
		}
		else if(ch=='(')
		{
			fout<<ch;
			push(S1, ch);
		}
		else if(ch==')')
		{	fout<<ch;
			char g=pop(S1);
			if(gettop(S1)=='#')
			{
				fout<<'\n';
			}
		}
		else if(ch=='{')
		{
			fout<<ch;
			push(S2, ch);
		}
		else if(ch=='}')
		{	fout<<ch;
			char g=pop(S2);
			if(gettop(S2)=='#')
			{
				fout<<'\n';
			}
		}
		else fout<<ch;
	}
	fin.close();
	fout.close();
	return 0;
}
