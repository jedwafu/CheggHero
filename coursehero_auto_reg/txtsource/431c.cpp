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
ll dp[110][110];

ll mods(ll a,ll b)
{
	return (a%b + b)%b;
}

ll DP(int n,int k,int d)
{
	if(n<0)
   	return 0;
   
   if(dp[n][d]!=-1)
   return dp[n][d];

   ll ans=0;
   int val=d;

   FOR(i,1,k)
   {
   	  val=d;
   	  if(i>=d)
   	  	val=0;
      ans= mods(mods(ans,mod)+mods(DP(n-i,k,val),mod),mod);
   	 // ans=ans+DP(n-i,k,val);
   } 

   dp[n][d]=ans;
   return ans;
}

int main(){
  fast;
  int n,k,d;
  cin>>n>>k>>d;
  
  FOR(i,0,n)
  FOR(j,0,d)
  dp[i][j]=-1;
  
  FOR(i,0,d-1)
  dp[i][d]=0;
  
  dp[1][0]=1;
  dp[0][0]=1;
  cout<<DP(n,k,d)<<endl;
  return 0;
}