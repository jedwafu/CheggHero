#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int arr[50010];
ll dp[50010];
int n,m,a,b;

ll function(int index)
{
	//cout<<"\ncall to "<<index<<endl;
	if(index >= n)
		return 0;

	if(dp[index]!= -1)
		return dp[index];

	int i=index;
	ll sum=0;
	bool flag=true;

	while(i<n)
    {
    	if(sum+arr[i]<= m)
    	{
    		sum+=arr[i];
    		i++;
    	}

    	else
    	{
           flag=false;
           break;
    	}
    }

    if(flag)
    {
    	dp[index]=(m-sum)*b;
    	//cout<<"\n for_ " << index << " "<<dp[index]<<endl;
    	return dp[index];
    }

    dp[index]= min((arr[i]-(m-sum))*a + function(i+1),((m-sum)*b + function(i)));
    //cout<<"\n for " << index << " "<<dp[index]<<endl;
    return dp[index];  
}

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	
    	cin>>n>>m;
    	cin>>a>>b;

    	for(int i=0;i<=n;i++)
    		dp[i]=-1;

    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        
        ll ans= function(0);
        cout<<ans<<endl;

    }	
    return 0;
}