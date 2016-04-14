#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
int partition(int A[], int low, int high)
{
	int p=A[low]; int l=low; int h=high;
	while(l<=h)
	{
		while(A[l]<=p) l++;
		while(A[h]>p) h--;
		if(l<h) swap(A[l], A[h]);
	}
	swap(A[low], A[h]);
	return h;
}
void quicksort(int A[], int low, int high)
{
	int j;
	if(low<high)
	{
	j=partition(A, low, high);
	quicksort(A, low, j-1);
	quicksort(A, j+1, high);
	}
}
int main()
{
	int a[50];
	int i=0;
	char m='y';
	cout<<"Enter elements ";
	do
	{
		cin>>a[i++];
		cout<<"More? ";
		cin>>m;
	}while(m=='y');
	int size=i;
	int low=0;
	int high=size-1;
	quicksort(a, low, high);
	for(i=0; i<size; i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
