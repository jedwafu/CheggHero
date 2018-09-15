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
const int inf= 1e7;
const ll mod = 1e9+7;
const int N = 1e5+10; 

int arr[110];
int dp[110][3];

int main(){
  fast;
  int n;
  cin>>n;

  FOR(i,0,n-1)
  cin>>arr[i];
  
  FOR(i,0,n-1)
  FOR(j,0,2)
  dp[i][j]=inf;

  if(arr[0]==0)
  dp[0][0]=1;
  if(arr[0]==1)
  	dp[0][1]=0;
  if(arr[0]==2)
  	dp[0][2]=0;
  if(arr[0]==3)
  	dp[0][1]=dp[0][2]=0;
  
  FOR(i,1,n-1)
  {
  	
  	dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
  	
  	if(arr[i]==1)
  	dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
  	
  	if(arr[i]==2)
    dp[i][2]=min(dp[i-1][0],dp[i-1][1]);	
  	
  	if(arr[i]==3)
  	{
       dp[i][1]=min(dp[i-1][0],dp[i-1][2]);	
       dp[i][2]=min(dp[i-1][0],dp[i-1][1]);	
  	}

  }

   cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
  return 0;
}