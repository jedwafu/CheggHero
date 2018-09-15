#include<bits/stdc++.h>
using namespace std;

int arr[70][70];
int xorval[70][70];
int main()
{
	int i,j,n,t,x,y,k,l,ans;
	cin>>t;
	
	while(t--)
	{
	  cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cin>>arr[i][j];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			xorval[i][j]=0;
			for(x=0;x<=i;x++)
			{
				for(y=0;y<=j;y++)
				{
					xorval[i][j]=xorval[i][j]^arr[x][y];
				}
			}
		}
	}
	
	int maxi=0;
	
	
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			
			for(k=0;k<n;k++)
			{
				for(l=k;l<n;l++)
				{
					if(i>0 && k>0)
					ans=xorval[i-1][l]^xorval[j][k-1]^xorval[j][l]^xorval[i-1][k-1];
					else if(i>0)
					ans=xorval[i-1][l]^xorval[j][l];
					else if(k>0)
					ans=xorval[j][k-1]^xorval[j][l];
					else
					ans=xorval[j][l];
					
					if(ans>maxi)
					maxi=ans;
				}
			}
		}
	}

	cout<<maxi<<endl;
    }
    return 0;
}
