#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

multiset<int> S;
vector<ii> ops;
int main(){
  fast;
  int n;
  cin>>n;
  
  FOR(i,1,n)
  {
  	string s;
  	cin>>s;
  	if(s=="insert")
  	{
  		int temp;
  		cin>>temp;
  		S.insert(temp);
  		ops.pb(mp(1,temp));
  	}
  	else if(s=="removeMin")
  	{
  		if(S.empty())
  			ops.pb(mp(1,1));
  		else
  		S.erase(S.begin());

  		ops.pb(mp(2,0));
  	}
  	
  	else
  	{
  		int temp;
  		cin>>temp;
  		while(!S.empty() and *S.begin()<temp)
  		{
  			ops.pb(mp(2,0));
  			S.erase(S.begin());
  		}
  		if(S.empty() or *S.begin()>temp)
  		{
  			S.insert(temp);
  			ops.pb(mp(1,temp));
  		}
  		
  		ops.pb(mp(3,temp));
  	}
  }

  cout<<sz(ops)<<endl;
  FOR(i,0,sz(ops)-1)
  {
  	if(ops[i].F==1)
  		cout<<"insert "<<ops[i].S<<endl;
  	else if(ops[i].F==2)
  		cout<<"removeMin"<<endl;
  	else
  		cout<<"getMin "<<ops[i].S<<endl;
  }
  return 0;
}