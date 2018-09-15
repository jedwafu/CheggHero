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
const ll INF = 1e18+10;
const ll mod = 1e9+7;
const int N = 1e5+10; 
 
int arr[100010];
bool seen[2010];
ll cost[2010];
ll ans[100010];
 
int main(){
  fast;
  int n;
  cin>>n;
  
  FOR(i,0,n-1)
  cin>>arr[i];
  
  FOR(i,0,2009)
  cost[i]=INF,seen[i]=false;
 
  ll mini=INF;
  ll temp=0;
 
  cost[arr[0]+1000]=0;
  seen[arr[0]+1000]=true;
  ans[0]=0;
 
  FOR(i,1,n-1)
  {
    mini=INF;
    FOR(j,0,2000)
    {
       if(seen[j])
       {        
          temp=i*(j-1000);
          temp*=(temp+1);
          temp+=cost[j];
          mini=min(mini,temp);   
       }
    }
    
    seen[arr[i]+1000]=true;
 
    temp=i*arr[i];
    temp*=(temp+1);
    mini-=temp;
    ans[i]=mini;
 
    cost[arr[i]+1000]=min(cost[arr[i]+1000],ans[i]);
 
  }
 
  temp=(n-1)*(arr[n-1]);
  temp*=(temp+1);
  ans[n-1]+=temp;
  
  cout<<ans[n-1]<<endl;
 
  return 0;
} 