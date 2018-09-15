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
const int N = 1e3+10; 

int arr[N][N];
int n,m;
int cnt[2];
void dfs(int i,int j,int c)
{
  if(i>n or i<1 or j>m or j<1)
  return;
  
  if(arr[i][j]!=-1)
  return;
  
  //cout<<"called "<<i<<" "<<j<<endl;
  arr[i][j]=c;
  cnt[c]++;

  dfs(i+2,j-1,1-c);
  dfs(i+2,j+1,1-c);
  dfs(i-2,j-1,1-c);
  dfs(i-2,j+1,1-c);
  dfs(i+1,j+2,1-c);
  dfs(i+1,j-2,1-c);
  dfs(i-1,j+2,1-c);
  dfs(i-1,j-2,1-c);

}

int main(){
  fast;
  fill(arr,-1);
  
  int ans=0;
  cin>>n>>m;
  FOR(i,1,n)
  FOR(j,1,m)
  if(arr[i][j]==-1)
  {
  	cnt[0]=cnt[1]=0;
  	dfs(i,j,0);
  	ans+=max(cnt[0],cnt[1]);
  }
  cout<<ans;
  return 0;
}