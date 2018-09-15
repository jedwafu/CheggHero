#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	long long int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int ans=0;
		ans=n/26;
		if(n%26)
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}
