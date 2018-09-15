#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool arr[100000];

vector<int> primes;
bool isPrime(long n)
{
    if(n==1)
    return false;
	int uLimit=sqrt(n);
	int size=primes.size();
	for(int i=0;primes[i]<=uLimit && i<size;i++)
	if(n%primes[i]==0)
	return false;
	return true;
}
int main()
{
	long long int i,j;
	int ul=sqrt(1000000000);
	
	arr[2]=true;
	for(i=3;i<=ul;i+=2)
	{
	arr[i]=true;
	arr[i+1]=false;
    }
    
	for( i=3;i<=ul;i+=2)
	{
		if(arr[i]==true)
        for( j=i*i;j<=ul;j=j+i)
        {
        	arr[j]=false;
		}
	}
    primes.push_back(2);
    
    for(i=3;i<=ul;i+=2)
    if(arr[i]==true)
    primes.push_back(i);
    
	int t;
	cin>>t;
	while(t--)
	{
	    long n,m;
	    cin>>m>>n;
	    if(m==2 || m==1)
	    {
	        cout<<2<<endl;
	        m=3;
	    }else
	    if(m%2==0)
	    m++;
 
	    for(long i=m;i<=n;i+=2)
	    if(isPrime(i))
	    cout<<i<<endl;
	    cout<<endl;
	}
 
 
	return 0;
}
