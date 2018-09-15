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

vector<ll> arr;
int main(){
  fast;
  ll n;
  cin>>n;

  if(n==1000000000)
  {
  	cout<<1000000000;
  	return 0;
  }

  ll temp=1;
  FOR(i,0,8)
  {
  	FOR(j,1,9)
  	{
  		arr.pb(j*temp);
  	}
  	temp*=10;
  }
  arr.pb(1000000000);

  FOR(i,1,sz(arr)-1)
  {
  	if(n>=arr[i-1] and n<arr[i])
  	{
  		cout<<arr[i]-n;
  		return 0;
  	}
  }

  return 0;
}