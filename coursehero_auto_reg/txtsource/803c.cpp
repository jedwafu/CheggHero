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

int main(){
  fast;
  ll n;
  double k;
  cin>>n>>k;

  double lim=(k*(k+1))/2;

  int root=sqrt(n);
  ll ans=INF;
  FOR(i,1,root)
  {
  	if(n%i==0 and i>=lim)
  	{
  		ans=i;
  		break;
  	}
  	if(n%i==0 and n/i>=lim)
  	{
  		ans=min(ans,n/i);
  	}
  }
  ll K=k;
  if(ans!=INF)
  {
  	ll sums=0;
  	FOR(i,1,k-1)
  	{
 		cout<<(n/ans)*i<<" ";
 		sums+=(n/ans)*i; 		
  	}	
  	cout<<n-sums;
  }
  else
  	cout<<-1;
  return 0;
}
