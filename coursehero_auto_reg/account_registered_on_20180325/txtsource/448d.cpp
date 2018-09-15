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

ll n,m,k;
ll binarysearch(ll low,ll high)
{
	if(low>high)
		return 0;
	if(low==high)
	{
		ll total=0;
		for(int i=1;i<=n;i++)
		total+=min((low-1)/i,m);		
        
        if(total<k)
        	return low;
        else return 0;
	}
    //cout<<low<<" "<<high<<endl;
	ll mid=(low+high)/2;
	ll total=0;
	for(int i=1;i<=n;i++)
	total+=min((mid-1)/i,m);

	if(total<k)
		{
			ll temp=binarysearch(mid+1,high);
			if(temp==0)
				return mid;
			else return temp;
		}
	else
		return binarysearch(low,mid-1);
}

int main(){
  fast;
  cin>>n>>m>>k;
  ll ans= binarysearch(1,m*n);
  cout<<ans<<endl;
  return 0;
}