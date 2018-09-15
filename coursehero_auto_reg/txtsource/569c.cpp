#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<int> val(20001);
vector<int> rub(20001);
bool done[100001];
void sieve()
{
	for(int i=1;i<=20000;i+=2)
	done[i]=true,done[i+1]=false;
	
	primes.push_back(2);
	val[2]=1;
	int prev=1;
	
	for(int i=3;i<=20000;i++)
	{
		if(done[i]==true)
		{
			primes.push_back(i);
			val[i]=prev+1;
			prev++;
			
			for(int j=i*i;j<=20000;j+=i)
			{
				done[j]=false;
			}
		}
		else
		val[i]=prev;
	}
}

bool ispalin(int n)
{
	int j=n;
	int temp=0;
	while(j>0)
	{
		temp=temp*10+j%10;
		j=j/10;
	}
	if(temp==n)
	return true;
	else
	return false;
}

void palindrome()
{
	int prev=0;
	for(int i=1;i<=20000;i++)
	{
		if(ispalin(i))
		{
			rub[i]=prev+1;
			prev++;
		}
		else
		rub[i]=prev;
	}
}

bool isprime(int n)
{
	for(int i=0;i<primes.size();i++)
	{
		if(n%primes[i]==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	sieve();
	palindrome();
	int p,q;
	cin>>p>>q;
	double a=p/(double)q;
	int maxi=0;
	val[1]=0;
	
	for(int i=1;i<20000;i++)
	{
		if((double)val[i]/(double)rub[i]<=a)
		maxi=i;
	}
	double p1=val[19999],p2=rub[19999];
	
	if(maxi<19999)
	{
	cout<<maxi;
	return 0;
    }  
	
	for(int i=20000;i<2000000;i++)
	{
		
		if(isprime(i))
		p1=p1+1;
		if(ispalin(i))
		p2=p2+1;
		
		if((double)p1/(double)p2<=a)
		maxi=i;
	}
	
	cout<<maxi;
	return 0;
}
