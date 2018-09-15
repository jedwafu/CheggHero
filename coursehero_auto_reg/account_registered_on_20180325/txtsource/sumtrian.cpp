#include<iostream>

using namespace std;

int main()
{
	
	int t,n,i,j,max;
	
	int arr[100];
	int path[100];
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(i=0;i<100;i++)
		path[i]=0;
		
		cin>>path[0];
		
		for(i=1;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
			   cin>>arr[j];	
			}
			
			for(j=i;j>0;j--)
			{
				if(path[j]+arr[j]>path[j-1]+arr[j])
				path[j]=path[j]+arr[j];
				
				else 
				path[j]=path[j-1]+arr[j];
			}
			
			path[j]=path[j]+arr[j];
			
		}
		
		max=path[0];
		
		for(i=1;i<n;i++)
		if(path[i]>max)
		max=path[i];
		
		cout<<max<<endl;
	}
	
	
	
	return 0;
}
