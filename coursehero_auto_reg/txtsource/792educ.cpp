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
const int mod = 1e9+7;
const int N = 1e5+10; 

string s;
int dp[3][N];
bool taken[3][N];
vi ans;
int main()
{
  fast;
  cin>>s;
  fill(taken,0);
  int n=sz(s);

  FOR(j,0,2)
  FOR(i,0,N-1)
  dp[j][i]=mod;
  
  if(s[0]!='0')
  {
  	int num=s[0]%3;
  	dp[num][0]=0;
  	taken[num][0]=1;
  }

  FOR(i,1,n-1)
  {
  	int num=s[i]-'0';
  	if(num!=0 and dp[num%3][i-1]==mod)
  	{
  		dp[num%3][i]=i;
  		taken[num%3][i]=1;
  	}


  	FOR(j,0,2)
  	dp[j][i]=min(dp[j][i],dp[j][i-1]+1);

  	FOR(j,0,2)
  	{
  		dp[(j+num)%3][i]=min(dp[(j+num)%3][i],dp[j][i-1]);
  		if(dp[(j+num)%3][i]==dp[j][i-1] and dp[j][i-1]!=mod)
  			taken[(j+num)%3][i]=1;
  	}
  }

  if(dp[0][n-1]==mod)
  {
  	FOR(i,0,n-1)
  	if(s[i]=='0')
  	{
  		cout<<0;
  		return 0;
  	}

  	cout<<-1;
  	return 0;
  }

  int check=0;
  NFOR(i,n-1,0)
  {
  	if(taken[check][i])
  	{
  		ans.pb(i);
  		int num=s[i]-'0';
  		num%=3;
  		check=(check-num)%3;
  		if(check<0)
  			check+=3;
  	}
  }
  
  reverse(ans.begin(),ans.end());
  FOR(i,0,sz(ans)-1)
  cout<<s[ans[i]]-'0';

  return 0;
}