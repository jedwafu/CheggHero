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

ll arr[N];
int main(){
  fast;
  ll ts,tf,t;
  ll ans=0;
  ll ansindex=0;
  int n;
  cin>>ts>>tf>>t;
  cin>>n;
  FOR(i,1,n)
  cin>>arr[i];

  ans=ts;
  ansindex=0;

  arr[0]=-1;

  ll endtime=ts;
  
  FOR(i,1,n)
  {
  	if(arr[i]==arr[i-1])
  	endtime+=t;
  	
  	else
  	{
  		if(endtime+t>tf or (arr[i]-1+t)>tf)
  		{
        //endtime+=t;
        continue;
      }
  		else
  		{
  			if(max((ll)0,endtime-(arr[i]-1))<=ans)
  			{
  				ans=max((ll)0,endtime-(arr[i]-1));
  				ansindex=arr[i]-1;
  			}
  			endtime=max(endtime+t,arr[i]+t);
        //cout<<i<<" "<<endtime<<endl;
  		}
  	}

  }

  if(endtime+t<=tf)
    ansindex=endtime;

  cout<<ansindex;
  return 0;
}