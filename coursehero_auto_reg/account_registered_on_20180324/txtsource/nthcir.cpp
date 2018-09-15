#include<bits/stdc++.h>
using namespace std;

long long int t;
double r1,r2,r3,r4;
long long int n0,p,m,b;
double ans=0,temp;
double x,y,z;

long long int n;
int main()
{
	scanf("%lld",&t);
	scanf("%lld %lld %lld %lld",&n0,&p,&m,&b);
	scanf("%lf %lf %lf %lf",&r1,&r2,&r3,&r4);
	n=n0;
	x=(1.0/(double)r2-1.0/(double)r1);
	
	y=(1.0/(double)r4);
	z=(1.0/(double)r3);
  	
   // cout<<x<<y<<z<<endl;
	for(long long int i=1;i<=t;i++)
	{
		n=((p%m)*(n%m))%m + b;
		
		if(n==1)
		ans+=r1;
		else if(n==2)
		ans+=r2;
		else if(n==3)
		ans+=r3;
		else if(n==4)
		ans+=r4;
		else
		{
			temp=n-5;
			ans+=1.0/((double)(temp+1)*(temp+2)*x +(double)(2+temp)*y - (double)(1+temp)*z);
		}	
	}
	
	printf("%.6lf",ans);
	
return 0;	
}
