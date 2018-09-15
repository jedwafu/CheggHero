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
const int N = 5e3+10; 

int arr[N][N];
vi dp[N];

int main(){
  fast;
  int n,m;
  cin>>n>>m;
  string s;
  FOR(i,1,n)
  {
    cin>>s;
    int temp=0;
    NFOR(j,m-1,0)
    {
      if(s[j]=='1')
      {
      	temp++;
      	dp[j].pb(temp);
      }
      else
      	temp=0;
    }
  }
  
  int ans=0;
  FOR(j,0,m-1)
  {
  	if(!dp[j].empty())
  	{
  		sort(dp[j].begin(),dp[j].end());
  	    int siz=sz(dp[j])-1;
  	    ans=max(ans,dp[j][0]*(siz+1));
  	    FOR(i,1,siz)
  	    {
          if(dp[j][i]>dp[j][i-1])
          {
           ans=max(ans,dp[j][i]*(siz+1-i));
          }
  	    }
    }
  }
  
  cout<<ans<<endl;
  return 0;
}