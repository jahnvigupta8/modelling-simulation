#include<iostream>
 #include <cstdlib> 
 #include<bits/stdc++.h>
#include <ctime>
using namespace std;
int main()
{
	int cust =0;
	float total=0;
	while(cust!=10)
	{
		float arv[10] ,dep[10],serv[10];float delay[9];
		float util=0;float time=0;
		float merge[20][3];int que=0,ser=0;
		for(int i=0; i<10; i++)
		{ 
    		arv[i] = 0;      
    		serv[i] = 0; 
 		}
		for(int i=0; i<10; i++)
		{ 
    		arv[i] = ((double) rand() / (RAND_MAX))*0.05;      
    		serv[i] = ((double) rand() / (RAND_MAX))*0.4; 
 		}
 		sort(arv,arv+10);
 		
 		int sum=0;
 		while(sum!=10)
 		{
 			float timea=timea+arv[sum];
 			time=time+arv[sum];delay[0]=0;
 			for(int i=1; i<10; i++)
			{	 
    	  		timea=time+serv[i];
    	  		dep[sum]=timea+delay[i-1];
				time=time+arv[i];
    			if(time <= timea)
    			{
    				delay[i]=timea-time;
    			//	cout<<"delay "<<delay[i]<<endl;
    			}
    			else
    			{
    				delay[i]=0;
					//cout<<"delay "<<delay[i]<<endl;
 				}
 			}
			 sum++;
 		}
 		
 		
 		
 		
 		
 		for(int z=0;z<20;z++)
		{
			for(int r=0;r<4;r++)
			{
				merge[z][r]=0;
			}
		}
		cout<<"ARIVALS"<<endl;
 		for(int i=0; i<10; i++)
		{ 
    		cout<<arv[i]<<" ";  
 		}
 		cout<<endl<<"DEPARTURES"<<endl;
 		for(int i=0; i<10; i++)
		{ 
    		cout<<dep[i]<<" ";  
 		}
 		cout<<endl;
		cust++;
		int p=0,q=0,num=0;
		while(p+q<=20)
		{
			if(p==10)
			{
				merge[num][0]=arv[q];
				q++;num++;
			}
			if(q==10)
			{
				merge[num][0]=dep[p];
				p++;num++;
			}
			if(dep[p]>=arv[q])
			{
				merge[num][0]=arv[q];
				q++;num++;
			}
			else
			{
				merge[num][0]=dep[p];
				p++;num++;
			}
		}
		int count=0,i=0,j=0;
		while(count!=20)
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
			cout<<" merge "<<z<<" "<<merge[z][0]<<endl;
			cout<<" queu "<<z<<" "<<merge[z][1]<<endl;
			cout<<" time "<<z<<" "<<merge[z][2]<<endl;
			cout<<"____________________________"<<endl<<endl;
		}
		cout<<"util  boy ---  "<<(util/merge[19][0])*100<<endl;
		total = total + (util/merge[19][0])*100;
	}
	cout<<"answer average "<<total/10;
}
