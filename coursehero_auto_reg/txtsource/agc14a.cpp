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

int main(){
  fast;
  ll a,b,c;
  cin>>a>>b>>c;
  if(a%2 or b%2 or c%2)
  {
  	cout<<0;
  	return 0;
  }

  if(a==b and b==c)
  {
  	cout<<-1;
  	return 0;
  }

  int ans=0;
  while(a%2==0 and b%2==0 and c%2==0)
  {
  	ans++;
  	ll newa=(b+c)/2;
  	ll newb=(a+c)/2;
  	ll newc=(a+b)/2;
  	a=newa;
  	b=newb;
  	c=newc;
  }

  cout<<ans;
  return 0;
}