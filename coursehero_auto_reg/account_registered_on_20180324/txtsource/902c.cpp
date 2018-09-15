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

int par1[N];
int lvl[N];
int par2[N];
int cnt=1;
int level=-1;
int h;

void dfs1(int p,int l)
{
	par1[cnt]=p;
	int s=cnt;
	cnt++;

	if(!lvl[l] and l<h)
	{
		lvl[l]=1;
		FOR(i,1,a[l+1])
		dfs1(s,l+1);
	}
}

void dfs2(int p,int l)
{
	par2[cnt]=p;
	int s=cnt;
	cnt++;

	if(l==level and !lvl[l])
	{
		lvl[l]=1;
		FOR(i,1,a[l+1]-1)
		dfs2(s,l+1);
	}

	else if(l==level and lvl[l]==1)
	{
		lvl[l]=2;
		dfs2(s,l+1);
	}

	else if(!lvl[l] and l<h)
	{
		lvl[l]=1;
		FOR(i,1,a[l+1])
		dfs2(s,l+1);
	}
}
int main(){
  fast;
  
  cin>>h;
  for(int i=0;i<=h;i++)
  	cin>>a[i];

  
  for(int i=h;i>0;i--)
  {
  	if(a[i]!=1 and a[i-1]!=1)
  	{
  		level=i-1;
  		break;
  	}
  }

  if(level==-1)
  {
  	cout<<"perfect"<<endl;
  	return 0;
  }

  FOR(i,0,h)
  lvl[i]=0;

  cnt=1;
  dfs1(0,0);

  FOR(i,0,h)
  lvl[i]=0;
  
  cnt=1;
  dfs2(0,0);

  int tot=0;
  FOR(i,0,h)
  tot+=a[i];

  cout<<"ambiguous"<<endl;
  FOR(i,1,tot)
  cout<<par1[i]<<" ";
  cout<<endl;

  FOR(i,1,tot)
  cout<<par2[i]<<" ";
  cout<<endl;

  return 0;
}