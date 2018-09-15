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

int arr[N];
int prefix[N];
int partial[N];
string s;

int seg[4*N];
void build(int curr,int l,int r){
  if(l == r){
    seg[curr] = prefix[l];
    return;
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);
  seg[curr]=max(seg[c1],seg[c2]);
}

int query(int curr,int l,int r,int x,int y){
  if(l > y || r < x)return 0;
  if(x <= l && r <= y){
    return seg[curr];
  }

  int c1 = curr<<1,c2 = c1|1,mid = l+r>>1;
  int q = max(query(c1,l,mid,x,y),query(c2,mid+1,r,x,y));
  return q;
}

int main(){
  fast;
  int n,k,p;
  cin>>n>>k>>p;

  FOR(i,1,n)
  cin>>arr[i];

  prefix[1]=0;

  FOR(i,1,min(n,k))
  {
  	prefix[1]+=arr[i];
  	partial[i]=prefix[1];
  }

  if(k>=n)
  {
  	cin>>s;

  	FOR(i,0,sz(s)-1)
  	{
  		if(s[i]=='?')
  		{
  			cout<<prefix[1]<<endl;
  		}
  	}

  	return 0;
  }

  
  FOR(i,2,n-k+1)
  prefix[i]=prefix[i-1]-arr[i-1]+arr[i+k-1];

  int temp=0;
  NFOR(i,n,n-k+2)
  {
    temp+=arr[i];
		prefix[i]=temp+partial[k-n+i-1];
  }

  build(1,1,n);

  cin>>s;
  	
  int cnt=0;

  FOR(i,0,sz(s)-1)
  {
		if(s[i]=='!')
    cnt++;
    
    if(cnt==n)
      cnt=0;

  	if(s[i]=='?')
    {
      if(cnt==0)
        cout<<query(1,1,n,1,n-k+1)<<endl;
      else
      {
        int ans=query(1,1,n,n-cnt+1,min(n,2*n-cnt-k+1));
        if(cnt<n-k+1)
        ans=max(ans,query(1,1,n,1,n-k+1-cnt));
        cout<<ans<<endl;
      }
    }
	}

  return 0;
}