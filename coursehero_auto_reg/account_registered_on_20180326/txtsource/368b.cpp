#include<bits/stdc++.h>
using namespace std;
int n,m;
set<int> s;
int arr[100010];
int last[100010];
int dp[100010];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=100010;i++)
	{
		last[i]=0;
		dp[i]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		s.insert(arr[i]);
		last[arr[i]]=i;
	}
	
	dp[1]=s.size();
	for(int i=2;i<=n;i++)
	{
		if(last[arr[i-1]]==i-1)
		dp[i]=dp[i-1]-1;
		else
		dp[i]=dp[i-1];
	}
	
	for(int i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		cout<<dp[temp]<<endl;
	}
	return 0;
}
