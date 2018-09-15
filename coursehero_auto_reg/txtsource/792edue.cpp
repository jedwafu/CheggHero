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
const int N = 5e2+10; 

int n;
ll arr[N];
ll lim=0;
ll ans=INF;

ll check(ll siz)
{
	ll tans=0;
	FOR(i,1,n)
  	{
  		if(arr[i]%(siz+1)==0)
  			tans+=arr[i]/(siz+1);

  		else if((arr[i]/siz)>=(arr[i]%siz))
  		tans+=arr[i]/(siz+1)+1;
  		
  		else
 		{
  			tans=INF;
  			break;
  		}
  	}
  	return tans;
}

int main(){
  fast;
  cin>>n;
  
  FOR(i,1,n)
  {
  	cin>>arr[i];
  	lim=max(lim,(ll)sqrt(arr[i]));
  }

  FOR(i,1,lim)
  ans=min(ans,check(i));
  

  FOR(i,1,lim)
  {
  	 ll siz=arr[1]/i;
  	 ans=min(ans,check(siz));
  	 if(arr[1]%i==0 and siz>1)
  	 ans=min(ans,check(siz-1));
  }	

  cout<<ans<<endl;
  return 0;
}