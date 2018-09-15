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

ll DP(ll n,ll t,ll d,ll k,bool flag)
{
  if(t==0)
  {
    
  }
  
  if(flag)
  return (k-1)*DP(n-1,t,d,k,false)+DP(n-1,t-1,d,k,true)+(k-1)*DP(n-d,t-1,d,k,true);
  
  return k*DP(n-1,t,d,k,false)+(k-1)*DP(n-d,t-1,d,k,true);
}

int main(){
  fast;
  
  ll n,d,t,k;
  cin>>n>>d>>t>>k;

  

  return 0;
}