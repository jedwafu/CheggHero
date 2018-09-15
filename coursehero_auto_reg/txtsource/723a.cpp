#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
  int x1,x2,x3;
  cin>>x1>>x2>>x3;

  int mini=100000;
  for(int i=1;i<=100;i++)
  mini=min(mini,abs(i-x1)+abs(i-x2)+abs(i-x3));
  
  cout<<mini<<endl;
  return 0;
}