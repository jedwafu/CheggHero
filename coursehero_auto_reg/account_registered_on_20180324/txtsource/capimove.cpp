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
const int N = 5e4+10; 

vector<ii> arr;
vi edge[N];
int ans[N];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n;
  	cin>>n;
  	arr.clear();
  	arr.pb(mp(0,0));
  	FOR(i,1,n)
  	{
  		ll temp;
  		cin>>temp;
  		arr.pb(mp(temp,i));
  		edge[i].clear();
  	}
    
    FOR(i,1,n-1)
    {
    	int u,v;
    	cin>>u>>v;
    	edge[u].pb(arr[v].F);
    	edge[v].pb(arr[u].F);
    }
    
    
    FOR(i,1,n)
    {
    	edge[i].pb(arr[i].F);
    	sort(edge[i].begin(),edge[i].end());
    }

    sort(arr.begin(),arr.end()); 
    
    
    FOR(i,1,n)
    {
    	int index=n;
    	ans[i]=index;
    	NFOR(j,sz(edge[i])-1,0)
    	{
    		if(edge[i][j]==arr[ans[i]].F)
    		{
    			index--;
    			ans[i]=index;
    		}
    		else
    			break;
    	}
    }

    FOR(i,1,n)
    cout<<arr[ans[i]].S<<" ";
    cout<<endl;
  }
  return 0;
}