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

ll c[N];
ll dp[2][N];
string s1,s2;

bool check(string a,string b)
{
	//cout<<"here"<<endl;
	int len=min(sz(a),sz(b));
	//cout<<len<<endl;
	FOR(i,0,len-1)
	{
		//cout<<a[i]-'a'<<" ";
		//cout<<b[i]-'a'<<endl;
		if(a[i]-'a'< b[i]-'a')
			return true;
		if(b[i]-'a'<a[i]-'a')
			return false;
	}

	if(sz(a)>sz(b))
		return false;

	return true;
}

int main(){
  fast;
  FOR(i,0,N-1)
  dp[0][i]=dp[1][i]=INF;

  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>c[i];
  

  FOR(i,1,n)
  {
  	cin>>s2;
  	if(i==1)
  	{
  		dp[0][1]=0;
  		dp[1][1]=c[1];
  	}
  	else
  	{
  		string temp1=s1;
  		string temp2=s2;
  		//cout<<temp1<<" "<<temp2<<endl;
  		if(check(temp1,temp2))
  			{
  				//cout<<dp[0][i]<<" "<<i<<endl;
  				dp[0][i]=min(dp[0][i],dp[0][i-1]);
  			}
  		reverse(temp1.begin(),temp1.end());
  		if(check(temp1,temp2))
  			{
  				//cout<<dp[0][i]<<" "<<i<<endl;
  				dp[0][i]=min(dp[0][i],dp[1][i-1]);
  			}
  		reverse(temp2.begin(),temp2.end());
  		if(check(temp1,temp2))
  			dp[1][i]=min(dp[1][i],c[i]+dp[1][i-1]);
  		reverse(temp1.begin(),temp1.end());
  		if(check(temp1,temp2))
  			dp[1][i]=min(dp[1][i],c[i]+dp[0][i-1]);
  	}
  	s1=s2;
  	//cout<<"here"<<endl;
  }
  ll ans=min(dp[1][n],dp[0][n]);
  if(ans>=INF)
  	cout<<-1;
  else
  cout<<ans;
  return 0;
}