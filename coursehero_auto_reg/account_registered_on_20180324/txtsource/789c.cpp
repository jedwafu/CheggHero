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

ll arr[N];
ll pre[N];
ll mini[N];
ll maxi[N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  {
  	mini[i]=INF;
  	maxi[i]=-INF;
  }

  FOR(i,1,n)
  cin>>arr[i];

  pre[1]=0;
  mini[1]=0;
  pre[2]=abs(arr[1]-arr[2]);
  maxi[2]=pre[2];

  FOR(i,3,n)
  {
  	if(i%2)
  	{
  		pre[i]=pre[i-1]-abs(arr[i-1]-arr[i]);
  		mini[i]=min(mini[i-2],pre[i]);
  		//cout<<i<<" "<<mini[i]<<endl;
  	}
  	else
  	{
  		pre[i]=pre[i-1]+abs(arr[i-1]-arr[i]);
  		maxi[i]=max(maxi[i-2],pre[i]);
  		//cout<<i<<" "<<maxi[i]<<endl;
  	}
  }

  ll ans=pre[2];

  FOR(i,3,n)
  {
  	if(i%2)
  	{
  		ans=max(ans,pre[i]-mini[i-2]);
  		ans=max(ans,maxi[i-1]-pre[i]);
  	}
  	else
  	{
  		ans=max(ans,pre[i]-mini[i-1]);
  		ans=max(ans,maxi[i-2]-pre[i]);
  	}
  }

  cout<<ans;
  return 0;
}