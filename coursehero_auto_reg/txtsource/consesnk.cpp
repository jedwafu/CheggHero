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

ll s[N];
ll val[N];
ll n,l,a,b;

ll check(ll value)
{
	ll temp=0;
  	ll st=value;
  	if(st < a)
  		st=a;
  	if(st > b - n*l)
  		st=b-n*l;

  	FOR(i,1,n)
  	temp+=abs(st-val[i]);

  	return temp;
}

int main()
{
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	ll ans=0;  	
  	cin>>n>>l>>a>>b;
  	FOR(i,1,n)
  	{
  		cin>>s[i];
  		if(s[i]<a)
  		{
  			ans+=a-s[i];
  			s[i]=a;
  		}
  		if(s[i]>b)
  		{
  			ans+=s[i]-b;
  			s[i]=b;
  		}
  	}

  	sort(s+1,s+n+1);
  	
  	FOR(i,1,n)
  	val[i]=s[i]-(i-1)*l;

  	sort(val+1,val+n+1);
  	if(n>1)
  	cout<<ans+min(check(val[n/2]),check(val[n/2+1]))<<endl;
  	else
  	cout<<ans+check(val[1])<<endl;

  }  

  return 0;
}