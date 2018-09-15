#include<bits/stdc++.h>
using namespace std;

int arr[110];
int dep[110];

int main()
{
	int i,j,t,n,count,temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		cin>>arr[i];
		
		for(i=0;i<n;i++)
		cin>>dep[i];
		
		count=0;
		for(i=0;i<n;i++)
		{
			temp=0;
			for(j=0;j<n;j++)
			{
				if(dep[j]>=dep[i] && arr[j]<dep[i])
				temp++;
			}
			if(temp>count)
			count=temp;
		}
		cout<<count<<endl;
	}
}
