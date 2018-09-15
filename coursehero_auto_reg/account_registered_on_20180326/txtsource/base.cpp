// Solution searched from oeis sequence.

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

int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
  	  ll k;
  	  cin>>k;
      if(k==1)
      {	
      	cout<<"INFINITY"<<endl;
      	continue;
      }

      double s=0;
      double n=k;
      double n1=n+.5;
      double n2=(n+.2)/2;
      for(int i=1;i<log(n)/log(2)+1;i++)
  	   {   
  	 	 double j=i;
  	 	 j=1/j;
         s+=floor(pow(n1,j))-floor(pow(n2,j));
  	   }
       ll ans=s;
  	  cout<<ans<<endl;    
   }
  return 0;
}