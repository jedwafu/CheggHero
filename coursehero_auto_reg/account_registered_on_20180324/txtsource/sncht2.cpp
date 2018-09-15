#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	int arr[100010];
	long long int sums[100010];
	cin>>n>>q;
	sums[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		sums[i]=sums[i-1]+arr[i];
	}
	
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<sums[n]-(sums[r]-sums[l-1])<<endl;
	}
	return 0;
}
