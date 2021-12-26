#include<bits/stdc++.h>
using namespace std;
int oper=20;
float q=0.1,tau=0.01;

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
	int number=5;
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
		cout<<"Arrival Time:";
		for(i=0;i<oper;i++)
    	cout<<arr[i]<<" ";
		cout<<endl;
		cout<<"Service time: ";
		for(i=0;i<oper;i++)
    	cout<<ser[i]<<" ";
		cout<<endl;
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
		float completion[oper];
		for(int l=0;l<oper;l++)
		{
			completion[l]=0;
		}
		while(check(visited))
		{
    		for(i=0;i<oper;i++)
    		{
        		if(visited[i]==false)
        		{
        	    	if(ser[i]>q)
            		{
                		ser[i]=ser[i]-q;
                		t=t+q;
                		completion[i]=completion[i]+tau;
            		}
            		else
            		{
                		visited[i]=true;
                		t=t+ser[i];
                		completion[i]=t;
                		ser[i]=0;
            		}
        		}
    		}
		}
		for(i=0;i<oper;i++)
		{
    		waiting[i]=abs(completion[i]-arr[i]-service[i]);
    		res[i]=abs(completion[i]-arr[i]);
		}
		cout<<"Waiting-Time: ";
		for(i=0;i<oper;i++)
		{
    		cout<<waiting[i]<<" ";
		}
		cout<<endl;
		cout<<"Response Time: ";
		for(i=0;i<oper;i++)
		{
		   cout<<res[i]<<" ";
		}
		cout<<endl;
		cout<<"Completion Time: ";
		for(i=0;i<oper;i++)
		{	
    		cout<<completion[i]<<" ";
		}
		cout<<endl;
		cout<<"average waiting Time: ";
		float sumwait=0,sumres=0,sumcom=0;
		for(i=0;i<oper;i++)
		{
		sumwait=sumwait+waiting[i];
    	//cout<<sumwait<<" ";
		}
		cout<<sumwait/oper<<endl;
		cout<<"average response Time: ";
		for(i=0;i<oper;i++)
		{
			sumres=sumres+res[i];
    		//cout<<sumwait<<" ";
		}
		cout<<sumres/oper<<endl;
		cout<<endl;
	}
}


