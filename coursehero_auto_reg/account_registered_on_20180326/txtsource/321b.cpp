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
int n,m;
vi atk;
vi def;
vi arr;
int dp[110][110][110][2];

int DP(int i1,int i2,int i3,bool skip)
{
       
      if(i1>=sz(def) and i2>=sz(atk) and skip)
	  	return 0;

      if(dp[i1][i2][i3][skip]+1)
      	return dp[i1][i2][i3][skip];

      if(i3>=m)
      	return 0;

      if(i1>=sz(def) and i2>=sz(atk))
      {
      	dp[i1][i2][i3][0]=arr[i3]+DP(i1,i2,i3+1,skip);
      	return dp[i1][i2][i3][0];
      }

      if(i1>=sz(def))
      {
      	int k=1;
        dp[i1][i2][i3][skip]=max(dp[i1][i2][i3][skip],(arr[i3]-atk[i2]+DP(i1,i2+1,i3+1,skip))*(arr[i3]>=atk[i2]));
        while(i2+k<sz(atk))
        {
      	dp[i1][i2][i3][skip]=max(dp[i1][i2][i3][skip],(arr[i3]-atk[i2+k]+DP(i1,i2+k+1,i3+1,1))*(arr[i3]>=atk[i2+k]));
      	k++;
        }
        return dp[i1][i2][i3][skip];
      }

      if(i2>=sz(atk))
      { 
      	if(skip)
      		return 0;

      	if(arr[i3]>def[i1])
      	{
      		dp[i1][i2][i3][skip]=DP(i1+1,i2,i3+1,skip);
      		return dp[i1][i2][i3][skip];
      	}
      	else
      	{
      		dp[i1][i2][i3][skip]=0;
      		return 0;
      	}
      }

        int k=1;
        dp[i1][i2][i3][skip]=max(dp[i1][i2][i3][skip],(arr[i3]-atk[i2]+DP(i1,i2+1,i3+1,skip))*(arr[i3]>=atk[i2]));
        while(i2+k<sz(atk))
        {
      	dp[i1][i2][i3][skip]=max(dp[i1][i2][i3][skip],(arr[i3]-atk[i2+k]+DP(i1,i2+k+1,i3+1,1))*(arr[i3]>=atk[i2+k]));
      	k++;
        }
      

      dp[i1][i2][i3][skip]=max(DP(i1+1,i2,i3+1,skip)*(arr[i3]>def[i1]),dp[i1][i2][i3][skip]);
      return dp[i1][i2][i3][skip];
}
int main(){
  fast;
  
  cin>>n>>m;
  fill(dp,-1);
  FOR(i,1,n)
  {
     string s;
     int c;
     cin>>s>>c;
     if(s=="ATK")
     	atk.pb(c);
     else
     	def.pb(c);
  }
  FOR(i,1,m)
  {
  	int c;
  	cin>>c;
  	arr.pb(c);
  }
  sort(atk.begin(),atk.end());
  sort(def.begin(),def.end());
  sort(arr.begin(),arr.end());
  reverse(arr.begin(),arr.end());
  reverse(def.begin(),def.end());
  reverse(atk.begin(),atk.end());
 
 /* FOR(i,0,sz(atk)-1)
  cout<<atk[i]<<endl;
  FOR(i,0,sz(def)-1)
  cout<<def[i]<<endl;
  FOR(i,0,sz(arr)-1)
  cout<<arr[i]<<endl;
  cout<<DP(0,0,0,0);
  */
  return 0;
}