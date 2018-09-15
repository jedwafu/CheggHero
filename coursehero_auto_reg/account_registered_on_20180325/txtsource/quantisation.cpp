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

int arr[1010];
ll dp[1010][130];
int taken[1010][130];
int levels[130][130];
int main(){
	FILE *fin =freopen("quant.in","r",stdin);
	FILE *fout=freopen("quant.out","w",stdout);
  fast;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  	cin>>arr[i];
  
  int m,s;
  cin>>m>>s;

  for(int i=0;i<m;i++)
  	for(int j=0;j<s;j++)
  		cin>>levels[i][j];

  for(int i=0;i<s;i++)
  	dp[0][i]=abs(arr[0]-levels[0][i]);
  
  int next;
  for(int i=1;i<n;i++)
  {
  	
  	for(int j=0;j<s;j++)
  	{
  		ll mini=INF;
  		int temp;
  		for(int k=0;k<s;k++)
  		{
  			next=k&(m-1);
  			if(dp[i-1][k]+abs(arr[i]-levels[next][j])<mini)
  			{
  				mini=dp[i-1][k]+abs(arr[i]-levels[next][j]);
  				temp=k;
  			}
  		}
  		dp[i][j]=mini;
  		taken[i][j]=temp;
  	}
  }

  int temp;
  ll ans=INF;
  vector<int> final;
  for(int i=0;i<s;i++)
  	{
        if (dp[n-1][i]<ans)
        {
        	ans=dp[n-1][i];
        	temp=i;
        }
  	}
  final.pb(temp);

  for(int i=n-1;i>0;i--)
  {
  	temp=taken[i][temp];
    final.pb(temp);
  }
  
  cout<<ans<<endl;
  for(int i=final.size()-1;i>=0;i--)
  	cout<<final[i]<<" ";
  return 0;
}