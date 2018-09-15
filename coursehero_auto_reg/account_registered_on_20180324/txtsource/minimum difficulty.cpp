#include<iostream>

using namespace std;

int main()
{
	int n,i,dpair=0,dskip,key1,key2;
	int array[100];
	
	cin>>n;
	
	cin>>array[0];
	
	for(i=1;i<n;i++)
	{
		cin>>array[i];
		if(array[i]-array[i-1]>dpair)
		{dpair=array[i]-array[i-1];
		 key1=i;
	    }
		
	}
	
	dskip=array[2]-array[0];
	for(i=3;i<n;i++)
	{
		if(array[i]-array[i-2]<dskip)
		{
			dskip=array[i]-array[i-2];
			key2=i;
		}
	}
	
	if(key2-1==key1|| key2-1==key1+1)
	{
		dpair=array[key2]-array[key2-2];
	}
	
	else
	{
		if(dskip>dpair)
		dpair=dskip;
	}
	
	cout<<dpair;
	
	return 0;
	
}
