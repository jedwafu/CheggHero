#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int i,n,count=0;
	cin>>n;
	
	int ** ptr= new int*[n];
	int * sum= new int[n];
	
	for(i=0;i<n;i++)
	sum[i]=0;
	
	for( i=0;i<n;i++)
	{
		ptr[i]=new int[3];
	}
	
	for(i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{cin>>ptr[i][j];
		 sum[i]=sum[i]+ptr[i][j];
	    }
	    
	    
	    if(sum[i]>1)
	    count++;
	}
	
	cout<<count;
	return 0;
}
