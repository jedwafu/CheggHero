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
double epsilon=1e-8;
const double PI = acos(-1.0);
int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  fast;
  
  int t;
  cin>>t;
  FOR(T,1,t)
  {
  	int p,x,y;
  	cin>>p>>x>>y;
  	if(p==0 or (((x-50)*(x-50))+((y-50)*(y-50)))>2500)
  	cout<<"Case #"<<T<<": white"<<endl;
    else
  	{
  		double np=(3.6)*p;
  		np=(PI/180)*np;
  		
  		double x1=0,y1=50,x2=x-50,y2=y-50;
  		double angle=atan2(x1*y2-y1*x2,x1*x2+y1*y2);
  		angle=-angle;
  		

  		if(angle<0)
  			angle+=2*PI;
  		if(np>=angle-epsilon)
  			cout<<"Case #"<<T<<": black"<<endl;
  		else
  			cout<<"Case #"<<T<<": white"<<endl;
  	}	
  }

  return 0;
}