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

ll arr[1010][1010];
ll dp1[1010][1010];
ll dp2[1010][1010];
ll dp3[1010][1010];
ll dp4[1010][1010];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,m;
  	cin>>n>>m;

  	for(int i=0;i<n;i++)
  		for(int j=0;j<m;j++)
  			{
  				cin>>arr[i][j];
  				dp1[i][j]=dp2[i][j]=dp3[i][j]=dp4[i][j]=arr[i][j];
  			}

    for(int i=n-2;i>=0;i--)
    	for(int j=0;j<m;j++)
    	{
    		dp1[i][j]=min(dp1[i][j],dp1[i+1][j]+arr[i][j]);
    	}

    for(int i=1;i<n;i++)
    	for(int j=0;j<m;j++)
    	{
    		dp2[i][j]=min(dp2[i][j],dp2[i-1][j]+arr[i][j]);
    	}
    
    for(int i=0;i<n;i++)
    	for(int j=1;j<m;j++)
    	{
    		dp3[i][j]=min(dp3[i][j],dp3[i][j-1]+arr[i][j]);
    	}

    for(int i=0;i<n;i++)
    	for(int j=m-2;j>=0;j--)
    	{
    		dp4[i][j]=min(dp4[i][j],dp4[i][j+1]+arr[i][j]);
    	}
    ll ans=INF;
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
          ans=min(ans,dp1[i][j]+dp2[i][j]+dp3[i][j]+dp4[i][j]-3*arr[i][j]);

     cout<<ans<<endl; 
 
  }
  return 0;
}