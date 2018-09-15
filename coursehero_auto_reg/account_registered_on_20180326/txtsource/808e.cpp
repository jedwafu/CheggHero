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

vector<ll> w[10];
int cur[10];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  FOR(i,1,3)
  {
  	w[i].pb(0);
  	cur[i]=0;
  }

  FOR(i,1,n)
  {
  	int wt;
  	ll c;
  	cin>>wt>>c;
  	w[wt].pb(c);
  }
  
  FOR(i,1,3)
  {
  	sort(w[i].begin(),w[i].end());
  	reverse(w[i].begin(),w[i].end());
  }

  ll ans=0;
  while(m>0)
  {
  	ll best1=0,best2=0,best3=0,best4=0,best5=0,best6=0;

		if(cur[3]<sz(w[3]) and m>=3)
		best1=w[3][cur[3]];

		if(cur[2]<sz(w[2]) and m>=2)
		best2=w[2][cur[2]];

		if(cur[2]<sz(w[2]) and cur[1]<sz(w[1]) and m>=3)
		best3=w[2][cur[2]]+w[1][cur[1]];

		if(cur[1]<sz(w[1]) and m>=1)
		best4=w[1][cur[1]];

		if(cur[1]+1<sz(w[1]) and m>=2)
		best5=w[1][cur[1]]+w[1][min(cur[1]+1,sz(w[1])-1)];
			
		if(cur[1]+2<sz(w[1]) and m>=3)
		best6=w[1][cur[1]]+w[1][min(cur[1]+1,sz(w[1])-1)]+w[1][min(cur[1]+2,sz(w[1])-1)];

		ll best=max(best1,max(best2,max(best3,max(best4,max(best5,best6)))));
		if(best==0)
			break;
		if(best==best1)
		{
			ans+=best1;
			m-=3;
			cur[3]++;
		}
		else if(best==best2)
		{
			ans+=best2;
			m-=2;
			cur[2]++;
		}
		else if(best==best3)
		{
			ans+=best3;
			m-=3;
			cur[2]++;
			cur[1]++;
		}
		else if(best==best4)
		{
			ans+=best4;
			m-=1;
			cur[1]++;
		}
		else if(best==best5)
		{
			ans+=best5;
			m-=2;
			cur[1]+=2;
		}
		else if(best==best6)
		{
			ans+=best6;
			m-=3;
			cur[1]+=3;
		}
  }

  cout<<ans;
  return 0;
}