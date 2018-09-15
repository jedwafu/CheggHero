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

ll a[N];
ll pre[N];
ll suff[N];
map<ll,int> m1;
map<ll,int> m2;

int main(){
  fast;
  int n;
  cin>>n;	 
  FOR(i,1,n)
  cin>>a[i];

  pre[0]=0;
  FOR(i,1,n)
  {
  	pre[i]=pre[i-1]+a[i];
  	m1[pre[i]]=i;
  }

  FOR(i,1,n)
  {
  	suff[i]=pre[n]-pre[i-1];
  	m2[suff[i]]=i;
  }


  if(pre[n]%2)
  {
  	cout<<"NO";
  	return 0;
  }

  ll half=pre[n]/2;

  if(m1[half])
  {
  	cout<<"YES";
  	return 0;
  }

  FOR(i,1,n)
  {
  	if(m1[half+a[i]]>=i)
  	{
  		cout<<"YES";
  		return 0;
  	}
  	if(m2[half+a[i]] and m2[half+a[i]]<=i)
  	{
  		cout<<"YES";
  		return 0;
  	}
  }

  cout<<"NO";
  return 0;
}