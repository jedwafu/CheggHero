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

vector<int>arr;
void populate(ll a)
{
	arr.clear();
	while(a>1)
	{
		arr.pb(a%2);
		a/=2;
	}
}

ll calc()
{
	ll ans=0;
	if(arr[0]==0)
		ans++;
	FOR(i,1,sz(arr)-1)
	{
		if(arr[i]==0)
		{
			ans+=(1<<i);
		}
	}
	return ans;
}

int main(){
  fast;
  int q;
  cin>>q;
  FOR(i,1,q)
  {
  	ll x;
  	cin>>x;
  	if(x==1)
  		cout<<0<<endl;
  	else
  	{
  		populate(x);
  		cout<<calc()<<endl;
  	}
  }

  
  return 0;
}