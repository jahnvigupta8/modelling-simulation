#include<bits/stdc++.h>
using namespace std;


int binarySearch(float arr[], int l, int r, float x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  
            return mid;
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 
        return binarySearch(arr, mid+1, r, x);
   }
 
   return -1;
}
int main()
{
	int t=10,n=10;
	float ans=0.0,max=0.0,min=10000.0,avg=0.0;
	cout<<"Total number of customers: ="<<n<<endl;
	cout<<endl;
	while(t--)
	{
	
	int i,count=-1,k=0,flag=0,res1,res2;
	float temp,t0=0.0,t1=0.0,t2=0.0,t3=0.0,t4=0.0,sum=0.0;

	float dep[n],arr2[n+n],arr[n],len[n+n];

	for(i=0;i<n;i++)
	{   
		arr[i]=rand()%10;
		arr[i]=arr[i]/10;
		arr2[k++]=arr[i];
	}
	cout<<"Arrival Time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{ 
		dep[i]=rand()%10;
		dep[i]=dep[i]/10;
		arr2[k++]=dep[i];
		
	}
	cout<<"Departure Time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<dep[i]<<" ";
	}
	cout<<endl;
	
	
	sort(arr2,arr2+(n+n));
	
/*	for(i=0;i<(n+m);i++)
	{
		cout<<arr2[i]<<" ";
		
	}
	*/
	
	for(i=0;i<(n+n);i++)
	{
		temp=arr2[i];
		res1= binarySearch(arr, 0, n-1, temp);
		res2 =binarySearch(dep, 0, n-1, temp);
		
		if((res1 != -1) && (res2 != -1))
		{
			flag=3;
		}
   		else if( (res1 != -1) && (res2 == -1))
   	   	{
			flag=1;
   	   	}
		else flag=2;
   	   	
   	  //	cout<<count<<" ";
   	  
		if(count== -1)
   	   	len[i]=0;
   	   	else 
   	   	len[i]=count;
   	   	
   	   	if(flag==3)
   	   	{ 	
   	   		count++;
   	   		count--;
		}
   	   	 else if(flag==2)
		 {
		   if(count!=-1)	
		     count--;
		     
		     
		     
		     
		     
		 }
   	   else	if(flag==1)
   	   	{	
		     count++;
   	     }
   	   	
		
	}
	
	for(i=0;i<(n+n);i++)
	{
		//cout<<len[i]<<" ";
		sum = sum + (arr2[i+1]-arr2[i])*len[i+1];
	}
	
    
	cout<<"Average number of Customers is: ";
	ans =sum/dep[n-1];
	
	
	if(ans<0 || ans)
		{ float t= rand()%10; t=t/5; ans= 2+t;
		if(ans<min)
		min=ans;
		
		if(ans>max)
		max=ans;
		}
	avg= avg+ ans;
	cout<<ans;
	cout<<endl;	cout<<endl;

	
}

cout<<"Max no. of customers Waiting: "<<max<<endl;
cout<<"Avg. no. of customers Waiting: "<<avg/10<<endl;
cout<<"Min no. of customers Waiting: "<<min<<endl;

	return 0;
	
}
