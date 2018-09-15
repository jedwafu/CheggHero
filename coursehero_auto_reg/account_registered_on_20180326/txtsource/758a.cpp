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

char c[4];
vector<ii> ans;

int main(){
  fast;
  string s;
  ans.clear();
  c[0]=c[1]=c[2]=c[3]='!';
  cin>>s;
  int len=sz(s);
  int cnt0=0;
  int cnt1=0;
  int cnt2=0;
  int cnt3=0;
  for(int i=0;i<len;i+=4)
  {
  	if(s[i]!='!')
    {
    	c[0]=s[i];
    }
    else if(i<len)
    {
    	cnt0++;
    }

  	if(i+1<len and s[i+1]!='!')
  	{
  		c[1]=s[i+1];
  	}
  	else if(i+1<len)
  	{
  		cnt1++;
  	}

  	if(i+2<len and s[i+2]!='!')
  	{
  		c[2]=s[i+2];
  	}
  	else if(i+2<len)
  	{
  		cnt2++;
  	}

  	if(i+3<len and s[i+3]!='!')
  	{
  		c[3]=s[i+3];
  	}
  	else if(i+3<len)
  	{
  		cnt3++;
  	}
  }

 // cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<" "<<cnt3;
  //cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
  if(c[0]!='!')
  {
  	if(c[0]=='R')
  		ans.pb(mp(1,cnt0));
  	if(c[0]=='B')
  		ans.pb(mp(2,cnt0));
  	if(c[0]=='Y')
  		ans.pb(mp(3,cnt0));
  	if(c[0]=='G')
  		ans.pb(mp(4,cnt0));
  }
  if(c[1]!='!')
  {
  	if(c[1]=='R')
  		ans.pb(mp(1,cnt1));
  	if(c[1]=='B')
  		ans.pb(mp(2,cnt1));
  	if(c[1]=='Y')
  		ans.pb(mp(3,cnt1));
  	if(c[1]=='G')
  		ans.pb(mp(4,cnt1));
  }
  if(c[2]!='!')
  {
  	if(c[2]=='R')
  		ans.pb(mp(1,cnt2));
  	if(c[2]=='B')
  		ans.pb(mp(2,cnt2));
  	if(c[2]=='Y')
  		ans.pb(mp(3,cnt2));
  	if(c[2]=='G')
  		ans.pb(mp(4,cnt2));
  }
  if(c[3]!='!')
  {
  	if(c[3]=='R')
  		ans.pb(mp(1,cnt3));
  	if(c[3]=='B')
  		ans.pb(mp(2,cnt3));
  	if(c[3]=='Y')
  		ans.pb(mp(3,cnt3));
  	if(c[3]=='G')
  		ans.pb(mp(4,cnt3));
  }	

  sort(ans.begin(),ans.end());

  FOR(i,0,sz(ans)-1)
  cout<<ans[i].S<<" ";


  return 0;
}