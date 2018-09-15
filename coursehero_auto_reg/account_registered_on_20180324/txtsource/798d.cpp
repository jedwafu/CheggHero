#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;

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
const int N = 1e5+10; 

pair<ii,int> arr[N];

int main(){
  fast;
  int n;
  cin>>n;
 
  FOR(i,1,n)
  {
  	cin>>arr[i].F.F;
  	//totx+=arr[i].F.F;
  }
  FOR(i,1,n)
  {
  	cin>>arr[i].F.S;
  	//toty+=arr[i].F.S;
  	arr[i].S=i;
  }

  sort(arr+1,arr+n+1);
  reverse(arr+1,arr+n+1);

  cout<<(n/2)+1<<endl;

  cout<<arr[1].S<<" ";
  for(int i=2;i<n;i+=2)
  {
  	if(arr[i].F.S>=arr[i+1].F.S)
  		cout<<arr[i].S<<" ";
  	else 
  		cout<<arr[i+1].S<<" ";
  }
  
  if(n%2==0)
  {
  	cout<<arr[n].S;
  }

  return 0;
}