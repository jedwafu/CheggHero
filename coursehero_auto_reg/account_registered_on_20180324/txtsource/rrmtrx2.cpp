#include<iostream>

using namespace std;

int main()
{
	int n,m,i,j;
	cin>>n>>m;
	
	int arr[47][38];
	long long int sum[38];
	long long int ans;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		cin>>arr[i][j];
	}
	
	for(i=0;i<m;i++)
	{
		sum[i]=0;
		
		for(j=0;j<n;j++)
		sum[i]=sum[i]+arr[j][i];
	}

	
	ans=1;
	for(i=0;i<m;i++)
	{
		
		ans=(ans%10000007)*(sum[i]%10000007)%10000007;
		
	}

	if(ans<0)
	ans=ans + 10000007;
	
	cout<<ans;
	
	return 0;
	
	
	
}
