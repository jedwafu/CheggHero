#include<bits/stdc++.h>
using namespace std;

int big =sqrt(1000000000);
int check[100000];
int counts[100];

vector<int>v;

void sieve()
{
	int i,j;
	for(i=3;i<=big;i+=2)
	{
		check[i]=1;
	}
	
	v.push_back(2);

	for(i=3;i<=big;i+=2)
	{
		if(check[i]==1)
		{
			for(j=i*i;j<=big;j+=i)
			{
				check[j]=0;
			}
			v.push_back(i);
		}
	}
	
}

int f(int a,int b,int div)
{
    unsigned int cnt=0,m=0;
    for(int i=a;i<=b;i++)
    {
        int h=i,ans=1;
        for(int j=0,t=v[j];j<v.size(); t = v[++j])
        {
                m=0;
                if(h%t==0)
                {
                        
                        while(h%t==0)
                        {
                                m++;
                                h/=t;
                        }
                        
                }
                ans=ans*(m+1);
                
				if(h==1)
                    break;
        }
        if(h>1)
        {
        	ans=ans*2;
		}
		
        if(ans==div)
            cnt++;
     }
     
     return cnt;
}
int main()
{
	sieve();
	long long int l,k,j,i,a,b,n,ans,countt=0;
	cin>>a>>b>>n;
	
	countt=f(a,b,n);
	cout<<countt;
	return 0;
}
