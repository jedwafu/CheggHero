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

string s;
vector<char> ans;

bool dp[N][2*N];
char what[N][2*N];
int main(){
  fast;
  int n,k;
  cin>>n>>k;
  cin>>s;	  
  s='D'+s;

  dp[0][k]=true;
  
  FOR(i,1,n)
  {
  	FOR(j,-k,k)
  	{
  		dp[i][j+k]=false;
  		what[i][j+k]='F';
  		if(j+k-1<2*k and j+k-1>0 and dp[i-1][j+k-1] and (s[i]=='W' or s[i]=='?'))
  			{
  				dp[i][j+k]=true;
  				what[i][j+k]='W';
  			}
  		if(j+k+1<2*k and j+k+1>0 and dp[i-1][j+k+1] and (s[i]=='L' or s[i]=='?'))
  			{
  				dp[i][j+k]=true;
  				what[i][j+k]='L';
  			}
  		if(j+k<2*k and j+k>0 and dp[i-1][j+k] and (s[i]=='D' or s[i]=='?'))
  			{
  				dp[i][j+k]=true;
  				what[i][j+k]='D';
  			}
  	}
  }

  FOR(i,1,n-1)
  {
  	bool flag=false;	
  	FOR(j,-k+1,k-1)
  	{
  		if(dp[i][j+k])
  		{
  			flag=true;
  			break;
  		}
  	}

  	if(!flag)
  	{
  		cout<<"NO"<<endl;
  		return 0;
  	}
  }

  if(dp[n][0])
  {
  	int j=0;
  	NFOR(i,n,1)
  	{
  		ans.pb(what[i][j]);
  		if(what[i][j]=='W')
  			j--;
  		if(what[i][j]=='L')
  			j++;
  	}
  }

  else if(dp[n][2*k])
  {
  	int j=2*k;
  	NFOR(i,n,1)
  	{
  		ans.pb(what[i][j]);
  		if(what[i][j]=='W')
  			j--;
  		if(what[i][j]=='L')
  			j++;
  	}	
  }

  else
  {
  	cout<<"NO"<<endl;
  	return 0;
  }

  reverse(ans.begin(),ans.end());
  FOR(i,0,sz(ans)-1)
  cout<<ans[i];
  return 0;
}