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

string s;
int check()
{
	int ans=0;
	FOR(i,1,sz(s)-1)
	{
		if(s[i]=='K' and s[i-1]=='V')
			ans++;
	}
	return ans;
}
int main(){
  fast;
  cin>>s;
  int ans=check();
  FOR(i,0,sz(s)-1)
  {
  	if(s[i]=='V')
  	{
  		s[i]='K';
  		ans=max(ans,check());
  		s[i]='V';
  	}
  	if(s[i]=='K')
  	{
  		s[i]='V';
  		ans=max(ans,check());
  		s[i]='K';
  	}	
  }
  cout<<ans;
  return 0;
}