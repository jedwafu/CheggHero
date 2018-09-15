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

int arr[2][N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,0,n-1)
  cin>>arr[0][i]>>arr[1][i];

  ll L=0,R=0;
  FOR(i,0,n-1)
  {
  	L+=arr[0][i];
  	R+=arr[1][i];
  }
  ll maxi=abs(L-R);
  ll templ,tempr;
  int index=-1;
  FOR(i,0,n-1)
  {
      templ=L-arr[0][i]+arr[1][i];
      tempr=R-arr[1][i]+arr[0][i];
      if(abs(templ-tempr)>maxi)
      {
      	maxi=abs(templ-tempr);
      	index=i;
      }  
  }

  cout<<index+1<<endl;
  return 0;
}