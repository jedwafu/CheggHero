#include<bits/stdc++.h>
using namespace std;

long long int fib[95];
int main()
{
	int t,ans;
	long long int n;
	cin>>t;
	
	fib[1]=1;
	fib[2]=2;
	for(int i=3;i<95;i++)
	fib[i]=fib[i-1]+fib[i-2];
	
	while(t--)
	{
		cin>>n;
		for(int i=1;i<95;i++)
		{
			if(n<fib[i])
			{
				ans=i-1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
