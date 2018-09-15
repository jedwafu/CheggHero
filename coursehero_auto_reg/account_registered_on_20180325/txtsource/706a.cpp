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

double x[N],y[N],v[N];
int main(){
	cout<<setprecision(12);
  fast;
  int a,b;
  cin>>a>>b;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>x[i]>>y[i]>>v[i];

  double mini=1e9;
  FOR(i,1,n)
  {
  	double dist=(x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b);
  	dist=sqrt(dist);
  	double time=dist/v[i];
  	if(time<mini)
  		mini=time;
  }
  cout<<mini;
  return 0;
}