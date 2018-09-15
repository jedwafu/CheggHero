#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int arr[600010];
int main()
{
	int n,k;
	cin>>n>>k;

	for(int i=1;i<=n;i++)
		cin>>arr[i];

    ll sum=0;
	for(int i=1;i<=k;i++)
		sum+=arr[i];
    
    ll mini=sum;
    int ans=1;
	for(int i=2;i<=n-k+1;i++)
	{	
		sum=sum-arr[i-1]+arr[i+k-1];    
		if(sum<mini)
		{
			mini=sum;
			ans=i;
		}
	}

	cout<<ans;
	return 0;
}