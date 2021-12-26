 #include <cstdlib> 
#include <ctime> 
#include <iostream>

using namespace std;

int main() 
{ 

int size,run;
 cout<< "how many customers ?" << endl;
 cin >> size;
 cout<< "how many runs ?" << endl;
 cin >> run;
 
/*rand() / double(RAND_MAX) generates a floating-point random
 number between 0 (inclusive) and 1 (inclusive), but it's not a good way for the 
 following reasons (because RAND_MAX is usually 32767): */
 float array1[size];
  float array2[size];
  float delay[size];
  float delayrun[run];
  for(int j=0;j<run;j++)
  {
  	float temp=0.;
  	for(int i=0; i<size; i++)
	{ 
    	array1[i] = ((double) rand() / (RAND_MAX))*0.02;      
    	array2[i] = ((double) rand() / (RAND_MAX))*0.1; 
        //cout<<array1[i]<<endl;
       // cout<<array2[i]<<endl;
 	} 
 	delay[0]=0;
 	float time=0;
 	float timea=timea+array1[0];
 	time=time+array1[0];
 	for(int i=1; i<size; i++)
	{ 
    	
    	
    	timea=time+array1[i];
	//	timea=timea + array[i]
	//	int temp1=time+array1[i];
    //	int temp2=time+array2[i-1];
    	if(timea <= time)
    	{
    		delay[i]=time-timea;
    	//	cout<<"delay "<<delay[i]<<endl;
    	}
    	else
    	{
    		delay[i]=0;
			//cout<<"delay "<<delay[i]<<endl;
 		}
 		time=time+array2[i-1];
 	}
 	for(int k=0;k<run;k++)
	 {
	 	temp=temp+delay[k];
	 }	
 			
 	delayrun[j]=(temp/size);
 	cout<<"average for "<<j<<" run - "<<delayrun[j]<<endl;
  }
	float final;
 	for(int k=0;k<run;k++)
 	{
 		final=final+delayrun[k];	
 	}
 	final=final/run;
 	cout<<"AVERAGE IS "<<final;
}
