#include<bits/stdc++.h>
using namespace std;
#define ll long long 

map<ll,ll> freq;
ll arr[1000010];
ll exact[1000010];
ll atleast[1000010];
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
        exact[i]=0;
        atleast[i]=0;
    }


	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
	}
    
    for(int i=0;i<n;i++)
    {
       if (exact[freq[arr[i]]]==0)
       	exact[freq[arr[i]]]=arr[i];
    }

    ll maxi=0;

    for(int i=0;i<n;i++)
    {
       if(freq[arr[i]]>=maxi)
       {
       	 while(maxi<=freq[arr[i]])
       	 {
             atleast[maxi]=arr[i];
             maxi++;
       	 }
       }
    }
    
    /*for(int i=0;i<n;i++)
    {
    	cout<<"exact "<<exact[i]<<endl;
    	cout<<"atleast "<<atleast[i]<<endl;
    }*/

    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
    	int type;
    	ll f;
    	scanf("%d %lld",&type, &f);
        if(f>n)
          printf("%d\n",0);

    	else if(type)
    	printf("%lld\n",exact[f]);    
        else
        printf("%lld\n",atleast[f]);
    }
    
return 0;
}