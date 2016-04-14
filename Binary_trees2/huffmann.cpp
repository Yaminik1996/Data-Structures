#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct hnode
{
	char ch;
	hnode *l;
	hnode *r;
	int freq;
};
struct set
{
	char ch;
	char code[100];
};
void swap(hnode *T1, hnode *T2)
{
	hnode P=*T1;
	*T1=*T2;
	*T2=P;
}
void sort(hnode *H[100], int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=i; j<size; j++)
		{
			if(H[j]->freq>H[i]->freq)
			{
				swap(H[i], H[j]);
			}
		}
	}
}
void print(char temp[30], set S[100], int size)
{
	for(int i=0; i<size; i++)
	{
		if(!strcmp(temp, S[i].code)) 
		{
			cout<<S[i].ch;
		}
	}
}
void decode(char str[500], set S[100], int size)
{
	char temp[30];
	int i=0, j;
	while(str[i]!='\0')
	{
		j=0;
		while(str[i]!='#')
		{
			temp[j++]=str[i++];
		}
		i++;
		temp[j]='\0';
		print(temp, S, size);
	}
}
void print1(hnode *T)
{
	if(T==NULL) cout<<"  ";
	else
	{
		print1(T->l);
		cout<<T->ch;
		print1(T->r);
	}
}
bool encode(hnode *H, char a, char str[100])
{
	if(H==NULL) return 0;
	else
	{
		if(H->ch==a) return 1;
		else if(encode(H->l, a, str)) strcat(str, "0");
		else if(encode(H->r, a, str)) strcat(str, "1");
	}
}
int main()
{
	set S[100];
	char ignore='*';
	hnode *H[100], *M;
	int i,n;
	cout<<"How many data elements ? "; cin>>n;
	for(i=0; i<n; i++)
	{
		H[i]=new(hnode);
		cout<<"Enter data ";
		cin>>H[i]->ch;
		S[i].ch=H[i]->ch;
		cout<<"Enter frequency ";
		cin>>H[i]->freq;
		H[i]->l=NULL; H[i]->r=NULL;
	}
	int size=i;
	int size1=i;
	sort(H, size);
	for(i=0; i<size; i++) cout<<H[i]->freq<<"  ";
	print1(H[size-1]);
	cout<<endl;
	while(size!=1)
	{
		M=new(hnode);
		M->l=H[size-1];
		M->r=H[size-2];
		M->freq=M->l->freq+M->r->freq;
		M->ch=ignore;
		H[size-2]=M;
		--size;
		sort(H, size);
		for(i=0; i<size; i++) cout<<H[i]->freq<<"  ";
		print1(H[size-1]);
		cout<<endl;
	}
	cout<<H[0]->freq;
	for(i=0; i<size1; i++)
	{
		strcpy(S[i].code, "");
		encode(H[0], S[i].ch, S[i].code);
	}
	cout<<endl;
	for(i=0; i<size1; i++)
	{
		cout<<S[i].ch<<"    "<<S[i].code<<endl;
	}
	char code[500], temp[100];
	cout<<"Enter code to be decoded with '#' delimiters ";
	cin>>code;
	decode(code, S, size1);
	return 0;
}
