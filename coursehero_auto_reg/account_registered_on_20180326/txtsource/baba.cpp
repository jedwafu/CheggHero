#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (ll)x.size()
#define all(x) x.begin(),x.end() 
#define F first
#define S second
#define FOR(i,a,b) for(ll i = a; i<=b; ++i)
#define NFOR(i,a,b) for(ll i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const ll N = 1e5+10; 

int main(){
  fast;
  ll n,q,s;cin >> n >> q >> s;
  ll Q[109],C[109],D[109],cur[109][109];
  fill(cur,0);
  for(ll i=1;i<=s;i++) cin>>Q[i];
  for(ll i=1;i<=q;i++) cin>>C[i];
  for(ll i=1;i<=n;i++){
  	cin>>D[i];
    
    for(ll j=1;j<=s;j++)
      cur[Q[j]][i]=cur[Q[j]][i-1];

  	for(ll j=1;j<=s;j++){
  		ll temp;
  		cin>>temp;
  		cur[Q[j]][i]+=temp;  
  	}
  }
  
  for(ll i=1;i<=n;i++){
  	for(ll m=1;m<=q;m++){
  		if(cur[m][i]>C[m]){
  			cout<<"impossible";
  			return 0;
  		}
  	}
  	for(ll j=i+1;j<=n;j++){
  		for(ll k=1;k<=q;k++){
  			if(cur[k][j]>C[k]&&cur[k][i]>0&&D[i]>0){
  				ll temp = min({cur[k][j]-C[k],cur[k][i],D[i],C[k]});
  				D[i]-=temp;
  				for(ll l=i;l<=n;l++)
  					cur[k][l]-=temp;
  			}
  		}
  	}

  	for(ll k=1;k<=q;k++){
  			if(cur[k][i]>0&&D[i]>0){
  				ll temp = min({cur[k][i],D[i],C[k]});
  				D[i]-=temp;
  				for(ll l=i;l<=n;l++)
  					cur[k][l]-=temp;
  			}
  		}

  }


  for(ll i=1;i<=q;i++)
  	if(cur[i][n]>0){
  		cout<<"impossible";
  			return 0;
  	}


  cout<<"possible";
  return 0;
}