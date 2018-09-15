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
  int n;
  cin>>n;
  ll change=0;
  int c,d;
  ll L=-INF;
  ll R=INF;
  FOR(i,1,n)
  {
  	cin>>c>>d;
  	if(d==1)
    L=max(L,1900-change);
    else
    R=min(R,1899-change);
    
    change+=c;
  }
  if(R==INF)
  	cout<<"Infinity";
  else if(L>R)
  	cout<<"Impossible";
  else
  	cout<<R+change;
  return 0;
}