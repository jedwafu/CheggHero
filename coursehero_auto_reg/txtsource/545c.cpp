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

ll x[N],h[N];
int fell[N];
int main(){
  fast;
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  	{cin>>x[i]>>h[i];
     fell[i]=x[i];
    }

  int ans=n;
  fell[0]=x[0];
  for(int i=1;i<n-1;i++)
  {
     if(x[i]-h[i]>fell[i-1])
     	fell[i]=x[i];
     else if(x[i]+h[i]<x[i+1])
     	fell[i]=x[i]+h[i];
     else
     	ans--;

  }

  cout<<ans<<endl;
  return 0;
}