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

char dp[N];
int val[10];
int len[2][N];

char DP(int k,bool first)
{
	if(k<=1)
		return '-';

	if(!first and k==6)
		{
			len[0][k]=1;
			return dp[k]='0';
		}
	if(first and k==6)
		{
			len[1][k]=1;
			return dp[k]='6';
		}

	if(k==2)
		{
			len[first][k]=1;
			return dp[k]='1';
		}
	if(k==3)
		{
			len[first][k]=1;
			return dp[k]='7';
		}
	if(k==4)
	{
		len[first][k]=1;
		return dp[k]='4';
	}
	if(k==5)
	{
		len[first][k]=1;
		return dp[k]='2';
	}
	if(k==7)
	{
		len[first][k]=1;
		return dp[k]='8';
	}
	
	if(dp[k]!='+')
		return dp[k];

	char index='-';
	int minlength=mod;
	if(first)
	{
		if(DP(k-2,false)!='-' and len[0][k-2]<minlength)
		{
			index='1';
			minlength=len[0][k-2];
		}
		if(DP(k-5,false)!='-' and len[0][k-5]<minlength)
		{
			index='2';
			minlength=len[0][k-5];
		}
		if(DP(k-4,false)!='-' and len[0][k-4]<minlength)
		{
			index='4';
			minlength=len[0][k-4];
		}
		if(DP(k-6,false)!='-' and len[0][k-6]<minlength)
		{
			index='6';
			minlength=len[0][k-6];
		}
		if(DP(k-3,false)!='-' and len[0][k-3]<minlength)
		{
			index='7';
			minlength=len[0][k-3];
		}
		if(DP(k-7,false)!='-' and len[0][k-7]<minlength)
		{
			index='8';
			minlength=len[0][k-7];
		}

			len[1][k]=1+minlength;
			return dp[k]=index;
	}

	else
	{
		if(DP(k-6,false)!='-' and len[0][k-6]<minlength)
		{
			index='0';
			minlength=len[0][k-6];
		}

		if(DP(k-2,false)!='-' and len[0][k-2]<minlength)
		{
			index='1';
			minlength=len[0][k-2];
		}
		if(DP(k-5,false)!='-' and len[0][k-5]<minlength)
		{
			index='2';
			minlength=len[0][k-5];
		}
		if(DP(k-4,false)!='-' and len[0][k-4]<minlength)
		{
			index='4';
			minlength=len[0][k-4];
		}
		
		if(DP(k-3,false)!='-' and len[0][k-3]<minlength)
		{
			index='7';
			minlength=len[0][k-3];
		}
		if(DP(k-7,false)!='-' and len[0][k-7]<minlength)
		{
			index='8';
			minlength=len[0][k-7];
		}

			len[0][k]=1+minlength;
			return dp[k]=index;
	}
}

int main()
{
  fast;
  for(int i=0;i<N;i++)
  	{
  		dp[i]='+';
  		len[0][i]=len[1][i]=-1;
  	}

  val[0]=6;
  val[1]=2;
  val[2]=5;
  val[4]=4;
  val[6]=6;
  val[7]=3;
  val[8]=7;

  int k;
  cin>>k;
  if(k==6)
  	return 0;
  if(DP(k,true)=='+' or DP(k,true)=='-')
  	cout<<-1;
  else
  	{
  		string ans="";
  		while(k>1)
  		{
  			ans+=dp[k];
  			k=k-val[dp[k]-'0'];
  		}
  		cout<<ans<<endl;
  	}
  return 0;
}