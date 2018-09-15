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

int command[3][N];
ll query[N];
ll nums[N];

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	int n,m;
  	cin>>n>>m;
  	
  	fill(nums,0);
  	fill(query,0);
  	query[m+1]=1;

  	FOR(i,1,m)
  	cin>>command[0][i]>>command[1][i]>>command[2][i];

  	for(int i=m;i>=0;i--)
  	{
  		query[i]=(query[i+1]+query[i])%mod;
  		if(query[i]<0)
  			query[i]+=mod;

  		if(command[0][i]==2)
  		{
  			query[command[2][i]]=(query[command[2][i]]+query[i])%mod;
  			if(query[command[2][i]]<0)
  				query[command[2][i]]+=mod;

			query[command[1][i]-1]=(query[command[1][i]-1]-query[i])%mod;
  			if(query[command[1][i]-1]<0)
  				query[command[1][i]-1]+=mod;  			
  		}
  	}

  	FOR(i,1,m)
  	{
  		if(command[0][i]==1)
  		{
  			nums[command[1][i]]=(nums[command[1][i]]+query[i])%mod;
  			if(nums[command[1][i]]<0)
  				nums[command[1][i]]+=mod;

			nums[command[2][i]+1]=(nums[command[2][i]+1]-query[i])%mod;
  			if(nums[command[2][i]+1]<0)
  				nums[command[2][i]+1]+=mod;
  		}
  	}
  	
  	FOR(i,1,n)
  	{
  		nums[i]=nums[i-1]+nums[i];
  		nums[i]%=mod;
  		if(nums[i]<0)
  			nums[i]+=mod;
  	}
  	
  	FOR(i,1,n)
  	cout<<nums[i]<<" ";
  	cout<<endl;
  }
  return 0;
}