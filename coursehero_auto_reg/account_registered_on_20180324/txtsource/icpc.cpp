#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
 	{
           
		ll n;
		cin>>n;
        ll ans=0;
        
        if(n==0)
        ans=0;

		else if(n%2)
		{
			ans+=(n/2)+1;
            ll temp=ceil((n-1)/3.0);  
			if(!((n-1)%3))
				temp++;


			if(temp%2)
			ans+= (n-temp)/2 +1;
			else
            ans+=(n-temp+1)/2; 
		}
		else
		{
			ans+=n/2;
			ll temp=ceil((n-1)/3.0);
			if(!((n-1)%3))
				temp++;
			if(temp%2)
			ans+=(n-temp+1)/2;
		    else 
            ans+=(n-temp)/2;
		}

		cout<<ans<<endl;
	}
	return 0;
}