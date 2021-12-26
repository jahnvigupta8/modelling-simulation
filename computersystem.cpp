#include<bits/stdc++.h>
using namespace std;
int oper=30;
bool check(bool visited[])
{

    for(int i=0;i<oper;i++)
    {
        if(visited[i]==false)
            return true;
    }
    return false;
}






int main()
{
	srand(unsigned(time(0)));
	int number=10;float quantum=0.1,t=0.03;
	float sum=0,sum1=0;
	while(number--)
	{
		int i;
		float arr[oper];
		for(int l=0;l<oper;l++)
		{
			arr[l]=0;
		}
		float ser[oper];
		for(int l=0;l<oper;l++)
		{
			ser[l]=0;
		}
		for(i=0;i<oper;i++)
		{
    	    arr[i]=rand()%10+1;
    	    arr[i]=arr[i]/10;
		}
		for(i=0;i<oper;i++)
		{
		    ser[i]=rand()%10+1;
    		ser[i]=ser[i]/10;
		}
		sort(arr,arr+oper);
		float service[oper];
		for(int l=0;l<oper;l++)
		{
			service[l]=0;
		}
		for(i=0;i<oper;i++)
		{
			service[i]=ser[i];
		}
		float waiting[oper];
		for(int l=0;l<oper;l++)
		{
			waiting[l]=0;
		}
		float res[oper];
		for(int l=0;l<oper;l++)
		{
			res[l]=0;
		}
		float t=0;
		bool visited[oper];
		visited[oper]={false};
		float end[oper];
		for(int l=0;l<oper;l++)
		{
			end[l]=0;
		}
		while(check(visited))
		{
    		for(i=0;i<oper;i++)
    		{
        		if(visited[i]==false)
        		{
        	    	if(ser[i]>quantum)
            		{
                		ser[i]=ser[i]-quantum;
                		t=t+quantum;
                		end[i]=end[i]+t;
            		}
            		else
            		{
                		visited[i]=true;
                		t=t+ser[i];
                		end[i]=t;
                		ser[i]=0;
            		}
        		}
    		}
		}
		for(i=0;i<oper;i++)
		{
    		waiting[i]=abs(end[i]-arr[i]-service[i]);
    		res[i]=abs(end[i]-arr[i]);
		}
		float wait=0,response=0,com=0;
		for(i=0;i<oper;i++)
		{
		wait=wait+waiting[i];
		}
		for(i=0;i<oper;i++)
		{
			response=response+res[i];
		}
		cout<<"case "<<(10-number)<<endl;
		cout<<"average waiting = "<<wait/oper<<endl;
		cout<<"average response = "<<response/oper<<endl;
		cout<<endl;
		sum += wait/oper;
		sum1 += response/oper;
	}
	cout<<"Total average waiting time = "<<sum/10<<endl;
	cout<<"Toatl average response time = "<<"  "<<sum1/10;
}


