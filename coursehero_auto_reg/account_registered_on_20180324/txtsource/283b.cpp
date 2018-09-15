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
const int N = 2e5+10; 
int n;
int arr[N];
int edgebig[N];
int edgesmall[N];
//int wbig[N];
//int wsmall[N];
ll dp[2][N];

ll DP(int type,int pos)
{
	if(dp[type][pos]+1)
		return dp[type][pos];
    
    if(dp[type][pos]==-2)
    	return -2;

	if(type==0)
	{
       dp[type][pos]=-2;
       ll val=DP(1-type,pos-arr[pos]);
       if(val==-2)
       return -2;
       dp[type][pos]=arr[pos]+val;
       return dp[type][pos];
	}
	else
	{
	   dp[type][pos]=-2;
       ll val=DP(1-type,pos+arr[pos]);
       if(val==-2)
       return -2;
       dp[type][pos]=arr[pos]+val;
       return dp[type][pos];
	}
}

int main(){
  fast;
  cin>>n;
  fill(dp,-1);
  
  dp[1][1]=-2;
  FOR(i,2,n)
  {
  	cin>>arr[i];
  	edgesmall[i]=i-arr[i];
  	//wsmall[i]=arr[i];
  	edgebig[i]=i+arr[i];
  	//wbig[i]=arr[i];
  	if(edgesmall[i]<=0)
  		dp[0][i]=arr[i];
  	if(edgebig[i]>n)
  		dp[1][i]=arr[i];
  }
  
  FOR(i,2,n)
  DP(0,i);

  FOR(i,2,n)
  {
  	if(dp[0][i]==-2)
  		cout<<-1<<endl;
  	else
        cout<<dp[0][i]+i-1<<endl;
  }
  
  return 0;
}