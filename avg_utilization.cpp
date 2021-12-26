#include<iostream>
using namespace std;
int main()
{
	float arv[8],dep[5],avg,t[4];
	float util=0;
	int ser=0;float merge[13][3];
	for(int z=0;z<13;z++)
	{
		for(int r=0;r<4;r++)
	{
		merge[z][4]=0;
	}
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
	
	int count=0,p=0,q=0,que=0;
	while(p+q<=13)
	{
		if(p==5)
		{
			merge[count][0]=arv[q];
			q++;count++;
		}
		if(q==8)
		{
			merge[count][0]=dep[p];
			p++;count++;
		}
		if(dep[p]>=arv[q])
		{
			merge[count][0]=arv[q];
			q++;count++;
		}
		else
		{
			merge[count][0]=dep[p];
			p++;count++;
		}
	}
	for(int z=0;z<13;z++)
	{
		cout<<"merge "<<merge[z][0]<<endl;
	}
	float time=0;
	count=0;
	int i=0,j=0;
	while(count!=13)
	{
		if (que==0&&ser==0&&merge[count][0]==arv[i])
		{
			que=0;ser=1;
			merge[count][1]=0;
			merge[count][2]=time;
		//	merge[count][3]=merge[count][0];
		
			i++;
		}
		else if (que==0&&ser==1&&merge[count][0]==arv[i])
		{
			que++;ser=1;
			merge[count][1]=que-1;
			merge[count][2]=time;
			util =util + merge[count][0]-merge[count][2];
		//	merge[count][3]=merge[count][0];
		i++;
		}
		else if (que>0&&ser==1&&merge[count][0]==arv[i])
		{
			que++;ser=1;
			merge[count][1]=que-1;
			merge[count][2]=time;
			util =util + merge[count][0]-merge[count][2];
		//	merge[count][3]=merge[count][0];
		i++;
		}
		else if (que==0&&ser==1&&merge[count][0]==dep[j])
		{
			que=0;ser=0;
			merge[count][1]=0;
			merge[count][2]=time;
			util =util + merge[count][0]-merge[count][2];
		//	merge[count][3]=merge[count][0];
		j++;
		}
		else if (que==0&&ser==0&&merge[count][0]==dep[j])
		{
			que=0;ser=0;
			merge[count][1]=0;
			merge[count][2]=time;
		//	merge[count][3]=merge[count][0];
			j++;
		}
		else if (que>0&&ser==1&&merge[count][0]==dep[j])
		{
			que--;ser=1;
			merge[count][1]=que+1;
			merge[count][2]=time;
			util =util + merge[count][0]-merge[count][2];
		//	merge[count][3]=merge[count][0];
			j++;
		}
			time=merge[count][0];
		count++;
	}
	cout<<endl<<endl;
	for(int z=0;z<13;z++)
	{
		cout<<"merge "<<merge[z][0]<<endl;
	}
	cout<<endl<<endl;
	for(int z=0;z<13;z++)
	{
		cout<<" merge "<<z<<" "<<merge[z][0]<<endl;
		cout<<" queu "<<z<<" "<<merge[z][1]<<endl;
		cout<<" time "<<z<<" "<<merge[z][2]<<endl;
		cout<<"____________________________"<<endl<<endl;
	}
	float delay[4];
	for(int z=0;z<4;z++)
	{
		delay[i]=0;
	}
	for(int w=0;w<13;w++)
	{
		if(merge[w][1]==0)
		{
			delay[0]=delay[0]+(merge[w][0]-merge[w][2]);
		}
		if(merge[w][1]==1)
		{
			delay[1]=delay[1]+(merge[w][0]-merge[w][2]);
		}
		if(merge[w][1]==2)
		{
			delay[2]=delay[2]+(merge[w][0]-merge[w][2]);
		}
		if(merge[w][1]==3)
		{
			delay[3]=delay[3]+(merge[w][0]-merge[w][2]);
		}
	}
	for(int i=0;i<4;i++)
	{
		avg=avg+(delay[i]*i);
	}
	avg=(avg/merge[12][0]);
	cout<<endl<<"total time when server was utilized - "<<util;
	cout<<endl<<"Average utilization of server - "<<util/merge[12][0];
	cout<<endl<<"percentage utilization of server - "<<(util/merge[12][0])*100<<"%";
}
