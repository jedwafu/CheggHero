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
const int N = 3e6+10; 

bool arr[N];
int main(){
  fast;
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  fill(arr,0);
  
  while(b<N)
  {
  	arr[b]=true;
  	b+=a;
  }

  while(d<N)
  {
  	if(arr[d]==true)
  	{
  		cout<<d<<endl;
  		return 0;
  	}
  	d+=c;
  }

  cout<<-1;
  return 0;
}