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

ll arr[N];
ll dp[2][N];
int main(){
  fast;
  int n;
  cin>>n;

  FOR(i,1,n)
  cin>>arr[i];
   
  dp[0][0]=dp[1][0]=0;   
  dp[0][1]=arr[1];
  FOR(i,2,n)
  dp[0][i]=dp[0][i-1]+arr[i];

  sort(arr+1,arr+n+1);
  dp[1][1]=arr[1];
  FOR(i,2,n)
  dp[1][i]=dp[1][i-1]+arr[i];  
  
  int m;
  cin>>m;

  FOR(i,1,m)
  {
  	int t,l,r;
  	cin>>t>>l>>r;
  	cout<<dp[t-1][r]-dp[t-1][l-1]<<endl;
  }
  return 0;
}