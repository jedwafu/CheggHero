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

int arr[N];
int dp[N];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  double d;
  FOR(i,1,n)
  cin>>arr[i]>>d;
  
  int ans=1;
  dp[1]=1;
  FOR(i,2,n)
  {
  	dp[i]=1;
  	FOR(j,1,i-1)
  	if(arr[i]>=arr[j])
  		dp[i]=max(dp[i],dp[j]+1);

    ans=max(ans,dp[i]);
  }
  
  cout<<n-ans;

  return 0;
}