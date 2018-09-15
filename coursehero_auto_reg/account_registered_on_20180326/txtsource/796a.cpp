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

int arr[N];
int main(){
  fast;
  int n,m,k;
  cin>>n>>m>>k;

  FOR(i,1,n)
  cin>>arr[i];

  int mindist=mod;
  FOR(i,1,m-1)
  {
  	if(arr[i]>0 and k>=arr[i])
  		{
  			mindist=min(mindist,10*(m-i));
  		}
  }
  FOR(i,m+1,n)
  {
  	if(arr[i]>0 and k>=arr[i])
  		{
  			mindist=min(mindist,10*(i-m));
  		}		
  }
  cout<<mindist;
  return 0;
}