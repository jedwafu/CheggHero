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
int main(){
  fast;
  int r;
  cin>>r;

  while(r--)
  {
  	int l;
  	cin>>l;
  	int lookingfor=0;
  	cin>>s;

  	FOR(i,0,l-1)
  	{
  		if(lookingfor and s[i]=='T')
  		lookingfor=0;

  		else if(lookingfor and s[i]=='H')
  		{
  			cout<<"Invalid"<<endl;
  			lookingfor=1;
  			break;
  		}

  		else if(!lookingfor and s[i]=='T')
  		{
  			cout<<"Invalid"<<endl;
  			lookingfor=1;
  			break;
  		}

  		else if(!lookingfor and s[i]=='H')
  			lookingfor=1;

  		if(i==(l-1) and lookingfor)
  		{
  			cout<<"Invalid"<<endl;
  			break;
  		}

  		if(i==(l-1) and !lookingfor)
  		{
  			cout<<"Valid"<<endl;
  			break;
  		}
  	}

  }
  return 0;
}