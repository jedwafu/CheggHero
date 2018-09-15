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

vi edges[N];
double prob[N];
void Prob(int s,int p)
{	
	if(p==0)
		prob[s]=1;

	else
	{
		double cnt=sz(edges[p]);
		if(p!=1)
		cnt--;

		prob[s]=prob[p]*(1/cnt);
	}
	
	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i]==p)
			continue;

		Prob(edges[s][i],s);
	}
}

double ans=0;

void dfs(int s,int p,int d)
{
	if(sz(edges[s])==1 and s!=1)
	{
		ans+=(d*prob[s]);
		return;
	}

	FOR(i,0,sz(edges[s])-1)
	{
		if(edges[s][i]==p)
			continue;

		dfs(edges[s][i],s,d+1);
	}
}

int main(){
  fast;
  int n;
  cin>>n;
  
  cout<<setprecision(12);
  cout<<fixed;
  if(n==1)
  {
  	cout<<0;
  	return 0;
  }

  FOR(i,1,n-1)
  {
  	int a,b;
  	cin>>a>>b;
  	edges[a].pb(b);
  	edges[b].pb(a);
  }


  Prob(1,0);
  dfs(1,0,0);

  cout<<ans;
  return 0;
}