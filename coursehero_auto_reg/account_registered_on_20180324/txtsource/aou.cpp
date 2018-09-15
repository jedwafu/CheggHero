#include<bits/stdc++.h>
using namespace std;

const long long int big=1e9;
vector<int> primes;
bool done[100010];
void sieve()
{
	primes.push_back(2);
	done[2]=true;
	for(int i=3;i<=sqrt(big);i+=2)
	{
		if(done[i]==false)
		{
			primes.push_back(i);
			for(int j=i*i;j<=sqrt(big);j+=i)
			{
				done[j]=false;
			}
		}
	}
}

int main()
{
	for(int i=1;i<1e5+10;i++)
	done[i]=false;
	
	
	sieve();
	long long int n;
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		int ans=0;
		int ctr=0;
		while(n>1 and ctr<primes.size())
		{
			if(n%primes[ctr]==0)
			{
				n/=primes[ctr];
				ans++;
			}
			
			else
			ctr++;
		}
		if(n>1)
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}
