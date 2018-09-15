#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,k,maxi=0;
	cin>>t;
	while(t--)
	{
		maxi=0;
		cin>>n>>k;
		for(int i=1;i<=k;i++)
		{
			maxi=max(maxi,n%i);
		}
		cout<<maxi<<endl;
	}
	return 0;
}
