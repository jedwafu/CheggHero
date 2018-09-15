#include<bits/stdc++.h>
using namespace std;

int arr[1010];
int main()
{
	int n,i,flag=1;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>arr[i];
	if(n==1)
	{
		cout<<"Yes";
		return 0;
	}
	
	for(i=0;i<n-2;i+=2)
	{
		if(((arr[i]+2)%n)==arr[i+2])
		flag=1;
		else
		{
			flag=0;
			break;
		}
	}
	
	if(flag==0)
	{
		cout<<"No";
		return 0;
	}
	
	for(i=1;i<n-2;i+=2)
	{
		if(((arr[i]+2)%n)==arr[i+2])
		flag=1;
		else
		{
			flag=0;
			break;
			
		}
	}
	
	if(flag==0)
	{
		cout<<"No";
		return 0;
	}
	
	if(arr[1]==0)
	arr[1]=n;
	if(arr[0]==0)
	arr[0]=n;
	
	if((n-arr[0])==(arr[1]-1))
	{
		cout<<"Yes";
	}
	else
	cout<<"No";
	
	return 0;
}
