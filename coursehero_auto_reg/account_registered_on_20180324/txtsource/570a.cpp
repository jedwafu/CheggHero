#include<bits/stdc++.h>
using namespace std;

long long int arr[101][101];
long long int can[101];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	can[i]=0;
	
	for(int i=1;i<=m;i++)
	{
		long long int maxi=0,temp=1;
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]>maxi)
			{
			  temp=j;
			  maxi=arr[i][j];
		    }
		}
		can[temp]++;
	}
	
	long long maxi=0;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(can[i]>maxi)
		{
			ans=i;
			maxi=can[i];
		}
	}
	
	cout<<ans;
	return 0;
}
