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
const int N = 5e5+10; 

int arr[N];
int nex[N];
int indeg[N];
int assign[N];
int cur=1;
int last;
void dfs(int source,int d)
{
	
	if(nex[source]!=-1)
	{
		assign[source]=d;
		cur++;
		dfs(nex[source],d+1);
	}
	else
	{
		assign[source]=last;
		last--;
	}
}

int main(){
  fast;
  int n;
  cin>>n;
  last=n;

  fill(nex,-1);
  fill(indeg,0);
  fill(assign,0);

  FOR(i,1,n)
  {
  	cin>>arr[i];
  	nex[i]=arr[i];
  	if(arr[i]+1)
  	indeg[arr[i]]++;
  }

  FOR(i,1,n)
  {
  	if(indeg[i]==0)
  	dfs(i,cur);
  }


  FOR(i,1,n)
  cout<<assign[i]<<" ";
  return 0;
}