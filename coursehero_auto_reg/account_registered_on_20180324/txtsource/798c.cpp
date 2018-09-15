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
const int N = 55; 

string arr[N];
string possible[N];
string temp[N];
int n;
bool check()
{
	FOR(i,1,n-1)
	{
		if(temp[i]!=temp[i+1])
			return false;
	}
	return true;
}

int main(){
  fast;
  
  cin>>n;
  FOR(i,1,n)
  {
  	cin>>arr[i];
  }

  ll ans=mod;
  ll tans=0;

  FOR(k,0,sz(arr[1]))
  {
  	possible[k]=arr[1].substr(k,sz(arr[1])-k)+arr[1].substr(0,k);
  }

  FOR(k,0,sz(arr[1])-1)
  {
  	tans=0;
  	FOR(i,1,n)
  	{
  		bool flag=false;
  		FOR(j,0,sz(arr[1])-1)
  		{
  			temp[j]=arr[i].substr(j,sz(arr[i])-j)+arr[i].substr(0,j);
  			if(temp[j]==possible[k])
  			{
  				tans+=j;
  				flag=true;
  				break;
  			}
  		}
  		if(!flag)
  		tans+=mod;
  	}
  	ans=min(ans,tans);
  }
  
  if(ans>=mod)
  	cout<<-1;
  else
  	cout<<ans;

  return 0;
}