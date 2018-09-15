#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
bool done[1000001];

bool palindrome(int i)
{
	int n=0;
	int temp=1;
	int j=i;
	while(j!=0)
	{
	 temp=j%10;
	 j=j/10;
	 n=n*10+temp;
    }
    if(n==i)
    return true;
    else
    return false;
}

void sieve()
{
	primes.push_back(2);
	done[2]=false;
	for(int i=3;i<=1000;i+=2)
	{
		if(done[i]==false)
		{
			primes.push_back(i);
			
			for(int j=i*i;j<=1000000;j+=i)
			done[j]=true;
		}
	}
	
	for(int i=1001;i<1000000;i+=2)
	{
		if(done[i]==false)
		primes.push_back(i);
	}
}

int main()
{
	for(int i=1;i<1000000;i+=2)
	done[i]=false,done[i+1]=true;
	
	sieve();
	
	
	int t,i;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		for(i=0;i<primes.size();i++)
		{
			if(primes[i]>=x and palindrome(primes[i]))
			{
				cout<<primes[i]<<endl;
				break;
			}
		}
		
		if(i==primes.size())
		{
			cout<<1003001<<endl;
		}
	}
	return 0;
}

