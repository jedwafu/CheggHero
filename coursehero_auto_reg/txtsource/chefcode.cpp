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
const int N = 50; 

ll arr[N];
ll dp[N][500010];
unordered_map <ll,int> val;
int cnt=0;


ll DP(int index,ll v)
{
	if(v<=arr[index])
		return 0;

	if(index==1)
		return (v>arr[1]);

	if(!val.count(v))
		val[v]=cnt++;

	int r=val[v];

	if(dp[index][r]!=-1)
		return dp[index][r];

	dp[index][r]=0;

	ll check=v/arr[index];
	if(check*arr[index]<v)
		check++;
	
	FOR(i,1,index-1)
	dp[index][r]+=DP(i,check);
	

	if(arr[index]<v)
		dp[index][r]++;

	return dp[index][r];
}

int main(){
  fast;
  int n;
  ll k;
  cin>>n>>k;
  val.clear();
  
  fill(dp,-1);

  FOR(i,1,n)
  cin>>arr[i];

  sort(arr+1,arr+n+1);

  ll ans=0;
  FOR(i,1,n)
  ans+=DP(i,k);

  cout<<ans<<endl;
 
  return 0;
}