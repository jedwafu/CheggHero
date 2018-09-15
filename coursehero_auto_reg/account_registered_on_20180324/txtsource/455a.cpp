#include<bits/stdc++.h>
using namespace std;

long long int cnt[100010];
int arr[100010];
long long int dp[100010];
int main()
{
	int n,maxi=0;
	cin>>n;
	for(int i=0;i<=100010;i++)
	cnt[i]=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		cnt[arr[i]]++;
		maxi=max(maxi,arr[i]);
	}
	dp[0]=0,dp[1]=cnt[1];
	for(long long int i=2;i<=maxi;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
	}
	
	cout<<dp[maxi];
    return 0;
}
