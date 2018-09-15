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

char arr[510][510];
ll dp[510][510];
ll ver[510][510];
ll hor[510][510];
ll aux[510][510];
int main(){
  fast;
  int h,w;
  cin>>h>>w;
  
  FOR(i,1,h)
  FOR(j,1,w)
  cin>>arr[i][j];
  
  dp[0][0]=0;
  hor[0][0]=ver[0][0]=aux[0][0]=0;
  hor[1][1]=ver[1][1]=aux[1][1]=0;

  dp[1][1]=0;

  FOR(i,2,w)
  if(arr[1][i-1]=='.' and arr[1][i]=='.')
  	dp[1][i]=dp[1][i-1]+1,hor[1][i]=hor[1][i-1]+1;
  else
  	dp[1][i]=dp[1][i-1],hor[1][i]=dp[1][i-1];
  
  FOR(i,2,h)
  if(arr[i][1]=='.' and arr[i-1][1]=='.')
  	dp[i][1]=dp[i-1][1]+1,ver[i][1]=1;
  else
  	dp[i][1]=dp[i-1][1],ver[i][1]=0;

  FOR(i,1,max(w,h))
  dp[i][0]=dp[0][i]=hor[i][0]=hor[0][i]=ver[0][i]=ver[i][0]=aux[i][0]=aux[0][i]=aux[i][1]=0;

  FOR(i,2,h)
  {

  	  FOR(j,2,w)
      {
         if(arr[i][j]=='.' and arr[i][j-1]=='.')
         	hor[i][j]=hor[i][j-1]+1;
         else
         	hor[i][j]=hor[i][j-1];
         
         if(arr[i][j]=='.' and arr[i-1][j]=='.')
           ver[i][j]=ver[i][j-1]+1;
         else
         	ver[i][j]=ver[i][j-1];  	

         dp[i][j]=dp[i-1][j]+hor[i][j]+ver[i][j];
      } 
  }
  
  FOR(i,2,w)
  if(arr[1][i]=='.' and arr[1][i-1]=='.')
  	aux[1][i]=1;
  else
  	aux[1][i]=0;

  FOR(i,2,h)
  FOR(j,2,w)
  {
  	if(arr[i][j]=='.' and arr[i][j-1]=='.')
  		aux[i][j]=aux[i-1][j]+1;
  	else
  		aux[i][j]=aux[i-1][j];
  }

/*  cout<<"hor"<<endl;
  FOR(i,1,h)
  {
  	FOR(j,1,w)
  	cout<<hor[i][j]<<" ";
  	cout<<endl;
  }

  cout<<"ver"<<endl;
  FOR(i,1,h)
  {
  	FOR(j,1,w)
  	cout<<ver[i][j]<<" ";
  	cout<<endl;
  }

  cout<<"aux"<<endl;
  FOR(i,1,h)
  {
  	FOR(j,1,w)
  	cout<<aux[i][j]<<" ";
  	cout<<endl;
  }
*/
  int q;
  cin>>q;
  FOR(i,1,q)
  {
  	int r1,r2,c1,c2;
  	cin>>r1>>c1>>r2>>c2;
  	cout<<dp[r2][c2]-dp[r1-1][c2]-dp[r2][c1-1]+dp[r1-1][c1-1]-(ver[r1][c2]-ver[r1][c1-1])-(aux[r2][c1]-aux[r1-1][c1])<<endl;
  }

  return 0;
}