#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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
const int N = 1e7+10; 

ll sp[N];
map<ll,ll> last_seen;
bool done[N]={false};
vector<vi> prime_fac(100010);
void sieve()
{
  for(ll i=2;i<=N;i+=2)
  	sp[i]=2;

  ll lim=sqrt(N);
  for(ll i=3;i<=N;i+=2)
  {
  	if(!done[i])
  	{
  	   sp[i]=i;
  	

  	if(i<=lim)
  	for(ll j=i;(j*i)<=N;j+=2)
  	{
  		if(!done[j*i])
  		{
  			done[j*i]=true;
  			sp[j*i]=i;
  		}
  	}

  	}	
  }
}

ll arr[100010];
ll best[100010];


int main(){
  fast;
  int t;
  cin>>t;
  sieve();

  while(t--)
  {
  	ll n;
  	cin>>n;
  	last_seen.clear();
  	
  	for(ll i=1;i<=n;i++)
  		{
  			cin>>arr[i];
  		}

    for(ll i=1;i<=n;i++)
    {
    	prime_fac[i].clear();
       while(arr[i]>1)
       {
       	prime_fac[i].pb(sp[arr[i]]);
       	arr[i]/=sp[arr[i]];
       }
    }
    
    for(ll i=0;i<prime_fac[1].size();i++)
    	last_seen[prime_fac[1][i]]=1;
    
    best[1]=1;

    for (ll i = 2; i<=n; i++)
    {
    	best[i]=1;
         
         for(ll j=0;j<prime_fac[i].size();j++)
         {
             if(1+best[last_seen[prime_fac[i][j]]]>best[i])
              best[i]=1+best[last_seen[prime_fac[i][j]]];
         }
          
         for(ll j=0;j<prime_fac[i].size();j++)
         {
             last_seen[prime_fac[i][j]]=i;
         }   	
    }
    

    ll maxi=1;   
    for(ll i=1;i<=n;i++)
        maxi=max(maxi,best[i]);
    
    cout<<maxi<<endl;
  }
  return 0;
}