#include<iostream>

using namespace std;
long long int arr[100000][2];
int main()
{
	int t,n,i,count;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		count=0;
		for(i=0;i<n;i++)
		{
			cin>>arr[i][0];
			arr[i][1]=1;
		}
		
		for(i=0;i<n-1;i++)
		{
			if(arr[i][0]!=arr[i+1][0])
			{
				if(arr[i][1]==1)
				{
				  count=count+2;
				  arr[i][1]=arr[i+1][1]=0;
			    }
			    
			    else
			    {
			    	count++;
			    	arr[i+1][1]=0;
				}
			}
			
		}
		
		cout<<count<<endl;
	}
	
	return 0;
}
