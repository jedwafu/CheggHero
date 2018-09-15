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

int arr[510];

int main(){
  fast;
  int n,k;
  cin>>n>>k;
  FOR(i,0,n-1)
  cin>>arr[i];
  
  int ans=0;
  FOR(i,1,n-1)
  {
  	if(arr[i]+arr[i-1]<k)
  	{
  		int temp=k-(arr[i]+arr[i-1]);
  		arr[i]+=temp;
  		ans+=temp;
  	}
  }
  cout<<ans<<endl;
  FOR(i,0,n-1)
  cout<<arr[i]<<" ";

  return 0;
}