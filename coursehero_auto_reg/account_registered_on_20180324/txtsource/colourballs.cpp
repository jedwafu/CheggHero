#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int arr[1001][1001];
int inp[1001];
 
void bq()
{
	int i,j;
	
	for(i=0;i<=1000;i++)
	{
		arr[i][0]=1;
		
		for(j=1;j<=i;j++)
		arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%mod;
		
	}
}

int main()
{
	int k,i;
	bq();
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>inp[i];
	}
	long long int ans=1,sum=inp[0];
	
	for(i=2;i<=k;i++)
	{
		sum+=inp[i-1];
		ans=(ans*arr[sum-1][inp[i-1]-1]%mod)%mod;	
	}
	
	cout<<ans;
	return 0;
}
