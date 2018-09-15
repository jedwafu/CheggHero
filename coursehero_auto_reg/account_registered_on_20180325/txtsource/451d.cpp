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
  string s;
  cin>>s;
  int len=sz(s);
  int oa=0,ob=0,ea=0,eb=0;
  ll ansodd=0;
  ll anseven=0;
  FOR(i,0,len-1)
  {
  	if(i%2)
  	{
  		if(s[i]=='a')
  		{
  			oa++;
  			ansodd+=oa;
  			anseven+=ea;
  		}
  		else 
  		{
  			ob++;
  			ansodd+=ob;
  			anseven+=eb;
  		}
  	}
  	else
  	{
  		if(s[i]=='a')
  		{
  			ea++;
  			ansodd+=ea;
  			anseven+=oa;
  		}
  		else
  		{
  			eb++;
  			ansodd+=eb;
  			anseven+=ob;
  		}
  	}

  }

  cout<<anseven<<" "<<ansodd;
  return 0;
}