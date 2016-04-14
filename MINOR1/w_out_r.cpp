#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;
void w_out_r(fstream &f, int k, int size, int r)
{
	int ex, h, h2, ptr;
	h=k%size;
	f.seekg(h*r, ios::beg);
	f>>ex>>ptr;
	if(ex==-1) 
	{
	f.seekg(h*r, ios::beg);
	f<<setw(3)<<k;
	}
	else if(ptr==-1)
	{
		h2=h;
		while(ex!=-1)
		{
		h=(h+1)%size;
		f.seekg(h*r, ios::beg);
		f>>ex>>ptr;
		}
		f.seekg(h*r, ios::beg);
		f<<setw(3)<<k;
		f.seekg(h2*r+3, ios::beg);
		f<<setw(3)<<h;
	}
	else
	{
		while(ex!=-1)
		{
			h=(h+1)%size;
			f.seekg(h*r, ios::beg);
			f>>ex;
		}
		f.seekg(h*r, ios::beg);
		f<<setw(3)<<k;
		while(ptr!=-1)
		{
			f.seekg(ptr*r, ios::beg);
			f>>ex>>ptr;
		}
		f.seekg(ptr*r+3, ios::beg);
		f<<setw(3)<<h;
	}
}
int main()
{
	fstream f("C:\\Users\\YAMINI KASHYAP\\Desktop\\Data.txt");
	int i, key, size=10, r=25;
	for(i=0; i<10; i++)
	{
	cout<<"Enter key ";
	cin>>key;
	w_out_r(f, key, size, r);
	}
	return 0;
}
