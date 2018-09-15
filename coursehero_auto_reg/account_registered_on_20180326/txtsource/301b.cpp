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

int n,d;
struct point
{
	int x,y;
	int distance(const point &p)
	{
		return d*(abs(x-p.x)+abs(y-p.y));
	}
};

point p[N];
int a[N];
int w[N][N];

int main(){
  fast;
  
  cin>>n>>d;
  FOR(i,1,n-2)
  cin>>a[i];

  FOR(i,0,n-1)
  cin>>p[i].x>>p[i].y;
  
  FOR(i,0,n-1)
  FOR(j,0,n-1)
  {
  	if(i!=j)
  	w[i][j]=p[i].distance(p[j])-a[j];
  }

  FOR(k,0,n-1)
  FOR(i,0,n-1)
  FOR(j,0,n-1)
  {
  	if(w[i][j]>w[i][k]+w[k][j])
  		w[i][j]=w[i][k]+w[k][j];
  }
  cout<<w[0][n-1]<<endl;
  return 0;
}