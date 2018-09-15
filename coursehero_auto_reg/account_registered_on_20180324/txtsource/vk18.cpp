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

ll val[2000010];
ll dp[1000010];
ll prefix[2000010];

int main(){
  fast;
  int t;
  cin>>t;

  prefix[0]=0;
  for(int i=1;i<=2000000;i++)
  {
  	int num=i;
  	int odd=0;
  	int even=0;
  	while(num)
  	{
  		if((num%10)%2)
  			odd+=num%10;
  		else
  			even+=num%10;
  		num/=10;
  	}

  	val[i]=abs(odd-even);
  	prefix[i]=prefix[i-1]+val[i];
  }

  dp[1]=2;
  for(int i=2;i<=1000000;i++)
  {
  	dp[i]=dp[i-1];
  	dp[i]+=2*(prefix[2*i-1]-prefix[i]);
  	dp[i]+=val[2*i];
  }

  while(t--)
  {
  	int n;
  	cin>>n;
  	cout<<dp[n]<<endl;
  }
  return 0;
}