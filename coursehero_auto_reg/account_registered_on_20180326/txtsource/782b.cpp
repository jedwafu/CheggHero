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

int n;
double pos[N],sp[N];
double eps=0.0000001;
bool check(double t)
{
	double left,right;
	left=pos[1]-sp[1]*t;
	right=pos[1]+sp[1]*t;
	FOR(i,2,n)
	{
		if(pos[i]-sp[i]*t>right-eps or pos[i]+sp[i]*t<left+eps)
			return false;
		left=max(left,pos[i]-sp[i]*t);
		right=min(right,pos[i]+sp[i]*t);
	}

	if(left<=right+eps)
		return true;
	else
		return false;
}

int main(){
  fast;
  cout<<setprecision(12);
  cin>>n;
  FOR(i,1,n)
  cin>>pos[i];
  FOR(i,1,n)
  cin>>sp[i];

  double r=1e9;
  double l=0;
  while(r-l>eps)
  {
  	double mid=(r+l)/2;
  	if(check(mid))
  		r=mid;
  	else
  		l=mid;
  }
  if(check(l))
  	cout<<l;
  else
  	cout<<r;

  return 0;
}