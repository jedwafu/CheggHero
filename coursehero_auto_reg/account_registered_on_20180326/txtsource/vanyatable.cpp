#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	
	int arr[101][101];
	int i,j,k;
	int x1,y1,x2,y2;
	long long int sum=0;
	
	for(i=1;i<101;i++)
	{
		for(j=1;j<101;j++)
		arr[i][j]=0;
	}
	
	for(i=0;i<n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		
		for(k=x1;k<=x2;k++)
		{
			for(j=y1;j<=y2;j++)
			arr[k][j]++;
		}
	}
	
	for(i=1;i<101;i++)
	{
		for(j=1;j<101;j++)
		sum+=arr[i][j];
	}
	
	cout<<sum;
	return 0;
}
