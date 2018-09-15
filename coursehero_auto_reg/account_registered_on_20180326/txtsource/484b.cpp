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
const int N = 2e6+10; 

int last_max[N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  {
  	int temp;
  	cin>>temp;
  	last_max[temp]=temp;
  }
  
  FOR(i,1,N-1)
  if(!last_max[i])
  	last_max[i]=last_max[i-1];

  int ans=0;
  FOR(i,1,N-1)
  {
  	if(last_max[i]==i)
  		{
  			for(int j=2*i-1;j<N;j+=i)
  				ans=max(ans,last_max[j]%i);
  		}
  } 
  cout<<ans;
  return 0;
}