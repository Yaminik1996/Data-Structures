#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
using namespace std;
void with_r(fstream &f, int k, int size, int r)
{
	int k2, ptr2, ptr3, ptr4, ex, h, h2, ptr;
	h=k%size;
	f.seekg(h*r, ios::beg);
	f>>ex>>ptr;
	if(ex==-1) 
	{
	f.seekg(h*r, ios::beg);
	f<<setw(3)<<k;
	}
	else if(ptr==-1&&(h==ex%size))
	{
		cout<<"CASE 2 working";
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
		cout<<"CASE 3 working";
		k2=ex;
		ptr2=h;
		while(ex!=-1)
		{
			ptr2=(ptr2+1)%size;
			f.seekg(ptr2*r, ios::beg);
			f>>ex;
		}
		f.seekg(ptr2*r, ios::beg);
		f<<setw(3)<<k2;
		f.seekg(h*r, ios::beg);
		f<<setw(3)<<k;
		cout<<" k2 = "<<k2<<" k = "<<k<<" ptr = "<<ptr<<" ptr2 = "<<ptr2;
		ptr=k2%size;
		f.seekg(ptr*r, ios::beg);
		f>>ex>>ptr3;
		cout<<endl<<"ptr = "<<ptr;
		while(ptr3!=k%size)
		{
			ptr=ptr3;
			f.seekg(ptr3*r, ios::beg);
			f>>ex>>ptr3;
		}
		f.seekg(ptr*r+3, ios::beg);
		f<<setw(3)<<ptr2;
	}
}
int main()
{
	fstream f("C:\\Users\\YAMINI KASHYAP\\Desktop\\data2.txt");
	int i, key=87, size=10, r=25;
	for(i=0; i<10; i++)
	{
	cout<<"Enter key ";
	cin>>key;
	with_r(f, key, size, r);
	}
	return 0;
}
