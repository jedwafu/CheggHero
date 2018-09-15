#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,m,n,ans,temp,ind;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n%2)
		{
			ans=m/n;
			temp=m%n;
			
			if(temp==0)
			{
			 ind=(n+1)/2;
	         cout<<ind<<" "<<ans<<endl;
                continue;
		    }
		
			
			if(ans%2)
			{
				if(temp%2)
				ind=n-temp/2;
				else
				ind=temp/2;
			}
			else
			{
				if(temp%2)
				ind=temp/2+1;
				else
				ind=(n+1)-temp/2;
			}
		}
		else
		{
			ans=m/n;
			temp=m%n;
			if(temp==0)
		    {
		    	ind=n/2+1;
                cout<<ind<<" "<<ans<<endl;
		    	continue;
			}
			if(temp%2)
			ind=temp/2+1;
			else
			ind=(n+1)-temp/2;
		}
		
		cout<<ind<<" "<<ans<<endl;
	}
	return 0;
}
