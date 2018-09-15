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
  int q;
  cin>>q;
  FOR(i,1,q)
  {
    ll a,b;
  	cin>>a>>b;
  	if(a%2==1 and b%2==1 and abs(b-a)==2)
  		cout<<"YES"<<endl;
  	else if(a%2==0 and b%2==0 and abs(b-a)==2)
  		cout<<"YES"<<endl;
  	else if(a%2==1 and b%2==0 and (b-a)==1)
  		cout<<"YES"<<endl;
  	else if(a%2==0 and b%2==1 and (a-b)==1)
  		cout<<"YES"<<endl;
  	else
  		cout<<"NO"<<endl;
  }
  return 0;
}		 