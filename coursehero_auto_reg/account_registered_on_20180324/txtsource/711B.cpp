#include<bits/stdc++.h>
using namespace std;

long long int arr[505][505];
int main()
{
	int n;
	cin>>n;
	int index1,index2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==0)
			{	index1=i,index2=j;}

		}
	}
	if(n==1)
    {
    	cout<<1<<endl;
    	return 0;
    }
    int flag;
    if (index1==0)
    	flag=1;
    else
    	flag=0;

    long long int sum1,sum2;
    sum1=sum2=0;
	for(int i=0;i<n;i++)
	{ 
       sum1+=arr[flag][i];
       sum2+=arr[index1][i];          
	}
	if(sum1-sum2<=0)
	{
		cout<<-1;
		return 0;
	}
    arr[index1][index2]=sum1-sum2;
    long long ans=sum1-sum2;
    flag=1;
    for(int i=0;i<n;i++)
    {
    	sum2=0;
    	for(int j=0;j<n;j++)
    	{
    		sum2+=arr[i][j];
    	}
    	if(sum2!=sum1)
    	{
    		flag=0;
    		break;
    	}
    }
    if(!flag)
    {
    	cout<<-1<<endl;
    	return 0;
    }

    for(int i=0;i<n;i++)
    {
    	sum2=0;
    	for(int j=0;j<n;j++)
    	{
    		sum2+=arr[j][i];
    	}
    	if(sum2!=sum1)
    	{
    		flag=0;
    		break;
    	}
    }

     if(!flag)
    {
    	cout<<-1<<endl;
    	return 0;
    }
    sum2=0;
    for(int i=0;i<n;i++)
    {
    	sum2+=arr[i][i];
    }
    if(sum2!=sum1)
    {
    	cout<<-1<<endl;
    	return 0;
    }
    sum2=0;
    for(int i=0;i<n;i++)
    {
    	sum2+=arr[i][n-1-i];
    }
    if(sum2!=sum1)
    {
    	cout<<-1<<endl;
    	return 0;
    }
    cout<<ans<<endl;
    return 0;

}