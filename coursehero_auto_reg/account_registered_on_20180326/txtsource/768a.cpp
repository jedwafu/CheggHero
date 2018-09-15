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
ll ans=0;
void solve(ll val,ll st,ll ed,ll l,ll r)
{
  if(l>ed or r<st or l>r)
    return;

  if(val==1)
  {
    ans++;
    return;
  }

  ll mid=(st+ed)/2;
  //cout<<"mid is "<<mid<<endl;
  if(l>mid)
    solve(val/2,mid+1,ed,l,r);
  else if(r<mid)
    solve(val/2,st,mid-1,l,r);
  else
    {
      if(val%2==1)
        ans++;

      solve(val/2,st,mid-1,l,mid-1);
      solve(val/2,mid+1,ed,mid+1,r);
    }
}

int main(){
  fast;
  //check for n=1 and 0.
  ll n,l,r;
  cin>>n>>l>>r;
  
  ll len=0;
  ll pows=1;
  if(n==1)
  {
    cout<<1;
    return 0;
  }
  if(n==0)
  {
    cout<<0;
    return 0;
  }
  if(n==2)
  {
    if(l==1 and r==1)
      cout<<1;
    else if(l==1 and r==2)
      cout<<1;
    else if(l==1 and r==3)
      cout<<2;
    else if(l==2 and r==2)
      cout<<0;
    else if(l==2 and r==3)
      cout<<1;
    else if(l==3 and r==3)
      cout<<1;
    return 0;
  }
  FOR(i,2,50)
  {
    pows=2*pows;
    if(n>=pows)
    len=2*pows-1;
    else
    break;
  }
  //cout<<len<<endl;
  solve(n,1,len,l,r);
  cout<<ans;
  return 0;
}