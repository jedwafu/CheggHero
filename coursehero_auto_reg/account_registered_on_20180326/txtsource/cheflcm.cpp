#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int t,i;
	long long int n,sum;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		sum=1+n;
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				if(n/i==i)
				sum=sum+i;
				else
				sum=sum+i+n/i;
			}
		}
		
		if(n==1)
		cout<<1<<endl;
		else
		cout<<sum<<endl;
	}
	return 0;
}
