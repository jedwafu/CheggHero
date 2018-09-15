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

int a[N];
int prefix1[N];
int prefix2[N];
vector<ii> ans;

bool check1(int pos,int cur,int t)
{
	if(prefix1[cur]-prefix1[pos]>=t)
		return true;

	return false;
}

bool check2(int pos,int cur,int t)
{
	if(prefix2[cur]-prefix2[pos]>=t)
		return true;

	return false;
}

int main()
{
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>a[i];

  prefix1[0]=prefix2[0]=0;
  FOR(i,1,n)
  {
  	if(a[i]==1)
  	{
  		prefix1[i]=prefix1[i-1]+1;
  		prefix2[i]=prefix2[i-1];
  	}
  	else
  	{
  		prefix2[i]=prefix2[i-1]+1;
  		prefix1[i]=prefix1[i-1];
  	}
  }

  FOR(i,1,n)
  {
  	int s1=0,s2=0;
  	int pos=0,tpos1=n+1,tpos2=n+1;
  	while(pos<=n)
  	{
  		int l=pos+1,r=n;
  		tpos1=tpos2=n+1;
 
  		while(r-l>1)
  		{
  			int mid=(l+r)/2;
  			if(check1(pos,mid,i))
  				r=mid;
  			else
  				l=mid;
  		}
  		if(check1(pos,l,i))
  			tpos1=l;
  		else if(check1(pos,r,i))
  			tpos1=r;

  		l=pos+1,r=n;
  		while(r-l>1)
  		{
  			int mid=(l+r)/2;
  			if(check2(pos,mid,i))
  				r=mid;
  			else
  				l=mid;
  		}
  		if(check2(pos,l,i))
  			tpos2=l;
  		else if(check2(pos,r,i))
  			tpos2=r;

  		if(tpos1<tpos2)
  		{
  			if(tpos1==n)
  			{	
  				if(s1+1>s2)
  				ans.pb(mp(s1+1,i));

  				break;
  			}
  			s1++;
  			pos=tpos1;
  		}

  		else if(tpos2<tpos1)
  		{
  			if(tpos2==n)
  			{
  				if(s2+1>s1)
  				ans.pb(mp(s2+1,i));
  				
  				break;
  			}
  			s2++;
  			pos=tpos2;
  		}

  		else
  			break;
  	}
  }

  cout<<sz(ans)<<endl;
  sort(ans.begin(),ans.end());
  FOR(i,0,sz(ans)-1)
  cout<<ans[i].F<<" "<<ans[i].S<<endl; 
  return 0;
}