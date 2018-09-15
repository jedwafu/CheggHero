#include<bits/stdc++.h>
using namespace std;

int arr[50];
int main()
{
	int n,m;
	int mini=10000000;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+m);
	
	for(int i=0;i<m-n+1;i++)
	{
		mini=min(mini,arr[i+n-1]-arr[i]);
	}
	cout<<mini;
}
