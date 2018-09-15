#include<bits/stdc++.h>
using namespace std;

char arr[100][100];
int counts[100]={0};
int maxi=1;

int main()
{
	int n,i,j,k,flag;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			flag=1;
			for(k=0;k<n;k++)
			{
			   if(arr[i][k]!=arr[j][k])
			   {
			   	flag=0;
			   	break;
			   }
		    }
			if(flag)
			counts[i]++;    
		}
		if(counts[i]>maxi)
		maxi=counts[i];
	}
	
	cout<<maxi;
	
	return 0;
}
