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
const int N = 1e2+10; 

int vol[N];
ii a[N];
int ans[N];
int main(){
  fast;
  int n,w;
  cin>>n>>w;
  
  FOR(i,1,n)
  {
  	cin>>a[i].F;
  	a[i].S=i;
  }

  sort(a+1,a+n+1);
  reverse(a+1,a+n+1);

  int total=0;
  FOR(i,1,n)
  {
  	vol[i]=(a[i].F+1)/2;
  	total+=vol[i];
  }

  if(total>w)
  {
  	cout<<-1;
  	return 0;
  }

  int rem=w-total;
  FOR(i,1,n)
  {
	int temp=min(a[i].F-vol[i],rem);
	rem-=temp;
	vol[i]+=temp;  	

	ans[a[i].S]=vol[i];
  }

  FOR(i,1,n)
  cout<<ans[i]<<" ";
  
  return 0;
}