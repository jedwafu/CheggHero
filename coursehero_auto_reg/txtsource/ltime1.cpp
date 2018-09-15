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
  ll m1,m2,m3,o1,o2,o3,p1,p2,p3;
  ll maxi=0;
  while(t--)
  { 
    cin>>m1>>m2>>m3;
    cin>>o1>>o2>>o3;
    cin>>p1>>p2>>p3;
    maxi=0;
    maxi=max(m1+m2+m3,maxi);
    maxi=max(o1+o2+o3,maxi);
    maxi=max(p1+p2+p3,maxi);
    maxi=max(m1+o1+p1,maxi);
    maxi=max(m2+o2+p2,maxi);
    maxi=max(m3+o3+p3,maxi);

    if(maxi==0)
    	cout<<maxi<<endl;
    else if(maxi%2==0)
    	cout<<maxi-1<<endl;
    else
    	cout<<maxi<<endl;
  }
  return 0;
}