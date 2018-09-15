#include<bits/stdc++.h>
using namespace std;
long long int arr[100010];

int main()
{
	int t;
	long long int n,k;
	cin>>t;
	while(t--)
	{
	
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	long long int bread=1;
	long long int left=k;
	
	for(int i=0;i<n;i++)
	{
	    if(left==0)
		{
			bread++;
			left=k;
		}
		
		if(left-arr[i]>0)
		left=left-arr[i]-1;
		
		else if(left-arr[i]==0)
		left=0;
		
		else 
		{
			arr[i]=arr[i]-left;
			bread+=arr[i]/k;
			arr[i]=arr[i]%k;
			left=0;
			if(arr[i]!=0)
			i--;
		}
	}
	
	cout<<bread<<endl;
    
	}
	return 0;
}
