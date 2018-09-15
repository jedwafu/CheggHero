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
const int N = 5e5+10; 

int c[2][2];
int ans[N];
int main(){
  fast;
  int n;
  cin>>n;
  c[0][0]=1;
  c[0][1]=2;
  c[1][0]=3;
  c[1][1]=4;

  FOR(i,1,n)
  {
  	int x1,y1,x2,y2;
  	cin>>x1>>y1>>x2>>y2;
  	x1=x1%2;
  	y1=y1%2;

  	if(x1<0)
  		x1+=2;
  	if(y1<0)
  		y1+=2;

  	ans[i]=c[x1][y1];
  }
  cout<<"YES"<<endl;
  FOR(i,1,n)
  cout<<ans[i]<<endl;
  return 0;
}