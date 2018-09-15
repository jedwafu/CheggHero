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

unsigned long long  pows[65];
int main(){
  fast;
  unsigned long long l,r;
  pows[0]=1;
  FOR(i,1,60)
  pows[i]=2*pows[i-1];
  
  cin>>l>>r;
  
  if(l==r)
  {
  	cout<<0;
  	return 0;
  }

  unsigned long long  ans=0;
  NFOR(i,59,0)
  {
  	if(!(pows[i]&l) and (pows[i]&r))
  	{
  		ans=i;
  		break;
  	}
  }
  //cout<<ans<<endl;
  ans=pows[ans+1]-1;
  cout<<ans;
  return 0;
}