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
const int N = 1e3+10; 
queue< pair<int,int> > st;
int r,c;
ll dp[N][N];
int num[N][N];

void calc(int x,int y)
{
	st.push(mp(x,y));
	while(!st.empty())
	{

		int a=st.front().F;
		int b=st.front().S;
        st.pop();
		
		if(a+1<r and dp[a+1][b]==INF and num[a+1][b]!=-1)
		{
			dp[a+1][b]=1+dp[a][b]; 
			st.push(mp(a+1,b));
		}
		if(a-1>=0 and dp[a-1][b]==INF and num[a-1][b]!=-1)
		{
			dp[a-1][b]=1+dp[a][b]; 
			st.push(mp(a-1,b));
		}
		if(b+1<c and dp[a][b+1]==INF and num[a][b+1]!=-1)
		{
			dp[a][b+1]=1+dp[a][b]; 
			st.push(mp(a,b+1));
		}
		if(b-1>=0 and dp[a][b-1]==INF and num[a][b-1]!=-1)
		{
			dp[a][b-1]=1+dp[a][b]; 
			st.push(mp(a,b-1));
		}
	}
}

int main(){
  fast;
  cin>>r>>c;
  string s;
  int s1,s2,e1,e2;
  FOR(i,0,r-1)
  {
  	cin>>s;
  	FOR(j,0,c-1)
  	{
  		dp[i][j]=INF;
  		num[i][j]=0;

  		if(s[j]=='T')
  		num[i][j]=-1;
  		
  		else if(s[j]=='S')
  	     s1=i,s2=j;
  		
  		else if(s[j]=='E')
  		{
  			dp[i][j]=0;
  			e1=i,e2=j;
  		}
        
        else
        	num[i][j]=s[j]-'0';
  	}
  }
  
  ll ans=0;
  calc(e1,e2);
  int val=dp[s1][s2];
  FOR(i,0,r-1)
  FOR(j,0,c-1)
  {
  	//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
  	if(dp[i][j]<=val)
  		ans+=num[i][j];
  }
  cout<<ans;
  return 0;
}