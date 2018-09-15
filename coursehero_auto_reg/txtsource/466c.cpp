#include<bits/stdc++.h>
using namespace std;
int arr[500010];
int counts[500010];
int sums[500010];

int n;
long long int sum=0;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
    {
	  cin>>arr[i];
	  sum+=arr[i];
    }
    if(sum%3)
    {
    	cout<<0;
    	return 0;
	}
    if(arr[n-1]==sum/3)
    counts[n-1]=1;
    else
    counts[n-1]=0;
    sums[n-1]=counts[n-1];
    long long int temp=arr[n-1];
    
    for(int i=n-2;i>=0;i--)
    {
        temp+=arr[i];
        
        if(temp==sum/3)
        counts[i]=1;
        else
        counts[i]=0;
        
        sums[i]=sums[i+1]+counts[i];
	}
	temp=0;
	long long int ans=0;
	for(int i=0;i<=n-3;i++)
	{
		temp+=arr[i];
		
		if(temp==sum/3)
		ans+=sums[i+2];
	}
    cout<<ans;
}
