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
const int N = 2e3+10; 

ll dp[10*N];
ll tdp[10*N];
int arr[N];
int offset=10000;
int main(){
  fast;
  int n;
  cin>>n;
  fill(dp,0);
  fill(tdp,0);

  FOR(i,1,n)
  cin>>arr[i];
	
  ll ans=0;		
  dp[arr[1]+offset]=1;
  dp[-arr[1]+offset]=1;

  FOR(i,2,n)
  {
  	tdp[-arr[i]+offset]=tdp[arr[i]+offset]=1;
  	FOR(j,0,2*offset)
  	{
  		if(j-arr[i]>=0 and j-arr[i]<=2*offset)
  			tdp[j]+=dp[j-arr[i]];
  		if(j+arr[i]>=0 and j+arr[i]<=2*offset)
  			tdp[j]+=dp[j+arr[i]];

  		tdp[j]%=mod;
  		if(tdp[j]<0)
  			tdp[j]+=mod;

  		//if(dp[i][j])
  		//	cout<<"dp "<<i<<" "<<j<<" is "<<dp[i][j]<<endl;
  	}

  	FOR(j,0,2*offset)
  	{
  		dp[j]=tdp[j];
  		tdp[j]=0;
  	}

  	ans=(ans+dp[offset])%mod;
  	if(ans<0)
  		ans+=mod;
  }

  cout<<ans;
  return 0;
}