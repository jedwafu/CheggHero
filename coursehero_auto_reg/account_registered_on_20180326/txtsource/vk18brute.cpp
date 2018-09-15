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
  int t;
  cin>>t;
  while(t--)
  {
  	int n;
  	cin>>n;
  	ll ans=0;

  	for(int i=1;i<=n;i++)
  	for(int j=1;j<=n;j++)
  	{
  		int num=i+j;
  		ll odd=0;
  		ll even=0;

  		while(num)
  		{
  			if((num%10)%2)
  			odd+=num%10;
  			else
  			even+=num%10;
  			num/=10;
  		}

  		ans+=abs(odd-even);
  	}
  	cout<<ans<<endl;
  }

  return 0;
}