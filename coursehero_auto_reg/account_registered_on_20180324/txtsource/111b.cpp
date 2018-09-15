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

int last[N];
int main(){
  fast;
  int n;
  cin>>n;
  fill(last,0);
  int x,y;
  int ans=0;
  FOR(i,1,n)
  {
  	ans=0;
  	cin>>x>>y;
  	int root=sqrt(x);
  	for(int j=1;j<=root;j++)
  	{
  		if(x%j==0)
  		{
            int other=x/j;
            if(last[j]<i-y)
            	ans++;
            if(last[other]<i-y and other!=j)
            	ans++;

            last[j]=last[other]=i;
  		}
  	}
  	cout<<ans<<endl;
  }
  return 0;
}