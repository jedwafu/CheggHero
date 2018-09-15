#include <bits/stdc++.h>
using namespace std;

#define inf 1000000
int price[110];
int dp[110];
int main()
{
	int c;
	cin>>c;
    
	while(c--)
	{
		int n,k;
		cin>>n>>k;
        
        for(int i=1;i<=k;i++)
        	cin>>price[i];

        price[0]=0;
        dp[0]=0;
        dp[1]=(price[1]==-1)? inf:price[1];
       // cout<<dp[1]<<endl;
        for(int i=2;i<=k;i++)
        {
        	dp[i]=inf;
            for(int j=1;j<=i;j++)
            {
            	if(price[j]!=-1)
            		dp[i]=min(dp[i],dp[i-j]+price[j]);
            }
         //   cout<<dp[i]<<endl;
        }
        if(dp[k]==inf)
        	dp[k]=-1;
        cout<<dp[k]<<endl;
	}
	return 0;
}