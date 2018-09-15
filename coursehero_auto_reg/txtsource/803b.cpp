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
const ll mod = 1e6+7;
const int N = 2e5+10; 

int arr[N];
int lft[N];
int rght[N];
int main()
{
  fast;
  int n;
  cin>>n;

  FOR(i,1,n)
  cin>>arr[i];
  
  if(arr[1]==0)
  	lft[1]=0;
  else
  	lft[1]=mod;

  FOR(i,2,n)
  {
  	if(arr[i]==0)
  		lft[i]=0;
  	else
  		lft[i]=1+lft[i-1];
  }

  if(arr[n]==0)
  	rght[n]=0;
  else
  	rght[n]=mod;

  NFOR(i,n-1,1)
  {
  	if(arr[i]==0)
  		rght[i]=0;
  	else
  		rght[i]=1+rght[i+1];
  }
  
  FOR(i,1,n)
  cout<<min(lft[i],rght[i])<<" ";
  
  return 0;
}