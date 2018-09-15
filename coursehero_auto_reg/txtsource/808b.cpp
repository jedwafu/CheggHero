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
const int N = 2e5+10; 

int a[N];
int main(){
  fast;
  int n,k;
  cin>>n>>k;
  cout<<setprecision(12);
  cout<<fixed;
  double total=0;
  ll prev=0;

  FOR(i,1,n)
  cin>>a[i];

  FOR(i,1,k)
  total+=a[i];

  prev=total;
  FOR(i,k+1,n)
  {
  	prev=prev-a[i-k]+a[i];
  	total+=prev;
  }

  cout<<total/(n-k+1);
  return 0;
}