#include<bits/stdc++.h>
using namespace std;

int main()
{

	int t,s,q;
	cin>>t>>s>>q;
	long long ans=s+s*(q-1);
	long long prev=s*(q-1);
	int counts=1;
	while(ans<t)
	{
		ans+=prev*q;
		counts++;
		prev=prev*q;
	}
	cout<<counts;
	return 0;
}
