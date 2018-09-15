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

ll dp[N];
ll mini[N];
ll tms[N];

ll calc(int index)
{
	ll times=tms[index];
	if(index==1)
		return 20;

	if(index==2)
		return 40;

	if(index>=3)
	{
		ll ans=20*index;

		int l=1;
		int r=index;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(tms[mid]>=times-1439)
				r=mid;
			else
				l=mid;
		}

		if(tms[l]>=times-1439)
			ans=min(ans,mini[l-1]+120);
		
		else if(tms[r]>=times-1439)
		ans=min(ans,mini[r-1]+120);

		l=1;
		r=index;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(tms[mid]>=times-89)
				r=mid;
			else
				l=mid;
		}
		
		if(tms[l]>=times-89)
			ans=min(ans,mini[l-1]+50);
		else if(tms[r]>=times-89)
		ans=min(ans,mini[r-1]+50); 

		ans=min(ans,mini[index-1]+20);
		return ans;
	}
}

int main()
{
  fast;
  
  int n;
  cin>>n;

  FOR(i,1,n)
  cin>>tms[i];


  dp[0]=0;
  mini[0]=0;
  mini[1]=20; 
  ll sums=0;
  
  FOR(i,1,n)
  {
  	mini[i]=calc(i);
  	dp[i]=mini[i]-sums;
  	sums+=dp[i];
  }

  FOR(i,1,n)
  cout<<dp[i]<<endl;
  return 0;
}