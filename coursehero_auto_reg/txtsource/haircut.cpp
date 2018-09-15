#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e3+10; 

ll day[N];
ll dp[N][N];
ll best[N];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	ll n,a,b;
  	cin>>n>>a>>b;

  	fill(best,0);
  	fill(dp,0);
  	FOR(i,1,n)
  	cin>>day[i];

  	FOR(i,1,n)
  	FOR(j,1,i)
  	{
  		if(day[j]-a<0)
  			continue;
  		int lim=day[j]+b-a;
  		int l=j,r=i;
  		while(r-l>1)
  		{
  			int mid=(l+r)/2;
  			if(day[mid]>lim)
  				r=mid;
  			else
  				l=mid;
  		}

  		if(day[r]<=lim)
  			dp[i][j]+=(r-j+1);
  		else if(day[l]<=lim)
  			dp[i][j]+=(l-j+1);

  		lim=day[j]-a;
  		l=1,r=j-1;
  		while(r-l>1)
  		{
  			int mid=(l+r)/2;
  			if(day[mid]>=lim)
  				r=mid;
  			else
  				l=mid;
  		}
  		if(day[r]<lim)
  			dp[i][j]+=best[r];
  		else if(day[l]<lim)
  			dp[i][j]+=best[l];

  		//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
  		if(best[i]<=dp[i][j])
  		{
  			best[i]=dp[i][j];
  			cout<<i<<" "<<j<<" yes"<<endl;
  		}
  		else
  			cout<<i<<" "<<j<<" no"<<endl;	
  		//best[i]=max(best[i],dp[i][j]);
  	}
  	ll ans=0;
  	FOR(i,1,n)
  	ans=max(ans,dp[n][i]);
  	cout<<ans<<endl;
  }
  return 0;
}