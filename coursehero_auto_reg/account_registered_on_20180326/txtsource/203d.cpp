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
  double a,b,m;
  double vx,vy,vz;
  double finalx,finalz;
  cin>>a>>b>>m;
  cin>>vx>>vy>>vz;
  
  double t=m/(-vy);
  if(vx==0)
   finalx=a/2;

  if(vx>0)
  {	
    double unitx=a/(2*vx);
    int temp=t/unitx;
    
    if(temp%4==0)
        finalx=a/2+(t-unitx*temp)*vx;
    if(temp%4==1)
    	finalx=a-(t-unitx*temp)*vx;
    if(temp%4==2)
    	finalx=a/2-(t-unitx*temp)*vx;
    if(temp%4==3)
        finalx=(t-unitx*temp)*vx;
  }
  if(vx<0)
  {
  	double unitx=a/(-2*(vx));
    int temp=t/unitx;

    if(temp%4==0)
        finalx=a/2+(t-unitx*temp)*vx;
    if(temp%4==1)
    	finalx=-(t-unitx*temp)*vx;
    if(temp%4==2)
    	finalx=a/2-(t-unitx*temp)*vx;
    if(temp%4==3)
        finalx=a+(t-unitx*temp)*vx;
  }
  
  if(vz==0)
  	finalz=0;
  else
  {
  	double unitz=b/vz;
  	int temp=t/unitz;
  	if(temp%2)
  		finalz=b-(t-unitz*temp)*vz;
  	else
  		finalz=(t-unitz*temp)*vz;
  }
   cout<<setprecision(12);
   cout<<finalx<<" "<<finalz;
  return 0;
}