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

vector<pair<int,ii> > arr;
int span[N];
ll dp[N];
void calc(int n)
{
	stack<int> st;
	st.push(n-1);
	span[n-1]=-1;
	NFOR(i,n-2,0)
	{
		
		while (!st.empty() && arr[st.top()].S.F >= arr[i].F)
         st.pop();

     	span[i] = (st.empty())? (-1) : (st.top());

		while (!st.empty() && arr[st.top()].S.F >= arr[i].S.F)
         st.pop();

     	st.push(i);
	}
}

int main(){
  fast;
  int n;
  cin>>n;
  fill(span,0);
  fill(dp,0);
  FOR(i,1,n)
  {
  	int a,b,h;
  	cin>>a>>b>>h;
  	arr.pb(mp(b,mp(a,h)));
  }

  sort(arr.begin(),arr.end());
  calc(n);
  NFOR(i,n-1,0)
  {
  	if(span[i]==-1)
  		dp[i]=arr[i].S.S;
  	else
  		dp[i]=dp[span[i]]+arr[i].S.S;
  }

  ll ans=0;
  FOR(i,0,n-1)
  ans=max(ans,dp[i]);
  cout<<ans;
  return 0;
}