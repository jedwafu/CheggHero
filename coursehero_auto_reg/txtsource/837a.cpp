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

int a[210];
int b[210];
int prevs[210][26*210];
int dp[210][26*210];

int main()
{
  fast;
  int n,k;
  cin>>n>>k;
  FOR(i,1,n)
  {
  	ll num;
  	cin>>num;
  	int cnt=0;
  	while(num>1 and num%2==0)
  	{
  		cnt++;
  		num/=2;
  	}
  	a[i]=cnt;

  	cnt=0;
  	while(num>1 and num%5==0)
  	{
  		cnt++;
  		num/=5;
  	}
  	b[i]=cnt;
  }

  fill(prevs,-1);
  fill(dp,-1);
  prevs[0][0]=0;

  for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=k;j++)
  	{
      int lim=min(26*j,26*210-1);
  		for(int y=0;y<=lim;y++)
  		{
        dp[j][y]=prevs[j][y];
  			if(y-b[i]>=0 and prevs[j-1][y-b[i]]!=-1)
  			{
  				dp[j][y]=max(prevs[j][y],prevs[j-1][y-b[i]]+a[i]);
  			}
        
  		}
  	}

     for(int j=0;j<=k;j++)
	   for(int y=0;y<26*210;y++)
	   prevs[j][y]=max(prevs[j][y],dp[j][y]);
  }

  int ans=0;
  for(int y=0;y<26*210;y++)
  ans=max(ans,min(prevs[k][y],y));
  	

  cout<<ans;
  return 0;
}