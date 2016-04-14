#include<iostream>
using namespace std;
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void print(int A[], int i, int n) 
{
    int j, k;
    if(i == n)
	{
        for(k=0; k<=n; k++) cout<<A[k];
        cout<<endl;
    } else 
	{
        for(j = i; j <= n; j++) 
		{
            swap(A[i], A[j]);
            print(A, i + 1, n);
            swap(A[i], A[j]);
        }
    }
}
int main() 
{
    int A[100], i, n;
    cout<<"Enter size of array ";
    cin>>n;
    cout<<"Enter array elements ";
    for(i=0; i<n; i++)	cin>>A[i];
    print(A, 0, n-1);
 	return 0;
}
