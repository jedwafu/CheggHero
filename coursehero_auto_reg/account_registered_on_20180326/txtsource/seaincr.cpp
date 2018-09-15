//code for LIS taken from stanford university's acm notebook available online.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int,int> ii;

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

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define STRICTLY_INCREASNG

VI LongestIncreasingSubsequence(VI v) {
  VPII best;
  VI dad(v.size(), -1);
  
  for (int i = 0; i < v.size(); i++) {
#ifdef STRICTLY_INCREASNG
    PII item = make_pair(v[i], 0);
    VPII::iterator it = lower_bound(best.begin(), best.end(), item);
    item.second = i;
#else
    PII item = make_pair(v[i], i);
    VPII::iterator it = upper_bound(best.begin(), best.end(), item);
#endif
    if (it == best.end()) {
      dad[i] = (best.size() == 0 ? -1 : best.back().second);
      best.push_back(item);
    } else {
      dad[i] = dad[it->second];
      *it = item;
    }
  }
  
  VI ret;
  for (int i = best.back().second; i >= 0; i = dad[i])
    ret.push_back(v[i]);
  reverse(ret.begin(), ret.end());
  return ret;
}


int arr[1000010];
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int m,n;
  	cin>>n>>m;

  	for(int i=1;i<=n;i++)
  		cin>>arr[i];

  	for(int i=0;i<m;i++)
  	{
  		int l,r;
  		cin>>l>>r;
  		vector<int> v1(arr + l, arr + r+1);
  		vector<int> v2=LongestIncreasingSubsequence(v1);
  		cout<<v2.size()<<endl;
  	}
  	
  }
  return 0;
}