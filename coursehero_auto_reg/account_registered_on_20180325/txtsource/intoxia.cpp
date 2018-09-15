#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,k,ans=0;
	float val=0;
	long long int arr[25];
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+k);
	
	if(arr[0]>1)
	{
		for(int i=0;i<k;i++)
		{
			for(long long int j=arr[i];j<=n;j+=arr[i])
			{
				ans++;
				
			   for(int k=0;k<i;k++)
			   {
			   	if(j%arr[k]==0)
			   	{
			   		ans--;
			   		break;
				   }
			   }
			}
		}
		
		val=(n-ans)/float(n);
		val*=100;
	}
	
	cout<<val<<endl;
	return 0;
}
