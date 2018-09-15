#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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

vi arr1[N];
vi arr2[N];
int main(){
  fast;
  int t;
  cin>>t;

  while(t--){
  	int n,m;
  	cin>>n>>m;
  	bool mainflag=true;
  	ll ans=0;
  FOR(i,0,n-1)
  FOR(j,0,m-1)
  {
  	ll temp;
  	cin>>temp;
  	arr1[i].pb(temp);
  }
  FOR(i,0,n-1)
  FOR(j,0,m-1)
  {
  	ll temp;
  	cin>>temp;
  	arr2[i].pb(temp);
  }

  FOR(i,0,n-1)
  {
  	if(arr1[i][0]<arr2[i][0])
  	{
  		bool flag=true;
  		ll mindif=arr2[i][0]-arr1[i][0];
  		FOR(j,1,m-1)
  		{
  			if(arr1[i][j]>=arr2[i][j])
  				{
  					flag=false;
  					break;
  				}
  			else
  			{
  				mindif=min(mindif,arr2[i][j]-arr1[i][j]);
  			}
  		}
  		if(flag)
  		{
  			ans+=mindif;
  			FOR(j,0,m-1)
  			arr1[i][j]+=mindif;
  		}	
    }
    else if(arr2[i][0]<arr1[i][0])
    {
    	bool flag=true;
  		ll mindif=arr1[i][0]-arr2[i][0];
  		FOR(j,1,m-1)
  		{
  			if(arr2[i][j]>=arr1[i][j])
  				{
  					flag=false;
  					break;
  				}
  			else
  			{
  				mindif=min(mindif,arr1[i][j]-arr2[i][j]);
  			}
  		}
  		if(flag)
  		{
  			ans+=mindif;
  			FOR(j,0,m-1)
  			arr2[i][j]+=mindif;
  		}	
    } 
}

    FOR(j,0,m-1)
    {
    	if(arr1[0][j]<arr2[0][j])
  	{
  		bool flag=true;
  		ll mindif=arr2[0][j]-arr1[0][j];
  		FOR(i,1,n-1)
  		{
  			if(arr1[i][j]>=arr2[i][j])
  				{
  					flag=false;
  					break;
  				}
  			else
  			{
  				mindif=min(mindif,arr2[i][j]-arr1[i][j]);
  			}
  		}
  		if(flag)
  		{
  			ans+=mindif;
  			FOR(i,0,n-1)
  			arr1[i][j]+=mindif;
  		}
  		else
  		{
  			mainflag=false;	
  		}	
    }
    else if(arr2[0][j]<arr1[0][j])
    {
    	bool flag=true;
  		ll mindif=arr1[0][j]-arr2[0][j];
  		FOR(i,1,n-1)
  		{
  			if(arr2[i][j]>=arr1[i][j])
  				{
  					flag=false;
  					break;
  				}
  			else
  			{
  				mindif=min(mindif,arr1[i][j]-arr2[i][j]);
  			}
  		}
  		if(flag)
  		{
  			ans+=mindif;
  			FOR(i,0,n-1)
  			arr1[i][j]+=mindif;
  		}
  		else
  		{
  			mainflag=false;	
  		}	

    }

    }

    if(mainflag==false)
    {
    	cout<<-1<<endl;
    }
    else
    {
    	FOR(i,0,n-1)
    	FOR(j,0,m-1)
    	if(arr1[i][j]!=arr2[i][j])
        {
        	mainflag=false;
        }

        if(mainflag)
        	cout<<ans<<endl;
        else
        	cout<<-1<<endl;
    }
}

  
  return 0;
}