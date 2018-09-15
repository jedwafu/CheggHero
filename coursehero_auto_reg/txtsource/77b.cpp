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
  int t;
  cin>>t;
  cout<<setprecision(12);
  while(t--)
  {
  	double a,b;
  	cin>>a>>b;
  	if(b==0)
  	{
  		cout<<1<<endl;
  		continue;
  	}

  	if(a>4*b)
  	{
        double temp=4*b;
        temp=((temp*temp)/8)+b*temp;
        temp/=2*a*b;
        temp+=(a-4*b)/a;
        cout<<temp<<endl;
  	}
  	else
  	{
  		double temp=a/8+b;
  		temp/=2*b;
  		cout<<temp<<endl;
  	}
  }
  return 0;
}