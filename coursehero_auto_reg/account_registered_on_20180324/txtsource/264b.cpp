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

vi divs[N];
int sp[N];
int last[N];
int dp[N];

void sieve()
{
   for(int i=2;i<N;i+=2)
   	sp[i]=2;

   for(int i=3;i<N;i+=2)
   {
   	if(!sp[i])
   	{
       sp[i]=i;
       if(i<=sqrt(N))
       for(int j=i*i;j<N;j+=2*i)
       	if(!sp[j])
       		sp[j]=i;
   	}
   }
}

int main(){
  fast;
  fill(last,0);
  fill(sp,0);
  fill(dp,0);
  sieve();

  int n;
  cin>>n;
  FOR(i,1,n)
  {
  	int temp;
  	cin>>temp;
  	//int temp=arr[i];
  	divs[i].clear();
    while(temp>1)
    {
    	divs[i].pb(sp[temp]);
    	temp/=sp[temp];
    }
  }
  
  dp[1]=1;
  for(int i=0;i<sz(divs[1]);i++)
  	last[divs[1][i]]=1;
  
  for(int i=2;i<=n;i++)
  {
  	dp[i]=1;
     for(int j=0;j<sz(divs[i]);j++)
     {
     	if(last[divs[i][j]])
        {
        	dp[i]=max(dp[i],1+dp[last[divs[i][j]]]);
        }
     }
     
     //cout<<i<<" "<<dp[i]<<endl;
     for(int j=0;j<sz(divs[i]);j++)
     last[divs[i][j]]=i;
  }
  
  int ans=0;
  for(int i=1;i<=n;i++)
  	ans=max(dp[i],ans);

  cout<<ans;
  return 0;
}