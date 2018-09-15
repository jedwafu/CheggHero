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

int n;
ll h[N];
ll prefix[N];
int maxleft[N];
int maxright[N];

void calcright()
{
	int right=n;
  	maxright[1]=n;
  	FOR(i,1,n)
  	{
  		if(h[i]<i)
  			{
  				maxright[1]=i-1;
  				right=i-1;
  				break;
  			}	
  	}

  	FOR(i,2,n)
  	{
  		int cur = maxright[i-1]-1;
  		
  		if(right < i)
  		{
  			cur=1;
  			right=i;
  		}

  		while(right <= n)
  		{
  			if(h[right]<cur)
  			{
  				maxright[i]=cur-1;
  				right=right-1;
  				break;
  			}

  			right++;
  			cur++;
  		}
  	}	
}

void calcleft()
{
	int left=1;
  	maxleft[n]=n;

  	NFOR(i,n,1)
  	{
  		if(h[i]<(n-i+1))
  			{
  				maxleft[n]=(n-i);
  				left=i+1;
  				break;
  			}	
  	}

  	NFOR(i,n-1,1)
  	{
  		int cur = maxleft[i+1]-1;
  		
  		if(left > i)
  		{
  			cur=1;
  			left=i;
  		}

  		while(left >= 1)
  		{
  			if(h[left]<cur)
  			{
  				maxleft[i]=cur-1;
  				left=left+1;
  				break;
  			}

  			left--;
  			cur++;
  		}
  	}	
}

ll req(int left,int right,ll val)
{
	return prefix[n]-((val)*(val));
}

ll check(ll val)
{	
	ll ans=INF;

	FOR(i,1,n)
	{

		if( (i+2*(val-1)) <= n and maxright[i] >= val and maxleft[i+2*(val-1)] >= val)
			ans=min(ans,req(i,i+2*(val-1),val));
	}

	if(ans==INF)
	return -1;
		
	else
		return ans;
}

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	cin>>n;

  	FOR(i,1,n)
  	{
  		maxright[i]=n-i+1;
  		maxleft[i]=i;
  	}

  	FOR(i,1,n)
  	cin>>h[i];


  	prefix[0]=0;
  	FOR(i,1,n)
  	prefix[i]=prefix[i-1]+h[i];
  	prefix[n+1]=prefix[n];

	calcright();
	calcleft();

	ll l=1;
	ll r=1000000000;

	while(r-l>1)
	{
		ll mid = (l+r)/2;
		if(check(mid)!=-1)
			l=mid;
		else
			r=mid;
	}

	if(check(r)!=-1)
		cout<<check(r)<<endl;
	else
		cout<<check(l)<<endl;
  }

  return 0;
}