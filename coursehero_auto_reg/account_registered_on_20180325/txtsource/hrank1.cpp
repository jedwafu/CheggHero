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

double arr[3][5];
double eps=0.0000001;
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	double xh,yh;
  	cin>>xh>>yh;
  	double xc,yc,sc;
  	cin>>xc>>yc>>sc;
  	bool flag=false;
  	FOR(i,0,4)
  	{
  		cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
  	}

  	double tm=sqrt((xc-xh)*(xc-xh)+(yc-yh)*(yc-yh))/sc;
  	FOR(i,0,4)
  	{
  		if((sqrt((arr[0][i]-xh)*(arr[0][i]-xh)+(arr[1][i]-yh)*(arr[1][i]-yh))/arr[2][i])<(tm-eps))
  		{
  			cout<<"NO"<<endl;
  			flag=true;
  			break;
  		}
  	}

  	if(!flag)
  		cout<<"YES"<<endl;
  }

  return 0;
}