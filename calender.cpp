#include<iostream>
using namespace std;
int main()
{
	int nd,d,m,y,i,j,k;
	cout<<"enter the number of the day on january 1st as if sun=1,mon=2,tue=3,wed=4,thu=5,fri=6,sat=7";
	cin>>d;
	cout<<"year";
	cin>>y;
	for(m=1;m<=12;m++)
	{
		switch(m)
		{
			case 1:cout<<"january"<<y;break;
			case 2:cout<<"february"<<y;break;
			case 3:cout<<"march"<<y;break;
			case 4:cout<<"april"<<y;break;
			case 5:cout<<"may"<<y;break;
			case 6:cout<<"june"<<y;break;
			case 7:cout<<"july"<<y;break;
			case 8:cout<<"august"<<y;break;
			case 9:cout<<"september"<<y;break;
			case 10:cout<<"october"<<y;break;
			case 11:cout<<"november"<<y;break;
			case 12:cout<<"december"<<y;
			break;
			
		}
		cout<<"\n";
		cout<<"sun"<<" "<<"mon"<<" "<<"tue"<<" "<<"wed"<<" "<<"thu"<<" "<<"fri"<<" "<<"sat"<<endl;
		for(i=1;i<=(d-1)*4;i++)
		{
			cout<<" ";
		}
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		nd=31;
		else if(m==4||m==6||m==9||m==11)
		nd=30;
		else if(m==2)
		{
			if(y%100==0)
			{
				if(y%400==0)
				nd=29;
				else nd=28;
			}
			else if(y%4==0)
			nd=29;
			else nd=28;
		}
		int k=0;
		for(j=1;j<=nd;j++)
		{
			if(j==(7-d+1)+7*k)
			{
				k++;
				cout<<j<<endl;
			}
			else if(j<10)
			cout<<j<<"   ";
			else
			cout<<j<<"  ";
		}
		cout<<endl;
		j++;
		d=(((d-1)+nd)%7)+1;
	}
	return 0;
}
