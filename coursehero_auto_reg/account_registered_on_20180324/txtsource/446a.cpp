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

ll arr[N];
int dp[N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>arr[i];
  dp[n]=1;
  int ans=1;

  NFOR(i,n-1,1)
  {
  	if(arr[i]<arr[i+1])
  	dp[i]=dp[i+1]+1;
    else
  	dp[i]=1;
    
    ans=max(ans,dp[i]);
  }

  if(arr[1]>=arr[2])
  	ans=max(ans,1+dp[2]);
  if(arr[n]<=arr[n-1])
  	ans=max(ans,1+dp[n-1]);

  FOR(i,1,n)
  {
     if(i+dp[i]-1<n)
     	ans=max(dp[i]+1,ans);
     if(i+dp[i]-1<=n and i>1)
     	ans=max(dp[i]+1,ans);
     if(i+dp[i]<n and (arr[i+dp[i]+1]-arr[i+dp[i]-1]>=2))
        ans=max(ans,dp[i]+dp[i+dp[i]+1]+1);
     if(i+dp[i]<=n and i+dp[i]-2>0 and (arr[i+dp[i]]-arr[i+dp[i]-2]>=2))
        ans=max(ans,dp[i]+dp[i+dp[i]]);
  }
  cout<<ans<<endl;
  return 0;
}