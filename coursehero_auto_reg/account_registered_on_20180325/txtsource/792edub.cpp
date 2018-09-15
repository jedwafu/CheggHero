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
const int N = 1e2+10; 

ll a[N];
int pos[N];
int main(){
  fast;
  int n,k;
  cin>>n>>k;
  FOR(i,0,n-1)
  pos[i]=i+1;

  FOR(i,0,k-1)
  cin>>a[i];

  int leader=0;
  FOR(i,0,k-1)
  {
  	int jump=a[i]%(n-i);
  	while(jump>0)
  	{
  		leader=(leader+1)%(n);
  		if(pos[leader])
  			jump--;
  	}
  	cout<<pos[leader]<<" ";
  	pos[leader]=0;
  	while(pos[leader]==0)
  	{
  		leader=(leader+1)%(n);
  	}
  }


  return 0;
}