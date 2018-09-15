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
const int N = 1e6+10; 

bool present[2010];
bool vis[2010];
queue<ii> q;
int main(){
  fast;
  int n,k;
  cin>>n>>k;
  fill(vis,0);
  int ans=0;
  bool flag1=false,flag2=false;
  FOR(i,1,k)
  {
  	int temp;
  	cin>>temp;
  	if(temp==n)
  	ans=1;
  	
  	if(temp<n)
  		flag1=true;
  	if(temp>n)
  		flag2=true;

  	present[temp]=true;
  }

  if(ans)
  {
  	cout<<1;
  	return 0;
  }

  if(!flag1 or !flag2)
  {
  	cout<<-1;
  	return 0;
  }

  q.push(mp(1000,0)); //everything shifted forward by 1000.
  flag1=false;
  while(!q.empty())
  {
  	int val=q.front().F;
  	int len=q.front().S;
  	if(val==1000 and flag1)
  		{
  			cout<<len;
  			return 0;
  		}
  	flag1=true;
  	q.pop();
  	if(vis[val])
  		continue;

  	vis[val]=true;
  	FOR(i,0,1000)
  	{
  		if(present[i])
  		{
  			if(0<=val+i-n and 1000>=val+i-n)
  			{
  				q.push(mp(val+i-n,len+1));
  			}
  		}
  	}
  }

  cout<<ans<<endl;
  return 0;
}