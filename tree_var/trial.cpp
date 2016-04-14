#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int a=67;
	fstream f("C:\\Users\\YAMINI KASHYAP\\Desktop\\Data.txt");
	f.seekg(26, ios::beg);
	f<<a;
	return 0;
}
