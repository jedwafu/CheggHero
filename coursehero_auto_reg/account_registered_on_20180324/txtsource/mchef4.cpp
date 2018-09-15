#include<bits/stdc++.h>
using namespace std;    
static long long int n,m,k;
static long long int rat[100010];
static long long int val[100010];
static long long int sums[100010]; 
static long long int dp1[100010],dp2[100010],dp3[510],dp4[510];
static long long int tree[500100];

void update(long long int node,long long int st, long long int ed,long long int qs,long long int qe,long long int value)
{
	if(st == qs && ed == qe)
    {   
        tree[node]=min(tree[node], value);
        return;
    }
    
    long long int mid=(st+ed)/2;
    
    if(qe <= mid)
    update(2*node,st, mid, qs, qe, value);
    else if(qs > mid)
    update(2*node +1,mid+1, ed, qs, qe, value);
    else
    {
        update(2*node,st, mid, qs, mid, value);
        update(2*node+1,mid+1, ed, mid+1, qe, value);
    }
    
}

long long int query(long long int node,long long int st, long long int ed, long long int i)
{
    if(st == ed && st == i)
    return tree[node];
        
    int mid = (st + ed)/2;
    if(i<=mid)
    return min(tree[node], query(2*node,st, mid, i));
    else
    return min(tree[node], query(2*node+1,mid+1, ed, i));
}


int main() 
{
    
   static long long int t,minc=600;
   static long long int l,r,c;
	scanf("%lld",&t);
	for(int v=0;v<t;v++)
	{
		 for(int i=0;i<500100;i++)
         tree[i]=600;
            
		scanf("%lld %lld %lld",&n,&k,&m);
		
		cin>>rat[0];
		sums[0]=rat[0];
		val[0]=600;
		
		for(int i=1;i<n;i++)
		{
			cin>>rat[i];
			val[i]=600;
			sums[i]=sums[i-1]+rat[i];
		}
		
	    for(int i=0;i<m;i++)
		{
		   
		    scanf("%lld %lld %lld",&l,&r,&c);
			minc=min(minc,c);
			update(1,1,n,l,r,c);
		}
        
        long long int p=0;
        for(int i=0;i<n;i++)
        {
        	if(rat[i]<0)
        	{
        		val[i]=query(1,1,n,i+1);
        		if(val[i]!=600)
                {
                    dp1[p]=0-rat[i];
                    dp2[p++]=val[i];
                }
			}
		}
        
        long long int len = p;
        for(int i=0;i<=k;i++)
        {
            dp3[i]=0;
            dp4[i]=0;
        }
        
         for(int i=0;i<len;i++)
        {
            dp4[0]=0;
            for(int j=1;j<=k;j++)
            {
                if(dp2[i]<=j)
                    dp4[j]=max(dp3[j], dp3[j-dp2[i]]+dp1[i]);
                else
                    dp4[j]=dp3[j];
            }
            
            for(int j=0;j<=k;j++)
                dp3[j]=dp4[j];
        }
        
		printf("%lld\n",sums[n-1]+dp3[k]);
		
   }
    
    return 0;
}
