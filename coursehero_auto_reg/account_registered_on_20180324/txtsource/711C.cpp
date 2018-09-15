#include<bits/stdc++.h>
using namespace std;

long long arr[110][110];
int color[110];
long long dp[110][110][110];
long long INF = 1e12;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>color[i];
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>arr[i][j];
	}
      
	for(int i=0;i<n;i++)
    { 
    	for(int j=0;j<=k;j++)
        {
        	for(int l=0;l<=m;l++)
        	{
        		dp[i][j][l]=INF;
        	}
        }
    }
    if(color[0]==0)
    {
    	for(int i=1;i<=m;i++)
    	dp[0][1][i]=arr[0][i];
    }
    else
    {
    	dp[0][1][color[0]]=0;
    }
    
    for(int i=1;i<n;i++)
    { 
         for(int j=1;j<=k;j++)
         {
         	for(int l=1;l<=m;l++)
         	{
         		if(color[i]==0)
         		{
         			dp[i][j][l]=dp[i-1][j][l]+arr[i][l];
                    
                    for(int w=1;w<=m;w++)
         			{
         				if(w!=l)
         				dp[i][j][l]=min(dp[i][j][l],dp[i-1][j-1][w]+arr[i][l]);
         			}
         	    }
         	    else
         	    {
         	    	if(color[i]==l)
         	    	for(int w=1;w<=m;w++)
         	    	{
         	    		if(w==l)
         	    			dp[i][j][l]=min(dp[i][j][l],dp[i-1][j][w]);
         	    		else
         	    			dp[i][j][l]=min(dp[i][j][l],dp[i-1][j-1][w]);
         	    	}
         	    }
         	   
         	}

         }
    }

    long long int mini=dp[n-1][k][1];
    for(int i=1;i<=m;i++)
    mini=min(mini,dp[n-1][k][i]);
    
    if(mini >= 1e12-100)
    	cout<<-1<<endl;
    else
    	cout<<mini<<endl;

    return 0;

}