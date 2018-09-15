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

char arr[N][N];
int stx,sty,edx,edy;
bool reach[5][N];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  fill(reach,0);
  FOR(i,1,n)
  FOR(j,1,m)
  {
  	cin>>arr[i][j];
  	if(arr[i][j]=='S')
  	{
  		stx=i;
  		sty=j;
  	}
  	if(arr[i][j]=='T')
  	{
  		edx=i;
  		edy=j;
  	}
  }


  NFOR(i,edy,1)
  {
  	if(arr[edx][i]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[1][i]=true;
  	}
  }
  FOR(i,edy,n)
  {
  	if(arr[edx][i]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[1][i]=true;
  	}	
  }

  NFOR(i,sty,1)
  {
  	if(arr[stx][i]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[2][i]=true;
  	}
  }
  FOR(i,sty,n)
  {
  	if(arr[stx][i]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[2][i]=true;
  	}	
  }

  NFOR(i,edx,1)
  {
  	if(arr[i][edy]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[3][i]=true;
  	}
  }
  FOR(i,edx,n)
  {
  	if(arr[i][edy]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[3][i]=true;
  	}	
  }

  NFOR(i,stx,1)
  {
  	if(arr[i][sty]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[4][i]=true;
  	}
  }
  FOR(i,stx,n)
  {
  	if(arr[i][sty]=='*')
  	{
  		break;
  	}
  	else
  	{
  		reach[4][i]=true;
  	}	
  }

  FOR(i,1,n)
  {
  	if(reach[3][i] and reach[4][i])
  	{
  		bool flag=true;
  		FOR(j,min(sty,edy),max(sty,edy))
  		{
  			if(arr[i][j]=='*')
  			{
  				flag=false;
  			}
  		}
  		if(flag)
  		{
  			cout<<"YES"<<endl;
  			return 0;
  		}
  	}
  }

  FOR(j,1,m)
  {
  	if(reach[1][j] and reach[2][j])
  	{
  		bool flag=true;
  		FOR(i,min(stx,edx),max(stx,edx))
  		{
  			if(arr[i][j]=='*')
  			{
  				flag=false;
  			}
  		}
  		if(flag)
  		{
  			cout<<"YES"<<endl;
  			return 0;
  		}
  	}
  }

  cout<<"NO"<<endl;
  return 0;
}