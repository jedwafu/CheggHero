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
const int N = 2e5+10; 

ll arr[N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,1,n)
  cin>>arr[i];

  FOR(i,1,n/2)
  {
  	if(i%2==1)
  	{
  		ll temp=arr[i];
  		arr[i]=arr[n-i+1];
  		arr[n-i+1]=temp;
  	}
  }
  FOR(i,1,n)
  cout<<arr[i]<<" ";
  return 0;
}