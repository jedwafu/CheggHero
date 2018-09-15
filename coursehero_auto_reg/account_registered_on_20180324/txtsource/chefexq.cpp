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
int main()
{
  fast;
  int n,q;
  cin>>n>>q;
  

  FOR(i,1,n)
  cin>>arr[i];

  FOR(t,1,q)
  {
  	int typ,i,x;
  	cin>>typ>>i>>x;
  	
  	if(typ==1)
  	arr[i]=x;
  	
  	if(typ==2)
  	{
  		int xorval=0;
  		int ans=0;
  		for(int j=1;j<=i;j++)
  		{
  			xorval^=arr[j];
  			if(xorval==x)
  			ans++;
  		}
  		cout<<ans<<endl;
  	}
  }

  return 0;
}