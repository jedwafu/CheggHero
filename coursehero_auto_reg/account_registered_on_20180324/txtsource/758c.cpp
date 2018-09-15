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

ll arr[110][110];
int main(){
  fast;
  ll n,m;
  ll k;
  ll x,y;
  cin>>n>>m>>k>>x>>y;
  fill(arr,0);

  if(n==1)
  {	
  	ll equal=k/m;
  	FOR(i,1,n)
  	FOR(j,1,m)
  	arr[i][j]=equal;

  	ll rem=k%m;
  	if(rem<0)
  		rem+=m;

  	FOR(j,1,rem)
  	arr[1][j]++;
  }
/*  else if(n==2)
  {
  	ll equal=k/(2*m);
  	FOR(i,1,n)
  	FOR(j,1,m)
  	arr[i][j]=equal;

  	ll rem=k%(2*m);
  	if(rem<0)
  		rem+=(2*m);
    
    ll cnt=0;
  	FOR(i,1,n)
  	FOR(j,1,m)
  	{
  		if(cnt==rem)
  		{
  			i=n+1;
  			break;
  		}

  		arr[i][j]++;
  		cnt++;

  	}

  }*/

  else
  {

  ll equal=k/((2*m*n)-(2*m));

  FOR(i,1,n)
  FOR(j,1,m)
  {
  	if(i==1 or i==n)
  	arr[i][j]=equal;
    else
    arr[i][j]=2*equal;
  }

  ll rem=k%((2*m*n)-(2*m));
  if(rem<0)
  	rem+=(2*m*n)-(2*m);

  ll cnt=0;

  if(rem<=m*n)
  {
  	FOR(i,1,n)
  	FOR(j,1,m)
  	{
  		if(cnt==rem)
  		{
  			i=n+1;
  			break;
  		}
  		arr[i][j]++;
  		cnt++;
  		
  	}
  }

  else
  {
  	FOR(i,1,n)
  	FOR(j,1,m)
  	{
  		arr[i][j]++;
  	}

  	rem-=(m*n);

    NFOR(i,n-1,1)
    FOR(j,1,m)
    {
    	if(cnt==rem)
    	{
    		i=0;
    		break;
    	}
    	arr[i][j]++;
    	cnt++;
    }
  }
  }


  ll mini=k;
  ll maxi=0;
  FOR(i,1,n)
  FOR(j,1,m)
  {
  	mini=min(mini,arr[i][j]);
  	maxi=max(maxi,arr[i][j]);
  }

  cout<<maxi<<" "<<mini<<" "<<arr[x][y];
  return 0;
}