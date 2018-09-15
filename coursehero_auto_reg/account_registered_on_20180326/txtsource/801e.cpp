#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 2e5+10; 

bool allowed[N];
vector<ii> val;
int dp[N];
int where[N];
int last[N];
vector<ll> ans;

int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a / b;
		int t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}

int mod_inverse(int a, int n) {
	int x, y;
	int g = extended_euclid(a, n, x, y);
	if (g > 1) return -1;
	int ret=x%n;
	if(ret<0)
		ret+=n;
	return ret;
}

int main(){
  fast;
  int n,m;
  cin>>n>>m;

  fill(last,-1);
  
  FOR(i,0,m-1)
  allowed[i]=true;

  FOR(i,1,n)
  {
  	int temp;
  	cin>>temp;
  	allowed[temp]=false;
  }

  FOR(i,1,m-1)
  {
  	if(allowed[i])
  	{
  		int g=__gcd(i,m);
  		val.pb(mp(g,i));
  	}
  }

  fill(dp,-1);

  sort(val.begin(),val.end());
 
  if(allowed[0])
  val.pb(mp(m,0));

  dp[0]=1;
  where[0]=0;
  last[val[0].F]=0;

  FOR(i,1,sz(val)-1)
  {
  	dp[i]=1;
  	where[i]=i;
  	//cout<<"here at value "<<val[i].S<<endl;
  	//last[val[i].F]=i;

  	int root=sqrt(val[i].F);
  	FOR(j,1,root)
  	{
  		if((val[i].F)%j==0)
  		{

  			if(dp[last[j]]!=-1 and dp[last[j]]+1>dp[i])
  			{
  				dp[i]=dp[last[j]]+1;
  				where[i]=last[j];
  			}	

  			int k=(val[i].F)/j;
  			if(k!=j)
  			if(dp[last[k]]!=-1 and dp[last[k]]+1>dp[i])
  			{
  				dp[i]=dp[last[k]]+1;
  				where[i]=last[k];
  			}	
  		}
  	}
  	last[val[i].F]=i;
  }

  int maxval=0;
  int maxidx=0;
  FOR(i,0,sz(val)-1)
  {
  	if(dp[i]>maxval)
  	{
  		maxval=dp[i];
  		maxidx=i;
	}
  }

  ll md=m;
  while(where[maxidx]!=maxidx)
  {
  	ll x=val[maxidx].S;
  	ll y=val[where[maxidx]].S;
 
  	ll g=__gcd(y,md);
  	x/=g;
  	y/=g;
  	ll temp=mod_inverse(y,md/g)*x;
  	temp%=md;
  	if(temp<0)
  		temp+=md;
  	ans.pb(temp);
  	maxidx=where[maxidx];
  }

  ans.pb(val[maxidx].S);

  reverse(ans.begin(),ans.end());
  cout<<sz(ans)<<endl;
  FOR(i,0,sz(ans)-1)
  cout<<ans[i]<<" ";
  return 0;
}