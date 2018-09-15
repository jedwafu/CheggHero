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

unordered_map<string,int> num;
ll dp[5010][5010];
int main(){
  fast;
  string s;
  cin>>s;
  num.clear();
  string temp;
  int last=1;
  for(int i=0;i<sz(s);i++)
  {
    temp="";
    for(int j=i;j<sz(s);i++)
    {
      temp+=s[j];
      if(num[temp]==0)
        num[temp]=last++;
    }
  }

  for(int i=0;i<sz(s);i++)
    dp[i][1]=1;

  for(int i=1;i<sz(s);i++)
  {
    for(int j=2;j<=i+1;j++)
    {
      dp[i][j]=
    }
  }
  return 0;
}