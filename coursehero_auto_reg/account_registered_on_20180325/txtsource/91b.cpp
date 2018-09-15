#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> ii;

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

vector<ii> arr; 
ll ans[N];
bool marked[N];
int r;
int main(){
  fast;
  int n;
  cin>>n;
  r=n;
  fill(ans,-1);
  fill(marked,0);
  FOR(i,1,n)
  {
  	ll temp;
  	cin>>temp;
    arr.pb(mp(temp,i));
  }
  
  sort(arr.begin(),arr.end());
  reverse(arr.begin(),arr.end());
  
  FOR(i,0,sz(arr)-1)
  {
  	if(r>arr[i].S)
  	{
  		//cout<<arr[i].F<<" "<<arr[i].S<<" "<<r<<endl;
  		ans[arr[i].S]=r-arr[i].S-1;
  	}
  	marked[arr[i].S]=true;
    while(marked[r])
    r--;
  }

  FOR(i,1,n)
  cout<<ans[i]<<" ";
  return 0;
}