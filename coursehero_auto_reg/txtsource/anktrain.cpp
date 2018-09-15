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
  while(t--)
  {
  	int n;
  	cin>>n;
    int rem=n%8;
    if(rem<0)
    rem+=8;

    if(rem==0)
    cout<<n-1<<"SL"<<endl;
    
    if(rem==1)
    cout<<n+3<<"LB"<<endl;
    
    if(rem==2)
    cout<<n+3<<"MB"<<endl;
    
    if(rem==3)
    	cout<<n+3<<"UB"<<endl;

    if(rem==4)
    	cout<<n-3<<"LB"<<endl;

    if(rem==5)
    	cout<<n-3<<"MB"<<endl;

    if(rem==6)
    	cout<<n-3<<"UB"<<endl;

    if(rem==7)
    	cout<<n+1<<"SU"<<endl;
   }
  return 0;
}