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
const int N = 7e4+10; 

int n;
int rity[2][N];
int dp[2][N];
int k[2];
int cnt[2][N];

queue<ii> q;

int main(){
  fast;
  
  fill(dp,-1);
  fill(cnt,0);
  cin>>n;
  cin>>k[0];

  FOR(i,1,k[0])
  cin>>rity[0][i];
  

  cin>>k[1];
  
  FOR(i,1,k[1])
  cin>>rity[1][i];

 
  dp[0][1]=dp[1][1]=0;


  q.push(mp(0,1));
  q.push(mp(1,1));

  while(!q.empty())
  {
  	int st=q.front().F;
  	int pos=q.front().S;
  	q.pop();

  	if(dp[st][pos]==0)
  	{
  		FOR(i,1,k[1-st])
  		{
  			if(dp[1-st][pos-rity[1-st][i]<=0 ? pos-rity[1-st][i]+n : pos-rity[1-st][i]]!=-1)
  				continue;
  			dp[1-st][pos-rity[1-st][i]<=0 ? pos-rity[1-st][i]+n : pos-rity[1-st][i]]=1;
			q.push(mp(1-st,pos-rity[1-st][i]<=0 ? pos-rity[1-st][i]+n : pos-rity[1-st][i]));
  		}
  	}

  	else
  	{
  		FOR(i,1,k[1-st])
  		{
  			cnt[1-st][pos-rity[1-st][i]<=0 ? pos-rity[1-st][i]+n : pos-rity[1-st][i]]++;
			if(cnt[1-st][pos-rity[1-st][i]<=0 ? pos-rity[1-st][i]+n : pos-rity[1-st][i]]==k[1-st])
			{
				dp[1-st][pos-rity[1-st][i]<=0 ? pos-rity[1-st][i]+n : pos-rity[1-st][i]]=0;
				q.push(mp(1-st,pos-rity[1-st][i]<=0 ? pos-rity[1-st][i]+n : pos-rity[1-st][i]));
			}				
  		}
  	}
  }

  FOR(i,0,1)
  {
  	FOR(j,2,n)
  	{
  		int temp=dp[i][j];
	  	if(temp==1)
  			cout<<"Win ";
  		if(temp==0)
  			cout<<"Lose ";
  		if(temp==-1)
  			cout<<"Loop ";		
  	}
  	cout<<endl;
  }
  return 0;
}