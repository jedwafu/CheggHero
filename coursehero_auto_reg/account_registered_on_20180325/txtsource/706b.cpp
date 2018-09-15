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
int arr[N];
int main(){
  fast;
  int n;
  cin>>n;
  FOR(i,0,n-1)
  cin>>arr[i];
  
  int q;
  cin>>q;
  sort(arr,arr+n);

  FOR(i,1,q)
  {
  	int m;
  	cin>>m;
  	int l=0;
  	int r=n-1;
  	while(r-l>1)
  	{
  		int mid=(r+l)/2;
  		if(arr[mid]>m)
  			r=mid;
  		else
  			l=mid;
  	}
  	if(arr[r]<=m)
  		cout<<r+1<<endl;
  	else if(arr[l]<=m)
  		cout<<l+1<<endl;
  	else
  		cout<<0<<endl;
  }
  return 0;
} 