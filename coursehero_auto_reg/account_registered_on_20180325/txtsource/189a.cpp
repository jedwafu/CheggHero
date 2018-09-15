#include<bits/stdc++.h>
using namespace std;
int n,arr[3];
int dp[4001];

int main()
{
	cin>>n>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	for(int i=0;i<4001;i++)
	dp[i]=-1;
	
	dp[0]=0;

    if(n<arr[0])
    {
    	cout<<0;
    	return 0;
	}
	
	int temp1,temp2,temp3,flag;
    for(int i=arr[0];i<=n;i++)
    {
    	 flag=0,temp1=0,temp2=0,temp3=0;
    	if( dp[i-arr[0]]>=0)
    	{
    		flag=1;
		  temp1=max(dp[i],dp[i-arr[0]]+1);
		  //cout<<i<<arr[0]<<temp1<<endl;
	    }
		
		if(dp[i-arr[1]]>=0 && i-arr[1]>=0)
		{
			flag=1;
		  temp2=max(dp[i],dp[i-arr[1]]+1);
		  //cout<<i<<arr[1]<<temp2<<endl;
	    }
	    
		if(dp[i-arr[2]]>=0 && i-arr[2]>=0)
		{
			flag=1;
		  temp3=max(dp[i],dp[i-arr[2]]+1);
		  //cout<<i<<arr[2]<<temp3<<endl;
	    }
	    
	    if(temp1<temp2)
	    temp1=temp2;
	    if(temp1<temp3)
	    temp1=temp3;
	    
	    if(flag==1)
	    dp[i]=temp1;
	    
	} 
	
	cout<<dp[n];
}
