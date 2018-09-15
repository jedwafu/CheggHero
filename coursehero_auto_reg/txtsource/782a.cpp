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

int done[N];

int main()
{
  fast;
  int n,cur=0,ans=0;
  cin>>n;
  fill(done,0);

  FOR(i,1,2*n)
  {
  	int x;
  	cin>>x;
  	done[x]++;

  	if(done[x]==1)
  	cur++;
  	else
  	cur--;

  	ans=max(ans,cur);
  }

  cout<<ans;
  return 0;
}