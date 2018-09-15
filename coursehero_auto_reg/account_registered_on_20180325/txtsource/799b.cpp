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

vector< pair<ll, ii> > p(N);
vi c[5];
int cur[5];
int fav[N];
bool done[N];

int main(){
  fast;
  int n;
  cin>>n;
  fill(cur,0);
  fill(done,0);
  FOR(i,1,n)
  cin>>p[i].F;
  FOR(i,1,n)
  cin>>p[i].S.F;
  FOR(i,1,n)
  cin>>p[i].S.S;

  sort(p.begin()+1,p.begin()+n+1);

  FOR(i,1,n)
  {
  	FOR(j,1,3)
  	{	
  		if(p[i].S.F==j or p[i].S.S==j)
  		{
  			c[j].pb(i);
  		}
  	}
  }

  int m;
  cin>>m;
  FOR(i,1,m)
  cin>>fav[i];
  
  FOR(i,1,m)
  {
  	while(cur[fav[i]]<sz(c[fav[i]]) and done[c[fav[i]][cur[fav[i]]]])
  	{
  		cur[fav[i]]++;
  	}
  	if(cur[fav[i]]==sz(c[fav[i]]))
  	cout<<-1<<" ";
  	else
  	{
  		cout<<p[c[fav[i]][cur[fav[i]]]].F<<" ";
  		done[c[fav[i]][cur[fav[i]]]]=true;
  		cur[fav[i]]++;
  	}
  }

  return 0;
}