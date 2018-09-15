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
const int N = 1e3+10; 

priority_queue<ll> rows;
priority_queue<ll> cols;
ll arr[N][N];
ll r[1000010];
ll c[1000010];
int main(){
  fast;
  ll n,m,k,p;
  cin>>n>>m>>k>>p;
  FOR(i,1,n)
  FOR(j,1,m)
  cin>>arr[i][j];

  FOR(i,1,n)
  {
  	ll sum=0;
  	FOR(j,1,m)
  	sum+=arr[i][j];

  	rows.push(sum);
  }
  
  FOR(j,1,m)
  {
  	ll sum=0;
  	FOR(i,1,n)
  	sum+=arr[i][j];

  	cols.push(sum);
  }
   
  r[0]=0;
  c[0]=0;
  FOR(i,1,k)
  {
  	ll temp=rows.top();
  	r[i]=r[i-1]+temp;

  	rows.pop();
  	rows.push(temp-m*p);

  	temp=cols.top();
  	c[i]=c[i-1]+temp;
  	//cout<<i<<" "<<c[i]<<endl;
  	cols.pop();
  	cols.push(temp-n*p);
  }
  
  ll ans=-INF;
  FOR(i,0,k)
  {
    ans=max(ans,r[i]+c[k-i]-((k-i)*i*p));
  }
  cout<<ans;
  return 0;
}