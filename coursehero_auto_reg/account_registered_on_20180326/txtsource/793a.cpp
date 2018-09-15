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
int main(){
  fast;
  int n;
  ll k;
  cin>>n>>k;
  ll mini=mod;
  FOR(i,1,n)
  {
  	cin>>arr[i];
  	mini=min(mini,arr[i]);
  }
  ll ans=0;
  FOR(i,1,n)
  {
  	if((arr[i]-mini)%k==0)
  	{
  		ans+=(arr[i]-mini)/k;
  	}
  	else
  	{
  		cout<<-1;
  		return 0;
  	}
  }

  cout<<ans<<endl;
  return 0;
}	