#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e4+10; 

vector<ii> arr[N];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  bool flag=true;
  FOR(i,1,m)
  {
  	int k;
  	cin>>k;
  	FOR(j,1,k)
  	{
  		int temp;
  		cin>>temp;
  		if(temp<0)
  			arr[i].pb(mp(-1*temp,-1));
  		else
  			arr[i].pb(mp(temp,1));
  	}
  	
  	if(flag==false)
  		continue;
  	
  	sort(arr[i].begin(),arr[i].end());
  	flag=false;

  	FOR(j,1,k-1)
  	{
  		if(arr[i][j].F==arr[i][j-1].F and arr[i][j].S != arr[i][j-1].S)
  		{
  			flag=true;
  			break;
  		}
  	}

  }

  if(flag)
  cout<<"NO";
  else
  	cout<<"YES";
  return 0;
}