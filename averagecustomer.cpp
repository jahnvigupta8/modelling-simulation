#include<iostream>
using namespace std;
int main()
{
	float arv[8],dep[5],avg,t[4];
	for(int z=0;z<4;z++)
	{
		t[z]=0;
	}
	arv[0]=0.4;
	arv[1]=1.6;
	arv[2]=2.1;
	arv[3]=3.8;
	arv[4]=4.0;
	arv[5]=5.6;
	arv[6]=5.8;
	arv[7]=7.2;
	dep[0]=2.4;
	dep[1]=3.1;
	dep[2]=3.3;
	dep[3]=4.9;
	dep[4]=8.6;
	float merge[13];
	int count=0,p=0,q=0,que=0;
	while(p+q<=13)
	{
		if(p==5)
		{
			merge[count]=arv[q];
			q++;count++;
		}
		if(q==8)
		{
			merge[count]=dep[p];
			p++;count++;
		}
		if(dep[p]>=arv[q])
		{
			merge[count]=arv[q];
			q++;count++;
		}
		else
		{
			merge[count]=dep[p];
			p++;count++;
		}
	}
	for(int z=0;z<13;z++)
	{
		cout<<"merge "<<merge[z]<<endl;
	}
	float time=0;
	int i=0,j=0,ser=1;
	for(int l=0;l<13;l++)
	{
		if(l==0)
		{
			que=0;
			t[0]=merge[l]-time;
			time=merge[l];	
			if(merge[l]==arv[i])
			{
				i++;ser=1;
			}
			if(merge[l]==dep[j])
			{
				j++;
			}
		}
		else
		{
			if(merge[l]=arv[i])
			{
				if(ser==1)
				que++;
				else
				{
					ser=1;que=0;
					if(que=0)
					{
					t[0]=t[0]+merge[l]-time;
					time=merge[l];
					}
				}
				if(que==1)
				{
					t[0]=t[0]+merge[l]-time;
					time=merge[l];
				}
				if(que==2)
				{
					t[1]=t[1]+merge[l]-time;
					time=merge[l];
				}
				if(que==3)
				{
					t[2]=t[2]+merge[l]-time;
					time=merge[l];
				}
				if(que==4)
				{
					t[3]=t[3]+merge[l]-time;
					time=merge[l];
				}
			}
			else
			{
				if(que>=0&&ser==1)
				{
					if(que==0)
					{
						ser=0;
						que=0;
					}
					else
					que--;
					
				}
				else if(que=0&&ser==0)
				{
					ser=1;que=0;
				}
				if(que==1)
				{
					t[2]=t[2]+merge[l]-time;
					time=merge[l];
				}
				if(que==0&&ser==1)
				{
					t[1]=t[1]+merge[l]-time;
					time=merge[l];
				}
				if(que==0&&ser==0)
				{
					t[0]=t[0]+merge[l]-time;
					time=merge[l];
				}
				if(que==2)
				{
					t[3]=t[3]+merge[l]-time;
					time=merge[l];
				}
				
			}
		}
	}
	for(int z=0;z<4;z++)
	{
		cout<<" time at "<<z<<" "<<t[0]<<endl;
		avg=avg+t[i]*i;
	}
	avg=(avg/merge[13]);
	cout<<"average - "<<avg;
}
