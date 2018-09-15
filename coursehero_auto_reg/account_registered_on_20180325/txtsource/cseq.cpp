#include<iostream>
#define mod 1000003
using namespace std;

int findinverse(int a, int b)
{
int x[3];
int y[3];
int quotient  = a / b;
int remainder = a % b;

x[0] = 0;
y[0] = 1;
x[1] = 1;
y[1] = quotient * -1;

int i = 2;
for (; (b % (a%b)) != 0; i++)
{
a = b;
b = remainder;
quotient = a / b;
remainder = a % b;
x[i % 3] = (quotient * -1 * x[(i - 1) % 3]) + x[(i - 2) % 3];
y[i % 3] = (quotient * -1 * y[(i - 1) % 3]) + y[(i - 2) % 3];
}

//x[i - 1 % 3] is inverse of a
//y[i - 1 % 3] is inverse of b
return x[(i - 1) % 3];
}
int main()
{
	int t,i;
	long long int n,l,r,k;
	long long int sum,help,temp;
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		k=r-l+1;
		if(n>k)
		n=k;
		
		sum=k;
		help=k;
		for(i=2;i<=n;i++)
		{
			temp=findinverse(i,mod);
			help=((((help)%mod*((k+i-1)%mod))%mod)*(temp%mod))%mod;
			sum=((sum%mod)+(help%mod))%mod; 
			sum=sum%mod;
		}
		cout<<sum<<endl;		
	}
	return 0;
}
