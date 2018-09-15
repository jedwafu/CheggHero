#include<bits/stdc++.h>
using namespace std;

long long int powers[31];
void calpow()
{
	powers[0]=1;
	int i;
    for(i=1;i<31;i++)
    {
    	powers[i]=2*powers[i-1];
	}
}

int main()
{
	calpow();
	int t,n,i,j,count1,count2,max1,max2;
	long long int a,b,ans;
	cin>>t;
	while(t--)
	{
		ans=0;
		count1=count2=0;
		cin>>n>>a>>b;
		while(a>0)
		{
			if(a%2==1)
			count1++;
			a=a/2;
		}
		
		while(b>0)
		{
			if(b%2==1)
			count2++;
			b=b/2;
		}
		
		if(count1>n-count2)
		max1=n-count2;
		else
		max1=count1;
		
		if(count2>n-count1)
		max2=n-count1;
		else
		max2=count2;
		
		max1=max1+max2;
		i=0;
	    while(max1--)
	    {
	    	ans=ans+powers[n-1-i];
	    	i++;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
