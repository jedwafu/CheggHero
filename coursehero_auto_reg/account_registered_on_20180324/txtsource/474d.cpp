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

ll mods(ll a,ll b)
{
	return (a%b + b)%b;
}

int dp[100010];
ll sums[100010];
int main(){
  fast;
  int t,k;
  cin>>t>>k;
  dp[0]=0;
  dp[1]=1+(k==1);
  sums[0]=0;
  sums[1]=1+(k==1);

  for(int i=2;i<=100010;i++)
  dp[i]=mods(mods(dp[i-1],mod) + mods(dp[(i-k>0)?(i-k):0],mod) + (k==i),mod);
  for(int i=2;i<=100010;i++)
  sums[i]=mods(mods(sums[i-1],mod)+mods(dp[i],mod),mod);

  for(int i=0;i<t;i++)
  {
  	int a,b;
  	cin>>a>>b;
  	cout<<mods(mods(sums[b],mod)-mods(sums[a-1],mod),mod)<<endl;
  }

  return 0;
}