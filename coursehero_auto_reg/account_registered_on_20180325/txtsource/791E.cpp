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
const ll INF = 1e9;
const ll mod = 1e9+7;
const int N = 80; 

string s;

int dp[N][N][N][4];
int tv=0,tk=0,tx=0;

int swaps(int p1,int p2,int p3,int val)
{
	int ans=0;
	int v=0,k=0,x=0;
	FOR(i,0,sz(s)-1)
	{
		if(s[i]=='V')
		{
			if(v==p1 and val==1)
				return ans;
			else if(v==p1)
				ans++;
			else
				v++;
		}
		else if(s[i]=='K')
		{
			if(k==p2 and val==2)
				return ans;
			else if(k==p2)
				ans++;
			else
				k++;
		}
		else
		{
			if(x==p3 and val==3)
				return ans;
			else if(x==p3)
				ans++;
			else
				x++;
		}
	}
}

int DP(int p1,int p2,int p3,int last)
{
	if(p1>tv or p1<0 or p2>tk or p2<0 or p3>tx or p3<0)
		return INF;

	if(dp[p1][p2][p3][last]!=-1)
		return dp[p1][p2][p3][last];

	int ans=INF;

	//cout<<"visiting state "<<p1<<" "<<p2<<" "<<p3<<" "<<last<<endl;
	if(last==1)
	{
		int temp=swaps(p1-1,p2,p3,1);
		ans=min(ans,DP(p1-1,p2,p3,1)+temp);
		ans=min(ans,DP(p1-1,p2,p3,2)+temp);
		ans=min(ans,DP(p1-1,p2,p3,3)+temp);
	}
	else if(last==2)
	{
		int temp=swaps(p1,p2-1,p3,2);
		//cout<<"swaps "<<p1<<" "<<p2-1<<" "<<p3<<" is "<<temp<<endl;
		ans=min(ans,DP(p1,p2-1,p3,2)+temp);
		ans=min(ans,DP(p1,p2-1,p3,3)+temp);
	}
	else
	{
		int temp=swaps(p1,p2,p3-1,3);
		ans=min(ans,DP(p1,p2,p3-1,1)+temp);
		ans=min(ans,DP(p1,p2,p3-1,2)+temp);
		ans=min(ans,DP(p1,p2,p3-1,3)+temp);
	}

	dp[p1][p2][p3][last]=ans;
	//cout<<"answer for "<<p1<<" "<<p2<<" "<<p3<<" "<<last<<" is "<<ans<<endl;
	return ans;
}

int main(){
  fast;
  int n;
  cin>>n;
  cin>>s;
  fill(dp,-1);
  FOR(i,0,sz(s)-1)
  {
  	if(s[i]=='V')
  		tv++;
  	else if(s[i]=='K')
  		tk++;
  	else
  		tx++;
  }

  dp[0][0][0][1]=dp[0][0][0][2]=dp[0][0][0][3]=0;
  if(s[0]=='V')
  	dp[1][0][0][1]=0;
  else if(s[0]=='K')
  	dp[0][1][0][2]=0;
  else
  	dp[0][0][1][3]=0;

  int ans=min(DP(tv,tk,tx,1),DP(tv,tk,tx,2));
  ans=min(ans,DP(tv,tk,tx,3));
  cout<<ans;
  return 0;
}