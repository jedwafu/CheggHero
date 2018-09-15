#include<bits/stdc++.h>
using namespace std;
long long int mod =1000000007;

long long arr[1000010];
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int neg=0;
		long long prod=1;
		long long big=-1e7;
		bool here=false;
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		    
			if(arr[i]>0)
		    prod=((prod%mod)*(arr[i]%mod))%mod,here=true;
		    
			if(arr[i]<0)
		    {
		    	neg++;
		    	
		    	if(arr[i]>big)
		    	big=arr[i];
			}
		}
	
	    if(here==false and neg<=1)
	    prod=0;
	
		if(n==1)
		{
			if(arr[0]<0)
			cout<<(arr[0]+mod)%mod<<endl;
			else
			cout<<arr[0]%mod<<endl;
			continue;
		}
		
		bool done=false;
		if(neg%2==0)
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]<0)
				{
					prod=((prod%mod)*((arr[i]+mod)%mod))%mod;
				}
			}
		}
		
		else 
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]<0)
				{
					if(arr[i]==big && done==false)
					{
						done=true;
					}
					
					else
					{
						prod=((prod%mod)*((arr[i]+mod)%mod))%mod;
					}
				}
			}
		}
		
		cout<<prod<<endl;
	}
	return 0;
}
