#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[100010];
int main()
{
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int maxi=1;
	int cur=1;

	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			cur++;
			if(cur>maxi)
				maxi=cur;
		}
		else
		 cur=1;
	}

	cout<<maxi<<endl;
}