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

int n;
char arr[55][55];
bool vis[55][55];
bool bear[3];
int cnt=0;
void dfs(int x,int y)
{
	vis[x][y]=true;
	cnt++;

	if(bear[1] or (bear[0] and bear[2]))
		return;

	FOR(i,-1,1)
	FOR(j,-1,1)
	{
		if(abs(i)+abs(j)!=1)
			continue;
		if(x+i>0 and x+i<=n and y+j>0 and y+j<=n and arr[x+i][y+j]=='P')
			bear[0]=true;
		if(x+i>0 and x+i<=n and y+j>0 and y+j<=n and arr[x+i][y+j]=='G')
			{
				bear[1]=true;
				return;
			}
		if(x+i>0 and x+i<=n and y+j>0 and y+j<=n and arr[x+i][y+j]=='B')
			bear[2]=true;
	}


	if(bear[0] and bear[2])
		return;

	FOR(i,-1,1)
	FOR(j,-1,1)
	{
		if(abs(i)+abs(j)!=1)
			continue;
		if(x+i>0 and x+i<=n and y+j>0 and y+j<=n and arr[x+i][y+j]=='?' and vis[x+i][y+j]==false)
			dfs(x+i,y+j);
	}
	
}

int main(){
  fast;
  int t;
  cin>>t;
  FOR(i,1,t)
  {
  	cin>>n;
  	fill(vis,0);

  	FOR(i,1,n)
  	FOR(j,1,n)
  	cin>>arr[i][j];

  	ll ans=1;
  	FOR(i,1,n)
  	FOR(j,1,n)
  	{
  		if(arr[i][j]=='?' and vis[i][j]==false)
  		{
  			cnt=0;
  			bear[0]=bear[1]=bear[2]=false;
  			dfs(i,j);
 			
 			if(bear[1] or (bear[0] and bear[2]))
 			ans=0;

 			if(bear[0]==false and bear[2]==false)
 			{
 				if(cnt==1)
 					ans=(ans*3)%mod;
 				else
 					ans=(ans*2)%mod;
 			}
  		}
  	}

  	FOR(x,1,n)
  	FOR(y,1,n)
  	{
  		if(arr[x][y]=='G')
  		{
  			FOR(i,-1,1)
			FOR(j,-1,1)
			{
				if(abs(i)+abs(j)!=1)
				continue;
				if(x+i>0 and x+i<=n and y+j>0 and y+j<=n and (arr[x+i][y+j]=='P' or arr[x+i][y+j]=='B' or arr[x+i][y+j]=='G') )
				ans=0;
			}	
  		}
  		if(arr[x][y]=='P')
  		{
  			FOR(i,-1,1)
			FOR(j,-1,1)
			{
				if(abs(i)+abs(j)!=1)
				continue;
				if(x+i>0 and x+i<=n and y+j>0 and y+j<=n and (arr[x+i][y+j]=='B' or arr[x+i][y+j]=='G') )
				ans=0;
			}	
  		}
  		if(arr[x][y]=='B')
  		{
  			FOR(i,-1,1)
			FOR(j,-1,1)
			{
				if(abs(i)+abs(j)!=1)
				continue;
				if(x+i>0 and x+i<=n and y+j>0 and y+j<=n and (arr[x+i][y+j]=='P' or arr[x+i][y+j]=='G') )
				ans=0;
			}	
  		}	
  	}
  	cout<<ans<<endl;
  }
  return 0;
}