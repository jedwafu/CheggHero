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

int main(){
  fast;
  int n;
  scanf("%d",&n);
  FOR(i,1,n)
  {
  	ll a,b;
  	scanf("%lld %lld",&a,&b);
  	ll num=a*b;
  	ll l=1;
  	ll r=1000000;
  	ll root=0;
  	while(r-l>1)
  	{
  		ll mid=(l+r)/2;
  		if(mid*mid*mid==num)
  		{
  			root=mid;
  			break;
  		}
  		else if(mid*mid*mid < num)
  		{
  			l=mid;
  		}
  		else
  		r=mid;
  	}

  	if(l*l*l==num)
  	{
  		root=l;
  	}
  	else if(r*r*r==num)
  	{
  		root=r;
  	}
  	if(root==0)
  		printf("No\n");
  	else
  	{
  		if(b%root or a%root)
  		{
  			printf("No\n");
  			continue;
  		}

  		ll n1=a/root;
  		ll n2=b/root;
  		ll sqn1=n1*n1;
  		ll sqn2=n2*n2;
  		bool flag1=false;
  		bool flag2=false;
  		if(n2<=a and a%n2==0 and sqn1<=a and a%sqn1==0)
  		flag1=true;
  		if(n1<=b and b%n1==0 and sqn2<=b and b%sqn2==0)
  		flag2=true;

  		if(flag1 and flag2)
  		printf("Yes\n");
  		else
  		printf("No\n");		
  	}
  }
  return 0;
}