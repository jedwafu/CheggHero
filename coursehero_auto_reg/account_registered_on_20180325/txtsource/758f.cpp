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

ll pows(int a,int b)
{
	ll ans=1;
	FOR(i,1,b)
	{
		ans*=a;
		if(ans>mod)
			ans-=mod;
	}

	return ans;
}

int main(){
  fast;
  
  ll n,l,r;
  cin>>n>>l>>r;
  if(n==1)
  {
  	cout<<r-l+1;
    return 0;
  }  
  if(n==2)
  {
  	cout<<(r-l+1)*(r-l);
  	return 0;
  }

  int threshold=0;
  FOR(i,1,r)
  {
  	if(pows(i,n-1)>r)
  	{
  		threshold=i-1;
  		break;
  	}
  }
  //cout<<threshold<<endl;
  ll ans=0;
  FOR(i,1,threshold)
  FOR(j,1,i-1)
  {
  	ll p1=pows(i,n-1);
  	ll p2=pows(j,n-1);

  	if(__gcd(i,j)==1)
  	{
  		ans+=max((ll)0,((r/p1)-((l-1)/p2)));
  	}
  }

  cout<<2*ans;
  return 0;
}