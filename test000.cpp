#include<bits/stdc++.h>
using namespace std;

int main()
{	
srand(time(NULL));
	float f,mins,maxs,inv ;
	
	f=rand()%100;
	f = f/100+1;
//	cout<<f<<endl;
	int h=rand()%100;
//	cout<<h<<endl;
	int arr[h],z,dem[h];
	//int t=0;
	int posinv=0,neginv=0;
//	 cout<<" : "<<h<<endl;
	 arr[0]=rand()%3;
	// cout<<" 0 "<<arr[0]<<endl;
	for(int i=1;i<h;i++)
	{
		z=int(rand())%3;
		if(z==0)
			z=1;
		arr[i]=z+arr[i-1];
	//	cout<<" "<<i<<" : "<<arr[i]<<endl;
	}
	cout<<"Enter the minimum inventory level";
	cin>>mins;
	cout<<"Enter the maximum inventory level";
	cin>>maxs;
	cout<<"Enter the inventory level";
	cin>>inv;
	sort(arr,arr+h);
	for(int i=0;i<h;i++)
	{
		dem[i]=rand()%10;	
	}
	cout<<"demand"<<endl;
//	for(int i=0;i<h;i++)
//	{
//		cout<<dem[i]<<endl;	
//	}
	int qu=0,time=0,flag=0;
	while(qu!=h)
	{
		if(time>=30&&flag==0)
		{
			flag=1;
			if(inv<mins)
			{
				inv=(maxs-inv);
			}
		}
		if(inv>0&&(inv-dem[qu]>=0))
		{
			posinv+=(arr[qu]-time)*inv;
			inv=inv-dem[qu];
			time=arr[qu];
		}
		else if(inv<0)
		{
			neginv=abs(neginv+(arr[qu]-time)*inv);
			inv=inv-dem[qu];
			time==arr[qu];
		}
		else if(inv>0&&(inv-dem[qu]<0))
		{
			int x=dem[qu]-inv;
			posinv+=(arr[qu]-time)*inv;
			neginv=abs(neginv+(arr[qu]-time)*x);
			inv=inv-dem[qu];
			time==arr[qu];
		}
		qu++;
	}
	cout<<"positive "<<posinv<<endl;
	cout<<"negitive "<<neginv<<endl;
	cout<<"holding cost = $"<<posinv<<endl;
	cout<<"shortening cost = $"<<neginv*5<<endl;
}
