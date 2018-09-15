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

vector<ii> power;
vector<ii> socket;
vector<int> powern;
vector<int> socketn;
int dones[200010];
int donep[200010];
int main(){
  fast;
  int n,m;
  cin>>n>>m;
  FOR(i,0,n-1)
  {
  	ll p;
  	cin>>p;
    power.pb(mp(p,i));
  }
  FOR(i,0,m-1)
  {
  	ll s;
  	cin>>s;
  	socket.pb(mp(s,i));
  }
  
  sort(power.begin(),power.end());
  sort(socket.begin(),socket.end());
  
  for(int i=0;i<200010;i++)
  	dones[i]=donep[i]=-1;
  
  int level=0;
  for(int i=0;i<32;i++)
  {
  	int cur_s=0;
  	int cur_p=0;
    
    while(cur_s<m and cur_p<n)
    {
    	if(donep[power[cur_p].S]!=-1)
    		cur_p++;
    	else if(dones[socket[cur_s].S]!=-1)
    		cur_s++;
    	else  if(socket[cur_s].F<power[cur_p].F)
    		cur_s++;
    	else if(socket[cur_s].F>power[cur_p].F)
    		cur_p++;
    	else if(socket[cur_s].F==power[cur_p].F)
    	{
    		dones[socket[cur_s].S]=level;
    		donep[power[cur_p].S]=socket[cur_s].S;
    		cur_s++;
    		cur_p++;
    	}
    }
    level++;
    //cout<<level<<endl;
    for(int i=0;i<m;i++)
    	if(dones[socket[i].S]==-1)
    		socket[i].F=(socket[i].F)/2+(((socket[i].F)%2)==1);
  } 

  int count=0;
  FOR(i,0,n-1)
  if(donep[i]!=-1)
     	count++;
     
  cout<<count<<" ";
  count=0;
  FOR(i,0,m-1)
  if(dones[i]!=-1)
  		count+=dones[i];
  
  cout<<count<<endl;
  FOR(i,0,m-1)
  {
  	if(dones[i]==-1)
  		cout<<0<<" ";
  	else
  		cout<<dones[i]<<" ";
  }
  cout<<endl;
  FOR(i,0,n-1)
  if(donep[i] ==-1)
  	cout<<0<<" ";
  else
  	cout<<donep[i]+1<<" ";

  cout<<endl;
  return 0;
}