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
const int N = 1e5+10; 

ll dp[200010];
int func(int h)
{
	return (h*(h+1))/2;
}
int main(){
  fast;
  int r,g,height;
  cin>>r>>g;

  FOR(i,1,1000)
  {
  	if((i*(i+1))/2>(r+g))
  	{
  		height=i-1;
  		break;
  	}
  }

  //int total=func(height);
  dp[0]=1;
  FOR(i,1,height)
  {
     NFOR(j,r,0)
     { 
     	ll temp=0;
     	if(j>=i and j-i+g>=func(i-1))
     	temp=dp[j-i]%mod;
        if(j+g-i>=func(i-1))
        temp=(temp+dp[j]);

        if(temp>=mod)
        	temp-=mod;

        dp[j]=temp;
     }
  }

  ll ans=0;
  FOR(i,0,r)
  {
  	ans+=dp[i];
    if(ans>=mod)
    	ans-=mod;
  }

  cout<<ans;
  return 0;
}