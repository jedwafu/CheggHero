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

int cnt[26];
int dp[N];
int main(){
  fast;
  fill(cnt,0);
  int index=2;
  FOR(i,1,100000)
  {
  	if(i<(index*(index-1))/2)
  		dp[i]=index-1;
  	if(i==(index*(index-1))/2)
  	{
  		dp[i]=index;
  		index++;
  	}
  }

  int n;
  cin>>n;
  if(n==0)
  {
  	cout<<"a"<<endl;
  	return 0;
  }
  index=0;
  while(n>0)
  {
  	//cout<<n<<" "<<dp[n]<<endl;
  	cnt[index]=dp[n];
  	n-=((dp[n]*(dp[n]-1))/2);
  	index++;
  }

  string ans="";
  for(int i=0;i<26;i++)
  {
  	for(int j=0;j<cnt[i];j++)
  		ans+='a'+i;
  }
  cout<<ans<<endl;
  return 0;
}