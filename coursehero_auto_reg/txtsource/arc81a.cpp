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
const int N = 2e5+10; 

int nxt[N][26];
int dp[N];
int main(){
  fast;
  string s;
  cin>>s;

  FOR(i,0,25)
  nxt[sz(s)][i]=sz(s);

  NFOR(i,sz(s)-1,0)
  {
  	FOR(j,0,25)
  	{
  		if(s[i]-'a'==j)
  			nxt[i][j]=i;
  		else
  			nxt[i][j]=nxt[i+1][j];
  	}
  }

  dp[sz(s)]=1;
  dp[sz(s)+1]=0;
  NFOR(i,sz(s)-1,0)
  {
  	dp[i]=sz(s)-i;
  	FOR(j,0,25)
  	{
  		dp[i]=min(dp[i],dp[nxt[i][j]+1]+1);
  	}
  	//cout<<i<<" "<<dp[i]<<endl;
  }


  int cur=0;
  string ans="";
  while(cur<sz(s))
  {
  	FOR(j,0,25)
  	{
  		if(dp[cur]==dp[nxt[cur][j]+1]+1)
  		{
  			//cout<<j<<" "<<nxt[cur][j]<<endl;
  			ans+='a'+j;
  			cur=nxt[cur][j]+1;
  			break;
  		}
  	}
  }

  cout<<ans;
  return 0;
}