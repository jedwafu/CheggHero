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
const int N = 1e6+10; 

bool done[N];

int main(){
  fast;
  ll m,h1,a1,x1,y1,h2,a2,x2,y2;

  fill(done,0);

  cin>>m;
  cin>>h1>>a1;
  cin>>x1>>y1;
  cin>>h2>>a2;
  cin>>x2>>y2;

  int cur=h1;
  done[cur]=true;
  ll t1=m+2;

  FOR(i,1,m)
  {
  	cur=(x1*cur+y1)%m;
  	if(cur<0)
  		cur+=m;

  	if(cur==a1)
  		t1=min(t1,(ll)i);

  	if(done[cur])
  		break;
  	done[cur]=true;
  }

  fill(done,0);

  cur=h2;
  done[cur]=true;
  ll t2=m+2;

  FOR(i,1,m)
  {
  	cur=(x2*cur+y2)%m;
  	if(cur<0)
  		cur+=m;

  	if(cur==a2)
  		t2=min(t2,(ll)i);

  	if(done[cur])
  		break;
  	done[cur]=true;
  }  

  if(t1==m+2 or t2==m+2)
  	cout<<-1;
  else
  cout<<(t1*t2)/__gcd(t1,t2);
  
  return 0;
}