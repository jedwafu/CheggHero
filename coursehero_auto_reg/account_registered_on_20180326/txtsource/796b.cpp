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
const int N = 1e6+10; 

bool hole[N];
int main(){
  fast;
  int n,m,k;
  cin>>n>>m>>k;
  fill(hole,0);
  FOR(i,1,m)
  {
  	int t;
  	cin>>t;
  	hole[t]=true;
  }
  
  int ball=1;
  bool flag=true;
  FOR(i,1,k)
  {
  	int u,v;
  	cin>>u>>v;
  	if(!flag)
  		continue;
  	else
  	{
  		if(ball==u)
  		{
  			ball=v;
  			if(hole[v])
  				flag=false;
  		}
  		else if(ball==v)
  		{
  			ball=u;
  			if(hole[u])
  				flag=false;
  		}
  	}
  }

  if(hole[1]==true)
  	ball=1;
  cout<<ball<<endl;
  return 0;

}