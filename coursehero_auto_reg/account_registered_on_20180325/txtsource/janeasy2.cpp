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

int dp[N];
int main(){
  fast;
  int t;
  cin>>t;
  string s1,s;
  while(t--)
  {
  	int k;
  	cin>>k;
  	cin>>s1;
    s='0';
    s=s+s1;
    int sum=0;
    int temp0=1;
    int temp1=0;
    int temp2=0;
  	FOR(i,1,k)
  	{
       sum+=s[i]-'0';
       if(sum%3==0)
       {
          dp[i]=temp0;
          temp0++;
       }
       else if(sum%3==1)
       {
       	dp[i]=temp1;
       	temp1++;
       }
       else
       {
       	dp[i]=temp2;
       	temp2++;
       }

       if((s[i]-'0')%3==0)
          	dp[i]--;
       if(i>1 and ((s[i]-'0')+(s[i-1]-'0'))%3==0)
          	dp[i]--;

          //cout<<i<<" "<<dp[i]<<endl;
  	}
    
    ll ans=0;
  	FOR(i,1,k)
  	{
  		int num=s[i]-'0';
  		//cout<<num<<endl;
       if((num%8)==0 and (num%3))
       	ans++;
  	}

  	FOR(i,1,k-1)
  	{
  		int num=(s[i]-'0')*10;
  		num+=s[i+1]-'0';
  		//cout<<num<<endl;
  		if((num%3)  and (num%8)==0)
  			ans++;
  	}

  	FOR(i,1,k-2)
  	{
  		int num=(s[i]-'0')*100;
  		num+=(s[i+1]-'0')*10;
  		num+=s[i+2]-'0';
  		//cout<<num<<endl;
  		if(num%8==0)
  		{
  			//cout<<ans<<endl;
  			ans+=i-dp[i+2];
  		}
  	}

  	cout<<ans<<endl;
  }
  return 0;
}