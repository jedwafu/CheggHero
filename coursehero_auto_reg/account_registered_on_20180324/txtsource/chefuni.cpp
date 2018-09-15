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

int dp[3][110][110][110];
int cost[110][110][110];

int main()
{
  fast;
  freopen("in.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--)
  {
  	
  	FOR(i,0,100)
  	FOR(j,0,100)
  	FOR(k,0,100)
  	FOR(l,0,2)
  	dp[l][i][j][k]=0;


  	int A,B,C,x,y,z;
  	
  	cin>>x>>y>>z;
  	cin>>A>>B>>C;

  	cost[0][0][0]=0;
  	FOR(i,1,100)
  	{
  	dp[0][0][0][i]=1+dp[0][0][0][i-1];
  	cost[0][0][i]=cost[0][0][i-1]+A;

  	dp[0][0][i][0]=1+dp[0][0][i-1][0];
	cost[0][i][0]=cost[0][i-1][0]+A;

  	dp[0][i][0][0]=1+dp[0][i-1][0][0];
  	cost[i][0][0]=cost[i-1][0][0]+A;
  	}

  	FOR(i,0,x)
  	{
  	FOR(j,0,y)
  	{
  		FOR(k,0,z)
  		{
  			if(i+j+k==i or i+j+k==j or i+j+k==k)
  			continue;
  			cost[i][j][k]=mod;

  			if(i-1>=0 and cost[i][j][k]>=cost[i-1][j][k]+A)
  			{
  				cost[i][j][k]=cost[i-1][j][k]+A;
  				FOR(l,0,2)
  				dp[l][i][j][k]=dp[l][i-1][j][k];
  				dp[0][i][j][k]+=1;
  			}

  			if(j-1>=0 and cost[i][j][k]>=cost[i][j-1][k]+A)
  			{
  				cost[i][j][k]=cost[i][j-1][k]+A;
  				FOR(l,0,2)
  				dp[l][i][j][k]=dp[l][i][j-1][k];
  				dp[0][i][j][k]+=1;
  			}

  			if(k-1>=0 and cost[i][j][k]>=cost[i][j][k-1]+A)
  			{
  				cost[i][j][k]=cost[i][j][k-1]+A;
  				FOR(l,0,2)
  				dp[l][i][j][k]=dp[l][i][j][k-1];
  				dp[0][i][j][k]+=1;
  			}	

			if(i-1>=0 and j-1>=0 and cost[i][j][k]>=cost[i-1][j-1][k]+B)
  			{
  				cost[i][j][k]=cost[i-1][j-1][k]+B;
  				FOR(l,0,2)
  				dp[l][i][j][k]=dp[l][i-1][j-1][k];
  				dp[1][i][j][k]+=1;
  			}

  			if(i-1>=0 and k-1>=0 and cost[i][j][k]>=cost[i-1][j][k-1]+B)
  			{
  				cost[i][j][k]=cost[i-1][j][k-1]+B;
  				FOR(l,0,2)
  				dp[l][i][j][k]=dp[l][i-1][j][k-1];
  				dp[1][i][j][k]+=1;
  			}

  			if(j-1>=0 and k-1>=0 and cost[i][j][k]>=cost[i][j-1][k-1]+B)
  			{
  				cost[i][j][k]=cost[i][j-1][k-1]+B;
  				FOR(l,0,2)
  				dp[l][i][j][k]=dp[l][i][j-1][k-1];
  				dp[1][i][j][k]+=1;
  			}

  			if( i-1>=0 and j-1>=0 and k-1>=0 and cost[i][j][k]>=cost[i-1][j-1][k-1]+C)
  			{
  				cost[i][j][k]=cost[i-1][j-1][k-1]+C;
  				FOR(l,0,2)
  				dp[l][i][j][k]=dp[l][i-1][j-1][k-1];
  				dp[2][i][j][k]+=1;
  			}
  		}
  		}
  		}

 	    cout<<cost[x][y][z]<<endl;
 	    //cout<<dp[0][x][y][z]<<" "<<dp[1][x][y][z]<<" "<<dp[2][x][y][z]<<endl;
	}
  
  return 0;
}