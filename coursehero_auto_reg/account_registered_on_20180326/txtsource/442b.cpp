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

double arr[110];
int main(){
  fast;
  cout<<setprecision(12);
  int n;
  cin>>n;
  FOR(i,0,n-1)
  cin>>arr[i];

  sort(arr,arr+n);
  double val=0;
  int index=n-1;
  NFOR(i,n-1,0)
  {
  	   index=i;
  	   if(arr[i]==1)
  	   {
  	   	cout<<1;
  	   	return 0;
  	   }

       val+=(arr[i]/(1-arr[i]));
       if(val>=1)
       	break;
       
  }
  double t=1,s=0;
  FOR(i,index,n-1)
  {
    s+=arr[i]/(1-arr[i]);
    t*=(1-arr[i]);
  }
  cout<<s*t;
  return 0;
}