#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 
vector<ii> sorted(5010);
int arr[5010];
int n;
int dp[5010][5010];
void DP(int index)
{
    for(int i=0;i<index;i++)
    {
       dp[sorted[i].S][sorted[index].S]=0;
       if(sorted[index].F<sorted[i].F)
       {
       	dp[sorted[i].S][sorted[index].S]=1;
       	int temp=0;
       	for(int j=index+1;j<n;j++)
       {
       	if(sorted[j].F<sorted[index].F and ((sorted[i].S<j and j<sorted[index].S)or(sorted[index].S<j and j<sorted[i].S)))
       	{
          temp=max(temp,dp[sorted[index].S][sorted[j].S]);  		
       	}
       }
       dp[sorted[i].S][sorted[index].S]+=temp;
       //cout<<i<<" "<<index<<" "<<dp[sorted[i].S][sorted[index].S]<<endl;
       }
    }
}

int main(){
  fast;
  
  cin>>n;
  for(int i=0;i<n;i++)
  {
  	cin>>arr[i];
  	sorted.pb(mp(arr[i],i));
  }
  sort(sorted.begin(),sorted.end());
  reverse(sorted.begin(),sorted.end());
  
  for(int i=0;i<n-1;i++)
  {
  	  if(sorted[n-1].F<sorted[i].F)
      dp[sorted[i].S][sorted[n-1].S]=1;
      else dp[sorted[i].S][sorted[n-1].S]=0;
  }

  for(int i=n-2;i>0;i--)
  	DP(i);

  for(int i=0;i<n;i++)
  {
  	int ans=0;
  	for(int j=0;j<n;j++)
  	{
  		if(i!=j and arr[j]<arr[i])
  		ans=max(ans,dp[i][j]);
  	}
  	cout<<ans<<" ";
  }
  return 0;
}