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

int dp[55][5005];
int w[55];
int x[505],c[505];

int solve(int n,int cost)
{
  if(cost<0)
    return 0;
  
  if(dp[n][cost]+1)
    return dp[n][cost];

  if(!n)
    return 0;

  dp[n][cost]=max(solve(n-1,cost),solve(n-1,cost-w[n]));
  return dp[n][cost];
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;    
    cin>>n;
    FOR(i,1,n)
    cin>>w[i];
    
    cin>>k;

    FOR(i,1,k)
    cin>>x[i];
    FOR(i,1,k)
    cin>>c[i];

    fill(dp,-1);

    FOR(i,0,n)
    dp[i][0]=1;
    


    FOR(i,1,k)
    {
      if(solve(n,c[i])) 
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    }

  }
  return 0;
} 