#include<bits/stdc++.h>
using namespace std;

int arr[1010];
int arr0[1010];
int arr1[1010];
int arr2[1010];
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr0[i]=arr1[i]=arr2[i]=0;
	}
	
	if(arr[0]%3==1)
	arr1[0]=arr[0];
	else if(arr[0]%3==2)
	arr2[0]=arr[0];
	else
	arr0[0]=arr[0];
	
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]%3==1)
		{
			arr1[i]=arr[i];
			for(int j=0;j<i;j++)
			{
				if(arr0[j]!=0)
				arr1[i]=max(arr1[i],arr0[j]+arr[i]);
				if(arr1[j]!=0)
				arr2[i]=max(arr2[i],arr1[j]+arr[i]);
				if(arr2[j]!=0)
				arr0[i]=max(arr0[i],arr2[j]+arr[i]);
			}
		}
		
		else if(arr[i]%3==2)
		{
			arr2[i]=arr[i];
			for(int j=0;j<i;j++)
			{
				if(arr2[j]!=0)
				arr1[i]=max(arr1[i],arr2[j]+arr[i]);
				if(arr0[j]!=0)
				arr2[i]=max(arr2[i],arr0[j]+arr[i]);
				if(arr1[j]!=0)
				arr0[i]=max(arr0[i],arr1[j]+arr[i]);
			}
		}
		else
		{
			arr0[i]=arr[i];
			for(int j=0;j<i;j++)
			{
				if(arr1[j]!=0)
				arr1[i]=max(arr1[i],arr1[j]+arr[i]);
				if(arr2[j]!=0)
				arr2[i]=max(arr2[i],arr2[j]+arr[i]);
				if(arr0[j]!=0)
				arr0[i]=max(arr0[i],arr0[j]+arr[i]);
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		ans=max(ans,arr0[i]);
	}
	cout<<ans<<endl;
	return 0;
}
