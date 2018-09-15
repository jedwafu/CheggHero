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
const int N = 1e6+10; 

string s;
ll pows[N];
int val[N];
int main(){
  fast;
  cin>>s;
  pows[0]=1;
  FOR(i,1,N-1)
  {
  	pows[i]=(2*pows[i-1])%mod;
  	if(pows[i]<0)
  		pows[i]+=mod;
  }

  if(s[0]=='a')
  	val[0]=1;
  else
  	val[0]=0;
  	
  FOR(i,1,sz(s)-1)
  {
  	val[i]=val[i-1];
  	if(s[i]=='a')
  		val[i]++;
  }
  ll ans=0;
  FOR(i,0,sz(s)-1)
  {
  	if(s[i]=='b')
  	{
  		ans=(ans+pows[val[i]]-1)%mod;
  		if(ans<0)
  			ans+=mod;
  	}
  }
  cout<<ans;
  return 0;
}