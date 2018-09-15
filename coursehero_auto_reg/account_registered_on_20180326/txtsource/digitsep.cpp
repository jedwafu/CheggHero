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

ll arr[310][20];
set<ll> G[310][310];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,m,x,y;
  	string s;
  	cin>>n;
  	cin>>s;
  	cin>>m>>x>>y;

  	FOR(i,0,n-1)
  	FOR(j,0,y)
  	G[i][j].clear();

    bool flag=true;
    FOR(i,0,n-1)
    {
    	if(s[i]!='0')
    		flag=false;
    }

    if(flag)
    {
    	cout<<0<<endl;
    	continue;
    }

  	FOR(i,0,n-1)
  	arr[i][1]=s[i]-'0';

  	FOR(i,0,n-1)
  	{
  		ll cur=arr[i][1];
  		FOR(j,2,min(m,n-i))
  		{
  			cur*=10;
  			cur+=s[i+j-1]-'0';
  			arr[i][j]=cur;
  		}
  	}
    
    G[0][0].insert(arr[0][1]);
    FOR(i,1,n-1)
    {
    	
    	if(i<m)
    		G[i][0].insert(arr[0][i+1]);

    	FOR(j,1,min(i,y))
    	{	
    		int maxi=max(i-m,j-1);
    		maxi=max(maxi,0);
    		
    		NFOR(k,i-1,maxi)
    		{
    			std::set<ll>::iterator it;
				for (it = G[k][j-1].begin(); it != G[k][j-1].end(); ++it)
				{
    				G[i][j].insert(__gcd(*it,arr[k+1][i-k]));
				}
    		}
    	}
    }    

    ll ans=1;
  	FOR(i,x,y)
  	{
  		if(!G[n-1][i].empty())
  			ans=max(ans,*G[n-1][i].rbegin());
  	}

  	cout<<ans<<endl;
  }
  return 0;
}