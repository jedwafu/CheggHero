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
const int N = 1e5+10; 

vector<pair<ll,ll> > arr;
int main(){
  fast;
  int n;
  cin>>n;
  arr.clear();
  for(int i=0;i<n;i++)
  {
  	ll l,r;
  	cin>>l>>r;
  	arr.pb(mp(l,r));
  }

  sort(arr.begin(),arr.end());

  ll ed1=arr[0].S;
  ll ed2=arr[1].S;

  for(int i=2;i<n;i++)
  {
  	if(min(ed1,ed2)>=arr[i].F)
  	{
  		cout<<"NO"<<endl;
  		return 0;
  	}

  	if(ed1<=ed2)
  	ed1=arr[i].S;
  	else
  	ed2=arr[i].S;
  }

  cout<<"YES"<<endl;
  return 0;
}