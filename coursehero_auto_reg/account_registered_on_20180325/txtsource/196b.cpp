#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> PII;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1510; 

int n,m;
char arr[N][N];
ii vis[N][N];
bool flag=false;

int modulo(int x,int m)
{
  int ret=x%m;
  if(ret<0)
    ret+=m;
  return ret;
}

void dfs(int stx,int sty)
{

  if(vis[modulo(stx,n)][modulo(sty,m)].F!=mod and vis[modulo(stx,n)][modulo(sty,m)].S!=mod and (vis[modulo(stx,n)][modulo(sty,m)].F!=stx or vis[modulo(stx,n)][modulo(sty,m)].S!=sty))
  {
    //cout<<stx%n<<" "<<sty%m<<endl;
    flag=true;
    return;
  }

  else if(vis[modulo(stx,n)][modulo(sty,m)].F==stx and vis[modulo(stx,n)][modulo(sty,m)].S==sty)
  return;
  

  if(arr[modulo(stx,n)][modulo(sty,m)]=='#')
    return;

  //cout<<"called for "<<stx<<" "<<sty<<endl;

  vis[modulo(stx,n)][modulo(sty,m)]=mp(stx,sty);

  FOR(i,-1,1)
  FOR(j,-1,1)
  {
    if(abs(i-j)==1)
    {
      int dstx=(stx+i);
      int dsty=(sty+j);
      
      
      if(arr[modulo(dstx,n)][modulo(dsty,m)]=='#')
        continue;


      dfs(dstx,dsty);
      
      if(flag)
        return;
    }
  }
}

int main()
{
  fast;
  int stx,sty;


  cin>>n>>m;
  
  FOR(i,0,n-1)
  FOR(j,0,m-1)
  {
  	cin>>arr[i][j];
  	if(arr[i][j]=='S')
  	{
  		stx=i;
  		sty=j;
  	}
    vis[i][j].F=mod;
    vis[i][j].S=mod;
  }

  dfs(stx,sty);  

  if(flag)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;

  return 0;
}