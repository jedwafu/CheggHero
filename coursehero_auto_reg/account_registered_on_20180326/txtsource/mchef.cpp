#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long int rat[100010];
long long int val[100010];
long long int sums[100010];
set<pair<int,pair<int,int> > > starts;
set<long long int> ends;
vector<pair<int,pair<int,int> > > v[100010];
vector<pair<int,pair<int,int> > > e[100010];
long long int dp[100010][501];
int main()
{

long long int t,minc=600;
scanf("%lld",&t);
for(int p=0;p<t;p++)
{
    scanf("%d %d %d",&n,&k,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&rat[i]);
		val[i]=600;
		if(i==0)
		sums[i]=rat[i];
		else
		sums[i]=sums[i-1]+rat[i];
	}
	
	for(int i=0;i<m;i++)
	{
		long long int l,r,c;
		scanf("%lld %lld %lld",&l,&r,&c);
		minc=min(c,minc);
		v[l-1].push_back(make_pair(c,make_pair(l-1,r-1)));
		e[r-1].push_back(make_pair(c,make_pair(l-1,r-1)));
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			starts.insert(v[i][j]);
			//cout<<"inserting "<<i<<" "<<v[i][j]<<endl;
		}
		
		v[i].clear();
		
		//cout<<starts.begin()->first<<endl;
		if(starts.empty()==false)
		val[i]=starts.begin()->first;
		
		for(int j=0;j<e[i].size();j++)
		{
			starts.erase(e[i][j]);
			//cout<<"erasing "<<e[i][j]<<endl;
		}
		e[i].clear();
	}
	
	//starts.clear();
	
	for(int i=0;i<minc;i++)
		{
			for(int j=0;j<n;j++)
			dp[j][i]=sums[j];
		}
		
		
		for(int j=minc;j<=k;j++)
		{
			if(rat[0]<0 && val[0]<=j)
			dp[0][j]=0;
			else
			dp[0][j]=rat[0];
		}
		
		for(int i=1;i<n;i++)
		{
			for(int j=minc;j<=k;j++)
			{
				if(j-val[i]>=0)
				dp[i][j]=max((dp[i-1][j]+rat[i]),(dp[i-1][j-val[i]]));
				else
				dp[i][j]=dp[i-1][j]+rat[i];
				
				//cout<<"dp["<<i<<"]["<<j<<"] is"<<dp[i][j]<<endl;
			}
		}
		
		printf("%lld\n",dp[n-1][k]);
	
}

return 0;
}
