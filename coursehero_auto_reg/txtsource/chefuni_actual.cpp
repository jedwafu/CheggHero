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

int x,y,z;
int a,b,c;
int mini,minicost,maxi;

void check(int t,int X,int Y,int Z)
{
	maxi=max(X,max(Y,Z));
	if(X+Y+Z-maxi>=maxi)
	{
		if((X+Y+Z)%2)
		minicost=min(minicost,t*c+((X+Y+Z)/2)*b+a);
		else
		minicost=min(minicost,t*c+((X+Y+Z)/2)*b);
	}
	else
	{
		minicost=min(minicost,t*c+(X+Y+Z-maxi)*b+(maxi-(X+Y+Z-maxi))*a);
	}

	minicost=min(minicost,t*c+(X+Y+Z)*a);
	return;
}

int main(){
  fast;

  //freopen("in.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int t;
  cin>>t;
  
  
  while(t--)
  {
  	cin>>x>>y>>z;
  	cin>>a>>b>>c;
	  	
	minicost=(x+y+z)*a;
	  	
  	check(0,x,y,z);

  	if(x>=1 and y>=1 and z>=1)
  	check(1,x-1,y-1,z-1);
  	
  	mini=min(x,min(y,z));
  	check(mini,x-mini,y-mini,z-mini);

  	maxi=max(x,max(y,z));
  	int k=x+y+z-2*maxi;
  	
  	if(k>=0)
  	check(k,x-k,y-k,z-k);

  	if((x+y+z-3*k)%2 and k>=1)
  	check(k-1,x-k+1,y-k+1,z-k+1);

  	cout<<minicost<<endl;
  }

  return 0;
}