#include<bits/stdc++.h>
using namespace std;

int maxi(int st,int ed,int a)
{
	if(ed-st+1==a)
	return 1;
	
	return (ed-st+2)/(a+1);
}

int arr[200010];

int main()
{
	int n,k,a;
	cin>>n>>k>>a;
	int m;
	cin>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<m;i++)
	{
		if(maxi(1,arr[i]-1,a)+maxi(arr[i]+1,n,a)>=k)
		continue;
		else
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	
	cout<<-1<<endl;
	return 0;
}
