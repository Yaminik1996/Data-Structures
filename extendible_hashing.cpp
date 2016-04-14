#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
const int bsize=2;
struct bucket
{
	int arr[bsize];
	int count;
	int d;
	char bhash[10];
};
bucket * directory[130];
char *a;
int dd;
int size; 
int factor;
int dcount;
void add(int );
void init()
{
	for(int i=0; i<130; i++) directory[i]=new bucket;
}
int hash(int key)
{
	return key%factor;
}
void extract(int j, int d, char a[])
{
	int b=j, c=0, r;
	strcpy(a, "");
	while(b&&c<d)
	{
		r=b%2;
		if(r) strcat(a, "1");
		else strcat(a, "0");
		c++;
		b=b/2;
	}
	while(c<d) 
	{
		strcat(a, "0");
		c++;
	}
}
void put(bucket *temp, int key)
{
	temp->arr[temp->count++]=key;
}
void split(int i)
{
	int k, l, h, d=directory[i]->d;
	int range=pow(2, dd-d);
	bucket *b1, *b2, *temp;
	b1=new bucket;
	b2=new bucket; 
	temp=new bucket;
	b1->d=d+1;
	b1->count=0;
	b2->d=d+1;
	b2->count=0;
	char p[10];
	for(k=i; k<i+range/2; k++)
	{
		temp=directory[k];
		for(l=0; l<temp->count; l++)
		{
			h=hash(temp->arr[l]);
			extract(h, d+1, p);
			if(p[strlen(p)-1]=='1') put(b2, temp->arr[l]);
			else put(b1, temp->arr[l]);
		}
	}
	strcpy(b1->bhash, directory[i]->bhash);
	strcat(b1->bhash, "0");
	strcpy(b2->bhash, directory[i]->bhash);
	strcat(b2->bhash, "1");
	for(k=i; k<i+range/2; k++)
	{
		directory[k]=b1;
	}
	for(k=i+range/2; k<i+range; k++) 
	{
		directory[k]=b2;
	}
}
void expand()
{
	for(int i=pow(2, dd)-1; i>=0; i--)
	{
		directory[2*i+1]=directory[i];
		directory[2*i]=directory[i];
	}
	++dd;
	dcount=pow(2, dd);
}
void insert(struct bucket *B, int key, int i)
{
	if(B->count<2) B->arr[B->count++]=key;
	else
	{
		if(B->d<dd)
		{
			split(i);
			add(key);
		}
		else
		{
			expand();
			add(key);
		}
	}
}
void add(int key)
{
	int h=hash(key);
	for(int i=0; i<dcount; i++)
		{
			a=new char[directory[i]->d+1];
			extract(h, directory[i]->d, a);
			if(strcmp(a, directory[i]->bhash)==0)
			{
				insert(directory[i], key, i);
				break;
			}
		}
}
void contract()
{
	if(dcount==2) return;
	int i=0;
	bool error=false;
	while(i<pow(2, dd)&&error==false)
	{
		if(directory[i]!=directory[i+1]) error=true;
		i=i+2;
	}
	if(error==false)
	{
		cout<<"Contracting";
		--dd;
		dcount=pow(2, dd);
		for(i=1; i<pow(2, dd); i++)	directory[i]=directory[2*i];
	}
}
void join(int i, int j)
{
	int k;
	bucket *temp1=directory[i];
	bucket *temp2=directory[j];
	int x=strcmp(temp1->bhash, temp2->bhash);
	if((temp1->count+temp2->count)/2<=2&&x!=0)
	{
		cout<<"Joining ";
		bucket *temp=new bucket;
		k=0;
		while(k<directory[i]->d-1)
		{
			temp->bhash[k]=directory[i]->bhash[k];
			++k;
		}
		temp->bhash[k]='\0';
		temp->d=directory[i]->d-1;
		for(k=0; k<temp1->count; k++) put(temp, temp1->arr[k]);
		for(k=0; k<temp2->count; k++) put(temp, temp2->arr[k]);
		directory[i]=temp;
		directory[j]=temp;
		contract();
	}	
}
void del(int key)
{
	int flag=0, i, j, k;
	bucket *temp=new bucket;
	for(i=0; i<dcount; i++)
	{
		temp=directory[i];
		for(j=0; j<temp->count; j++)
		{
			if(temp->arr[j]==key) 
			{
				flag=1;
				break;
			}
		}
		if(flag) 
			{
				break;
			}
	}
	if(flag)
	{
	for(k=j; k<temp->count; k++)
	{
		temp->arr[k]=temp->arr[1+k];
	}
	--temp->count;
	}
	if(i%2==0) join(i, i+1);
	else if(i%2==1) join(i-1, i);
}
int main()
{
	int key, h;
	init();
	char *a;
	dd=1;
	dcount=2;
	directory[0]->count=0;
	directory[0]->d=1;
	strcpy(directory[0]->bhash, "0");
	directory[1]->count=0;
	directory[1]->d=1;
	strcpy(directory[1]->bhash, "1");
	cout<<"Enter factor for hashing ";
	cin>>factor;
	char yes='y';
	dcount=2;
	while(yes=='y'||yes=='Y')
	{
		cout<<"Enter element";
		cin>>key;
		add(key);
		for(int i=0; i<dcount; i++)
		{
			cout<<endl<<directory[i]->bhash<<"\t";
			for(int j=0; j<directory[i]->count; j++)
				cout<<directory[i]->arr[j]<<"\t";
		}
		cout<<endl<<endl;
		cout<<"More ?";
		cin>>yes;
	}
	yes='y';
	while(yes=='y'||yes=='Y')
	{
	cout<<"Enter key for deletion ";
	cin>>key;
	del(key);
	cout<<endl;
	for(int i=0; i<dcount; i++)
	{
		cout<<endl<<directory[i]->bhash<<"\t";
		for(int j=0; j<directory[i]->count; j++)
			cout<<directory[i]->arr[j]<<"\t";
	}
	cout<<"More ? ";
	cin>>yes;
	}
	return 0;
}
