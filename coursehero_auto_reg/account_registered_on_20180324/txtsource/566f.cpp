#include<bits/stdc++.h>
using namespace std;

bool present[1000010];
int dp[1000010];
int main()
{
	int n,maxi=1;
	cin>>n;
	for(int i=1;i<=1000010;i++)
	{
		present[i]=false;
		dp[i]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		present[temp]=true;
		dp[temp]=1;
	}
	
	for(int i=1;i<=1000010;i++)
	{
		if(present[i])
		{
			maxi=max(dp[i],maxi);
			
		   for(int j=2*i;j<=1000010;j+=i)
		   {
		     if(present[j])
		     {
		     	dp[j]=max(dp[j],dp[i]+1);
		        maxi=max(dp[j],maxi);
			 }
		   }
		}
	}
	
	cout<<maxi<<endl;
	return 0;
}
