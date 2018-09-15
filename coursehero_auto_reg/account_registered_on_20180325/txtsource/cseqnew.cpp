#include<bits/stdc++.h>
using namespace std;
#define mod 1000003

int modu(int n,int m)
{
	long long int temp;
	
    if(m==0)
    return 1;
    if(m==1)
    return n;
    if(m%2)
    {
    	return ((n%mod)*(modu(n,m-1)%mod))%mod;
	}
	
	else
	{
		temp=modu(n,m/2);
		return ((temp%mod)*(temp%mod))%mod;
	}
}

int main()
{
	int t,i;
	long long int n,l,r,ans,term;
	
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		
		
		long int k= r-l+1;
		if(n>k)
		n=k;
		
		ans=term=k%mod;
		
		for(i=1;i<n;i++)
		{
			term=(((term%mod *(i+k)%mod)%mod)*modu((i+1),mod-2))%mod;
			ans=(ans%mod+term%mod)%mod;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
