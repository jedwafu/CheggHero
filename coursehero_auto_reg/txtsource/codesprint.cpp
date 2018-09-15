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
  int g;
  cin>>g;
  FOR(i,1,g)
  {
    ll n,m,s;
    cin>>n>>m>>s;
    ll nc2=((n-1)*(n-2))/2;
    if(m<=nc2+1)
    cout<<s+(m-n+1)<<endl;
    else
    {
      if(nc2-((n-2)*(m-nc2))>=0)
      {
        ll ans=nc2;
        ans+=(s-(n-2))*(m-nc2);
        cout<<ans<<endl;
      }
      else
      {
        ll l=1;
        ll r=s;
        while((r-l)>1)
        {
          ll mid=(l+r)/2;
          if(s-mid*(n-2)>0)
            l=mid;
          else
            r=mid;
        }

        if(s-r*(n-2)>0)
        {
          ll ans=r*nc2;
          ans+=(s-r*(n-2))*(m-nc2);
          cout<<ans<<endl; 
        }
        else
        {

          ll ans=l*nc2;
          ans+=(s-l*(n-2))*(m-nc2);
          cout<<ans<<endl; 
        }
      }
    }
  }
  return 0;
}