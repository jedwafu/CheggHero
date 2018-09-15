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

int fdepth=0;
string s;
int depth=-1;
ll pows[60];
map<ll,int> dir;

void calc(ll cur,ll val)
{
	depth++;

	if(val==cur)
		return;

	if(val<cur)
	{
		ll low=cur-pows[fdepth-depth]+1;
		ll high=cur-1;
		dir[(low+high)/2]=1;
		calc((low+high)/2,val);
	}
	else
	{
		ll low=cur+1;
		ll high=cur+pows[fdepth-depth]-1;
		dir[(low+high)/2]=2;
		calc((low+high)/2,val);
	}
}

int main(){
  fast;
  ll n;
  int q;
  cin>>n>>q;

  pows[0]=1;
  FOR(i,1,59)
  pows[i]=2*pows[i-1];

  ll total=n+1;
  while(total>1)
  {
  	total/=2;
  	fdepth++;
  }
  fdepth--;
 // cout<<"fdepth "<<fdepth<<endl;

  FOR(j,1,q)
  {
  	ll start;
  	cin>>start;
  	cin>>s;
  	depth=-1;

  	calc((n+1)/2,start);

  	FOR(i,0,sz(s)-1)
  	{
  		if(s[i]=='U')
  		{
  			if(start==(n+1)/2)
  				continue;

  			if(dir[start]==1)
  			{
  				start=(start+pows[fdepth-depth]);
  				depth--;
  			}
  			else if(dir[start]==2)
  			{
  				start=(start-pows[fdepth-depth]);
  				depth--;
  			}
  		}

  		if(s[i]=='L')
  		{
  			if(depth==fdepth)
  				continue;
  			
  			ll low=start-pows[fdepth-depth]+1;
			ll high=start-1;
			dir[(low+high)/2]=1;
			start=(low+high)/2;
			depth++;
  		}

  		if(s[i]=='R')
  		{
  			if(depth==fdepth)
  				continue;

  			ll low=start+1;
			ll high=start+pows[fdepth-depth]-1;
			dir[(low+high)/2]=2;
			start=(low+high)/2;
			depth++;
  		}

  		//cout<<start<<" "<<depth<<endl;
  	}
  	cout<<start<<endl;
  }
  return 0;
}