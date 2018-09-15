#include<bits/stdc++.h>
using namespace std;
int arr[100];
int dp[100];

int main()
{
	int n,s=0,maxi=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]==1)
		{
		  s++;
		  arr[i]=-1;
	    }
	    
	 	else arr[i]=1;
	}
	if(s==n)
	{
		cout<<s-1;
		return 0;
	}
	dp[0]=max(0,arr[0]);
	maxi=arr[0];
	for(int i=1;i<n;i++)
	{
		dp[i]=max(0,dp[i-1]+arr[i]);
		maxi=max(maxi,dp[i]);
	}
	
	cout<<s+maxi;
	return 0;
}
