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

ll S1=0;
ll S2=0;
int n,k;
vi edges[N];
ll rem[6][N];
ll temp[6];

ll dfs(int source,int par)
{
	if(sz(edges[source])==1 and par!=0)
	{
		S1+=n-1;
		return 1;
	}

	ll siz=1;
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;
		siz+=dfs(edges[source][i],source);
	}
	S1+=siz*(n-siz);
	return siz;
}

void dfs2(int source,int par)
{
	if(sz(edges[source])==1 and par!=0)
	return;
	
	
	bool flag=false;	
	FOR(i,0,sz(edges[source])-1)
	{
		if(edges[source][i]==par)
			continue;
		
		dfs2(edges[source][i],source);
		rem[0][edges[source][i]]++;

		if(flag)
		{
			FOR(j,0,k-1)
			temp[j]=0;

			FOR(j1,0,k-1)
			{
				FOR(j2,0,k-1)
				{
					temp[(j1+j2+1)%k]+=rem[j1][source]*rem[j2][edges[source][i]];
					//cout<<source<<" "<<temp[0]<<" "<<temp[1]<<endl;
				}
			}

			FOR(j,1,k-1)
			S2+=(k-j)*temp[j];
		}

		//cout<<source<<" "<<rem[0][source]<<" "<<rem[1][source]<<endl;
		FOR(j,0,k-1)
		rem[(j+1)%k][source]+=rem[j][edges[source][i]];
		
		//cout<<source<<" "<<rem[0][source]<<" "<<rem[1][source]<<endl;
		flag=true;
	}

	FOR(j,1,k-1)
	{
		//cout<<"remainder "<<j<<" from "<<source<<" is "<<rem[j][source]<<endl;
		S2+=((k-j)*rem[j][source]);
	}

	return;
}

int main(){
  fast;
  cin>>n>>k;
  
  fill(rem,0);
  
  FOR(i,1,n-1)
  {
  	int a,b;
  	cin>>a>>b;
  	edges[a].pb(b);
  	edges[b].pb(a);
  }

  ll dummy=dfs(1,0);
  dfs2(1,0);

  cout<<(S1+S2)/k;
  return 0;
}