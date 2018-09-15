#include<bits/stdc++.h>
using namespace std;

int arr[1001];

int main()
{
	int n,m,a,b,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(arr[a]>arr[b])
		ans+=arr[b];
		else
		ans+=arr[a];
	}
	
	cout<<ans;
	
	return 0;

}
